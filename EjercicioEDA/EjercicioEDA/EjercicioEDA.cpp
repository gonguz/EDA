// GRUPO VJ13 Gonzalo Guzmán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool resolver(std::vector<int>const& elementos, std::vector<int>::size_type& p) {

	for (unsigned int i = 0, x = elementos.size()-1; i < elementos.size(), x > p; ++i, --x){
		if (elementos[i] <= p && elementos[i]< elementos[x]) {
			return true;
		}else
		{
			return false;
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(){

int numElems;
std::vector<int>::size_type p;
std::cin >> numElems;
std::cin >> p;
std::vector<int> v(numElems);
p = v[p];
for (int& i : v) std::cin >> i;

if (resolver(v, p) == true)
{
	std::cout << "SI" << "\n";
}
else
{
	std::cout << "NO" << "\n";
}



}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("01EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}