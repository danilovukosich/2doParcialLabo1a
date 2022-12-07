/*
 * inputs.c
 *
 *  Created on: 7 dic 2022
 *      Author: danil
 */

#ifndef INPUTS_C_
#define INPUTS_C_

#include "inputs.h"


int Utn_GetInt ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(GetInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int GetInt ( int * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (MyGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;

}

/////////////////////////////////////////////////////////////////
///
///
///

int Utn_GetShortInt ( short int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	short int aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(GetShortInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int GetShortInt ( short int * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (MyGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;

}



int esNumericaInt ( char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int MyGets ( char * cadena, int longitud)
{
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}


int Utn_GetFloat( float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(GetFloat(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

float GetFloat ( float * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (MyGets(buffer, sizeof (buffer))==0 && EsNumericaFloat(buffer) == 1)
		{
			*pResultado = atof (buffer);
			retorno = 1;
		}
	}
	return retorno;

}

float EsNumericaFloat ( char * cadena)
{
	int retorno;
	int i=0;
	int contador=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '.' || cadena[i] > '9' || cadena[i] == '/' || contador>1)
			{
				retorno = -1;
				break ;
			}
			if(cadena[i] == '.')
			{
				contador++;
			}
			i++;

		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

/////////////////////////////////////////////////////////////////////////
///
int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}



int EsNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' '))
			{
				retorno = 0;

				break;
			}
		}
	}
	return retorno;
}

int GetNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 && EsNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);

			retorno = 0;
		}
    }
    return retorno;
}




int Utn_GetNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(GetNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud && bufferString[0] != '\0' && bufferString[0] != ' ')
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;

			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int AscendenteDescendente(void)
{
	int opcion=0;

	Utn_GetInt(&opcion, "\nElija el orden:\n1)Ascendente.\n2)Descendente.\n>Ingrese una opcion:", "Ingrese una opcion VALIDA!", 1, 2, 15);

	switch(opcion)
	{
	case 1:
		opcion= 1;
		break;
	case 2:
		opcion= 0;
		break;
	}

	return opcion;
}

#endif /* INPUTS_C_ */
