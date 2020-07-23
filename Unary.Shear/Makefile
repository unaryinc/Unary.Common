rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC_DIR := Source
OBJ_DIR := Temp
SRC_FILES := $(call rwildcard,$(SRC_DIR),*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

ifeq ($(OS),Windows_NT)
	OSName := Windows
else
	OSName := $(shell uname -s)
endif

ifeq ($(OSName), Windows)
	Result = Unary.Shear.dll
endif
ifeq ($(OSName), Linux)
	Result = Unary.Shear.dll
endif

$(Result): $(OBJ_FILES)
	g++ -g -ggdb -Wall -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
ifeq ($(OSName), Windows)
	mkdir $(subst /,\\,$(dir $(@))) || (exit 0)
else
	mkdir -p $@ || true
endif	
	g++ -g -ggdb -Wall -I$(CURDIR)/Include -I$(CURDIR)/../rapidjson/include -c $< -o $@