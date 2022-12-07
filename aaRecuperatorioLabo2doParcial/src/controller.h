/*
 * controller.h
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "parser.h"


int controller_cargarPosteosDesdeTexto(char* path , LinkedList* pListaPosteos);
int controller_listarPosteos(LinkedList* pListaPosteos);
int controller_guardarPosteosModoTexto(char* path , LinkedList* pListaPosteos);


#endif /* CONTROLLER_H_ */
