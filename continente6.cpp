#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <list>

#include <algorithm> 

using namespace std;



int procura(list <string> aux, string st){	// procurar uma palavra numa lista
	int res=0;
	if(aux.empty()) res =0;
	list< string> ::iterator iter;
		for(iter=aux.begin();iter!=aux.end();iter++){	//se a frase tiver a palavra retorna true(1)
			if(*iter == st) res= 1;
		}
	
	return res;
}



list <list <string> > remover(list< list <string> > aux,string bla){ //remover a linha que contem uma palavra dada
	list< list <string> >::iterator it;
	int t=1;
	it=aux.begin();
	while(it!=aux.end() && t){
		if(procura(*it,bla)) {aux.remove(*it);t=0;}	
		else{it++;}	
	}
	return aux;
}
		
list< list <string> > funcao(list< list <string> > aux,list<string> st,int* res){
	if (aux.empty()) {res= 0; return aux;}
	list< list< string> >::iterator it;
	list< string> ::iterator ite;
	list< string> ::iterator iter;
	if(st.empty()){
		it=aux.begin();		// se a "stack" tiver vazia meto cenas la para dentro
		for(iter=(*it).begin();iter!=(*it).end();iter++){
			st.push_back(*iter);
		}
		return funcao(aux,st,res);
	}
	else{	// se a "stack" tiver cenas fixes
		for(ite=st.begin();ite!=st.end();ite++){
			for(it=aux.begin();it!=aux.end();it++){
				if(procura((*it),(*ite))){	//vou procurar  um pais da "stack" na estrutura
					for(iter=(*it).begin();iter!=(*it).end();iter++){
						if(!(procura(st,*iter)))st.push_back(*iter); // para não meter repetidos na stack (c++ é uma nódoa nisto)
					}
				}
			}
		}
		*res= st.size();
	}
	for(ite=st.begin();ite!=st.end();ite++){
		aux=remover(aux,*ite);	//limpo da estrutura tudo o que já vi.
	}	
	return aux;
}


int main(){
	int res=0;
	int r=0;
	list< list <string> > aux;
	list<string> frases;
	list<string> aux2;
	list<string> st;
	string pais;
	string paises;
	list< list <string> > ::iterator ite;
	while(!(getline(cin,pais)).eof()){
		if(!(pais.empty()))frases.push_back(pais);
	}//leio todas as frases para uma lista
	pais.clear();
	list<string> ::iterator it;
	
	for(it=frases.begin();it!=frases.end();it++){
		paises=*it;
		pais=(string)(strtok((char*)(paises.c_str())," "));
		aux2.push_back(pais);
		paises.erase(0,pais.size()+1);
		while (!pais.empty()){		// enquanto a frase tiver palavras
			if(strtok((char*)(paises.c_str())," ")==NULL) pais.clear();
			else{
				pais=(string)(strtok((char*)(paises.c_str())," "));	//vou buscar as outras palavras
				aux2.push_back(pais);
				paises.erase(0,pais.size()+1);}
			}
		aux.push_back(aux2);
		aux2.clear();
	}
	
	// até aqui so construi a estrutura
	while(!(aux.empty())){
		aux=funcao(aux,st,&res);	// para assegurar que no caso de primeiro aparecer a sequencia mais pequena
		if(res > r) r=res;
	}
	cout << r<<endl;
	return 0;
}
