#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

struct ponto{
	int x,y;};

int main(){
	int x,y,i,j,cont=0;
	ponto aux,aux2;
	int tl=0,tc=0;
	string str;
	queue<ponto> q;
	string::iterator it;
	char matriz[100][100];

	//inicializar a matriz so com espaços
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			matriz[i][j]=' ';

	//ler
	cin>>y>>x; //estou a pegar os 1os dois valores
	i=0;
	getline(cin,str);
	str.clear();
	while(getline(cin,str)){ //estou a ler linha por linha e a colocar numa matriz
		if(!str.empty()){
			j=0;
			tl++;
			for(it=str.begin();it != str.end();it++){
				matriz[i][j]=*it;
				j++;
			}
			i++;tc++;
		}
	}
	str.clear();

	

	if(x>tl || y> tc) cout<<0<<endl;
	else{
		aux.x=x;
		aux.y=y;
		if(matriz[aux.x][aux.y]==' '){
			q.push(aux);
			cont++;
		}
		while(!q.empty()){
			aux2=q.front();
			if(matriz[aux2.x][(aux2.y)+1]==' '){
				aux=aux2;
				aux.y=aux.y+1;
				q.push(aux);
				cont++;
				matriz[aux2.x][(aux2.y)+1]='#';
			}
			if(matriz[aux2.x][(aux2.y)-1]==' '){
				aux=aux2;
				aux.y=aux.y-1;
				q.push(aux);
				cont++;
				matriz[aux2.x][(aux2.y)-1]='#';
			}
			if(matriz[(aux2.x)-1][aux2.y]==' '){
				aux=aux2;
				aux.x=aux.x-1;
				q.push(aux);
				cont++;
				matriz[(aux2.x)-1][aux2.y]='#';
			}
			if(matriz[(aux2.x)+1][aux2.y]==' '){
				aux=aux2;
				aux.x=aux.x+1;
				q.push(aux);
				cont++;
				matriz[(aux2.x)+1][aux2.y]='#';
			}
			matriz[aux2.x][aux2.y]='#';
			q.pop();
		}
	}

	//imprimir a matriz
	for(i=0;i<25;i++){
		for(j=0;j<25;j++){
			cout<< matriz[i][j];
		}
		cout<<endl;
	}

	cout<<'\n'<<cont<<endl;


}











