#include "Lista.h"
#include "Equipo.h"
#include <string>


#ifndef __GRUPO_H__
#define __GRUPO_H__

//Definición de la estructura grupo.

typedef struct Grupo
{
	string idGrupo;
	string nombreGrupo;
	Equipo* equipo1;
	Equipo* equipo2;
	Equipo* equipo3;
	Equipo* equipo4;
};//[8]

/*
PRE: El TDA no debe haber sido creado.
POST: Crea el TDA con los siguientes valores por defecto:
	idGrupo = "", nombreGrupo = "", equipo1 = NULL, equipo2 = NULL
	equipo3 = NULL, equipo4 = NULL.
*/

PtrDato crearGrupo(Grupo &grupo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: El TDA es destruido.
*/

void destruirGrupo(Grupo &grupo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idGrupo".
*/

void setIdGrupo(Grupo &grupo, string idGrupo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "idGrupo".
*/

string getIdGrupo(Grupo &grupo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "nombreGrupo".
*/

void setNombreGrupo(Grupo &grupo, string nombreGrupo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "nombreGrupo".
*/

string getNombreGrupo(Grupo &grupo);

/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Asigna el valor del campo "equipo1".
*/

void setEquipo1(Grupo &grupo,Equipo* equipo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "equipo1".
*/

Equipo* getEquipo1(Grupo &grupo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Asigna el valor del campo "equipo2".
*/

void setEquipo2(Grupo &grupo,Equipo* equipo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "equipo2".
*/

Equipo* getEquipo2(Grupo &grupo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Asigna el valor del campo "equipo3".
*/

void setEquipo3(Grupo &grupo,Equipo* equipo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "equipo3".
*/

Equipo* getEquipo3(Grupo &grupo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Asigna el valor del campo "equipo4".
*/

void setEquipo4(Grupo &grupo,Equipo* equipo);


/*--------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creaado y no destruido.
POST: Devuelve el valor del campo "equipo4".
*/

Equipo* getEquipo4(Grupo &grupo);

#endif
