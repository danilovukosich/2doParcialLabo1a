/*
 * parser.h
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "posteos.h"

int parser_posteosFromText(FILE* pFile , LinkedList* pListaPosteos);
int parser_PosteosSaveAsText(FILE* pFile , LinkedList* pListaPosteos);

#endif /* PARSER_H_ */
