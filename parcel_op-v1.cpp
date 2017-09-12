/*	CARACTERISTICAS
-Programa para solo 4 variables ( a , b, c, d) **
-No se deben repetir las variables ***
-Los valores de las variables estan predefinidas por orden alfabetico ('a' siempre tendra el mismo valor sin importar el lugar donde aparezca)
EL RPOGRMA FUNCIONA HASTA ESTE PUNTO PERO AUN NO REALIZA LAS OPERACIONES: LO QUE HACE ES DAR UN PEQUENO DESCARTE EN CUANTO A LA SINTASIS 
ADEMAS DE GENERAR TODA LA SECUENCIA DE OPERACIONES QUE SE DEBE REALIZAR PARA OBTENER EL RESULTADO
*/
#include <iostream>
#include <vector>//se usa vectores para lograr modificar los elementos y tamano de la expresion logica
using namespace std;
 
char variables[]={'a','b','c','d'};//4-variables * 16 variables
//char variable [5][32];
//variable [0]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};//  1/1
//variable [1]={1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0};//  2/2
//variable [2]={1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};//  4/4
//variable [3]={1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};//  8/8
//variable [4]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};// 16/16
char operadores[]={'~','&','|','^'};// 4-operadores
char parentesis[]={'(',')','[',']'};//2-parentesis
int num_exp;
vector <char> expresion; //La expresion logica en vector
int ind_exp;
vector <char> sub_exp;

int fun_tam_exp(char exp[]){//para conococer el tamano de la funcion, de array a vector
	for (int i=0; i<50;i++){//hacer un while seria peligroso, tal vez no ingresa ';' y seria infinito
		if (exp[i]==';')//para saber el tamano del array
			return i+1;
		else 
			expresion.push_back(exp[i]);//es la forma mas rapida de realizar las operaciones siguientes *usando algo dinamico como es los vectores
	}return 0;
}

int aux_ind(){//da el indice del primer caracter ')' Esta funcion es llamada varias veces* ya que la expresion es modificada
	for (int i=0; i<expresion.size();i++){
		if(expresion[i]==')')
			return i;
	}
	return 0;
}

int aux_num_exp(){//da el numero de agrupaciones con parentesis
	int x;//necesario para saber cuantas sub operaciones se realizara
	for (int i=0; i<expresion.size();i++){
		if(expresion[i]==')')
			x+=1;
	}return x;
}
//las 2 funciones de arriba se parecen mucho pero no se me ocurrio algo mejor .. ??
int expresiones(){//GENREA LA SECUENCIA DE OPERACIONES QUE SE DEBE REALIZAR PARA DAR UN RESULTADO CORRECTO EN CUANTO A PARENTESIS/AGRUPACIONES
	num_exp = aux_num_exp();
 	for (int a=0; a<num_exp+1;a++){//
		int aux = aux_ind();
		while ((expresion[aux]!='(')&&(aux>0)){//para identificar una sub-operacion se usa el indice de ')' hasta llegar al '(' de forma regresiva
			sub_exp.push_back(expresion[aux-1]);//agrega los elementos que estan antes del '(' hasta despues del '('
			expresion.erase(expresion.begin()+aux);//quita los elementos del vector hasta que termine el while
			aux-=1;//necesario para recorrer el vector
			cout <<aux<<endl;
		}
		expresion[aux]='x';//al quitar los elementos queda un sombrante que es el '(' con indice aux.. y es replazado por un nuevo elemento 
		//operaciones(sub_exp);  // la nueva variable estara en realcion con los resultados que se obtenga de sub-proceso 
	}return 1;
}
//     Operacion de binarios con un for y "&","|", y demas.. teniendo en cuenta la prioridad de los operadores****
//void operaciones(){
//
//	switch (x) 
//		case '~':	;
//		case '&':	;break;
//		case '|':	;break;
//		case '^':	;break;
//		default:; 			
//	return;
//}

bool sintasis(int tam_exp){//condicionales para que la expresion sea correcta
	int x=0;
	for (int i=0; i<tam_exp;i++){//un for de for para igualar elemento por elemento con las variables y demas
		for (int j=0; j<4;j++){
			int aux=1;
			if ((expresion[i]!=variables[j])||(expresion[i]!=operadores[j])||(expresion[i]!=parentesis[j])){
				x+=1;//suma la cantidad de desigualdades entre elemento de la expresion con todas las variables operadores y parentesis
			}else if((expresion[0]==')')||(expresion[tam_exp-1]==operadores[j])){
				return 0;
		}}
	}if (x==4) return 0;//si llega a 4 desigualdades significa que ninguna de los caracteres ingresados es valido
	return 1;//solo regresa 1 si la expresion esta escrita correctamente ---> falta mas condiciones
}

int main(){
	char exp[50];
	cout << "Ingrese una expresion logica y...\n" << "AL FINAL DE LA EXPRESION COLOQUE ';'(PUNTO Y COMA):\n"; cin >> exp;
	int tam_exp = fun_tam_exp(exp);
	if (tam_exp > 1){//solo para comprobar que se ingreso el caracter de 'fin' que es el ';' punto y coma
		if (sintasis(tam_exp)==1){//si la expresion esta correctamente escrita recien inicia las operaciones
			cout << expresiones();
			expresiones();
			//operador()
//			for (int i=0; i<20;i++) //Para imprimir los resultados 
//				cout << expresion[i]<<"  extra\n";
		}
		else //si no esta bien escrita envia este aviso y ya no realiza mas operaciones
			cout << "Expresion invalida";
	}
	else 
		cout << "Falta el ';' al final de la expresion";
	return 0;
}//     ~(~(a&b)|~c&(~d))     # 18

//mi meta era que reconozca y opere una expresion similar a ""~(~(a&b)|~c&(~d))"" ademas de que rechace operaciones como 
// -- "&a" -- "))((a&b" -- "a&&b" -- "a~" --
