#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "pedirDatos.h"
#include "salidaDatos.h"
#include "Controller.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* nombre del archivo a cargar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \return int retorna 0 si se cargo correctamente o -1 sino
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador, int *id)
{
	int ret = -1;
	if (pArrayListJugador != NULL && id != NULL) {
		FILE *pFile;
		pFile = fopen(path, "r");

		if (pFile != NULL && parser_JugadorFromText(pFile, pArrayListJugador,id) == 0 && ll_len(pArrayListJugador) > 0) {
			ret = 0;
		}
		fclose(pFile);
	}
    return ret;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* nombre del archivo a cargar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \return int retorna 0 si se cargo correctamente o -1 sino
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, int *id)
{
	int ret = -1;
	FILE *pFile;

	pFile = fopen(path, "rb");
	if (pFile != NULL && pArrayListJugador != NULL && parser_JugadorFromBinary(pFile, pArrayListJugador, id) == 0) {
		ret = 0;
	}
	fclose(pFile);
    return ret;
}

/**
 * @brief se da de alta un jugador
 *
 * @param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * @param idJugador id por referencia para hacerlo autoincremental
 * @return int retorna 0 si se cargo correctamente o -1 sino
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, int *idJugador)
{
	int ret = -1;
	if (pArrayListJugador != NULL && idJugador != NULL) {
		int validacion1;
		int validacion2;
		int validacion3;
		int validacion4;

		char nombre[100];
		int edad;
		char posicion[30];
		char nacionalidad[30];
		char id[100];
		itoa(*idJugador, id, 10);

		validacion1 = utn_getCadenaCaracteres(nombre, "Ingrese el nombre", "Error, no puede tener mas de 100 caracteres", 100, 3);
		validacion2 = utn_getEnteroConMaxMin(&edad, "Ingrese la edad", "Error, no puede ser menor a 15 ni mayor a 60",  15, 60, 3);
		validacion3 = utn_getCadenaCaracteres(posicion, "Ingrese la posicion", "Error, no puede tener mas de 30 caracteres", 30, 3);
		validacion4 = utn_getCadenaCaracteres(nacionalidad, "Ingrese la nacionalidad", "Error, no puede tener mas de 30 caracteres", 30, 3);
		char edadChar[3];
		itoa(edad, edadChar, 10);
		Jugador *jugadorAux = jug_newParametros(id, nombre, edadChar, posicion, nacionalidad, "0");

		if (jugadorAux != NULL && validacion1 == 0 && validacion2 == 0 && validacion3 == 0 && validacion4 == 0) {
			ll_add(pArrayListJugador, jugadorAux);
			ret = 0;
		}
		(*idJugador)++;
	}
    return ret;
}

/** \brief Modificar datos del jugador
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param pArrayListSeleccion LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se modifico correctamente o -1 sino
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	listarJugadores(pArrayListJugador, pArrayListSeleccion);
	int idModificar;
	int index;
	int opcion;
	Jugador *pJugador;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];

	if (utn_getEnteroConMaxMin(&idModificar, "Ingrese el id del jugador a modificar", "Error, tiene que ser mayor a 0", 1, 99999999, 3) == 0
			&& jug_buscarPorId(pArrayListJugador, idModificar, &index) == 0) {
		pJugador = ll_get(pArrayListJugador, index);
		imprimirMenuCuatroOpciones("1:Nombre", "2:Edad", "3:Posicion", "4:Nacionalidad");
		if (utn_getEnteroConMaxMin(&opcion, "Ingrese la opcion", "Error, tiene que ser una de las opciones",  1, 4, 3) == 0) {
			switch(opcion){
			case 1:
				if (utn_getCadenaCaracteres(nombre, "Ingrese el nombre", "Error, no puede tener mas de 100 caracteres", 100, 3) == 0 &&
						jug_setNombreCompleto(pJugador, nombre) == 0) {
					ret = 0;
				}
				break;
			case 2:
				if (utn_getEnteroConMaxMin(&edad, "Ingrese la edad", "Error, no puede ser menor a 15 ni mayor a 60",  15, 60, 3) == 0
						&& jug_setEdad(pJugador, edad) == 0) {
					ret = 0;
				}
				break;
			case 3:
				if (utn_getCadenaCaracteres(posicion, "Ingrese la posicion", "Error, no puede tener mas de 30 caracteres", 30, 3) == 0 &&
						jug_setPosicion(pJugador, posicion) == 0) {
					ret = 0;
				}
				break;
			case 4:
				if (utn_getCadenaCaracteres(nacionalidad, "Ingrese la nacionalidad", "Error, no puede tener mas de 30 caracteres", 30, 3) == 0 &&
						jug_setNacionalidad(pJugador, nacionalidad) == 0) {
					ret = 0;
				}
				break;
			}
		}
	}else{
		printf("No existe jugador con ese id\n");
	}

    return ret;
}

/**
 * @brief se da de baja un mjugador
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param pArrayListSeleccion LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se dio de baja correctamente o -1 sino
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int ret = -1;

	listarJugadores(pArrayListJugador, pArrayListSeleccion);
	int idModificar;
	int index;
	int idSeleccionJugador;
	int idSeleccion;
	Jugador *pJugador;
	Seleccion *pSeleccion;
	int convocados;

	if (utn_getEnteroConMaxMin(&idModificar, "Ingrese el id del jugador a dar de baja", "Error, tiene que ser mayor a 0", 1, 99999999, 3) == 0
			&& jug_buscarPorId(pArrayListJugador, idModificar, &index) == 0) {
		pJugador = ll_get(pArrayListJugador, index);
		jug_getSIdSeleccion(pJugador, &idSeleccionJugador);
		if (idSeleccionJugador != 0) {
			for(int i = 0; i < ll_len(pArrayListSeleccion); i++){
				pSeleccion = ll_get(pArrayListSeleccion, i);
				selec_getId(pSeleccion, &idSeleccion);
				if (idSeleccionJugador == idSeleccion) {
					selec_getConvocados(pSeleccion, &convocados);
					convocados--;
					selec_setConvocados(pSeleccion, convocados);
				}
			}
		}
		ll_remove(pArrayListJugador, index);
		jug_delete(pJugador);
		ret = 0;
	}else{
		printf("No existe jugador con ese id\n");
	}

    return ret;
}

/**
 * @brief dependiendo de la opcion que elija el usuario se lista una cosa u otra
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param pArrayListSeleccion LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se listo correctamente o -1 sino
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	int opcion;
	imprimirMenuTresOpciones("1:Listar jugadores", "2:Listar selecciones", "3:Listar jugadores convocados");
	if (utn_getEnteroConMaxMin(&opcion, "Ingrese lo que quiere listar", "Error, tiene que ser una de las opciones", 1, 3, 3) == 0) {
		switch (opcion){
		case 1:
			listarJugadores(pArrayListJugador, pArrayListSeleccion);
			ret = 0;
			break;
		case 2:
			controller_listarSelecciones(pArrayListSeleccion);
			ret = 0;
			break;
		case 3:
			listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
			ret = 0;
			break;
		}
	}
	return ret;
}
/**
 * @brief convoca o saca a un jugador de una seleccion
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param pArrayListSeleccion LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se convoco o saco correctamente o -1 sino
 */
int controller_convocarOsacarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int ret = -1;
	int opcion;

	imprimirMenuDosOpciones("1:Convocar jugador", "2:Sacar jugador");
	if (utn_getEnteroConMaxMin(&opcion, "Ingrese la opcion", "Error, tiene que ser una de las opciones", 1, 2, 3) == 0) {
		switch(opcion){
		case 1:
			if (jug_convocarJugador(pArrayListJugador, pArrayListSeleccion) == 0) {
				ret = 0;
			}
			break;
		case 2:
			if (jug_sacarJugador(pArrayListJugador, pArrayListSeleccion) == 0) {
				ret = 0;
			}
			break;
		}
	}
	return ret;
}

/**
 * @brief ordena las listas dependiendo de lo que elija el usuario
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \param pArrayListSeleccion LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se ordeno correctamente o -1 sino
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	int opcion;
	int (*pFunc)(void*, void*);
	imprimirMenuCuatroOpciones("1:Jugadores por nacionalidad", "2:Selecciones por confederacion", "3:Jugadores por edad", "4:Jugadores por nombre");
	if (utn_getEnteroConMaxMin(&opcion, "Ingrese una de las opciones", "Error, tiene que ser una de las opciones", 1, 4, 3) == 0) {
		switch(opcion){
		case 1:
			pFunc = jug_ordenarJugadoresPorNacionalidad;
			ll_sort(pArrayListJugador, pFunc, 1);
			ret = 0;
			break;
		case 2:
			controller_ordenarSelecciones(pArrayListSeleccion);
			ret = 0;
			break;
		case 3:
			pFunc = jug_ordenarJugadoresPorEdad;
			ll_sort(pArrayListJugador, pFunc, 1);
			ret = 0;
			break;
		case 4:
			pFunc = jug_ordenarJugadoresPorNombre;
			ll_sort(pArrayListJugador, pFunc, 1);
			ret = 0;
			break;
		}
	}

    return ret;
}

/**
 * @brief guarda la lista de jugadores en modo texto
 *
 * \param path char* nombre del archivo a guardar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * @param id ultimo id cargado
 * @return retorna 0 si se guardo correctamente y -1 sino
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador, int id)
{
	int ret = -1;
	FILE *pFile = fopen(path, "w");
	if (pFile != NULL && pArrayListJugador != NULL && parser_guardarJugadorEnTexto(pFile, pArrayListJugador, id) == 0) {
		ret = 0;
	}
	fclose(pFile);
    return ret;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char* nombre del archivo a guardar
 * \param pArrayListJugador LinkedList* lista donde se guardan los jugadores
 * \return int retorna 0 si se guardo correctamente o -1 sino
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int id)
{
	int ret = -1;
	FILE *pFile = fopen(path, "wb");
	if (pFile != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		if (parser_guardarJugadorEnBinario(pFile, pArrayListJugador, pArrayListSeleccion, id) == 0) {
			ret = 0;
		}
	}else{
		printf("Error al crear el archivo\n");
	}
	fclose(pFile);
    return ret;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* nombre del archivo a cargar
 * \param pArrayListJugador LinkedList* lista donde se guardan las selecciones
 * \return int retorna 0 si se cargo correctamente o -1 sino
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	FILE *pFile;
	pFile = fopen(path, "r");

	if (pFile != NULL && parser_SeleccionFromText(pFile, pArrayListSeleccion) == 0 && ll_len(pArrayListSeleccion) > 0) {
		ret = 0;
	}

	fclose(pFile);
	return ret;
}


/**
 * @brief lista todas las selecciones
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan las selecciones
 */
void controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	listarSelecciones(pArrayListSeleccion);
}

/**
 * @brief ordena la lista de selecciones
 *
 * \param pArrayListJugador LinkedList* lista donde se guardan las selecciones
 * @return retorna 0 si no hubo errores y -1 si hubo
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	int (*pFunc)(void*, void*);
	pFunc = selec_ordenarSeleccionesPorConfederacion;
	ll_sort(pArrayListSeleccion, pFunc, 1);
	ret = 0;

	return ret;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char* nombre del archivo donde se van a guardar las selecciones
 * \param pArrayListSeleccion LinkedList* lista donde estan guardadas las selecciones
 * \return int retorna 0 si no hubo errores y -1 si hubo
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int ret = -1;
	FILE *pFile = fopen(path, "w");
	if (pFile != NULL && pArrayListSeleccion != NULL && parser_guardarSeleccionEnTexto(pFile, pArrayListSeleccion) == 0) {
		ret = 0;
	}
	fclose(pFile);
	return ret;
}


