#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salidaDatos.h"
#include "Jugador.h"
#include "Seleccion.h"



void listarJugadoresNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones){
	Jugador *pJugador;
	int idSeleccionJugador;
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
	printf("|%*s||%*s||%*s||%*s||%*s||%*s|\n", 5, "Id", 30, "Nombre", 4, "Edad", 25, "Posicion", 15, "Nacionalidad"
			, 15, "Seleccion");
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
	for(int i = 0; i < ll_len(pArrayListJugador); i++){
		pJugador = ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
		if(idSeleccionJugador == 0){
			listarJugador(pJugador, "No convocado");
		}
	}
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
}

void listarSeleccionesPorConvocar(LinkedList* pArrayListSelecciones){
	Seleccion *pSeleccion;
	int cantidadConvocados;
	printf("+-----++--------------------++--------------------++----------+\n");
	printf("|%*s||%*s||%*s||%*s|\n", 5, "Id", 20, "Pais", 20, "Confederacion", 10, "Convocados");
	printf("+-----++--------------------++--------------------++----------+\n");
	for(int i = 0; i < ll_len(pArrayListSelecciones); i ++){
		pSeleccion = ll_get(pArrayListSelecciones, i);
		selec_getConvocados(pSeleccion, &cantidadConvocados);
		if (cantidadConvocados < 22) {
			listarSeleccion(pSeleccion);
		}
	}
	printf("+-----++--------------------++--------------------++----------+\n");
}

void listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones){
	Jugador *pJugador;
	int idSeleccionJugador;
	Seleccion *pSeleccion;
	int idSeleccion;
	char nombreSeleccion[30];
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
	printf("|%*s||%*s||%*s||%*s||%*s||%*s|\n", 5, "Id", 30, "Nombre", 4, "Edad", 25, "Posicion", 15, "Nacionalidad"
			, 15, "Seleccion");
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
	for(int i = 0; i < ll_len(pArrayListJugador); i++){
		pJugador = ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
		if(idSeleccionJugador != 0){
			for(int j = 0; j < ll_len(pArrayListSelecciones); j++){
				pSeleccion = ll_get(pArrayListSelecciones, j);
				selec_getId(pSeleccion, &idSeleccion);
				if (idSeleccionJugador == idSeleccion) {
					selec_getPais(pSeleccion, nombreSeleccion);
					listarJugador(pJugador, nombreSeleccion);
				}
			}
		}
	}
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
}

void listarSelecciones(LinkedList* pArrayListSelecciones){
	Seleccion *pSeleccion;
	printf("+-----++--------------------++--------------------++----------+\n");
	printf("|%*s||%*s||%*s||%*s|\n", 5, "Id", 20, "Pais", 20, "Confederacion", 10, "Convocados");
	printf("+-----++--------------------++--------------------++----------+\n");
	for(int i = 0; i < ll_len(pArrayListSelecciones); i ++){
		pSeleccion = ll_get(pArrayListSelecciones, i);
		listarSeleccion(pSeleccion);
	}
	printf("+-----++--------------------++--------------------++----------+\n");
}

void listarSeleccion(Seleccion *pSelecicon){

	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	selec_getId(pSelecicon, &id);
	selec_getPais(pSelecicon, pais);
	selec_getConfederacion(pSelecicon, confederacion);
	selec_getConvocados(pSelecicon, &convocados);

	printf("|%*d||%*s||%*s||%*d|\n", 5, id, 20, pais, 20, confederacion, 10, convocados);
}

void listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones){
	Jugador *pJugador;
	int idSeleccionJugador;
	Seleccion *pSeleccion;
	int idSeleccion;
	char nombreSeleccion[30];
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
	printf("|%*s||%*s||%*s||%*s||%*s||%*s|\n", 5, "Id", 30, "Nombre", 4, "Edad", 25, "Posicion", 15, "Nacionalidad"
			, 15, "Seleccion");
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
	for(int i = 0; i < ll_len(pArrayListJugador); i++){
		pJugador = ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
		if(idSeleccionJugador != 0){
			for(int j = 0; j < ll_len(pArrayListSelecciones); j++){
				pSeleccion = ll_get(pArrayListSelecciones, j);
				selec_getId(pSeleccion, &idSeleccion);
				if (idSeleccionJugador == idSeleccion) {
					selec_getPais(pSeleccion, nombreSeleccion);
					listarJugador(pJugador, nombreSeleccion);
				}
			}
		}else{
			listarJugador(pJugador, "No convocado");
		}
	}
	printf("+-----++------------------------------++----++-------------------------++---------------++--------------+\n");
}

void listarJugador(Jugador *pJugador, char *seleccion){
	int id;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];

	jug_getId(pJugador, &id);
	jug_getNombreCompleto(pJugador, nombre);
	jug_getEdad(pJugador, &edad);
	jug_getPosicion(pJugador, posicion);
	jug_getNacionalidad(pJugador, nacionalidad);

	printf("|%*d||%*s||%*d||%*s||%*s||%*s|\n", 5, id, 30, nombre, 4, edad, 25, posicion, 15, nacionalidad
				, 15, seleccion);
}

void imprimirMenuOnceOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5, char *mensaje6,
		char *mensaje7, char *mensaje8, char *mensaje9, char *mensaje10, char *mensaje11){
	printf("----------------------------\n");
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("%s\n", mensaje3);
	printf("%s\n", mensaje4);
	printf("%s\n", mensaje5);
	printf("%s\n", mensaje6);
	printf("%s\n", mensaje7);
	printf("%s\n", mensaje8);
	printf("%s\n", mensaje9);
	printf("%s\n", mensaje10);
	printf("%s\n", mensaje11);
	printf("----------------------------\n");
}

void imprimirMenuCincoOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5){
	printf("----------------------------\n");
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("%s\n", mensaje3);
	printf("%s\n", mensaje4);
	printf("%s\n", mensaje5);
	printf("----------------------------\n");
}

void imprimirMenuCuatroOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4){
	printf("----------------------------\n");
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("%s\n", mensaje3);
	printf("%s\n", mensaje4);
	printf("----------------------------\n");
}

void imprimirMenuDosOpciones(char *mensaje1, char *mensaje2){
	printf("----------------------------\n");
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("----------------------------\n");
}

void imprimirMenuTresOpciones(char *mensaje1, char *mensaje2, char *mensaje3){
	printf("----------------------------\n");
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("%s\n", mensaje3);
	printf("----------------------------\n");
}

void imprimirMenuSeisOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5, char *mensaje6){
	printf("----------------------------\n");
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("%s\n", mensaje3);
	printf("%s\n", mensaje4);
	printf("%s\n", mensaje5);
	printf("%s\n", mensaje6);
	printf("----------------------------\n");
}
