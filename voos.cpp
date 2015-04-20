#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <istream>
using namespace std;

typedef string no;
typedef int preco;
typedef map<no,map<no,preco> > grafo;





map<no,no> travessia(grafo &g,no o){
	map<no,no> p;
	map<no,preco> d;
	list<no> next;
	next.push_back(o);
	p[o]=o;
	d[o]=0;
	while(!next.empty()){
		list<no>::iterator min=next.begin();
		list<no>::iterator at;

		for(at=next.begin();at != next.end();at++){
			if(d[*at]<d[*min])
				min=at;
		}
		no n=*min;
		next.erase(min);

		map<no,preco>::iterator it;
		for(it= g[n].begin();it != g[n].end();it++){
			if(p.count(it->first)==0){
				p[it->first]=n;
				d[it->first]=d[n]+it->second;
				next.push_back(it->first);
			}
			else{
				if((d[n]+it->second) < d[it->first]){
					p[it->first]=n;
					d[it->first]= d[n] + it->second;
				}
			}
		}
	
	}
	return p;
}






int main(){
	grafo g;
	string o,d,origem,destino;
	int p,menorPreco=0;
	cin>>origem>>destino;
	while(cin>>o>>d>>p){
		g[o][d]=p;
		g[d][o]=p;
	}

	
	
	map<no,preco> d= distancias(g,p)





	/*
	grafo::iterator it;
	map<no,preco>::iterator it2;
	for(it=g.begin();it!=g.end();it++){
		cout<< it->first<<':';
		for(it2=it->second.begin();it2!=it->second.end();it2++)
			cout<<' '<<it2->first<<' '<<it2->second ;
		cout<<endl;
	}
	cout<<ori<<' '<<dest<<endl;
	*/
}