#include "Equipo.h"
#include "string.h"

/*------------------------------------------------------------------*/

PtrDato crearEquipo(Equipo &equipo)
{
    PtrDato puntero = new Equipo;
	equipo.idEquipo = 0;
	equipo.nombreEquipo = "";
	equipo.puntos = 0;
	equipo.golesFavor = 0;
	equipo.golesContra = 0;
	Lista lista;
	crearLista(lista,&compararIdJugador);
	equipo.listaJugadores = lista;
    return puntero;
}

/*--------------------------------------------------------------------*/

void destruirEquipo(Equipo &equipo)
{

}

/*--------------------------------------------------------------------*/

void setIdEquipo(Equipo &equipo, int idEquipo)
{
	equipo.idEquipo = idEquipo;
}

/*--------------------------------------------------------------------*/

int getIdEquipo(Equipo &equipo)
{
    return equipo.idEquipo;
}

/*--------------------------------------------------------------------*/

void setNombreEquipo(Equipo &equipo, string nombreEquipo)
{
	equipo.nombreEquipo = nombreEquipo;
}

/*--------------------------------------------------------------------*/

string getNombreEquipo(Equipo &equipo)
{
	return equipo.nombreEquipo;
}

/*--------------------------------------------------------------------*/

void setPuntos(Equipo &equipo, int puntos)
{
	equipo.puntos = puntos;
}

/*--------------------------------------------------------------------*/

int getPuntos(Equipo &equipo)
{
	return equipo.puntos;
}

/*--------------------------------------------------------------------*/

void setGolesFavor(Equipo &equipo, int golesFavor)
{
	equipo.golesFavor = golesFavor;
}

/*--------------------------------------------------------------------*/

int getGolesFavor(Equipo &equipo)
{
	return equipo.golesFavor;
}

/*--------------------------------------------------------------------*/

void setGolesContra(Equipo &equipo, int golesContra)
{
	equipo.golesContra = golesContra;
}

/*--------------------------------------------------------------------*/

int getGolesContra(Equipo &equipo)
{
	return equipo.golesContra;
}

/*--------------------------------------------------------------------*/

void setListaJugadores(Equipo &equipo,Lista lista)
{
    equipo.listaJugadores = lista;
}

/*--------------------------------------------------------------------*/

PtrDato getListaJugadores(Equipo &equipo)
{
    return &equipo.listaJugadores;
}

/*--------------------------------------------------------------------*/
/*
ResultadoComparacion compararIdEquipo (PtrDato dato1, PtrDato dato2)
{
	if( ((Equipo*)dato1)->idEquipo > ((Equipo*)dato2)->idEquipo)
		return MAYOR;
	else
	{
		if( ((Equipo*)dato1)->idEquipo < ((Equipo*)dato2)->idEquipo)
			return MENOR;
		else
			return IGUAL;
	}
}
*/
/*--------------------------------------------------------------------*/
/*
ResultadoComparacion compararGoles (PtrDato dato1, PtrDato dato2)
{
	if( ((Equipo*)dato1)->golesFavor > ((Equipo*)dato2)->golesFavor)
		return MAYOR;
	else
	{
		if( ((Equipo*)dato1)->golesFavor < ((Equipo*)dato2)->golesFavor)
			return MENOR;
		else
			return IGUAL;
	}
}
*/
/*--------------------------------------------------------------------*/
/*
ResultadoComparacion compararPuntos (PtrDato dato1, PtrDato dato2)
{
	if( ((Equipo*)dato1)->puntos > ((Equipo*)dato2)->puntos)
		return MAYOR;
	else
	{
		if( ((Equipo*)dato1)->puntos < ((Equipo*)dato2)->puntos)
			return MENOR;
		else
			return IGUAL;
	}
}
*/
