default: output
output: main.o linked.o node.o car.o bus.o truck.o
		g++ main.o linked.o node.o car.o bus.o truck.o -o output
main.o: main.cpp
		g++ -c main.cpp -o main.o
linked.o: linked.cpp
		g++ -c linked.cpp -o linked.o
node.o: node.cpp
		g++ -c node.cpp -o node.o
car.o: car.cpp
		g++ -c car.cpp -o car.o
bus.o: bus.cpp
		g++ -c bus.cpp -o bus.o
truck.o: truck.cpp
		g++ -c truck.cpp -o truck.o
clean:
		-rm -f main main.o linked.o node.o car.o bus.o truck.o
