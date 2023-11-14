all: testCambio testDyV testMochila

testDyV: test_DyV.cpp DyV.h
	g++ -o testDyV test_DyV.cpp DyV.h

testCambio: monedas.cpp
	g++ -o testCambio monedas1.cpp

testMochila: mochila.cpp
	g++ -o testMochila mochila.cpp

clean:
	rm -r *.o *.gch
