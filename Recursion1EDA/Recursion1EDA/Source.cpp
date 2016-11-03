//Grupo VJ13, Gonzalo Guzmán del Río.
//El ejercicio consiste en encontrar el valor mas pequeño en un vector de n elementos.
//Para ello, se partira el vector en dos partes y se observara tanto la parte izquierda como derecha del vector.
//El numero mas pequeño de cada lado sera comparado y saldra por pantalla ese valor.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



//El tipo de recursion es lineal ya que en cada caso se hace una sola llamada.
//El coste es O(f(logn)) ya que se utiliza un algoritmo de divide y vencerás para su resolución.
void resolver(std::vector<int> const v, int & min, int prim, int ultimo) {
	int j = ultimo - prim;
	if (j == 1)
		min = v[0];
	else if (j == 2) {
		ultimo -= 1;
		if (v[prim] > v[ultimo])
			min = v[ultimo];
		else
			min = v[prim];
	}
	else if (j > 2)
	{
		int div = (prim + ultimo) / 2;
		if (v[div - 1] < v[div]) {
			ultimo = div;
			resolver(v, min, prim, ultimo);
		}
		else if (v[div + 1] < v[div]) {
			prim = div;
			resolver(v, min, prim, ultimo);
		}
		else {
			min = v[div];
		}

			
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int longitud;
	std::cin >> longitud;
	int min = 0;
	int prim = 0;
	int ult = longitud;

	if (!std::cin)
		return false;


	std::vector<int>v(longitud);
	
	for (size_t i = 0; i < v.size();++i)
	{
		std::cin >> v[i];
	}
	resolver(v, min, prim, ult);
	std::cout << min;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		std::cout << "\n";


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}