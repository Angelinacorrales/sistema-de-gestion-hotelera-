#include <iostream>
#include <string>
using namespace std;

const int MAX_HABITACIONES=100;

struct Habitacion {
	int numero;
	string tipo;
	bool disponible;
};

int main(){
	Habitacion
	habitaciones [MAX_HABITACIONES];
	
	int contadorHabitaciones = 0 ;
	int opcion;
	
	do {
		cout <<"\nSistema de Gestion Hotelera\n";
		cout <<"1. Agregar habitacion\n";
		cout <<"2. Reservar habitacion\n";
		cout <<"3. Consultar estado de habitaciones\n";
		cout <<"4. Salir\n";
		cout <<"Elige una opcion:";
		
		cin >> opcion;
		if (opcion == 1) {
			if (contadorHabitaciones >= MAX_HABITACIONES) {
				cout <<"No se puede agregar mas habitaciones.\n";
			} else {
				cout <<"Numero de haitacion:";
				cin >> habitaciones [contadorHabitaciones] .numero;
				cout <<"Tipo de habitacion (Individual/Doble/suite):";
				cin >> habitaciones [contadorHabitaciones] .tipo;
				
				habitaciones [contadorHabitaciones] .disponible = true;
				contadorHabitaciones++;
				cout <<"Habitacion agregada con exito.\n";
			}
		} else if (opcion == 2) {
			int numero;
			cout <<"Numero de habitacion a reservar:";
			cin >> numero;
			bool encontrada = false;
			for (int i = 0; i < contadorHabitaciones; i++) {
				if (habitaciones[i] .numero == numero) {
					encontrada = true;
					if (habitaciones[i] .disponible) {
						habitaciones[i] .disponible = false;
						cout <<"La habitaion" << numero << "ha sido reservada con exito.\n";
					} else {
						cout <<"La habitacion" << numero << "ya esta reservada.\n";
					}
					break;
				}
			}
			if (! encontrada) {
				cout <<"La habitacion" << numero << "no existe.\n";
			}
		} else if (opcion == 3) {
			cout <<"\nEstado de las habitaciones:\n";
			for (int i = 0; i < contadorHabitaciones; i++) {
				cout <<"Habitacion" << habitaciones[i] .numero << "(" << habitaciones[i] .tipo <<") -";
				cout << (habitaciones[i] .disponible? "Disponible" : "Reservada") << endl;
			}
		} else if (opcion == 4) {
			cout <<"Saliendo del sistema...\n";
		} else {
			cout <<"Opcion invalida. Intenta nuevamente.\n";
		}
		
	} while (opcion != 4);
	return 0;
	
}

