#include "Grupo.h"

PtrDato crearGrupo(Grupo &grupo)
{
    PtrDato puntero = new Grupo;
	grupo.idGrupo = "";
	grupo.nombreGrupo = "";
	grupo.equipo1 = NULL;
	grupo.equipo2 = NULL;
	grupo.equipo3 = NULL;
	grupo.equipo4 = NULL;
    return puntero;
}


/*--------------------------------------------------------------------*/


void destruirGrupo(Grupo &grupo)
{
     delete &grupo;
}


/*--------------------------------------------------------------------*/


void setIdGrupo(Grupo &grupo, string idGrupo)
{
   grupo.idGrupo = idGrupo;     
}


/*--------------------------------------------------------------------*/


string getIdGrupo(Grupo &grupo)
{
   return grupo.idGrupo;
}


/*--------------------------------------------------------------------*/


void setNombreGrupo(Grupo &grupo, string nombreGrupo)
{
     grupo.nombreGrupo = nombreGrupo;
}


/*--------------------------------------------------------------------*/


string getNombreGrupo(Grupo &grupo)
{
    return grupo.nombreGrupo;
}


/*--------------------------------------------------------------------*/


void setEquipo1(Grupo &grupo, Equipo* equipo)
{
    grupo.equipo1 = equipo;    
}


/*--------------------------------------------------------------------*/


Equipo* getEquipo1(Grupo &grupo)
{
    return grupo.equipo1;    
}


/*--------------------------------------------------------------------*/


void setEquipo2(Grupo &grupo, Equipo* equipo)
{
     grupo.equipo2 =  equipo;
}


/*--------------------------------------------------------------------*/


Equipo* getEquipo2(Grupo &grupo)
{
     return grupo.equipo2;   
}


/*--------------------------------------------------------------------*/


void setEquipo3(Grupo &grupo, Equipo* equipo)
{
    grupo.equipo3 =  equipo; 
}     


/*--------------------------------------------------------------------*/


Equipo* getEquipo3(Grupo &grupo)
{
     return grupo.equipo3;   
}


/*--------------------------------------------------------------------*/


void setEquipo4(Grupo &grupo, Equipo* equipo)
{
     grupo.equipo4 =  equipo;
}


/*--------------------------------------------------------------------*/


Equipo* getEquipo4(Grupo &grupo)
{
     return grupo.equipo4;   
}

