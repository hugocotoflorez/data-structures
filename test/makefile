all: da

da: ./da_test.c ../src/da/da.h
	gcc da_test.c -o da_test -O0 -fsanitize=address,null

