nullstring :=
space := $(nullstring) # end of the line

CC := clang #--analyze

SRCDIR := src
TEST_DIR := tests
BUILDDIR := build
BUILD_TEST_DIR := build/test
TARGET := bin/runner

SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TEST_SRC := $(shell find $(TEST_DIR) -type f -name *.$(SRCEXT))
# call func  $(functionname  arg1,arg2,arg3...)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TEST_OBJS := $(patsubst $(TEST_DIR)/%,$(BUILD_TEST_DIR)/%,$(TEST_SRC:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
#LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include

# DIR_INC=./include
# DIR_SRC=./src
# DIR_OJB=./obj
# DIR_BIN=./build
# DIR_TEST=./tests
#
# SRC = $(wildcard ${DIR_SRC}/*.c)
# OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC}))

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILD_TEST_DIR)/%.o: $(TEST_DIR)/%.$(SRCEXT)
	@mkdir -p $(BUILD_TEST_DIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean


# Tests
test: $(TEST_OBJS) $(OBJECTS)
	@echo $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ $(INC) $(LIB) -o ./bin/tester
	@echo "\n=========run test============"
	@-(./bin/tester)

.PHONY: test
