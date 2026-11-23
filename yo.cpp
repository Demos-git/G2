#include <iostream>
#include <string>
#include <iomanip>
#include "yo.h"
using namespace std;

string nombres[MAX];
int cantidades[MAX];
string categorias[MAX];
float precios[MAX];
int total = 0;

int leerEntero(const string& mensaje) {
    int n;
    cout << mensaje;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. " << mensaje;
    }
    cin.ignore(10000, '\n');
    return n;
}

float leerFloat(const string& mensaje) {
    float n;
    cout << mensaje;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. " << mensaje;
    }
    cin.ignore(10000, '\n');
    return n;
}

string leerLinea(const string& mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    return texto;
}

int buscarProducto(const string& nombre) {
    for (int i = 0; i < total; i++) {
        if (nombres[i] == nombre) return i;
    }
    return -1;
}

bool agregarProducto(const string& nombre, int cantidad,
                     const string& categoria, float precio) {
    if (cantidad < 0 || precio < 0) return false;

    int i = buscarProducto(nombre);
    if (i != -1) {
        cantidades[i] += cantidad;
        return true;
    }

    if (total >= MAX) return false;

    nombres[total] = nombre;
    cantidades[total] = cantidad;
    categorias[total] = categoria;
    precios[total] = precio;
    total++;
    return true;
}

bool venderProducto(const string& nombre, int cantidad) {
    int i = buscarProducto(nombre);
    if (i == -1 || cantidad <= 0 || cantidades[i] < cantidad) {
        return false;
    }
    cantidades[i] -= cantidad;
    return true;
}

void mostrarInventario() {
    if (total == 0) {
        cout << "No hay productos en el inventario.\n";
        return;
    }
    cout << fixed << setprecision(2);
    cout << "\n--- INVENTARIO ---\n";
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << nombres[i] << " | " << categorias[i]
             << " | Cantidad: " << cantidades[i]
             << (cantidades[i] == 0 ? " (AGOTADO)" : "")
             << " | $" << precios[i] << "\n";
    }
    cout << "\n";
}

void cargarInventarioInicial() {
    agregarProducto("Bocina Bluetooth", 10, "Bocinas", 25.99f);
    agregarProducto("Laptop gamer", 5, "Laptops", 999.99f);
    agregarProducto("Smartphone", 15, "Telefonos", 399.50f);
}

void procesoAdmin() {
    string nombre = leerLinea("Nombre: ");
    string categoria = leerLinea("Categoria: ");
    int cantidad = leerEntero("Cantidad: ");
    float precio = leerFloat("Precio: ");

    if (agregarProducto(nombre, cantidad, categoria, precio))
        cout << "Producto agregado/reabastecido.\n";
    else
        cout << "No se pudo agregar (datos invalidos o inventario lleno).\n";
}

void procesoUsuario() {
    string nombre = leerLinea("Nombre del producto: ");
    int cantidad = leerEntero("Cantidad a vender: ");

    if (venderProducto(nombre, cantidad))
        cout << "Venta realizada.\n";
    else
        cout << "No se pudo realizar la venta (producto no encontrado o cantidad insuficiente).\n";
}