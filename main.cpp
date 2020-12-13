#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include "Textable.h"
#include "Func.h"
#include <sstream>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//Metodos
void Registro ();
void Tabla();
void TaxienRuta(vector <string> TaxiRuta);
void DisponibilidadTaxi (vector <string> TaxiEjecutivo, vector <string> TaxiTradicional, string Categoria);

// Metodos projecto II
void GuardarRegistro(string ID, string Dui, string Seguro, string Telefono, string Placa, string Marca, string nMotor, int anio);
void GuardarRegistroViajes (string ID, string Partida, string Destino, int Precio);

void LecturaStorage ();



void CategoriaTaxi(string ID);
void LecturaTransaction ();


void ListadoTodos ();
void ListadoEspecifico ();

void gotoxy(int x, int y);


int main () {

int Opcion;

string Respuesta = "S";

system("color 03");
//system("color %");
cout<<"************************************************************************************************************************";
gotoxy(45,2);cout<<"Bienvenido a TrueDrive"<<"\n";
cout<<"\n"<<"************************************************************************************************************************";
cout<<"\n\t\t CARGANDO ";
Sleep(100);//Pausa
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">";
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100); 
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100); 
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"<"; 
Sleep(100);
cout<<">"; 
Sleep(100);
cout<<"\n\n\t Exito! \n";

Sleep(2000);//Pausa antes de siguiente pantalla
system("cls");

string opcionPalabra;
char opcionMenu;

LecturaStorage ();
LecturaTransaction ();
do{



system("cls");
gotoxy(45,1);cout<<"***********************"<<endl;
gotoxy(45,2);cout<<"Sistema TrueDrive Taxis"<<endl;
gotoxy(45,3);cout<<"***********************"<<endl;
cout<<endl;

cout<<"1.  Admin Login"<<endl;
cout<<"2. Login de Empleados"<<endl;
cout<<"3. Salir"<<endl;

cout<<"Seleccione una opcion del menu: ";
cin>>opcionPalabra;

int opcion = atoi( opcionPalabra.c_str() );
 switch(opcion)
 {
  case 1:
    {
    	string UserName;
        string Password;
        bool LoginSuccess= false;
        do
		{
//************************************************************************************
//*                           Admin Login                                            *
//************************************************************************************     
    		system("cls");
			gotoxy(45,1);cout<<"********************"<<endl;
            gotoxy(45,2);cout<<"*  Login Administrativo   *"<<endl;
        	gotoxy(45,3);cout<<"********************"<<endl;
    		cout<<endl;
    		Sleep(500);
			cout<<"Pista:- admin\n";
    		cout<<"\nUserName: ";
    		cin>>UserName;
    		cout<<"Password: ";
			cin>>Password;
 
    		if(UserName== AdminName && Password == AdminPassword)
    		{
				cout<<"Acceso concedido \n";
    			LoginSuccess= true;
    			Sleep(2000);
    			system("cls");
    			char opcionMenu;
				do
    			{
					system("cls");
        			string opcionPalabra;
					gotoxy(45,1);cout<<"********************"<<endl;
					gotoxy(45,2);cout<<"*  Administracion  *"<<endl;
					gotoxy(45,3);cout<<"********************"<<endl;
					cout<<"Menu de opciones:\n\n"<<endl;
					cout<<"\t\t1. Registrar taxi y conductor"<<endl;
					cout<<"\t\t2. Consultar Taxis Registrados"<<endl;
					cout<<"\t\t3. Enviar un taxi al cliente"<<endl;
					cout<<"\t\t4. Consultar taxis en ruta"<<endl;
					cout<<"\t\t5. Consultar taxis disponibles"<<endl;
					cout<<"\t\t6. Regresar un taxi a la cola de disponibilidad"<<endl;
					cout<<"\t\t7. Listado de viajes realizados por todos los vehículos"<<endl;
					cout<<"\t\t8. Listado de viajes realizados por vehículo"<<endl;
					cout<<"\t\t9. Salir del programa"<<endl<<endl;
					cout<<"Por favor, inserte su opcion: ";
					cout<<"Selecciona una opcion :";
					cin>>opcionPalabra;
					int opcion = atoi( opcionPalabra.c_str() );
					switch(opcion)
                    {
						case 1:
						{	 
							system("cls");
							Registro();
							GuardarRegistro( ID, Dui, Seguro, Telefono, Placa, Marca, nMotor, anio);
							break;
						}
						case 2:{
							system("cls");
							Tabla();
							break;
						}
						case 3:{
							system("cls");
							cout<< "\n1. Taxi Tradicional\n"; 
							cout<< "2. Taxi Ejecutivo\n";
							cout<< "\nSeleccione la categoria del taxi:";
							cin>>OpTaxi;
							cout<< "Ingrese el punto de partida del cliente: "<<endl;
							cin>> Partida;
							cout<< "Ingrese el destino del cliente: "<<endl;
							cin>> Destino;
							cout<< "Ingrese el precio del viaje: "<<endl;
							cin>> Precio;
							if (OpTaxi==1) {
								TaxiRuta.push_back(TaxiTradicional.front());
								TaxiTradicional.erase(TaxiTradicional.begin());
								GuardarRegistroViajes ( TaxiTradicional.front(), Partida, Destino, Precio);
							}else if (OpTaxi==2){
								TaxiRuta.push_back(TaxiEjecutivo.front());
								TaxiEjecutivo.erase(TaxiEjecutivo.begin());
								GuardarRegistroViajes (TaxiEjecutivo.front(), Partida, Destino, Precio);
							}else {
								cout<< "Opcion de categoria inexistente";
							}
							break;			
						}
						case 4:{
							system("cls");
							TaxienRuta(TaxiRuta);
							break;
						}
						case 5:{
							system("cls");
							DisponibilidadTaxi (TaxiEjecutivo,TaxiTradicional, "Tradicional");
							DisponibilidadTaxi (TaxiEjecutivo,TaxiTradicional, "Ejecutiva");
							break;
							}
						case 6:{
							system("cls");
							TaxienRuta(TaxiRuta);
							cout<< "Ingrese el ID del taxi que desea retornar a la lista de los taxis disponibles: ";
							cin>>ID;
							string CategoriaTaxiRuta ="";
							CategoriaTaxiRuta = Categoria;
							if (CategoriaTaxiRuta == "Ejecutiva") {
								TaxiEjecutivo.push_back(ID);
								for(int i=0; i<TaxiRuta.size();i++)
                    				{
										if (TaxiRuta.at(i)==ID){
                    					TaxiRuta.erase(TaxiRuta.begin()+i);
                    					break;
										}			
									}
							}else if (CategoriaTaxiRuta == "Tradicional") {
		    					TaxiTradicional.push_back(ID);
								for(int i=0; i<TaxiRuta.size();i++)
                    			{
									if (TaxiRuta.at(i)==ID){
									TaxiRuta.erase(TaxiRuta.begin()+i);
                    				break;
									}
								}
							}else{
								cout<< "Este taxi no se encuentra en ruta.";
							}
						break;
						}
						case 7:{
							system("cls");
							ListadoTodos ();
							break;
						}
						case 8:{
							system("cls");
							ListadoEspecifico ();
							break;
						}
						case 9:{
							system("cls");
							cout<<"\tUsted se ha deslogeado correctamente\n";
							cout<<"\n"<<endl<<endl;
							break;
						}	
						default:{
							system("cls");
							cout<<"Ingresaste una opcion incorrecta.\n"<<endl;
							break;
						}
					}//end of switch
                 	if(opcion==9)
						{
						break;
						}
				cout<<"Presione cualquier tecla para regresar al menu anterior...";
				opcionMenu=getch();
				}while(opcionMenu);  
				}         
                else
				{
					cout<<"User y Password incorrectos.\n"
					<<"Porfavor intente nuevamente";
					Sleep(2000);
				}
		}while(!LoginSuccess);
		break; //end of Admin Login do
	}//end of case1
case 2:
    {
    	string UserName="";
		string Password="";
		bool LoginSuccess= false;
		do{
//*********************************************************************************************************
//*                           Menu Empleados                                            *
//*********************************************************************************************************
				system("cls");
				cout<<"\t********************"<<endl;
				cout<<"\t*  Login de Empleados     *"<<endl;
				cout<<"\t********************"<<endl;
				cout<<"\nPista:- worker\n";
				cout<<"UserName: ";
				cin>>UserName;
				cout<<"Password: ";
				cin>>Password;
 
    		if(UserName== "worker" && Password == "worker" || UserName== NewWorkerName && Password == NewWorkerPassword )
    		{
				cout<<"Acceso concedido \n";
    			LoginSuccess= true;
    			Sleep(2000);
    			system("cls");
    			char opcionMenu;
				do
    			{
					system("cls");
        			string opcionPalabra;
					gotoxy(45,1);cout<<"********************"<<endl;
					gotoxy(45,2);cout<<"*  Administracion  *"<<endl;
					gotoxy(45,3);cout<<"********************"<<endl;
					cout<<"Menu de opciones:\n\n"<<endl;
					cout<<"\t\t1. Registrar taxi y conductor"<<endl;
					cout<<"\t\t2. Consultar Taxis Registrados"<<endl;
					cout<<"\t\t3. Enviar un taxi al cliente"<<endl;
					cout<<"\t\t4. Consultar taxis en ruta"<<endl;
					cout<<"\t\t5. Consultar taxis disponibles"<<endl;
					cout<<"\t\t6. Regresar un taxi a la cola de disponibilidad"<<endl;
					cout<<"\t\t7. Listado de viajes realizados por todos los vehículos"<<endl;
					cout<<"\t\t8. Listado de viajes realizados por vehículo"<<endl;
					cout<<"\t\t9. Deslogearse"<<endl<<endl;
					cout<<"Por favor, inserte su opcion: ";
					cout<<"Selecciona una opcion :";
					cin>>opcionPalabra;
					int opcion = atoi( opcionPalabra.c_str() );
					switch(opcion)
                    {
						case 1:
						{	
							system("cls");  
							Registro();
							GuardarRegistro( ID, Dui, Seguro, Telefono, Placa, Marca, nMotor, anio);
							break;
						}
						case 2:{
							system("cls");
							Tabla();
							break;
						}
						case 3:{
							system("cls");
							cout<< "\n1. Taxi Tradicional\n"; 
							cout<< "2. Taxi Ejecutivo\n";
							cout<< "\nSeleccione la categoria del taxi:";
							cin>>OpTaxi;
							cout<< "Ingrese el punto de partida del cliente: ";
							cin>> Partida;
							cout<< "Ingrese el destino del cliente: ";
							cin>> Destino;
							cout<< "Ingrese el precio del viaje: ";
							cin>> Precio;
							if (OpTaxi==1) {
								TaxiRuta.push_back(TaxiTradicional.front());
								TaxiTradicional.erase(TaxiTradicional.begin());
								GuardarRegistroViajes ( TaxiTradicional.front(), Destino, Partida, Precio);
							}else if (OpTaxi==2){
								TaxiRuta.push_back(TaxiEjecutivo.front());
								TaxiEjecutivo.erase(TaxiEjecutivo.begin());
								GuardarRegistroViajes (TaxiEjecutivo.front(), Destino, Partida, Precio);
							}else {
								cout<< "Opcion de categoria inexistente";
							}
							break;			
						}
						case 4:{
							system("cls");
							TaxienRuta(TaxiRuta);
							break;
						}
						case 5:{
							system("cls");
							DisponibilidadTaxi (TaxiEjecutivo,TaxiTradicional, "Tradicional");
							DisponibilidadTaxi (TaxiEjecutivo,TaxiTradicional, "Ejecutiva");
							break;
							}
						case 6:{
							system("cls");
							TaxienRuta(TaxiRuta);
							cout<< "Ingrese el ID del taxi que desea retornar a la lista de los taxis disponibles: ";
							cin>>ID;
							string CategoriaTaxiRuta ="";
							CategoriaTaxiRuta = Categoria;
							if (CategoriaTaxiRuta == "Ejecutiva") {
								TaxiEjecutivo.push_back(ID);
								for(int i=0; i<TaxiRuta.size();i++)
                    				{
										if (TaxiRuta.at(i)==ID){
                    					TaxiRuta.erase(TaxiRuta.begin()+i);
                    					break;
										}			
									}
							}else if (CategoriaTaxiRuta == "Tradicional") {
		    					TaxiTradicional.push_back(ID);
								for(int i=0; i<TaxiRuta.size();i++)
                    			{
									if (TaxiRuta.at(i)==ID){
									TaxiRuta.erase(TaxiRuta.begin()+i);
                    				break;
									}
								}
							}else{
								cout<< "Este taxi no se encuentra en ruta.";
							}
						break;
						}
						case 7:{
							system("cls");
							ListadoTodos ();
							break;
						}
						case 8:{
							system("cls");
							ListadoEspecifico ();
							break;
						}
						case 9:{
							system("cls");
							cout<<"\tUsted se ha deslogeado correctamente\n";
							cout<<"\n"<<endl;
							break;
						}	
						default:{
							system("cls");
							cout<<"Ingresaste una opcion incorrecta.\n";
							break;
						}
					}//end of switch
                 	if(opcion==9)
						{
						break;
						}
				cout<<"Presione cualquier tecla para regresar al menu anterior...";
				opcionMenu=getch();
				}while(opcionMenu);  
				}         
                else
				{
					cout<<"User y Password incorrectos.\n"
					<<"Porfavor intente nuevamente";
					Sleep(2000);
				}
		}while(!LoginSuccess);
		break; //end of Worker Login do
	}//end of case 2
case 3:{
	system("cls");
	gotoxy(45,2);cout<<"Gracias por utilizar el sistema construido por Edwin Duran y Salvador Rodriguez\n";
	gotoxy(45,3);cout<<"Hecho en El Salvador con amor <3"<<endl<<endl;
	return 0; 
	break;
}//end of case 3
default:
	{
		system("cls");
		cout<<"Ingresaste una opcion incorrecta."<<endl;
		break;
	}//end of default
}//end of Main Switch
cout<<"Presione cualquier tecla para continuar... ";
opcionMenu=getch();
}while(opcionMenu); //end of Main do

}
