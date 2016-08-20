# dwm version
VERSION = "6.1-slankdev"

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2
# OpenBSD (uncomment)
FREETYPEINC = ${X11INC}/freetype2

# includes and libs
INCS = -I${X11INC} -I${FREETYPEINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS}

# flags
CPPFLAGS =  -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CPPFLAGS += -D_DEFAULT_SOURCE 
CXXFLAGS =  -std=c++11
CXXFLAGS += -pedantic
CXXFLAGS += -Wall -Wextra
CXXFLAGS += -Wno-deprecated-declarations
CXXFLAGS += -Wno-unused-parameter
CXXFLAGS += -g -O0 -Os ${INCS} ${CPPFLAGS}
CXXFLAGS += -I/usr/include/freetype2
LDFLAGS  = -s ${LIBS}

# compiler and linker
CXX = g++
