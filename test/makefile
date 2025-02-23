opt = -O0 -fsanitize=address,null -Wall -Wextra -Werror

all:
	echo "use ./test_all.sh or a specific rule"

da_test: ./da_test.c ../src/da/da.h
	gcc da_test.c -std=c99 -o da_test ${opt}

ll_test: ./ll_test.c ../src/ll/ll.h
	gcc ll_test.c -std=gnu99 -o ll_test ${opt}

rm:
	rm da_test 2>/dev/null
	rm ll_test 2>/dev/null


