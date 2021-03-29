main: src/main.o src/Arribo.o src/Barco.o src/Barcos/BarcoPesquero.o src/Barcos/BarcoPasajero.o src/Fecha.o src/Puerto.o src/TipoTamanio.o 
	
	mv src/main.o src/Arribo.o src/Barco.o src/Barcos/BarcoPesquero.o src/Barcos/BarcoPasajero.o src/Fecha.o src/Puerto.o src/TipoTamanio.o ./Obj
	g++ obj/*.o -o sistema

main.o: main.cpp

Arribo.o: Arribo.cpp

Barco.o: Barco.cpp

BarcoPesquero.o: BarcoPesquero.cpp

BarcoPasaajero.o: BarcoPasajero.cpp

Fecha.o: Fecha.cpp

Puerto.o: Puerto.cpp

TipoTamanio.o: TipoTamanio.cpp

clean:
	rm -f obj/*.o sistema
	clear

