#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

/**
 * @brief pide por consola un numero entero entre 2 valores y con una cierta cantidad de intentos, }
 * muestra un mensaje al pedir el numero entero, en caso de que este mal ingresado el numero, se muestra un mensaje de error
 *
 * @param pResultado variable donde se guarda el valor introducido por el usuario
 * @param mensaje mensaje que se muestra para pedir el numero al usuario
 * @param mensajeError mensaje que se muestra en caso del que el numero ingresado este mal
 * @param minimo el menor valor posible que puede ingresar el usuario
 * @param maximo el mayor valor posible que puede ingresar el usuario
 * @param reintentos la cantidad de intentos que tiene el usuario
 * @return devuelve 0 si esta todo bien o -1 si hay un error
 */
int utn_getEnteroConMaxMin(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
/**
 * @brief pide por consola un numero flotante entre 2 valores y con una cierta cantidad de intentos, }
 * muestra un mensaje al pedir el numero entero, en caso de que este mal ingresado el numero, se muestra un mensaje de error
 *
 * @param pResultado variable donde se guarda el valor introducido por el usuario
 * @param mensaje mensaje que se muestra para pedir el numero al usuario
 * @param mensajeError mensaje que se muestra en caso del que el numero ingresado este mal
 * @param minimo el menor valor posible que puede ingresar el usuario
 * @param maximo el mayor valor posible que puede ingresar el usuario
 * @param reintentos la cantidad de intentos que tiene el usuario
 * @return devuelve 0 si esta todo bien o -1 si hay un error
 */
int utn_getFloatConMaxMin(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
/**
 * @brief pide por consola un caracter entre 2 valores y con una cierta cantidad de intentos, }
 * muestra un mensaje al pedir el caracter, en caso de que este mal ingresado, se muestra un mensaje de error
 *
 * @param pResultado variable donde se guarda el valor introducido por el usuario
 * @param mensaje mensaje que se muestra para pedir el caracter al usuario
 * @param mensajeError mensaje que se muestra en caso del que el caracter ingresado este mal
 * @param minimo el menor valor posible que puede ingresar el usuario
 * @param maximo el mayor valor posible que puede ingresar el usuario
 * @param reintentos la cantidad de intentos que tiene el usuario
 * @return devuelve 0 si esta todo bien o -1 si hay un error
 */
int utn_getCharConMaxMin(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);
/**
 * @brief pide por consola una cadena de caracteres con un maximo posible y con una cierta cantidad de intentos, }
 * muestra un mensaje al pedir la cadena, en caso de que este mal ingresada, se muestra un mensaje de error
 *
 * @param pResultado variable donde se guarda el valor introducido por el usuario
 * @param mensaje mensaje que se muestra para pedir la cadena al usuario
 * @param mensajeError mensaje que se muestra en caso del que la cadena ingresada este mal
 * @param tam tamaño maximo de la cadena
 * @param reintentos la cantidad de intentos que tiene el usuario
 * @return devuelve 0 si esta todo bien o -1 si hay un error
 */
int utn_getCadenaCaracteres(char *pResultado, char *mensaje, char *mensajeError, int tam, int reintentos);
/**
 * @brief pide por consola un short entre 2 valores y con una cierta cantidad de intentos, }
 * muestra un mensaje al pedir el short, en caso de que este mal ingresado, se muestra un mensaje de error
 *
 * @param pResultado variable donde se guarda el valor introducido por el usuario
 * @param mensaje mensaje que se muestra para pedir el short al usuario
 * @param mensajeError mensaje que se muestra en caso del que el short ingresado este mal
 * @param minimo el menor valor posible que puede ingresar el usuario
 * @param maximo el mayor valor posible que puede ingresar el usuario
 * @param reintentos la cantidad de intentos que tiene el usuario
 * @return devuelve 0 si esta todo bien o -1 si hay un error
 */
int utn_getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo, short maximo, int reintentos);

#endif
