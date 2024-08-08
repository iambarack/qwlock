CC=g++
CFLAGS=
DEPS = main.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: main.cpp
	g++ -c main.cpp -o build/main.o
	g++ -o build/main.exe build/main.o
	.\build\main.exe
hellomake: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	del /Q /F .\build\main.exe .\build\*.o