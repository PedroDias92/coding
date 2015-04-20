#include <iostream>

using namespace std;

int troco(int valor) {
    int aux;
    if (valor == 0) return 0;    
    aux = troco(valor - 1);
    if (valor >= 3) aux = min(aux,troco(valor-3));
    if (valor >= 4) aux = min(aux,troco(valor-4));
    return (aux+1);
}

int main() {
    int v;
    cin >> v;
    cout << troco(v) << endl;
    return 0;
}