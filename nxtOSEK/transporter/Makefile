include Makefile.include
PROJECT_ID = 309

# It needs to define this macro to use TOPPERS/JSP
TOPPERS_KERNEL = NXT_JSP

# Target specific macros
TARGET = main

TARGET_CPP_SOURCES = main.cpp MEXU.cpp $(MEXU_GENERATED_FILES)

TOPPERS_JSP_CFG_SOURCE = ./main.cfg

# Don't modify below part
O_PATH ?= build

# makefile for C++(.cpp) build
include ../ecrobot/ecrobot++.mak

downloadAndExpand:
	wget --load-cookies=cookie.txt http://group.clooca.com/download/c/${PROJECT_ID} -O downloaded.zip
	unzip -o downloaded.zip
