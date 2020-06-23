SRC_DIR := Source
OBJ_DIR := Temp
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

Unary.Make.exe: $(OBJ_FILES)
	g++ -g -ggdb -Wall -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -g -ggdb -Wall -I$(CURDIR)/Include -I$(CURDIR)/../rapidjson/include -c -o $@ $<