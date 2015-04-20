#include <iostream>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef string no;
typedef map< no, list<no> > grafo;

map<no,no> travessia(grafo &g, no o) {
    map<no,no> p;
    list<no> next;
    next.push_back(o); // põe no fim da lista a origem
    p[o] = o; 
    while (!next.empty()) { //enquanto a lista não esta vazia
        no n = next.front();//acessa o primeiro elemento
        next.pop_front();
        list<no>::iterator it;
        for (it = g[n].begin(); it != g[n].end(); it++) {
            if (p.count(*it) == 0) { //se ainda não foi visitado
                p[*it] = n; //coloca no resultado final
                next.push_back(*it); //coloca na queue
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

map<no,int> distancias(map<no,no> &p) {
    map<no,int> d;
    map<no,no>::iterator it;
    for (it = p.begin(); it != p.end(); it++) {
        d[it->first] = caminho(p,it->first).size() - 1;
    }
    return d;
}

int main() {
    grafo g;
    string o,d;

    while (cin >> o >> d) {
        g[o].push_back(d);
        g[d].push_back(o);
    }

    grafo::iterator it;
    for (it = g.begin(); it != g.end(); it++) {
        cout << it->first << ":";
        map<no,no> p = travessia(g,it->first);
        map<no,int> d = distancias(p);
        map<no,no>::iterator at;
        for (at = p.begin(); at != p.end(); at++) {
            if (at->first != it->first) cout << " " << at->first << "(" << d[at->first] << ")";
        }
        cout << endl;
    }

    return 0;
}

