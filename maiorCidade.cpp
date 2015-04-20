#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <cstdlib>

using namespace std;

int main(){
	int i,o,j,x=0;
	string rua;
	int matriz[26][26];
	for(i=0;i<26;i++)
		for(j=0;j<26;j++) {
			matriz[i][j]=3000;
			matriz[i][i]=0;
		}
	while(cin>>rua){
		if((int)rua.size()<matriz[rua[0]-'a'][rua[rua.size()-1]-'a']){
			matriz[rua[0]-'a'][rua[rua.size()-1]-'a']=rua.size();
			matriz[rua[rua.size()-1]-'a'][rua[0]-'a']=rua.size();
		}
	}//floyd warshal !
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)
			for(o=0;o<26;o++){
				x=matriz[j][i]+matriz[i][o];
				if(x<matriz[j][o]) matriz[j][o]=x;
			}
			
	//saber qual a maior cidade
	x=0;
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)
			if(matriz[i][j]<3000 && matriz[i][j]>x) x=matriz[i][j];
	cout<<x<<endl;
	return 0;
}