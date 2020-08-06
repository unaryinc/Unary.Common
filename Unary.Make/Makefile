rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC_DIR := ${CURDIR}/Source
OBJ_DIR := ${CURDIR}/Temp

ifeq ($(Debug), 1)
	Args := -g -ggdb 
	ResultFirst := Unary.Make.Debug
	OBJ_DIR := $(OBJ_DIR)/Debug
else
	Args := -O3 
	ResultFirst := Unary.Make.Release
	OBJ_DIR := $(OBJ_DIR)/Release
endif

SRC_FILES := $(call rwildcard,$(SRC_DIR),*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

ifeq ($(OS),Windows_NT)
	OSName := Windows
else ifeq ($(OS),Darwin)
	$(error MACOS IS NOT SUPPORTED, IT DIED IN A HORRIBLE WAY)
else
	OSName := $(shell uname -s)
endif

ifeq ($(OSName), Windows)
	Result := $(ResultFirst).exe
else ifeq ($(OSName), Linux)
	Result := $(ResultFirst).out
else
	Result := $(ResultFirst).unknown
endif

ifeq ($(OSName), Windows)
	export PATH := $(PATH);$(CURDIR)/../Unary.MinGW/bin
endif

$(Result): $(OBJ_FILES)
	g++ $(Args)-Wall -static -std=c++17 -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
ifeq ($(OSName), Windows)
	mkdir $(subst /,\\,$(dir $(@))) || (exit 0)
else
	mkdir -p $@ || true
endif
	g++ $(Args)-Wall -static -std=c++17 -I$(CURDIR)/Include -I$(CURDIR)/../rapidjson/include -c $< -o $@
	

clean : 
ifeq ($(OS),Windows_NT)
	rd /s /q Temp || (exit 0)
	del Unary.Make.Debug.exe || (exit 0)
	del Unary.Make.Release.exe || (exit 0)
else
	echo "Not implemented yet"
endif