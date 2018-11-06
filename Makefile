srcdir := .
builddir := build
outdir := bin
CC ?= gcc
CXX ?= g++
LD = g++
CPREFLAGS := -I $(srcdir) --std=c++11
CFLAGS := -Wall -Wextra -pedantic -O2 -fPIC $(CPREFLAGS)
CXXFLAGS := $(CFLAGS)
LDFLAGS = -fPIC
CSOURCES := $(shell find $(srcdir) -type f -name "*.c")
CXXSOURCES := $(shell find $(srcdir) -type f -name "*.cpp")
COBJS := $(CSOURCES:$(srcdir)/%.c=$(builddir)/%.c.o)
CXXOBJS := $(CXXSOURCES:$(srcdir)/%.cpp=$(builddir)/%.cxx.o)
CDEPS := $(SOURCES:$(srcdir)/%.c=$(builddir)/%.c.d)
CXXDEPS := $(CXXSOURCES:$(srcdir)/%.cpp=$(builddir)/%.cxx.d)
TARGET := $(outdir)/ksicamp-the-game
INSTALLTARGET := /usr/local/bin/ksicamp-the-game

all: $(TARGET)

$(TARGET): $(COBJS) $(CXXOBJS)
	@echo Linking $@
	@mkdir -p $(outdir)
	$(LD) $+ $(LDFLAGS) -o $@

$(builddir)/%.c.o: $(srcdir)/%.c $(builddir)/%.c.d
	@echo Building $@
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) -c -o $@ $<

$(builddir)/%.cxx.o: $(srcdir)/%.cpp $(builddir)/%.cxx.d
	@echo Building $@
	@mkdir -p "$(@D)"
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(builddir)/%.c.d: $(srcdir)/%.c
	@echo Generating dependency list for $<
	@mkdir -p "$(@D)"
	$(CC) -MM -MP $(CPREFLAGS) $< | sed -r -e "1 s|^|$(@D)/|" -e "s^.o:^.o $@ :^" > $@

$(builddir)/%.cxx.d: $(srcdir)/%.cpp
	@echo Generating dependency list for $<
	@mkdir -p "$(@D)"
	$(CXX) -MM -MP $(CPREFLAGS) $< | sed -r -e "1 s|^|$(@D)/|" -e "s^.o:^.o $@ :^" > $@

clean:
	rm -rf $(builddir)
	rm -rf $(outdir)

install:
	cp $(TARGET) $(INSTALLTARGET)
uninstall:
	rm $(INSTALLTARGET)

.PHONY: all clean install uninstall
.SECONDARY:
.SUFFIXES:
-include $(CDEPS) $(CXXDEPS)
