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

	//quando os adjacentes sao irregulares ou seja de tamanhos distintos 
	//neste caso ha 2 ou 3 paises por linha ,faço assim
	// se or regular faço como o voos
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
	list<string> imprimir;
	list<string>::iterator ol;
	string a;

	for(ip = paises.begin(); ip != paises.end();ip++) {
		candidatos.push(*ip);
		a=(*ip);
		while(!candidatos.empty()) {

			aux = candidatos.front();
			candidatos.pop();
			visitados[aux] = 2;

			conta++;

			//cout << aux << " ole:  " << conta << endl;
			for(j = input[aux].begin(); j!= input[aux].end();j++) {
				if(visitados[*j] == 0) {
					candidatos.push(*j);
					visitados[*j] =1;
					//cout << "quando entras" << *j << endl;
				}
			}
		}
		if(conta > max) {
			max = conta;
		}
		cont.insert(pair<string,int>(a,conta));
		conta = 0;
	}

	


for (mapa=cont.begin(); mapa!=cont.end();mapa++){
		cout << mapa->first << endl  ;
	}
	

	return 0;
}