#include "Lista.h"

#include "AdmComparaciones.h"
#include <string>

#ifndef __EQUIPO_H__
#define __EQUIPO_H__



using namespace std;

//Definición de la estructura equipo.

struct Equipo
{
	int idEquipo;
	string nombreEquipo;
	int puntos;
	int golesFavor;
	int golesContra;
	Lista listaJugadores;
};

/*--------------------------------------------------------------------*/
/*
PRE: El TDA no debe haber sido creado.
POST: Crea el TDA con los siguientes valores por defecto:
	idEquipo = 0, nombreEquipo[30] = " ", puntos = 0, golesFavor = 0,
	golesContra = 0.
listaJugadores: Cada estructura equipo contiene	una lista de jugadores asociados.
*/

PtrDato crearEquipo(Equipo &equipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: El TDA es destruido.
*/

void destruirEquipo(Equipo &equipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idEquipo".
*/

void setIdEquipo(Equipo &equipo, int idEquipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "idEquipo".
*/

int getIdEquipo(Equipo &equipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "nombreEquipo".
*/

void setNombreEquipo(Equipo &equipo, string nombreEquipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "nombreEquipo".
*/

string getNombreEquipo(Equipo &equipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "puntos".
*/

void setPuntos(Equipo &equipo, int puntos);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "puntos".
*/

int getPuntos(Equipo &equipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "golesFavor".
*/

void setGolesFavor(Equipo &equipo, int golesFavor);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "golesFavor".
*/

int getGolesFavor(Equipo &equipo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "golesContra".
*/

void setGolesContra(Equipo &equipo, int golesContra);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "golesFavor".
*/

int getGolesContra(Equipo &equipo);

/*--------------------------------------------------------------------*/

void setListaJugadores(Equipo &equipo,Lista lista);

/*--------------------------------------------------------------------*/

PtrDato getListaJugadores(Equipo &equipo);

/*--------------------------------------------------------------------*/

// Función que compara los Id.
//ResultadoComparacion compararIdEquipo (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/

// Función que compara los goles.
//ResultadoComparacion compararGoles (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/

// Función que compara los puntos.
//ResultadoComparacion compararPuntos (PtrDato dato1, PtrDato dato2);



#endif
