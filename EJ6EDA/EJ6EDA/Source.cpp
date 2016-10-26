//VJ13 Gonzalo Guzmán del Río
//COmprueba si las letras de la palabra están bien ordenadas alfabéticamente
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

//El coste es O(f(n)) ya que tan solo recorrerá una vez la palabra hasta que encuentre un desorden en las letras
void resolver(std::string & palabra, int & longitud, int & numSeguidos) {
	longitud = 0;
	numSeguidos = 1;
	for (std::vector<int>::size_type i = 0; i < palabra.length(); ++i) {
		if (palabra[i]<palabra[i+1])
		{
			++numSeguidos;
		}
		else
		{
			if (longitud<=numSeguidos)
			{
				longitud = numSeguidos;
				
			}
			numSeguidos = 1;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::string palabra;
	std::cin >> palabra;
	int longitud;
	int numSeguidos;
	
	if (palabra == "XXX")
	{
		return false;
	}

	resolver(palabra, longitud, numSeguidos);
	std::cout << palabra.length() << " " << longitud;

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso()) {
		std::cout << "\n";
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}