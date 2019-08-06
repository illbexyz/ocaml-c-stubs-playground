CC			= gcc
CFLAGS		= -Wall -pedantic -Werror -W
LIB_NAME	= playground
SRC_DIR		= src
HEADERS_DIR	= include
BUILD_DIR	= build
STATIC_DIR	= $(BUILD_DIR)/static
SHARED_DIR	= $(BUILD_DIR)/shared
DIRS		= $(BUILD_DIR) $(STATIC_DIR) $(SHARED_DIR)
LIB_PATH = $(shell pwd)

.PHONY: all dirs install clean

all: dirs $(BUILD_DIR)/lib$(LIB_NAME).a $(BUILD_DIR)/lib$(LIB_NAME).so

$(BUILD_DIR)/lib$(LIB_NAME).a: $(STATIC_DIR)/$(LIB_NAME).o
	ar rcs $@ $<

$(BUILD_DIR)/lib$(LIB_NAME).so: $(SHARED_DIR)/$(LIB_NAME).o
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
