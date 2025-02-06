clang++ -c -o uuid.o ../uuid.cpp
clang++ -c -o main.o main.cpp
clang++ -o main main.o uuid.o

rm *.o
