
LIBC = /usr/lib/libc.a
CC = cproc

build: bar-menu

bar-menu: main.o libbarnabas
	ld -static -s -z norelro -z noseparate-code -o bar-menu main.o BarnabasBox/libbarnabas.a $(LIBC)

main.o: main.c
	$(CC) -c -o main.o main.c

libbarnabas: BarnabasBox/
	make -C BarnabasBox -f Makefile

clean:
	rm -f main.o

all: build clean

