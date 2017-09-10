/*	CARACTERISTICAS
-Programa para solo 4 variables ( a , b, c, d) **
-No se repiten las variables ***
-Los valores de las variables estan predefinidas por orden alfabetico ('a' siempre tendra el mismo valor sin importar el lugar donde aparezca)
-
-Demaciadas condiciones para un programa, le quita la utilidad ***
**** EL ORDEN DE LOS NUMEROS DEBERIA SER CRUCIAL PARA QUE EL RESULTADO SEA CORRECTO (101 != 110)
***** NO ES POSIBLE SABER SI EL RESULTADO FINAL ESTA EN EL ORDEN CORRECTO AL SER TAN ARBITRARIOS LOS VALORES
*/
#include <iostream>
using namespace std;
 
char variables[]={'a','b','c','d'};//4-variables
char operadores[]={'&','|','~','^'};//2-parentesis y 4-operadores
char parentesis[]={'(',
int num_exp=0;

void expresiones(char expresion[],int num_exp){
 	int ind_exp[num_exp];
 	for (int a=0; a<num_exp;a++){
 		for (int i=0; i<20;i++){
 			if (expresion[i]==')')
 				
 		}
 	}
	
	return;
}

void operador(){
	switch (x) 
		case '~':	;
		case '&':	;break;
		case '|':	;break;
		case '^':	;break;
		default:; 			
	return;
}

bool sintasis(char expresion[],int tam_exp,int& num_exp){

	for (int i=0; i<tam_exp;i++){
		for (int j=0; j<7;j++){
			if (j==6)
				return 0;
			else if ((expresion[i]==variable[j])||(expresion[i]==operadores[j]))
				break;
			else if((expresion[0]==operadores[j])||(expresion[tam_exp-1]==operadores[j]))
				return 0;
			else if(expresion[i]==')')
				num_exp++
		}
	}return 1;
}

int fun_tam_exp(char expresion[]){
	for (int i=0; i<50;i++){
		if (expresion[i]==';')
			return i;
	}return 0;
}
int main(){
	char expresion[50];
	cout << "Ingrese una expresion logica y...\n" << "AL FINAL DE LA EXPRESION COLOQUE ';'(PUNTO Y COMA):\n"; cin >> expresion;
	int tam_exp = fun_tam_exp(expresion[]);
	if (tam_exp > 0){
		if (sintasis(expresion[],tam_exp,num_exp)==1){
			expresiones(
			operador(
			for (int i=0; i<20;i++)
				cout << expresion[i]<<"  extra\n";
		}
		else 
			cout << "Expresion invalida";
	}
	else 
		cout << "Falta el ';' al final de la expresion";
	return 0;
}//     ~(~(a&b)|~c&(~d))     # 18
