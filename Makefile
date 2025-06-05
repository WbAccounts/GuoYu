OBJS += main.cpp

CPPFLAGS += -std=c++11

test : $(OBJS)
	$(CXX) $(CPPFLAGS) -o test $(OBJS)
