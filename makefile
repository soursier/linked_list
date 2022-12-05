CC ?= gcc
CFLAGS += -Wall --pedantic -Werror
LIB_PATH = .

all: 
	$(CC) $(LDFLAGS) -L$(LIB_PATH) -o linked_list $(CFLAGS) linked_list.c main.c

test:
	$(CC) $(LDFLAGS) -L$(LIB_PATH) -o test_linked_list $(CFLAGS) test_linked_list.c linked_list.c -lcunit -D TEST

clean:
	rm -f *.o linked_list test_linked_list