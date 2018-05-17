all: main seq

main: main.c
	gcc -fopenmp -O3 ./main.c -o ./bin/main.out  -lm 

seq: sequential.c
	gcc -O3 ./sequential.c -o ./bin/sequential.out  -lm 

run:
	./bin/main.out

clean:
	rm -r ./bin/*.out
