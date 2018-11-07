PROJECT      = PrintCanvas
SOURCES      = main.cxx
INCLUDES     = 
OBJECTS      = $(patsubst %.cxx, %.o, $(SOURCES))
ROOTCFLAGS  := $(shell root-config --cflags)
ROOTLIBS    := $(shell root-config --libs)
ROOTGLIBS   := $(shell root-config --glibs)
LIBRARIES := $(shell root-config --libdir)
ROOTINC := $(shell root-config --incdir)
CFLAGS += $(ROOTCFLAGS)
LIBS += $(ROOTLIBS)

LIBS += -lMinuit
LDFLAGS = -O

# LIBS += -lRooFit -lRooFitCore

$(PROJECT): $(OBJECTS)
	g++ -o $@ $(OBJECTS) $(LDFLAGS) $(LIBS) -I$(ROOTINC) -L$(LIBRARIES)

%.o : %.cxx $(INCLUDES)
	g++ ${CFLAGS} -c -g -o $@ $< -I$(ROOTINC) -L$(LIBRARIES)


clean:
	rm -f ${PROJECT} ${OBJECTS}

install:
	cp ${PROJECT} ~/usr/boss/bin/${PROJECT}

test:
	./${PROJECT} ../PrSth.root



