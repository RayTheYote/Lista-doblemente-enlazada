#include <iostream>
using namespace std;

struct nodo{
	int valor;
	nodo *anterior;
	nodo *siguiente;
};

nodo *puntero_anterior=NULL;
nodo *puntero_inicio=NULL;
int longitud=0;

void agregar_nodo(){
	int input;
	nodo *nuevo_nodo=new nodo;
	cout<<"Ingrese el valor del nodo: ";
	cin>>input;
	system("cls");
	nuevo_nodo->valor=input;
	if(puntero_inicio == NULL){
	nuevo_nodo->anterior=puntero_anterior;
	nuevo_nodo->siguiente=NULL;
	puntero_inicio=nuevo_nodo;
	puntero_anterior=nuevo_nodo;
	}
	else{
		puntero_anterior->siguiente=nuevo_nodo;
		nuevo_nodo->siguiente=NULL;
		nuevo_nodo->anterior=puntero_anterior;
		puntero_anterior=nuevo_nodo;
	}
	longitud++;
}

void quitar_nodo(){
	int input;
	cout<<"!Los nodos se listan del 1 hasta el "<<longitud<<"!"<<endl<<endl;
	cout<<"Que nodo quiere eliminar? --> ";
	cin>>input;
	nodo *nuevo_nodo;
	nuevo_nodo=puntero_inicio;
	for(int zeta=1; zeta < input; zeta++){
		nuevo_nodo=nuevo_nodo->siguiente;
	}
	nuevo_nodo->anterior->siguiente=nuevo_nodo->siguiente;
	nuevo_nodo->siguiente->anterior=nuevo_nodo->anterior;
	delete nuevo_nodo; 
	system("cls");
	longitud--;
}

void mostrar_lista(){
	nodo *nuevo_nodo=puntero_inicio;
	cout<<"NULL --> ";
	while(nuevo_nodo != NULL){
		cout<<nuevo_nodo->valor<<" --> ";
		nuevo_nodo=nuevo_nodo->siguiente;
	}
	cout<<"NULL"<<endl;
	system("pause");
	system("cls");
}
	
void mostrar_nodo(){
	int value;
	cout<<"!Los nodos se listan del 1 hasta el "<<longitud<<"!"<<endl<<endl;
	cout<<"Que nodo quiere visualizar? --> ";
	cin>>value;
	cout<<endl; 
	nodo *nuevo_nodo;
	nuevo_nodo=puntero_inicio;
	for(int zeta=1; zeta < value; zeta++){
		nuevo_nodo=nuevo_nodo->siguiente;
	}
	cout<<nuevo_nodo->anterior->valor<<" --> ||"<<nuevo_nodo->valor<<"|| --> "<<nuevo_nodo->siguiente->valor<<endl;
	system("pause");
	system("cls");
}

inline void menu(){
	cout<<"+------------------------------+"<<endl;
	cout<<"+        Menu de opciones      +"<<endl;
	cout<<"+                              +"<<endl;
	cout<<"+ 1-Agregar nodo               +"<<endl;
	cout<<"+ 2-Quitar nodo                +"<<endl;
	cout<<"+ 3-Visualizar lista           +"<<endl;
	cout<<"+ 4-Visualizar nodo especifico +"<<endl;
	cout<<"+                              +"<<endl;
	cout<<"+------------------------------+"<<endl<<endl;
}

int main(int argc, char *argv[]) {
	system("color 0a");
	int valor;
	while(true){
		menu();
		cout<<"Elija una opcion: ";
		cin>>valor;
		system("cls");
		switch(valor){
		case 1:agregar_nodo();
		break;
		case 2:quitar_nodo();
		break;
		case 3:mostrar_lista();
		break;
		case 4:mostrar_nodo();
		break;
		case 0: return 0;
		break;
		}
	}
	return 0;
}
