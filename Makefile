srcdir := .
builddir := build
outdir := bin
CC ?= gcc
CXX ?= g++
LD = g++
CPREFLAGS := -I $(srcdir) --std=c++11
CFLAGS := -Wall -Wextra -Werror -pedantic -O2 -fPIC $(CPREFLAGS)
CXXFLAGS := $(CFLAGS)
LDFLAGS = -fPIC
CSOURCES := $(shell find $(srcdir) -type f -name "*.c")
CHEADERS := $(shell find $(srcdir) -type f -name "*.h")
CXXSOURCES := $(shell find $(srcdir) -type f -name "*.cpp")
CXXHEADERS := $(shell find $(srcdir) -type f -name "*.hxx")
CODESOURCES := $(CHEADERS) $(CSOURCES) $(CXXHEADERS) $(CXXSOURCES)
COBJS := $(CSOURCES:$(srcdir)/%.c=$(builddir)/%.c.o)
CXXOBJS := $(CXXSOURCES:$(srcdir)/%.cpp=$(builddir)/%.cxx.o)
CDEPS := $(SOURCES:$(srcdir)/%.c=$(builddir)/%.c.d)
CXXDEPS := $(CXXSOURCES:$(srcdir)/%.cpp=$(builddir)/%.cxx.d)
TARGET := $(outdir)/ksicamp-the-game
INSTALLTARGET := /usr/local/bin/ksicamp-the-game
CLANGTIDYOPTS := --checks='-*,bugprone-*,cert-*,cppcoreguidelines-*,-cppcoreguidelines-pro-bounds-constant-array-index,clang-analyzer-*,modernize-*,performance-*,portability-*,readability-*,google-*,-google-runtime-references'

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

lint:
	cpplint --filter "-legal/copyright,-runtime/references,-build/c++11" $(CODESOURCES)
	clang-tidy $(CLANGTIDYOPTS) $(CSOURCES) $(CXXSOURCES)

fix:
	clang-format -style=Google -i $(CODESOURCES)
	clang-tidy $(CLANGTIDYOPTS) -fix -format-style=Google $(CSOURCES) $(CXXSOURCES)

.PHONY: all clean install uninstall
.SECONDARY:
.SUFFIXES:
-include $(CDEPS) $(CXXDEPS)
