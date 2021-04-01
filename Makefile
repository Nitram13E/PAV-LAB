main: src/main.o src/Class/Arribo.o src/Class/Barco.o src/Class/Puerto.o src/Class/Barcos/BarcoPasajero.o src/Class/Barcos/BarcoPesquero.o src/DataTypes/DtArribo.o src/DataTypes/DtBarco.o src/DataTypes/DtFecha.o src/DataTypes/DtPuerto.o src/DataTypes/Barcos/DtBarcoPasajero.o src/DataTypes/Barcos/DtBarcoPesquero.o
	
	mv src/main.o src/Class/Arribo.o src/Class/Barco.o src/Class/Puerto.o src/Class/Barcos/BarcoPasajero.o src/Class/Barcos/BarcoPesquero.o ./Obj
	mv src/DataTypes/DtArribo.o src/DataTypes/DtBarco.o src/DataTypes/DtFecha.o src/DataTypes/DtPuerto.o src/DataTypes/Barcos/DtBarcoPasajero.o src/DataTypes/Barcos/DtBarcoPesquero.o ./obj
	g++ obj/*.o -o sistema

main.o: main.cpp

Arribo.o: Arribo.cpp

Barco.o: Barco.cpp

BarcoPesquero.o: BarcoPesquero.cpp

BarcoPasajero.o: BarcoPasajero.cpp

Puerto.o: Puerto.cpp

DtFecha.o: DtFecha.cpp

DtArribo.o: DtArribo.cpp

DtBarco.o: DtBarco.cpp

DtBarcoPesquero.o: DtBarcoPesquero.cpp

DtBarcoPasajero.o: DtBarcoPasajero.cpp

DtPuerto.o: DtPuerto.cpp

clean:
	rm -f obj/*.o sistema
	clear

