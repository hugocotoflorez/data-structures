/* Linked List Generic Implementation
 *
 * Linked List sin estructura base. Solo hay
 * nodos que forman una estructura circular. La
 * decision de tomar un nodo como nodo base recae
 * en el usuario que use esta implementacion
 *
 * Author: Hugo Coto Florez
 */

#include <assert.h> // assert
#include <stddef.h> // NULL
#include <stdlib.h> // malloc
#include <string.h> // memcpy


// return a node type
#define LL(type)            \
        struct              \
        {                   \
                void *prev; \
                void *next; \
                type elem;  \
        }

#define CAST(ptr, base_ptr) ((typeof(base_ptr)) ptr)

#define ll_MALLOC(size)                         \
        ({                                      \
                __auto_type ret = malloc(size); \
                assert(ret);                    \
                bzero(ret, size);               \
                ret;                            \
        })

#define ll_init(base_ptr)                \
        {                                \
                (base_ptr)->prev = NULL; \
                (base_ptr)->next = NULL; \
        }

#define ll_get(base_ptr) ((base_ptr)->elem)

#define ll_newnode(base_ptr, e)                                             \
        ({                                                                  \
                typeof(base_ptr) __node__ = ll_MALLOC(sizeof(*(base_ptr))); \
                __node__->elem = (e);                                       \
                __node__;                                                   \
        })

#define ll_insert_after(base_ptr, e)                                         \
        ({                                                                   \
                __auto_type __node__ = ll_newnode((base_ptr), e);            \
                __node__->prev = (base_ptr);                                 \
                if ((base_ptr)->next == NULL)                                \
                {                                                            \
                        __node__->next = (base_ptr);                         \
                        (base_ptr)->prev = __node__;                         \
                }                                                            \
                else                                                         \
                {                                                            \
                        __node__->next = CAST((base_ptr)->next, (base_ptr)); \
                        CAST((base_ptr)->next, (base_ptr))->prev = __node__; \
                }                                                            \
                (base_ptr)->next = __node__;                                 \
        })

#define ll_next(base_ptr) CAST((base_ptr)->next, (base_ptr))

#define LL_DESTROY_BASE 1

#define ll_destroy(base_ptr, ...)                                 \
        {                                                         \
                typeof((base_ptr)) __base__ = ((base_ptr));       \
                typeof((base_ptr)) __next__ = ((base_ptr))->next; \
                typeof((base_ptr)) __ptr__;                       \
                if (__next__ != NULL)                             \
                        do                                        \
                        {                                         \
                                __ptr__ = __next__;               \
                                __next__ = __next__->next;        \
                                free(__ptr__);                    \
                        } while (__next__ != __base__);           \
                __VA_OPT__(free((base_ptr)));                     \
        }


#define for_ll_each(_i_, base_ptr)                                            \
        for (typeof((base_ptr)) _i_ = (base_ptr)->next; _i_ && _i_ != (base_ptr); \
             _i_ = _i_->next)
