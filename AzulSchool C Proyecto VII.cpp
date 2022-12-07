#include <iostream>
#include <conio.h>
#include <string.h>
#include <charconv>

using namespace std;

// Declaracion de variables globales

char name_employee[20][50];
int n_employee[20];
int employee_Counter = 0;

// Declaracion de funciones

int validar_numero(char b[]);

int validar_nombre(char nombre[][50],int cont);

bool validar_palabra(char pal[]);

void interfaz_Colect(string accion);

bool is_repeat_number(int nList_to_Verif[], int n, int size);

void employee_registry();

void order(bool criterio);

void Show_Register();

void Show_One(int position);

void Search_interfaz_name();

void Search_interfaz_n();

void Search_repeat_name(char name_to_Verif[][50], char target[], int size);

void menu();

int main(){
	
	menu();
	
}

void interfaz_Colect(string accion){
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			   Bienvenido a este mini programa de registro de empleados"<<endl;
	cout<<"			                                                            "<<endl;
	cout<<"			       "<<accion<<endl;
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<"			>> ";
	
}

int validar_numero(char b[]) //PARA ASEGURAR LA ENTRADA DE ENTEROS UNICAMENTE
{
    int i,j;

    for(i=0; i<strlen(b); i++)         //MIDE LA LONGITUD DEL ARREGLO CON STRLEN(B)
    {
        if(!(b[i]>=48 && b[i]<=57))
        {
            cerr<<"			ERROR, SOLO INGRESA NUMEROS"<<endl;
            return 0;
        }
    }
    return 1;
}

bool validar_palabra(char pal[]) //Valida el ingreso de una palabra  
{
     int i;
     for(i=0;pal[i]!='\0'&&pal[i]>='A'&&pal[i]<='z';i++);
     if(pal[i]!='\0') return false;
     else return true;     
}

int validar_nombre(char nombre[][50],int cont)
{
    int i,j;
			for(i=0; nombre[cont][i] != '\0' ; i++)
		{
			if(nombre[cont][i] >='a' && nombre[cont][i] <= 'z' || nombre[cont][i] >='A' && nombre[cont][i] <= 'Z')
			{
			return 1;
			}
				
		}
//RETORNA 0 SI NO SON CARACTERES
return 0;
}

void employee_registry(){
		
	/*
	
	Bucle para registrar el nombre e ID de un empleado
	
	*/
	
	char n_Employee_aux[5] = "0";
	
	do{
		
	if(employee_Counter == 20){
		
		cerr<<endl<<"		Error! limite de empleados alcanzado."<<endl<<"			";
		system("pause");
			
	}
	
	else{
	
	cin.clear();
		
	interfaz_Colect("Ingrese el nombre del empleado.");

	cin.getline(name_employee[employee_Counter],15);
	
	if(!validar_nombre(name_employee,employee_Counter)){
		
		cerr<<endl<<"		Error! Caracteres no permitidos"<<endl<<"			";
		system("pause");
	}
	
	else{
		
		do{
			cin.clear();
			
			interfaz_Colect("Ingrese el numero asignado al empleado: " );	
			
			cin.getline(n_Employee_aux,5);
		
			if(!validar_numero(n_Employee_aux)){
			
			// El validador tiene su propio mensaje de error
		
			cout<<endl<<"				";
			system("pause");
		
		
			}
		
			else if(stof(n_Employee_aux)>20 || stof(n_Employee_aux)<1){
		
			cout<<endl<<"				El numero esta fuera de rango 1-20"<<endl;
			
			system("pause");
			
			}
			
			
			else if(employee_Counter >=1 && is_repeat_number(n_employee, stof(n_Employee_aux), employee_Counter)){  
			
			//FUNCION DE BUSQUEDA DE REPETIDOS -> is_repeat_number
		
	     	cout<<"\n\n";	
    		cerr<<"		> El numero ingresado ya ha sido registrado antes, no se permiten repeticiones de este dato."<<endl<<"				";		
			system("pause");
			
			}
		
			else{
			
			n_employee[employee_Counter] = stof(n_Employee_aux);
			
			// strupr sirve para que la cadena se transforme a mayusculas en su totalidad
			
			strupr(name_employee[employee_Counter]);
		
			employee_Counter++;
					
			cout<<"			Registro exitoso..."<<endl<<"				";
			
			system("pause");
			
			}
				
			}while(!validar_numero(n_Employee_aux) || stof(n_Employee_aux)>20 || stof(n_Employee_aux)<1);
	
			}
		}

			
	}while(!validar_nombre(name_employee , employee_Counter) && !validar_numero(n_Employee_aux));

}

bool is_repeat_number(int nList_to_Verif[], int n, int size){
	
    char resultado = 'F';
     
    /*Algoritmo*/
     
    for(int i=0; i<size; i++){
        if(nList_to_Verif[i] == n){
            resultado = 'V';
        }
    }
   
    if(resultado == 'V'){
     return true;
	}
  
	else{
	// El numero no se repite por lo que se retorna false
	return false;
	} 
	
}

void Search_repeat_name(char name_to_Verif[][50], char target[], int size){
     
    /*Algoritmo*/
         
    for(int i=0; i<size; i++){
        if(strncmp(name_to_Verif[i],target,3)==0){
           Show_One(i);
        }
    }
	
}

void Search_interfaz_name(){
	
		char name_aux[50];
	
	/*
	
	  Bucle para listar los empleados que cumplan con el criterio de busqueda
		
	*/
	
		do{
			
			interfaz_Colect("		Ingrese el nombre del empleado que busca: " );
			
			cin.getline(name_aux,15);		
			
			if(!validar_palabra(name_aux)){
			
			cout<<"		ERROR, CARACTERES INVALIDOS"<<endl<<endl;
		
			cout<<endl<<"				";
			system("pause");
		
		
			}
			
			else{
		
					cout<<endl<<endl<<"			_________________________________________________________________________"<<endl<<endl;
					cout<<"			Empleados registrados que cumplen con el criterio de busqueda o se asemejan: "<<endl<<endl;
					strupr(name_aux);
					Search_repeat_name(name_employee,name_aux,employee_Counter);
					
					cout<<endl<<"		Ojo: Si no hay resultados, tal empleado no existe en el registro."<<endl;
					
				}
			
						
			
			
		}while(!validar_palabra(name_aux));
		
	
}

void Search_interfaz_n(){
	
	char n_aux[15];
	int n=0;
	
	do{
			
			interfaz_Colect("		Ingrese el ID/numero del empleado que busca: " );
			
			cin.getline(n_aux,15);		
			
			if(!validar_numero(n_aux)){

			cout<<endl<<"				";
			system("pause");
		
		
			}
			
			else{
					
					n = stof(n_aux);
					
					cout<<endl<<endl<<"			_________________________________________________________________________"<<endl<<endl;
					cout<<"			Empleados registrados que cumplen con el criterio de busqueda: "<<endl<<endl;
				
						for(int i=0; i<employee_Counter; i++){
      		 			 if(n_employee[i] == n){
    				    	Show_One(i);
  						      }
  						  }
					
					cout<<endl<<"		Ojo: Si no hay resultados, tal empleado no existe en el registro."<<endl;
					
				}
					
			
		}while(!validar_numero(n_aux));
			
	
}


void order(bool criterio){

	int aux = 0;
	char aux2[50];	
	
	//Ordenamiento doble con metodo burbuja
	
	if(criterio){
		
	for(int i=0; i<employee_Counter - 1 ; i++){
		
	for(int j=0; j<employee_Counter - 1 ; j++){
		
		if(n_employee[j] < n_employee[j+1]){
			
		//Ordenando los ID	
			
		aux = n_employee[j];
		
		n_employee[j] =  n_employee[j+1];
		
		n_employee[j+1] = aux;
		
		
		// Ordenando los nombres con la función strncpy
		
		strncpy(aux2,name_employee[j],50);
		
		strncpy(name_employee[j],name_employee[j+1],50);
		
		strncpy(name_employee[j+1],aux2,50);

		}
			
	}
	
	}
		
		
	}
	
	else{
		
	for(int i=0; i<employee_Counter -1 ; i++){
		
	for(int j=0; j<employee_Counter -1; j++){
		
		if(n_employee[j] > n_employee[j+1]){
			
		//Ordenando los ID
			
		aux = n_employee[j];
		
		n_employee[j] =  n_employee[j+1];
		
		n_employee[j+1] = aux;
		
		
		// Ordenando los nombres con la función strncpy
		
		strncpy(aux2,name_employee[j],50);
		
		strncpy(name_employee[j],name_employee[j+1],50);
		
		strncpy(name_employee[j+1],aux2,50);

		}
			
	}
	
		
	}
	
	
}

}

void Show_Register(){
	
	cout<<endl<<endl<<"			_________________________________________________________________________"<<endl<<endl;
	cout<<"			Empleados registrados: "<<endl<<endl;
	
	for(int i = 0; i<employee_Counter; i++){
	
		cout<<"			"<<"Nombre: "<<name_employee[i]<<" -- "<<"ID: "<<n_employee[i]<<endl<<endl;
		
	}

	cout<<"			_________________________________________________________________________"<<endl;
		
}

void Show_One(int position){
	
	
		cout<<"			"<<"Nombre: "<<name_employee[position]<<" -- "<<"ID: "<<n_employee[position]<<endl<<endl;
		
		cout<<"			_________________________________________________________________________"<<endl;
		
}


void menu(){
	
	char opc;

	do{
		system("cls");
		
		cout<<"			____________________________________________________________________"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|               Saludos! Bienvenido a este programa                |"<<endl;
		cout<<"			|             de practica que se encarga de gestionar              |"<<endl;
		cout<<"			|               un registro reducido de empleados                  |"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|                                                                  |"<<endl;								
		cout<<"			|  *Presione el numero asociado a la opcion deseada.               | "<<endl;
		cout<<"			|                                                                  |"<<endl;		
		cout<<"			|   1.- Registrar empleado.                                        |"<<endl;
		cout<<"			|   2.- Buscar empleado por su nombre.                             |"<<endl;
		cout<<"			|   3.- Buscar empleado por su ID/Numero asignado.                 |"<<endl;		
		cout<<"			|   4.- Mostrar empleados en orden ascendente.                     |"<<endl;
		cout<<"			|   5.- Mostrar empleados en orden descendente.                    |"<<endl;
		cout<<"			|                                                                  |"<<endl;						
		cout<<"			|  (0).-  Salir                                                    |"<<endl;		
		cout<<"			|                                                                  |"<<endl;					
		cout<<"			-------------------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
				
			system("cls");
	
				employee_registry();
				
			break;
			
			case '2':
				
			system("cls");	
			
			if(employee_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes empleados."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			
			else{
			
			Search_interfaz_name();
	
			cout<<"			";
			system("pause");
							
			}
							
			break;
			
			case '3':
				
			system("cls");	
			
			if(employee_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes empleados."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			
			else{
			
			Search_interfaz_n();
	
			cout<<"			";
			system("pause");
							
			}
							
			break;
			
			
			case '4':
				
			system("cls");
			
			if(employee_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes empleados."<<endl<<"			";
				cout<<"		";
				system("pause");
			}
			
			else{
				
			order(false);
			Show_Register();
			cout<<"		";
			system("pause");
							
			}
		
			break;
			
			case '5':
		
			system("cls");	
			
			if(employee_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes empleados."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			
			else{
			order(true);
			Show_Register();
			cout<<"			";
			system("pause");
							
			}
							
			break;
		
			case '0':
				
			cout<<endl<<"Gracias por utilizar este programa!"<<endl;
			getch();
			
			break;
			
			default:
			cerr<<"	ERROR, INTENTE DE NUEVO!"<<endl;
			getch();
			break;
		}
		
	}while(opc!='0');
}
