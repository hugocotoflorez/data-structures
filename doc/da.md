## NAME
DA - Dynamic Array

## SYNOPSIS
``` c
#include "da.h"

DA(some_type) DA(some_type);
DA(some_type) da_init(DA(some_type) *da_ptr [, const int size]);
int da_append(DA(some_type) *da_ptr, some_type e);
int da_insert(DA(some_type) *da_ptr, some_type e, int i);
void da_destroy(DA(some_type) *da_ptr);
int da_getsize(DA(some_type) da);
int for_da_each(some_type *i, DA(some_type) da);
```

## DESCRIPTION

Macro based dynamic array

### QUICK START

Declare a DA new type:
``` c
DA(char) da_char;
```

Declare a new DA:
``` c
da_char str;
da_init(&str);
```

Append or insert elements:
``` c
da_append(&str, 'a');
da_insert(&str, 'a', 0);
```

Get size:
``` c
size = da_getsize(&str);
```

Pseudo for each:
``` c
for_da_each(i, str){
    printf("%c\n", i);
}
```

Destroy the DA:
``` c
da_destroy(&str);
```

/* Initialize DA_PTR (that is a pointer to a DA). Initial size (int) can be
 * passed as second argument, default is 0. */
#define da_init(da_ptr, ...)                                                            \
        ({                                                                              \
                (da_ptr)->capacity = 0##__VA_ARGS__ ? __VA_ARGS__ : 4;                  \
                (da_ptr)->size = 0;                                                     \
                (da_ptr)->data = malloc(sizeof *((da_ptr)->data) * (da_ptr)->capacity); \
                assert(da_ptr);                                                         \
                sizeof *((da_ptr)->data);                                               \
        })

#include <assert.h>
// add E to DA_PTR that is a pointer to a DA of the same type as E
#define da_append(da_ptr, e)                                                     \
        ({                                                                       \
                if ((da_ptr)->size >= (da_ptr)->capacity)                        \
                {                                                                \
                        (da_ptr)->capacity += 3;                                 \
                        (da_ptr)->data =                                         \
                        realloc((da_ptr)->data,                                  \
                                sizeof(*((da_ptr)->data)) * (da_ptr)->capacity); \
                        assert(da_ptr);                                          \
                }                                                                \
                assert((da_ptr)->size < (da_ptr)->capacity);                     \
                (da_ptr)->data[(da_ptr)->size++] = (e);                          \
                (da_ptr)->size - 1;                                              \
        })

/* Destroy DA pointed by DA_PTR. DA can be initialized again but previous values
 * are not accessible anymore. */
#define da_destroy(da_ptr)        \
        ({                        \
                (da_ptr)->capacity = 0; \
                (da_ptr)->size = 0;     \
                free((da_ptr)->data);   \
                (da_ptr)->data = NULL;  \
        })

/* Insert element E into DA pointed by DA_PTR at index I. */
#include <string.h> // memmove
#define da_insert(da_ptr, e, i)                                                 \
        ({                                                                      \
                assert((i) >= 0 && (i) <= (da_ptr)->size);                      \
                da_append(da_ptr, e);                                           \
                memmove((da_ptr)->data + (i) + 1, (da_ptr)->data + (i),         \
                        ((da_ptr)->size - (i) - 1) * sizeof *((da_ptr)->data)); \
                (da_ptr)->data[i] = (e);                                        \
        })

/* Get size */
#define da_getsize(da) (da->size)

/* can be used as:
 * for_da_each(i, DA), where
 * - i: varuable where a pointer to an element from DA is going to be stored
 * - DA: is a valid DA */
#define for_da_each(_i_, da) \
        for (__auto_type _i_ = (da).data; (int) (_i_ - (da).data) < (da).size; ++_i_)


#endif
