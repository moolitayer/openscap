/*
 * oval_state.c
 *
 *  Created on: Mar 3, 2009
 *      Author: david.niemoller
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "oval_definitions_impl.h"
#include "oval_collection_impl.h"
#include "oval_agent_api_impl.h"

typedef struct oval_state {
	oval_family_enum family;
	oval_subtype_enum subtype;
	char *name;
	char *comment;
	char *id;
	int deprecated;
	int version;
	struct oval_collection *notes;
	struct oval_collection *entities;
} oval_state_t;

int oval_iterator_state_has_more(struct oval_iterator_state *oc_state)
{
	return oval_collection_iterator_has_more((struct oval_iterator *)
						 oc_state);
}

struct oval_state *oval_iterator_state_next(struct oval_iterator_state
					    *oc_state)
{
	return (struct oval_state *)
	    oval_collection_iterator_next((struct oval_iterator *)oc_state);
}

oval_family_enum oval_state_family(struct oval_state *state)
{
	return (state)->family;
}

oval_subtype_enum oval_state_subtype(struct oval_state * state)
{
	return ((struct oval_state *)state)->subtype;
}

char *oval_state_name(struct oval_state *state)
{
	return ((struct oval_state *)state)->name;
}

struct oval_iterator_string *oval_state_notes(struct oval_state *state)
{
	return (struct oval_iterator_string *)oval_collection_iterator(state->
								       notes);
}

struct oval_iterator_entity *oval_state_entities(struct oval_state *state)
{
	return (struct oval_iterator_entity *)oval_collection_iterator(state->
								       entities);
}

char *oval_state_comment(struct oval_state *state)
{
	return ((struct oval_state *)state)->comment;
}

char *oval_state_id(struct oval_state *state)
{
	return ((struct oval_state *)state)->id;
}

int oval_state_deprecated(struct oval_state *state)
{
	return ((struct oval_state *)state)->deprecated;
}

int oval_state_version(struct oval_state *state)
{
	return state->version;
}

struct oval_state *oval_state_new()
{
	oval_state_t *state = (oval_state_t *) malloc(sizeof(oval_state_t));
	state->deprecated = 0;
	state->version = 0;
	state->family = FAMILY_UNKNOWN;
	state->subtype = OVAL_SUBTYPE_UNKNOWN;
	state->comment = NULL;
	state->id = NULL;
	state->name = NULL;
	state->notes = oval_collection_new();
	state->entities = oval_collection_new();
	return state;
}

void oval_state_free(struct oval_state *state)
{
	if (state->comment != NULL)
		free(state->comment);
	if (state->id != NULL)
		free(state->id);
	if (state->name != NULL)
		free(state->name);
	void free_notes(void *note) {
		free(note);
	}
	oval_collection_free_items(state->notes, &free_notes);
	free(state);
}

void set_oval_state_id(struct oval_state *state, char *id)
{
	state->id = id;
}

void set_oval_state_family(struct oval_state *state, oval_family_enum family)
{
	state->family = family;
}

void set_oval_state_subtype(struct oval_state *state, oval_subtype_enum subtype)
{
	state->subtype = subtype;
}

void set_oval_state_name(struct oval_state *state, char *name)
{
	state->name = name;
}

void add_oval_state_notes(struct oval_state *state, char *notes)
{
	oval_collection_add(state->notes, (void *)notes);
}

void set_oval_state_comment(struct oval_state *state, char *comment)
{
	state->comment = comment;
}

void set_oval_state_deprecated(struct oval_state *state, int deprecated)
{
	state->deprecated = deprecated;
}

void set_oval_state_version(struct oval_state *state, int version)
{
	state->version = version;
}

int _oval_state_parse_notes(xmlTextReaderPtr reader,
			    struct oval_parser_context *context, void *user)
{
	struct oval_state *state = (struct oval_state *)user;
	void note_consumer(char *text, void *null) {
		add_oval_state_notes(state, text);
	}
	return oval_parser_text_value(reader, context, &note_consumer, NULL);
}

int _oval_state_parse_tag(xmlTextReaderPtr reader,
			  struct oval_parser_context *context, void *user)
{
	struct oval_state *state = (struct oval_state *)user;
	xmlChar *tagname = xmlTextReaderName(reader);
	xmlChar *namespace = xmlTextReaderNamespaceUri(reader);
	int return_code = 1;
	if ((strcmp(tagname, "notes") == 0)) {
		return_code =
		    oval_parser_parse_tag(reader, context,
					  &_oval_state_parse_notes, state);
	} else {
		void consume_entity(struct oval_entity *entity, void *null) {
			oval_collection_add(state->entities, (void *)entity);
		}
		return_code =
		    oval_entity_parse_tag(reader, context, &consume_entity,
					  NULL);
	}
	if (return_code != 1) {
		int line = xmlTextReaderGetParserLineNumber(reader);
		printf
		    ("NOTICE: oval_state_parse_tag::parse of %s terminated on error at <%s> line %d\n",
		     state->id, tagname, line);
	}
	free(tagname);
	free(namespace);
	return return_code;
}

int oval_state_parse_tag(xmlTextReaderPtr reader,
			 struct oval_parser_context *context)
{
	char *id = xmlTextReaderGetAttribute(reader, "id");
	struct oval_object_model *model = oval_parser_context_model(context);
	//printf("DEBUG::oval_state_parse_tag::id = %s\n", id);
	struct oval_state *state = get_oval_state_new(model, id);
	oval_subtype_enum subtype = oval_subtype_parse(reader);
	set_oval_state_subtype(state, subtype);
	char *comment = xmlTextReaderGetAttribute(reader, "comment");
	set_oval_state_comment(state, comment);
	int deprecated = oval_parser_boolean_attribute(reader, "deprecated", 0);
	set_oval_state_deprecated(state, deprecated);
	char *version = xmlTextReaderGetAttribute(reader, "version");
	set_oval_state_version(state, atoi(version));
	free(version);

	int return_code =
	    oval_parser_parse_tag(reader, context, &_oval_state_parse_tag,
				  state);
	return return_code;
}

void oval_state_to_print(struct oval_state *state, char *indent, int index)
{
	char nxtindent[100];

	if (strlen(indent) > 80)
		indent = "....";

	if (index == 0)
		snprintf(nxtindent, sizeof(nxtindent), "%sSTATE.", indent);
	else
		snprintf(nxtindent, sizeof(nxtindent), "%sSTATE[%d].", indent, index);

	printf("%sID         = %s\n", nxtindent, oval_state_id(state));
	printf("%sFAMILY     = %d\n", nxtindent, oval_state_family(state));
	printf("%sSUBTYPE    = %d\n", nxtindent, oval_state_subtype(state));
	printf("%sVERSION    = %d\n", nxtindent, oval_state_version(state));
	printf("%sCOMMENT    = %s\n", nxtindent, oval_state_comment(state));
	printf("%sDEPRECATED = %d\n", nxtindent, oval_state_deprecated(state));
	struct oval_iterator_string *notes = oval_state_notes(state);
	for (index = 1; oval_iterator_string_has_more(notes); index++) {
		printf("%sNOTE[%d]    = %s\n", nxtindent, index,
		       oval_iterator_string_next(notes));
	}

	struct oval_iterator_entity *contents = oval_state_entities(state);
	for (index = 1; oval_iterator_entity_has_more(contents); index++) {
		struct oval_entity *entity =
		    oval_iterator_entity_next(contents);
		oval_entity_to_print(entity, nxtindent, index);
	}
}
