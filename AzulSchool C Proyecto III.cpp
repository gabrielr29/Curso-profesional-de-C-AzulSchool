#include <iostream>
#include <conio.h>

using namespace std;

bool IsFloat(string const& numero);
void notes_calculator();
bool isNumberInt(const string& str);
int comprobator(string number, string msj, int max, int min);

int main(){
	
	notes_calculator();
	
}

bool isNumberInt(const string& str){
	
    return str.find_first_not_of( "0123456789" ) == string::npos;
    
}

int comprobator(string number, string msj, int max, int min){
	
	bool exit=true;
	long long int n;
	
	do{
	
	cout<<"		"<<msj;
	cin>>number;
			
	if(isNumberInt(number)){
		
	n=stoi(number);
	
 	if(n<min || n>max){
 		system("cls");
 		cerr<<"\n"<<"  	Numero invalido, max: "<<max<<" min: "<<min<<"\n";
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

void notes_calculator(){
	
	int n_students=0, aux = 0, aux2 = 0;
	string n_aux, n_aux2;
	double sumatoria=0, promedio=0;
	
	
	n_students = comprobator(n_aux,"Ingrese el numero de estudiantes min=20, max=30: ", 30, 20);
	
	float n1[n_students], n2[n_students];
	
	for(int i=0; i<n_students; i++){
				
		do{
			
		system("cls");	
			
		cout<<"		Ingrese la nota del estudiante numero: "<<i+1<<endl;
		cout<<"			>>";	
		
		cin>>n_aux2;
			
			if(!IsFloat(n_aux2)){
			
			cerr<<"		ERROR, PARAMETRO INVALIDO, SOLO NUMEROS"<<endl;
			getch();
				
			}
			else if(stof(n_aux2)>10 || stof(n_aux2)<0){
			
				cerr<<"		ERROR, SOLO NUMEROS DEL 0 AL 10."<<endl;
				getch();	
				
			}
			else{}
		
			
		}while(!IsFloat(n_aux2) || stof(n_aux2)>10 || stof(n_aux2)<0);
		
				
		n1[i] = stof(n_aux2);
		
	}
	

//OPCIONAL! (NO PIDE ORGANIZAR)
/*
	for(int i=0; i<n_students ; i++){
		
	for(int j=0; j<n_students ; j++){
		
		if(n1[j] > n1[j+1]){
			
		aux = n1[j];
		n1[j]=n1[j+1];
		n1[j+1]=aux;
		
		}
			
	}
	
	}	
	
	*/
	
	system("cls");

	cout<<endl;
	
	cout<<"		Los siguientes estudiantes forman parte del grupo al que se le asigno el trabajo para aumentar un punto."<<endl<<endl;
	
	for(int i=0; i<n_students; i++){
				
		if(n1[i]<=6){
		
		n2[i] = n1[i] + 1;	
		
		cout<<"		Estudiante n#"<<i<<endl;
					
		}else{
		
		n2[i] = n1[i];	
			
		}
	
		
	}
	
	cout<<endl;
	
	//Mostrar notas
	
	for(int i=0; i<n_students; i++){
	
	cout<<"		La nota promedio del alumno "<<i+1<<" es: "<<n1[i]<<endl;	
			
		
	}
	
	cout<<endl<<"		Luego de la asignacion del trabajo, las notas quedaron de la siguiente manera: "<<endl<<endl;
	
	for(int i=0; i<n_students; i++){
	
	cout<<"		La nota promedio del alumno "<<i+1<<" es: "<<n2[i]<<endl;	
			
		
	}
		
	int menor = 10, mayor = 0;
	
	//Calculan mayor promedio
	
	for(int i = 0; i < n_students; i++){
		
	if(n1[i]>mayor){
		
		mayor = n1[i];
		aux2 = i;	
	}
	
	else{
	}	
			
	}
	
	//Calcular menor promedio
	
	for(int i = 0; i < n_students; i++){
		
		
	if(n1[i]<menor){
		
		menor = n1[i];
		aux = i;
					
	}
	
	else{
	}	
			
	}
	
	//Calculo de la sumatoria y el promedio
	
	for(int i=1; i<=n_students; i++){
		
		sumatoria += n1[i];
		promedio = sumatoria / n_students;
			
	}
	
	cout<<endl<<"		El promedio total es: "<<promedio<<endl;
	cout<<"		La suma total de notas es: "<<sumatoria<<endl;
	cout<<"		El estudiante numero "<<aux+1<<" es quien tiene el menor promedio."<<endl;
	cout<<"		El estudiante numero "<<aux2+1<<" es quien tiene el mayor promedio."<<endl;
	

	
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
