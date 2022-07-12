CC = g++
CFLAGS = -pedantic -std=c++11 -w -MMD -g3 -g -fPIC\
		 -W -Wall -Wextra -Wshadow -Wcast-align -Wcast-qual -Wctor-dtor-privacy\
		 -Wdisabled-optimization -Wformat=2 -Wlogical-op -Wmissing-declarations\
		 -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wredundant-decls\
		 -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef\
		 -Wzero-as-null-pointer-constant -Wuseless-cast -Wnon-virtual-dtor

INCLUDES = -I.
LIBS =  

SRC = ${wildcard *.cpp}
TESTS = ${SRC:.cpp=.exe}

.PHONY: clean dist-clean dist

all:
	$(MAKE) $(TESTS)

%.exe: %.cpp 
	@echo Building $@
	$(CC) $(CFLAGS) $(INCLUDES) $? -o $@

clean:
	@echo Cleaning...
	@rm -rf *~ *.o prog out.txt *.d

dist-clean: clean
	@rm -rf *.exe
