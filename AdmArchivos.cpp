#include <cstdlib>
#include "AdmArchivos.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Jugador.h"
#include "Equipo.h"
#include "Partido.h"
#include "Grupo.h"
#include "Lista.h"


using namespace std;



int cadenaAentero(string dato)
{
    int num;
    stringstream ss(dato);
    ss >> num;
    return num;
}



//CARGA DE LOS PARTIDOS
void cargarPartidos(Lista &listaPartidos, Lista &listaPartidosTerminados){

    ifstream fpartidos;
    fpartidos.open("partidos.txt");
    Partido par;
    crearPartido(par);
    string dato;

    if (fpartidos.is_open()){
       while (fpartidos.good()){

            Partido* ptrPartido = new Partido;
            crearPartido(*ptrPartido);

            getline (fpartidos,dato,';');
            setIdPartido(par, cadenaAentero(dato));

            PtrNodoLista cursor = localizarDato(listaPartidos,&par);
            PtrNodoLista cursor2 = localizarDato(listaPartidosTerminados,&par);

            if((cursor == fin())&&(cursor2 == fin()))
            {
             setIdPartido(*ptrPartido, cadenaAentero(dato));

             getline (fpartidos,dato,';');
             setIdEquipoL(*ptrPartido,cadenaAentero( dato));

             getline (fpartidos,dato,';');
             setIdEquipoV(*ptrPartido,cadenaAentero( dato));

             getline (fpartidos,dato,';');
             setGolesL(*ptrPartido,cadenaAentero( dato));

             getline (fpartidos,dato);
             setGolesV(*ptrPartido,cadenaAentero(dato));

             if((getGolesL(*ptrPartido) > -1) or (getGolesV(*ptrPartido)> -1))
             {
                adicionarFinal(listaPartidosTerminados,ptrPartido);
                //cout<<"entro"<<endl;
             }
             else
             {
                adicionarFinal(listaPartidos,ptrPartido);
             }
            }
            else
            {   cout<<endl;
                cout<<"El partido con ID "<<getIdPartido(par)<<" ya esta cargado en memoria"<<endl;
                getline(fpartidos,dato);
            }

    }

            fpartidos.close();

    }

    else{
          cout << "Error al abrir el archivo." << endl << endl;
          system ("PAUSE");
    }

};



void cargarJugadores(Lista &listaJugador)
{
    ifstream fJugadores;
    fJugadores.open("Jugadores.txt");

    string dato;

    if (fJugadores.is_open())
    {
       while (fJugadores.good())
       {

            Jugador* ptrJugador = new Jugador;
            crearJugador(*ptrJugador);

            getline (fJugadores,dato,';');
            setIdJugador(*ptrJugador, cadenaAentero(dato));

            getline (fJugadores,dato,';');
            setNombreJugador(*ptrJugador,dato);

            getline (fJugadores,dato,';');
            setGoles(*ptrJugador, cadenaAentero(dato));

            getline (fJugadores,dato);
            setIdEquipoPertenece(*ptrJugador, cadenaAentero(dato));



            adicionarFinal(listaJugador,ptrJugador);
       }

            fJugadores.close();

    }

    else
    {
          cout << "Error al abrir el archivo Jugadores.txt." << endl << endl;
          system ("PAUSE");
    }

}

void cargarEquipo(Lista &listaEquipo)
{
    ifstream fEquipos;
    fEquipos.open("Equipos.txt");

    string dato;

    if (fEquipos.is_open())
    {
       while (fEquipos.good())
       {

            Equipo* ptrEquipo = new Equipo;
            crearEquipo(*ptrEquipo);

            getline (fEquipos,dato,';');
            setIdEquipo(*ptrEquipo, cadenaAentero(dato));

            getline (fEquipos,dato,';');
            setNombreEquipo(*ptrEquipo,dato);

            getline (fEquipos,dato,';');
            setPuntos(*ptrEquipo, cadenaAentero(dato));

            getline (fEquipos,dato,';');
            setGolesFavor(*ptrEquipo, cadenaAentero(dato));

            getline (fEquipos,dato);
            setGolesContra(*ptrEquipo, cadenaAentero(dato));



            adicionarFinal(listaEquipo,ptrEquipo);
        }

            fEquipos.close();

    }

    else
    {
          cout << "Error al abrir el archivo Equipos.txt." << endl << endl;
          system ("PAUSE");
    }

}

void cargarGrupo(Lista &listaGrupos, Lista &listaEquipo)
{
    Equipo equipoAux;
    crearEquipo(equipoAux);
    PtrNodoLista puntero;

    ifstream fGrupos;
    fGrupos.open("Grupos.txt");

    string dato;

    if (fGrupos.is_open())
    {
       while (fGrupos.good())
       {

            Grupo* ptrGrupo = new Grupo;
            crearGrupo(*ptrGrupo);

            getline (fGrupos,dato,';');
            setIdGrupo(*ptrGrupo,dato);

            getline (fGrupos,dato,';');
            setNombreGrupo(*ptrGrupo,dato);

            getline (fGrupos,dato,';');
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero =localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo1(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }

            getline (fGrupos,dato,';');
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero =localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo2(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }



            getline (fGrupos,dato,';');
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero =localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo3(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }


            getline (fGrupos,dato);
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero =localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo4(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }




            adicionarFinal(listaGrupos,ptrGrupo);
        }

            fGrupos.close();

    }

    else
    {
          cout << "Error al abrir el archivo Grupos.txt." << endl << endl;
          system ("PAUSE");
    }
}
/*
void cargarGrupo(Lista &listaGrupos, Lista &listaEquipo)
{
    Equipo equipoAux;
    crearEquipo(equipoAux);
    PtrNodoLista puntero;

    ifstream fGrupos;
    fGrupos.open("Grupos.txt");

    string dato;
    string linea;
    int aux = 0;

    if (fGrupos.is_open())
    {
       while (fGrupos.good())
       {

            Grupo* ptrGrupo = new Grupo;
            crearGrupo(*ptrGrupo);


            getline(fGrupos,linea);
            aux = linea.find(';');
            dato = linea.substr(0,aux);

            linea.erase(0,aux+1);

            //getline (fGrupos,dato,';');
            setIdGrupo(*ptrGrupo,dato);

            aux = linea.find(';');
            dato = linea.substr(0,aux);
            linea.erase(0,aux+1);
            //getline (fGrupos,dato,';');
            setNombreGrupo(*ptrGrupo,dato);


            aux = linea.find(';');
            dato = linea.substr(0,aux);
            linea.erase(0,aux+1);
            //getline (fGrupos,dato,';');
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero = localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo1(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }

            aux = linea.find(';');
            dato = linea.substr(0,aux);
            linea.erase(0,aux+1);
            //getline (fGrupos,dato,';');
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero =localizarDato(listaEquipo,&equipoAux);
            if(puntero != fin())
            {
              setEquipo2(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }

            aux = linea.find(';');
            dato = linea.substr(0,aux);

            linea.erase(0,aux+1);
            //getline (fGrupos,dato,';');
            //cout<<"dato: "<<dato<<endl;
            setIdEquipo(equipoAux,cadenaAentero(dato));
            puntero = localizarDato(listaEquipo,&equipoAux);
            //cout<<puntero<<endl;
            if(puntero != fin())
            {//cout<<"entro"<<endl;
              setEquipo3(*ptrGrupo,((Equipo*)puntero->ptrDato));
            }
            else
            {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
            }

            if(aux>-1)
            {

              dato = linea.substr(0,aux);
              linea.erase(0,aux+1);


              //getline (fGrupos,dato);
              setIdEquipo(equipoAux,cadenaAentero(dato));
              puntero =localizarDato(listaEquipo,&equipoAux);

              if(puntero != fin())
              {
                setEquipo4(*ptrGrupo,((Equipo*)puntero->ptrDato));
              }
              else
              {
                cout<<"no se encuentra el equipo con id "<<dato<<endl;
              }
            }

            adicionarFinal(listaGrupos,ptrGrupo);
        }

            fGrupos.close();


    }

    else
    {
          cout << "Error al abrir el archivo Grupos.txt." << endl << endl;
          system ("PAUSE");
    }
}

*/
void cargaArchivos(Lista &listaEquipo,Lista &listaPartidos,Lista &listaGrupo,Lista &listaPartidosTerminados)
{

    cargarEquipo(listaEquipo);
    Equipo equipoAux;
    crearEquipo(equipoAux);
    PtrNodoLista ptrCursor;

    ifstream fJugadores;
    fJugadores.open("Jugadores.txt");

    string dato;

    if (fJugadores.is_open())
    {
       while (fJugadores.good())
       {

            Jugador* ptrJugador = new Jugador;
            crearJugador(*ptrJugador);

            getline (fJugadores,dato,';');
            setIdJugador(*ptrJugador, cadenaAentero(dato));

            getline (fJugadores,dato,';');
            setNombreJugador(*ptrJugador,dato);

            getline (fJugadores,dato,';');
            setGoles(*ptrJugador, cadenaAentero(dato));

            getline (fJugadores,dato);
            setIdEquipoPertenece(*ptrJugador, cadenaAentero(dato));


            setIdEquipo(equipoAux,cadenaAentero(dato));

            ptrCursor=localizarDato(listaEquipo,&equipoAux);
            if(ptrCursor != fin())
            {

                PtrDato puntero = getListaJugadores(*((Equipo*)ptrCursor->ptrDato));
                adicionarFinal(*((Lista*)puntero),ptrJugador);

            }
            else
            {
                int opcion = 0;
                cout<<"el jugador "<<getNombreJugador(*ptrJugador)<<" con ID "<<getIdJugador(*ptrJugador)<< " no pertenece a ningun equipo registrado"<<endl;

            }
       }

            fJugadores.close();

    }

    cargarGrupo(listaGrupo,listaEquipo);
    cargarPartidos(listaPartidos,listaPartidosTerminados);

}
/**********************************************************************************/
void guardarPartidos(Lista &listaPartidos, Lista &listaPartidosTerminados)
{
     string fPartido ("Partidos.txt");
     ofstream f_listaPartido(fPartido.c_str());


     PtrNodoLista cursor = primero(listaPartidos);
     while(cursor!=fin())
     {
        PtrNodoLista cursor2=siguiente(listaPartidos,cursor);
        if(cursor2 ==fin()){
           f_listaPartido<<getIdPartido(*((Partido*)cursor->ptrDato))<<";"<<getIdEquipoL(*((Partido*)cursor->ptrDato))<<";"<<getIdEquipoV(*((Partido*)cursor->ptrDato))<<";"<<getGolesL(*((Partido*)cursor->ptrDato))<<";"<<getGolesV(*((Partido*)cursor->ptrDato));
           cursor = siguiente(listaPartidos,cursor);

        }else{
              f_listaPartido<<getIdPartido(*((Partido*)cursor->ptrDato))<<";"<<getIdEquipoL(*((Partido*)cursor->ptrDato))<<";"<<getIdEquipoV(*((Partido*)cursor->ptrDato))<<";"<<getGolesL(*((Partido*)cursor->ptrDato))<<";"<<getGolesV(*((Partido*)cursor->ptrDato))<<"\n";
              cursor = siguiente(listaPartidos,cursor);
              }
     }
     f_listaPartido<<"\n";
     PtrNodoLista cursor3 = primero(listaPartidosTerminados);
     while(cursor3!=fin())
     {
        PtrNodoLista cursor4=siguiente(listaPartidosTerminados,cursor3);
        if(cursor4 ==fin()){
           f_listaPartido<<getIdPartido(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoL(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoV(*((Partido*)cursor3->ptrDato))<<";"<<getGolesL(*((Partido*)cursor3->ptrDato))<<";"<<getGolesV(*((Partido*)cursor3->ptrDato));
           cursor3 = siguiente(listaPartidosTerminados,cursor3);

        }else{
              f_listaPartido<<getIdPartido(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoL(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoV(*((Partido*)cursor3->ptrDato))<<";"<<getGolesL(*((Partido*)cursor3->ptrDato))<<";"<<getGolesV(*((Partido*)cursor3->ptrDato))<<"\n";
              cursor3 = siguiente(listaPartidosTerminados,cursor3);
              }
     }


      f_listaPartido.close();
}
/*---------------------------------------------------------------------------------*/
/*void guardarPartidosTerminados(Lista &listaPartidosTerminados)
{
     string fPartido ("Partidos.txt");
     ofstream f_listaPartido(fPartido.c_str());


     PtrNodoLista cursor3 = primero(listaPartidosTerminados);
     while(cursor3!=fin())
     {
        PtrNodoLista cursor4=siguiente(listaPartidosTerminados,cursor3);
        if(cursor4 ==fin()){
           f_listaPartido<<getIdPartido(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoL(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoV(*((Partido*)cursor3->ptrDato))<<";"<<getGolesL(*((Partido*)cursor3->ptrDato))<<";"<<getGolesV(*((Partido*)cursor3->ptrDato));
           cursor3 = siguiente(listaPartidosTerminados,cursor3);

        }else{
              f_listaPartido<<getIdPartido(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoL(*((Partido*)cursor3->ptrDato))<<";"<<getIdEquipoV(*((Partido*)cursor3->ptrDato))<<";"<<getGolesL(*((Partido*)cursor3->ptrDato))<<";"<<getGolesV(*((Partido*)cursor3->ptrDato))<<"\n";
              cursor3 = siguiente(listaPartidosTerminados,cursor3);
              }
     }
      f_listaPartido.close();
}
*/
/*********************************************************************************/
void guardarGrupos(Lista &listaGrupos)
{
     string fGrupo ("Grupos.txt");
     ofstream f_listaGrupo(fGrupo.c_str());

     PtrNodoLista cursor = primero(listaGrupos);
     while(cursor!=fin())
     {
        PtrNodoLista cursor2=siguiente(listaGrupos,cursor);
        if(cursor2 ==fin()){
               f_listaGrupo<<getIdGrupo(*((Grupo*)cursor->ptrDato))<<";"<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<";"<<getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))<<";"<<getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))<<";"<<getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))<<";"<<getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))));
            cursor = siguiente(listaGrupos,cursor);
             }else{
                   f_listaGrupo<<getIdGrupo(*((Grupo*)cursor->ptrDato))<<";"<<getNombreGrupo(*((Grupo*)cursor->ptrDato))<<";"<<getIdEquipo(*(getEquipo1(*((Grupo*)cursor->ptrDato))))<<";"<<getIdEquipo(*(getEquipo2(*((Grupo*)cursor->ptrDato))))<<";"<<getIdEquipo(*(getEquipo3(*((Grupo*)cursor->ptrDato))))<<";"<<getIdEquipo(*(getEquipo4(*((Grupo*)cursor->ptrDato))))<<"\n";
                     cursor = siguiente(listaGrupos,cursor);
                   }
     }

      f_listaGrupo.close();
}

/*********************************************************************************/
void guardarArchivos(Lista &listaEquipo)
{
     string fEquipo ("Equipos.txt");
     string fJugador ("Jugadores.txt");

     ofstream f_listaEquipo(fEquipo.c_str());
     ofstream f_listaJugador(fJugador.c_str());
     bool cont=true;

     PtrNodoLista cursor = primero(listaEquipo);
     while(cursor!=fin())
     {
           PtrNodoLista cursor3=siguiente(listaEquipo,cursor);

           if(cursor3 ==fin()){
           f_listaEquipo<<getIdEquipo(*((Equipo*)cursor->ptrDato)) <<";"<<getNombreEquipo(*((Equipo*)cursor->ptrDato))<<";"<<getPuntos(*((Equipo*)cursor->ptrDato))<<";"<<getGolesFavor(*((Equipo*)cursor->ptrDato))<<";"<<getGolesContra(*((Equipo*)cursor->ptrDato));
          // cursor = siguiente(listaEquipo,cursor);
           }else{
                 f_listaEquipo<<getIdEquipo(*((Equipo*)cursor->ptrDato)) <<";"<<getNombreEquipo(*((Equipo*)cursor->ptrDato))<<";"<<getPuntos(*((Equipo*)cursor->ptrDato))<<";"<<getGolesFavor(*((Equipo*)cursor->ptrDato))<<";"<<getGolesContra(*((Equipo*)cursor->ptrDato))<<"\n";
           //      cursor = siguiente(listaEquipo,cursor);
                 }

           PtrDato puntero = getListaJugadores(*((Equipo*)cursor->ptrDato));
           Lista auxLista = *((Lista*)puntero);
           PtrNodoLista cursor2 = primero(auxLista);





           while(cursor2 !=fin())
           {

              // PtrNodoLista cursor4=siguiente(auxLista,cursor2);
               if(cursor2==primero(auxLista) && cont==true){

                  f_listaJugador<<getIdJugador(*((Jugador*)cursor2->ptrDato))<<";"<<getNombreJugador(*((Jugador*)cursor2->ptrDato))<<";"<<getGoles(*((Jugador*)cursor2->ptrDato))<<";"<<getIdEquipoPertenece(*((Jugador*)cursor2->ptrDato));
                  cursor2 = siguiente(auxLista,cursor2);
                  }else{
                      f_listaJugador<<"\n"<<getIdJugador(*((Jugador*)cursor2->ptrDato))<<";"<<getNombreJugador(*((Jugador*)cursor2->ptrDato))<<";"<<getGoles(*((Jugador*)cursor2->ptrDato))<<";"<<getIdEquipoPertenece(*((Jugador*)cursor2->ptrDato));
                      cursor2 =siguiente(auxLista,cursor2);
                       }



           }
           cursor =siguiente(listaEquipo,cursor);
           cont=false;

     }


     f_listaEquipo.close();
     f_listaJugador.close();

}
/*
//ABM de las listas EQUIPOS JUGADORES Y PARTIDOS


//ABM DE JUGADORES
void agregarJugador(Lista &listaEquipos){

     Jugador* ptrJugador = new Jugador;
     crearJugador(*ptrJugador);
     int id = 1;
     char dato[50];
     char dato2;
     if (!listaVacia(Jugadores)){
        id = (getIdJugador(*((Jugador*)(ultimo(Jugadores)->ptrDato))))+1;
     }
     cout << "Id: " << id << endl;
     setIdJugador(*ptrJugador,id);
     //cin.ignore();

     cout << "Ingrese Nombre del jugador: " ;
     cin.getline(dato, 50);
     setNombreJugador(*ptrJugador,dato);
     //cin.ignore();

     cout << "Ingrese sus goles: " ;
     cin.getline(dato, 50);
     setGoles(*ptrJugador, cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese el id del equipo al cual pertenece : " ;
     cin.getline(dato, 50);
     setIdEquipoPertenece(*ptrJugador, cadenaAentero(dato));
     //cin.ignore();
     Equipo aux;       //esto lo puso EZE
     crearEquipo(aux);
     setIdEquipo(cadenaAentero(dato));
     PtrNodoLista cursor =localizarDato(listaEquipo,&aux);

     adicionarFinal(*((Lista*)getListaJugadores(cursor)), ptrJugador);

};

void eliminarJugador(Lista &Jugadores){

     cout << "Ingrese el Id del jugador a Eliminar: " ;
     int Id_Jugador;
     cin >> Id_Jugador;
     Jugador* ptrJugador = localizarJugadorPorId(Jugadores, Id_Jugador);

     if (ptrJugador == NULL){
          cout << "No existe el jugador seleccionado." << endl;
         // system("PAUSE");
     }
     else{
          Jugador aux;
          crearJugador(aux);
          setIdJugador(aux, Id_Jugador);

          PtrNodoLista nodo = localizarDato(Jugadores, &aux);

          eliminarNodo(Jugadores,nodo);
          cout << "Se dio de baja el jugador Correctamente\n";
          //system ("PAUSE");
     }
};


void modificarJugador(Lista &Jugadores){

     cout << "Ingrese el Id del jugador a modificar: " ;
     int Id_Jugador;
     cin >> Id_Jugador;
     Jugador* ptrJugador = localizarJugadorPorId(Jugadores, Id_Jugador);

     if (ptrJugador == NULL){
          cout << "No existe el Usuario seleccionado." << endl;
          system ("PAUSE");
     }
     else{
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
                       setNombreJugador(*ptrJugador,dato);
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese cantidad de goles: " ;
                       cin.getline(dato, 50);
                       setGoles(*ptrJugador, cadenaAentero(dato));
                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo al que pertenece: " ;
                       cin.getline(dato, 50);
                       setIdEquipoPertenece(*ptrJugador, cadenaAentero(dato));
                       break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
          }
     }
};


//ABM DE EQUIPOS
void agregarEquipo(Lista &Equipos){

     Equipo* ptrEquipo = new Equipo;
     crearEquipo(*ptrEquipo);
     int id = 1;
     char dato[50];
     char dato2;
     if (!listaVacia(Equipos)){
        id = (getIdEquipo(*((Equipo*)(ultimo(Equipos)->ptrDato))))+1;
     }
     cout << "Id: " << id << endl;
     setIdEquipo(*ptrEquipo,id);
     //cin.ignore();

     cout << "Ingrese Nombre Equipo: " ;
     cin.getline(dato, 50);
     setNombreEquipo(*ptrEquipo,dato);
     //cin.ignore();

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

void eliminarEquipo(Lista &Equipos){

     cout << "Ingrese el Id del Equipo a Eliminar: " ;
     int Id_Equipo;
     cin >> Id_Equipo;
     Equipo* ptrEquipo = localizarEquipoPorId(Equipos, Id_Equipo);

     if (ptrEquipo == NULL){
          cout << "No existe el equipo seleccionado." << endl;
         // system("PAUSE");
     }
     else{
          Equipo aux;
          crearEquipo(aux);
          setIdEquipo(aux, Id_Equipo);

          PtrNodoLista nodo = localizarDato(Equipos, &aux);

          eliminarNodo(Equipos,nodo);
          cout << "Se dio de baja el equipo Correctamente\n";
          //system ("PAUSE");
     }
};

void modificarEquipo(Lista &Equipos){

     cout << "Ingrese el Id del equipo a modificar: " ;
     int Id_Equipo;
     cin >> Id_Equipo;
     Equipo* ptrEquipo = localizarEquipoPorId(Equipos, Id_Equipo);

     if (ptrEquipo == NULL){
          cout << "No existe el Usuario seleccionado." << endl;
          system ("PAUSE");
     }
     else{
          int seleccion;

          cout << "Que dato desea modificar?" << endl << endl;
          cout << "1. Nombre del equipo" << endl;
          cout << "2. Cnatidad de puntos" << endl;
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
                       setNombreEquipo(*ptrEquipo,dato);
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese cantidad de puntos: " ;
                       cin.getline(dato, 50);
                       setPuntos(*ptrEquipo, cadenaAentero(dato));
                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese goles a favor: " ;
                       cin.getline(dato, 50);
                       setGolesFavor(*ptrEquipo, cadenaAentero(dato));
                       break;
               case 4: system("cls");
                       cout << "Ingrese goles recibidos: " ;
                       cin >> dato;
                       setGolesContra(*ptrEquipo, cadenaAentero(dato));
                       break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
          }
     }
};

//ABM DE PARTIDOS
void agregarPartido(Lista &Partidos){

     Partido* ptrPartido = new Partido;
     crearPartido(*ptrPartido);
     int id = 1;
     char dato[50];
     char dato2;
     if (!listaVacia(Partidos)){
        id = (getIdPartido(*((Partido*)(ultimo(Partidos)->ptrDato))))+1;
     }
     cout << "Id: " << id << endl;
     setIdPartido(*ptrPartido,id);
     //cin.ignore();

     cout << "Ingrese id del equipo local: " ;
     cin.getline(dato, 50);
     setIdEquipoL(*ptrPartido,cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese id del equipo visitante: " ;
     cin.getline(dato, 50);
     setIdEquipoV(*ptrPartido, cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese el goles del equipo local : " ;
     cin.getline(dato, 50);
     setGolesL(*ptrPartido, cadenaAentero(dato));
     //cin.ignore();

     cout << "Ingrese el goles del equipo visitante : " ;
     cin.getline(dato, 50);
     setGolesV(*ptrPartido, cadenaAentero(dato));
     //cin.ignore();

     adicionarFinal(Partidos, ptrPartido);

};

void eliminarPartido(Lista &Partidos){

     cout << "Ingrese el Id del partido a Eliminar: " ;
     int Id_Partido;
     cin >> Id_Partido;
     Partido* ptrPartido = localizarPartidoPorId(Partidos, Id_Partido);

     if (ptrPartido == NULL){
          cout << "No existe el partido seleccionado." << endl;
         // system("PAUSE");
     }
     else{
          Partido aux;
          crearPartido(aux);
          setIdPartido(aux, Id_Partido);

          PtrNodoLista nodo = localizarDato(Partidos, &aux);

          eliminarNodo(Partidos,nodo);
          cout << "Se dio de baja el partido Correctamente\n";
          //system ("PAUSE");
     }
};

void modificarPartido(Lista &Partidos){

     cout << "Ingrese el Id del partido a modificar: " ;
     int Id_Partido;
     cin >> Id_Partido;
     Partido* ptrPartido = localizarPartidoPorId(Partidos, Id_Partido);

     if (ptrPartido == NULL){
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
                       setIdEquipoL(*ptrPartido,cadenaAentero(dato));
                       break;
               case 2: system("cls");
                       cin.ignore();
                       cout << "Ingrese id del equipo visitante: " ;
                       cin.getline(dato, 50);
                       setIdEquipoV(*ptrPartido, cadenaAentero(dato));
                       break;
               case 3: system("cls");
                       cin.ignore();
                       cout << "Ingrese goles equipo local: " ;
                       cin.getline(dato, 50);
                       setGolesL(*ptrPartido, cadenaAentero(dato));
                       break;
               case 4: system("cls");
                       cout << "Ingrese goles equipo visitante: " ;
                       cin >> dato;
                       setGolesV(*ptrPartido, cadenaAentero(dato));
                       break;
               default: cout << "Opcion invalida" << endl;
                        system ("PAUSE");
                        break;
          }
     }
};

*/




