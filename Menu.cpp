

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
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


float registrarCompra(string productos[],
                      float preciosProductos[],
                      int stock[],
                      int cantidadProductos) {

    string nombre;
    int cantidadesCompra[100] = {0};

    float subtotal = 0;
    float iva = 0;
    float total = 0;

    cout << "Ingrese su nombre: ";
    cin >> ws;
    getline(cin, nombre);

    cout << "===== REGISTRAR COMPRA =====" << endl;

    for (int i = 0; i < cantidadProductos; i++) {

        cout << "Producto: " << productos[i] << endl;
        cout << "Precio: $" << preciosProductos[i] << endl;
        cout << "Stock disponible: " << stock[i] << endl;

        cout << "Ingrese la cantidad que desea comprar: ";

        while (!(cin >> cantidadesCompra[i]) ||
               cantidadesCompra[i] < 0 ||
               cantidadesCompra[i] > stock[i]) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Cantidad invalida. Stock disponible: "
                 << stock[i] << endl;

            cout << "Ingrese nuevamente: ";
        }
    }

    cout << "===== FACTURA DE COMPRA =====" << endl;
    cout << "Cliente: " << nombre << endl;

    for (int i = 0; i < cantidadProductos; i++) {

        if (cantidadesCompra[i] > 0) {

            cout << productos[i]
                 << " x " << cantidadesCompra[i]
                 << " = $"
                 << preciosProductos[i] * cantidadesCompra[i]
                 << endl;

            subtotal += preciosProductos[i] * cantidadesCompra[i];

            stock[i] -= cantidadesCompra[i];
        }
    }

    iva = subtotal * 0.13;
    total = subtotal + iva;

    cout << fixed << setprecision(2);

    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA (13%): $" << iva << endl;
    cout << "Total a pagar: $" << total << endl;

    cout << "=============================" << endl;

    return total;
}


void consultarStock(string productos[],
                    int stock[],
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

        cout << "================================" << endl;
        cout << "       SISTEMA DE TIENDA.       " << endl;
        cout << "================================" << endl;

        cout << "1. Mostrar productos" << endl;
        cout << "2. Realizar compra" << endl;
        cout << "3. Consultar stock" << endl;
        cout << "4. Salir del sistema" << endl;

        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Debe ingresar un numero." << endl;
            continue;
        }

        switch (opcion) {

            case 1: {

                cout << "===== PRODUCTOS DISPONIBLES =====" << endl;

                cout << fixed << setprecision(2);

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

                registrarCompra(
                    productos,
                    preciosProductos,
                    stock,
                    cantidadProductos
                );

                break;
            }

            case 3: {

                consultarStock(
                    productos,
                    stock,
                    cantidadProductos
                );

                break;
            }

            case 4: {

                cout << "Saliendo del sistema..." << endl;
                cout << "Gracias por utilizar nuestro sistema." << endl;

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
