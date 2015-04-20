#include <iostream>
#include <map>

using namespace std;

typedef unsigned long int nat;

nat ffib(nat n,map<nat,nat> &cache){
	if(n<2)
		return 1;
	if(cache.count(n)>0)
		return cache[n];
	cache[n]=ffib (n-1,cache) + ffib(n-2,cache);
	return cache[n];
}

nat fib(nat n){
	map<nat,nat> cache;
	return ffib(n,cache);
}

int main(){
	nat a;
	cin>>a;
	cout<< fib(a) << endl;
	return 0;
}