GCC = g++

Flags = -std=c++17 -Werror

EmptyLineCleaner: LineCleaner.o
	$(GCC) $(Flags) -o EmptyLineCleaner LineCleaner.o

LineCleaner.o: LineCleaner.cpp
	$(GCC) $(Flags) -c LineCleaner.cpp
