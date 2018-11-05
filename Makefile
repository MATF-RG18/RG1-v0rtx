#currently doesn't work, need to search about making installers easier
# -*- Makefile -*-
PROGRAM = v0rtX
CC 			= gcc
CFLAGS	= -std=c99 -g -Wall -Wextra -ftime-report
LDFLAGS = -lGL -lGLU -lglut -lm 
IFLAGS  = -I./include/ 

src = $(wildcard src/*.c)
bak = $(wildcard src/*.c~)
obj = $(patsubst %.c, %.o, $(src))

$(PROGRAM): $(obj)
	$(CC) -o $(PROGRAM) *.o $(LDFLAGS) 

$(obj): $(src)
	$(CC) -c $(src) -I./include/

.PHONY: clean

clean:
	-rm -rf $(bak) *.o $(PROGRAM) *core
