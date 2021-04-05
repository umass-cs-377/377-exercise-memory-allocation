CXX=g++
CXXFLAGS += -g -Wall -Wextra -pthread
CPPFLAGS += -isystem src -std=c++11

MKDIR_P = mkdir -p
OBJ_DIR = obj

all: one two

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

obj/%.o: %.cpp ${OBJ_DIR}
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

one: obj/one.o
	$(CXX) -o $@ $^

two: obj/two.o
	$(CXX) -o $@ $^

clean:
	rm -f *~ obj/*.o *.zip
	rm -f one two
