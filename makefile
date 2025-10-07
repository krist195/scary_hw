CC = gcc




all: 3i1 3i2 3i3 4i1 4i2 4i3

3i1:
	$(CC) 3zadanije/3i1/Header/*.c -o 3zadanije/3i1/Header/main.o

3i2:
	$(CC) 3zadanije/3i2/Header/*.c -o 3zadanije/3i2/Header/main.o

3i3:
	$(CC) 3zadanije/3i3/Header/*.c -o 3zadanije/3i3/Header/main.o

4i1:
	$(CC) 4zadanija/4i1/Header/*.c -o 4zadanija/4i1/Header/main.o

4i2:
	$(CC) 4zadanija/4i2/Header/*.c -o 4zadanija/4i2/Header/main.o

4i3:
	$(CC) 4zadanija/4i3/Header/*.c -o 4zadanija/4i3/Header/main.o

clean:
	rm -f 3zadanije/3i1/Header/main.o \
	      3zadanije/3i2/Header/main.o \
	      3zadanije/3i3/Header/main.o \
	      4zadanija/4i1/Header/main.o \
	      4zadanija/4i2/Header/main.o \
	      4zadanija/4i3/Header/main.o


