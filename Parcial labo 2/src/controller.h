/*
 * controller.h
 *
 *  Created on: 30 nov 2022
 *      Author: danil
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "parser.h"

int controller_cargarPeliculaDesdeTexto(char* path , LinkedList* pListaPeliculas);
int controller_listarPeliculas(LinkedList* pListaPeliculas);
int controller_guardarPeliculasModoTexto(char* path , LinkedList* pListaPeliculas);

#endif /* CONTROLLER_H_ */
