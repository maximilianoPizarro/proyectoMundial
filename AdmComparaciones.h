#include "Lista.h"

#ifndef __ADMCOMPARACIONES_H__
#define __ADMCOMPARACIONES_H__

/*--------------------------------------------------------------------*/
/*
PRE: Los equipos a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre el ID de ambos equipos. 
*/

ResultadoComparacion compararIdEquipo (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/
/*
PRE: Los grupos a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre el ID de ambos grupos. 
*/

ResultadoComparacion compararIdGrupo(PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/
/*
PRE: Los equipos a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre los golesAfavor de ambos equipos. 
*/

ResultadoComparacion compararGoles (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/
/*
PRE: Los equipos a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre los puntos de ambos equipos. 
*/

ResultadoComparacion compararPuntos (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/
/*
PRE: Los jugadores a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre el ID de ambos jugadores. 
*/

ResultadoComparacion compararIdJugador (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/
/*
PRE: Los jugadores a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre los goles de ambos jugadores. 
*/

ResultadoComparacion compararGolesJugador (PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/
/*
PRE: Los jugadores a comparar tienen que estar creados.
POST: Devuelve el resultado de la comparacion entre el ID 
      del equipo perteneciente de ambos jugadores. 
*/

ResultadoComparacion compararIdEquipoPertenece(PtrDato dato1, PtrDato dato2);


/*--------------------------------------------------------------------*/

ResultadoComparacion compararIdPartidos(PtrDato dato1, PtrDato dato2);

/*--------------------------------------------------------------------*/

ResultadoComparacion compararParEjecucion(PtrDato dato1, PtrDato dato2);


#endif
