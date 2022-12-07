#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

// Estructuras a utilizar en el programa

struct Date{
	int day, month, year;
};

struct Teacher{
	
	string name_teacher;
	int age;
	string specialization;
	string country;	
	
};

struct Course{
	string Course_name;
	struct Teacher teacher;
	struct Date date;
};

// Declaracion global de la estructura general

struct Course course[7];

// Funciones a utilizar

void Search_repeat_name(Course c[], string target);
void Search_repeat_spec(Course c[], string target);
void year_filter(Course c[],int year_base);
void interfaz_Colect(string accion);
void data_Registration();
void specialization_Selector();
void modification_option(Course c[]);
void menu();

void data_Registration(){
	
	//Nombres de los cursos
	
	course[0].Course_name = "Curso Profesional de PHP";
	course[1].Course_name = "Curso Profesional de JavaScript";
	course[2].Course_name = "Curso Profesional de Node.js";
	course[3].Course_name = "Curso Profesional de Python";
	course[4].Course_name = "Curso Profesional de Sql";
	course[5].Course_name= "Curso Profesional de React";
	course[6].Course_name= "Curso Profesional de C++";
	course[7].Course_name= "Curso Basico de Computacion";
	
	//Nombres de los maestros que dictan los cursos
	
	course[0].teacher.name_teacher = "Carlos Hernandez";
	course[1].teacher.name_teacher = "Jose Manuel Pereira";	
	course[2].teacher.name_teacher = "Daniel Orio Islas";
	course[3].teacher.name_teacher = "Lucas Lucyk";
	course[4].teacher.name_teacher = "Noel Urbina";	
	course[5].teacher.name_teacher = "Martin Melo Godinez";
	course[6].teacher.name_teacher= "Angel Sanchez Espinoza";
	course[7].teacher.name_teacher= "Gabriel Rodriguez";
		
	//Fecha de los cursos
	
	course[0].date.day = 21;
	course[0].date.month = 4;
	course[0].date.year = 2020;

	course[1].date.day = 4;
	course[1].date.month = 6;
	course[1].date.year = 2020;
	
	course[2].date.day = 26;
	course[2].date.month = 12;
	course[2].date.year = 2019;
	
	course[3].date.day = 5;
	course[3].date.month = 11;
	course[3].date.year = 2019;
	
	course[4].date.day = 30;
	course[4].date.month = 10;
	course[4].date.year = 2019;
	
	course[5].date.day = 8;
	course[5].date.month = 11;
	course[5].date.year = 2019;
	
	course[6].date.day = 3;
	course[6].date.month = 11;
	course[6].date.year = 2019;
	
	course[7].date.day = 6;
	course[7].date.month = 10;
	course[7].date.year = 2024;	
	
	//Pais de procedencia de los profesores
	
	course[0].teacher.country = "Mexico";
	course[1].teacher.country = "Mexico";
	course[2].teacher.country = "Mexico";
	course[3].teacher.country = "Argentina";
	course[4].teacher.country = "Mexico";
	course[5].teacher.country = "Mexico";
	course[6].teacher.country = "Mexico";
	course[7].teacher.country = "Venezuela";
	
	//Edad de los profesores	
	
	course[0].teacher.age =  24;
	course[1].teacher.age =  23;
	course[2].teacher.age =  24;
	course[3].teacher.age =  25;
	course[4].teacher.age =  26;
	course[5].teacher.age =  27;
	course[6].teacher.age = 35;	
	course[7].teacher.age = 24;
	
	//Especializacion de los profesores
	
	course[0].teacher.specialization = "Servidores";
	course[1].teacher.specialization = "Programacion";
	course[2].teacher.specialization = "Servidores";
	course[3].teacher.specialization = "Programacion";
	course[4].teacher.specialization = "Base de datos";
	course[5].teacher.specialization = "Programacion";
	course[6].teacher.specialization = "Programacion";
	course[7].teacher.specialization = "Programacion";
} 

// Funcion para mostrar la data de cada curso

void Show_Data(Course curso[], int n){
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			   "<<"Nombre del curso: "<<curso[n].Course_name<<endl;
	cout<<"			   "<<"Nombre del profesor que lo imparte: "<<curso[n].teacher.name_teacher<<endl;
	cout<<"			   "<<"Edad del profesor: "<<curso[n].teacher.age<<endl;
	cout<<"			   "<<"Especialidad del profesor: "<<curso[n].teacher.specialization<<endl;
	cout<<"			   "<<"Pais de origen del profesor: "<<curso[n].teacher.country<<endl;	
	cout<<"			   "<<"Fecha de publicacion del curso: "<<curso[n].date.day<<" / "<<curso[n].date.month<<" / "<<curso[n].date.year<<endl;			
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<endl;
		
}

void specialization_Selector(){
	
	char opc;
	bool loop;
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			   "<<"Que especialidad deseas usar como criterio de busqueda?"<<endl<<endl;
	cout<<"			   "<<"(1) Programacion"<<endl;
	cout<<"			   "<<"(2) Base de datos"<<endl;
	cout<<"			   "<<"(3) Servidores"<<endl;		
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<endl;	
	
	do{
		
		opc = getch();
		
		switch(opc){
			
			case '1':
			Search_repeat_spec(course, "Programacion");
			loop = false;
			break;
			
			case '2':
			Search_repeat_spec(course, "Base de datos");	
			loop = false;
			break;	
				
			case '3':
			Search_repeat_spec(course, "Servidores");	
			loop = false;	
			break;
			
			default:
			cerr<<"	ERROR, INTENTE DE NUEVO!"<<endl;
			getch();	
			break;		
			
		}
			
	}while(loop);
	
}

void Search_repeat_name(Course c[], string target){
     
    /*Algoritmo*/
    
 	int counter = 0;
	   
    for(int i=0; i<8; i++){
        if(target == c[i].teacher.name_teacher){
           Show_Data(c, i);
           counter++;
        }
    }
	
	cout<<endl<<endl<<"Coincidencias totales: "<<counter<<endl;
	
}

void Search_repeat_spec(Course c[], string target){
     
    /*Algoritmo*/
    
 	int counter = 0;
	   
    for(int i=0; i<8; i++){
        if(target == c[i].teacher.specialization){
           Show_Data(c, i);
           counter++;
        }
    }
	
	cout<<endl<<endl<<"Coincidencias totales: "<<counter<<endl;
	
}

int year_colector(){
	
	string year;
	bool pass = false;
	int i = 0;
	
	do{
		
	interfaz_Colect("Ingrese el year actual: ");	
	fflush(stdin);
	getline(cin, year);	

	try {
		
         i = std::stoi(year);
              
    }
    catch (invalid_argument const &e) {
    	
        cout << "				Bad input: std::invalid_argument thrown" << endl;
                
    }
    catch (out_of_range const &e) {
    	
        cout << "				Integer overflow: out_of_range thrown" << endl;
        
    }
    
    if(i<2022 || i>2024){
      cout<<"				ERROR, Year Invalido"<<endl;
	  cout<<"				"; system("pause");	
	}
      	
	else{
		pass = true;
	}
		
	}while(!pass);
	
	return i;	
	
}

void year_filter(Course c[],int year_base, bool criterio){
	
	if(criterio==true){

		for(int i=0; i<8; i++){
		
		if((year_base - c[i].date.year)>1){
			Show_Data(c, i);
		}
					
	}	
			
	}

	else{
		
		for(int i=0; i<8; i++){
		
		if((year_base - c[i].date.year)<1){
			Show_Data(c, i);
		}
				
	}			
		
	}
		
}

void interfaz_Colect(string accion){
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			   Bienvenido a este mini programa que simula un gestor de cursos"<<endl;
	cout<<"			                                                            "<<endl;
	cout<<"			       "<<accion<<endl;
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<"			>> ";
	
}

void modification_option(Course c[]){
	
	char opc, opc2;
	string target;
	int pos = 0;
	bool comprobator = false;
	bool loop, loop2;
	
	interfaz_Colect("Ingrese el nombre del curso cuyos parametros desees modificar.");	
	getline(cin,target);
	fflush(stdin);

	// Algoritmo para buscar cursos por su nombre  
	
	for(int i=0; i<8; i++){
		
        if(target == c[i].Course_name){
           Show_Data(c, i);
           comprobator = true;
           pos = i;
           cout<<"				"; system("pause");
        }
        
    }
    
    if(comprobator == false){
    	
    	cout<<"				No existe tal curso."<<endl;
    	cout<<"				"; system("pause");
	}
	
	else{
		
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			   "<<"Que parametro deseas modificar?"<<endl<<endl;
	cout<<"			   "<<"(1) Nombre del curso."<<endl;
	cout<<"			   "<<"(2) Nombre del profesor que imparte el curso."<<endl;
	cout<<"			   "<<"(3) Edad del profesor que imparte el curso"<<endl;	
	cout<<"			   "<<"(4) Pais de origen del profesor que imparte el curso"<<endl;
	cout<<"			   "<<"(5) Fecha de publicacion del curso"<<endl;
	cout<<"			   "<<"(6) Especializacion del profesor que imparte el curso"<<endl;
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<endl;	
	
	do{
		
		opc = getch();
		
		switch(opc){
			
			case '1':
				
			interfaz_Colect("Ingrese el nuevo nombre del curso.");	
			getline(cin,c[pos].Course_name);	
			loop = false;
			fflush(stdin);
			
			break;
			
			case '2':
				
			interfaz_Colect("Ingrese la nuevo nombre.");
			getline(cin,c[pos].teacher.name_teacher);	
			loop = false;
			fflush(stdin);
			
			break;	
							
			case '3':
				
			interfaz_Colect("Ingrese la nueva edad.");
			cin>>c[pos].teacher.age;	
			loop = false;
			fflush(stdin);
			loop = false;
				
			break;
	
			case '4':
				
			interfaz_Colect("Ingrese el pais de origen.");
			getline(cin,c[pos].teacher.country);	
			loop = false;
			fflush(stdin);
			loop = false;
				
			break;	
			
			case '5':
				
			interfaz_Colect("Ingrese el dia de publicacion.");
			cin>>c[pos].date.day;	
			interfaz_Colect("Ingrese el month de publicacion.");
			cin>>c[pos].date.month;	
			interfaz_Colect("Ingrese el year de publicacion.");
			cin>>c[pos].date.year;	
			loop = false;
			fflush(stdin);
			loop = false;
				
			break;	
			
			case '6':
			
					
			cout<<"			------------------------------------------------------------"<<endl;
			cout<<"			   "<<"A que especialidad desea cambiar?"<<endl<<endl;
			cout<<"			   "<<"(1) Programacion"<<endl;
			cout<<"			   "<<"(2) Base de datos"<<endl;
			cout<<"			   "<<"(3) Servidores"<<endl;		
			cout<<"			 ___________________________________________________________"<<endl;
		
			cout<<endl;	
	
				do{
					
			opc2 = getch();
		
			switch(opc2){
			
			case '1':
			c[pos].teacher.specialization = "Programacion";
			loop2 = false;
			break;
			
			case '2':
			c[pos].teacher.specialization = "Base de datos";	
			loop2 = false;
			break;	
				
			case '3':
			c[pos].teacher.specialization = "Servidores";
			loop2 = false;	
			break;
			
			default:
			cerr<<"	ERROR, INTENTE DE NUEVO!"<<endl;
			getch();	
			break;		
			
				}
				
				}while(loop2);
			
			break;
			
			default:
			cerr<<"	ERROR, INTENTE DE NUEVO!"<<endl;
			getch();	
			break;		
			
		}
			
	}while(loop);	
		
		
	}
    	
}
	
	
	
void menu(){
	
	char opc;
	string target;
	int actual_year;
	string key = "Qwerty2022*";
	
	data_Registration();
	actual_year = year_colector();
	
	
	do{
		system("cls");
		
		cout<<"			____________________________________________________________________"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|               Saludos! Bienvenido a este programa                |"<<endl;
		cout<<"			|               de practica que simula una parte de                |"<<endl;
		cout<<"			|                      un gestor de cursos                         |"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|                                                                  |"<<endl;								
		cout<<"			|  *Presione el numero asociado a la opcion deseada.               | "<<endl;
		cout<<"			|                                                                  |"<<endl;		
		cout<<"			|   1.- Buscar curso por profesor                                  |"<<endl;
		cout<<"			|   2.- Buscar por especialidad                                    |"<<endl;
		cout<<"			|   3.- Buscar cursos con mas de un year de publicacion.           |"<<endl;		
		cout<<"			|   4.- Buscar cursos con menos de un year de publicacion.         |"<<endl;
		cout<<"			|   5.- Modificar los datos de un curso (Requiere clave)           |"<<endl;
		cout<<"			|   6.- Mostrar todos los registros                                |"<<endl;		
		cout<<"			|                                                                  |"<<endl;						
		cout<<"			|  (0).-  Salir                                                    |"<<endl;		
		cout<<"			|                                                                  |"<<endl;					
		cout<<"			-------------------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
				
			system("cls");
			
			interfaz_Colect("Ingrese el nombre del profesor cuyos cursos desea ver.");	
			getline(cin,target);
			Search_repeat_name(course, target);
			
			cout<<"			";
			system("pause");
			
			break;
			
			case '2':
				
			system("cls");	
	
			specialization_Selector();	

			cout<<"			";
			system("pause");
							
			break;
			
			case '3':
				
			system("cls");	
			
			year_filter(course,actual_year,true);
	
			cout<<"			";
			system("pause");
								
			break;
			
			case '4':
				
			system("cls");
			
			year_filter(course,actual_year,false);
		
			cout<<"		";
			system("pause");
	
			break;
			
			case '5':
		
			system("cls");	
			
			interfaz_Colect("Ingrese la clave para acceder a las opciones de modificacion.");
			getline(cin, target);
			
				if(target == key){
					
				modification_option(course);
					
				}
				
				else{
				cout<<endl<<"				ERROR, CLAVE INVALIDA."<<endl;	
				cout<<"			";
				system("pause");	
				
				}
					
							
			break;
			
			case '6':
		
			system("cls");	
			
			for(int i=0; i<8; i++){
			
			Show_Data(course, i);	
							
			}

			cout<<"			";
			system("pause");
							
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

int main(void){
	
	menu();
	
}

