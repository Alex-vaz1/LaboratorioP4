CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -Iinclude -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXECUTABLE = $(BINDIR)/principal

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
MAINOBJ = $(OBJDIR)/principal.o

all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS) $(MAINOBJ) | $(BINDIR)
	$(CC) $^ -o $@
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(MAINOBJ): principal.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR):
	mkdir -p $(OBJDIR)
$(BINDIR):
	mkdir -p $(BINDIR)
clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)

