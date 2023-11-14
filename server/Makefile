all:
	g++ -c -I includes src/Order.cpp -o build/Order.o
	g++ -c -I includes src/Dispachante.cpp -o build/Dispachante.o
	g++ -c -I includes src/restaurante.cpp -o build/restaurante.o
	g++ -c -I includes src/Menu.cpp -o build/Menu.o
	g++ -c -I includes src/Message.cpp -o build/Message.o
	g++ -c -I includes src/Server.cpp -o build/Server.o
	g++ -c -I includes src/esqueleto.cpp -o build/esqueleto.o
	g++ -I includes build/*.o src/Main.cpp -o build/Main
	

	rm -r build/*.o