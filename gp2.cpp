#include <iostream>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef string no;
typedef int peso;
typedef map<no, map<no,peso> > grafo;



map<no,no> travessia(grafo &g,no o){
	map<no,no> p;
	map<no,peso> d;
	list<no> next;
	next.push_back(o);
	p[o]=o;
	d[o]=0;

	while(!next.empty()){
		list<no>::iterator min=next.begin();
		list<no>::iterator at;
		for(at=next.begin();at != next.end() ; at++){
			if(d[*at]< d[*min])
				min=at;
		}
		no n=*min;
		next.erase(min);

		map<no,peso>::iterator it;
		for(it=g[n].begin();it != g[n].end(); it++){
			if(p.count(it->first) == 0){
				p[it->first]=n; //
				d[it->first]= d[n]+ it->second;
				next.push_back(it->first);
			}
			else{
				if((d[n] + it->second) < d[it->first]){
					p[it->first]=n;
					d[it->first]=d[n] + it->second;
				}
			}
		}
	}
	return p;
}

list<no> caminho(map<no,no> &p, no d) {
    list<no> path;
    while (p[d] != d) {
        path.push_front(d);
        d = p[d];
    }
    path.push_front(d);
    return path;
}

map<no,peso> distancias(grafo &g,map<no,no> &p){
	map<no,peso> d;
	map<no,no>::iterator it;
	for(it=p.begin(); it != p.end(); it++){
		peso len=0;
		list<no> cam = caminho(p,it->first);
		no ant= cam.front();
		list<no>::iterator at;
		for(at=cam.begin() ; at != cam.end(); at++){
			len+= g[ant][*at];
			ant= *at;
		}
		d[it->first]=len;
	}
	return d;
}

int main(){
	grafo g;
	string o,d;
	int a;

	//ler
	while(cin>>o>>d>>a){
		g[o][d]=a;
		g[d][o]=a;
	}

	grafo::iterator it;
	
	for(it=g.begin();it !=g.end(); it++){
		cout<< it->first << ":";
		map<no,no> p= travessia(g,it->first);
		map<no,peso> d= distancias(g,p);

		map<no,no>::iterator at;
		for (at = p.begin(); at != p.end(); at++){
			if(it->first != at->first)
				cout<< " "<< at->first<< "("<<d[at->first]<< ")" ;
		}
		cout<<endl;
	}




	return 0;
}



