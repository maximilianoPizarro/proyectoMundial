#include "Jugador.h"
#include "string.h"

/*------------------------------------------------------------------*/

PtrDato crearJugador(Jugador &jugador)
{
    PtrDato puntero = new Jugador;
	jugador.idJugador = 0;
	jugador.nombreJugador="";
	jugador.goles = 0;
	jugador.idEquipoPertenece = 0;
return puntero;
}

/*------------------------------------------------------------------*/

void destruirJugador(Jugador &jugador)
{
   delete &jugador;
}

/*------------------------------------------------------------------*/

void setIdJugador(Jugador &jugador, int idJugador)
{
	jugador.idJugador = idJugador;
}

/*------------------------------------------------------------------*/

int getIdJugador(Jugador &jugador)
{
	return jugador.idJugador;
}

/*------------------------------------------------------------------*/

void setNombreJugador(Jugador &jugador, string nombreJugador)
{
	jugador.nombreJugador = nombreJugador;
}

/*------------------------------------------------------------------*/

string getNombreJugador(Jugador &jugador)
{
	return jugador.nombreJugador;
}

/*------------------------------------------------------------------*/

void setGoles(Jugador &jugador, int goles)
{
	jugador.goles = goles;
}

/*------------------------------------------------------------------*/

int getGoles(Jugador &jugador)
{
	return jugador.goles;
}

/*------------------------------------------------------------------*/

void setIdEquipoPertenece(Jugador &jugador, int idEquipoPertenece)
{
	jugador.idEquipoPertenece = idEquipoPertenece;
}

/*------------------------------------------------------------------*/

int getIdEquipoPertenece(Jugador &jugador)
{
	return jugador.idEquipoPertenece;
}

/*------------------------------------------------------------------*/
/*
ResultadoComparacion compararIdJugador (PtrDato dato1, int dato2)
{
	if( ((Jugador*)dato1)->idJugador > dato2)
		return MAYOR;
	else
	{
		if( ((Jugador*)dato1)->idJugador < dato2)
			return MENOR;
		else
			return IGUAL;
	}
}


ResultadoComparacion compararIdEquipoPertenece(PtrDato dato1, int dato2)
{
	if( ((Jugador*)dato1)->idEquipoPertenece > dato2)
		return MAYOR;
	else
	{
		if( ((Jugador*)dato1)->idEquipoPertenece < dato2)
			return MENOR;
		else
			return IGUAL;
	}
}

*/
