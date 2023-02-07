#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"

#ifndef SALIDADATOS_H_
#define SALIDADATOS_H_
/**
 * @brief imprime las selecciones que pueden convocar jugadores
 *
 * @param pArrayListSelecciones lista donde estan guardados las selecciones
 */
void listarSeleccionesPorConvocar(LinkedList* pArrayListSelecciones);
/**
 * @brief imprime los jugadores no convocados
 *
 * @param pArrayListJugador lista donde estan guardados los jugadores
 * @param pArrayListSelecciones lista donde estan guardados las selecciones
 */
void listarJugadoresNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones);
/**
 * @brief imprime los jugadores convocados
 *
 * @param pArrayListJugador lista donde estan guardados los jugadores
 * @param pArrayListSelecciones lista donde estan guardados las selecciones
 */
void listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones);
/**
 * @brief imprime una lista de selecciones
 *
 * @param pArrayListSelecciones lista donde estan guardados las selecciones
 */
void listarSelecciones(LinkedList* pArrayListSelecciones);
/**
 * @brief imprime una seleccion
 *
 * @param pSelecicon seleccion a imprimir
 */
void listarSeleccion(Seleccion *pSelecicon);
/**
 * @brief imprime una lista de jugadores
 *
 * @param pArrayListJugador lista donde estan guardados los jugadores
 * @param pArrayListSelecciones lista donde estan guardados las selecciones
 */
void listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones);
/**
 * @brief imprime un jugador
 *
 * @param pJugador puntero al jugador a imprimir
 * @param seleccion selecion donde juega el jugador
 */
void listarJugador(Jugador *pJugador, char *seleccion);
/**
 * @brief imprime 11 opciones
 *
 * @param mensaje1 opcion 1
 * @param mensaje2 opcion 2
 * @param mensaje3 opcion 3
 * @param mensaje4 opcion 4
 * @param mensaje5 opcion 5
 * @param mensaje6 opcion 6
 * @param mensaje7 opcion 7
 * @param mensaje8 opcion 8
 * @param mensaje9 opcion 9
 * @param mensaje10 opcion 10
 * @param mensaje11 opcion 11
 */
void imprimirMenuOnceOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5, char *mensaje6,
		char *mensaje7, char *mensaje8, char *mensaje9, char *mensaje10, char *mensaje11);
/**
 * @brief imprime un menu de 5 opciones
 *
 * @param mensaje1 opcion 1
 * @param mensaje2 opcion 2
 * @param mensaje3 opcion 3
 * @param mensaje4 opcion 4
 * @param mensaje5 opcion 5
 */
void imprimirMenuCincoOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5);
/**
 * @brief imprime un menu de 4 opciones
 *
 * @param mensaje1 opcion 1
 * @param mensaje2 opcion 2
 * @param mensaje3 opcion 3
 * @param mensaje4 opcion 4
 */
void imprimirMenuCuatroOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4);
/**
 * @brief imprime un menu de 2 opciones
 *
 * @param mensaje1 opcion 1
 * @param mensaje2 opcion 2
 */
void imprimirMenuDosOpciones(char *mensaje1, char *mensaje2);
/**
 * @brief imprime un menu de 5 opciones
 *
 * @param mensaje1 opcion 1
 * @param mensaje2 opcion 2
 * @param mensaje3 opcion 3
 * @param mensaje4 opcion 4
 * @param mensaje5 opcion 5
 * @param mensaje6 opcion 6
 */
void imprimirMenuSeisOpciones(char *mensaje1, char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5, char *mensaje6);
/**
 * @brief imprime un menu de 3 opciones
 *
 * @param mensaje1 opcion 1
 * @param mensaje2 opcion 2
 * @param mensaje3 opcion 3
 */
void imprimirMenuTresOpciones(char *mensaje1, char *mensaje2, char *mensaje3);

#endif /* SALIDADATOS_H_ */
