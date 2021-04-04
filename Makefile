exec = programa #Nombre del archivo ejecutable

obj = src/main.o \
	  \
	  src/Class/Arribo.o \
	  src/Class/Barco.o \
	  src/Class/Barcos/BarcoPasajero.o \
	  src/Class/Barcos/BarcoPesquero.o \
	  src/Class/Puerto.o \
	  \
	  src/DataTypes/DtArribo.o \
	  src/DataTypes/DtBarco.o \
	  src/DataTypes/Barcos/DtBarcoPasajero.o \
	  src/DataTypes/Barcos/DtBarcoPesquero.o \
	  src/DataTypes/DtPuerto.o \
	  src/DataTypes/DtFecha.o

all: $(obj)
	@ mv $(obj) ./obj
	g++ obj/*.o -o $(exec)
	@ echo "\nEjecutar con: ./$(exec)"

$(obj): %.o: %.cpp

clean:
	rm -f obj/*.o $(exec)
	clear
