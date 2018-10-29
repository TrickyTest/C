# Let's see if I can get this to work, peeps

all: doe_het

doe_het: obj/test.o obj/main.o
	@echo Dumping it all together into one big executable file
	@g++ obj/*.o -o bin/hello_makefile_mybin
	
obj/test.o:src/test.c
	@echo Compiling test.c
	@gcc src/test.c -o obj/test.o -c -Wall
obj/main.o:src/main.c obj/test.o
	@echo Compiling main.c
	@gcc src/main.c -o obj/main.o -c -Wall -I head
	
