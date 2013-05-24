# $Id$ 

ALL: dynamics

#include ${TAO_DIR}/bmake/tao_common



##target
#dynamics : dynamics.o  membrane_system.o membrane.o tao_chkopts
#	@-${CLINKER} -o dynamics dynamics.o membrane_system.o membrane.o  ${TAO_LIB} ${PETSC_SNES_LIB}
	
dynamics : dynamics.o  membrane_system.o membrane.o 
	g++ -O3 -o dynamics dynamics.o membrane_system.o membrane.o -Wall

dynamics.o : dynamics.C
	g++ -O3 -c dynamics.C 

membrane_system.o : membrane_system.C
	g++ -O3 -c membrane_system.C

membrane.o : membrane.C
	g++ -O3 -c membrane.C -Wall 

##phony
	
clean :
##rm dynamics.o  polymer_system.o
	rm *.o

run :
	./dynamics

all : 
	rm data/*
	make clean
	make
	make run
