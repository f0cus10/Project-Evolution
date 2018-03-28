
#FLAGS
CXXFLAG = -O3 -std=c++11 -Wall
EXEC_DIR=.

#Rule for .cpp files
.cpp.o:
		g++ $(CXXFLAG) $(INCLUDES) -c $< -o $@

INCLUDES = -I.

ALL_OBJ=main.o Shell.o Entry.o

PROGRAM_0=evolution

$(PROGRAM_0): $(ALL_OBJ)
		g++ $(CXXFLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ) $(INCLUDES)

all:
		make $(PROGRAM_0)
clean:
		(rm -f *.o; rm -f evolution)


