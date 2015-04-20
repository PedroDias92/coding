#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

int main() {


	int conta; 
	int max = conta = 0;

	string aux;
	
	list <string> paises;
	list <string> ::iterator ip,j;


	map <string, list<string> > input;
	map <string, list<string> >::iterator ii;

	map <string, int> visitados;
	//string pedro;

	getline(cin,aux);

	string p = aux;
	int tamanho;
	cin >> tamanho;
	getline(cin,aux);

	while(getline(cin,aux)) {
		stringstream oo;
		stringstream ss;

		//Nesta altura o oo e o ss s~ao apenas endereços de memoria

		
		ss << aux;
		oo << aux;
		//Nesta altura nao faço a minima ideia do que faz pois continua a retornar o mesmo
		//talvez indique que ss e oo sao endereços da string principal
		//IMPORTANTE SEM ISTO NAO IMPRIME
		//cout << ss << "  primeiro:  " << oo << " segundo "<< endl;
		
		string pai;
		string filho;

		while(ss >> pai) {
//CURIOSIDADE ,se puser ss >> filho em baixo ele imprime todos excepto o que ja im
//imprimiu antes, ao passo que se for oo>>filho ele imprime todos de novo
//logo estes gajos funcionam como apontadores nas linhas
			while(oo >> filho) {
				//cout << " pai :" << pai << " filho: "<< filho<< endl;
				//ja funciona, pois neste ciclo o pai controla a linha
				//if(pai != filho) {
					paises.push_back(pai);
					paises.push_back(filho);

					input[pai].push_back(filho);
					input[filho].push_back(pai);

					visitados.insert(pair <string,int>(pai,0));
					visitados.insert(pair <string,int>(filho,0));

					//visitados.sort();
					//visitados.unique();
				//}
				
			}
		}
	}

	paises.sort(); //ordena por ordem
	paises.unique(); //remove os repetidos

	/**
	for (ip=paises.begin(); ip!=paises.end();ip++){
		cout << " Vertice : " << *ip << endl;
		cout<< " Adjacentes ";
	for (j=input[*ip].begin(); j!=input[*ip].end();j++){
		cout << " " << *j;
	}
	cout << endl;
	cout << endl;
}
	*/

	queue <string> candidatos;
	map <string,int> distancia;
	map<string,int> cont;
	map<string,int> ::iterator mapa;
	string a;
	set < string> resultado;

	set < string>:: iterator paist;
	if(tamanho==0) cout<<p<<endl;
	//for(ip = paises.begin(); ip != paises.end();ip++) {
		//cout << p << endl;
		candidatos.push(p);
		distancia[p]=0;
		//if(visitados[p] == 2) c;
		//a = (*ip);
		while(!candidatos.empty()) {

			aux = candidatos.front();
			//cout << aux << endl;
			//cout << conta << endl;
			candidatos.pop();
			visitados[aux] = 2;
			
			//if(conta == tamanho) cont.insert(pair<string,int> (aux,conta));

			
			//cout << aux << " ole:  " << conta << endl;
			for(j = input[aux].begin(); j!= input[aux].end();j++) {
				if(visitados[*j] == 0) {
					candidatos.push(*j);
					visitados[*j] =1;
					distancia[*j] = distancia[aux] + 1;
					if(distancia[*j] == tamanho) 
						resultado.insert(*j);
						//cout << distancia[*j] << *j ;
					//cout << "quando entras" << *j << endl;
				}
			}
		}
		if(conta > max) {
			max = conta;
		}


	//	cout << a<< conta << endl ;
		//cont.insert(pair<string,int> (a,conta));
		//conta = 0;
	


	for (paist=resultado.begin(); paist!=resultado.end();paist++){
		cout << *paist <<  endl  ;
	}
	

	//cout << max << endl;
	return 0;
}