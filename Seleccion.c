#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
/**
 * @brief crea un espacio en memoria dinamica para una seleccion
 *
 * @return devuelve el puntero al espacio en memoria donde esta la seleccion
 */
Seleccion* selec_new(){
	Seleccion *pSeleccion;
	pSeleccion = (Seleccion*)malloc(sizeof(Seleccion));
	return pSeleccion;
}
/**
 * @brief crea un espacio en memoria dinamica para una seleccion y le da valores
 *
 * @param idStr id que va a tener la seleccion
 * @param paisStr nombre del pais
 * @param confederacionStr confederacion donde esta el pais
 * @param convocadosStr cantidad de convocados que tiene la seleccion
 * @return
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion *pSeleccion = selec_new();
	if (pSeleccion != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL) {
		pSeleccion->id = atoi(idStr);
		strcpy(pSeleccion->pais, paisStr);
		strcpy(pSeleccion->confederacion, confederacionStr);
		pSeleccion->convocados = atoi(convocadosStr);
	}

	return pSeleccion;
}
/**
 * @brief borra una seleccion
 *
 * @param this puntero al espacio en memoria a borrar
 */
void selec_delete(Seleccion *this){
	if (this != NULL) {
		free(this);
	}
}
/**
 * @brief escribe el valor del id de una seleccion en la variable id pasada por parametro
 *
 * @param this puntero a la seleccion
 * @param id variable donde se va a guardar el id
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int selec_getId(Seleccion* this,int* id){
	int ret = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor del pais de una seleccion en la variable pais pasada por parametro
 *
 * @param this puntero a la seleccion
 * @param pais variable donde se va a guardar el pais
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int selec_getPais(Seleccion* this,char* pais){
	int ret = -1;
	if (this != NULL && pais != NULL) {
		strcpy(pais, this->pais);
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor de la confederacion de una seleccion en la variable confederacion pasada por parametro
 *
 * @param this puntero a la seleccion
 * @param confederacion variable donde se va a guardar la confederacion
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int selec_getConfederacion(Seleccion* this,char* confederacion){
	int ret = -1;
	if (this != NULL && confederacion != NULL) {
		strcpy(confederacion, this->confederacion);
		ret = 0;
	}
	return ret;
}
/**
 * @brief le pone valor al campo convocados de una seleccion
 *
 * @param this puntero a la seleccion
 * @param convocados cantidad de convocados que va a tener la seleccion
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int selec_setConvocados(Seleccion* this,int convocados){
	int ret = -1;
	if (this != NULL && convocados < 22) {
		this->convocados = convocados;
		ret = 0;
	}
	return ret;
}
/**
 * @brief escribe el valor de los convocados de una seleccion en la variable convocados pasada por parametro
 *
 * @param this puntero a la seleccion
 * @param convocados variable donde se va a guardar los convocados
 * @return retorna 0 si no hubo errores o -1 si hubo
 */
int selec_getConvocados(Seleccion* this,int* convocados){
	int ret = -1;
	if (this != NULL && convocados != NULL) {
		*convocados = this->convocados;
		ret = 0;
	}
	return ret;
}
/**
 * @brief busca una seleccion por id
 *
 * @param listaSeleccion lista donde estan guardados las selecciones
 * @param idAbuscar id a buscar
 * @param index variable donde se guarda el index de la seleccion encontrada
 * @return retorna 0 si encontro a la seleccion o -1 sino
 */
int selec_buscarPorId(LinkedList *listaSeleccion, int idAbuscar, int *index){
	int ret = -1;
	Seleccion *pseleccion;
	int idSeleccion;

	for(int i = 0; i < ll_len(listaSeleccion); i++){
		pseleccion = ll_get(listaSeleccion, i);
		selec_getId(pseleccion, &idSeleccion);
		if (idAbuscar == idSeleccion) {
			*index = i;
			ret = 0;
		}
	}

	return ret;
}
/**
 * @brief compara dos confederaciones de dos selecciones
 *
 * @param pSeleccion1 seleccion 1
 * @param pSeleccion2 seleccion 2
 * @return retorna 1 si la confederacion de la seleccion2 es menor a la seleccion1 o 0 sino
 */
int selec_ordenarSeleccionesPorConfederacion(void *pSeleccion1, void *pSeleccion2){

	int ret = 0;
	char confederacion1[30];
	char confederacion2[30];
	Seleccion *pSeleccion3 = (Seleccion*) pSeleccion1;
	Seleccion *pSeleccion4 = (Seleccion*) pSeleccion2;
	selec_getConfederacion(pSeleccion3, confederacion1);
	selec_getConfederacion(pSeleccion4, confederacion2);

	if (stricmp(confederacion2, confederacion1) < 0) {
		ret = 1;
	}

	return ret;
}
