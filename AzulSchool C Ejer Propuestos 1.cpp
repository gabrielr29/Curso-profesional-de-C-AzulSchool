#include <iostream>
#include <conio.h>
using namespace std;

void show_D(int d, string planet){
		
		system("cls");	
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|           Planetas del SS y sus distancias           |"<<endl;
		cout<<"		|                   medias al sol                      |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		  * La distancia media de "<<planet<<" es: "<<d<<" Millones de km"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|   Presione cualquier tecla para continuar...         |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		--------------------------------------------------------"<<endl;
		
		getch();	
}

void show_C(string color, string description){
		
		system("cls");	
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|          Colores del semaforo y su respectivo        |"<<endl;
		cout<<"		|                     significado                      |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		  * El color "<<color<<" significa: "<<description<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|   Presione cualquier tecla para continuar...         |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		--------------------------------------------------------"<<endl;
		
		getch();	
}

void planets(){
	
		char opc;
	
	do{
		system("cls");
		
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|           Planetas del SS y sus distancias           |"<<endl;
		cout<<"		|                   medias al sol                      |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		| *Ingrese el numero correspondiente a su busqueda     |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  1.- Mercurio                                        |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  2.- Venus                                           |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  3.- Tierra                                          |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  4.- Marte                                           |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  5.- Jupiter                                         |"<<endl;		
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  6.- Saturno                                         |"<<endl;		
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  7.- Urano                                           |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  8.- Neptuno                                         |"<<endl;		
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  9.- Volver al menu anterior                         |"<<endl;		
		cout<<"		--------------------------------------------------------"<<endl;
		
		opc = getch();
				
		switch(opc){
			
			case '1':
			system("cls");	
			show_D(59,"Mercurio");
			break;
			
			case '2':
			system("cls");	
			show_D(108,"Venus");
			break;
			
			case '3':
			system("cls");	
			show_D(150,"Tierra");
			break;
			
			case '4':
			system("cls");	
			show_D(228,"Marte");
			break;
			
			case '5':
			system("cls");	
			show_D(750,"Jupiter");
			break;
			
			case '6':
			system("cls");	
			show_D(1431,"Saturno");
			break;
			
			case '7':
			system("cls");	
			show_D(2877,"Urano");
			break;
			
			case '8':
			system("cls");	
			show_D(4509,"Neptuno");
			break;
			
			case '9':
			break;	
			
			default:
			system("cls");		
			cout<<"ERROR, intente de nuevo."<<endl;
			getch();
			break;	
		}
		
	}while(opc!='9');
	
	
}

void traffic_l(){
	
		char opc;
	
	do{
		system("cls");
		
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|          Colores del semaforo y su respectivo        |"<<endl;
		cout<<"		|                     significado                      |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		| *Ingrese el numero correspondiente a su busqueda     |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  1.- Rojo                                            |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  2.- Verde                                           |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  3.- Amarillo                                        |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  4.- Volver al menu anterior                         |"<<endl;		
		cout<<"		--------------------------------------------------------"<<endl;
		
		opc = getch();
				
		switch(opc){
			
			case '1':
			system("cls");	
			show_C("Rojo","<No pasar>");
			break;
			
			case '2':
			system("cls");	
			show_C("Verde","<Adelante>");
			break;
			
			case '3':
			system("cls");	
			show_C("Amarillo","<Precaucion>");
			break;
					
			case '4':
			break;	
			
			default:
			system("cls");		
			cout<<"ERROR, intente de nuevo."<<endl;
			getch();
			break;	
		}
		
	}while(opc!='4');
	
	
}



int main(){
	
	char opc;
	
	do{
		system("cls");
		
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|        Saludos! Bienvenido a este programa           |"<<endl;
		cout<<"		|         de practica, que deseas hacer?               |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  1.- Conocer los planetas del SS y sus distancias    |"<<endl;
		cout<<"		|  medias al sol.                                      |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  2.- Conocer los colores del semaforo y el signifi-  |"<<endl;
		cout<<"		|  cado de cada uno.                                   |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|  3.- Salir                                           |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		--------------------------------------------------------"<<endl;
		
		opc = getch();
				
		switch(opc){
			
			case '1':
			system("cls");		
			planets();	
			break;
			
			case '2':
			system("cls");		
			traffic_l();
			break;
			
			case '3':
			cout<<endl<<"Gracias por utilizar este programa!"<<endl;
			getch();
			break;
			
			default:
			cout<<"ERROR, intente de nuevo!"<<endl;
			getch();
			break;
		}
		
	}while(opc!='3');
	
	
	return 0;	
}