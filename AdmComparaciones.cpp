#include "AdmComparaciones.h"
#include "Equipo.h"
#include "Jugador.h"
#include "Partido.h"
#include "Grupo.h"
#include "PartidosEjecucion.h"

/************************************************************/
/***************FUNCIONES DE COMPARACION*********************/
/************************************************************/
//agrego un comparar

ResultadoComparacion compararListaPartidos(PtrDato ptrDato1, PtrDato ptrDato2) {
    int dato1 = ((Partido*) ptrDato1)->idPartido;
    int dato2 = ((Partido*) ptrDato2)->idPartido;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

/*----------------------------------------------------------------------*/

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
/*----------------------------------------------------------------------*/
ResultadoComparacion compararIdGrupo(PtrDato dato1, PtrDato dato2)
{
   if( ((Grupo*)dato1)->idGrupo > ((Grupo*)dato2)->idGrupo)
		return MAYOR;
	else
	{
		if( ((Grupo*)dato1)->idGrupo < ((Grupo*)dato2)->idGrupo)
			return MENOR;
		else
			return IGUAL;
	}
}


/*--------------------------------------------------------------------*/

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

/*--------------------------------------------------------------------*/

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
/*--------------------------------------------------------------------------*/
ResultadoComparacion compararIdJugador (PtrDato dato1, PtrDato dato2)
{
	if( ((Jugador*)dato1)->idJugador > ((Jugador*)dato2)->idJugador)
		return MAYOR;
	else
	{
		if( ((Jugador*)dato1)->idJugador < ((Jugador*)dato2)->idJugador)
			return MENOR;
		else
			return IGUAL;
	}
}
/*---------------------------------------------------------------------------*/
ResultadoComparacion compararGolesJugador (PtrDato dato1, PtrDato dato2)
{
	if( ((Jugador*)dato1)->goles > ((Jugador*)dato2)->goles)
		return MAYOR;
	else
	{
		if( ((Jugador*)dato1)->goles < ((Jugador*)dato2)->goles)
			return MENOR;
		else
			return IGUAL;
	}
}

/*--------------------------------------------------------------------------*/

ResultadoComparacion compararIdEquipoPertenece(PtrDato dato1, PtrDato dato2)
{
	if( ((Jugador*)dato1)->idEquipoPertenece > ((Jugador*)dato2)->idEquipoPertenece)
		return MAYOR;
	else
	{
		if( ((Jugador*)dato1)->idEquipoPertenece < ((Jugador*)dato2)->idEquipoPertenece)
			return MENOR;
		else
			return IGUAL;
	}
}

/*----------------------------------------------------------------------------*/

ResultadoComparacion compararParEjecucion(PtrDato dato1, PtrDato dato2)
{
   if( ((ParEjecucion*)dato1)->partido->idPartido > ((ParEjecucion*)dato2)->partido->idPartido)
		return MAYOR;
	else
	{
		if( ((ParEjecucion*)dato1)->partido->idPartido < ((ParEjecucion*)dato2)->partido->idPartido)
			return MENOR;
		else
			return IGUAL;
	}
}

/*----------------------------------------------------------------------------*/

ResultadoComparacion compararIdPartidos(PtrDato ptrDato1, PtrDato ptrDato2) {
    int dato1 = ((Partido*) ptrDato1)->idPartido;
    int dato2 = ((Partido*) ptrDato2)->idPartido;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}
