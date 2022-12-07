/* Practicas AZULWEB CURSO GRATUITO
	
	Escriba un programa en C++ que determine cuanto dinero
	puede ahorrarse cada mes para comprar un nuevo TV. El 
	programa debera permitirle introducir los gastos mensuales
	siguientes: gastos de la casa, comida, combustible, seguro,
	y ropa. Determine que podra ahorrar 200 pesos cada mes para su televisor
	unicamente cuando tenga al menos 300 pesos disponibles  despues de pagar 
	todos los gastos.

*/

#include <iostream>

using namespace std;

int main(){
	
	float savings, income, cHouse, cCar, cFood, cFuel, cSeguro, cClothes, cTotal;

		cout<<"Cuantos es su ingreso del mes (pesos)?"<<endl;
		cin>>income;
		
		cout<<"Cuanto el el gasto de la casa?"<<endl;
		cin>>cHouse;
		
		cout<<"Cuanto el el gasto del coche?"<<endl;
		cin>>cCar;
		
		cout<<"Cuanto es el gasto en comida?"<<endl;
		cin>>cFood;
		
		cout<<"Cuanto es el gasto en combustible?"<<endl;
		cin>>cFuel;
	
		cout<<"Cuanto es el gasto en seguro?"<<endl;
		cin>>cSeguro;
		
		cout<<"Cuanto es el gasto en ropa?"<<endl;
		cin>>cClothes;
		
		cTotal = cHouse + cCar + cFood + cFuel + cSeguro + cClothes;
		
		savings = income - cTotal;
		
		cout<<endl<<"Sus ingresos del mes son: "<<income<<endl;
		cout<<"Sus ahorro del mes es: "<<savings<<endl;
		cout<<"Sus gastos totales son: "<<cTotal<<endl;
		
		if(savings>=300){
			cout<<"Con los datos proporcionados se determino que es posible ahorrar 200 pesos "<<
			"para el televisor."<<endl;
		}
		else{
			cout<<"Con los datos proporcionados se determino que no es posible ahorrar 200 pesos "<<
			"para el televisor."<<endl;
		}
		
		return 0;
		
}