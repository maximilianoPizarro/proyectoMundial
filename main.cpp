#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <iomanip>

#include "Lista.h"
#include "AdmArchivos.h"
#include "AdmComparaciones.h"
#include "Equipo.h"
#include "Jugador.h"
#include "Partido.h"
#include "Grupo.h"
#include "PartidosEjecucion.h"
#include "Evento.h"

#ifndef NULL
#define NULL      0
#endif

using namespace std;

/******************************************************************************/
/*Definicion de Procedimientos para la interfaz del Menu*/
void mostrarEncabezadoMenu(void);
void MenuPrincipal(void);
void MenuABMtxt(void);
void MenuAdmPartidos(void);
void MenuProcesarPeportes(void);
void MenuSalir(void);
void mostrarEncabezadoEquipo(void);
void mostrarEncabezadoJugador(void);
void mostrarEncabezadoGrupos(void);
void mostrarEncabezadoPartidos(void);
void MenuABM(void);
void MenuFIN(void);
void banderaArgentina(void);
/*Definicion de Procedimientos para los Mensajes de Error*/
void mensajeDeErrorMenuPrincipal(void);
void mensajeDeErrorMenuABMtxt(void);
void mensajeDeErrorMenuAdmPartidos(void);
void mensajeDeErrorMenuProcesarReportes(void);
void mensajeDeErrorMenuABM(void);
/*funciones*/
char numeroAcaracter(int n);
void PIP(void);
void color(int X);
void renglonAzul(void);void renglonBlanco(void);
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/*---------------------------------------------------------------------------------------*/
PtrNodoLista localizarJugador(Lista &listaEquipo, int idJugador)
{

     PtrNodoLista ptrJugador = fin();
     PtrNodoLista devuelve = fin();
     Jugador auxJugador;
     crearJugador(auxJugador);
     setIdJugador(auxJugador,idJugador);
     PtrNodoLista cursor = primero(listaEquipo);
     //bool encontrado = false;

     while (cursor != fin())
     {
         ptrJugador = localizarDato(*((Lista*)getListaJugadores(*((Equipo*)cursor->ptrDato))),&auxJugador);
         if (ptrJugador != fin())
         {
            devuelve = ptrJugador;
            //encontrado = true;
         }
         cursor = siguiente(listaEquipo,cursor);
     }

  return devuelve;
}

/******************************************************************************/

                            /* RECORRER */

void recorrerListaEjecucion(Lista &listaEjecucion)
{
//RECORRO LISTA DE PARTIDOS EN EJECUCION
    cout<<"Partidos en ejecucion: "<<endl;
    mostrarEncabezadoPartidos();
    PtrNodoLista cursor = primero(listaEjecucion);
    Partido* par;
    while(cursor != fin())
    {
         par = getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato));
         cout<<"\t"<<getIdPartido(*(getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato))))<<"; \t"<<getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato))))<<"; \t"<<getIdEquipoV(*(getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato))))<<"; \t"<<getGolesL(*(getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato))))<<"; \t"<<getGolesV(*(getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato))))<<endl;

        cursor = siguiente(listaEjecucion,cursor);
    }
}

void recorrerListaGrupo(Lista &listaGrupo)
{

//RECORRO LISTA DE LOS GRUPOS

 mostrarEncabezadoGrupos();  /*Escribe el encabezado con los datos de los grupos*/

 PtrNodoLista cursor = primero(listaGrupo);

 while(cursor != fin())
 {

    string Id= getIdGrupo(*((Grupo*)cursor->ptrDato));
    cout<<Id<<"\t";
    string nombre= getNombreGrupo(*((Grupo*)cursor->ptrDato));
    cout<<nombre<<"\t\t";
    int IdEquipo1= getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))));
    cout<<IdEquipo1<<"\t";
    int IdEquipo2= getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))));
    cout<<IdEquipo2<<"\t";
    int IdEquipo3= getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))));
    cout<<IdEquipo3<<"\t";
    int IdEquipo4= getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))));
    cout<<IdEquipo4<<"\t\n";

    cursor = siguiente(listaGrupo, cursor);

 }

}
/******************************************************************************/

//RECORRO LISTA DE LOS PARTIDOS

void recorrerListaPartidos(Lista &listaPartidos)
{
 mostrarEncabezadoPartidos();/*Escribe el encabezado con los datos de los partidos*/

 PtrNodoLista cursor = primero(listaPartidos);
 if(cursor != fin())
 {
    while(cursor != fin())
    {

    int Id= getIdPartido(*((Partido*)cursor->ptrDato));
    cout<<"\t"<<Id<<"\t";
    int IdEquippoL= getIdEquipoL(*((Partido*)cursor->ptrDato));
    cout<<IdEquippoL<<"\t";
    int IdEquipoV= getIdEquipoV(*((Partido*)cursor->ptrDato));
    cout<<IdEquipoV<<"\t";
    int GolesL= getGolesL(*((Partido*)cursor->ptrDato));
    cout<<GolesL<<"\t";
    int GolesV= getGolesV(*((Partido*)cursor->ptrDato));
    cout<<GolesV<<"\t\n";

    cursor = siguiente(listaPartidos, cursor);
    }
 }
 else
 {
     cout<<"lista vacia"<<endl;
 }
}

/******************************************************************************/
void recorrerEquipo(Lista &listaEquipo, bool encabezado )
{

//RECORRO LISTA DE LOS EQUIPOS

    if (encabezado==true)
    {mostrarEncabezadoEquipo();}/*Escribe el encabezado con los datos del equipo*/

    encabezado=false;

    PtrNodoLista cursor = primero(listaEquipo);
    while (cursor !=fin())
    {
        cout<<"| "<<getIdEquipo(*((Equipo*)cursor->ptrDato))<<" | ";
        cout<<"  "<<getNombreEquipo(*((Equipo*)cursor->ptrDato))<<" | ";
        cout<<getPuntos(*((Equipo*)cursor->ptrDato))<<" | ";
        cout<<getGolesFavor(*((Equipo*)cursor->ptrDato))<<" | ";
        cout<<getGolesContra(*((Equipo*)cursor->ptrDato))<<"|";
        cout<<""<<endl;

        PtrDato puntero = getListaJugadores(*((Equipo*)cursor->ptrDato));
        Lista auxLista = *((Lista*)puntero);
        PtrNodoLista cursor2 = primero(auxLista);

        mostrarEncabezadoJugador(); /*Encabezado con los datos del jugador*/

        while(cursor2 !=fin())
        {
            cout<<"\t"<<getIdJugador(*((Jugador*)cursor2->ptrDato))<<" ";
            cout<<getNombreJugador(*((Jugador*)cursor2->ptrDato))<<" ";
            cout<<getGoles(*((Jugador*)cursor2->ptrDato))<<" | ";
            cout<<getIdEquipoPertenece(*((Jugador*)cursor2->ptrDato))<<" |";
            cout<<""<<endl;

            cursor2 =siguiente(auxLista,cursor2);
        }
        cout<<endl;
        cursor =siguiente(listaEquipo,cursor);
    }
}

/*---------------------------------------------------------------------------------------*/
/*--------------------------     VALIDACIONES     ---------------------------------------*/

bool validarGrupos(Lista &listaGrupo)
{
    bool existe = false;
    int error = 0;
    PtrNodoLista cursor = primero(listaGrupo);

    while(cursor != fin())
    {
        bool completo = true;
        if(getEquipo1(*((Grupo*)cursor->ptrDato))== NULL)
        {
            completo = false;
        }
        if(getEquipo2(*((Grupo*)cursor->ptrDato))== NULL)
        {
            completo = false;
        }
        if(getEquipo3(*((Grupo*)cursor->ptrDato))== NULL)
        {
            completo = false;
        }
        if(getEquipo4(*((Grupo*)cursor->ptrDato))== NULL)
        {
            completo = false;
        }

        if(completo == false)
        {
            error = error + 1;
            cout<<endl;
            cout<<"El "<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<" no tiene los 4 equipos asignados"<<endl;
            cout<<endl;
        }

     cursor = siguiente(listaGrupo,cursor);
    }
    if(error>0)
    {
        existe = true;
    }
    return existe;
}
/*---------------------------------------------------------------------------------------*/
bool validaGrupoEquipos(Lista &listaGrupo)
{
    bool existe = false;
    int error = 0;
    PtrNodoLista cursor = primero(listaGrupo);
    Equipo equi;
    crearEquipo(equi);
    while(cursor != fin())
    {
      if((getEquipo1(*((Grupo*)cursor->ptrDato))!=NULL)&&(getEquipo2(*((Grupo*)cursor->ptrDato))!=NULL)&&(getEquipo3(*((Grupo*)cursor->ptrDato))!=NULL)&&(getEquipo4(*((Grupo*)cursor->ptrDato))!=NULL))
       {
        if((getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato)))))
           or(getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato)))))
           or(getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))))
          {
            error = error + 1;
            cout<<endl;
            cout<<"hay inconsistencias en el grupo"<<endl;
          }
        if((getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato)))))
           or(getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))))
          {
            error = error + 1;
            cout<<endl;
            cout<<"hay inconsistencias en el grupo"<<endl;
          }
        if((getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato)))))==getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato)))))
          {
            error = error + 1;
            cout<<endl;
            cout<<"hay inconsistencias en el grupo"<<endl;
          }

        PtrNodoLista sig = siguiente(listaGrupo,cursor);
        while(sig != fin())
        {
         if((getEquipo1(*((Grupo*)sig->ptrDato))!= NULL)&&(getEquipo2(*((Grupo*)sig->ptrDato))!= NULL)&&(getEquipo3(*((Grupo*)sig->ptrDato))!= NULL)&&(getEquipo4(*((Grupo*)sig->ptrDato))!= NULL))
          {

          if((getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo1(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo2(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo3(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo4(*((Grupo*)sig->ptrDato))))))
            {
                error = error + 1;
                cout<<endl;
                cout<<"Hay equipos repetidos en el grupo "<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<" y "<<getNombreGrupo(*((Grupo*)sig->ptrDato))<<endl;
            }

          if((getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo1(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo2(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo3(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo4(*((Grupo*)sig->ptrDato))))))
            {
                error = error + 1;
                cout<<endl;
                cout<<"Hay equipos repetidos en el grupo "<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<" y "<<getNombreGrupo(*((Grupo*)sig->ptrDato))<<endl;
            }

          if((getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo1(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo2(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo3(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))==getIdEquipo(*(getEquipo4(*((Grupo*)sig->ptrDato))))))
            {
                error = error + 1;
                cout<<endl;
                cout<<"Hay equipos repetidos en el grupo "<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<" y "<<getNombreGrupo(*((Grupo*)sig->ptrDato))<<endl;
            }

          if((getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo1(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo2(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo3(*((Grupo*)sig->ptrDato)))))
             or(getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))== getIdEquipo(*(getEquipo4(*((Grupo*)sig->ptrDato))))))
            {
                error = error + 1;
                cout<<endl;
                cout<<"Hay equipos repetidos en el grupo "<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<" y "<<getNombreGrupo(*((Grupo*)sig->ptrDato))<<endl;
            }
         }

        sig = siguiente(listaGrupo,sig);
        }

        }
    cursor = siguiente(listaGrupo,cursor);
    }
    if(error>0)
    {
        existe = true;
    }
    return existe;

}
/*---------------------------------------------------------------------------------------*/
void AlertaGoles(Lista &listaEquipo)
{

    int goles=0;
    PtrNodoLista cursor = primero(listaEquipo);
    PtrNodoLista cursor2 = fin();
    PtrNodoLista ptrJugador = fin();
    Jugador jugadore;
    crearJugador(jugadore);

 while(cursor != fin())
    {
     cursor2 = primero(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))));
     while(cursor2 != fin())
     {
         goles = goles + getGoles(*((Jugador*)cursor2->ptrDato));

     cursor2 = siguiente(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),cursor2);
     }
     cursor = siguiente(listaEquipo,cursor);
   }

   if(goles % 10 ==0)//Cada 10 goles
         {   PIP();
             cout<<"\n\n\t\t******************************";
             cout<<"\n\t\t* Se conviertieron 10 Goles!!*";
             cout<<"\n\t\t******************************";
             cout<<"\n\n"<<endl;
             system("PAUSE");
         }
   if(goles % 100 ==0)//Cada 100 goles
         {   PIP();PIP();PIP();
             cout<<"\n\n\t\t**********************************";
             cout<<"\n\t\t* Ya se conviertieron "<<goles<<" Goles!!*";
             cout<<"\n\t\t**********************************";
             cout<<"\n\n"<<endl;
             system("PAUSE");
         }


}
/*---------------------------------------------------------------------------------------*/
/*recorre los jugadores de todos los equipos comparando los ids para verificar que no haya un jugador anotado en 2
equipos
*/
bool validarJugador(Lista &listaEquipo)
{
    bool existe = false;
    int error = 0;
    PtrNodoLista cursor = primero(listaEquipo);
    PtrNodoLista cursor2 = fin();
    PtrNodoLista ptrJugador = fin();
    Jugador juga;
    crearJugador(juga);

    while(cursor != fin())
    {

        cursor2 = primero(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))));
        while(cursor2 != fin())
        {
            //setIdJugador(juga,getIdJugador(*((Jugador*)cursor2->ptrDato)));
            //ptrJugador = localizarJugador(listaEquipo,getIdJugador(*((Jugador*)cursor2->ptrDato)));
            PtrNodoLista aux = cursor;
            PtrNodoLista sig = siguiente(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),cursor2);
            bool encontrado = false;
            //cout<<"cursor2 :"<<getNombreJugador(*((Jugador*)cursor2->ptrDato))<<endl;

           while(aux != fin())
           {
            while((sig != fin()) &&(! encontrado))
            {  //cout<<"siguente :"<<getNombreJugador(*((Jugador*)sig->ptrDato))<<endl;
                if(getIdJugador(*((Jugador*)cursor2->ptrDato))== getIdJugador(*((Jugador*)sig->ptrDato)))
                {
                    error = error + 1;
                    PIP();
                    cout<<"\nEl jugador "<<getNombreJugador(*((Jugador*)cursor2->ptrDato))<<" pertenece al equipo con ID "<<getIdEquipoPertenece(*((Jugador*)cursor2->ptrDato))<<" y "<<getIdEquipoPertenece(*((Jugador*)sig->ptrDato))<<endl;
                    cout<<"\n";
                  encontrado = true;
                }
              sig = siguiente(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),sig);
            }
            aux = siguiente(listaEquipo,aux);
            if(aux != fin())
            {
                sig = primero(*((Lista*)(getListaJugadores(*((Equipo*)aux->ptrDato)))));
            }
           }

         cursor2 = siguiente(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),cursor2);
        }
     cursor = siguiente(listaEquipo,cursor);
    }
    if(error > 0)
    {
        existe = true;
    }
  return existe;
}

/*---------------------------------------------------------------------------------------*/
/*------------------------           ABM            ------------------------------------*/

//ABM DE JUGADORES
void agregarJugador(Lista &listaEquipos)
{

     Jugador* ptrJugador = new Jugador;
     crearJugador(*ptrJugador);
     int id = 1;
     char dato[50];

         PtrNodoLista cursor = primero(listaEquipos);
         while (cursor !=fin())
         {
            PtrDato puntero = getListaJugadores(*((Equipo*)cursor->ptrDato));
            Lista auxLista = *((Lista*)puntero);
            PtrNodoLista cursor2 = primero(auxLista);
            while(cursor2 !=fin())
            {
              if(id <= getIdJugador(*((Jugador*)(cursor2->ptrDato))))
              {
                    id = getIdJugador(*((Jugador*)(cursor2->ptrDato)));
              }
              cursor2 =siguiente(auxLista,cursor2);
            }

            cursor =siguiente(listaEquipos,cursor);
         }


        id = id + 1;

     cout << "Id: " << id << endl;
     setIdJugador(*ptrJugador,id);
     //cin.ignore();

     cout << "Ingrese Nombre del jugador: "<<endl;
     //cin.ignore();
     cin.getline(dato,50);
     setNombreJugador(*ptrJugador,dato);


     cout << "Ingrese sus goles: "<<endl ;
     cin.getline(dato,50);
     setGoles(*ptrJugador, cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese el id del equipo al cual pertenece : "<<endl;
     cin.getline(dato,50);
     setIdEquipoPertenece(*ptrJugador, cadenaAentero(dato));

     //cin.ignore();

     Equipo aux;       //esto lo puso EZE
     crearEquipo(aux);
     setIdEquipo(aux,cadenaAentero(dato));
     PtrNodoLista ptrCursor = localizarDato(listaEquipos,&aux);
     if(ptrCursor != fin())
     {
         PtrDato puntero = getListaJugadores(*((Equipo*)ptrCursor->ptrDato));
         adicionarFinal(*((Lista*)puntero),ptrJugador);
     }
     else
     {
         PIP();
        cout<<" el equipo con id "<<dato<<" no existe"<<endl;
        system("PAUSE");
     }

};

void eliminarJugador(Lista &listaEquipo){

     bool a=false;
     cout << "Ingrese el Id del jugador a Eliminar: " ;
     int idJugador;
     cin >> idJugador;

     PtrNodoLista ptrJugador = fin();
     Jugador auxJugador;
     crearJugador(auxJugador);
     setIdJugador(auxJugador,idJugador);
     PtrNodoLista cursor = primero(listaEquipo);

     while (cursor != fin())
     {

         ptrJugador = localizarDato(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),&auxJugador);

         if (ptrJugador != fin())
         {

          eliminarNodo(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),ptrJugador);
          cout << "Se dio de baja el jugador Correctamente\n";
          cursor = siguiente(listaEquipo,cursor);
          a=true;

         }
         else{


          cursor = siguiente(listaEquipo,cursor);
         }
     }


          if (ptrJugador == fin()){
          if(a==false)
           {
          cout << "No existe el jugador seleccionado." << endl;
          system("pause");
          }
          }

};


void modificarJugador(Lista &listaEquipo){

      bool a=false;
      PtrNodoLista nodo = fin();
      Equipo equi;
      crearEquipo(equi);

     cout << "Ingrese el Id del jugador a modificar: " ;
     int idJugador;
     cin >> idJugador;
     PtrNodoLista ptrJugador = fin();
     Jugador auxJugador;
     crearJugador(auxJugador);
     setIdJugador(auxJugador,idJugador);

     PtrNodoLista cursor = primero(listaEquipo);

     while (cursor != fin())
     {

         ptrJugador = localizarDato(*((Lista*)(getListaJugadores(*((Equipo*)cursor->ptrDato)))),&auxJugador);

         if (ptrJugador != fin())
         {
          int seleccion;

          cout << "Que dato desea modificar?" << endl << endl;
          cout << "1. Nombre del jugador" << endl;
          cout << "2. Cantidad de goles" << endl;
          cout << "3. Id del equipo al que pertenece " << endl;


          cout << "Su eleccion: ";
          cin >> seleccion;

          char dato[50];
          switch (seleccion){

               case 1: system("cls");
                       cin.ignore();
                       cout << "Ingrese Nombre del jugador: " ;
                       cin.getline(dato, 50);
                       setNombreJugador(*((Jugador*)(ptrJugador->ptrDato)),dato);
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese cantidad de goles: " ;
                       cin.getline(dato, 50);
                       setGoles(*((Jugador*)(ptrJugador->ptrDato)), cadenaAentero(dato));
                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo al que pertenece: " ;
                       cin.getline(dato, 50);

                       setIdEquipo(equi,cadenaAentero(dato));
                       nodo = localizarDato(listaEquipo,&equi);
                       if(nodo != fin())
                       {
                           PtrNodoLista aux = ptrJugador;
                           setIdEquipo(equi,getIdEquipoPertenece(*((Jugador*)ptrJugador->ptrDato)));
                           PtrNodoLista nodo2 = localizarDato(listaEquipo,&equi);
                           PtrDato punt = getListaJugadores(*((Equipo*)nodo2->ptrDato));
                           setIdEquipoPertenece(*((Jugador*)(ptrJugador->ptrDato)), cadenaAentero(dato));
                           PtrDato puntero = getListaJugadores(*((Equipo*)nodo->ptrDato));
                           adicionarFinal(*((Lista*)puntero),ptrJugador->ptrDato);
                           eliminarNodo(*((Lista*)punt),aux);

                       }
                       else
                       {
                           cout<<"No existe ningun equipo con esa ID"<<endl;
                           system("pause");
                       }break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
           }
          cursor = siguiente(listaEquipo,cursor);
           a=true;
         }else{


          cursor = siguiente(listaEquipo,cursor);
         }


     //PtrNodoLista ptrJugador = localizarDato(Jugadores, &auxJugador);

      }
       if (ptrJugador == fin()){
          if(a==false){
          cout << "No existe el jugador seleccionado." << endl;
          system("PAUSE");
         }
     }

};



//ABM DE EQUIPOS
void agregarEquipo(Lista &Equipos){

     Equipo* ptrEquipo = new Equipo;
     crearEquipo(*ptrEquipo);
     int id = 1;
     char dato[50];

     if (!listaVacia(Equipos))
     {
        id = (getIdEquipo(*((Equipo*)(ultimo(Equipos)->ptrDato))))+1;
     }
     cout << "Id: " << id << endl;
     setIdEquipo(*ptrEquipo,id);
     //cin.ignore();

     cout << "Ingrese Nombre Equipo: " ;
     //cin.ignore();
     cin.getline(dato, 50);
     setNombreEquipo(*ptrEquipo,dato);

     cout << "Ingrese Puntos: " ;
     cin.getline(dato, 50);
     setPuntos(*ptrEquipo, cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese goles a favor : " ;
     cin.getline(dato, 50);
     setGolesFavor(*ptrEquipo, cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese goles recibidos : " ;
     cin.getline(dato, 50);
     setGolesContra(*ptrEquipo, cadenaAentero(dato));
     //cin.ignore();

     adicionarFinal(Equipos, ptrEquipo);

};
/*----------------------------------------------------------------------------*/
void eliminarEquipo(Lista &Equipos){

     cout << "Ingrese el Id del Equipo a Eliminar: " ;
     int idEquipo;
     cin >> idEquipo;
     Equipo aux;       //esto lo puso EZE
     crearEquipo(aux);
     setIdEquipo(aux,idEquipo);

     PtrNodoLista cursor = localizarDato(Equipos, &aux);

     if (cursor == fin())
     {
          cout << "No existe el equipo seleccionado." << endl;
         // system("PAUSE");
     }
     else
     {
          eliminarNodo(Equipos,cursor);
          cout << "Se dio de baja el equipo Correctamente\n";
          //system ("PAUSE");
     }
};
/*----------------------------------------------------------------------------*/

void modificarEquipo(Lista &Equipos){

     cout << "Ingrese el Id del equipo a modificar: " ;
     int idEquipo;
     cin >> idEquipo;
     Equipo aux;       //esto lo puso EZE
     crearEquipo(aux);
     setIdEquipo(aux,idEquipo);

     PtrNodoLista cursor = localizarDato(Equipos, &aux);


     if (cursor == fin())
     {
          cout << "No existe el Equipo seleccionado." << endl;
          system ("PAUSE");
     }
     else{
          int seleccion;

          cout << "Que dato desea modificar?" << endl << endl;
          cout << "1. Nombre del equipo" << endl;
          cout << "2. Cantidad de puntos" << endl;
          cout << "3. Goles a favor" << endl;
          cout << "4. Goles recibidos" << endl;

          cout << "Su eleccion: ";
          cin >> seleccion;

          char dato[50];
          switch (seleccion){

               case 1: system("cls");
                       cin.ignore();
                       cout << "Ingrese Nombre del equipo: " ;
                       cin.getline(dato, 50);
                       setNombreEquipo(*((Equipo*)(cursor->ptrDato)),dato);
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese cantidad de puntos: " ;
                       cin.getline(dato, 50);
                       setPuntos(*((Equipo*)(cursor->ptrDato)), cadenaAentero(dato));
                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese goles a favor: " ;
                       cin.getline(dato, 50);
                       setGolesFavor(*((Equipo*)(cursor->ptrDato)), cadenaAentero(dato));
                       break;
               case 4: system("cls");
                       cout << "Ingrese goles recibidos: " ;
                       cin >> dato;
                       setGolesContra(*((Equipo*)(cursor->ptrDato)), cadenaAentero(dato));
                       break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
          }
     }
};
/*------------------------------------------------------------------------------*/

//ABM DE PARTIDOS
void agregarPartido(Lista &Partidos,Lista &listaPartidosTerminados,Lista &listaEquipo)
{
     PtrNodoLista cursor = fin();
     Equipo equi;
     crearEquipo(equi);

     Partido* ptrPartido = new Partido;
     crearPartido(*ptrPartido);
     int id = 1;
     char dato[50];
     //char dato2;
     if (!listaVacia(Partidos))
     {
        id = (getIdPartido(*((Partido*)(ultimo(Partidos)->ptrDato))))+1;
     }
     cout << "Id: " << id << endl;
     setIdPartido(*ptrPartido,id);
     //cin.ignore();

     cout << "Ingrese id del equipo local: " ;
     //cin.ignore();
     cin.getline(dato, 50);
     setIdEquipo(equi,cadenaAentero(dato));
     cursor = localizarDato(listaEquipo,&equi);
     if(cursor != fin())
     {
         setIdEquipoL(*ptrPartido,cadenaAentero(dato));

         cout << "Ingrese id del equipo visitante: " ;
         cin.getline(dato, 50);
         setIdEquipo(equi,cadenaAentero(dato));
         cursor = localizarDato(listaEquipo,&equi);
         if(cursor != fin())
         {
            setIdEquipoV(*ptrPartido,cadenaAentero(dato));

            cout << "Ingrese el goles del equipo local : " ;
            cin.getline(dato, 50);
            setGolesL(*ptrPartido, cadenaAentero(dato));


            cout << "Ingrese el goles del equipo visitante : " ;
            cin.getline(dato, 50);
            setGolesV(*ptrPartido, cadenaAentero(dato));
     //cin.ignore();

           if((getGolesL(*ptrPartido) > -1) or (getGolesV(*ptrPartido)> -1))
           {
               adicionarFinal(listaPartidosTerminados,ptrPartido);
                //cout<<"entro"<<endl;
           }
           else
           {
              adicionarFinal(Partidos,ptrPartido);
           }

         }
         else
         {
            cout<<endl;
            cout<<"El ID ingresado no corresponde a ningun equipo"<<endl;
            system("Pause");
         }

     }
     else
     {
         cout<<endl;
         cout<<"El ID ingresado no corresponde a ningun equipo"<<endl;
         system("Pause");
     }

     //cin.ignore();


     //cin.ignore();
};
/*----------------------------------------------------------------------------*/

void eliminarPartido(Lista &Partidos){

     cout << "Ingrese el Id del partido a Eliminar: " ;
     int idPartido;
     cin >> idPartido;
     Partido aux;
     crearPartido(aux);
     setIdPartido(aux,idPartido);
     PtrNodoLista cursor = localizarDato(Partidos, &aux);

     if (cursor == fin())
     {
          cout << "No existe el partido seleccionado." << endl;
         // system("PAUSE");
     }
     else{
          //se deberia llamar al destruir
          eliminarNodo(Partidos,cursor);
          cout << "Se dio de baja el partido Correctamente\n";
          //system ("PAUSE");
     }
};
/*----------------------------------------------------------------------------*/

void modificarPartido(Lista &Partidos){

     cout << "Ingrese el Id del partido a modificar: " ;
     int idPartido;
     cin >> idPartido;
     Partido aux;
     crearPartido(aux);
     setIdPartido(aux,idPartido);
     PtrNodoLista cursor = localizarDato(Partidos, &aux);


     if (cursor == fin())
     {
          cout << "No existe el partido seleccionado." << endl;
          system ("PAUSE");
     }
     else{
          int seleccion;

          cout << "Que dato desea modificar?" << endl << endl;
          cout << "1. id del equippo local" << endl;
          cout << "2. id del equipo visitante" << endl;
          cout << "3. Goles del equipo local" << endl;
          cout << "4. Goles del equipo visitante" << endl;

          cout << "Su eleccion: ";
          cin >> seleccion;

          char dato[50];
          switch (seleccion){

               case 1: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo local: " ;
                       cin.getline(dato, 50);
                       setIdEquipoL(*((Partido*)(cursor->ptrDato)),cadenaAentero(dato));
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo visitante: " ;
                       cin.getline(dato, 50);
                       setIdEquipoV(*((Partido*)(cursor->ptrDato)), cadenaAentero(dato));
                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese goles equipo local: " ;
                       cin.getline(dato, 50);
                       setGolesL(*((Partido*)(cursor->ptrDato)), cadenaAentero(dato));
                       break;
               case 4: system("cls");
                       cout << "Ingrese goles equipo visitante: " ;
                       cin >> dato;
                       setGolesV(*((Partido*)(cursor->ptrDato)), cadenaAentero(dato));
                       break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
          }
     }
};

//ABM DE GRUPOS

void agregarGrupo(Lista &listaGrupos,Lista &listaEquipo)
{

     Equipo equipoAux;
     crearEquipo(equipoAux);
     PtrNodoLista puntero = fin();
     PtrNodoLista cursor2 = fin();

     Grupo* ptrGrupo = new Grupo;
     crearGrupo(*ptrGrupo);
     PtrNodoLista cursor = primero(listaGrupos);
     char dato[50];
     char dato2[50]="Grupo ";

     cout << "Ingrese letra del grupo: " ;
     //cin.ignore();
     cin.getline(dato, 50);
     setIdGrupo(*ptrGrupo,dato);
     cursor2 = localizarDato(listaGrupos,ptrGrupo);

     if(cursor2 == fin())
     {
        strcat(dato2,dato) ;
        cout << "Nombre del grupo: "<<dato2<<endl ;
        setNombreGrupo(*ptrGrupo,dato2);

        cout << "Ingrese id del equipo 1: " ;
        cin.getline(dato, 50);
        setIdEquipo(equipoAux,cadenaAentero(dato));
        puntero =localizarDato(listaEquipo,&equipoAux);
        if(puntero != fin())
        {
          setEquipo1(*ptrGrupo,((Equipo*)puntero->ptrDato));

          cout << "Ingrese id del equipo 2: " ;
          cin.getline(dato, 50);
          setIdEquipo(equipoAux,cadenaAentero(dato));
          puntero =localizarDato(listaEquipo,&equipoAux);
          if(puntero != fin())
          {
            setEquipo2(*ptrGrupo,((Equipo*)puntero->ptrDato));

            cout << "Ingrese id del equipo 3: " ;
            cin.getline(dato, 50);
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero =localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo3(*ptrGrupo,((Equipo*)puntero->ptrDato));

              cout << "Ingrese id del equipo 4: " ;
              cin.getline(dato, 50);
              setIdEquipo(equipoAux,cadenaAentero(dato));
              puntero =localizarDato(listaEquipo,&equipoAux);
              if(puntero != fin())
              {
                setEquipo4(*ptrGrupo,((Equipo*)puntero->ptrDato));

                adicionarFinal(listaGrupos, ptrGrupo);
              }
              else
              {
                cout<<"el equipo es inexistente"<<endl;
                system("Pause");
              }
            }
            else
            {
              cout<<"el equipo es inexistente"<<endl;
              system("Pause");
            }
          }
          else
          {
           cout<<"el equipo es inexistente"<<endl;
           system("Pause");
          }

        }
        else
        {
          cout<<"el equipo es inexistente"<<endl;
          system("Pause");
        }

     }
     else
     {
         cout<<"Ya existe un grupo con ese ID"<<endl;
         system("Pause");
     }
};

void eliminarGrupo(Lista &listaGrupos)
{
     cout << "Ingrese el Id del Grupo a Eliminar: " ;
     string idGrupo;
     cin>>idGrupo;

     //*idGrupo=toupper(*idGrupo);

     //string srt(idGrupo);

     Grupo aux;
     crearGrupo(aux);
     setIdGrupo(aux,idGrupo);

     PtrNodoLista cursor = localizarDato(listaGrupos, &aux);

     if (cursor == fin())
     {
          cout << "No existe el Grupo seleccionado." << endl;
          system("PAUSE");
     }
     else
     {
          eliminarNodo(listaGrupos,cursor);
          cout << "Se dio de baja el Grupo Correctamente\n";
          //system ("PAUSE");
     }

}

/*----------------------------------------------------------------------------*/

void modificarGrupo(Lista &listaGrupos,Lista &listaEquipo){

     Equipo equipoAux;
     crearEquipo(equipoAux);
     PtrNodoLista puntero;

     cout << "Ingrese la letra del grupo a modificar: " ;

     Grupo* ptrGrupo = new Grupo;
     crearGrupo(*ptrGrupo);

     string idGrupo;
     cin >>idGrupo;

     //*idGrupo=toupper(*idGrupo);

     //string srt(idGrupo);


   /*Grupo aux;
     crearGrupo(aux);*/
     setIdGrupo(*ptrGrupo,idGrupo);
     PtrNodoLista cursor = localizarDato(listaGrupos ,ptrGrupo);

     if (cursor == fin())
     {
          cout << "No existe el grupo seleccionado." << endl;
          system ("PAUSE");
     }
     else
     {
          int seleccion;

          cout << "Que dato desea modificar?" << endl << endl;
          cout << "1. Nombre del grupo" << endl;
          cout << "2. id del equipo 1:" << endl;
          cout << "3. id del equipo 2:" << endl;
          cout << "4. id del equipo 3:" << endl;
          cout << "5. id del equipo 4:" << endl;
          cout << "Su eleccion: ";
          cin >> seleccion;

          char dato[50];
          switch (seleccion){

               case 1: system("cls");
                       cin.ignore();
                       cout << "Ingrese nombre del grupo: " ;
                       cin.getline(dato, 50);
                       setNombreGrupo(*((Grupo*)(cursor->ptrDato)), dato);
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo 1: " ;
                       cin.getline(dato, 50);
                       setIdEquipo(equipoAux,cadenaAentero(dato));
                       puntero =localizarDato(listaEquipo,&equipoAux);
                       if(puntero != fin())
                       setEquipo1(*((Grupo*)(cursor->ptrDato)) , ((Equipo*)puntero->ptrDato)  );
                       else
                       {
                           cout<<"No existe un equipo con ese ID"<<endl;
                           system("Pause");
                       }

                       //cout<<getIdEquipo(*(getEquipo1(*ptrGrupo)));

                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo 2: " ;
                       cin.getline(dato, 50);
                       setIdEquipo(equipoAux,cadenaAentero(dato));
                       puntero =localizarDato(listaEquipo,&equipoAux);
                       if(puntero != fin())
                       setEquipo2(*((Grupo*)(cursor->ptrDato)) , ((Equipo*)puntero->ptrDato)  );
                       else
                       {
                           cout<<"No existe un equipo con ese ID"<<endl;
                           system("Pause");
                       }


                       break;
               case 4: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo 3: " ;
                       cin.getline(dato, 50);
                       setIdEquipo(equipoAux,cadenaAentero(dato));
                       puntero =localizarDato(listaEquipo,&equipoAux);
                       if(puntero != fin())
                       setEquipo3(*((Grupo*)(cursor->ptrDato)) , ((Equipo*)puntero->ptrDato)  );
                       else
                       {
                           cout<<"No existe un equipo con ese ID"<<endl;
                           system("pause");
                       }


                       break;
               case 5: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo 4: " ;
                       cin.getline(dato, 50);
                       setIdEquipo(equipoAux,cadenaAentero(dato));
                       puntero =localizarDato(listaEquipo,&equipoAux);
                       if(puntero != fin())
                       setEquipo4(*((Grupo*)(cursor->ptrDato)) , ((Equipo*)puntero->ptrDato)  );
                       else
                       {
                           cout<<"No existe un equipo con ese ID"<<endl;
                           system("Pause");
                       }


                       break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
          }
     }
};

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

Grupo* reportarGrupoMuerte(Lista &listaGrupos)
{
   PtrNodoLista cursor = primero(listaGrupos);
   Grupo* aux;

   int  goles=0;
   while(cursor != fin())
   {
       int golesTotales = 0;

       golesTotales = getGolesFavor(*(getEquipo1(*((Grupo*)cursor->ptrDato)))) + getGolesFavor(*(getEquipo2(*((Grupo*)cursor->ptrDato)))) + getGolesFavor(*(getEquipo3(*((Grupo*)cursor->ptrDato)))) + getGolesFavor(*(getEquipo4(*((Grupo*)cursor->ptrDato))));

       if(golesTotales > goles)
       {
           aux =((Grupo*)cursor->ptrDato);
           goles = golesTotales;
       }
       cursor = siguiente(listaGrupos, cursor);
   }



   return aux;
}
/******************************************************************************/

//esto es solo hasta consultar al profesor... mi razonamiento es que cuando el administrador ingrese el id del partido
//esto significa que el partido se inicio y pasa a la lista de partidos en ejecucion (por ahora no le den bola)

/*-----------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------*/

                         // PARTIDOS(EVENTOS) //
void ordenarGrupo(Lista &listaGrupo)//ESTO LO HIZO EZE EL 20/6
{

    PtrNodoLista cursor = primero(listaGrupo);

    while(cursor != fin())
    {

      Lista auxEquipo;
      crearLista(auxEquipo,&compararPuntos);
      adicionarFinal(auxEquipo,(getEquipo1(*((Grupo*)cursor->ptrDato))));
      adicionarFinal(auxEquipo,(getEquipo2(*((Grupo*)cursor->ptrDato))));
      adicionarFinal(auxEquipo,(getEquipo3(*((Grupo*)cursor->ptrDato))));
      adicionarFinal(auxEquipo,(getEquipo4(*((Grupo*)cursor->ptrDato))));

      int longi =longitud(auxEquipo);
      PtrNodoLista base = primero(auxEquipo);

      PtrNodoLista sig =siguiente(auxEquipo,base);

      for(int i=0;i<longi-1;i++)
      {

         for(int j=0;j<longi-1;j++)
         {

             if(getPuntos(*((Equipo*)base->ptrDato)) < getPuntos(*((Equipo*)sig->ptrDato)))
             {

                 PtrDato puntero =  base->ptrDato;
                 base->ptrDato = sig->ptrDato;
                 sig->ptrDato = puntero;
             }
             else if(getPuntos(*((Equipo*)base->ptrDato)) == getPuntos(*((Equipo*)sig->ptrDato)))
             {

                 int golesbase = getGolesFavor(*((Equipo*)base->ptrDato)) - getGolesContra(*((Equipo*)base->ptrDato));
                 int golesSig = getGolesFavor(*((Equipo*)sig->ptrDato)) - getGolesContra(*((Equipo*)sig->ptrDato));
                 if(golesSig > golesbase)
                 {
                     PtrDato puntero =  base->ptrDato;
                     base->ptrDato = sig->ptrDato;
                     sig->ptrDato = puntero;
                 }
             }

             base = siguiente(auxEquipo,base);
             sig = siguiente(auxEquipo,sig);

         }
       base = primero(auxEquipo);
       sig = siguiente(auxEquipo,base);

      }
          PtrNodoLista aux = primero(auxEquipo);
          setEquipo1(*((Grupo*)cursor->ptrDato),((Equipo*)aux->ptrDato));
          aux = siguiente(auxEquipo,aux);
          setEquipo2(*((Grupo*)cursor->ptrDato),((Equipo*)aux->ptrDato));
          aux = siguiente(auxEquipo,aux);
          setEquipo3(*((Grupo*)cursor->ptrDato),((Equipo*)aux->ptrDato));
          aux = siguiente(auxEquipo,aux);
          setEquipo4(*((Grupo*)cursor->ptrDato),((Equipo*)aux->ptrDato));

      cursor = siguiente(listaGrupo,cursor);
    }
}

/*-----------------------------------------------------------------------------------------*/

void actualizarPartidos(Lista &listaPartidosTerminados,Lista &listaPartidos,Lista &listaGrupos,Lista &listaEjecucion )//ESTO LO HIZO EZE EL 20/6
{

    ordenarGrupo(listaGrupos);


    PtrNodoLista cursor = fin();
    PtrNodoLista cursor2 = fin();
    PtrNodoLista auxCursor = fin();
    PtrNodoLista aux =fin();
    int idPartido = 0;
    Grupo gru;
    crearGrupo(gru);
    Partido par;
    crearPartido(par);

    if(! listaVacia(listaPartidosTerminados))
    {
        cursor = primero(listaPartidosTerminados);
        while(cursor != fin())
        {      //cout<<"idPartido "<<idPartido <<" "<<"id de lista "<<getIdPartido(*((Partido*)cursor->ptrDato))<<endl;
            if(idPartido < getIdPartido(*((Partido*)cursor->ptrDato)))
            {
                idPartido = getIdPartido(*((Partido*)cursor->ptrDato));
                //cout<<"idpartido "<<idPartido<<endl;
            }
           cursor = siguiente(listaPartidosTerminados,cursor);
        }
    int idPartido2 = 100;
    PtrNodoLista puntero = fin();
    if(! listaVacia(listaPartidos))
    {
        puntero = primero(listaPartidos);
        while(puntero != fin())
        {      //cout<<"idPartido "<<idPartido <<" "<<"id de lista "<<getIdPartido(*((Partido*)cursor->ptrDato))<<endl;
            if(idPartido > getIdPartido(*((Partido*)puntero->ptrDato)))
            {
                idPartido2 = getIdPartido(*((Partido*)puntero->ptrDato));
                //cout<<"idpartido "<<idPartido<<endl;
            }
           puntero = siguiente(listaPartidosTerminados,puntero);
        }
     }
     int idPartido3 = 100;
    PtrNodoLista punt = fin();
    if(! listaVacia(listaEjecucion))
    {
        punt = primero(listaEjecucion);
        while(punt != fin())
        {      //cout<<"idPartido "<<idPartido <<" "<<"id de lista "<<getIdPartido(*((Partido*)cursor->ptrDato))<<endl;
            if(idPartido > getIdPartido(*getPartidoEjecucion(*((ParEjecucion*)punt->ptrDato))))
            {
                idPartido3 = getIdPartido(*getPartidoEjecucion(*((ParEjecucion*)punt->ptrDato)));

            }
           punt = siguiente(listaEjecucion,punt);
        }
     }

     if((idPartido >= 48) && (idPartido < 55)&&(idPartido2 > 48)&&(idPartido3 >= 48))
     {

 //--------------------------------49-------------------------------------------------------------
       setIdGrupo(gru,"A");

       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,49);
       cursor = localizarDato(listaPartidos,&par);
       if(cursor != fin())
       {
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"B");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"El partido esta en ejecucion"<<endl;
           }*/

       }
       }
//---------------------------------50------------------------------------------------------------
       setIdGrupo(gru,"C");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,50);
       cursor = localizarDato(listaPartidos,&par);
       if(cursor != fin())
       {
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"D");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 50"<<endl;
           }*/
       }
       }
//--------------------------------51------------------------------------------------------------
       setIdGrupo(gru,"B");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,51);
       cursor = localizarDato(listaPartidos,&par);
       if(cursor != fin())
       {
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"A");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 51"<<endl;
           }*/
       }
       }
//----------------------------------52-------------------------------------------------------------
       setIdGrupo(gru,"D");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,52);
       cursor = localizarDato(listaPartidos,&par);
       if(cursor != fin())
       {
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"C");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 52"<<endl;
           }*/
       }
       }
//---------------------------------53---------------------------------------------------------------
       setIdGrupo(gru,"E");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,53);
       cursor = localizarDato(listaPartidos,&par);
       if(cursor != fin())
       {
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"F");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 53"<<endl;
           }*/
       }
       }
//--------------------------------54----------------------------------------------------------------
       setIdGrupo(gru,"G");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,54);
       cursor = localizarDato(listaPartidos,&par);
       if(cursor != fin())
       {
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"H");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 !=fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 54"<<endl;
           }*/
        }
       }
//--------------------------------55----------------------------------------------------------------
       setIdGrupo(gru,"F");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,55);
       if(cursor2 != fin())
       {
          cursor = localizarDato(listaPartidos,&par);
          if(cursor != fin())
          {
              setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));
          }


          setIdGrupo(gru,"E");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }
        }

       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 55"<<endl;
           }*/
       }
       }
//--------------------------------56----------------------------------------------------------------
       setIdGrupo(gru,"H");
       cursor2 = localizarDato(listaGrupos,&gru);
       if(cursor2 != fin())
       {
       setIdPartido(par,56);
       if(cursor2 != fin())
       {
          cursor = localizarDato(listaPartidos,&par);
          if(cursor != fin())
          setIdEquipoL(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo1(*((Grupo*)cursor2->ptrDato))));

          setIdGrupo(gru,"G");
          cursor2 = localizarDato(listaGrupos,&gru);
          if(cursor2 != fin())
          {
              setIdEquipoV(*((Partido*)cursor->ptrDato),getIdEquipo(*getEquipo2(*((Grupo*)cursor2->ptrDato))));
          }


       }
       else
       {

           /*else
           {
              cout<<"no se encuentra el id del partido 56"<<endl;
           }*/
       }
       }
     }
 //-----------------------------------------------------------------------------------------------------
 //---------------------------CUARTOS-----------------------------------------------------------------
     if((idPartido >= 56) && (idPartido < 60)&&(idPartido2 > 56)&&(idPartido3 >= 56))
     {

 //----------------------------57---------------------------------------------------------------------
         setIdPartido(par,49);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,57);
             cursor2 = localizarDato(listaPartidos,&par);
             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,50);
                cursor = localizarDato(listaPartidosTerminados,&par);
                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }

             }
             else
             {

                /*else
                {
                  cout<<"no se encuentra el id del partido 57"<<endl;
                }*/
             }
         }
//-------------------------58-----------------------------------------------------------------------------
         setIdPartido(par,53);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,58);
             cursor2 = localizarDato(listaPartidos,&par);
             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,54);
                cursor = localizarDato(listaPartidosTerminados,&par);
                if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }
             }
             else
             {

           /*else
           {
              cout<<"no se encuentra el id del partido 58"<<endl;
           }*/
             }
         }
//------------------------------59-------------------------------------------------------------
        setIdPartido(par,51);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,59);
             cursor2 = localizarDato(listaPartidos,&par);
             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,52);
                cursor = localizarDato(listaPartidosTerminados,&par);
                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }

             }
             else
             {

           /*else
           {
              cout<<"no se encuentra el id del partido 59"<<endl;
           }*/
             }
         }
//----------------------------------------60-----------------------------------------------------------
        setIdPartido(par,55);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,60);
             cursor2 = localizarDato(listaPartidos,&par);
             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,56);
                cursor = localizarDato(listaPartidosTerminados,&par);
                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }

             }
             else
             {

           /*else
           {
              cout<<"no se encuentra el id del partido 60"<<endl;
           }*/
             }
         }

      }   //---------------------------------------------------------------------------
 //---------------------------------SEMIFINALES-----------------------------------------------
     if((idPartido>=60) && (idPartido < 62)&&(idPartido2 > 60)&&(idPartido3 >= 60))
     {
 //-------------------------------61--------------------------------------------------------
         setIdPartido(par,57);
         cursor = localizarDato(listaPartidosTerminados,&par);

         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,61);
             cursor2 = localizarDato(listaPartidos,&par);

             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,58);

                cursor = localizarDato(listaPartidosTerminados,&par);

                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }
             }
             else
             {
                //auxCursor = localizarDato(listaPartidosTerminados,&par);

           /*else
           {
              cout<<"no se encuentra el id del partido 61"<<endl;
           }*/
             }
         }
//-----------------------------------62-------------------------------------------------------------
      setIdPartido(par,59);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,62);

             cursor2 = localizarDato(listaPartidos,&par);

             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,60);

                cursor = localizarDato(listaPartidosTerminados,&par);

                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }
             }
             else
             {
                //auxCursor = localizarDato(listaPartidosTerminados,&par);

           /*else
           {
              cout<<"no se encuentra el id del partido 62"<<endl;
           }*/
             }
         }

     }

     if(idPartido>=62)
     {
 //--------------------------------------------------------------------------------------------------
 //-------------------------------FINAL----------------------------------------------------------------
         setIdPartido(par,61);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,64);
             cursor2 = localizarDato(listaPartidos,&par);
             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,62);
                cursor = localizarDato(listaPartidosTerminados,&par);
                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) > getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }
             }
             else
             {
                //auxCursor = localizarDato(listaPartidosTerminados,&par);

           /*else
           {
              cout<<"no se encuentra el id del partido 64"<<endl;
           }*/
             }
         }
//-----------------------------------------------------------------------------------------------------
//-------------------------------3er y 4to Puesto------------------------------------------------------
         setIdPartido(par,61);
         cursor = localizarDato(listaPartidosTerminados,&par);
         if(cursor == fin())
         {
             //cout<<"No se puede definir la llave,faltan jugar partidos "<<endl;
         }
         else
         {
             setIdPartido(par,63);
             cursor2 = localizarDato(listaPartidos,&par);
             if(cursor2 != fin())
             {
                if(getGolesL(*((Partido*)cursor->ptrDato)) < getGolesV(*((Partido*)cursor->ptrDato)))
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                }
                else
                {
                   setIdEquipoL(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                }
                setIdPartido(par,62);
                cursor = localizarDato(listaPartidosTerminados,&par);
                 if(cursor != fin())
                {
                   if(getGolesL(*((Partido*)cursor->ptrDato)) < getGolesV(*((Partido*)cursor->ptrDato)))
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoL(*((Partido*)cursor->ptrDato)));
                   }
                   else
                   {
                    setIdEquipoV(*((Partido*)cursor2->ptrDato),getIdEquipoV(*((Partido*)cursor->ptrDato)));
                   }
                }
             }
             else
             {

           /*else
           {
              cout<<"no se encuentra el id del partido 63"<<endl;
           }*/
             }
         }
     }
}
}
/*---------------------------------------------------------------------------------------*/

void inicioPartido(Lista &listaPartidos, Lista &listaEjecucion)//ESTO LO HIZO EZE EL 20/6
{
     int idPartido;

     cout<<"ingrese el ID del partido a iniciar: "<<endl;
     cin>>idPartido;

     Partido aux;
     crearPartido(aux);
     setIdPartido(aux,idPartido);
     PtrNodoLista cursor = fin();

      cursor = localizarDato(listaPartidos,&aux);
    if(cursor != fin())
      {


      if((getIdEquipoL(*((Partido*)cursor->ptrDato))<0) or (getIdEquipoV(*((Partido*)cursor->ptrDato))<0))
      {
        cout<<"Este partido no se puede jugar todavia..."<<endl;
      }
      else
      {
        int idEquipo1 = getIdEquipoL(*((Partido*)cursor->ptrDato));
        cout<<"idEquipo1 "<<idEquipo1<<endl;
        int idEquipo2 = getIdEquipoV(*((Partido*)cursor->ptrDato));
        cout<<"idEquipo2 "<<idEquipo2<<endl;
        PtrNodoLista aux2 = primero(listaEjecucion);
        //recorrerListaEjecucion(listaEjecucion);
        bool encontrado = false;
        while(aux2 != fin())
        {
            //cout<<getIdEquipoL(*((Partido*)aux2->ptrDato))<<endl;
            //cout<<getIdEquipoV(*((Partido*)aux2->ptrDato))<<endl;
            if((getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)aux2->ptrDato)))) == idEquipo1) or (getIdEquipoV(*(getPartidoEjecucion(*((ParEjecucion*)aux2->ptrDato)))) == idEquipo1) or (getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)aux2->ptrDato)))) == idEquipo2) or (getIdEquipoV(*(getPartidoEjecucion(*((ParEjecucion*)aux2->ptrDato)))) == idEquipo2))
            {
                encontrado = true;
            }
            aux2 = siguiente(listaEjecucion,aux2);
        }

        if(! encontrado)
        {
            setGolesL(*((Partido*)cursor->ptrDato),0);
            setGolesV(*((Partido*)cursor->ptrDato),0);
            ParEjecucion* par = new ParEjecucion;
            crearParEjecucion(*par);
            //cout<<getIdPartido(*((Partido*)cursor->ptrDato))<<";"<<(getIdEquipoL(*((Partido*)cursor->ptrDato)))<<";"<<(getIdEquipoV(*((Partido*)cursor->ptrDato)))<<";"<<(getGolesL(*((Partido*)cursor->ptrDato)))<<";"<<(getGolesV(*((Partido*)cursor->ptrDato)))<<endl;
            setPartidoEjecucion(*par,((Partido*)cursor->ptrDato));
            //cout<<par->partido->idPartido<<";"<<par->partido->idEquipoL<<";"<<par->partido->idEquipoV<<endl;
            adicionarFinal(listaEjecucion,par);
            //recorrerListaEjecucion(listaEjecucion);
            eliminarDato(listaPartidos,&aux);
            //recorrerListaPartidos(listaPartidos);

            cout<<"\n**********************"<<endl;
            cout<<"* inicio el partido! *"<<endl;
            cout<<"**********************"<<endl;
        }
        else
        {
            cout<<"uno de los dos equipos ya esta disputando un partido"<<endl;
        }

     }
      }
      else
      {
          cout<<"el id del partido no se encuentra"<<endl;
      }
}

/*-----------------------------------------------------------------------------------------*/
void agregarEventos(Lista &listaEjecucion, Lista &listaEquipo)//ESTO LO HIZO EZE EL 20/6
{
    int idPartido;

     cout<<"ingrese el ID del partido: "<<endl;
     cin>>idPartido;
     Partido parti;
     crearPartido(parti);
     setIdPartido(parti,idPartido);


     ParEjecucion aux;
     crearParEjecucion(aux);
     setPartidoEjecucion(aux,&parti);
     PtrNodoLista nodo = fin();

     nodo = localizarDato(listaEjecucion,&aux);

     if(nodo != fin())
     {
           //cout<<"\n**********************"<<endl;
           //cout<<"* Entro al Partido *"<<endl;
           //cout<<"**********************"<<endl;
           //Jugador jugador;
           //crearJugador(jugador);
           int idJugador = 0;
           cout<<"ingrese el ID del jugador que convirtio un gol"<<endl;
           cin>>idJugador;
           //cout<<idJugador<<endl;
           //setIdJugador(jugador,idJugador);


           PtrNodoLista ptrJugador = fin();
           //cout<<"vamos a buscar al jugador"<<endl;
           ptrJugador = localizarJugador(listaEquipo,idJugador);

           //cout<<getNombreJugador(*((Jugador*)ptrJugador->ptrDato))<<endl;
              if (ptrJugador != fin())
              {
                //cout<<"primer if"<<endl;
                int idEquipoPer = getIdEquipoPertenece(*((Jugador*)ptrJugador->ptrDato));
                //cout<<"idEquipo pertenece "<<idEquipoPer<<endl;

                int idEquipo1 = getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))));
                //cout<<"idEquipo 1:"<<idEquipo1<<endl;

                int idEquipo2 = getIdEquipoV(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))));
                //cout<<"idEquipo 2:"<<idEquipo2<<endl;
                if((idEquipoPer == idEquipo1)or(idEquipoPer == idEquipo2))
                {
                      if(idEquipoPer == idEquipo1)
                  {
                     cout<<"Equipo local"<<endl;
                     Evento* evento = new Evento;
                     crearEvento(*evento);
                     setJugador(*evento,((Jugador*)ptrJugador->ptrDato));
                     Equipo aux;
                     crearEquipo(aux);
                     setIdEquipo(aux,idEquipo1);
                     PtrNodoLista dat = localizarDato(listaEquipo,&aux);
                     //cout<<"Equipo 1 "<<getNombreEquipo(*((Equipo*)dat->ptrDato))<<endl;
                     setEquipo(*evento,((Equipo*)dat->ptrDato));
                     setIdEquipo(aux,idEquipo2);
                     dat = localizarDato(listaEquipo,&aux);
                     //cout<<"Equipo 2 "<<getNombreEquipo(*((Equipo*)dat->ptrDato))<<endl;
                     setEquipoContrario(*evento,((Equipo*)dat->ptrDato));
                     encolar((*((Cola*)getCola(*(ParEjecucion*)nodo->ptrDato))),evento);
                     //cout<<"paso 1"<<endl;


                   }
                   else if(idEquipoPer == idEquipo2)
                   {
                     cout<<"Equipo Visitante"<<endl;
                     Evento* evento = new Evento;
                     crearEvento(*evento);
                     setJugador(*evento,((Jugador*)ptrJugador->ptrDato));
                     Equipo aux;
                     crearEquipo(aux);
                     setIdEquipo(aux,idEquipo2);
                     PtrNodoLista dat = localizarDato(listaEquipo,&aux);
                     setEquipo(*evento,((Equipo*)dat->ptrDato));
                     setIdEquipo(aux,idEquipo1);
                     dat = localizarDato(listaEquipo,&aux);
                     setEquipoContrario(*evento,((Equipo*)dat->ptrDato));
                     encolar((*((Cola*)getCola(*(ParEjecucion*)nodo->ptrDato))),evento);

                    }
                }
                else
                {
                    cout<<"El jugador no pertenece a ninguno de los dos equipos"<<endl;
                }


                    /*else
                    {
                      cout<<endl;
                      cout<<"El ID del jugador no pertenece a niguno de los 2 equipo"<<endl;
                      cout<<endl;
                    }*/

                }
                else
                {
                    cout<<endl;
                    cout<<"El ID del jugador no pertenece a niguno de los 2 equipo"<<endl;
                    cout<<endl;
                }
          }
          else
          {
            cout<<endl;
            cout<<"El id ingresado no corresponde a ningun partido"<<endl;
            cout<<endl;
          }
}
/*-----------------------------------------------------------------------------------------*/

void procesarColas(Lista &listaEjecucion,Lista &listaEquipo,PtrNodoLista partido)//ESTO LO HIZO EZE EL 20/6
{

        //PtrDato puntero = getCola(*((ParEjecucion*)cursor->ptrDato));
        //Cola auxCola = *((Cola*)puntero);
        Jugador* ayuda;

        //cout<<"entrara?"<<endl;

        while(! colaVacia(*((Cola*)getCola(*((ParEjecucion*)partido->ptrDato)))))
        {

           PtrDato evento = desencolar(*((Cola*)getCola(*((ParEjecucion*)partido->ptrDato))));
           //cout<<getNombreJugador(*(getJugador(*((Evento*)evento))))<<";"<<"Equipo 1 "<<getNombreEquipo(*(getEquipo(*((Evento*)evento))))<<";"<<"Equipo 2 "<<getNombreEquipo(*(getEquipoContrario(*((Evento*)evento))))<<endl;
           ayuda = getJugador(*((Evento*)evento));
           //cout<<"entro"<<endl;
           //cout<<getIdJugador(*ayuda)<<endl;

           int idJugador = 0;
           idJugador = getIdJugador(*(ayuda));
           //cout<<"id del jugador"<<idJugador<<endl;
           PtrNodoLista nodo = localizarJugador(listaEquipo,idJugador);
           setGoles(*((Jugador*)(nodo->ptrDato)),getGoles(*((Jugador*)nodo->ptrDato))+1);

           int idEquipo = getIdEquipoPertenece(*((Jugador*)(nodo->ptrDato)));
           Equipo equi;
           crearEquipo(equi);
           setIdEquipo(equi,idEquipo);
           nodo = localizarDato(listaEquipo,&equi);

           int golesF = getGolesFavor(*((Equipo*)nodo->ptrDato));

           setGolesFavor((*((Equipo*)nodo->ptrDato)),golesF + 1);

           //cout<<"id equipo "<<getIdEquipo(*(getEquipoContrario(*((Evento*)evento))))<<endl;

           setIdEquipo(equi,getIdEquipo(*(getEquipoContrario(*((Evento*)evento)))));
           nodo = localizarDato(listaEquipo,&equi);
           int golesC = getGolesContra(*((Equipo*)(nodo->ptrDato)));
           setGolesContra(*((Equipo*)(nodo->ptrDato)),golesC + 1);

           //cout<<"IdEquipo "<<idEquipo<<endl;

           if (idEquipo == getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)partido->ptrDato)))))
           {
               setGolesL(*(getPartidoEjecucion(*((ParEjecucion*)partido->ptrDato))),getGolesL(*(getPartidoEjecucion(*((ParEjecucion*)partido->ptrDato))))+1);
           }
           else
           {

               setGolesV(*(getPartidoEjecucion(*((ParEjecucion*)partido->ptrDato))),getGolesV(*(getPartidoEjecucion(*((ParEjecucion*)partido->ptrDato))))+1);
           }

        }


    }

/*-----------------------------------------------------------------------------------------*/
void terminarPartidos(Lista &listaEjecucion,Lista &listaEquipo,Lista &listaPartidosTerminados)//ESTO LO HIZO EZE EL 20/6
{
    int idPartido=0;
    recorrerListaEjecucion(listaEjecucion);
    PtrNodoLista cursor = primero(listaEjecucion);

    if(cursor != fin())
    {
    cout<<"Elija el partido que quiere terminar"<<endl;
    cin>>idPartido;

     Partido parti;
     crearPartido(parti);
     setIdPartido(parti,idPartido);


     ParEjecucion aux;
     crearParEjecucion(aux);
     setPartidoEjecucion(aux,&parti);
     PtrNodoLista nodo = fin();

     nodo = localizarDato(listaEjecucion,&aux);
     //cout<<"nodo :"<<getIdPartido(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))))<<endl;
     int idEquipo = 0;

     if(nodo != fin())
     {
        procesarColas(listaEjecucion,listaEquipo,nodo);

        PtrNodoLista auxCursor =fin();
        cursor = localizarDato(listaEjecucion,&aux);
        if(cursor == fin())
        {
            cout<<endl;
            cout<<" no se encuentra el partido de ID: "<<idPartido<<endl;
        }
        else
        {

        //while (cursor != fin())
        //{
          if(getGolesL(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)))) > getGolesV(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)))))
          {
           idEquipo = getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))));

           Equipo equi;
           crearEquipo(equi);
           setIdEquipo(equi,idEquipo);
           PtrNodoLista aux = localizarDato(listaEquipo,&equi);

           setPuntos(*((Equipo*)aux->ptrDato),getPuntos(*((Equipo*)aux->ptrDato))+3);

           auxCursor = siguiente(listaEjecucion,nodo);
           adicionarFinal(listaPartidosTerminados,getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)));
           eliminarNodo(listaEjecucion,nodo);


            cout<<"\n***********************"<<endl;
            cout<<"* Termino el partido! *"<<endl;
            cout<<"***********************"<<endl;

            if(idPartido == 64)
            {
                cout<<"***************************************"<<endl;
                cout<<"**EL CAMPEON ES "<<getNombreEquipo(*((Equipo*)aux->ptrDato))<<"**"<<endl;
                cout<<"***************************************"<<endl;
            }

         }
         else if(getGolesL(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)))) == getGolesV(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)))))
         {
           if(idPartido < 49)
           {
              idEquipo = getIdEquipoL(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))));

              Equipo equi;
              crearEquipo(equi);
              setIdEquipo(equi,idEquipo);
              PtrNodoLista aux = localizarDato(listaEquipo,&equi);

              setPuntos(*((Equipo*)aux->ptrDato),getPuntos(*((Equipo*)aux->ptrDato))+1);

              idEquipo = getIdEquipoV(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))));

              Equipo equip;
              crearEquipo(equip);
              setIdEquipo(equip,idEquipo);
              PtrNodoLista aux2 = localizarDato(listaEquipo,&equip);

              setPuntos(*((Equipo*)aux2->ptrDato),getPuntos(*((Equipo*)aux2->ptrDato))+1);

              auxCursor = siguiente(listaEjecucion,nodo);
              adicionarFinal(listaPartidosTerminados,getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)));
              eliminarNodo(listaEjecucion,nodo);
              //cursor = auxCursor;

               cout<<"\n***********************"<<endl;
               cout<<"* Termino el partido! *"<<endl;
               cout<<"***********************"<<endl;
           }
           else
           {
               cout<<endl;
               cout<<"en esta etapa no se permiten los empates"<<endl;
               cout<<"el partido ID:"<<getIdPartido(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))))<<" sigue en ejecucion"<<endl;

           }


        }
        else
        {
           idEquipo = getIdEquipoV(*(getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato))));

           Equipo equi;
           crearEquipo(equi);
           setIdEquipo(equi,idEquipo);
           PtrNodoLista aux = localizarDato(listaEquipo,&equi);

           setPuntos(*((Equipo*)aux->ptrDato),getPuntos(*((Equipo*)aux->ptrDato))+3);

           auxCursor = siguiente(listaEjecucion,nodo);
           adicionarFinal(listaPartidosTerminados,getPartidoEjecucion(*((ParEjecucion*)nodo->ptrDato)));
           eliminarNodo(listaEjecucion,nodo);
           //cursor = auxCursor;

            cout<<"\n***********************"<<endl;
            cout<<"* Termino el partido! *"<<endl;
            cout<<"***********************"<<endl;

            if(idPartido == 64)
            {
                cout<<"***************************************"<<endl;
                cout<<"**EL CAMPEON ES "<<getNombreEquipo(*((Equipo*)aux->ptrDato))<<"**"<<endl;
                cout<<"***************************************"<<endl;
            }

        }
        /*
        auxCursor = siguiente(listaEjecucion,cursor);
        adicionarFinal(listaPartidosTerminados,getPartidoEjecucion(*((ParEjecucion*)cursor->ptrDato)));
        eliminarNodo(listaEjecucion,cursor);
        cursor = auxCursor;*/
    }
    //cursor = siguiente(listaEjecucion,cursor);
    //}
  }
  else
  {
      cout<<endl;
      cout<<"no se encuentra el partido"<<endl;
  }
    }
    else
    {
        cout<<endl;
        cout<<"no hay partidos en ejecucion"<<endl;
    }

}


/*-----------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------*/


/******************************************************************************/
//agrego un comparar

ResultadoComparacion compararListaJugadores(PtrDato ptrDato1, PtrDato ptrDato2) {
    int dato1 = ((Jugador*) ptrDato1)->idJugador;
    int dato2 = ((Jugador*) ptrDato2)->idJugador;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

/******************************************************************************/

void recorrerListaJugadores(Lista &jugadores)
{

//RECORRO LISTA DE LOS JUGADORES

 mostrarEncabezadoJugador();/*Escribe el encabezado con los datos que tiene el Jugador*/
 PtrNodoLista cursor = primero(jugadores);

 while(cursor != fin())
 {
    cout<<"\t";
    int Id= getIdJugador(*((Jugador*)cursor->ptrDato));
    cout<<Id<<" ";
    string Nombre= getNombreJugador(*((Jugador*)cursor->ptrDato));
    cout<<Nombre<<" ";
    int Goles= getGoles(*((Jugador*)cursor->ptrDato));
    cout<<Goles<<" | ";
    int idEquipoPertenece= getIdEquipoPertenece(*((Jugador*)cursor->ptrDato));
    cout<<idEquipoPertenece<<" |\n";

    cout<<endl;
    cursor = siguiente(jugadores, cursor);

 }

}

/******************************************************************************/

                       /*** LOS REPORTES ***/

//goles totales a lo largo del mundial

void golesTotales(Lista &listaAux){


     PtrNodoLista actual;

     actual  = primero(listaAux);
     int total=0;
     int cont=0;
     while(actual->sgte != NULL)
     {

               if(  getGoles(*((Jugador*)actual->ptrDato)) > 0  )
               {
                    total=total +getGoles(*((Jugador*)actual->ptrDato));
                    cont=cont+1;
               }





          actual = actual->sgte;



     }
      cout<<"\n\n";
      cout<<"Cantidad de goles que hubo en el mundial:\n"<<endl;
      cout<<"\n"<<"Cantidad de jugadores totales que convirtieron : " << cont<<", Camtidad de goles : "<<total<<endl;
     }

/******************************************************************************/

//cantidad de jugadores por segmento
void cantidad(Lista &listaAux)
{
     cout<<"Estadisticas.........\n\n";
     cout<<"\tJugadores con la misma cantidad de goles:"<<endl;
     int cont=1;
     PtrNodoLista actual;
     PtrNodoLista siguiente;
     bool a=false;
     PtrDato aux;
     actual  = primero(listaAux);

     while(actual->sgte != NULL)
     {
        siguiente = actual->sgte;

          while(siguiente!=NULL)
          {

               if(  getGoles(*((Jugador*)actual->ptrDato)) == getGoles(*((Jugador*)siguiente->ptrDato))  )
               {
                    cont=cont+1;
               }

              siguiente = siguiente->sgte;
          }

          int gol=getGoles(*((Jugador*)actual->ptrDato));

          PtrNodoLista siguiente2 = actual->sgte;

          if((gol!=getGoles(*((Jugador*)siguiente2->ptrDato))) && (a==false)){//que sea diferente y que no se halla procesado
                cout<<"\n\n\t"<<"Cantidad de Goles : " << gol<<", Cantidad de Jugadores : "<<cont<<endl;
          }else{
                if (a!=true){//es igual,se imprime y se pone un true
                cout<<"\n\n\t"<<"Cantidad de Goles : " << gol<<", Cantidad de Jugadores : "<<cont<<endl;
                a=true;
                }else{
                      if(gol!=getGoles(*((Jugador*)siguiente2->ptrDato))){
                      a=false;
                      }else{
                      a=true;
                      }


                }
          }
          cont=1;
          actual = actual->sgte;
          siguiente = actual->sgte;

     }
}
/******************************************************************************/

//ordeno lista de goleadores
void ordenarLista(Lista &listaAux)

{


     PtrNodoLista actual;
     PtrNodoLista siguiente;
     PtrDato aux;
     actual  = primero(listaAux);

     while(actual->sgte != NULL)
     {
        siguiente = actual->sgte;

          while(siguiente!=NULL)
          {
               if(  getGoles(*((Jugador*)actual->ptrDato)) < getGoles(*((Jugador*)siguiente->ptrDato))  )
               {
                    aux = siguiente->ptrDato;
                    siguiente->ptrDato = actual->ptrDato;
                    actual->ptrDato = aux;
               }


              siguiente = siguiente->sgte;

          }



          actual = actual->sgte;
          siguiente = actual->sgte;

     }



     cout<<"\n\n\t Tabla de goleadores..."<<endl;


}

//creo lista auxiliar de jugadores
 void crear(Lista &listaEquipos)

{

    //RECORRO LISTA DE LOS EQUIPOS
    Lista listaAux;
    crearLista(listaAux,&compararIdJugador);

    PtrNodoLista cursor = primero(listaEquipos);
    while (cursor !=fin())
    {

        PtrDato puntero = getListaJugadores(*((Equipo*)cursor->ptrDato));
        Lista auxLista = *((Lista*)puntero);
        PtrNodoLista cursor2 = primero(auxLista);


        while(cursor2 !=fin())
        {


            adicionarFinal(listaAux,cursor2->ptrDato);

            cursor2 =siguiente(auxLista,cursor2);
        }


        cursor =siguiente(listaEquipos,cursor);
    }


         ordenarLista(listaAux);
         recorrerListaJugadores(listaAux);
         cantidad(listaAux);
         golesTotales(listaAux);



}

/******************************************************************************/

//porcentaje goles locales/visitantes
void calcularPorcentaje(Lista &listaPartidosTerminados){

     PtrNodoLista actual;
     actual  = primero(listaPartidosTerminados);
     int  totalLocales=0;
     int  totalVisitantes=0;
     float porL=0;
     float porV=0;

     while(actual!= NULL)
     {

            totalLocales=totalLocales + getGolesL(*((Partido*)actual->ptrDato));

            totalVisitantes=totalVisitantes + getGolesV(*((Partido*)actual->ptrDato));


          actual = actual->sgte;


     }
     cout<<"\n\n\t Suma de goles  locales "<<totalLocales<<"\t Suma de goles visitantes "<<totalVisitantes<<endl;


        porL=(float)  totalLocales/(totalLocales+totalVisitantes);
        porL=(float) porL*100;

        porV=(float)  totalVisitantes/(totalLocales+totalVisitantes);
        porV=(float) porV*100;

     cout<<"\n\n Porcentaje de goles locales "<<porL<<"%"<<"\t Porcentaje de goles visitantes "<<porV<<"%"<<endl;


}

/******************************************************************************/

//Calculo el total de goles por grupo
void golesDeGrupos(Lista &listaGrupos){

PtrNodoLista cursor = primero(listaGrupos);
   Grupo* aux;

   int  goles=0;
   int total=0;
   while(cursor != fin())
   {
       int golesTotales = 0;
       cout<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<endl;
       cout<<getNombreEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))<<" Goles a favor "<<getGolesFavor(*(getEquipo1(*((Grupo*)cursor->ptrDato))))<<endl;
       cout<<getNombreEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))<<" Goles a favor "<<getGolesFavor(*(getEquipo2(*((Grupo*)cursor->ptrDato))))<<endl;
       cout<<getNombreEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))<<" Goles a favor "<<getGolesFavor(*(getEquipo3(*((Grupo*)cursor->ptrDato))))<<endl;
       cout<<getNombreEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))<<" Goles a favor "<<getGolesFavor(*(getEquipo4(*((Grupo*)cursor->ptrDato))))<<endl;

       golesTotales = getGolesFavor(*(getEquipo1(*((Grupo*)cursor->ptrDato)))) + getGolesFavor(*(getEquipo2(*((Grupo*)cursor->ptrDato)))) + getGolesFavor(*(getEquipo3(*((Grupo*)cursor->ptrDato)))) + getGolesFavor(*(getEquipo4(*((Grupo*)cursor->ptrDato))));
       cout<<"Goles totales de este Grupo :"<<golesTotales<<endl;
       cout<<""<<endl;

       total=total + golesTotales;

       cursor = siguiente(listaGrupos, cursor);
   }


       cout<<"Goles totales :"<<total<<endl;

}

/******************************************************************************/

void ordenarAux(Lista &listaAux)

{


     PtrNodoLista actual;
     PtrNodoLista siguiente;
     PtrDato aux;
     actual  = primero(listaAux);

     int diferencia=0;
     int diferencia2=0;


     while(actual->sgte != NULL)
     {
        siguiente = actual->sgte;



          while(siguiente!=NULL)
          {

               if(  getPuntos(*((Equipo*)actual->ptrDato)) < getPuntos(*((Equipo*)siguiente->ptrDato))  )
               {
                    aux = siguiente->ptrDato;
                    siguiente->ptrDato = actual->ptrDato;
                    actual->ptrDato = aux;
               }else{
                     if(  getPuntos(*((Equipo*)actual->ptrDato)) == getPuntos(*((Equipo*)siguiente->ptrDato))  )
                     {
                             diferencia=getGolesFavor(*((Equipo*)actual->ptrDato))-getGolesContra(*((Equipo*)actual->ptrDato));
                             diferencia2=getGolesFavor(*((Equipo*)siguiente->ptrDato))-getGolesContra(*((Equipo*)siguiente->ptrDato));

                          if(  diferencia < diferencia2){
                               aux = siguiente->ptrDato;
                               siguiente->ptrDato = actual->ptrDato;
                               actual->ptrDato = aux;

                               }
                     }
                     }

              siguiente = siguiente->sgte;


          }



          actual = actual->sgte;
          siguiente = actual->sgte;

     }



    // cout<<"\n\n\t Tabla de grupos..."<<endl;


}

/******************************************************************************/

//Posicion de los equipos en los grupos
 void posiciones(Lista &listaEquipos)

{

    PtrNodoLista actual;
    actual  = primero(listaEquipos);

    int a;
    int b;
    int cont=1;
    int i;

    Lista listaAux;


    for(i=0;i<8;i++){

        crearLista(listaAux,&compararIdEquipo);

            if(cont=1)
            {
              a=0;
              b=4;
            }else{
                  if(cont=2){
                       a=4;
                       b=8;

                  }else{
                        if(cont=3){
                        a=8;
                        b=12;
                        }else{
                               if(cont=4){
                               a=12;
                               b=16;
                               }else {
                                     if(cont=5){

                                         a=16;
                                         b=20;
                                     }else{
                                           if(cont=6){
                                             a=20;
                                             b=24;

                                                     }else{
                                                           if(cont=7){
                                                             a=24;
                                                               b=28;
                                                                     }else{

                                                                     a=28;
                                                                     b=32;


                                                                       }
                                                                 }
                                           }
                              }
                     }
                     }

                     }

            for(int j=a;j<b;j++){

                adicionarFinal(listaAux,actual->ptrDato);

                actual = actual->sgte;
            }

         cont=cont+1;
         ordenarAux(listaAux);

         cout<<" ::::::::::::::::::::::::::GRUPO "<<numeroAcaracter(i)<<endl;
         //cout<<" :::::::::::::\n\n\n"<<endl;
         recorrerEquipo(listaAux,false);

   }

}

/******************************************************************************/

void fixture(Lista &listaPartidos,Lista &listaEquipos,Lista &listaPartidosTerminados){

Lista aux;
crearLista(aux,&compararIdPartidos);
PtrNodoLista apunta = primero(listaPartidosTerminados);

Equipo equi;
crearEquipo(equi);
//CARGO LA LISTA AUX CON LAS 3 LISTAS DE PARTIDOS
while(apunta != fin())
{
    adicionarFinal(aux,apunta->ptrDato);
    apunta = siguiente(listaPartidosTerminados,apunta);
}
/*
apunta = primero(listaEjecucion);
if(apunta != fin())
{
    while(apunta != fin())
    {
    adicionarFinal(aux,getPartidoEjecucion(*((ParEjecucion*)apunta->ptrDato)));
    apunta = siguiente(listaEjecucion,apunta);
    }
}
*/
apunta = primero(listaPartidos);
while(apunta != fin())
{
    adicionarFinal(aux,apunta->ptrDato);
    apunta = siguiente(listaPartidos,apunta);
}

apunta = primero(aux);
int lon = longitud(aux) -1;
PtrNodoLista apunta2 = primero(aux);
//ORDENA LA LISTA AUX POR ID DE PARTIDO
for(int i = 1; i< lon +1;i++)
{
    apunta2 = primero(aux);
    for(int j = 0; j < lon;j++)
    {
        PtrNodoLista punAux =siguiente(aux,apunta2);
        if(getIdPartido(*((Partido*)apunta2->ptrDato)) > getIdPartido(*((Partido*)punAux->ptrDato)))
        {
            PtrDato dato = apunta2->ptrDato;
            apunta2->ptrDato = punAux->ptrDato;
            punAux->ptrDato = dato;
        }
        apunta2 = siguiente(aux,apunta2);
    }
}
cout<<"paso 2"<<endl;
//IMPRIMO POR PANTALLA
apunta = primero(aux);
apunta2 =siguiente(aux,apunta);
PtrNodoLista nodo;

recorrerListaPartidos(aux);
cout<<setiosflags(ios::left);
while(apunta != fin())
{

  if((getIdPartido(*((Partido*)apunta->ptrDato)) == 49) && (apunta2 != fin()))
  {
      cout<<endl;
      cout<<"*************** OCTAVOS DE FINAL *****************"<<endl;
      cout<<endl;

      if((getIdEquipoL(*((Partido*)apunta->ptrDato))>-1)&&(getIdEquipoV(*((Partido*)apunta->ptrDato))>-1))
      {

        setIdEquipo(equi,getIdEquipoL(*((Partido*)apunta->ptrDato)));
        nodo = localizarDato(listaEquipos,&equi);
        if(nodo != fin())
        {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           setIdEquipo(equi,getIdEquipoV(*((Partido*)apunta->ptrDato)));
           nodo = localizarDato(listaEquipos,&equi);
           if(nodo != fin())
           {
              cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
              cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;
           }

        }
      }
      else
      {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoL(*((Partido*)apunta->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoV(*((Partido*)apunta->ptrDato));
           cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;

      }

  }
  else if((getIdPartido(*((Partido*)apunta->ptrDato)) == 57) && (apunta2 != fin()))
  {
      cout<<endl;
      cout<<"*************** CUARTOS DE FINAL *****************"<<endl;
      cout<<endl;

      if((getIdEquipoL(*((Partido*)apunta->ptrDato))>-1)&&(getIdEquipoV(*((Partido*)apunta->ptrDato))>-1))
      {

        setIdEquipo(equi,getIdEquipoL(*((Partido*)apunta->ptrDato)));
        nodo = localizarDato(listaEquipos,&equi);
        if(nodo != fin())
        {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           setIdEquipo(equi,getIdEquipoV(*((Partido*)apunta->ptrDato)));
           nodo = localizarDato(listaEquipos,&equi);
           if(nodo != fin())
           {
              cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
              cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;
           }

        }
      }
      else
      {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoL(*((Partido*)apunta->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoV(*((Partido*)apunta->ptrDato));
           cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;

      }
  }
  else if((getIdPartido(*((Partido*)apunta->ptrDato)) == 61) && (apunta2 != fin()))
  {
      cout<<endl;
      cout<<"****************** SEMIFINAL *********************"<<endl;
      cout<<endl;

      if((getIdEquipoL(*((Partido*)apunta->ptrDato))>-1)&&(getIdEquipoV(*((Partido*)apunta->ptrDato))>-1))
      {

        setIdEquipo(equi,getIdEquipoL(*((Partido*)apunta->ptrDato)));
        nodo = localizarDato(listaEquipos,&equi);
        if(nodo != fin())
        {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           setIdEquipo(equi,getIdEquipoV(*((Partido*)apunta->ptrDato)));
           nodo = localizarDato(listaEquipos,&equi);

           if(nodo != fin())
           {
              cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
              cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;
           }

        }
      }
      else
      {
           cout<<"entro por este lado"<<endl;
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoL(*((Partido*)apunta->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoV(*((Partido*)apunta->ptrDato));
           cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;

      }
  }
  else if((getIdPartido(*((Partido*)apunta->ptrDato)) == 63) && (apunta2 != fin()))
  {
      cout<<endl;
      cout<<"*************** 3ER Y 4TO PUESTO *****************"<<endl;
      cout<<endl;

      if((getIdEquipoL(*((Partido*)apunta->ptrDato))>-1)&&(getIdEquipoV(*((Partido*)apunta->ptrDato))>-1))
      {

        setIdEquipo(equi,getIdEquipoL(*((Partido*)apunta->ptrDato)));
        nodo = localizarDato(listaEquipos,&equi);

        if(nodo != fin())
        {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           setIdEquipo(equi,getIdEquipoV(*((Partido*)apunta->ptrDato)));
           nodo = localizarDato(listaEquipos,&equi);
           if(nodo != fin())
           {
              cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
              cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;
           }

        }
      }
      else
      {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoL(*((Partido*)apunta->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoV(*((Partido*)apunta->ptrDato));
           cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;

      }
  }
  else if(getIdPartido(*((Partido*)apunta->ptrDato)) == 64)
  {
      cout<<endl;
      cout<<"********************* FINAL **********************"<<endl;
      cout<<endl;

      if((getIdEquipoL(*((Partido*)apunta->ptrDato))>-1)&&(getIdEquipoV(*((Partido*)apunta->ptrDato))>-1))
      {

        setIdEquipo(equi,getIdEquipoL(*((Partido*)apunta->ptrDato)));
        nodo = localizarDato(listaEquipos,&equi);
        if(nodo != fin())
        {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           setIdEquipo(equi,getIdEquipoV(*((Partido*)apunta->ptrDato)));
           nodo = localizarDato(listaEquipos,&equi);
           if(nodo != fin())
           {
              cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
              cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;
           }

        }
      }
      else
      {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoL(*((Partido*)apunta->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoV(*((Partido*)apunta->ptrDato));
           cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;

      }
  }
  else
  {
      if((getIdEquipoL(*((Partido*)apunta->ptrDato))>-1)&&(getIdEquipoV(*((Partido*)apunta->ptrDato))>-1))
      {

        setIdEquipo(equi,getIdEquipoL(*((Partido*)apunta->ptrDato)));
        nodo = localizarDato(listaEquipos,&equi);
        if(nodo != fin())
        {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           setIdEquipo(equi,getIdEquipoV(*((Partido*)apunta->ptrDato)));
           nodo = localizarDato(listaEquipos,&equi);
           if(nodo != fin())
           {
              cout<<setw(17)<<getNombreEquipo(*((Equipo*)nodo->ptrDato));
              cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;
           }

        }
      }
      else
      {
           cout<<setw(4)<<getIdPartido(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoL(*((Partido*)apunta->ptrDato));
           cout<<setw(5)<<getGolesL(*((Partido*)apunta->ptrDato));
           cout<<setw(17)<<getIdEquipoV(*((Partido*)apunta->ptrDato));
           cout<<setw(3)<<getGolesV(*((Partido*)apunta->ptrDato))<<endl;

      }
  }
  apunta = siguiente(aux,apunta);
  apunta2 =siguiente(aux,apunta2);
}
/*
PtrNodoLista cursor3 = primero(listaEquipos);
PtrNodoLista cursor4 = primero(listaPartidosTerminados);
string nomL;
string nomV;

int golesV=0;
int golesL=0;

    cout<<"\tResultados....."<<endl<<endl;
    while(cursor4 != fin())
    {


    int Id= getIdPartido(*((Partido*)cursor4->ptrDato));
    cout<<setiosflags(ios::left);
    cout<<setw(4)<<Id;

    int IdEquipoL= getIdEquipoL(*((Partido*)cursor4->ptrDato));

    int IdEquipoV= getIdEquipoV(*((Partido*)cursor4->ptrDato));

    int GolesL= getGolesL(*((Partido*)cursor4->ptrDato));

    int GolesV= getGolesV(*((Partido*)cursor4->ptrDato));

    cursor3 = primero(listaEquipos);


      while(cursor3 != fin())
    {
         if(IdEquipoL==getIdEquipo(*((Equipo*)cursor3->ptrDato))){
          nomL=getNombreEquipo(*((Equipo*)cursor3->ptrDato));
          golesL=getGolesL(*((Partido*)cursor4->ptrDato));

          }else{
                if(IdEquipoV==getIdEquipo(*((Equipo*)cursor3->ptrDato))){
                nomV=getNombreEquipo(*((Equipo*)cursor3->ptrDato));
                golesV=getGolesV(*((Partido*)cursor4->ptrDato));


                }


           }

       cursor3 = siguiente(listaEquipos, cursor3);

    }


    cout<<setw(17)<<nomL<<setw(5)<<GolesL<<setw(17)<<nomV<<setw(3)<<GolesV<<endl;

    cursor4 = siguiente(listaPartidosTerminados, cursor4);


    }

    //Partidos pendientes


PtrNodoLista cursor = primero(listaEquipos);
PtrNodoLista cursor2 = primero(listaPartidos);

     cout<<endl;
     cout<<"\tResultados Pendientes....."<<endl<<endl;
    while(cursor2 != fin())
    {


    int Id= getIdPartido(*((Partido*)cursor2->ptrDato));
    cout<<setiosflags(ios::left);
    cout<<setw(4)<<Id;

    int IdEquipoL= getIdEquipoL(*((Partido*)cursor2->ptrDato));

    int IdEquipoV= getIdEquipoV(*((Partido*)cursor2->ptrDato));

    int GolesL= getGolesL(*((Partido*)cursor2->ptrDato));

    int GolesV= getGolesV(*((Partido*)cursor2->ptrDato));

    cursor = primero(listaEquipos);


      while(cursor != fin())
    {
         if(IdEquipoL==getIdEquipo(*((Equipo*)cursor->ptrDato))){
          nomL=getNombreEquipo(*((Equipo*)cursor->ptrDato));
          golesL=getGolesL(*((Partido*)cursor2->ptrDato));

          }
          else
          {
                if(IdEquipoV==getIdEquipo(*((Equipo*)cursor->ptrDato))){
                nomV=getNombreEquipo(*((Equipo*)cursor->ptrDato));
                golesV=getGolesV(*((Partido*)cursor2->ptrDato));


                } else
                {
                    if(IdEquipoL==-1)
                    {
                       nomL="Local";
                       nomV="Visitante";
                    }
                }
          }

       cursor = siguiente(listaEquipos, cursor);

    }
        if(IdEquipoL==-1)
        {
            cout<<"          Partido pendiente  "<<endl;
        }
        else
        {
            cout<<setw(17)<<nomL<<setw(5)<<GolesL<<setw(17)<<nomV<<setw(3)<<GolesV<<endl;
        }

    cursor2 = siguiente(listaPartidos, cursor2);


    }*/

    }


/******************************************************************************/

/* Presentar un menú con las siguientes opciones:

a. Administrar equipos, jugadores, grupos y partidos
    (Alta, Baja y Modificación) debido a que
    pueden existir errores en los datos.

b. Administrar Partidos
    b.i. Registrar el inicio de un partido (identificado por id).
    b.ii. Registrar los goles ocurridos en cada partido
    (identificando equipo y jugador).
    b.iii. Registrar el fin de un partido.

c. Procesar reportes:

    c.i. Listado de goleadores. Ordenado en forma descendente
        por cantidad de goles. El reporte se deberá segmentar por cantidad
        de goles(por ejemplo, si el máximo de goles es 10,
        deberá figurar “10 goles” y todos los jugadores con 10 goles,
        después 9, y todos los que convirtieron 9 goles, etc). Se deberá poner
        un subtotal indicando la cantidad de jugadores en cada segmento y
        un total final con cantidad de jugadores y cantidad de goles.

    c.ii. Orden de equipos por grupo (con puntos y diferencia de gol).
        Es decir, Grupo A, equipos del Grupo A, Grupo B, equipos del Grupo B,
        etc. Además, se deben informar los goles parciales por grupos
        y el total de todos los grupos.

    c.iii. Listar el fixture con todos los resultados y los partidos pendientes
        ordenados por partido.

    c.iv. Deberá informar “el grupo de la muerte” que será el grupo en que se
    hayan efectuado mayor cantidad de goles totales.

    c.v. Porcentaje goles local o visitante.

d. Salir de la aplicación (se deberán grabar los datos en los archivos).*/


/*main*/

int main()
{
    Lista listaEquipo;
    crearLista(listaEquipo,&compararIdEquipo);

     //agrego la lista de partidos
    Lista listaPartidos;
    crearLista(listaPartidos,&compararIdPartidos);

    Lista listaPartidosTerminados;
    crearLista(listaPartidosTerminados,&compararIdPartidos);

    Lista listaGrupo;
    crearLista(listaGrupo,&compararIdGrupo);

    Lista listaEjecucion;
    crearLista(listaEjecucion,&compararParEjecucion);


    //recorrerEquipo(listaEquipo);
    //recorrerListaGrupo(listaGrupo);

    //agrego una lista aux para los jugadores
    Lista listaJugadores;
    crearLista(listaJugadores,&compararIdJugador);
    cargarJugadores(listaJugadores);


    //recorrerListaPartidos(listaPartidosTerminados);
    //recorrerListaJugadores(listaJugadores);

    //agregarEventos(listaEjecucion,listaEquipo);
    //agregarEventos(listaEjecucion,listaEquipo);
    //terminarPartidos(listaEjecucion,listaEquipo,listaPartidosTerminados);


    // eliminarJugador(listaEquipo);
      //recorrerEquipo(listaEquipo,true);
    //posiciones(listaGrupo);

    /*---------------------------------------------------------------------------*/
    /*--------  lista Errores archivos ------------------------------------------*/
    cout<<endl;
    cout<<"        Errores en los archivos"<<endl;
    cout<<"        ***********************"<<endl;
    cout<<endl;
    bool bandera1;
    bool bandera2;
    bool bandera3;
     cargaArchivos(listaEquipo,listaPartidos,listaGrupo,listaPartidosTerminados);

     bandera1 = validarGrupos(listaGrupo);
     bandera2 = validaGrupoEquipos(listaGrupo);
     bandera3 = validarJugador(listaEquipo);

     if((!bandera1)&&(!bandera2)&&(!bandera3))
     {
         cout<<"Carga completada"<<endl;
         actualizarPartidos(listaPartidosTerminados,listaPartidos,listaGrupo,listaEjecucion);
     }
     else
     {   cout<<endl;
         cout<<"Se recomienda no seguir la ejecucion, existen inconsistencias en los archivos"<<endl;
         cout<<endl;
     }

     //actualizarPartidos(listaPartidosTerminados,listaPartidos,listaGrupo);

system("PAUSE");


                       /*--- MENU ---*/

color(47);

int option;
char respuesta;
fflush(stdin);

do
{
   MenuPrincipal();
   scanf("%d", &option);
   fflush(stdin);
   system("cls");
   switch (option)

  {   case 1 :{ /*a. Administrar equipos, jugadores, grupos y partidos
                (Alta, Baja y Modificación) */option=9;
               AlertaGoles(listaEquipo);
               do{
                      MenuABMtxt();
                      scanf("%d", &option);
                      fflush(stdin);
                      system("cls");
                      switch (option)
                      {case 1:{ /*** equiposABM ***/option=9;

                                     do{
                                       mostrarEncabezadoMenu();
                                       recorrerEquipo(listaEquipo,true);
                                       MenuABM();
                                       scanf("%d", &option);
                                       fflush(stdin);
                                       switch (option)
                                       {case 1:{/*alta();*/
                                                agregarEquipo(listaEquipo);
                                                break;}
                                        case 2:{/*modificacion();*/
                                                modificarEquipo(listaEquipo);
                                                break;}
                                        case 3:{/*baja();*/
                                                eliminarEquipo(listaEquipo);
                                                break;}
                                        case 0:{/*vuelve al sub menu equiposABM*/break;}
                                        default:{mensajeDeErrorMenuABM();break;}
                                        }
                                       }while(option !=0);
                                 break;}
                       case 2:{ /*** jugadoresABM ***/option=9;

                                     do{
                                       mostrarEncabezadoMenu();
                                       recorrerEquipo(listaEquipo, true);
                                       MenuABM();
                                       scanf("%d", &option);
                                       fflush(stdin);
                                       switch (option)
                                       {case 1:{/*alta();*/
                                                agregarJugador(listaEquipo);
                                                break;}
                                        case 2:{/*modificacion();*/
                                                modificarJugador(listaEquipo);
                                                break;}
                                        case 3:{/*baja();*/
                                                eliminarJugador(listaEquipo);
                                                break;}
                                        case 0:{/*vuelve al sub menu equiposABM*/break;}
                                        default:{mensajeDeErrorMenuABM();break;}
                                        }
                                       }while(option !=0);

                               break;}
                       case 3:{ /*gruposABM*/option=9;

                                     do{
                                       mostrarEncabezadoMenu();
                                       recorrerListaGrupo(listaGrupo);
                                       MenuABM();
                                       scanf("%d", &option);
                                       fflush(stdin);
                                       switch (option)
                                       {case 1:{/*alta();*/
                                                 agregarGrupo(listaGrupo,listaEquipo);
                                                 break;}
                                        case 2:{/*modificacion();*/
                                                 modificarGrupo(listaGrupo,listaEquipo);
                                                 break;}
                                        case 3:{/*baja();*/
                                                 eliminarGrupo(listaGrupo);
                                                 break;}
                                        case 0:{/*vuelve al sub menu equiposABM*/break;}
                                        default:{mensajeDeErrorMenuABM();break;}
                                        }
                                       }while(option !=0);

                               break;}
                       case 4:{ /*partidosABM*/option=9;
                                     do{
                                       mostrarEncabezadoMenu();
                                       recorrerListaPartidos(listaPartidos);
                                       MenuABM();
                                       scanf("%d", &option);
                                       fflush(stdin);
                                       switch (option)
                                       {case 1:{/*alta();*/
                                                 agregarPartido(listaPartidos,listaPartidosTerminados,listaEquipo);
                                                 break;}
                                        case 2:{/*modificacion();*/
                                                 modificarPartido(listaPartidos);
                                                 break;}
                                        case 3:{/*baja();*/
                                                 eliminarPartido(listaPartidos);
                                                 break;}
                                        case 0:{/*vuelve al sub menu equiposABM*/break;}
                                        default:{mensajeDeErrorMenuABM();break;}
                                        }
                                       }while(option !=0);

                                 break;}
                       case 0:{ /*vuelve a menu principal*/break;}
                       default:{mensajeDeErrorMenuABMtxt();break;}
                       }
               }while(option != 0);
              break;}

      case 2 :{/*b. Administrar Partidos*/option=9;
               AlertaGoles(listaEquipo);
               do{
                       mostrarEncabezadoMenu();
                       //recorrerListaPartidos(listaPartidos);
                       MenuAdmPartidos();

                       scanf("%d", &option);
                       fflush(stdin);
                       switch (option)
                      {case 1:{mostrarEncabezadoMenu();/*RegIncioPartido();*/
                               recorrerListaPartidos(listaPartidos);
                               inicioPartido(listaPartidos, listaEjecucion);
                               //cout<<"inicio el partido!"<<endl;
                               cout<<endl<<endl;
                       break;}
                       case 2:{mostrarEncabezadoMenu();/*RegGolesOcurridos();*/
                               recorrerEquipo(listaEquipo, false);
                               recorrerListaEjecucion(listaEjecucion);
                               agregarEventos(listaEjecucion,listaEquipo);

                       break;}
                       case 3:{mostrarEncabezadoMenu();cout<<"paso"<<endl;terminarPartidos(listaEjecucion,listaEquipo,listaPartidosTerminados);
                       actualizarPartidos(listaPartidosTerminados,listaPartidos,listaGrupo,listaEjecucion);break;}
                       case 0:{/*vuelve a menu principal*/break;}
                       default:{mensajeDeErrorMenuAdmPartidos();break;}
                       }
                    cout<<"\n\n";
                    system("PAUSE");
               }while(option != 0);
              break;}

      case 3:{/*c. Procesar reportes:*/option=9;
              AlertaGoles(listaEquipo);
              do{
                       MenuProcesarPeportes();
                       scanf("%d", &option);
                       fflush(stdin);
                       switch (option)
                      {case 1:{/*ListarGoleadores*/mostrarEncabezadoMenu();crear(listaEquipo);break;}
                       case 2:{/*OrdEquiposPorGrupos*/mostrarEncabezadoMenu();posiciones(listaEquipo);golesDeGrupos(listaGrupo);  break;}
                       case 3:{/*ListarResultadosYPendientes*/mostrarEncabezadoMenu();fixture(listaPartidos,listaEquipo,listaPartidosTerminados);break;}
                       case 4:{/*GrupoDeLaMuerte*/mostrarEncabezadoMenu(); Grupo* gru =reportarGrupoMuerte(listaGrupo);
                       cout<<getNombreGrupo(*(reportarGrupoMuerte(listaGrupo)))<<endl<<endl
                           <<getNombreEquipo(*getEquipo1(*gru))<<endl
                           <<getNombreEquipo(*getEquipo2(*gru))<<endl
                           <<getNombreEquipo(*getEquipo3(*gru))<<endl
                           <<getNombreEquipo(*getEquipo4(*gru));    break;}
                       case 5:{/*PorcentajeGolesVL*/mostrarEncabezadoMenu();calcularPorcentaje(listaPartidosTerminados);break;}
                       case 0:{/*vuelve a menu principal*/break;}
                       default:{mensajeDeErrorMenuProcesarReportes();break;}
                       }
                    cout<<"\n\n";
                    system("PAUSE");
                   }while(option != 0);
              break;}

      case 4:{/*d. Salir de la aplicación */

              if(! listaVacia(listaEjecucion))
              {
                  cout<<"Hay partidos en ejecucion"<<endl;
                  terminarPartidos(listaEjecucion,listaEquipo,listaPartidosTerminados);
                  system("PAUSE");
              }
              else
              {
                  MenuFIN();


                  cin>>respuesta;

                  if(respuesta=='s')
                  {

                  guardarArchivos(listaEquipo);
                  guardarGrupos(listaGrupo);
                  guardarPartidos(listaPartidos,listaPartidosTerminados);
                  //guardarPartidosTerminados(listaPartidosTerminados);
                  }

                  MenuSalir();
              }
               break;}

      default:{mensajeDeErrorMenuPrincipal(); break;}
    }
}while(option != 4);

    cout<<"\n\n";

    system("PAUSE");

    return 0;
}


/******************************************************************************/

/***funciones de menu****/
void mostrarEncabezadoMenu(void)
{
system("cls");
printf("\n*********** UNIVERSIDAD NACIONAL DE LANUS     ");
cout<<"**********************************\n";
printf("*********** Algoritmos y Estructuras de Datos ");
cout<<"**********************************\n";
printf("*********** Tp Mundial Brasil 2014            ");
cout<<"**********************************\n\n";
}

void MenuPrincipal(void)
    {
        mostrarEncabezadoMenu();
        printf("Que operacion desea realizar?\n\n");
        printf("1. Administrar equipos, jugadores, grupos y partidos \n");
        printf("2. Administrar Partidos \n");
        printf("3. Procesar reportes \n");
        printf("4. Salir\n\n");
        printf("Ingrese numero de operacion: ");

    }

void MenuABMtxt(void)
{
        mostrarEncabezadoMenu();
        printf("Elija el archivo .txt a procesar\n\n");
        printf("1. equipos.txt \n");
        printf("2. jugadores.txt \n");
        printf("3. grupos.txt \n");
        printf("4. partidos.txt \n");
        printf("0. para volver a menu principal \n\n");
        printf("Ingrese numero de operacion: ");

}
void MenuAdmPartidos(void)
{
        printf("\n Administrar Partidos: \n\n");
        printf("1. Registrar el inicio de un partido  \n");
        printf("2. Registrar los goles ocurridos en cada partido  \n");
        printf("3. Registrar el fin de un partido \n");
        printf("0. para volver a menu principal \n\n");
        printf("Ingrese numero de operacion: ");

}

void MenuProcesarPeportes(void)
{
        mostrarEncabezadoMenu();
        printf("Procesar Reportes: \n\n");
        printf("1. Listado de goleadores.  \n");
        printf("2. Orden de equipos por grupo  \n");
        printf("3. Listado de resultados y partidos pendientes(fixture)\n");
        printf("4. Mostrar el grupo de la muerte \n");
        printf("5. Porcentaje goles local o visitante. \n");
        printf("0. para volver a menu principal \n\n");
        printf("Ingrese numero de operacion: ");

}

void MenuSalir(void)
{
    mostrarEncabezadoMenu();

    banderaArgentina();

    printf("\n Algoritmos y Estructura de Datos.\n\n");
    printf(" Docentes: Ing. Diego Azcurra y Ing. Damian Santos.\n\n");
    printf(" Alumnos: Aguirre Rodrigo, Lastra Ezequiel\n ");
    printf("\t Pizarro Maximiliano, Mouzo Leandro.\n\n");
    printf(" UNLA, 2014.\n\n");


}

void MenuFIN(void)
{
     mostrarEncabezadoMenu();
     printf("Desea Guardar y Salir?");
     printf("\ns/n:  ");
}

void mostrarEncabezadoEquipo(void)
{
    system("cls");
    cout<<"\n\t  ********** Equipos************"<<endl;
    cout<<"\n -------------------------------------------------------"<<endl;
    cout<<"\n| Id"<<" | "<<"Nombre"<<" | "<<"Puntos"<<" | ";
    cout<<"Goles a Favor"<<" | "<<"Goles en contra |"<<"\n"<<endl;
    cout<<" -------------------------------------------------------\n"<<endl;
}

void mostrarEncabezadoJugador(void)
{
     cout<<"\n\t********** Jugadores************";
     cout<<"\n\tId|"<<" "<<"Nombre|"<<" "<<"Goles|"<<" ";
     cout<<"Id Equipo que Pertenece|"<<"\n\t"<<endl;
}
void mostrarEncabezadoGrupos(void)
{
    system("cls");
    cout<<"\n\t  ********** GRUPOS************"<<endl;
    cout<<"\n -------------------------------------------------------"<<endl;
    cout<<"\nId\t"<<"| Nombre"<<" | "<<"Equipo 1"<<" | "<<"Equipo 2"<<" | ";
    cout<<"Equipo 3"<<" | "<<"Equipo 4 |"<<"\n"<<endl;
    cout<<" -------------------------------------------------------\n"<<endl;
}

void mostrarEncabezadoPartidos(void)
{
    cout<<"\n\t  ********** Partidos************"<<endl;
    cout<<"\n -------------------------------------------------------"<<endl;
    cout<<"\n idPartido "<<"|idEquipoL"<<" | "<<"idEquipoV"<<" | "<<"golesL"<<" | ";
    cout<<"golesV"<<" | "<<"\n"<<endl;
    cout<<" -------------------------------------------------------\n"<<endl;

}
void MenuABM(void)
{
     cout<<"\n -------------------------------------------------------"<<endl;
     cout<<"\n Que operacion desea realizar? \n"<<endl;
     printf("1. Alta  \n");
     printf("2. Modificacion  \n");
     printf("3. Baja \n");
     printf("0. para volver a menu principal \n\n");
     printf("Ingrese numero de operacion: ");

}

void menuMODjugador(void){

          cout << "\nQue dato desea modificar?" << endl << endl;
          cout << "1. Nombre del jugador" << endl;
          cout << "2. Cantidad de goles" << endl;
          cout << "3. Id del equipo al que pertenece " << endl;

          cout << "Su eleccion: ";
}
/******************************************************************************/

/*Mensajes de error*/
void mensajeDeErrorMenuPrincipal(void)
{
 mostrarEncabezadoMenu();
 printf("\nError, las opciones validas son 1, 2, 3 o 4. \n\n");
 PIP();
 system("PAUSE");
 MenuPrincipal();

}

void mensajeDeErrorMenuABMtxt(void)
{
 mostrarEncabezadoMenu();
 printf("\nError, las opciones validas son 1, 2, 3, 4 o 0. \n\n");
 PIP();
 system("PAUSE");
 MenuABMtxt();

}

void mensajeDeErrorMenuAdmPartidos(void)
{
 mostrarEncabezadoMenu();
 printf("\nError, las opciones validas son 1, 2, 3 o 0. \n\n");
 PIP();
 system("PAUSE");
 MenuAdmPartidos();
}

void mensajeDeErrorMenuProcesarReportes(void)
{
 mostrarEncabezadoMenu();
 printf("\nError, las opciones validas son 1, 2, 3, 4, 5 o 0. \n\n");
 PIP();
 system("PAUSE");
 MenuProcesarPeportes();

}

void mensajeDeErrorMenuABM(void)
{
 mostrarEncabezadoMenu();
 printf("\nError, las opciones validas son 1, 2, 3 o 0 \n\n");
 PIP();
 system("PAUSE");
 MenuABM();
}
/******************************************************************************/
char numeroAcaracter(int n)
{
     switch (n)
     {case 0:return 'A';
      case 1:return 'B';
      case 2:return 'C';
      case 3:return 'D';
      case 4:return 'E';
      case 5:return 'F';
      case 6:return 'G';
      case 7:return 'H';
      }
}
void PIP(void)
{
printf("%c", '\x07');
}

void banderaArgentina(void)
{
 PIP();
 cout<<"\n\t\t\t\t\tVamos Argentina!!!\n\n";
 renglonAzul();
 renglonAzul();
 renglonAzul();
 renglonBlanco();
 renglonBlanco();
 renglonBlanco();
 renglonAzul();
 renglonAzul();
 renglonAzul();

 color(47);
 cout<<"\n";

}

void renglonAzul(void)
{
     color(2); //verde

     for(int ren=1;ren<=30;ren++)
     {
     printf("%c",219);
     }

     color(1); //azul
     for(int ren=1;ren<=40;ren++)
     {
     printf("%c",178);
     }
     printf("%c\n",178);

}

void renglonBlanco(void)
{
     color(2);

     for(int ren=1;ren<=30;ren++)
     {
     printf("%c",219);
     }

     color(47); //blanco
     for(int ren=1;ren<=40;ren++)
     {
     printf("%c",178);
     }
     printf("%c\n",178);

}

void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

