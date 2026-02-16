# ====== Config ======
TARGET ?= BorisTheTomato
CXX := g++
CC := gcc
BUILD ?= debug

CPP_SRCS := $(wildcard *.cpp)
C_SRCS := $(wildcard *.c)
OBJ := $(CPP_SRCS:.cpp=.o) $(C_SRCS:.c=.o)
DEP := $(OBJ:.o=.d)

SDL_DEPS := ./SDL2


PKG_DEPS := sdl2 SDL2_image SDL2_mixer SDL2_ttf

BASE_FLAGS := -std=c++17 -Wall -Wextra

ifeq ($(BUILD), release)
	CXXFLAGS := $(BASE_FLAGS) -O2
else
	CXXFLAGS := $(BASE_FLAGS) -g -O0
endif

CXXFLAGS += -MMD -MP
CXXFLAGS += -I$(SDL_DEPS)/SDL2-2.0.4/include
CXXFLAGS += -I$(SDL_DEPS)/SDL2_image-2.0.1/include
CXXFLAGS += -I$(SDL_DEPS)/SDL2_mixer-2.0.1/include
CXXFLAGS += -I$(SDL_DEPS)/SDL2_ttf-2.0.14/include
CXXFLAGS += $(shell pkg-config --cflags $(PKG_DEPS))

CFLAGS := -Wall -Wextra -MMD -MP
CFLAGS += -I$(SDL_DEPS)/SDL2-2.0.4/include
CFLAGS += -I$(SDL_DEPS)/SDL2_image-2.0.1/include
CFLAGS += -I$(SDL_DEPS)/SDL2_mixer-2.0.1/include
CFLAGS += -I$(SDL_DEPS)/SDL2_ttf-2.0.14/include
CFLAGS += $(shell pkg-config --cflags $(PKG_DEPS))

LDFLAGS :=
LIBS := $(shell pkg-config --libs $(PKG_DEPS))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

-include $(DEP)

.PHONY: all clean run rebuild