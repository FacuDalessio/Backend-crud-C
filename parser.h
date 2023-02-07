#include <stdlib.h>
#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador, int *id);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador, int *id);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_guardarJugadorEnTexto(FILE *pFile, LinkedList* pArrayListJugador, int id);
int parser_guardarJugadorEnBinario(FILE *pFile, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int id);
int parser_guardarSeleccionEnTexto(FILE *pFile, LinkedList* pArrayListSeleccion);

#endif /* PARSER_H_ */
