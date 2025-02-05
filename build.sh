clang++ -std=c++11 -c -o uuid.o uuid.cpp
clang++ -std=c++11 -c -o main.o main.cpp
clang++ -std=c++11 -o main main.o uuid.o

rm *.o
