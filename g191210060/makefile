run: compile link run
compile:
	g++ -c ./src/node.cpp -o ./lib/node.o
	g++ -c ./src/tree.cpp -o ./lib/tree.o
	g++ -c ./src/stack.cpp -o ./lib/stack.o
	g++ -c ./src/stacknode.cpp -o ./lib/stacknode.o
	g++ -c ./src/treeparent.cpp -o ./lib/treeparent.o
	g++ -c ./src/main.cpp -o ./lib/main.o
link:
	g++ ./lib/node.o ./lib/tree.o ./lib/stack.o ./lib/stacknode.o ./lib/treeparent.o ./lib/main.o -o ./bin/program
run:
	./bin/program