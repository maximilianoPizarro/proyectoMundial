#include "Lista.h"
#include <iostream>

#include "string.h"
#include <string>

#ifndef __JUGADOR_H__
#define __JUGADOR_H__

using namespace std;

// Definición de la estructura jugador.

typedef struct Jugador
{
	int idJugador;
	string nombreJugador;
	int goles;
	int idEquipoPertenece;
};

/*------------------------------------------------------------------*/
/*
PRE: El TDA no debe haber sido creado.
POST: Crea el TDA con los siguientes valores por defecto:
	idJugador = 0, nombreJugador = " ", fechaNacimiento = "00/00/0000",
	goles = 0, idEquipoPertenece = 0.
*/

PtrDato crearJugador(Jugador &jugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado.
POST: Destruye el TDA.
*/

void destruirJugador(Jugador &jugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idJugador".
*/

void setIdJugador(Jugador &jugador, int idJugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idJugador".
*/

int getIdJugador(Jugador &jugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "nombreJugador".
*/

void setNombreJugador(Jugador &jugador, string nombreJugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "nombreJugador".
*/

string getNombreJugador(Jugador &jugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setGoles(Jugador &jugador, int goles);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

int getGoles(Jugador &jugador);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idEquipoPertenece".
*/

void setIdEquipoPertenece(Jugador &jugador, int idEquipoPertenece);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idJugador".
*/

int getIdEquipoPertenece(Jugador &jugador);
/*------------------------------------------------------------------*/

// Función que compara los Id.
//ResultadoComparacion compararIdJugador (PtrDato dato1, int dato2);

/*-------------------------------------------------------------------*/

//Función que compara el Id al que pertenece el jugador.
//ResultadoComparacion compararIdEquipoPertenece(PtrDato dato1, int dato2);


#endif
