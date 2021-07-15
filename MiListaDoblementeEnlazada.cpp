#include <iostream>
#include<stdio.h>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
	nodo *ant;
};


void agregarIN(nodo *&,int);
void agregarFIN(nodo *&,int);
void mostrar(nodo *&);
bool flag= 0;
int main(){
	system ("color B0");
	nodo *lista = NULL;

	agregarFIN(lista,1);
	agregarIN(lista,2);
	agregarFIN(lista,3);
	agregarIN(lista,4);
	agregarFIN(lista,5);
	agregarIN(lista,6);
	agregarFIN(lista,7);
	
	mostrar(lista);
	
	return 0;
}

void agregarIN(nodo *&lista,int n){
	nodo *aux = lista;
	nodo *aux2 = lista;
	nodo *nuevo = new nodo();
	nuevo->dato=n;
	if(lista == NULL){
		nuevo->sig=lista;
		nuevo->ant=NULL;
		
	}else{
		int contador =0;
		while(aux!=NULL){
			aux=aux->ant;
			contador ++;
		}
		while(contador>1){
			
			aux2=aux2->ant;
			contador--;
		}
		aux2->ant=nuevo;
		nuevo->sig = aux2;
		nuevo->ant = aux;
		
	}
	lista = nuevo;
	flag = 0;
	
}
void agregarFIN(nodo *&lista,int n){
	nodo *aux2 = lista;
	nodo *aux = lista;
	nodo *nuevo = new nodo();
	nuevo->dato=n;
	
	if(lista == NULL){
		nuevo->ant=lista;
		nuevo->sig=NULL;
	}
	else{
		int contador =0;
		while(aux!=NULL){
			
			aux=aux->sig;
			contador ++;
		}
		while(contador>1){
			
			aux2=aux2->sig;
			contador--;
		}
		aux2->sig = nuevo;
		nuevo->ant = aux2;
		nuevo->sig = NULL;
		
	}
	
	lista = nuevo;
	flag = 1;
	
}
void mostrar(nodo *&lista){
	nodo *aux=lista;
	if (flag == 0 ){
		while(aux!=NULL){
			cout<<aux->dato<<" ";
			aux=aux->sig;
		}
	}
	if (flag == 1 ){
		int contador = 0 ;
		while(aux!=NULL){
			aux = aux->ant;
			contador++;
		}
		aux=lista;
		while(contador>1){
			aux = aux->ant;
			contador--;
		}
		while(aux!=NULL){
			cout<<aux->dato<<" ";
			aux=aux->sig;
		}
	}
	
	
}

