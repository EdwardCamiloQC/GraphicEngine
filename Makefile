SRC_DIR = ./src
BUILD_DIR = build
MISLIBS_DIR = /home/edward/Documentos/CodigosC++/MisLibrerias
VPATH = $(SRC_DIR):$(MISLIBS_DIR)

INCLUDES = -I./headers -I./include -I$(MISLIBS_DIR)
LIBRARIES = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
COMPILER = g++
DEBUGER = gdb
FLAGSCPP = -c -Wall
FLAGSDEBUG = -g

PROJECT = $(notdir $(shell pwd))
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
SOURCES += $(wildcard $(MISLIBS_DIR)/figure.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

$(BUILD_DIR)/$(PROJECT) : $(OBJECTS) $(BUILD_DIR)/glad.o
	$(COMPILER) -o $@ $^ $(LIBRARIES) $(INCLUDES)

$(BUILD_DIR)/%.o : %.cpp | $(BUILD_DIR)
	$(COMPILER) $(FLAGSCPP) $(INCLUDES) $< -o $@

$(BUILD_DIR)/glad.o : $(SRC_DIR)/glad.c
	$(COMPILER) $(FLAGSCPP) $(INCLUDES) $< -o $@

$(BUILD_DIR) :
	mkdir $(BUILD_DIR)

runProject :
	./$(BUILD_DIR)/$(PROJECT)

debugProject :
	$(DEBUGER) ./$(BUILD_DIR)/$(PROJECT)

info :
	$(info $(OBJECTS))

clean :
	rm ./$(BUILD_DIR)/*