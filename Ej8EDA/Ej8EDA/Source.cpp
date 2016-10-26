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
#include <string>
#include <string.h>
#include <ctype.h>



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(std::string  cadena, std::string  patron, int & cont) {
	std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
	std::transform(patron.begin(), patron.end(), patron.begin(), ::tolower);
	bool encontrado;
	cont = 0;
	for (std::vector<int>::size_type i = 0; i < cadena.length(); ++i) {
		size_t j = 0;
		encontrado = true;
		while (encontrado && j < patron.length())
		{
			if (cadena[i+j] != patron[j])
			{
				encontrado = false;
			}
			else
			{
				if (j ==patron.length()-1)
				{
					++cont;
				}
				++j;
			}
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string cadena;
	//std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
	std::string patron;
	std::getline(std::cin, cadena);
	std::getline(std::cin, patron);
	
	int cont;

	if (!std::cin)
		return false;

	resolver(cadena, patron, cont);
	std::cout << cont;

	// escribir sol


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