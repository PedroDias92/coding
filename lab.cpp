#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <stdio.h>
#include <stdlib.h>


#define PRETO 2
#define CINZA 1
#define BRANCO 0

using namespace std;

struct Par {
	int coordX;
	int coordY;
};

bool operator< (const Par &a,const Par &b ){
	return ((a.coordX < b.coordX) || ((a.coordX == b.coordX) && (a.coordY < b.coordY)));
}

//Diskstra............................................................................................
int dijkstra(map <Par,list<Par> > grafo, Par origem, Par destino){
	queue < Par > orla;
	map < Par, int > cor;
	map < Par, int > custos;
	map < Par, int > ::iterator cs;

	list < Par > :: iterator c1;
	list <Par> caminho;
	Par aux=origem;

	cor[origem]=CINZA;
	custos[origem]=0;

	orla.push(origem);

	while(!orla.empty() && (aux.coordX!=destino.coordX || aux.coordY!=destino.coordY)){
		aux = orla.front();
		orla.pop();
		for(c1 = grafo[aux].begin(); c1!=grafo[aux].end(); c1++){
			if (cor[*c1] == BRANCO){
				cor[*c1] = CINZA;
				orla.push(*c1);
				custos[*c1]=1+custos[aux];
			}
			else {
				if(cor[*c1] == CINZA){
					if(custos[*c1] > (custos[aux] + 1)){
						custos[*c1] = custos[aux] + 1;

					}
				}

			}
		}
		cor[aux] = PRETO;

	}

	return custos[destino];
}


//main............................................................................


int main(){
	int tamanhoMatriz;
	int i,j,g,f,tamanho;
	string le;
	Par coordenada;
	Par coordenadaInicial;
	Par coordenadaFinal;
	Par coo;
	list<Par> ad;
	list<Par> ::iterator l;
	map <Par,list<Par> > graph;
	map <Par,list<Par> > :: iterator it;
	list<Par> finais;
	list<Par> ::iterator oo;

	//guarda tamanho....................................................................

	cin>>tamanhoMatriz;
	getline(cin,le);
	char matriz[tamanhoMatriz][tamanhoMatriz];

	//faz matriz.......................................................................

	for(g=0;getline(cin,le);g++){
		for(f=0;le[f]!='\0';f++){
				matriz[g][f]=le[f];
			}
		}
	
	/*for(i=0;i<tamanhoMatriz;i++){
		for(j=0;j<tamanhoMatriz;j++){
			cout<<matriz[i][j];
		}
		cout<<endl;
	}*/

	//faz grafo..........................................................................
	for(i=0;i<tamanhoMatriz;i++){
		for(j=0;j<tamanhoMatriz;j++){
				coo.coordX=j;
				coo.coordY=i;
					if(i>=0 && i<tamanhoMatriz && j-1>=0 && j-1<tamanhoMatriz && matriz[i][j-1]==' ' && matriz[i][j]==' '){
						coordenada.coordX=j-1;
						coordenada.coordY=i;
						ad.push_back(coordenada);
					}
					if(i>=0 && i<tamanhoMatriz && j+1>=0 && j+1<tamanhoMatriz && matriz[i][j+1]==' ' && matriz[i][j]==' '){
						coordenada.coordX=j+1;
						coordenada.coordY=i;
						ad.push_back(coordenada);
					}
					if(i-1>=0 && i-1<tamanhoMatriz && j>=0 && j<tamanhoMatriz && matriz[i-1][j]==' ' && matriz[i][j]==' '){
						coordenada.coordX=j;
						coordenada.coordY=i-1;
						ad.push_back(coordenada);
					}
					if(i+1>=0 && i+1<tamanhoMatriz && j>=0 && j<tamanhoMatriz && matriz[i+1][j]==' ' && matriz[i][j]==' '){
						coordenada.coordX=j;
						coordenada.coordY=i+1;
						ad.push_back(coordenada);
					}
					if(matriz[i][j]==' '){
						coordenada.coordX=i;
						coordenada.coordY=j;
						finais.push_back(coordenada);
					}

				graph.insert(pair<Par,list<Par> > (coo,ad));
				ad.clear();
		}
	}

	/*for(it=graph.begin();it!=graph.end();it++){
		cout<<"("<<it->first.coordX<<","<<it->first.coordY<<") --->>";
		for(l=it->second.begin();l!=it->second.end();l++){
			cout<<"("<<l->coordX<<","<<l->coordY<<")";
		}
		cout<<endl;
	}*/

	for(oo=finais.begin();oo!=finais.end();oo++)
		cout<<oo->coordX ;
	//fazer dijkstra......................................................................................
	coordenadaInicial.coordX=0;
	coordenadaInicial.coordY=0;
	coordenadaFinal.coordX=tamanhoMatriz-1;
	coordenadaFinal.coordY=tamanhoMatriz-1;

	/*tamanho=dijkstra(graph,coordenadaInicial,coordenadaFinal);
	cout<<tamanho<<endl;
*/

	return 0;
}