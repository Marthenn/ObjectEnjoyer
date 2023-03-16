CC = g++
STD = -std=c++17

OBJECTS = src/main.cpp $(filter-out src/Classes/*/main.cpp, $(wildcard src/Classes/*/*.cpp))
CINCLUDES = -Isrc -Isrc/Classes -Isrc/Classes/DeckPlayer/ -Isrc/Classes/Player/PlayerException

TARGET = bin/main

run : build
	$(TARGET)
build :
	$(CC) $(STD) $(CINCLUDES) $(OBJECTS) -o $(TARGET)

