#include "Lista.h"
#include "Jugador.h"
#include "Equipo.h"
#include <iostream>
#include <string>

#ifndef __EVENTO_H__
#define __EVENTO_H__

using namespace std;

// Definición de la estructura jugador.

typedef struct Evento
{
	
    Jugador* jugador;
	Equipo* equipo;
	Equipo* equipoContrario;
};

/********************************************************************************/


PtrDato crearEvento(Evento &evento);


/********************************************************************************/


void destruirEvento(Evento &evento);



/********************************************************************************/


void setJugador(Evento &evento,Jugador* jugador);


/********************************************************************************/


Jugador* getJugador(Evento &evento);


/********************************************************************************/ 


void setEquipo(Evento &evento,Equipo* equipo);


/********************************************************************************/


Equipo* getEquipo(Evento &evento);


/********************************************************************************/


void setEquipoContrario(Evento &evento,Equipo* equipo);


/********************************************************************************/


Equipo* getEquipoContrario(Evento &evento);


/********************************************************************************/   

#endif
