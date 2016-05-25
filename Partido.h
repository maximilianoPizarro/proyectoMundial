#include "Lista.h"
#include "AdmComparaciones.h"
#include <stdio.h>
#include <string>
#include "string.h"



#ifndef __PARTIDO_H__
#define __PARTIDO_H__

using namespace std;

typedef struct Partido
{
	int idPartido;
	int idEquipoL;
	int idEquipoV;
	int golesL;
	int golesV;
};

/*------------------------------------------------------------------*/
/*
PRE: El TDA no debe haber sido creado.
POST: Crea el TDA con los siguientes valores por defecto:
	idPartido = 0, idEquipoL = 0, idEquipoV = 0, golesL = 0, golesV = 0.
*/

PtrDato crearPartido(Partido &partido);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado.
POST: Destruye el TDA.
*/

void destruirPartido(Partido &partido);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idPartido".
*/

void setIdPartido(Partido &partido, int idPartido);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idPartido".
*/

int getIdPartido(Partido &partido);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idEquipoL".
*/

void setIdEquipoL(Partido &partido, int idEquipoL);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idEquipoL".
*/

int getIdEquipoL(Partido &partido);

/*------------------------------------------------------------------*/

/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idEquipoV".
*/

void setIdEquipoV(Partido &partido, int idEquipoV);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idEquipoV".
*/

int getIdEquipoV(Partido &partido);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "golesL".
*/

void setGolesL(Partido &partido, int golesL);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "golesL".
*/

int getGolesL(Partido &partido);

/*------------------------------------------------------------------*/

/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "golesV".
*/

void setGolesV(Partido &partido, int golesV);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "golesV".
*/

int getGolesV(Partido &partido);




#endif



