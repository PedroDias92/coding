#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <queue>

using namespace std;
typedef std::pair<int,int> pair_type;

int main(){
	map<pair_type,list<pair_type> > adj;
	map<pair_type,list<pair_type> > ::iterator it;
	list<pair_type>:: iterator j;
	queue<pair_type> candidatos;
	map<pair_type,pair_type> parent;
	string aux;
	int n;

	//apanha o inteiro
	cin>>n;
	getline(cin,aux);

	//inicializa a matriz com espaços
	char matriz[n][n];
	int linhas,colunas;
	for(linhas=0;linhas<n;linhas++)
		for(colunas=0;colunas<n;colunas++)
			matriz[linhas][colunas]=' ';



	//insere na matriz
	int f,g=0;
	while(getline(cin,aux)){
		f=0;
		while(aux[f]!='\0'){
			matriz[f][g]=aux[f];
			f++;
		}
		g++;
	}

	//imprimir a matriz
/*
	for(linhas=0;linhas<n;linhas++){
		for(colunas=0;colunas<n;colunas++)
			cout<<matriz[linhas][colunas];
		cout<<endl;
	}
*/

	//meter para a lista

	pair_type o,d;

	for(linhas=0;linhas<n;linhas++){
		for(colunas=0;colunas<n;colunas++){

			if(matriz[colunas][linhas]==' '){
				o=make_pair(colunas,linhas);
				if(matriz[colunas+1][linhas]==' '){
					d=make_pair(colunas+1,linhas);
					adj[o].push_back(d);
					adj[d].push_back(o);
				}
				if(matriz[colunas][linhas+1]==' '){
					d=make_pair(colunas,linhas+1);
					adj[o].push_back(d);
					adj[d].push_back(o);
				}
			}
		}
	}

	//Travessia com calculo das distancias

	map<pair_type,int> dist;
	map<pair_type,int>::iterator dt;

	pair_type c;
	c=make_pair(0,0);

	parent[c]=c;
	candidatos.push(c);
	dist[c]=0;

	while(!candidatos.empty()){
		c=candidatos.front();
		candidatos.pop();

		for(j=adj[c].begin();j!=adj[c].end();j++){
			if(!parent.count(*j)){
				candidatos.push(*j);
				parent[*j]=c;
				dist[*j]=dist[c]+1;
			}
		}
	}

	pair_type u;
	u=make_pair(n-1,n-1);
	cout<< dist[u]<< endl;


	return 0;








































}