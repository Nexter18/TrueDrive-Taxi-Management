#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include <sstream>
#include <fstream>
#include<windows.h>

using namespace std;

//Sysdmin
string NewWorkerName;
string NewWorkerPassword;
string AdminName="admin";
string AdminPassword="admin";

// Registro TrueDriver
string ID;
string Dui;
string Nombre;
string Seguro;
string Telefono;
//Registro de Vehiculo
string Placa;
string Marca;
string nMotor;
int anio;
string Categoria;
int NumerodeRegistro=0;
int validaAnio;
int numRegistroEjecutivo=0;
int numRegistroTradicional =0;
string MensajeValidacion= "";

int OpTaxi;

//Variables reutilizables
string Partida;
string Destino;
int Precio;
string dolarsign = "$";



// Vectores del sistema

vector <string> TaxiCliente;
vector <string> TaxiRuta;
vector <string> TaxiEjecutivo;
vector <string> TaxiTradicional;

//Matriz para archivos
string Datos [1000][10];


string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

string RegistroViajesMatriz [100][4];
int NumerodeRegistro2 = 0;

//Funcion posicion cursor
void gotoxy(int x, int y){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x;
dwPos.Y = y;
SetConsoleCursorPosition(hcon, dwPos);
}

//Metodos principales

void ValidacionTaxista (string ID, string Dui, string Placa);

	void Registro () {
		
	
		cout<< "Ingrese ID: ";
		cin>>ID;
		
		cout<< "Ingrese el nombre y apellido del taxista : ";
		cin.ignore();
        getline(cin,Nombre);
        
        cout<< "Ingrese su numero de DUI: ";
		cin>>Dui;
		
		cout<< "Numero de Seguro Social: ";
		cin>>Seguro;
		
		cout<< "Numero de Telefono: ";
		cin>>Telefono;
		
		cout<< "Numero de Placa: ";
		cin>>Placa;
		
		cout<< "Marca del Taxi: ";
		cin>>Marca;
		
		cout<< "Numero de Motor: ";
		cin>>nMotor;
				
		cout<< "Anio del auto: ";
		cin>>anio;
			 
		cin.ignore();	 
		if (anio>=2010 & anio<2015) {  
			
			validaAnio=1; 
			Categoria = "Tradicional";
		}
		
		else if (anio>=2015) {  
		    
		    validaAnio=1;
		    Categoria = "Ejecutiva";
		
		} 
		while(anio<2010)
		{
		cout<<"Porfavor ingrese un año mayor a 2010."<<endl;
		cout<<"\nAnio del auto: "<<endl;
		cin>>anio;
		}
		
		ValidacionTaxista (ID, Dui, Placa);
		         
      if (validaAnio == 1 && MensajeValidacion == ""  ) {
	      
	      
	      
	      
         Datos [NumerodeRegistro][0]= ID;
         Datos [NumerodeRegistro][1]= Nombre;
         Datos [NumerodeRegistro][2]= Dui;
         Datos [NumerodeRegistro][3]= Seguro;
         Datos [NumerodeRegistro][4]= Telefono;
         Datos [NumerodeRegistro][5]= Placa;
         Datos [NumerodeRegistro][6]= Marca;
         Datos [NumerodeRegistro][7]= nMotor; 
         Datos [NumerodeRegistro][8]= Categoria;
         Datos [NumerodeRegistro][9]= anio;
         NumerodeRegistro = NumerodeRegistro + 1;
         
         
         if (Categoria=="Ejecutiva") {
         
		 TaxiEjecutivo.push_back(ID);
		 
         numRegistroEjecutivo = numRegistroEjecutivo + 1;
         
         }
         
         else {
         	
         TaxiTradicional.push_back(ID);
         
         numRegistroTradicional = numRegistroTradicional + 1;
         
		 } 
         
	    } else {
	    	
	      cout<< MensajeValidacion;
		}
		system("cls");
		gotoxy(35,5);cout<<"Registro agregado con exito!"<<endl;
      } 





    void Tabla (){

	TextTable t( '-', '|', '+' );
	t.add("ID");
	t.add("Nombre");
	t.add("Dui");
	t.add("Seguro");
	t.add("Telefono");
	t.add("Placa");
	t.add("Marca");
	t.add("Numero de Motor");
	t.add("Categoria");
	t.endOfRow();
	


    
    
    
    
    for(int i=0; i<NumerodeRegistro ;i++)
	{
		
		t.add((Datos[i][0]));
		t.add((Datos[i][1]));
		t.add((Datos[i][2]));
	    t.add((Datos[i][3]));
	    t.add((Datos[i][4]));
	    t.add((Datos[i][5]));
	    t.add((Datos[i][6]));
	    t.add((Datos[i][7]));
	    t.add((Datos[i][8]));
	    
		t.endOfRow();	
	}
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;

	}
	
	
	
	
	
    void TaxienRuta (vector <string> TaxiRuta)
{
	TextTable t( '-', '|', '+' );
	t.add("ID");
	t.add("Nombre");
	t.add("Numero de telefono");
	t.add("Categoria");
	t.endOfRow();
	
	for(int i=0; i<TaxiRuta.size();i++)
	{
		t.add((TaxiRuta.at(i)));
	      for(int A=0; A<NumerodeRegistro ;A++)
	{
		if (TaxiRuta.at(i)==Datos[A][0]) {
		
			t.add((Datos[A][1]));
			t.add((Datos[A][4]));
			t.add((Datos[A][8]));
		}
		
	}
		t.endOfRow();	
	}
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;
	
	
}


// Paso 5

void DisponibilidadTaxi (vector <string> TaxiEjecutivo, vector <string> TaxiTradicional, string Categoria)
{
	
	
	if (Categoria=="Ejecutiva") {
         
		 cout<< "\n +++ Disponibilidad de taxis Ejecutivos +++\n";
         
         
         
         }
         
         else {
         	
         cout<< "\n +++ Disponibilidad de taxis Tradicionales +++\n";
         
		 } 
		 
		 
	
	TextTable t( '-', '|', '+' );
	t.add("ID");
	t.add("Nombre");
	t.add("Numero de telefono");
	t.add("Categoria");
	t.endOfRow();
	
	
	if (Categoria=="Ejecutiva") {
         
		
         
         for(int i=0; i<TaxiEjecutivo.size();i++)
	{
		t.add((TaxiEjecutivo.at(i)));
	      for(int A=0; A<NumerodeRegistro ;A++)
	{
		if (TaxiEjecutivo.at(i)==Datos[A][0]) {
		
			t.add((Datos[A][1]));
			t.add((Datos[A][4]));
			t.add((Datos[A][8]));
		}
		
	}
		t.endOfRow();	
	}
            
         }
         
         else {
         	
      
         
           for(int i=0; i<TaxiTradicional.size();i++)
	{
		t.add((TaxiTradicional.at(i)));
	      for(int A=0; A<NumerodeRegistro ;A++)
	{
		if (TaxiTradicional.at(i)==Datos[A][0]) {
		
			t.add((Datos[A][1]));
			t.add((Datos[A][4]));
			t.add((Datos[A][8]));
		}
		
	}
		t.endOfRow();	
	}
		 }
	
	
	
	
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;
	
	

}


void CategoriaTaxi (string ID) {
	
	Categoria="";
	
	for(int A=0; A<NumerodeRegistro ;A++)
	{
		if (Datos[A][0] == ID) {
			
			Categoria = Datos [A][8];
			
			break ;
			
		}
		
		
	}
	
	
}

void ValidacionTaxista (string ID, string Dui, string Placa) {
	
	MensajeValidacion= "";
	
	for(int A=0; A<NumerodeRegistro ;A++)
	{
		if (Datos[A][0] == ID) {
			
			MensajeValidacion= "El ID que quiere registrar ya existe, elije otro numero";
			
		}
		
		if (Datos[A][2] == Dui) {
			
			MensajeValidacion= "El Dui que quiere registrar ya pertenece a un taxista registrado";
			
		}
		
		if (Datos[A][5] == Placa) {
			
			MensajeValidacion= "La placa del vehiculo que quiere registrar ya existe";
			
		}
		
	}
	
}

//Projecto II - Guardado de datos

void GuardarRegistro (string ID, string Dui, string Seguro, string Telefono, string Placa, string Marca, string nMotor, int anio) {
	
	ofstream myfile ("CARS_STORAGE.txt", ios::app);
	  if (myfile.is_open()) {
	  	
	  	
	  	
	  		myfile <<ID<<"\n";	
	    	myfile <<Nombre<<"\n";
	    	myfile <<Dui<<"\n";
	    	myfile <<Seguro<<"\n";
	    	myfile <<Telefono<<"\n";
	    	myfile <<Placa<<"\n";
	    	myfile <<Marca<<"\n";
		    myfile <<nMotor<<"\n";
		    
            myfile <<anio<<"\n";
	        myfile <<"-----------\n";
	        myfile.close();
	  	    
	  	    
	  	    
	  	
	  	
	  } else {
	  	
	  	cout << "No se pudo abrir el archivo o el archivo no existe aun";
	  }
}


void GuardarRegistroViajes (string ID, string Partida, string Destino, int Precio) {
	
	ofstream myfile ("TRANSACTION_LOG.txt", ios::app);
	  if (myfile.is_open()) {
	  	
	  	
	  	
	  		myfile <<ID<<"\n";	
	    	myfile <<Partida<<"\n";
	    	myfile <<Destino<<"\n";
	    	myfile <<Precio<<"\n";
	    	
	        myfile <<"-----------\n";
	        myfile.close();
	        
	        cout<<"Viaje registrado con exito"<<endl;
	  	    
	  	
	  } else {
	  	
	  	cout << "No se puede abrir el archivo o el archivo no existe aun";
	  }
}

	  
	  
	  void LecturaStorage () {

	  
	  string Line;
	  int column = 0;
	  int row = 0;
	  
	  ifstream myfile ("CARS_STORAGE.txt");
	  if (myfile.is_open()) {
	  	
	  	while ( getline(myfile,Line) )
	  	
	  	{  
	  	
	  	//cout << Line;
	  	
	  	if (Line == "-----------") {
     	
     	    row = row + 1;
     		column = 0;
     		NumerodeRegistro = NumerodeRegistro + 1;
		 }
	 	else
	 	{
	 		Datos[row][column]=Line;
     	//	cout << Datos[row][column]+"\n";
     		column = column + 1;
     		
		 }
     	
	  	
		  }
		  
		  myfile.close();
		 
		  } 
	  else cout<<"No se puede abrir el archivo o el archivo aun no existe";
	    
}

 void LecturaTransaction () {
 	
	  string Line;
	  int column = 0;
	  int row = 0;
	  
	  ifstream myfile ("TRANSACTION_LOG.txt");
	  if (myfile.is_open()) {
	  	
	  	while ( getline(myfile,Line) )
	  	
	  	{  
	  	

	  	if (Line == "-----------") {
     	
     	    row = row + 1;
     		column = 0;
     		NumerodeRegistro2 = NumerodeRegistro2 + 1;
		 }
	 	else
	 	{
	 		RegistroViajesMatriz [row][column]=Line;
	 		
	 	//	cout<<RegistroViajesMatriz [row][column];
	 	
     		column = column + 1;
     		
		 }
     	
	  	
		  }
		  
		  myfile.close();
		 
		  } 
	  else cout<<"No se puede abrir el archivo o el archivo aun no existe";
}

// Option 7

void ListadoTodos ()
{
	 
	
	TextTable t( '-', '|', '+' );
	t.add("ID");
	t.add("Punto de salida");
	t.add("Punto de llegada");
	t.add("Precio del viaje");
	t.endOfRow();
		
	 
	for(int A=0; A<NumerodeRegistro2 ;A++)
	{

			t.add((RegistroViajesMatriz[A][0]));
			t.add((RegistroViajesMatriz[A][1]));
			t.add((RegistroViajesMatriz[A][2]));
		    t.add(dolarsign+(RegistroViajesMatriz[A][3]));
			t.endOfRow();
		
	}
	
		

	
	
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;

}


void ListadoEspecifico ()
{
	 string IDtaxi;
	 cout<<"Ingrese el ID del taxi a buscar :";
	 cin >>IDtaxi;
	
	TextTable t( '-', '|', '+' );
	t.add("ID");
	t.add("Punto de partida");
	t.add("Punto de partida");
	t.add("Precio del viaje");
	t.endOfRow();
		
	 
	for(int A=0; A<NumerodeRegistro2 ;A++)
	{
          if (RegistroViajesMatriz[A][0]==IDtaxi) {
          	
		  
          
          
			t.add((RegistroViajesMatriz[A][0]));
			t.add((RegistroViajesMatriz[A][1]));
			t.add((RegistroViajesMatriz[A][2]));
		    t.add("$"+(RegistroViajesMatriz[A][3]));
			t.endOfRow();
			
			
		
	}
}
	
	
		

	
	
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;



}
