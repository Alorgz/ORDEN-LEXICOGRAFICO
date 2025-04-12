#include <iostream>

#include <fstream>

#include <string>

#include <vector>
 
using namespace std;
 
unsigned long long calcularCoefBinomial(int total, int seleccionados) {

    if (seleccionados > total)

        return 0;

    if (seleccionados > total - seleccionados)

        seleccionados = total - seleccionados;

    unsigned long long resultado = 1;

    for (int i = 1; i <= seleccionados; i++) {

        resultado = resultado * (total - i + 1) / i;

    }

    return resultado;

}
 
void generarYGuardarCombinaciones(int total, int seleccionados, ofstream &archivo, unsigned long long &contador) {

    if (seleccionados == 0) {

        archivo << "\n";

        contador++;

        return;

    }
 
    vector<int> combinacionActual(seleccionados);

    for (int i = 0; i < seleccionados; i++) {

        combinacionActual[i] = i + 1;

    }
 
    while (true) {

        for (int i = 0; i < seleccionados; i++) {

            archivo << combinacionActual[i];

            if (i < seleccionados - 1)

                archivo << ",";

        }

        archivo << "\n";

        contador++;
 
        int i;

        for (i = seleccionados - 1; i >= 0; i--) {

            if (combinacionActual[i] < total - seleccionados + i + 1)

                break;

        }

        if (i < 0)

            break;

        combinacionActual[i]++;

        for (int j = i + 1; j < seleccionados; j++) {

            combinacionActual[j] = combinacionActual[j - 1] + 1;

        }

    }

}
 
bool entradaValida(int total, int seleccionados) {

    return total >= 1 && seleccionados >= 0 && seleccionados <= total;

}
 
int main() {

    int n, r;
 
    while (true) {

        cout << "Ingrese el valor de n (>= 1): ";

        cin >> n;

        cout << "Ingrese el valor de r (>= 0 y <= n): ";

        cin >> r;

        if (entradaValida(n, r))

            break;

        else

            cout << "Entrada no válida. Por favor intente de nuevo.\n";

    }
 
    string nombreArchivo = "combinaciones_n" + to_string(n) + "_r" + to_string(r) + ".csv";

    ofstream salida(nombreArchivo);

    if (!salida.is_open()) {

        cerr << "No se puede abrir el archivo para escribir: " << nombreArchivo << "\n";

        return 1;

    }
 
    unsigned long long totalGeneradas = 0;

    generarYGuardarCombinaciones(n, r, salida, totalGeneradas);

    salida.close();
 
    unsigned long long totalTeorico = calcularCoefBinomial(n, r);

    cout << "\nNúmero total de combinaciones generadas: " << totalGeneradas << endl;

    cout << "Número teórico de combinaciones C(" << n << ", " << r << "): " << totalTeorico << endl;

    cout << "Los conteos " << (totalGeneradas == totalTeorico ? "coinciden." : "NO coinciden.") << endl;

    cout << "Archivo CSV guardado con el nombre: " << nombreArchivo << endl;
 
    return 0;

}
 