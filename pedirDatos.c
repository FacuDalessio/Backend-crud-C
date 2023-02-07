#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getEnteroConMaxMin(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int bufferInt;
	int ret = -1;

	if (pResultado != NULL && mensajeError != NULL && mensaje != NULL && minimo <= maximo && reintentos >= 0) {
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if (scanf("%d", &bufferInt) == 1) {
				if (bufferInt <= maximo && bufferInt >= minimo) {
					ret = 0;
					*pResultado = bufferInt;
					break;
				} else{
					if (reintentos > 0) {
						printf("%s\n", mensajeError);
						printf("Le quedan %d intentos \n", reintentos);
					}
					reintentos--;
				}
			}else{
				if (reintentos > 0) {
					printf("Tiene que ser un numero entero \n");
					printf("Le quedan %d intentos \n", reintentos);
				}
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return ret;
}

int utn_getFloatConMaxMin(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos){
	float bufferFloat;
	int ret = -1;

	if (pResultado != NULL && mensajeError != NULL && mensaje != NULL && minimo <= maximo && reintentos >= 0) {
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if (scanf("%f", &bufferFloat) == 1) {
				if (bufferFloat <= maximo && bufferFloat >= minimo) {
					ret = 0;
					*pResultado = bufferFloat;
					break;
				} else{
					if (reintentos > 0) {
						printf("%s\n", mensajeError);
						printf("Le quedan %d intentos \n", reintentos);
					}
					reintentos--;
				}
			}else{
				if (reintentos > 0) {
					printf("Tiene que ser un numero flotante\n");
					printf("Le quedan %d intentos \n", reintentos);
				}
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return ret;
}

int utn_getCharConMaxMin(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos){
	char bufferChar;
	int ret = -1;

		if (pResultado != NULL && mensajeError != NULL && mensaje != NULL && minimo <= maximo && reintentos >= 0) {
			do{
				printf("%s", mensaje);
				fflush(stdin);
				if (scanf("%c", &bufferChar) == 1) {
					if (bufferChar <= maximo && bufferChar >= minimo) {
						ret = 0;
						*pResultado = bufferChar;
						break;
					} else{
						if (reintentos > 0) {
							printf("%s\n", mensajeError);
							printf("Le quedan %d intentos \n", reintentos);
						}
						reintentos--;
					}
				}else{
					if (reintentos > 0) {
						printf("Tiene que ser un caracter\n");
						printf("Le quedan %d intentos \n", reintentos);
					}
					reintentos--;
				}
			}while(reintentos >= 0);

		}
		return ret;
}

int utn_getCadenaCaracteres(char *pResultado, char *mensaje, char *mensajeError, int tam, int reintentos){
	int ret = -1;
	char cadenaAux[tam];

	if (pResultado != NULL && mensajeError != NULL && mensaje != NULL && tam > 0) {
				do{
					printf("%s", mensaje);
					fflush(stdin);
					gets(cadenaAux);

					if (strlen(cadenaAux) <= tam) {
						ret = 0;
						strcpy(pResultado, cadenaAux);
						break;
					} else{
						if (reintentos > 0) {
							printf("%s\n", mensajeError);
							printf("Le quedan %d intentos \n", reintentos);
						}
						reintentos--;
					}
				}while(reintentos >= 0);

			}
			return ret;
}

int utn_getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo, short maximo, int reintentos){
	short buffershort;
	int ret = -1;

	if (pResultado != NULL && mensajeError != NULL && mensaje != NULL && minimo <= maximo && reintentos >= 0) {
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if (scanf("%hi", &buffershort) == 1) {
				if (buffershort <= maximo && buffershort >= minimo) {
					ret = 0;
					*pResultado = buffershort;
					break;
				} else{
					if (reintentos > 0) {
						printf("%s\n", mensajeError);
						printf("Le quedan %d intentos \n", reintentos);
					}
					reintentos--;
				}
			}else{
				if (reintentos > 0) {
					printf("Tiene que ser un short \n");
					printf("Le quedan %d intentos \n", reintentos);
				}
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return ret;
}
