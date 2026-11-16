
#include <iostream>
#include <string>
using namespace std;

int opcion;
const int cantidadProductos = 3;

float preciosProductos[3] = {25.99, 999.99, 399.50};

string productos[3] = {
    "Bocina",
    "Laptop Gamer",
    "Smartphone"
};

int stock[3] = {100, 25, 80};





void consultarStock(string productos[], int stock[],
                    int cantidadProductos) {

    cout << "===== CONSULTA DE INVENTARIO =====" << endl;

    for (int i = 0; i < cantidadProductos; i++) {

        cout << "Producto: " << productos[i] << endl;
        cout << "Unidades disponibles: " << stock[i] << endl;

        if (stock[i] == 0) {
            cout << "Estado: AGOTADO" << endl;
        }
        else {
            cout << "Estado: DISPONIBLE" << endl;
        }

        cout << "------------------------" << endl;
    }
}



int main() {

    do {

        cout << "===== SISTEMA DE TIENDA =====" << endl;
        cout << "1. Mostrar productos" << endl;
        cout << "2. Realizar compra" << endl;
        cout << "3. Consultar stock" << endl;
        cout << "4. Salir del sistema" << endl;

        cout << "Seleccione una opcion: ";

        switch (opcion) {

            case 1: {

                cout << "===== PRODUCTOS DISPONIBLES =====" << endl;

                for (int i = 0; i < cantidadProductos; i++) {

                    cout << i + 1 << ". " << productos[i] << endl;
                    cout << "Precio: $" << preciosProductos[i] << endl;
                    cout << "Stock: " << stock[i] << endl;
                    cout << "------------------------" << endl;
                }

                break;
            }

            case 2: {

                cout << "Realizando compra..." << endl;
                

                break;
            }

            case 3: {

                consultarStock(productos, stock, cantidadProductos);

                break;
            }

            case 4: {

                cout << "Saliendo del sistema..." << endl;

                break;
            }

            default: {

                cout << "Opcion invalida. Intente nuevamente." << endl;

                break;
            }
        }

    } while (opcion != 4);

    return 0;
}
