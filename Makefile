CFLAGS = -Wall -Wextra -Werror

all: geometry

geometry: bin/geometry

bin/geometry: obj/src/geometry/main.o obj/src/staticlib/staticlib.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/geometry/main.o: src/geometry/main.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/staticlib/staticlib.a: obj/src/staticlib/geometryshapes.o obj/src/staticlib/fileread.o
	ar rcs $@ $^

obj/src/staticlib/geometryshapes.o: src/staticlib/geometryshapes.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/staticlib/fileread.o: src/staticlib/fileread.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

.PHONY: clean

clean:
	rm obj/src/staticlib/*.a obj/src/staticlib/*.o obj/src/geometry/*.o bin/geometry
