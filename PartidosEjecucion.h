#include "Cola.h"
#include "Partido.h"



#ifndef __PARTIDOSEJECUCION_H__
#define __PARTIDOSEJECUCION_H__



#ifndef NULL
#define NULL      0
#endif

typedef struct ParEjecucion
{
    Partido* partido;
    Cola colaEventos;    
};
/*-----------------------------------------------------------------------------*/


void crearParEjecucion(ParEjecucion &partido);


/*-----------------------------------------------------------------------------*/


void destruirParEjecucion(ParEjecucion &partido);


/*-----------------------------------------------------------------------------*/


Partido* getPartidoEjecucion(ParEjecucion &partido);


/*-----------------------------------------------------------------------------*/ 


void setPartidoEjecucion(ParEjecucion &partido,Partido* par); 


/*-----------------------------------------------------------------------------*/


PtrDato getCola(ParEjecucion &partido);


/*-----------------------------------------------------------------------------*/


void setCola(ParEjecucion &partido, Cola cola); 


/*-----------------------------------------------------------------------------*/                    
#endif
