#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

#define PRETO 2
#define CINZA 1
#define BRANCO 0

using namespace std;


typedef std::pair <string,int> par;
//O menor serve apenas para decidir quem sera o primeiro da orla, pois o dikstra
//vai pelos caminhos mais curtos, e aquele que for o vertice de menor caminho a partir da raiz
// e o primeiro a ser visitado

string Menor (list<string> l, map <string,int> custos) {
	string aux;
	list <string> ::iterator i;
	aux = l.front();

	for(i = l.begin(); i!= l.end();i++) {
		if(custos[*i] <= custos[aux]) aux = *i;
	}

	return aux;
}
	


int dijkstra(map<string, list <par> > grafo, string origem, string destino){
	list< string> orla;
	map <string,int> cor;
	map <string,int> custos;

	list<par>:: iterator c;

	string aux = origem;
	cor[origem] = CINZA;
	custos[origem] = 0;

	orla.push_back(origem);


	while(!orla.empty() && aux!= destino) {
		aux = Menor(orla,custos);
		orla.remove(aux);
		
		for(c = grafo[aux].begin(); c!= grafo[aux].end(); c++) {
			
			if(cor[c->first]== BRANCO) {
				cor[c->first] = CINZA;
				orla.push_back(c->first);
				custos[c->first] = custos[aux] + c->second;
			}

			else{
				if(cor[c->first]==CINZA){
					if(custos[c->first] > (custos[aux]+ c->second)) {
						custos[c->first] = custos[aux]+c->second;
					}
				}	
			}
		}
		cor[aux]  =PRETO;
		aux = orla.front();
	}
	
	return custos[destino];

}

int main() {

	string s;
	string origem;
	string destino;

	

	list <string> aero;
	list <string> :: iterator i;

	list <par> ::iterator ip;

	map <string,list<par> > adj;
	map <string,list<par> >:: iterator ia;

	map <string, int> visitados;

	cin >> origem >> destino;
	getline(cin,s);

	while(getline(cin,s)) {
		stringstream oo;
		
		oo << s;

		string o;
		string d;
		int c;

		oo >> o;
		oo >> d;
		oo >> c;

		par x,y;
		

		//cout << "1" << o << "2" << d << "3" << c << endl;

		x = make_pair(d,c);
		y = make_pair(o,c);

		aero.push_back(o);
		aero.push_back(d);

		adj[o].push_back(x);
		adj[d].push_back(y);

		visitados.insert(pair <string,int> (o,0));
		visitados.insert(pair <string,int> (d,0));
				
	}
	
	aero.sort();
	aero.unique();
/**

	for(i = aero.begin(); i!= aero.end(); i++) {
		
		cout << *i << endl;
		
		for(ip = adj[*i].begin(); ip!= adj[*i].end(); ip++){
			cout << ip->first << "Peso" << ip->second << endl;
		}
		cout << endl;
	}
*/
//cout << origem << destino;

	int menor = dijkstra(adj,origem,destino);

	cout << menor << endl;
	return 0;
}
