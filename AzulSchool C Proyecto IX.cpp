#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

// Funciones a utilizar

float Sum(double a, double b);
float Subtract(double a, double b);
float Multiplication(double a, double b);
float Division(double a, double b);
float Potency(double a, float n);
float Square_root(double a);
float number_colector(string a);
void interfaz_Colect(string accion);
void Show_R(float r);
void menu();

int main(void){
	
	menu();
	
	
}

float Sum(float a, float b){
	
	return a+b;
		
}

float Subtract(float a, float b){
	
	return a-b;
		
}

float Multiplication(float a, float b){
	
	return a*b;
		
}

float Division(float a, float b){
	
	return a/b;
		
}

float Potency(float a, float n){
	
	return pow(a,n);
	
}

float Square_root(float a){
	
	return sqrt(a);
	
}

void interfaz_Colect(string accion){
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			              Bienvenido a esta calculadora simple"<<endl;
	cout<<"			                                                            "<<endl;
	cout<<"			       "<<accion<<endl;
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<"			>> ";
	
}

void Show_R(float r){
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			              Bienvenido a esta calculadora simple"<<endl;
	cout<<"			                                                            "<<endl;
	cout.precision(2);
	cout<<"			       "<<"El resultado es: "<<fixed<<r<<endl;
	cout<<"			 ___________________________________________________________"<<endl<<endl;
	

	
}


float number_colector(string a){
	
	string number;
	bool pass = false;
	float i = 0;
	
	do{
		
	interfaz_Colect(a);	
	fflush(stdin);
	cin>>number;	

	try {
		
         i = std::stof(number);
              
    }
    catch (invalid_argument const &e) {
    	
        cout << "				Bad input: std::invalid_argument thrown" << endl;
        pass = true;
                
    }
    catch (out_of_range const &e) {
    	
        cout << "				Integer overflow: out_of_range thrown" << endl;
        pass = true;
        
    }
    
    		cout<<"			";
			system("pause");  

		
	}while(pass);
	
	return i;	
	
}


void menu(){
	
	char opc;
	float target, target2,r;

	
	do{
		system("cls");
		
		cout<<"			____________________________________________________________________"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|              Bienvenido a esta calculadora simple                |"<<endl;
		cout<<"			|                                                                  |"<<endl;								
		cout<<"			|  *Presione el numero asociado a la opcion deseada.               | "<<endl;
		cout<<"			|                                                                  |"<<endl;		
		cout<<"			|   1.- Suma                                                       |"<<endl;
		cout<<"			|   2.- Resta                                                      |"<<endl;
		cout<<"			|   3.- Multiplicacion                                             |"<<endl;		
		cout<<"			|   4.- Division                                                   |"<<endl;
		cout<<"			|   5.- Potencia                                                   |"<<endl;
		cout<<"			|   6.- Raiz cuadrada                                              |"<<endl;		
		cout<<"			|                                                                  |"<<endl;						
		cout<<"			|  (0).-  Salir                                                    |"<<endl;		
		cout<<"			|                                                                  |"<<endl;					
		cout<<"			-------------------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
				
			system("cls");
			
			target = number_colector("Ingrese el primer numero: ");	
			
			target2 = number_colector("Ingrese el segundo numero: ");		
			
			Show_R(Sum(target,target2));
			
			fflush(stdin);
			
			cout<<"			";
			system("pause");
			
			break;
			
			case '2':
				
			system("cls");	
	
			target = number_colector("Ingrese el primer numero: ");	
			
			target2 = number_colector("Ingrese el segundo numero: ");		
			
			Show_R(Subtract(target,target2));
			
			fflush(stdin);

			cout<<"			";
			system("pause");
							
			break;
			
			case '3':
				
			system("cls");	
			
			target = number_colector("Ingrese el primer numero: ");	
			
			target2 = number_colector("Ingrese el segundo numero: ");		
			
			Show_R(Multiplication(target,target2));
			
			fflush(stdin);
	
			cout<<"			";
			system("pause");
								
			break;
			
			case '4':
				
			system("cls");
			
			target = number_colector("Ingrese el primer numero: ");	
			
			target2 = number_colector("Ingrese el segundo numero: ");		
			
			if(target2 == 0 ){
				cout<<"				ERROR, DIVISION ENTRE 0"<<endl;
			}
			
			else{
				
			Show_R(Division(target,target2));
				
			}
			
			fflush(stdin);
			cout<<"		";
			system("pause");
	
			break;
			
			case '5':
		
			system("cls");	
			
			target = number_colector("Ingrese el numero que desea potenciar: ");
			
			target2 = number_colector("Ingrese la potencia: ");
			
			Show_R(Potency(target,target2));
			
			fflush(stdin);
		
			cout<<"		";
			system("pause");		
							
			break;
			
			case '6':
		
			system("cls");	
						
			target = number_colector("Ingrese el numero cuya raiz cuadrada desea conocer: ");	
			
			if(target < 0 ){
				cout<<"				SYNTAXT ERROR"<<endl;
			}
			
			else{
				
			Show_R(Square_root(target));
				
			}
			
			fflush(stdin);
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