#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include "_sexp-types.h"
#include "_sexp-value.h"
#include "_sexp-manip.h"
#include "public/sm_alloc.h"

/*
 * Numbers
 */

SEXP_t *SEXP_number_new (SEXP_numtype_t t, const void *n)
{
        if (t <= SEXP_NUM_UINT16) {
                if (t <= SEXP_NUM_INT8) {
                        switch (t) {
                        case SEXP_NUM_BOOL:  return SEXP_number_newb   (*(bool    *)(n));
                        case SEXP_NUM_INT8:  return SEXP_number_newi_8 (*(int8_t  *)(n));
                        case SEXP_NUM_UINT8: return SEXP_number_newu_8 (*(uint8_t *)(n));
                        }
                } else {
                        switch (t) {
                        case SEXP_NUM_INT16:  return SEXP_number_newi_16 (*(int16_t  *)(n));
                        case SEXP_NUM_UINT16: return SEXP_number_newu_16 (*(uint16_t *)(n));
                        }
                }
        } else {
                if (t <= SEXP_NUM_INT64) {
                        switch (t) {
                        case SEXP_NUM_INT32:  return SEXP_number_newi_32 (*(int32_t  *)(n));
                        case SEXP_NUM_UINT32: return SEXP_number_newu_32 (*(uint32_t *)(n));
                        case SEXP_NUM_INT64:  return SEXP_number_newi_64 (*(int64_t  *)(n));
                        }
                } else {
                        switch (t) {
                        case SEXP_NUM_UINT64: return SEXP_number_newu_64 (*(uint64_t *)(n));
                        case SEXP_NUM_DOUBLE: return SEXP_number_newf    (*(double   *)(n));
                        }
                }
        }
        
        errno = EINVAL;
        return  (NULL);
}

SEXP_t *SEXP_number_newb (bool n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (bool),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_BOOL;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newi_8  (int8_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (int8_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_INT8;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newu_8  (uint8_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (uint8_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_UINT8;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newi_16 (int16_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (int16_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_INT16;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newu_16 (uint16_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (uint16_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_UINT16;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newi_32 (int32_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (int32_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_INT32;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newu_32 (uint32_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (uint32_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_UINT32;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newi_64 (int64_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (int64_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_INT64;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newu_64 (uint64_t n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (uint64_t),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_UINT64;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_number_newf (double n)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        
        if (SEXP_val_new (&v_dsc, sizeof (SEXP_numtype_t) + sizeof (double),
                          SEXP_VALTYPE_NUMBER) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        SEXP_NCASTP(b,v_dsc.mem)->t = SEXP_NUM_DOUBLE;
        SEXP_NCASTP(b,v_dsc.mem)->n = n;
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

int SEXP_number_get (SEXP_t *s_exp, void *dst, SEXP_numtype_t type)
{
        return (-1);
}

void SEXP_number_free (SEXP_t *s_exp)
{
        SEXP_free (s_exp);
}

bool SEXP_numberp (const SEXP_t *s_exp)
{
        if (s_exp == NULL) {
                errno = EFAULT;
                return (false);
        }
        
        return ((s_exp->s_valp & SEXP_VALT_MASK) == SEXP_VALTYPE_NUMBER);
}

SEXP_numtype_t SEXP_number_type (const SEXP_t *s_exp)
{
        SEXP_val_t v_dsc;

        if (s_exp == NULL) {
                errno = EFAULT;
                return (SEXP_NUM_NONE);
        }

        if (!SEXP_numberp (s_exp)) {
                errno = EINVAL;
                return (SEXP_NUM_NONE);
        }

        SEXP_val_dsc (&v_dsc, s_exp->s_valp);
        
        return (*(SEXP_numtype_t *)((uint8_t *)(v_dsc.mem) + v_dsc.hdr->size - sizeof (SEXP_numtype_t)));
}

/*
 * Strings
 */

SEXP_t *SEXP_string_new  (const void *string, size_t length)
{
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;

        if (SEXP_val_new (&v_dsc, sizeof (char) * length,
                          SEXP_VALTYPE_STRING) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        memcpy (v_dsc.mem, string, sizeof (char) * length);

        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

SEXP_t *SEXP_string_newf (const char *format, ...)
{
        va_list    alist;
        SEXP_t    *s_exp;
        SEXP_val_t v_dsc;
        char      *v_string;
        int        v_strlen;
        
        va_start (alist, format);
        v_strlen = vasprintf (&v_string, format, alist);
        
        if (v_strlen < 0) {
                /* TODO: handle this */
                return (NULL);
        }

        va_end (alist);
        
        if (SEXP_val_new (&v_dsc, sizeof (char) * v_strlen,
                          SEXP_VALTYPE_STRING) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }
        
        memcpy  (v_dsc.mem, v_string, sizeof (char) * v_strlen);
        sm_free (v_string);
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (NULL);
}

void SEXP_string_free (SEXP_t *s_exp)
{
        SEXP_free (s_exp);
}

bool SEXP_stringp (const SEXP_t *s_exp)
{
        if (s_exp == NULL) {
                errno = EFAULT;
                return (false);
        }
        
        return ((s_exp->s_valp & SEXP_VALT_MASK) == SEXP_VALTYPE_STRING);
}

size_t SEXP_string_length (const SEXP_t *s_exp)
{
        SEXP_val_t v_dsc;
        
        if (s_exp == NULL) {
                errno = EFAULT;
                return ((size_t)(-1));
        }
        
        SEXP_val_dsc (&v_dsc, s_exp->s_valp);
        
        if (v_dsc.type != SEXP_VALTYPE_STRING) {
                errno = EINVAL;
                return ((size_t)(-1));
        }
        
        return (v_dsc.hdr->size / sizeof (char));
}

int SEXP_strcmp (SEXP_t *s_exp, const char *str)
{
        return (-1);
}

int SEXP_strncmp (SEXP_t *s_exp, const char *str, size_t n)
{
        return (-1);
}

char *SEXP_string_cstr (SEXP_t *s_exp)
{
        return (NULL);
}

char *SEXP_string_cstr_r (SEXP_t *s_exp, char *buf, size_t len)
{
        return (NULL);
}

char *SEXP_string_subcstr (SEXP_t *s_exp, size_t beg, size_t len)
{
        return (NULL);
}

char *SEXP_string_cstrp (const SEXP_t *s_exp)
{
        return (NULL);
}

/*
 * Lists
 */

SEXP_t *SEXP_list_new (SEXP_t *memb, ...)
{
        va_list    alist;
        SEXP_val_t v_dsc;
        SEXP_t    *s_ptr[32];
        size_t     s_cur;
        uint8_t    b_exp;
        SEXP_t    *s_exp;
        
        va_start (alist, memb);

        s_cur = 0;
        s_ptr[s_cur] = memb;

        while (s_ptr[s_cur] != NULL) {
                _A(s_cur < (sizeof s_ptr / sizeof (SEXP_t *)));
                s_ptr[++s_cur] = va_arg (alist, SEXP_t *);
        }
        
        if (SEXP_val_new (&v_dsc, sizeof (void *) + sizeof (uint16_t),
                          SEXP_VALTYPE_LIST) != 0)
        {
                /* TODO: handle this */
                return (NULL);
        }

        if (s_cur > 0) {
                for (b_exp = 0; (size_t)(2 << b_exp) < s_cur; ++b_exp);
                
                SEXP_LCASTP(v_dsc.mem)->offset = 0;
                SEXP_LCASTP(v_dsc.mem)->b_addr = (void *)SEXP_rawval_lblk_new (b_exp);
                
                if (SEXP_rawval_lblk_fill ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr,
                                           s_ptr, s_cur) != ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr))
                {
                        /* TODO: handle this */
                        return (NULL);
                }
        } else {
                SEXP_LCASTP(v_dsc.mem)->offset = 0;
                SEXP_LCASTP(v_dsc.mem)->b_addr = NULL;
        }
        
        s_exp = SEXP_new ();
        s_exp->s_type = NULL;
        s_exp->s_valp = v_dsc.ptr;
        
        return (s_exp);
}

void SEXP_list_free (SEXP_t *s_exp)
{
        SEXP_free (s_exp);
}

bool SEXP_listp (const SEXP_t *s_exp)
{
        if (s_exp == NULL) {
                errno = EFAULT;
                return (false);
        }
        
        return ((s_exp->s_valp & SEXP_VALT_MASK) == SEXP_VALTYPE_LIST);
}

size_t SEXP_list_length (const SEXP_t *s_exp)
{
        SEXP_val_t v_dsc;

        if (s_exp == NULL) {
                errno = EFAULT;
                return ((size_t)(-1));
        }

        SEXP_val_dsc (&v_dsc, s_exp->s_valp);

        if (v_dsc.type != SEXP_VALTYPE_LIST) {
                errno = EINVAL;
                return ((size_t)(-1));
        }
        
        return (SEXP_rawval_list_length ((struct SEXP_val_list *)v_dsc.mem));
}

SEXP_t *SEXP_list_first (const SEXP_t *list)
{
        SEXP_val_t v_dsc;
        SEXP_t    *s_exp;
        
        if (list == NULL) {
                errno = EFAULT;
                return (NULL);
        }

        SEXP_val_dsc (&v_dsc, list->s_valp);

        if (v_dsc.type != SEXP_VALTYPE_LIST) {
                errno = EINVAL;
                return (NULL);
        }

        s_exp = SEXP_rawval_lblk_nth ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr,
                                      SEXP_LCASTP(v_dsc.mem)->offset + 1);

        return (s_exp == NULL ? NULL : SEXP_ref (s_exp));
}

SEXP_t *SEXP_listref_first (SEXP_t *list)
{
        return (NULL);
}

SEXP_t *SEXP_list_rest  (const SEXP_t *list)
{
        errno = EOPNOTSUPP;
        return (NULL);
}

SEXP_t *SEXP_listref_rest (SEXP_t *list)
{
        return (NULL);
}

SEXP_t *SEXP_list_last (const SEXP_t *list)
{
        SEXP_val_t v_dsc;
        uint32_t   l_len;
        struct SEXP_val_lblk *l_blk;
        
        if (list == NULL) {
                errno = EFAULT;
                return (NULL);
        }
        
        SEXP_val_dsc (&v_dsc, list->s_valp);

        if (v_dsc.type != SEXP_VALTYPE_LIST) {
                errno = EINVAL;
                return (NULL);
        }

        l_blk = SEXP_VALP_LBLK(SEXP_rawval_lblk_last ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr));
        
        if (l_blk == NULL)
                return (NULL);
        
        return (SEXP_ref (l_blk->memb + (l_blk->real - 1)));
}

SEXP_t *SEXP_listref_last (SEXP_t *list)
{
        return (NULL);
}

SEXP_t *SEXP_list_nth (const SEXP_t *list, uint32_t n)
{
        SEXP_val_t v_dsc;
        uint32_t   l_len;
        SEXP_t    *s_exp;

        if (list == NULL) {
                errno = EFAULT;
                return (NULL);
        }
        
        SEXP_val_dsc (&v_dsc, list->s_valp);

        if (v_dsc.type != SEXP_VALTYPE_LIST || n < 1) {
                errno = EINVAL;
                return (NULL);
        }
        
        s_exp = SEXP_rawval_lblk_nth ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr,
                                      SEXP_LCASTP(v_dsc.mem)->offset + n);
        
        return (s_exp == NULL ? NULL : SEXP_ref (s_exp));
}

SEXP_t *SEXP_listref_nth (SEXP_t *list, uint32_t n)
{
        return (NULL);
}

SEXP_t *SEXP_list_add (SEXP_t *list, SEXP_t *s_exp)
{
        SEXP_val_t v_dsc;
        uint32_t   l_len;
                        
        if (list == NULL || s_exp == NULL) {
                errno = EFAULT;
                return (NULL);
        }

        SEXP_val_dsc (&v_dsc, list->s_valp);
        
        if (v_dsc.type != SEXP_VALTYPE_LIST) {
                errno = EINVAL;
                return (NULL);
        }
        
        if (v_dsc.hdr->refs > 1) {
                /*
                 * Create a private copy of the value and
                 * decrement the reference counter in the
                 * original value.
                 */
                uintptr_t uptr;
                
                uptr = SEXP_rawval_list_copy ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr,
                                              (uintptr_t)SEXP_LCASTP(v_dsc.mem)->offset);
                
                if (SEXP_rawval_decref (list->s_valp)) {
                        /* TODO: handle this */
                }
                
                list->s_valp = uptr;
                SEXP_val_dsc (&v_dsc, list->s_valp);

                uptr = SEXP_rawval_lblk_last ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr);
                SEXP_rawval_lblk_add1 (uptr, s_exp);
        } else {
                /*
                 * Only one reference exists to the value.
                 * However, list blocks have their own
                 * reference counter and some blocks can
                 * be shared. This case is handled by the
                 * function SEXP_rawval_list_add.
                 */
                SEXP_LCASTP(v_dsc.mem)->b_addr = (void *)SEXP_rawval_lblk_add ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr, s_exp);
        }
        
        return (list);
}

SEXP_t *SEXP_list_join (const SEXP_t *list_a, const SEXP_t *list_b)
{
        errno = EOPNOTSUPP;
        return (NULL);
}

SEXP_t *SEXP_list_push (SEXP_t *list, SEXP_t *s_exp)
{
        errno = EOPNOTSUPP;
        return (NULL);
}

SEXP_t *SEXP_list_pop (SEXP_t *list)
{
        errno = EOPNOTSUPP;
        return (NULL);
}

SEXP_lstack_t *SEXP_lstack_new (void)
{
        SEXP_lstack_t *stack;
        
        stack->l_size = SEXP_LSTACK_INIT_SIZE;
        stack->l_real = 0;
        stack->l_sref = sm_alloc (sizeof (SEXP_t *) * SEXP_LSTACK_INIT_SIZE);
        
        return (stack);
}

SEXP_t *SEXP_lstack_push (SEXP_lstack_t *stack, SEXP_t *ref)
{
        if (stack->l_real == stack->l_size) {
                if (stack->l_size < SEXP_LSTACK_GROWFAST_TRESH)
                        stack->l_size <<= 1;
                else
                        stack->l_size  += SEXP_LSTACK_GROWSLOW_DIFF;
                
                stack->l_sref = sm_realloc (stack->l_sref, sizeof (SEXP_t *) * stack->l_size);
        }
        
        stack->l_sref[stack->l_real++] = ref;
        
        return (ref);
}

SEXP_t *SEXP_lstack_pop (SEXP_lstack_t *stack)
{
        SEXP_t *ref;
        size_t  diff;
        
        ref  = stack->l_sref[--stack->l_real];
        diff = stack->l_size - stack->l_real;
        
        if (stack->l_size > SEXP_LSTACK_GROWFAST_TRESH) {
                if (diff >= SEXP_LSTACK_GROWSLOW_DIFF) {
                        stack->l_size  -= SEXP_LSTACK_GROWSLOW_DIFF;
                        goto resize;
                }
        } else {
                if (diff >= 2 * stack->l_real) {
                        stack->l_size >>= 1;
                        goto resize;
                }
        }

        return (ref);
resize:
        stack->l_sref = sm_realloc (stack->l_sref, sizeof (SEXP_t *) * stack->l_size);
        return (ref);
}

SEXP_t *SEXP_lstack_top (SEXP_lstack_t *stack)
{
        return (stack->l_sref[stack->l_real - 1]);
}

/*
 * Generic
 */

SEXP_t *SEXP_new (void)
{
        SEXP_t *s_exp;

        s_exp = sm_talloc (SEXP_t);
        s_exp->s_type = NULL;
        s_exp->s_valp = 0;
        s_exp->s_flgs = 0;
        
        return (s_exp);
}

SEXP_t *SEXP_ref (const SEXP_t *s_exp_o)
{
        SEXP_t *s_exp_r;

        s_exp_r = SEXP_new ();
        s_exp_r->s_type = s_exp_o->s_type;
        s_exp_r->s_valp = SEXP_rawval_incref (s_exp_o->s_valp);
        
        return (s_exp_r);
}

SEXP_t *SEXP_softref (const SEXP_t *s_exp_o)
{
        SEXP_t *s_exp_r;
        
        s_exp_r = SEXP_new ();
        s_exp_r->s_type = s_exp_o->s_type;
        s_exp_r->s_valp = s_exp_o->s_valp;
        
        SEXP_flag_set (s_exp_r, SEXP_FLAG_SREF);
        
        return (s_exp_r);
}

void SEXP_free (SEXP_t *s_exp)
{
       
        if (((s_exp->s_flgs &
              (SEXP_FLAG_SREF|SEXP_FLAG_INVAL|SEXP_FLAG_UNFIN)) == 0) &&
            SEXP_typeof (s_exp) != SEXP_TYPE_EMPTY)
        {
                SEXP_val_t v_dsc;
                uint32_t   refs;

                SEXP_val_dsc (&v_dsc, s_exp->s_valp);

                if (SEXP_rawval_decref (s_exp->s_valp)) {
                        switch (v_dsc.type) {
                        case SEXP_VALTYPE_STRING:
                                sm_free (v_dsc.hdr);
                                break;
                        case SEXP_VALTYPE_NUMBER:
                                sm_free (v_dsc.hdr);
                                break;
                        case SEXP_VALTYPE_LIST:
                                SEXP_rawval_lblk_free ((uintptr_t)SEXP_LCASTP(v_dsc.mem)->b_addr, SEXP_free);
                                sm_free (v_dsc.hdr);
                        default:
                                abort ();
                        }
                }
        }
        
        s_exp->s_valp = 0;
        s_exp->s_type = NULL;
        
        sm_free (s_exp);
        
        return;
}

const char *SEXP_datatype (const SEXP_t *s_exp)
{
        errno = EOPNOTSUPP;
        return (NULL);
}

int SEXP_datatype_set (SEXP_t *s_exp, const char *name)
{
        errno = EOPNOTSUPP;
        return (-1);
}

SEXP_type_t SEXP_typeof (const SEXP_t *s_exp)
{
        SEXP_val_t v_dsc;
        
        SEXP_val_dsc (&v_dsc, s_exp->s_valp);
        
        return ((SEXP_type_t) v_dsc.type);
}

const char *__sexp_strtype[] = {
        "empty",
        "string",
        "number",
        "list"
};

const char *SEXP_strtype (const SEXP_t *s_exp)
{
        SEXP_val_t v_dsc;
        
        if (s_exp == NULL)
                return ("null");
        
        SEXP_val_dsc (&v_dsc, s_exp->s_valp);
        
        return (__sexp_strtype[v_dsc.type]);
}
