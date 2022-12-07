#include <iostream>
#include <conio.h>
#include <string.h>


using namespace std;

//Declaracion de variables

char name[20][40];
char subject1[20][3], subject2[20][3], subject3[20][3], subject4[20][3], subject5[20][3];
char n_Subject[5][40];
int student_Counter = 0;

//Declaracion de funciones

string ToString(int n);
bool IsNInt_Array(char pal[]);
bool name_Validator(char name[][40],int cont);
void name_colecter();
void Show_Students();
void Show_Subject(int counter, string msj, int student_ID);
void Validator_N(int counter, int max, int min, string msj, bool Tsubject_FstudentOrNsubject,char copy_array[3]);
void subject_selector(int counter, char note[3],int student_ID);
void Notes_Colect(bool mod_request);
void Subject_Name_Colect();
void interfaz_Colect(string accion);
void menu();



int main(){
	
menu();
	
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
		case 10:
			return "10";
			break;
		case 0:
			return "0";
			break;
		default:
			return "error";
			break;
	}	
}


bool IsNInt_Array(char pal[]) //Devuelve True si todos los caracteres son numeros
{
     int i;
     for(i=0;pal[i]!='\0'&&pal[i]>='0'&&pal[i]<='9';i++);
     if(pal[i]!='\0') return false;
     else return true;     
}

bool name_Validator(char name[][40],int cont){
	
    int i,j;
	
	for(i=0; name[cont][i] != '\0' ; i++){
		
		if(name[cont][i] >='a' && name[cont][i] <= 'z' || name[cont][i] >='A' && name[cont][i] <= 'Z'){
			
			return true;
			
		}
				
	}
		
//RETORNA 0 SI NO ESTA EN EL RANGO A-Z || a-z

return false;

}

void interfaz_Colect(string accion){
	
	system("cls");
		
	cout<<"			------------------------------------------------------------"<<endl;
	cout<<"			       Bienvenido a este gestor de notas y promedios          "<<endl;
	cout<<"			                                                            "<<endl;
	cout<<"			       "<<accion<<endl;
	cout<<"			 ___________________________________________________________"<<endl;
	
	cout<<"			>> ";
	
}

void name_colecter(){
		
	/*
	
	Bucle para registrar el nombre del estudiante, se apoya en el comprobador
	y valida que no se registren mas de los solicitados en el enunciado.
	
	
	*/
	
	do{
		
	if(student_Counter == 20){
		
		cerr<<endl<<"		Error! limite de estudiantes alcanzado."<<endl<<"			";
		system("pause");
			
	}
	
	else{
		
	interfaz_Colect("Ingrese el nombre del estudiante.");
	cin.getline(name[student_Counter],40);
	
	if(!name_Validator(name,student_Counter)){
		
		cerr<<endl<<"		Error! Caracteres no permitidos"<<endl<<"			";
		system("pause");
	}	
	
	else{
		//Aca no se interrumpe el bucle pero tampoco se aumenta el contador para no duplicar el aumento con la funcion que colecta las notas.
	}
	
	}
			
	}while(!name_Validator(name,student_Counter));

}

void Show_Subject(int counter, string msj, int student_ID){
	
			switch(counter){
			
			case 0:

			cout<<"			"<<"La materia "<<n_Subject[counter]<<" con "<<"("<<subject1[student_ID]<<")"<<" "<<msj;
			
			break;	
			
			case 1:
				
			cout<<"			"<<"La materia "<<n_Subject[counter]<<" con "<<"("<<subject2[student_ID]<<")"<<" "<<msj;
			
			break;	
						
			case 2:
		
			cout<<"			"<<"La materia "<<n_Subject[counter]<<" con "<<"("<<subject3[student_ID]<<")"<<" "<<msj;
			
			break;	
			
			case 3:

			cout<<"			"<<"La materia "<<n_Subject[counter]<<" con "<<"("<<subject4[student_ID]<<")"<<" "<<msj;
			
			break;	

			case 4:
		
			cout<<"			"<<"La materia "<<n_Subject[counter]<<" con "<<"("<<subject5[student_ID]<<")"<<" "<<msj;
		
			break;	
		}
	
}

void Show_Students(){
	
	float general_Av = 0;
	int mayor = 0;
	int menor = 10;
	int aux = 0, aux2 = 0;
		
	cout<<endl<<endl<<"			_________________________________________________________________________"<<endl<<endl;
	cout<<"			Estudiantes registrados y sus respectivas notas y promedios: "<<endl<<endl;
	
	for(int i=0; i<student_Counter; i++){
		
		
		
		
		cout<<"			"<<"Estudiante N#"<<i+1<<"-->"<<name[i]<<" : "<<endl<<"			"<<"I.- "<<n_Subject[0]<<" "<<"("<<subject1[i]<<")"<<
		" --"<<"II.- "<<n_Subject[1]<<" "<<"("<<subject2[i]<<")"<<" --"<<"III.- "<<n_Subject[2]<<" "<<"("<<subject3[i]<<")"<<endl;
		
		cout<<"			"<<"IV.- "<<n_Subject[3]<<" ("<<subject4[i]<<")"<<" --"<<"V.- "<<n_Subject[4]<<" "<<"("<<subject5[i]<<")"<<endl;
		
		cout<<"			"<<"Promedio: "<<((stof(subject1[i])+stof(subject2[i])+stof(subject3[i])+stof(subject4[i])+stof(subject5[i]))/5)<<endl;
		
		if(mayor<stoi(subject1[i])){
			mayor = stoi(subject1[i]);
			aux = 0;
		}
		if(mayor<stoi(subject2[i])){
			mayor = stoi(subject2[i]);
			aux = 1;
		}
		if(mayor<stoi(subject3[i])){
			mayor = stoi(subject3[i]);
			aux = 2;
		}
		if(mayor<stoi(subject4[i])){
			mayor = stoi(subject4[i]);
			aux = 3;
		}
		if(mayor<stoi(subject5[i])){
			mayor = stoi(subject5[i]);
			aux = 4;
		}
		
		Show_Subject(aux,"es en la que le va mejor.",i);
		cout<<endl;
	
		if(menor>stoi(subject1[i])){
			menor = stoi(subject1[i]);
			aux2 = 0;
		}
		if(menor>stoi(subject2[i])){
			menor = stoi(subject2[i]);
			aux2 = 1;
		}
		if(menor>stoi(subject3[i])){
			menor = stoi(subject3[i]);
			aux2 = 2;
		}
		if(menor>stoi(subject4[i])){
			menor = stoi(subject4[i]);
			aux2 = 3;
		}
		if(menor>stoi(subject5[i])){
			menor = stoi(subject5[i]);
			aux2 = 4;
		}
		
		Show_Subject(aux2,"es en la que le va peor.",i);
		cout<<endl<<endl;
		// Calculo del promedio 
		general_Av += ((stof(subject1[i])+stof(subject2[i])+stof(subject3[i])+stof(subject4[i])+stof(subject5[i]))/5);
			
		cin.clear();
		
	}
	
	if(student_Counter==1){	}
	else{
	general_Av = general_Av/(student_Counter);			
	}
	
	cout<<"			El promedio general es: "<<general_Av<<endl;
	cout<<"			_________________________________________________________________________"<<endl;
		
}

void Validator_N(int counter, int max, int min, string msj, bool Tsubject_FstudentOrNsubject,char copy_array[3]){
	
	char note[3]; 	
	bool flag = false;
	
	do{
		
	// Llamado a la funcion "interfaz_Colect" que muestra un recuadro con la informacion sobre que datos se solicitan.	
		
	interfaz_Colect(msj);
	
	/*
	
	Primer if para saber si se quiere validar un numero a manera de ID
	para un estudiante (funcion asociada a la modificacion de datos). o
	quiere registrar una nota de una materia. El false tambien sirve para
	saber cual materia del 1 al 5 quiere modificar.
		
	
	*/
	
	if(Tsubject_FstudentOrNsubject){
			
	cout<<n_Subject[counter];
	cout<<endl<<"			>>";
		
	}
	else{
	
	Show_Students();
	cout<<endl<<"			>>";	
	}
	
	
	cin.getline(note,3);
	cin.clear();
	
	// Validacion de la nota (debe ser un entero positivo)
	
	if(!IsNInt_Array(note)){
		
		cerr<<endl<<"		Error! Caracteres no permitidos."<<endl<<"			";
		system("pause");
		flag = false;
		
	}
	
	else if(stof(note)>max || stof(note)<min){
		
		cerr<<endl<<"		Error! Se sale del rango "<<min<<" "<<"-"<<max<<endl<<"			";
		system("pause");	
		flag = false;
		
	}
	
	else{
		
		flag = true;
		strncpy(copy_array,note, 3);
		
	}	
			
		
	}while(!flag);
	

	
}

void subject_selector(int counter, char note[3],int student_ID){
	
			switch(counter){
			
			case 0:

			strncpy(subject1[student_ID],note,3);
			
			break;	
			
			case 1:
				
			strncpy(subject2[student_ID],note,3);
			
			break;	
						
			case 2:
		
			strncpy(subject3[student_ID],note,3);
			
			break;	
			
			case 3:

			strncpy(subject4[student_ID],note,3);
			
			break;	

			case 4:
		
			strncpy(subject5[student_ID],note,3);
		
			break;	
		}
		
}

void Notes_Colect(bool mod_request){
	
	int counter = 0;
	char note[3]; 
	char n_student[3];
	char subject[3];
	
	/*
	
	Bucle para registrar las notas de cada materia, se apoya en el comprobador
	y valida que no se pase del rango 0-10.
		
	*/
	
	if(!mod_request){
		
		do{

		Validator_N(counter, 10,0,"Ingrese la nota correspondiente a ", true, note);
		
		subject_selector(counter, note, student_Counter);
		
		counter++;
		cin.clear();
		
		//Una vez se realicen todos los registros, el student_Counter debe aumentar tambien
		//char subject1[20][3], subject2[20][3], subject3[20][3], subject4[20][3], subject5[20][3];

		}while(counter!=5);
		
		student_Counter++;
					
	}
	
	else{
						
		Validator_N(0, 20,1,"Ingrese el numero asociado al estudiante cuya nota desea modificar", false,n_student);
		
		Validator_N(0,5,1,"Ingrese el numero asociado a la materia cuya nota desea modificar (1-5): ",false,subject);
		
		Validator_N(stoi(subject)-1,10,0,"Ingrese la nota correspondiente a ",true,note);
		
		subject_selector(stoi(subject)-1, note, stoi(n_student)-1);
		
	}
	
}

void Subject_Name_Colect(){
	
	/*
	
	Bucle para registrar el nombre de las materias, se apoya en el comprobador
	y valida que no se registren materias de nombre demasiado largo
		
	*/
	
	int counter_s = 0;
	
	do{
					
	interfaz_Colect(("Ingrese el nombre de la materia n#" + ToString(counter_s+1)));
	cin.getline(n_Subject[counter_s],25);
	
	if(!name_Validator(n_Subject,counter_s)){
		
		cerr<<endl<<"		Error! Caracteres no permitidos."<<endl<<"			";
		system("pause");
		
	}
	
	else if(strlen(n_Subject[counter_s])>25){
		
		cerr<<endl<<"		Error! Demasiados caracteres."<<endl<<"			";
		system("pause");	
		
	}	
	
	else{
		counter_s++;
		cin.clear();
	}
					
	}while(counter_s!=5);
	
	for(int i=0; i<5; i++){
		cout<<"			Materia N#"<<i+1<<" "<<n_Subject[i]<<endl;
	}
	cout<<"				";
	system("pause");
	
}

void menu(){
	
	char opc;

	do{
		system("cls");
		
		cout<<"			_______________________________________________________"<<endl;
		cout<<"			|                                                      |"<<endl;
		cout<<"			|        Saludos! Bienvenido a este programa           |"<<endl;
		cout<<"			|       de practica que se encarga de registrar        |"<<endl;
		cout<<"			|        notas de estudiantes para promediarlas        |"<<endl;
		cout<<"			|           mostrar la mayor, menor y mas.             |"<<endl;
		cout<<"			|                                                      |"<<endl;
		cout<<"			|                                                      |"<<endl;							
		cout<<"			|  *Presione el numero asociado al orden deseado.      | "<<endl;
		cout<<"			|                                                      |"<<endl;		
		cout<<"			|   1.- Agregar estudiantes                            |"<<endl;
		cout<<"			|   2.- Mostrar listado de estudiantes                 |"<<endl;
		cout<<"			|   3.- Modificar notas de un estudiante               |"<<endl;
		cout<<"			|                                                      |"<<endl;						
		cout<<"			|  (0).-  Salir                                        |"<<endl;		
		cout<<"			|                                                      |"<<endl;					
		cout<<"			--------------------------------------------------------"<<endl;
									
		opc = getch();
				
		switch(opc){
			
			case '1':
				
			system("cls");
			
			if(student_Counter == 0){
				
				Subject_Name_Colect();
				name_colecter();
				Notes_Colect(false);
				
			}		
			
			else{
				
				name_colecter();
				Notes_Colect(false);
				
			}
			
			break;
			
			case '2':
				
			system("cls");	
			
			if(student_Counter==0){
				
				cerr<<"			ERROR: Aun no ha registrado a ningun alumno."<<endl<<"			";
				cout<<"			";
				system("pause");
			}
			
			else{
				
			Show_Students();
			cout<<"			";
			system("pause");
							
			}
							
			break;
			
			case '3':
				
			system("cls");
			
			if(student_Counter==0){
				
			cerr<<"			ERROR: Aun no ha registrado a ningun alumno."<<endl<<"			";
			cout<<"			";
			system("pause");
			
			}
			
			else{
					
			Notes_Colect(true);
			
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