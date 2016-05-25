#include "PartidosEjecucion.h"

/*-----------------------------------------------------------------------------*/


void crearParEjecucion(ParEjecucion &partido)
{
     partido.partido = NULL;
     Cola cola;
     crearCola(cola);
     partido.colaEventos = cola;
}


/*-----------------------------------------------------------------------------*/


void destruirParEjecucion(ParEjecucion &partido)
{
     delete &partido;
}     


/*-----------------------------------------------------------------------------*/


Partido* getPartidoEjecucion(ParEjecucion &partido)
 {
      return partido.partido;
 }     


/*-----------------------------------------------------------------------------*/


 void setPartidoEjecucion(ParEjecucion &partido, Partido* par)
 {
      partido.partido = par;
 }
 
 
 /*----------------------------------------------------------------------------*/
 
 
 PtrDato getCola(ParEjecucion &partido)
 {
      return &partido.colaEventos;   
 }    
 
 
 /*----------------------------------------------------------------------------*/    
 
 
 void setCola(ParEjecucion &partido, Cola cola)
 {
      partido.colaEventos = cola;
 }
 
 
