CXX=g++

SRC_DIR = src
SRCS = $(SRC_DIR)/*.cpp

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}
PROGRAM = GraphSearches

$(PROGRAM): $(SRCS)
	$(CXX) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRCS)

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o	$(PROGRAM)
