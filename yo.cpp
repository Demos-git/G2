#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Producto {
    int cantidad;
    string categoria;
    double precio;
};

using Inventario = unordered_map<string, Producto>;

bool agregarProducto(Inventario& stock, const string& nombre,
                     int cantidad, const string& categoria, double precio) {
    if (cantidad < 0 || precio < 0) return false;

    auto it = stock.find(nombre);
    if (it != stock.end()) {
        it->second.cantidad += cantidad;  
    } else {
        stock[nombre] = {cantidad, categoria, precio};
    }
    return true;
}

bool venderProducto(Inventario& stock, const string& nombre, int cantidad = 1) {
    auto it = stock.find(nombre);
    if (it == stock.end() || cantidad <= 0 || it->second.cantidad < cantidad) {
        return false;
    }
    it->second.cantidad -= cantidad;
    return true;
}

bool eliminarProducto(Inventario& stock, const string& nombre) {
    return stock.erase(nombre) > 0;
}

void mostrarInventario(const Inventario& stock) {
    for (const auto& producto : stock) {
        cout << producto.first << " | " << producto .second.categoria
             << " | Cantidad: " << producto.second.cantidad
             << " | $" << producto.second.precio << "\n";
    }
}

int main() {
    Inventario stock;

    agregarProducto(stock, "Bocina Bluetooth", 10, "Bocinas", 25.99);
    agregarProducto(stock, "Laptop gamer", 5, "Laptops", 999.99);
    agregarProducto(stock, "Smartphone", 15, "Telefonos", 399.50);

    if (!venderProducto(stock, "Bocina Bluetooth"))
        cout << "No se pudo vender la bocina\n";
    if (!venderProducto(stock, "Laptop gamer", 10))
        cout << "No hay suficiente stock de laptops\n";

    mostrarInventario(stock);
    return 0;
}