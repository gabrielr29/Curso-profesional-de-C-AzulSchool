#include <iostream>
#include <conio.h>
#include <string.h>
#include <charconv>

using namespace std;

// Declaracion de variables globales

char name_movie[20][50];
int movie_years[20];
int movie_Counter = 0;

// Declaracion de funciones

int validar_numero(char b[]);
int validar_nombre(char nombre[][50],int cont);
void interfaz_Colect(string accion);
void movie_colecter();
void order(bool Tnew_or_Fold);
void menu();
void search_Year();


int main(){

 menu();
 
}

void interfaz_Colect(string accion){
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			       Bienvenido a este gestor de peliculas                "<<endl;
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

void movie_colecter(){
		
	/*
	
	Bucle para registrar el nombre y year de lanzamiento de la
	cada pelicula.
	
	*/
	
	char year_aux[20];
	
	do{
		
	if(movie_Counter == 20){
		
		cerr<<endl<<"		Error! limite de peliculas alcanzado."<<endl<<"			";
		system("pause");
			
	}
	
	else{
	
	cin.clear();	
		
	interfaz_Colect("Ingrese el nombre de la pelicula.");

	cin.getline(name_movie[movie_Counter],40);
	
	if(!validar_nombre(name_movie,movie_Counter)){
		
		cerr<<endl<<"		Error! Caracteres no permitidos"<<endl<<"			";
		system("pause");
	}
	
	else{
		
		do{
			cin.clear();
			
			interfaz_Colect("Ingrese el year de lanzamiento de la pelicula: " );
			
			cin.getline(year_aux,5);
		
			if(!validar_numero(year_aux)){
			
			// El validador tiene su propio mensaje de error
		
			cout<<endl<<"				";
			system("pause");
		
		
			}
		
			else if(stof(year_aux)>2100 || stof(year_aux)<1895){
		
			cout<<endl<<"				El year esta fuera del rango 1895 (Primera <pelicula> del mundo) y 2100"<<endl;
			
			system("pause");
			
			}
		
			else{
			
			movie_years[movie_Counter] = stof(year_aux);
		
			movie_Counter++;
					
			cout<<"			Registro exitoso..."<<endl<<"				";
			
			system("pause");

			
			}
			
			
			}while(!validar_numero(year_aux) || stof(year_aux)>2100 || stof(year_aux)<1895);
		
		}

		}
			
	}while(!validar_nombre(name_movie,movie_Counter) && !validar_numero(year_aux));

	
	

}

void order(bool Tnew_or_Fold){

	int aux = 0;
	char aux2[50];
	
	
	//Ordenamiento doble con metodo burbuja
	
	if(Tnew_or_Fold){
		
	for(int i=0; i<movie_Counter -1 ; i++){
		
	for(int j=0; j<movie_Counter -1; j++){
		
		if(movie_years[j] < movie_years[j+1]){
			
		//Ordenando los years	
			
		aux = movie_years[j];
		
		movie_years[j] =  movie_years[j+1];
		
		movie_years[j+1] = aux;
		
		
		// Ordenando los nombres con la función strncpy
		
		strncpy(aux2,name_movie[j],50);
		
		strncpy(name_movie[j],name_movie[j+1],50);
		
		strncpy(name_movie[j+1],aux2,50);

		}
			
	}
	
	}
		
		
	}
	
	else{
		
	for(int i=0; i<movie_Counter -1 ; i++){
		
	for(int j=0; j<movie_Counter -1; j++){
		
		if(movie_years[j] > movie_years[j+1]){
			
		//Ordenando los years	
			
		aux = movie_years[j];
		
		movie_years[j] =  movie_years[j+1];
		
		movie_years[j+1] = aux;
		
		
		// Ordenando los nombres con la función strncpy
		
		strncpy(aux2,name_movie[j],50);
		
		strncpy(name_movie[j],name_movie[j+1],50);
		
		strncpy(name_movie[j+1],aux2,50);

		}
			
	}
	
		
	}
	

	
}

}

void search_Year(){
	
	char year_aux[5];
	
	/*
	
	  Bucle para listar peliculas que cumplan con el criterio de busqueda
	 se apoya en funcion strncmp para la comparacion del year recibido por teclado.
		
	*/
	
		do{
			
			interfaz_Colect("Ingrese el year de lanzamiento de las peliculas que desea listar: " );
			
			cin.getline(year_aux,5);		
			
			if(!validar_numero(year_aux)){
			
			// El validador tiene su propio mensaje de error
		
			cout<<endl<<"				";
			system("pause");
		
		
			}
			
			else if(stof(year_aux)>2100 || stof(year_aux)<1895){
		
			cout<<endl<<"				El year esta fuera del rango 1895 (Primera <pelicula> del mundo) y 2100"<<endl;
			cout<<"			";
			system("pause");
			
			}	
			
			else{
				
				int aux = stof(year_aux);
			
					cout<<endl<<endl<<"			_________________________________________________________________________"<<endl<<endl;
					cout<<"			Peliculas registradas que cumplen con el criterio de busqueda: "<<endl<<endl;
					
				for(int i=0; i<movie_Counter; i++){
						
				if(aux == movie_years[i]){
					
				cout<<"			"<<"Nombre de la pelicula: "<<name_movie[i]<<" -- "<<"Publicada en: "<<movie_years[i]<<endl<<endl;
					
					
					
				}	
						
						
				}
					
	
				cout<<"			_________________________________________________________________________"<<endl;	
					
				}
			
						
			
			
		}while(!validar_numero(year_aux));
		
}


void Show_Movies(){
	
	cout<<endl<<endl<<"			_________________________________________________________________________"<<endl<<endl;
	cout<<"			Peliculas registradas y sus respectivas fechas de estreno: "<<endl<<endl;
	
	for(int i=0; i<movie_Counter; i++){
	
		cout<<"			"<<"Nombre de la pelicula: "<<name_movie[i]<<" -- "<<"Publicada en: "<<movie_years[i]<<endl<<endl;
		
	}

	cout<<"			_________________________________________________________________________"<<endl;
		
}


void menu(){
	
	char opc;

	do{
		system("cls");
		
		cout<<"			____________________________________________________________________"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|               Saludos! Bienvenido a este programa                |"<<endl;
		cout<<"			|             de practica que se encarga de registrar              |"<<endl;
		cout<<"			|              peliculas y ordenarlas segun su fecha               |"<<endl;
		cout<<"			|                          de estreno                              |"<<endl;
		cout<<"			|                                                                  |"<<endl;
		cout<<"			|                                                                  |"<<endl;								
		cout<<"			|  *Presione el numero asociado al orden deseado.                  | "<<endl;
		cout<<"			|                                                                  |"<<endl;		
		cout<<"			|   1.- Agregar peliculas.                                         |"<<endl;
		cout<<"			|   2.- Mostrar peliculas desde las mas viejas a las mas nuevas.   |"<<endl;
		cout<<"			|   3.- Mostrar peliculas desde las mas nuevas a las mas viejas.   |"<<endl;
		cout<<"			|   4.- Mostrar peliculas de un year en concreto.                  |"<<endl;		
		cout<<"			|                                                                  |"<<endl;						
		cout<<"			|  (0).-  Salir                                                    |"<<endl;		
		cout<<"			|                                                                  |"<<endl;					
		cout<<"			-------------------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
				
			system("cls");
			if(movie_Counter>=19){
				
				cerr<<"			ERROR: Se ha alcanzado el maximo de registros (20)."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			else{
				movie_colecter();
			}
				
			break;
			
			case '2':
				
			system("cls");	
			
			if(movie_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes peliculas."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			
			else{
			
			order(false);	
			Show_Movies();
			cout<<"			";
			system("pause");
							
			}
							
			break;
			
			case '3':
				
			system("cls");
			
			if(movie_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes peliculas."<<endl<<"			";
				cout<<"		";
				system("pause");
			}
			
			else{
				
			order(true);
			Show_Movies();
			cout<<"		";
			system("pause");
							
			}
		
			break;
			
			case '4':
		
			system("cls");	
			
			if(movie_Counter<=1){
				
				cerr<<"			ERROR: Aun no ha registrado suficientes peliculas."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			
			else{
			
			search_Year();
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

