#include "Evento.h"


/********************************************************************************/


PtrDato crearEvento(Evento &evento)
{
     PtrDato puntero = new Evento;
     evento.jugador = NULL;
     evento.equipo = NULL;
     evento.equipoContrario = NULL;
     return puntero;     
}
/********************************************************************************/


void destruirEvento(Evento &evento)
{
     
}
/********************************************************************************/




void setJugador(Evento &evento,Jugador* dato)
{
   evento.jugador = dato;  
     
}


/********************************************************************************/


Jugador* getJugador(Evento &evento)
{
         return evento.jugador;
}


/********************************************************************************/ 


void setEquipo(Evento &evento,Equipo* dato)
{
   evento.equipo = dato;  
     
}


/********************************************************************************/


Equipo* getEquipo(Evento &evento)
{
         return evento.equipo;
}


/********************************************************************************/ 


void setEquipoContrario(Evento &evento,Equipo* dato)
{
   evento.equipoContrario = dato;  
     
}


/********************************************************************************/


Equipo* getEquipoContrario(Evento &evento)
{
         return evento.equipoContrario;
}


/********************************************************************************/ 
