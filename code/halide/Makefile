CXX := g++
HALIDE_DIR := ../../halide_lib

# Flags de compilation
CXXFLAGS := -std=c++17 #-Wall -Wextra

# Inclusion et liaison avec Halide
HALIDE_INCLUDE := $(HALIDE_DIR)/include/
HALIDE_LIB := $(HALIDE_DIR)/lib/
LDFLAGS := -L$(HALIDE_LIB) -lHalide -Wl,-rpath=$(HALIDE_LIB)
CPPFLAGS := -I$(HALIDE_INCLUDE)

#opencv
OPENCV_LIB := $(shell pkg-config --libs opencv4)
OPENCV_CFLAGS := $(shell pkg-config --cflags opencv4)
LDFLAGS += $(OPENCV_LIB)
CPPFLAGS += $(OPENCV_CFLAGS)

# Fichiers source
SRCS := main.cpp

# Fichiers objets
OBJS := $(SRCS:.cpp=.o)

# Nom de l'exécutable
TARGET := main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	export LD_LIBRARY_PATH=$(HALIDE_LIB):$$LD_LIBRARY_PATH 
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
