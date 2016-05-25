#include "Partido.h"
#include "string.h"

/*------------------------------------------------------------------*/

PtrDato crearPartido(Partido &partido)
{
    PtrDato puntero = new Partido;
	partido.idPartido = 0;
	partido.idEquipoL = 0;
	partido.idEquipoV = 0;
	partido.golesL = 0;
	partido.golesV = 0;
    return puntero;
}

/*--------------------------------------------------------------------*/

void destruirPartido(Partido &partido)
{
    delete &partido;
}

/*--------------------------------------------------------------------*/

void setIdPartido(Partido &partido, int idPartido)
{
	partido.idPartido = idPartido;
}

/*--------------------------------------------------------------------*/

int getIdPartido(Partido &partido)
{
    return partido.idPartido;
}

/*--------------------------------------------------------------------*/

void setIdEquipoL(Partido &partido, int idEquipoL)
{
	partido.idEquipoL = idEquipoL;
}

/*--------------------------------------------------------------------*/

int getIdEquipoL(Partido &partido)
{
    return partido.idEquipoL;
}

/*--------------------------------------------------------------------*/
void setIdEquipoV(Partido &partido, int idEquipoV)
{
	partido.idEquipoV = idEquipoV;
}

/*--------------------------------------------------------------------*/

int getIdEquipoV(Partido &partido)
{
    return partido.idEquipoV;
}

/*--------------------------------------------------------------------*/


void setGolesL(Partido &partido, int golesL)
{
	partido.golesL = golesL;
}

/*--------------------------------------------------------------------*/

int getGolesL(Partido &partido)
{
	return partido.golesL;
}

/*--------------------------------------------------------------------*/

void setGolesV(Partido &partido, int golesV)
{
	partido.golesV = golesV;
}

/*--------------------------------------------------------------------*/

int getGolesV(Partido &partido)
{
	return partido.golesV;
}

/*--------------------------------------------------------------------*/

/*
ResultadoComparacion compararIdEquipo (PtrDato dato1, int idEquipo)
{
	if( ((Equipo*)dato1)->idEquipo > idEquipo)
		return MAYOR;
	else
	{
		if( ((Equipo*)dato1)->idEquipo < idEquipo)
			return MENOR;
		else
			return IGUAL;
	}
}


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
