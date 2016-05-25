#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__


void procesarEquipos(Lista &listaEquipo);

void cargarEquipo(Lista &listaequipos, int id, char* nombre, int puntos, int golesFavor, int golesContra);    

void procesarJugadores(Lista &listaJugador);

void cargarJugador(Lista &listaJugador,int id,char *nombre,char *fecha,int goles,int idequipo);

void procesarFecha(Lista &listaEquipo);

void actualizarGolesEquipos(Lista &listaEquipo,int idlocal,int idvisitante,int goleslocal,int golesvisitante);

void procesarGoles(Lista &listaJugador);

void actualizarGolesJugador(Lista &listaJugador,int idjugador,int goles);

void mostrarEquipo(Lista &listaEquipo, Lista &listaJugador);

void mostrarJugador(Lista &listaJugador);

void mostrarTabla(Lista &listaEquipo);

void ordenacion(PtrDato vector[], int n);

void intercambiar(PtrDato x,PtrDato y);

void guardarLista(Lista &listaEquipo);


#endif
