target=main
LDFLAGS+=/usr/local/lib
INCLUDES+=/usr/local/include/
CFLAGS=-Wall
#CFLAGS=-Wall -lstdc++

$(target): $(target).o
	$(CXX) -pg -L$(LDFLAGS) $< -o $@

$(target).o: $(target).cpp
	$(CXX) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
