all: main.c
	make binary_search
	make linear_search
	make selection_sort

binary_search: main.c
	gcc main.c -o binary_search -DB_S -Wall -Werror -Wextra -Wvla -Wconversion -pedantic -std=c11

linear_search: main.c
	gcc main.c -o linear_search -DL_S -Wall -Werror -Wextra -Wvla -Wconversion -pedantic -std=c11

selection_sort: main.c
	gcc main.c -o selection_sort -DS_S -Wall -Werror -Wextra -Wvla -Wconversion -pedantic -std=c11
clean:
	rm -f linear_search binary_search selection_sort