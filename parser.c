#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "salidaDatos.h"
#include "pedirDatos.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
* \param pFile archivo abierto donde se va a guardar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param id se pasa por referencia el id para poder guardar el valor del id y hacerlo autoincremental
 * \return int retorna 0 si se cargo correctamente o -1 sino
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador, int *id)
{
	int ret = -1;
	int camposLeidos;
	char buffer[6][100];
	Jugador *jugadorAux;
	int contError = 0;
	char idTexto[30];

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3], buffer[4], buffer[5]);
	fscanf(pFile,"%[^\n]\n",idTexto);

	*id = atoi(idTexto);

	do{
		camposLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3], buffer[4], buffer[5]);
		if (camposLeidos == 6) {
			jugadorAux = jug_newParametros(buffer[0],buffer[1],buffer[2],buffer[3], buffer[4], buffer[5]);
			ll_add(pArrayListJugador, jugadorAux);
		}else{
			contError++;
		}
	}while(!feof(pFile));

	if (contError == 0) {
		ret = 0;
	}
    return ret;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
* \param pFile archivo abierto donde se va a guardar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param id se pasa por referencia el id para poder guardar el valor del id y hacerlo autoincremental
 * \return int retorna 0 si se cargo correctamente o -1 sino
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, int *id)
{
	int ret = -1;
	int cantidadLeida;
	Jugador *jugadorAux = jug_new();
	char idTexto[30];


	fscanf(pFile,"%[^\n]\n",idTexto);
	*id = atoi(idTexto);

	while(!feof(pFile)){
		cantidadLeida = fread(jugadorAux, sizeof(Jugador), 1, pFile);
		if (cantidadLeida == 1) {
			ll_add(pArrayListJugador, jugadorAux);
			ret = 0;
		}
	}

	return ret;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
* \param pFile archivo abierto donde se va a guardar
 * \param pArrayListSeleccion LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se cargo correctamente o -1 sino
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	int camposLeidos;
	char buffer[4][100];
	Seleccion *seleccionAux;
	int contError = 0;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

	do{
		camposLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		if (camposLeidos == 4) {
			seleccionAux = selec_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
			ll_add(pArrayListSeleccion, seleccionAux);
		}else{
			contError++;
		}
	}while(!feof(pFile));

	if (contError == 0) {
		ret = 0;
	}
	return ret;
}
/**
 * @brief guarda en binario los jugadores convocados de una confederacion seleccionada por el usuario
 *
* \param pFile archivo abierto donde se va a guardar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param pArrayListSeleccion lista donde se guardan las selecciones
 * \param id para guardar en el archivo el ultimo id utilizado
 * \return int retorna 0 si se cargo correctamente o -1 sino
 */
int parser_guardarJugadorEnBinario(FILE *pFile, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int id){
	char confederacionAcargar[30];
	int opcion;
	Jugador *pJugador;
	Seleccion *pSeleccion;
	int idSeleccionJugador;
	int idSeleccion;
	char confederacionSeleccion[30];
	int ret = -1;
	int cantidadEscrita;

	fprintf(pFile, "%d\n", id);

	imprimirMenuCincoOpciones("1:AFC", "2:CAF","3:CONCACAF" ,"4:CONMEBOL", "5:UEFA");
	if (utn_getEnteroConMaxMin(&opcion, "Ingrese la confederacion a guardar", "Error, tiene que ser una de las opciones", 1, 5, 3) == 0) {
		switch(opcion){
		case 1:
			strcpy(confederacionAcargar, "AFC");
			break;
		case 2:
			strcpy(confederacionAcargar, "CAF");
			break;
		case 3:
			strcpy(confederacionAcargar, "CONCACAF");
			break;
		case 4:
			strcpy(confederacionAcargar, "CONMEBOL");
			break;
		case 5:
			strcpy(confederacionAcargar, "UEFA");
			break;
		}
		for(int i= 0; i < ll_len(pArrayListJugador); i++){
			pJugador = ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
			if (idSeleccionJugador != 0) {
				for(int j = 0; j < ll_len(pArrayListSeleccion); j++){
					pSeleccion = ll_get(pArrayListSeleccion, j);
					selec_getId(pSeleccion, &idSeleccion);
					selec_getConfederacion(pSeleccion, confederacionSeleccion);
					if (idSeleccionJugador == idSeleccion && strcmp(confederacionAcargar, confederacionSeleccion) == 0) {
						cantidadEscrita = fwrite(pJugador, sizeof(Jugador), 1, pFile);
						if (cantidadEscrita >= 1) {
							ret = 0;
						}
					}
				}
			}
		}
	}else{
		printf("Error al elegir la opcion\n");
	}
	return ret;
}
/**
 * @brief guarda la lista de jugadores en un archivo de texto
 *
 * \param pFile archivo abierto donde se va a guardar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param id para guardar en el archivo el ultimo id utilizado
 * \return int retorna 0 si se cargo correctamente o -1 sino
 */
int parser_guardarJugadorEnTexto(FILE *pFile, LinkedList* pArrayListJugador, int id){
	int ret = -1;
	Jugador *pJugador;
	int idSeleccion;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idJugador;

	fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","nombreCompleto","edad","posicion","nacionalidad","idSeleccion");
	fprintf(pFile, "%d\n", id);

	for(int i = 0; i < ll_len(pArrayListJugador); i++){
		pJugador = ll_get(pArrayListJugador, i);
		jug_getEdad(pJugador, &edad);
		jug_getNombreCompleto(pJugador, nombre);
		jug_getId(pJugador, &idJugador);
		jug_getNacionalidad(pJugador, nacionalidad);
		jug_getPosicion(pJugador, posicion);
		jug_getSIdSeleccion(pJugador, &idSeleccion);
		fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",idJugador,nombre,edad,posicion,nacionalidad,idSeleccion);
		ret = 0;
	}
	return ret;
}
/**
 * @brief guarda la lista de selecciones en un arhivo de texto
 *
* \param pFile archivo abierto donde se va a guardar
 * @param pArrayListSeleccion lista donde estan guardadas las selecciones
 * \return int retorna 0 si se cargo correctamente o -1 sino
 */
int parser_guardarSeleccionEnTexto(FILE *pFile, LinkedList* pArrayListSeleccion){
	int ret = -1;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	Seleccion *pSeleccion;

	fprintf(pFile,"%s,%s,%s,%s\n","id","pais","confederacion","convocados");

	for(int i = 0; i < ll_len(pArrayListSeleccion); i++){
		pSeleccion = ll_get(pArrayListSeleccion, i);
		selec_getId(pSeleccion, &id);
		selec_getPais(pSeleccion, pais);
		selec_getConfederacion(pSeleccion, confederacion);
		selec_getConvocados(pSeleccion, &convocados);

		fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
		ret = 0;
	}

	return ret;
}
