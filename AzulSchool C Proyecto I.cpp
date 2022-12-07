#include <iostream>
#include <conio.h>

using namespace std;

void translate_menu();
void translate(char opc);
string options_i();
string options_ii();
string validator_day();
string validator_month();
string validator_year();


int main(){
	
	
	translate_menu();
	
	return 0;
	
}

string options_i(int month){
	
	switch(month){
		
		case 1:
		return "Enero";
		break;
		
		case 2:
		return "Febrero";
		break;
		
		case 3:
		return "Marzo";
		break;
		
		case 4:
		return "Abril";
		break;
		
		case 5:
		return "Mayo";
		break;
		
		case 6:
		return "Junio";
		break;	
		
		case 7:
		return "Julio";
		break;
		
		case 8:
		return "Agosto";
		break;
		
		case 9:
		return "Septiembre";
		break;
		
		case 10:
		return "Octubre";
		break;
		
		case 11:
		return "Noviembre";
		break;
		
		case 12:
		return "Diciembre";
		break;	
		
		default:
		cerr<<"	ERROR"<<endl;		
		break;	
	}
	
}

string options_ii(int month){
	
	switch(month){
		
		case 1:
		return "Ene";
		break;
		
		case 2:
		return "Feb";
		break;
		
		case 3:
		return "Mar";
		break;
		
		case 4:
		return "Abr";
		break;
		
		case 5:
		return "May";
		break;
		
		case 6:
		return "Jun";
		break;	
		
		case 7:
		return "Jul";
		break;
		
		case 8:
		return "Ago";
		break;
		
		case 9:
		return "Sep";
		break;
		
		case 10:
		return "Oct";
		break;
		
		case 11:
		return "Nov";
		break;
		
		case 12:
		return "Dic";
		break;	
		
		default:
		cerr<<"	ERROR"<<endl;		
		break;	
	}
	
}

string validator_day(){
	
		//Declaracion de variable y asignacion de valor "0"
		
		char dd[1];
		string dd_validated = "0";
	
		//Validaciones simples - Caso del dia
			
			do{
				cout<<"	>>Ingrese el dia (dd)"<<endl<<endl;
				cout<<"	>>";
				cin>>dd;
				
				
				if(atoi(dd)>31 || atoi(dd)<1){
				cerr<<"	ERROR"<<endl;
				}
				else{
				dd_validated = dd;	
				cin.clear();	
				}
				
			}while(atoi(dd)>31 || atoi(dd)<1);
			
		return dd_validated;
	
}

string validator_month(){
	
		//Declaracion de variable y asignacion de valor "0"
		char mm[1];
		string mm_validated = "0";

	//Validaciones simples - Caso del mes
			
			do{
				cout<<"	>>Ingrese el mes (mm)"<<endl<<endl;
				cout<<"	>>";
				cin>>mm;
				
				
				if(atoi(mm)>12 || atoi(mm)<1){
				cerr<<"	ERROR"<<endl;
				}
				else{
				mm_validated = mm;	
				cin.clear();	
				}
								
			}while(atoi(mm)>12 || atoi(mm)<1);
			
	return mm_validated;
}

string validator_year(){
	
	//Declaracion de variable y asignacion de valor "0"
		
		char yy[4];
		string yy_validated = "0";
			
	//Validaciones simples - Caso del year
			
			do{
				cout<<"	>>Ingrese el year (yy)"<<endl<<endl;
				cout<<"	>>";
				cin>>yy;
				
				
				if(atoi(yy)>3000 || atoi(yy)<1000){
				cerr<<"	ERROR"<<endl;
				}
				else{
				yy_validated = yy;
				cin.clear();	
				}
								
			}while(atoi(yy)>3000 || atoi(yy)<1000);
			
	return yy_validated;
}


void translate(char opc){
	
		
		//Declaracion de variables y asignacion de valor "0"

		string dd, mm, yy, fecha;
		int m_opc;
			
		dd = "0";
		mm = "0";
		yy = "0";
	

		system("cls");
		
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|        Saludos! Bienvenido a este programa           |"<<endl;
		cout<<"		|         de practica, que transforma fechas a         |"<<endl;
		cout<<"		|                 a otros formatos.                    |"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|        *Ingrese la fecha en formato numerico*        |"<<endl;
		cout<<"		|          (dd/mm/yy), cada dato se pedira por         |"<<endl;		
		cout<<"		|   separado. Presione cualquier tecla para continuar. |"<<endl;
		cout<<"		--------------------------------------------------------"<<endl;
		getch();
		
		dd = validator_day();
		mm = validator_month();	
		yy = validator_year();	
		
		// Conversion a int para enviar el parametro a la funcion options_i u opctions_ii
		
		m_opc = stoi(mm); 
		
		switch(opc){
			
			case '1':
				cout<<endl<<"	La fecha en el formato solicitado queda de la siguiente manera: ";
				fecha = "	" + options_i(m_opc) + " , "  + dd + " , "  + yy;
				cout<<endl<<fecha<<endl;
				break;
				
			case '2':
				cout<<endl<<"	La fecha en el formato solicitado queda de la siguiente manera: ";
				fecha = "	" + options_ii(m_opc) + " , " + dd + " , " + yy;
				cout<<endl<<fecha<<endl;	
				break;
				
			case '3':
				cout<<endl<<"	La fecha en el formato solicitado queda de la siguiente manera: ";	
				fecha = "	" + dd + " / " + mm + " / " + yy;
				cout<<endl<<fecha<<endl;
				break;
				
			default:
			 cerr<<"	ERROR"<<endl;
			 break;	
		}			
		
	
}

void translate_menu(){
	
	char opc;

	do{
		system("cls");
		
		cout<<"		_______________________________________________________"<<endl;
		cout<<"		|                                                      |"<<endl;
		cout<<"		|        Saludos! Bienvenido a este programa           |"<<endl;
		cout<<"		|         de practica, que transforma fechas a         |"<<endl;
		cout<<"		|                 a otros formatos.                    |"<<endl;
		cout<<"		|                                                      |"<<endl;			
		cout<<"		|  *Presione el numero asociado al formato deseado.    |"<<endl;
		cout<<"		|                                                      |"<<endl;		
		cout<<"		|  (1).-  Mes completo (Ej: Octubre, 6 2022)           |"<<endl;
		cout<<"		|  (2).-  Mes abreviado (Ej: Oct, 6 2022)              |"<<endl;
		cout<<"		|  (3).-  (dd/mm/yy)                                   |"<<endl;
		cout<<"		|  (4).-  Salir                                        |"<<endl;		
		cout<<"		|                                                      |"<<endl;					
		cout<<"		--------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
			system("cls");		
			translate(opc);
			getch();
			break;
			
			case '2':
			system("cls");		
			translate(opc);
			getch();
			break;
			
			case '3':
			system("cls");		
			translate(opc);
			getch();	
			break;
			
			case '4':
			cout<<endl<<"Gracias por utilizar este programa!"<<endl;
			getch();
			break;
			
			default:
			cerr<<"	ERROR, INTENTE DE NUEVO!"<<endl;
			break;
		}
		
	}while(opc!='4');

	
}
