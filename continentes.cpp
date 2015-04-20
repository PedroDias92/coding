
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <istream>
using namespace std;
typedef string a;


list< list<string> > funcao(list<list < string> > aux,list<string> st,int *res){
  //caso não haja paises
  if(aux.empty()){res=0;return aux;}
  list< list<string> >::iterator it;
  list<string>:: iterator ite;
  list<string>:: iterator iter;

  if(st.empty()){ // se a "stack" estiver vazia meto cenas ça para dentro
    it=aux.begin();
    for(iter=(*it).begin();iter!=(*it).end();iter++){
      st.push_back(*iter);
    }
    return funcao(aux,st,res);
  }
  else{ //se a "stack" tiver cenas fixes
    for(ite=st.begin();ite!=st.end();ite++){
      for(it=aux.begin();it!=aux.end();it++){
        if(procura((*it),(*ite))){  //vou procurar  um pais da "stack" na estrutura
          for(iter=(*it).begin();iter!=(*it).end();iter++){
            if(!(procura(st,*iter)))st.push_back(*iter); // para não meter repetidos na stack (c++ é uma nódoa nisto)
          }
        }
      }
    }
    *res= st.size();
  }
  for(ite=st.begin();ite!=st.end();ite++){
    aux=remover(aux,*ite);  //limpo da estrutura tudo o que já vi.
  } 
  return aux;
}















int main ()
{
  list<string> frases;
  string pais;
  string paises;
  int res=0;
  list<string> st;

  //ler todas as palavras para uma lista.
  while(!getline(cin,pais).eof()){
      if(!(pais.empty()))
        frases.push_back(pais);
  }
  pais.clear();

  list<string>::iterator it;

  for(it=frases.begin();it!=frases.end();it++){
    paises=*it;
    pais=(string)(strtok((char*)(paises.c_str())," "));
    aux2.push_back(pais);
    paises.erase(0,pais.size()+1);
    //enquanto a frase tiver palavras
    while(!pais.empty()){
      if(strtok((char*)(paises.c_str())," ")==NULL)
        pais.clear();
      //vou buscar as outras palavras
      else{
        pais=(string)(strtok((char*)(paises.c_str())," "));
        aux2.push_back(pais);
        paises.erase(0,pais.size()+1);
      }
      aux.push_back(aux2);
      aux2.clear();
    }

    //ate aqui so construi a estrutura
    while(!(aux.empty())){
      aux=funcao(aux,st,&res); //para assegurar que o primeiro aparecer a sequencia mais pequena
      if(res > r)
        r=res;
    }
    cout << r <<endl;
    return 0;
  }






  return 0;
}