#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <queue>


using namespace std;

typedef std::pair<int, int> pair_type;

int main() {

	map<pair_type,list<pair_type> > adj;
	map<pair_type,list<pair_type> > :: iterator it;

	list<pair_type>:: iterator j;

	queue<pair_type> candidatos;

	map <pair_type,pair_type> parent;

	string aux;

	int n;


	//APANHA O INTEIRO E TIRA O \n
	cin >> n;
	getline(cin,aux);

	//INICIA MATRIZ

	char mat[n][n];
	int linha,coluna;

	/*for(linha=0;linha<n;linha++){
		for(coluna=0;coluna<n;coluna++) {
			mat[linha][coluna] = '0';
		}
	}*/

	//INSERE MATRIZ
	int f,g=0;

	while(getline(cin,aux)){
	        f=0;
			while(aux[f]!='\0') {
					mat[f][g]=aux[f];
					f++;
				}
			g++;
		}

	//IMPRIME MATRIZ

		/*for(r=0;r<g;r++){
		for(t=0;t<max_f;t++) {
			cout << mat[r][t];
		}
		cout << endl;
	}*/

	pair_type o,d;

	for(linha=0;linha<n;linha++){

		for(coluna=0;coluna<n;coluna++) {

			if(mat[coluna][linha]==' ') {
				o=make_pair(coluna,linha);
				if(mat[coluna+1][linha]==' ') {
					
					d=make_pair(coluna+1,linha);
					adj[o].push_back(d);
					adj[d].push_back(o);

				}

				if(mat[coluna][linha+1]==' ') {

					d=make_pair(coluna,linha+1);
					adj[o].push_back(d);
					adj[d].push_back(o);

			}

			
		}
	}}

//TRAVESSIA COM CACULO DAS DISTANCIAS


	map<pair_type,int> dist;
	map<pair_type,int>:: iterator dt;

	pair_type c;
	c=make_pair(0,0);


	parent[c]=c;
	candidatos.push(c);

	dist[c]=0;

	while(!candidatos.empty()) {
		c=candidatos.front();
		candidatos.pop();

	for (j=adj[c].begin(); j!=adj[c].end();j++){

		if(!parent.count(*j)) {
			candidatos.push(*j);
			parent[*j]=c;
			dist[*j]=dist[c]+1;
			
		}

	}}

	//Imprime a distancia do ultimo vertice


	pair_type u;
	u=make_pair(n-1,n-1);

	cout << dist[u] << endl;


return 0;



}