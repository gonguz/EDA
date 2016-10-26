// Grupo XYZ, Fulano y Mengano
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
void resolver(std::vector<int> const& v, int & cont, int & max) {
	max = v[0];
	for (std::vector<int>::size_type i = 1; i < v.size(); ++i)
	{
		if (v[i] > max)
		{
			max = v[i];
			cont = 1;
		}
		else if(v[i] == max)
		{
			++cont;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numElem;
	std::cin >> numElem;
	std::vector<int> v(numElem);
	for (int& i:v)
	{
		std::cin >> i;
	}
	int cont = 1;
	int max = v[0];


	resolver(v, cont, max);
	std::cout << max << " " << cont << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Prueba.txt");
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