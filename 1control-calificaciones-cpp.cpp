#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    char continuar;

    do { // Bucle externo: repite el programa para otro grupo
        int cantidadEstudiantes;
        int aprobados = 0;            // Contador de aprobados
        int reprobados = 0;           // Contador de reprobados
        double sumaPromedios = 0;     // Acumulador de los promedios de todos
        double mejorPromedio = -1;    // Empieza en -1 para que el primer estudiante lo supere
        string mejorNombre = "";

        do { // Valida que la cantidad de estudiantes sea mayor que 0
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;

            if (cantidadEstudiantes <= 0) {
                cout << "Valor invalido. Debe ser mayor que 0." << endl;
            }
        } while (cantidadEstudiantes <= 0);

        cin.ignore(); // Limpia el Enter que quedo despues de leer el numero

        for (int i = 1; i <= cantidadEstudiantes; i++) { // Recorre cada estudiante
            string nombre;
            double nota;
            double sumaNotas = 0; // Se reinicia en 0 con cada estudiante

            cout << "--- Estudiante " << i << " ---" << endl;
            cout << "Nombre: ";
            getline(cin, nombre);

            for (int j = 1; j <= 4; j++) { // Recorre las 4 calificaciones
                do { // Repite la peticion mientras la nota este fuera de 0-100
                    cout << "Calificacion " << j << ": ";
                    cin >> nota;

                    if (nota < 0 || nota > 100) {
                        cout << "Nota invalida. Debe estar entre 0 y 100." << endl;
                    }
                } while (nota < 0 || nota > 100);

                sumaNotas = sumaNotas + nota; // Acumulador de las notas
            }

            cin.ignore(); // Limpia el Enter antes del proximo nombre

            double promedio = sumaNotas / 4;

            cout << fixed << setprecision(2);
            cout << "Promedio: " << promedio << " - ";
            if (promedio >= 70) {
                cout << "Aprobado" << endl;
                aprobados++;
            }
            else {
                cout << "Reprobado" << endl;
                reprobados++;
            }

            sumaPromedios = sumaPromedios + promedio;

            if (promedio > mejorPromedio) { // Guarda al estudiante con el promedio mas alto
                mejorPromedio = promedio;
                mejorNombre = nombre;
            }
        }

        double promedioGrupo = sumaPromedios / cantidadEstudiantes;

        cout << endl;
        cout << "===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
        cout << "Promedio del grupo: " << promedioGrupo << endl;
        cout << "Mejor promedio: " << mejorNombre << " (" << mejorPromedio << ")" << endl;

        cout << "Desea procesar otro grupo? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpia el Enter antes de un posible nuevo grupo
    } while (continuar == 's' || continuar == 'S');

    return 0;
}