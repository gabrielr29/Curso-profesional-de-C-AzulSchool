#include <iostream>
#include <conio.h>

using namespace std;

bool isNumberInt(const string& str);
int comprobador(string number, string msj);
void mult_Tables(int table, int max);
void tables_menu();

int main(){
	
	
	tables_menu();
	
	return 0;
	
}

bool isNumberInt(const string& str){
    return str.find_first_not_of( "0123456789" ) == string::npos;
}

int comprobator(string number, string msj){
	
	bool exit=true;
	long long int n;
	
	do{
	
	cout<<"		"<<msj;
	cin>>number;
			
	if(isNumberInt(number)){
		
	n=stoi(number);
	
 	if(n>100){
 		system("cls");
 		cerr<<"\n"<<"  	Numero invalido, max 100"<<"\n";
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
	cerr<<"\n"<<"  	Numero invalido, solo se permiten enteros no negativos, presione una tecla para volver a intentar"<<"\n";	
	
	getch();
	
	}
			
	}while(exit);
	
}


void mult_Tables(int table, int max){

	for(int i = 1; i <= max ; i++){
		
		cout<<"			"<<table<<" x "<<i<<" = "<<table*i<<endl;
			
	}

} 


void tables_menu(){
	
	char opc;
	int table = 0, max = 0;
	string n, m;

	do{
		system("cls");
		
		cout<<"			_______________________________________________________"<<endl;
		cout<<"			|                                                      |"<<endl;
		cout<<"			|        Saludos! Bienvenido a este programa           |"<<endl;
		cout<<"			|         de practica, que muestra tablas de           |"<<endl;
		cout<<"			|             multiplicacion (max 100)                 |"<<endl;
		cout<<"			|                                                      |"<<endl;			
		cout<<"			|       *Ingrese el numero de la tabla a mostrar:      |"<<endl;
		cout<<"			|        y luego el limite hasta el que desea que      |"<<endl;
		cout<<"			|         se muestre, ejemplo: Tabla: 5, max:10        |"<<endl;
		cout<<"			|          mostrara la tabla del 5 hasta 5x10.         |"<<endl;
		cout<<"			|                                                      |"<<endl;
		cout<<"			--------------------------------------------------------"<<endl;
		cout<<"			>>";
		cout<<"\n";
				
			table = comprobator(n,"			Ingrese el numero: ");
			
			max = comprobator(m, "			Ingrese el limite: ");
			
			system("cls");
			
			cout<<"				La tabla elegida fue "<<table<<" y el limite sera "<<max<<":"<<endl<<endl;
			
			mult_Tables(table, max);
				
			do{
				
			cout<<endl<<"			Desea ver mas tablas? (y/n)"<<endl;
			
			opc = getch();
			
			}while(opc!='Y' && opc!='y' && opc!='n' && opc!='N');
				
	}while(opc!='n' && opc!='N');

	
}
