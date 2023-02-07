#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "pedirDatos.h"
#include "salidaDatos.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    int idJugador;
    int banderaArchivoTexto = 0;
    int banderaGuardarTexto = 1;

    if (listaJugadores != NULL && listaSelecciones != NULL) {
    	do{
    		imprimirMenuOnceOpciones("1:Carga de archivos de texto", "2:Alta jugador", "3:Modificacion jugador", "4:Baja jugador", "5:Listados", "6:Convocar o sacar jugadores",
    				"7:Ordenar lista", "8:Generar archivo binario", "9:Cargar archivo binario", "10:Guardar archivos de texto", "11:Salir");
    		if (utn_getEnteroConMaxMin(&option, "Ingrese una opcion", "Error, Tiene que ser unas de las opciones", 1, 11, 3) == 0) {
    			switch(option)
				{
					case 1:
						if (banderaArchivoTexto == 0) {
							if (controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores, &idJugador) == 0 &&
									controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 0) {
								printf("Se cargaron correctamente\n");
								banderaArchivoTexto = 1;
								banderaGuardarTexto = 0;
							}else{
								printf("No se pudieron cargar correctamente\n");
							}
						}else{
							printf("Ya se cargo un archivo\n");
						}
						break;
					case 2:
						if (ll_isEmpty(listaJugadores) == 0) {
							if (controller_agregarJugador(listaJugadores, &idJugador) == 0) {
								banderaGuardarTexto = 0;
								printf("Se cargo correctamente\n");
							}else{
								printf("no se pudo cargar correctamente\n");
							}
						}else{
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
					case 3:
						if (banderaArchivoTexto == 1) {
							if (controller_editarJugador(listaJugadores, listaSelecciones) == 0) {
								banderaGuardarTexto = 0;
								printf("Se modifico correctamente\n");
							}else{
								printf("No se modifico correctamente\n");
							}
						}else{
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
					case 4:
						if (banderaArchivoTexto == 1) {
							if (controller_removerJugador(listaJugadores, listaSelecciones) == 0) {
								banderaGuardarTexto = 0;
								printf("Se dio de baja correctamente\n");
							}else{
								printf("No se dio de baja correctamente\n");
							}
						} else {
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
					case 5:
						if (banderaArchivoTexto == 1) {
							if (controller_listarJugadores(listaJugadores, listaSelecciones) == -1) {
								printf("No se pudo listar correctamente\n");
							}
						} else {
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
					case 6:
						if (banderaArchivoTexto == 1) {
							if (controller_convocarOsacarJugador(listaJugadores, listaSelecciones) == 0) {
								printf("Se convoco o saco correctamente\n");
								banderaGuardarTexto = 0;
							} else {
								printf("No se pudo convocar o sacar correctamente\n");
							}
						} else {
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
					case 7:
						if (banderaArchivoTexto == 1) {
							if (controller_ordenarJugadores(listaJugadores, listaSelecciones) == 0) {
								printf("Se ordeno correctamente\n");
							}else{
								printf("No se guardo correctamente\n");
							}
						} else {
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
					case 8:
						if (controller_guardarJugadoresModoBinario("jugadoresConvocados.bin", listaJugadores, listaSelecciones, idJugador) == 0) {
							printf("Se guardo correctamente\n");
						}else{
							printf("No se guardo correctamente\n");
						}
						break;
					case 9:
						if (banderaArchivoTexto == 0) {
							if (controller_cargarJugadoresDesdeBinario("jugadoresConvocados.bin", listaJugadores, &idJugador) == 0
									&& controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 0) {
								banderaArchivoTexto = 1;
								printf("Se cargaron correctamente\n");
							}else{
								printf("Error en cargar el archivo\n");
							}
						}else{
							printf("Ya cargaste un archivo\n");
						}
						break;
					case 10:
						if (banderaArchivoTexto == 1) {
							if (controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores, idJugador) == 0 &&
									controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)) {
								banderaGuardarTexto = 1;
								printf("Se guardo correctamente\n");
							}else{
								printf("Error en guardar los datos\n");
							}
						}else{
							printf("Primero tiene que cargar un archivo\n");
						}
						break;
				}
			}else{
				printf("Error en ingresar la opcion\n");
			}
    		if (banderaGuardarTexto == 0 && option == 11) {
				utn_getEnteroConMaxMin(&option, "Estas saliendo sin guardar\ningrese 11 para salir igual o 10 para volver al menu", "Error, ingrese 11 o 10", 10, 11, 3);
			}else if(option == 11){
				utn_getEnteroConMaxMin(&option, "Seguro que quiere salir?\ningrese 11 para salir igual o 10 para volver al menu", "Error, ingrese 11 o 10", 10, 11, 3);
			}
		}while(option != 11);
	}

    printf("Salio correctamente");
    ll_clear(listaJugadores);
    ll_clear(listaSelecciones);
    ll_deleteLinkedList(listaJugadores);
	ll_deleteLinkedList(listaSelecciones);

    return 0;
}

