#include "../src/ll/ll.h"
#include <assert.h>

typedef LL(int) int_ll;

int
main()
{
        int_ll list;
        ll_init(&list);

        ll_insert_after(&list, 3);
        ll_insert_after(&list, 2);
        ll_insert_after(&list, 1);
        ll_insert_after(&list, 0);

        int idx = 0;
        for_ll_each(i, &list)
        {
                assert(ll_get(i) == idx++);
        }

        ll_destroy(&list);

        return 0;
}
