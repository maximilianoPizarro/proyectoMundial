#include "Lista.h"
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

#ifndef ADMINNISTRADORARCHIVOS_H_INCLUDED
#define ADMINNISTRADORARCHIVOS_H_INCLUDED

using namespace std;

/*--------------------------------------------------------------------*/
/*
PRE: El archivo "jugadores.txt" y la lista listaJugadores deben
     haber sido creados.
POST: Carga los datos del archivo "jugadores.txt" a la lista listaJugadores.
*/

void cargarJugadores(Lista &listaJugador);

/*--------------------------------------------------------------------*/
/*
PRE: El archivo "equipos.txt" y la lista listaEquipo deben
     haber sido creados.
POST: Carga los datos del archivo "equipos.txt" a la lista listaEquipo.
*/

void cargarEquipo(Lista &ListaEquipo);

/*--------------------------------------------------------------------*/
/*
PRE: El archivo "partidos.txt" y la lista listaPartidos deben
     haber sido creados.
POST: Carga los datos del archivo "partidos.txt" a la lista listaPartidos.
*/

void cargarPartidos(Lista &listaPartidos);

/*--------------------------------------------------------------------*/
/*
PRE: Los archivos "Equipos.txt", "partidos.txt" y "grupos.txt" y las listas
listaEquipo, listaPartidos y listaGrupos deben haber sido creados.
POST: Carga los datos de todos los archivos en las listas correspondientes.
*/

void cargaArchivos(Lista &listaEquipo, Lista &listaPartidos, Lista &listaGrupo,Lista &listaPartidosTerminados);

/*--------------------------------------------------------------------*/
/*
PRE: Los archivos "Equipos.txt", "partidos.txt" y "grupos.txt" y las listas
listaEquipo, listaPartidos y listaGrupos deben haber sido creados.
POST: Guarda los datos de todas las listas en los archivos correspondienteslos.
*/

void guardarArchivos(Lista &listaEquipo);

/*--------------------------------------------------------------------*/
/*
PRE: El archivo "partidos.txt" y la lista listaPartidos deben haber sido creados.
POST: Guarda los datos de la lista listaPartidos en el archivo "partidos.txt".
*/

void guardarPartidos(Lista &listaPartidos,Lista &listaPartidosTerminados);

/*--------------------------------------------------------------------*/
/*
PRE: El archivo "Grupos.txt" y la lista listaGrupos deben haber sido creados.
POST: Guarda los datos de la lista listaPartidos en el archivo "partidos.txt".
*/

void guardarGrupos(Lista &listaGrupos);

/*--------------------------------------------------------------------*/
/*
PRE: Se necesita de una cadena para operar.
POST: Convierte una cadena a un entero.
*/
int cadenaAentero(string dato);


// guardarPartidosTerminados(Lista &listaPartidosTerminados);


#endif // ADMINNISTRADORARCHIVOS_H_INCLUDED
