CC        = gcc
CFLAGS   += -Wall -Wextra
CPPFLAGS +=
LDFLAGS  +=
LDLIBS   +=

PROGRAMS = \
	exercise_1-01 \
	exercise_1-02 \
	exercise_1-03 \
	exercise_1-04 \
	exercise_1-05 \
	exercise_1-06 \
	exercise_1-07 \
	exercise_1-08 \
	exercise_1-09 \
	exercise_1-10 \
	exercise_1-11 \
	exercise_1-12 \
	exercise_1-13 \
	exercise_1-14 \
	exercise_1-15 \
	exercise_1-16 \
	exercise_1-17 \
	exercise_1-18 \
	exercise_1-19 \
	exercise_1-20 \
	exercise_1-21 \
	exercise_1-22 \
	exercise_1-23 \
	exercise_1-24 \
	exercise_2-01 \
	exercise_2-02 \
	exercise_2-03 \
	exercise_2-04 \
	exercise_2-05 \
	exercise_2-06 \
	exercise_2-07 \
	exercise_2-08 \
	exercise_2-09 \
	exercise_2-10 \
	exercise_3-01 \
	exercise_3-02 \
	exercise_3-03 \
	exercise_3-04 \
	exercise_3-05 \
	exercise_3-06 \
	exercise_4-01 \
	exercise_4-02 \
	exercise_4-03 \
	exercise_4-04 \
	exercise_4-05 \
	exercise_4-06 \
	exercise_4-07 \
	exercise_4-08 \
	exercise_4-09 \
	exercise_4-10 \
	exercise_4-11 \
	exercise_4-12 \
	exercise_4-13 \
	exercise_5-01 \
	exercise_5-02 \
	exercise_5-03 \
	exercise_5-04 \
	exercise_5-05 \
	exercise_5-06 \
	exercise_5-07 \
	exercise_5-08 \
	exercise_5-09 \
	exercise_5-10 \
	exercise_5-11 \
	exercise_5-12 \
	exercise_5-13 \
	exercise_5-14 \
	exercise_5-15 \
	exercise_5-16 \
	exercise_5-17 \
	exercise_5-18 \
	exercise_5-19 \
	exercise_5-20 \
	exercise_6-01 \
	exercise_6-02 \
	exercise_6-03 \
	exercise_6-04 \
	exercise_6-05 \
	exercise_6-06 \
	exercise_7-01 \
	exercise_7-02 \
	exercise_7-03 \
	exercise_7-04 \
	exercise_7-06 \
	exercise_7-07 \
	exercise_7-08 \
	exercise_7-09 \
	exercise_8-01 \
	exercise_8-02 \
	exercise_8-03 \
	exercise_8-04 \
	exercise_8-05 \
	exercise_8-06 \
	exercise_8-07 \
	exercise_8-08 \

LIBRARIES =

all: $(LIBRARIES) $(PROGRAMS)

check: all

#example: example.o obj2.o

$(LIBRARIES): %.a:
	ar -rv $@ $^
	ranlib $@

$(PROGRAMS): %: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o: %.C
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

%: %.rl
	ragel -o $@ $<

.PHONY: all check clean
clean:
	rm -f $(PROGRAMS) core *.o .*.dep

.%.dep: %.c
	@$(CC)  $(CFLAGS)   -M $(CPPFLAGS) $< > $@

.%.dep: %.cc
	@$(CXX) $(CXXFLAGS) -M $(CPPFLAGS) $< > $@

.%.dep: %.cpp
	@$(CXX) $(CXXFLAGS) -M $(CPPFLAGS) $< > $@

.%.dep: %.cxx
	@$(CXX) $(CXXFLAGS) -M $(CPPFLAGS) $< > $@

.%.dep: %.C
	@$(CXX) $(CXXFLAGS) -M $(CPPFLAGS) $< > $@

-include $(patsubst   %.c,.%.dep, $(wildcard   *.c))
-include $(patsubst  %.cc,.%.dep, $(wildcard  *.cc))
-include $(patsubst %.cpp,.%.dep, $(wildcard *.cpp))
-include $(patsubst %.cxx,.%.dep, $(wildcard *.cxx))
-include $(patsubst   %.C,.%.dep, $(wildcard   *.C))

