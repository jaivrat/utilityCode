#############################################################################
# A Smart Makefile
# Author : JAI VRAT SINGH
# Why Smart Makefile: It reads all cpp files from the current source directory
#                     and builds the source code. So to create any new project
#                     just copy this Makefile to your directory. It will build
#                     for you
# Reference http://stackoverflow.com/questions/2908057/makefiles-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary
# Template: app
#############################################################################

#QuantLibincludes : /usr/local/include/  in this we have ql/*.h
#Quanlib lib files: /usr/local/lib 
####### Compiler, tools and options

CC	=	gcc
CXX	=	g++
CFLAGS	=	-pipe -Wall -W -O2 -DNO_DEBUG
CXXFLAGS=	-g 
INCPATH	=	-I$(HOME)/work/3rdParty/macInstalls/boost/include -I/usr/local/include 
#LIBPATH	=	-L/usr/local/lib -L/Users/jaivrat/work/3rdParty/macInstalls/boost/lib -L/Users/jaivrat/Library/Developer/Xcode/DerivedData/TestCPPDyn-eurdpjkdhlgtlpbvieghgxipgjxq/Build/Products/Debug
LIBPATH	=	-L/usr/local/lib -L/Users/jaivrat/work/3rdParty/macInstalls/boost/lib
LINK	=	g++
LFLAGS	=	
#LIBS	=	-lm -lQuantLib #-lTestCPPDyn
#LIBS	=	-lm -lQuantLib
LIBS	=	-lm
REMOVE	=	rm -f

####### Files
HEADERS =	
SOURCES := $(wildcard *.cpp)
OBJECTS := $(addprefix ,$(notdir $(SOURCES:.cpp=.o)))
TARGET	=	a.out

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .C .c

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(REMOVE) $(TARGET) 
	$(LINK) $(LFLAGS) $(LIBPATH) -o $@ $^  $(LIBS)

clean:
	$(REMOVE) $(OBJECTS) $(TARGET)
	$(REMOVE) core *~

