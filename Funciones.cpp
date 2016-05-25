#include "Lista.h"
#include "Equipo.h"
#include "Jugador.h"
#include <iostream>

using namespace std;


void guardarLista(Lista &listaEquipo)
{
int id;
char* nom;
int puntos;
int gf;
int gc;

char* Varide;
char* Varpuntos;
char* Vargf;
char* Vargc;

FILE *archivo;
char b;
char * pch;
char buffer [5][30];
int cont=0,i=0,control=0;
int vec[20];
char nombreArchivo[30];
    
    
    
     if( (archivo = fopen("H:\\Equipos,txt", "a")) == NULL )
     {
       printf("ERROR. No se pudo abrir el archivo \n");
     }
    else
    {
         PtrNodoLista cursor = primero(listaEquipo);
        
      while (cursor !=fin())
    {
    
     int Id= getIdEquipo(*((Equipo*)cursor->ptrDato));
     char* Nombre= getNombreEquipo(*((Equipo*)cursor->ptrDato));
     int Puntos= getPuntos(*((Equipo*)cursor->ptrDato));
     int Gfavor= getGolesFavor(*((Equipo*)cursor->ptrDato));
     int Gcontra= getGolesContra(*((Equipo*)cursor->ptrDato));
     
      cursor=siguiente(listaEquipo ,cursor);
     
     
      itoa (id, Varide, 10);
      itoa (Puntos, Varpuntos, 10);
      itoa (Gfavor, Vargf, 10);
      itoa (Gcontra, Vargc, 10);
      fprintf(archivo,"%s;%s;%s;%s;%s\n",Varide,Nombre,Varpuntos,Vargf,Vargc);
      
     
     
     
     }
         
          
      } 
       
}   



//======================================================================================

void recorrerListaEquipo (Lista &lista)

{
PtrNodoLista cursor;
cursor=primero(lista);
while (cursor !=fin())
{
    
    int Id= getIdEquipo(*((Equipo*)cursor->ptrDato));
      cout<<Id<<"\t";    
     char* Nombre= getNombreEquipo(*((Equipo*)cursor->ptrDato));
      cout<<Nombre<<"\t\t";
     int Puntos= getPuntos(*((Equipo*)cursor->ptrDato));
      cout<<Puntos<<"\t"; 
      int Gfavor= getGolesFavor(*((Equipo*)cursor->ptrDato));
      cout<<Gfavor<<"\t";
      int Gcontra= getGolesContra(*((Equipo*)cursor->ptrDato));
      cout<<Gcontra<<endl;
cursor=siguiente(lista ,cursor);
}}

//==================================================================================
void recorrerListaJugador(Lista &lista)
{
PtrNodoLista cursor;
cursor=primero(lista);
while (cursor !=fin())
{
    
    int Id= getIdJugador(*((Jugador*)cursor->ptrDato));
      cout<<Id<<"\t";    
     char* Nombre= getNombreJugador(*((Jugador*)cursor->ptrDato));
      cout<<Nombre<<"\t\t";
     char * fecha= getFechaNacimiento(*((Jugador*)cursor->ptrDato));
      cout<<fecha<<"\t"; 
      int Goles= getGoles(*((Jugador*)cursor->ptrDato));
      cout<<Goles<<"\t";
      int IdEquipo= getIdEquipoPertenece(*((Jugador*)cursor->ptrDato));
      cout<<IdEquipo<<endl;
cursor=siguiente(lista ,cursor);
}}


//==================================================================================

void intercambiar (PtrDato &x,PtrDato &y)
{
     
PtrDato aux;

aux = x;
x = y;
y = aux;
}

//=================================================================================
void ordenacion(PtrDato vector[], int n)
{
char* nombre;
int puntos;
int i,j;
for( i=0; i < n; i++ )
{
     for( j= 0; j < n-1; j++)
     {
       if((compararPuntos(vector[j],vector[j+1])) == MENOR) 
         {
          intercambiar( vector[j], vector[j+1] );
        
         
         }
     }
 

}
   for(int u=0;u<n;u++)
     {
     nombre = getNombreEquipo(*((Equipo*)vector[u]));
     puntos = getPuntos(*((Equipo*)vector[u]));     
     cout<<nombre<<"\t\t"<<puntos<<endl;
      
     }
     

}
//=================================================================================

void mostrarTabla(Lista &listaEquipo)
{
     
     int k = 0, n = longitud(listaEquipo);
     PtrDato vector[n];
     
     PtrNodoLista puntero = primero(listaEquipo);
    
     while(puntero != fin())
     {
     vector[k] = puntero->ptrDato;
    
     k++;
     puntero = siguiente(listaEquipo,puntero);
     }
     
     ordenacion(vector,n);
     
     
}
//=====================================================================================

void mostrarEquipo(Lista &listaEquipo, Lista &listaJugador)
{
     int idEquipo, id, puntos, golesFavor, golesContra;
     int idJugador, goles;
     char* nombre;
     char* nombreJugador;
     char* fecha;
     bool encontrado = false, jugadores = false;
     PtrNodoLista cursor = primero(listaEquipo);
     
     cout << "Ingrese el ID del equipo a buscar: ";
     cin >> idEquipo;
     
     while(cursor != fin() && ! encontrado)
     {
     if(compararIdEquipo(((Equipo*)cursor->ptrDato),idEquipo) == IGUAL)
     {
     id = getIdEquipo(*((Equipo*)cursor->ptrDato));
     nombre = getNombreEquipo(*((Equipo*)cursor->ptrDato));
     puntos = getPuntos(*((Equipo*)cursor->ptrDato));
     golesFavor = getGolesFavor(*((Equipo*)cursor->ptrDato));
     golesContra  = getGolesContra(*((Equipo*)cursor->ptrDato));
     encontrado = true;
     }
     cursor = siguiente(listaEquipo,cursor);
     }
     if(encontrado)
     {
     cout << id << "\t" << nombre << "\t" << puntos << "\t" << golesFavor << "\t" << golesContra << endl;
     
     cursor = primero(listaJugador);
     
     while(cursor != fin())
     {
     if(compararIdEquipoPertenece(((Jugador*)cursor->ptrDato), idEquipo) == IGUAL)
     {
     jugadores = true;
     idJugador = getIdJugador(*((Jugador*)cursor->ptrDato));
     nombreJugador = getNombreJugador(*((Jugador*)cursor->ptrDato));
     fecha = getFechaNacimiento(*((Jugador*)cursor->ptrDato));
     goles = getGoles(*((Jugador*)cursor->ptrDato));
     
     cout << idJugador << "\t" <<nombreJugador << "\t" << fecha << "\t" << goles << "\t" << idEquipo << endl;
     }
     cursor = siguiente(listaJugador,cursor);
     }
     if(! jugadores)
     {
          cout << "No tiene jugadores.";
     }
     }
     else
     {
     cout << "El equipo no existe." << endl;
     }
     }
     
//===========================================================================================================
    void mostrarJugador(Lista &listaJugador)
    {
         
     int idJugador, idEquipoPertene, goles;
     int idEquipoPertenece;
     char* nombreJugador;
     char* fecha;
     bool encontrado = false, jugadores = false;
     PtrNodoLista cursor = primero(listaJugador);
     
     cout << "Ingrese el ID del jugador a buscar: ";
     cin >> idJugador;
     
     while(cursor != fin() && ! encontrado)
     {
     if(compararIdJugador(((Jugador*)cursor->ptrDato),idJugador) == IGUAL)
     {
     idEquipoPertenece = getIdEquipoPertenece(*((Jugador*)cursor->ptrDato));
     nombreJugador = getNombreJugador(*((Jugador*)cursor->ptrDato));
     fecha = getFechaNacimiento(*((Jugador*)cursor->ptrDato));
     goles = getGoles(*((Jugador*)cursor->ptrDato));
     
     encontrado = true;
     }
     cursor = siguiente(listaJugador,cursor);
     }
     if(encontrado)
     {
     cout << idJugador << "\t" <<nombreJugador << "\t" << fecha << "\t" << goles << "\t" << idEquipoPertenece << endl;
     }
          

}

//=============================================================================================================
void cargarEquipo(Lista &listaEquipos, int id, char* nombre, int puntos, int golesFavor, int golesContra)
{
     Equipo equipo;
     PtrDato ptrdato = crearEquipo(equipo);
     setIdEquipo(*((Equipo*)ptrdato),id);
     setNombreEquipo( *((Equipo*)ptrdato),nombre);
     setPuntos(*((Equipo*)ptrdato),puntos);
     setGolesFavor(*((Equipo*)ptrdato),golesFavor);
     setGolesContra(*((Equipo*)ptrdato),golesContra);
     adicionarFinal(listaEquipos,ptrdato);
   

    
}
//=================================================================================================
void cargarJugador(Lista &listaJugador,int id,char *nombre,char *fecha,int goles,int idequipo)
{
     Jugador jugador;
     PtrDato ptrdato = crearJugador(jugador);
     setIdJugador(*((Jugador*)ptrdato),id);
     setNombreJugador( *((Jugador*)ptrdato),nombre);
     setFechaNacimiento(*((Jugador*)ptrdato),fecha);
     setGoles(*((Jugador*)ptrdato),goles);
     setIdEquipoPertenece(*((Jugador*)ptrdato),idequipo);
     adicionarFinal(listaJugador,ptrdato);
   

    
}
//=============================================================================================================
void actualizarGolesEquipos(Lista &listaEquipo,int idlocal,int idvisitante,int goleslocal,int golesvisitante)
 {
    
    // RECORRO LA LISTA BUSCANDO LA ID DEL EQUIPO LOCAL PARA SUMARLE LOS GOLES A FAVOR Y SUMAR LOS GOLES EN CONTRA 
    
    PtrNodoLista cursor = primero(listaEquipo);
    
      while(cursor != fin())
          {
         /*pregunto si es el id que estoy buscando*/
              if(compararIdEquipo((Equipo*)cursor->ptrDato,idlocal) == IGUAL)
              {
         /*guardo el total en un aux y despues lo guardo en el tda*/
          int golesFaux = getGolesFavor(*((Equipo*)cursor->ptrDato)) + goleslocal;
          setGolesFavor(*((Equipo*)cursor->ptrDato),golesFaux);
          
          int golesCaux = getGolesContra(*((Equipo*)cursor->ptrDato)) + golesvisitante;
          setGolesContra(*((Equipo*)cursor->ptrDato),golesCaux);
          
              }
          cursor = siguiente(listaEquipo,cursor);
          }
      
      
      //HAGO LO MISMO QUE ARRIBA PERO AHORA CON EL EQUIPO VISITANTE 
         
   cursor = primero(listaEquipo);  // ESTO LO HAGO PARA VOLVER AL PRINCIPIO DE LA LISTA
    
      while(cursor != fin())
          {
         /*pregunto si es el id que estoy buscando*/
              if(compararIdEquipo((Equipo*)cursor->ptrDato,idvisitante) == IGUAL)
              {
         /*guardo el total en un aux y despues lo guardo en el tda*/
          int golesFaux = getGolesFavor(*((Equipo*)cursor->ptrDato)) + golesvisitante;
          setGolesFavor(*((Equipo*)cursor->ptrDato),golesFaux);
          
          int golesCaux = getGolesContra(*((Equipo*)cursor->ptrDato)) + goleslocal;
          setGolesContra(*((Equipo*)cursor->ptrDato),golesCaux);
          
              }
          cursor = siguiente(listaEquipo,cursor);
          }
   
   
   
  
  
  
   // SECTOR DE LA FUNCUON QUE SE OCUPA DE LOS PUNTOS
   
     if (goleslocal > golesvisitante) //Gano local + 3
    {
        cursor = primero(listaEquipo);
       while(cursor != fin())
          {
         /*pregunto si es el id que estoy buscando*/
              if(compararIdEquipo((Equipo*)cursor->ptrDato,idlocal) == IGUAL)
              {
         /*guardo el total en un aux y despues lo guardo en el tda*/
          int puntosaux = getPuntos(*((Equipo*)cursor->ptrDato)) + 3;
          setPuntos(*((Equipo*)cursor->ptrDato),puntosaux);
              }
          }
    }    
    else//Gano visitante +3
      if(goleslocal < golesvisitante)
      {
            cursor = primero(listaEquipo);
             while(cursor != fin())
          {
         /*pregunto si es el id que estoy buscando*/
              if(compararIdEquipo((Equipo*)cursor->ptrDato,idvisitante) == IGUAL)
              {
         /*guardo el total en un aux y despues lo guardo en el tda*/
          int puntosaux = getPuntos(*((Equipo*)cursor->ptrDato)) + 3;
          setPuntos(*((Equipo*)cursor->ptrDato),puntosaux);
              }  
          cursor = siguiente(listaEquipo,cursor);
          }
      }
  
   else   //Empataron  1 punto para cada equipo
        {
        
         cursor = primero(listaEquipo);
          while(cursor != fin())
          {
         /*pregunto si es el id que estoy buscando*/
              if(compararIdEquipo((Equipo*)cursor->ptrDato,idvisitante) == IGUAL or compararIdEquipo((Equipo*)cursor->ptrDato,idlocal) == IGUAL )
              {
         /*guardo el total en un aux y despues lo guardo en el tda*/
          int puntosaux = getPuntos(*((Equipo*)cursor->ptrDato)) + 1;
          setPuntos(*((Equipo*)cursor->ptrDato),puntosaux);
              }  
          cursor = siguiente(listaEquipo,cursor);
          } 
         } 
 
  guardarLista(listaEquipo);
  
}
//------------------------------------------------------------------------------------------------
void actualizarGolesJugador(Lista &listaJugador,int idjugador,int goles)
{
	PtrNodoLista cursor = primero(listaJugador);

	while(cursor != fin())
    {
    if(compararIdJugador((Jugador*)cursor->ptrDato,idjugador) == IGUAL)
	{
     int golesaux = getGoles(*((Jugador*)cursor->ptrDato)) + goles;
     setGoles(*((Jugador*)cursor->ptrDato),golesaux);
	}
		cursor = siguiente(listaJugador,cursor);

	}
}

/*==================================================================================================
FUNCION QUE RECIBE LOS DATOS DEL EQUIPO
=================================================================================================*/ 
void procesarEquipos(Lista &listaEquipo)
{
int id;
char* nom;
int puntos;
int gf;
int gc;

char* Varide;
char* Varpuntos;
char* Vargf;
char* Vargc;

FILE *archivo;
char b;
char * pch;
char buffer [30];
int cont=0,i=0,control=0;
int vec[20];
char nombreArchivo[30];

cout <<"Ingrese el nombre del archivo:"<<endl;
cin >>nombreArchivo;

/*--- Cargo el vector de longitudes de las lineas del txt ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
b=fgetc(archivo);
cont++;
if(b == '\n')
{
vec[i]= cont;
i++;
cont=0;
}
}

}
fclose(archivo);
/*
/*--- Cargo las lineas ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
fgets(buffer,vec[i],archivo);

pch = strtok (buffer,";\n");
while (pch != NULL)
{
control++;

switch(control)
{
case 1: Varide=pch ;break;
case 2: nom=pch ;break;
case 3: Varpuntos=pch ;break;
case 4: Vargf=pch ;break;
case 5: Vargc=pch ;break;
}
if(control==5)
{
id = atoi(Varide);
puntos = atoi(Varpuntos);
gf = atoi(Vargf);
gc = atoi(Vargc);
cout<<id<<"\t"<<nom<<"\t"<<puntos<<"\t"<<gf<<"\t"<<gc<<endl;
cargarEquipo(listaEquipo,id,nom,puntos,gf,gc);
}

pch = strtok (NULL, ";\n");

}
i++;
control=0;

}

}
fclose(archivo);

}

//==================================================================================
void procesarJugadores(Lista &listaJugador)
{
int id;
char* nombre;
char* fecha;
int goles;
int idequipo;

char* Varid;
char* Vargoles;
char* Varidequipo;

FILE *archivo;
char b;
char* pch;
char buffer[30];
int cont=0,i=0,control=0;
int vec[20];
char nombreArchivo[30];

cout <<"Ingrese el nombre del archivo:"<<endl;
cin >>nombreArchivo;

/*--- Cargo el vector de longitudes de las lineas del txt ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
b=fgetc(archivo);
cont++;
if(b == '\n')
{
vec[i]= cont;
i++;
cont=0;
}
}

}
fclose(archivo);
/*
/*--- Cargo las lineas ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
fgets(buffer,vec[i],archivo);

pch = strtok (buffer,";\n");

while (pch != NULL)
{
control++;


switch(control)
{
case 1: Varid=pch; break;
case 2: nombre=pch; break;
case 3: fecha=pch; break;
case 4: Vargoles=pch; break;
case 5: Varidequipo=pch; break;
}
if(control==5)
{
id = atoi(Varid);
goles = atoi(Vargoles);
idequipo = atoi(Varidequipo);

cargarJugador(listaJugador,id,nombre,fecha,goles,idequipo);
}

pch = strtok (NULL, ";\n");

}
i++;
control=0;

}

}
fclose(archivo);
 
     
     }

//======================================================================================
void procesarFecha(Lista &listaEquipo)
{
int idlocal;
int  idvisitante;
int goleslocal;
int  golesvisitante;

char* Varidlocal;
char* Varidvisitante;
char* Varglocal;
char* Vargvisitante;

FILE *archivo;
char b;
char* pch;
char buffer[30];
int cont=0,i=0,control=0;
int vec[20];
char nombreArchivo[30];
cout <<"Ingrese el nombre del archivo:"<<endl;
cin >>nombreArchivo;

/*--- Cargo el vector de longitudes de las lineas del txt ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
b=fgetc(archivo);
cont++;
if(b == '\n')
{
vec[i]= cont;
i++;
cont=0;
}
}

}
fclose(archivo);
/*
/*--- Cargo las lineas ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
fgets(buffer,vec[i],archivo);

pch = strtok (buffer,";\n");

while (pch != NULL)
{
control++;

switch(control)
{
case 1: Varidlocal=pch; break;
case 2: Varidvisitante=pch; break;
case 3: Varglocal=pch; break;
case 4: Vargvisitante=pch; break;

}
if(control==4)
{
idlocal = atoi(Varidlocal);
idvisitante = atoi(Varidvisitante);
goleslocal = atoi(Varglocal);
golesvisitante = atoi(Vargvisitante);

actualizarGolesEquipos(listaEquipo,idlocal,idvisitante,goleslocal,golesvisitante);
}

pch = strtok (NULL, ";\n");

}
i++;
control=0;

}

}
fclose(archivo);
 
     
     }

//=================================================================================
void procesarGoles(Lista &listaJugador)
{
int idjugador;
int  goles;
char* Varidjugador;
char* Vargoles;

FILE *archivo;
char b;
char* pch;
char buffer[30];
int cont=0,i=0,control=0;
int vec[20];
char nombreArchivo[30];
cout <<"Ingrese el nombre del archivo:"<<endl;
cin >>nombreArchivo;

/*--- Cargo el vector de longitudes de las lineas del txt ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
b=fgetc(archivo);
cont++;
if(b == '\n')
{
vec[i]= cont;
i++;
cont=0;
}
}

}
fclose(archivo);
/*
/*--- Cargo las lineas ---*/
if( (archivo = fopen(nombreArchivo, "r")) == NULL )
{
printf("ERROR. No se pudo abrir el archivo \n");
}
else
{
while(! feof(archivo) )
{
fgets(buffer,vec[i],archivo);

pch = strtok (buffer,";\n");

while (pch != NULL)
{
control++;

switch(control)
{
case 1: Varidjugador=pch; break;
case 2: Vargoles=pch; break;

}
if(control==2)
{
idjugador = atoi(Varidjugador);
goles = atoi(Vargoles);
cout<<idjugador<<goles<<endl;
actualizarGolesJugador(listaJugador,idjugador,goles);
}

pch = strtok (NULL, ";\n");

}
i++;
control=0;

}

}
fclose(archivo);
 
     
     }


//==================================================================================
