#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "pedirDatos.h"
#include "salidaDatos.h"
/**
 * @brief crea un espacio en memoria dinamica para un jugador
 *
 * @return devuelve el puntero al espacio en memoria donde esta el jugador
 */
Jugador* jug_new(){
	Jugador *pJugador;
	pJugador = (Jugador*)malloc(sizeof(Jugador));
	return pJugador;
}
/**
 * @brief crea un espacio en memoria dinamica para un jugador y le da valores
 *
 * @param idStr id que va a tener el jugador
 * @param nombreCompletoStr nombre que va a tener el jugador
 * @param edadStr edad que va a tener el jugador
 * @param posicionStr posicion que va a tener el jugador
 * @param nacionalidadStr nacionalidad que va a tener el jugador
 * @param idSelccionStr id de seleccion que va a tener el jugador
 * @return devuelve el puntero al espacio en memoria donde esta el jugador
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr){
	Jugador *pJugador = jug_new();
	if (pJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL) {
		pJugador->id = atoi(idStr);
		strcpy(pJugador->nombreCompleto, nombreCompletoStr);
		pJugador->edad = atoi(edadStr);
		strcpy(pJugador->posicion, posicionStr);
		strcpy(pJugador->nacionalidad, nacionalidadStr);
		pJugador->idSeleccion = atoi(idSelccionStr);
	}

	return pJugador;
}
/**
 * @brief borra un jugador
 *
 * @param this puntero al espacio en memoria a borrar
 */
void jug_delete(Jugador* this){
	if (this != NULL) {
		free(this);
	}
}
/**
 * @brief le pone valor al campo id de un jugador
 *
 * @param this puntero al jugador
 * @param id id que va a tener el jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_setId(Jugador* this,int id){
	int ret = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor del id de un jugador en la variable id pasada por parametro
 *
 * @param this puntero al jugador
 * @param id variable donde se va a guardar el id
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_getId(Jugador* this,int* id){
	int ret = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}
/**
 * @brief le pone valor al campo nombre de un jugador
 *
 * @param this puntero al jugador
 * @param nombreCompleto valor que se va a guardar en el campo nombre del jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int ret = -1;
	if (this != NULL && nombreCompleto != NULL) {
		strcpy(this->nombreCompleto, nombreCompleto);
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor del nombre de un jugador en la variable nombre pasada por parametro
 *
 * @param this puntero al jugador
 * @param nombreCompleto variable donde se guarda el nombre del jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int ret = -1;
	if (this != NULL && nombreCompleto != NULL) {
		strcpy(nombreCompleto, this->nombreCompleto);
		ret = 0;
	}
	return ret;
}
/**
 * @brief le pone valor al campo posicion de un jugador
 *
 * @param this puntero al jugador
 * @param posicion valor que va a tener el campo posicion
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_setPosicion(Jugador* this,char* posicion){
	int ret = -1;
	if (this != NULL && posicion != NULL) {
		strcpy(this->posicion, posicion);
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor de la posicion de un jugador en la variable posicion pasada por parametro
 *
 * @param this puntero al jugador
 * @param posicion variable donde se va a guardar la posicion del jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_getPosicion(Jugador* this,char* posicion){
	int ret = -1;
	if (this != NULL && posicion != NULL) {
		strcpy(posicion, this->posicion);
		ret = 0;
	}
	return ret;
}
/**
 * @brief le pone valor al campo nacionalidad de un jugador
 *
 * @param this puntero al jugador
 * @param nacionalidad valor que va a tener el campo nacionalidad
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int ret = -1;
	if (this != NULL && nacionalidad != NULL) {
		strcpy(this->nacionalidad, nacionalidad);
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor de la nacionalidad de un jugador en la variable nacionalidad pasada por parametro
 *
 * @param this puntero al jugador
 * @param nacionalidad variable donde se va a guardar la nacionalidad del jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int ret = -1;
	if (this != NULL && nacionalidad != NULL) {
		strcpy(nacionalidad, this->nacionalidad);
		ret = 0;
	}
	return ret;
}
/**
 * @brief le pone valor al campo edad de un jugador
 *
 * @param this puntero al jugador
 * @param edad valor que va a tener el campo edad
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_setEdad(Jugador* this,int edad){
	int ret = -1;
	if (this != NULL && edad > 0 && edad < 60) {
		this->edad = edad;
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor de la edad de un jugador en la variable edad pasada por parametro
 *
 * @param this puntero al jugador
 * @param edad variable donde se va a guardar la edad del jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_getEdad(Jugador* this,int* edad){
	int ret = -1;
	if (this != NULL && edad != NULL) {
		*edad = this->edad;
		ret = 0;
	}
	return ret;
}
/**
 * @brief le pone valor al campo idSeleccion de un jugador
 *
 * @param this puntero al jugador
 * @param idSeleccion valor que va a tener el campo idSeleccion
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int ret = -1;
	if (this != NULL && idSeleccion < 32) {
		this->idSeleccion = idSeleccion;
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor del idSeleccion de un jugador en la variable idSeleccion pasada por parametro
 *
 * @param this puntero al jugador
 * @param idSeleccion variable donde se va a guardar el idSeleccion del jugador
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion){
	int ret = -1;
	if (this != NULL && idSeleccion != NULL) {
		*idSeleccion = this->idSeleccion;
		ret = 0;
	}
	return ret;
}
/**
 * @brief busca un jugador por id
 *
 * @param listaJugadores lista donde estan guardados los jugadores
 * @param idAbuscar id a buscar
 * @param index variable donde se guarda el index del jugador encontrado
 * @return retorna 0 si encontro al jugador o -1 sino
 */
int jug_buscarPorId(LinkedList *listaJugadores, int idAbuscar, int *index){
	int ret = -1;
	Jugador *pJugador;
	int idJugador;

	for(int i = 0; i < ll_len(listaJugadores); i++){
		pJugador = ll_get(listaJugadores, i);
		jug_getId(pJugador, &idJugador);
		if (idAbuscar == idJugador) {
			*index = i;
			ret = 0;
		}
	}

	return ret;
}
/**
 * @brief compara dos nacionalidades de dos jugadoeres
 *
 * @param pJugador1 jugador1
 * @param pJugador2 jugador2
 * @return retorna 1 si la nacionalidad del jugador2 es menor a la del jugador1 o 0 sino
 */
int jug_ordenarJugadoresPorNacionalidad(void *pJugador1, void *pJugador2){

	int ret = 0;
	char nacionalidad1[30];
	char nacionalidad2[30];
	jug_getNacionalidad((Jugador*) pJugador1, nacionalidad1);
	jug_getNacionalidad((Jugador*)pJugador2, nacionalidad2);

	if (stricmp(nacionalidad2, nacionalidad1) < 0) {
		ret = 1;
	}

	return ret;
}
/**
 * @brief compara dos edades de dos jugadoeres
 *
 * @param pJugador1 jugador1
 * @param pJugador2 jugador2
 * @return retorna 1 si la edad del jugador2 es menor a la del jugador1 o 0 sino
 */
int jug_ordenarJugadoresPorEdad(void *pJugador1, void *pJugador2){

	int ret = 0;
	int edad1;
	int edad2;
	jug_getEdad((Jugador*)pJugador1, &edad1);
	jug_getEdad((Jugador*)pJugador2, &edad2);

	if (edad2 < edad1) {
		ret = 1;
	}

	return ret;
}
/**
 * @brief compara dos nombres de dos jugadoeres
 *
 * @param pJugador1 jugador1
 * @param pJugador2 jugador2
 * @return retorna 1 si el nombre del jugador2 es menor al del jugador1 o 0 sino
 */
int jug_ordenarJugadoresPorNombre(void *pJugador1, void *pJugador2){

	int ret = 0;
	char nombre1[100];
	char nombre2[100];
	jug_getNombreCompleto((Jugador*) pJugador1, nombre1);
	jug_getNombreCompleto((Jugador*) pJugador2, nombre2);

	if (stricmp(nombre2, nombre1) < 0) {
		ret = 1;
	}

	return ret;
}
/**
 * @brief convoca un jugador a una seleccion
 *
 * @param pArrayListJugador lista donde estan guardados los jugadores
 * @param pArrayListSeleccion lista donde estan guardados las selecciones
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ret = -1;
	int idJugador;
	int indexJugador;
	Jugador *pJugador;
	int idSeleccionJugador;
	int idSeleccion;
	int indexSeleccion;
	Seleccion *pSeleccion;
	int convocados;

	listarJugadoresNoConvocados(pArrayListJugador, pArrayListSeleccion);
	if (utn_getEnteroConMaxMin(&idJugador, "Ingrese el id del jugador a convocar", "Error, tiene que ser mayor a 0", 1, 99999999, 3) == 0
			&& jug_buscarPorId(pArrayListJugador, idJugador, &indexJugador) == 0) {
		pJugador = ll_get(pArrayListJugador, indexJugador);
		jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
		if (idSeleccionJugador == 0) {
			listarSeleccionesPorConvocar(pArrayListSeleccion);
			if (utn_getEnteroConMaxMin(&idSeleccion, "Ingrese el id de la seleccion a convocar", "Error, tiene que ser mayor a 0", 1, 99999999, 3) == 0
					&& selec_buscarPorId(pArrayListSeleccion, idSeleccion, &indexSeleccion) == 0) {
				pSeleccion = ll_get(pArrayListSeleccion, indexSeleccion);
				selec_getConvocados(pSeleccion, &convocados);
				if (convocados < 22) {
					convocados++;
					selec_setConvocados(pSeleccion, convocados);
					jug_setIdSeleccion(pJugador, idSeleccion);
					ret = 0;
				}else{
					printf("Esa seleccion ya tiene todos los convocados\n");
				}
			} else {
				printf("No existe seleccion con ese id\n");
			}
		}else{
			printf("Ese jugador ya tiene una seleccion\n");
		}
	}else{
		printf("No existe jugador con ese id\n");
	}

	return ret;
}
/**
 * @brief saca un jugador de una seleccion
 *
 * @param pArrayListJugador lista donde estan guardados los jugadores
 * @param pArrayListSeleccion lista donde estan guardados las selecciones
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int jug_sacarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ret = -1;
	int idJugador;
	int indexJugador;
	Jugador *pJugador;
	int idSeleccionJugador;
	int idSeleccion;
	Seleccion *pSeleccion;
	int convocados;

	listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
	if (utn_getEnteroConMaxMin(&idJugador, "Ingrese el id del jugador a sacar", "Error, tiene que ser mayor a 0", 1, 99999999, 3) == 0
				&& jug_buscarPorId(pArrayListJugador, idJugador, &indexJugador) == 0) {
		pJugador = ll_get(pArrayListJugador, indexJugador);
		jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
		for(int i = 0; i < ll_len(pArrayListSeleccion); i++){
			pSeleccion = ll_get(pArrayListSeleccion, i);
			selec_getId(pSeleccion, &idSeleccion);
			if (idSeleccionJugador == idSeleccion) {
				jug_setIdSeleccion(pJugador, 0);
				selec_getConvocados(pSeleccion, &convocados);
				convocados--;
				selec_setConvocados(pSeleccion, convocados);
				ret = 0;
			}
		}
	}else{
		printf("No existe jugador con ese id\n");
	}

	return ret;
}
