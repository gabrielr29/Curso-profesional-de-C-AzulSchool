#include <iostream>
#include <conio.h>

using namespace std;

bool IsFloat(string const& numero);
string ToString(int n);
float Float_comprobator(int max, int i, int j);
void M_Calculator(int d, char operation);
void Matrix_menu();

int main(){
	
	Matrix_menu();
	
}

string ToString(int n){
	
	switch(n){
		
		case 1:
			return "1";
			break;
		
		case 2:
			return "2";
			break;
		case 3:
			return "3";
			break;
		case 4:
			return "4";
			break;
		case 5:
			return "5";
			break;
		case 6:
			return "6";
			break;
		case 7:
			return "7";
			break;
		case 8:
			return "8";
			break;
		case 9:
			return "9";
			break;
		case 0:
			return "0";
			break;
				
	}	
	
}

float Float_comprobator(int max, int i, int j){
	
	bool exit=true;
	float n;
	string number, msj;
	
	do{
	
	
		msj = "			[ "+ToString(i+1)+"  "+ToString(j+1)+" ]";
			
			cout<< msj;
					
			cout<<endl;
			
			cout<<"		>>";
	
	cin>>number;
			
	if(IsFloat(number)){
		
	n=stof(number);
	
 	if(n>max){
 		system("cls");
 		cerr<<"\n"<<"  	Numero invalido, max: "<<max<<"\n";
 		cin.clear();
 		getch();
	 }
	 
	else{
	exit=false;	
	return n;
		
	} 

	}
	
	else{
	system("cls");
	cerr<<"\n"<<"  	Numero invalido, presione una tecla para volver a intentar"<<"\n";	
	
	getch();
	
	}
			
	}while(exit);
	
}

// Codigo tomado de: https://es.stackoverflow.com/questions/198050/validar-entrada-de-datos-float

bool IsFloat(string const& numero){
  bool toReturn = false;

  try{
    size_t pos = 0;
    std::stof(numero,&pos);

    // Verificamos que se ha procesado todo el contenido de numero 
    toReturn = ( pos == numero.length() );
  }

  catch(std::exception const&){
  	
    // 1234e1000 -> std::out_of_range      
    // HOLA      -> std::invalid_argument
    
  }

  return toReturn;
}

void M_Calculator(int d, char operation){
	
	float number;
	
	float m1[d][d], m2[d][d], mr[d][d];
	
	
	//Doble for para el rellenado de la matriz 1
	
	cout<<"			Matriz 1 "<<endl<<endl;
	
	for(int i = 0; i<d ; i++){
					
		for(int j = 0; j<d; j++){
			
			number = Float_comprobator(999999, i,j);
						
			m1[i][j] = number;
			
			cin.clear();
						
		}
		
	}
	
	system("cls");
	
	//Doble for para el rellenado de la matriz 2
	
	cout<<"			Matriz 2"<<endl<<endl;
	
	for(int i = 0; i<d ; i++){
						
		for(int j = 0; j<d; j++){
	
			number =  Float_comprobator(999999, i,j);
			
			m2[i][j] = number;
			
			cin.clear();
			
		}
			
	}
	
	
	// Condicional para distinguir si es suma o resta 
	
	if(operation == '+'){
		
		for(int i = 0; i<d ; i++){
		
		for(int j = 0; j<d; j++){
			
			mr[i][j] = m1[i][j] + m2[i][j];
			
		
		}
	}
		
		
	}
	
	else if(operation == '-'){
		
		for(int i = 0; i<d ; i++){
		
		for(int j = 0; j<d; j++){
			
			mr[i][j] = m1[i][j] - m2[i][j];
			
		
		}
	}
			
	}
	
	cout<<"			La matriz resultante es:  "<<endl<<endl;

	for(int i=0; i<d; i++){
		
		cout<<"			|";
		
		for(int j=0; j<d; j++){
			
			cout<<" "<<mr[i][j]<<" ";
			
		}
		
		cout<<" |";
		cout<<endl;
		
	}
	
	cout<<endl<<"	Que nace de operar: "<<endl<<endl;
	
		for(int i=0; i<d; i++){
		
		cout<<"			|";
		
		for(int j=0; j<d; j++){
			
			cout<<" "<<m1[i][j]<<" ";
			
		}
		
		cout<<" |";
		cout<<endl;
		
	}
	
	cout<<endl<<"			...con"<<endl<<endl;
	
		for(int i=0; i<d; i++){
		
		cout<<"			|";
		
		for(int j=0; j<d; j++){
			
			cout<<" "<<m2[i][j]<<" ";
			
		}
		
		cout<<" |";
		cout<<endl;
		
	}
	
	cout<<endl;
	cout<<"			";
	system("pause");

}


char S_or_R(){
	
	char opc;
	
	do{
		system("cls");
		
		cout<<"			_______________________________________________________"<<endl;
		cout<<"			|                                                      |"<<endl;
		cout<<"			|  *Desea sumar o restar?                              | "<<endl;
		cout<<"			|                                                      |"<<endl;		
		cout<<"			|  (1) Sumar                                           |"<<endl;
		cout<<"			|  (2) Restar                                          |"<<endl;
		cout<<"			|                                                      |"<<endl;					
		cout<<"			--------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
			system("cls");		
			return '+';
			break;
			
			case '2':
			system("cls");		
			return '-';
			break;

			default:
			cerr<<"	ERROR, INTENTE DE NUEVO!"<<endl;
			break;
		}
		
	}while(opc!='1' || opc!='2');

	
}


void Matrix_menu(){
	
	char opc;

	do{
		system("cls");
		
		cout<<"			_______________________________________________________"<<endl;
		cout<<"			|                                                      |"<<endl;
		cout<<"			|        Saludos! Bienvenido a este programa           |"<<endl;
		cout<<"			|         de practica que se encarga de sumar          |"<<endl;
		cout<<"			|         o restar matrices hasta de orden 9x9         |"<<endl;
		cout<<"			|                                                      |"<<endl;			
		cout<<"			|  *Presione el numero asociado al orden deseado.      | "<<endl;
		cout<<"			|                                                      |"<<endl;		
		cout<<"			|  (1).-  2x2                                          |"<<endl;
		cout<<"			|  (2).-  3x3                                          |"<<endl;
		cout<<"			|  (3).-  4x4                                          |"<<endl;
		cout<<"			|  (4).-  5x5                                          |"<<endl;
		cout<<"			|  (5).-  6x6                                          |"<<endl;
		cout<<"			|  (6).-  7x7                                          |"<<endl;
		cout<<"			|  (7).-  8x8                                          |"<<endl;
		cout<<"			|  (8).-  9x9                                          |"<<endl;
		cout<<"			|  (8).-  10x10                                        |"<<endl;
		cout<<"			|  (9).-  11x11                                        |"<<endl;
		cout<<"			|  (0).-  Salir                                        |"<<endl;		
		cout<<"			|                                                      |"<<endl;					
		cout<<"			--------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
				
			system("cls");
					
			M_Calculator(2, S_or_R());
			
			break;
			
			case '2':
				
			system("cls");	
				
			M_Calculator(3, S_or_R());
			
			break;
			
			case '3':
				
			system("cls");
					
			M_Calculator(4, S_or_R());
		
			break;
			
			case '4':
				
			system("cls");
					
			M_Calculator(5, S_or_R());
	
			break;
			
			case '5':
				
			system("cls");
					
			M_Calculator(6, S_or_R());
		
			break;
			
			case '6':
				
			system("cls");
					
			M_Calculator(7, S_or_R());
	
			break;
			
			case '7':
				
			system("cls");
					
			M_Calculator(8, S_or_R());
	
			break;												
			
			case '8':
				
			system("cls");	
				
			M_Calculator(9, S_or_R());
	
			break;			
			
			case '9':
				
			system("cls");
					
			M_Calculator(9, S_or_R());
	
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