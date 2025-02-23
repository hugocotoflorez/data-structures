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
macro for_da_each(some_type *i, DA(some_type) da);
```

## DESCRIPTION

Macro based dynamic array

### QUICK START

Declare a DA new type:
``` c
typedef DA(char) da_char;
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
    printf("%c\n", *i);
}
```

Destroy the DA:
``` c
da_destroy(&str);
```
## RETURN VALUE
`DA(some_type)`: DA base struct of data type some_type.
`da_init()`: Initialized DA.
`da_append(DA(some_type) *da_ptr, some_type e)`: index where element is stored.
`da_insert()`: none
`da_destroy()`: none
`da_getsize()`: DA size
`for_da_each(some_type *i, DA(some_type) da)`: none

## ATTRIBUTES
| Interface | Attribute | Value |
| --- | --- | --- |
| All DA functions | Thread safety | none |

## STANDARDS
C99, gnu C99

## Author

Hugo Coto Florez. Github at github.com/hugocotoflorez
