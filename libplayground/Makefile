CC			= gcc
CFLAGS		= -Wall -pedantic -Werror -W -Iinclude
LIB_NAME	= playground
SRC_DIR		= src
HEADERS_DIR	= include
BUILD_DIR	= build
STATIC_DIR	= $(BUILD_DIR)/static
SHARED_DIR	= $(BUILD_DIR)/shared
DIRS		= $(BUILD_DIR) $(STATIC_DIR) $(SHARED_DIR)
LIB_PATH 	= $(shell pwd)

SRC_FILES	= playground.c animal.c

STATIC_OBJ_FILES	= $(addprefix $(STATIC_DIR)/, $(SRC_FILES:.c=.o))
SHARED_OBJ_FILES	= $(addprefix $(SHARED_DIR)/, $(SRC_FILES:.c=.o))

.PHONY: all dirs install clean

all: dirs $(BUILD_DIR)/lib$(LIB_NAME).a $(BUILD_DIR)/lib$(LIB_NAME).so

$(BUILD_DIR)/lib$(LIB_NAME).a: $(STATIC_OBJ_FILES)
	ar rcs $@ $^

$(BUILD_DIR)/lib$(LIB_NAME).so: $(SHARED_OBJ_FILES)
	$(CC) -shared $^ -L$(HEADERS_DIR) -o $@

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SHARED_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

dirs: $(DIRS)

$(DIRS):
	@mkdir $@

install:
	cp build/libplayground.so /usr/lib/

clean:
	rm -rf $(BUILD_DIR)

