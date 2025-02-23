#include <assert.h>
#include <stdio.h>

#include "../src/da/da.h"

typedef DA(char) char_da;

int
main()
{
        char_da str;
        char_da str2;
        char_da str3;

        assert(0);

        printf("INIT ... ");
        da_init(&str, 0);
        da_init(&str2);
        da_init(&str3, 7);

        printf("done!\nAPPEND - INSERT ... ");
        for (int i = 0; i < 127; ++i)
        {
                da_append(&str, i);
                da_insert(&str2, i, i);
                da_insert(&str3, i, 0);
        }


        printf("done!\nGETSIZE ... ");
        int size = da_getsize(str3);

        assert(da_getsize(str) == da_getsize(str2));
        assert(da_getsize(str2) == da_getsize(str3));
        assert(size == da_getsize(str3));
        assert(size == 127);

        printf("done!\nFOR_DA_EACH ... ");
        int idx = 0;
        for_da_each(i, str)
        {
                assert(*i == idx);
                assert(*i == str.data[idx]);
                assert(*i == str2.data[idx]);
                assert(*i == str3.data[size - idx - 1]);
                ++idx;
        }

        printf("done!\nDESTROY ... ");
        da_destroy(&str);
        da_destroy(&str2);
        da_destroy(&str3);

        printf("done!\n");

        return 0;
}
