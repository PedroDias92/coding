#include <iostream>
#include <map>
using namespace std;

int ftroco(int valor,map<int,int> &cache){
	int aux;
	if(valor==0) return 0;
	if(cache.count(valor) >0)
		return cache[valor];

	aux=ftroco(valor-1,cache);

	if(valor >= 3) aux=min(aux,ftroco(valor-3,cache));
	if(valor >= 4) aux=min(aux,ftroco(valor-4,cache));
	cache[valor]=aux+1;
	return cache[valor];
}


int troco(int valor){
	map<int,int> cache;
	return ftroco(valor,cache);
}



int main(){
	int v;
	cin>>v;
	cout<<troco(v)<<endl;
	return 0;
}