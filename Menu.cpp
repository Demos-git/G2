
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
const int MAX = 100;
string nombres[MAX];
string categorias[MAX];
int cantidades[MAX];
float precios[MAX];
int total = 0;
 
const int SIN_ACCESO = 0;
const int ADMIN = 1;
const int USUARIO = 2;
 
int iniciarSesion() {
    string usuario, contrasena;
 
    for (int intento = 1; intento <= 3; intento++) {
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasena: ";
        cin >> contrasena;
 
        if (usuario == "admin" && contrasena == "admin246") {
            cout << "Bienvenido, administrador!" << endl;
            return ADMIN;
        }
        if (usuario == "usuario" && contrasena == "usuario123") {
            cout << "Bienvenido, usuario!" << endl;
            return USUARIO;
        }
        cout << "Datos incorrectos. Intento " << intento << " de 3." << endl;
    }
    return SIN_ACCESO;
}
 
void agregarProducto(string nombre, string categoria, int cantidad, float precio) {
    if (total >= MAX) {
        cout << "El inventario esta lleno." << endl;
        return;
    }
    nombres[total] = nombre;
    categorias[total] = categoria;
    cantidades[total] = cantidad;
    precios[total] = precio;
    total++;
}
 
void mostrarProductos() {
    cout << fixed << setprecision(2);
    cout << "===== PRODUCTOS =====" << endl;
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << nombres[i]
             << " (" << categorias[i] << ")"
             << " - $" << precios[i]
             << " - Stock: " << cantidades[i] << endl;
    }
}
 
void consultarStock() {
    cout << "===== CONSULTA DE STOCK =====" << endl;
    for (int i = 0; i < total; i++) {
        cout << nombres[i] << ": " << cantidades[i] << " unidades";
        if (cantidades[i] == 0) {
            cout << " (AGOTADO)";
        }
        cout << endl;
    }
}
 
void reabastecer() {
    string nombre, categoria;
    int cantidad;
    float precio;
 
    cin.ignore();
    cout << "Nombre del producto: ";
    getline(cin, nombre);
 
    for (int i = 0; i < total; i++) {
        if (nombres[i] == nombre) {
            cout << "Cantidad a agregar: ";
            cin >> cantidad;
            if (cantidad > 0) {
                cantidades[i] = cantidades[i] + cantidad;
                cout << "Stock actualizado." << endl;
            } else {
                cout << "Cantidad invalida." << endl;
            }
            return;
        }
    }
 
    cout << "Categoria: ";
    getline(cin, categoria);
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "Precio: ";
    cin >> precio;
 
    if (cantidad < 0 || precio < 0) {
        cout << "Datos invalidos." << endl;
        return;
    }
    agregarProducto(nombre, categoria, cantidad, precio);
    cout << "Producto agregado." << endl;
}
 
void realizarCompra() {
    string cliente;
    int cantidadesCompra[MAX];
    float subtotal = 0;
    float iva, totalPagar;
 
    cin.ignore();
    cout << "Ingrese su nombre: ";
    getline(cin, cliente);
 
    cout << "===== REGISTRAR COMPRA =====" << endl;
    cout << fixed << setprecision(2);
 
    for (int i = 0; i < total; i++) {
        cout << nombres[i] << " - $" << precios[i]
             << " - Stock: " << cantidades[i] << endl;
        cout << "Cantidad que desea comprar: ";
        cin >> cantidadesCompra[i];
 
        while (cantidadesCompra[i] < 0 || cantidadesCompra[i] > cantidades[i]) {
            cout << "Cantidad invalida. Stock disponible: " << cantidades[i] << endl;
            cout << "Ingrese de nuevo: ";
            cin >> cantidadesCompra[i];
        }
    }
 
    cout << endl << "===== FACTURA =====" << endl;
    cout << "Cliente: " << cliente << endl;
 
    for (int i = 0; i < total; i++) {
        if (cantidadesCompra[i] > 0) {
            float parcial = precios[i] * cantidadesCompra[i];
            cout << nombres[i] << " x " << cantidadesCompra[i]
                 << " = $" << parcial << endl;
            subtotal = subtotal + parcial;
            cantidades[i] = cantidades[i] - cantidadesCompra[i];
        }
    }
 
    iva = subtotal * 0.13;
    totalPagar = subtotal + iva;
 
    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA (13%): $" << iva << endl;
    cout << "Total a pagar: $" << totalPagar << endl;
    cout << "===================" << endl;
}
 
int main() {
    int opcion;
    int rol;
 
    agregarProducto("Bocina Bluetooth", "Bocinas", 10, 25.99);
    agregarProducto("Laptop gamer", "Laptops", 5, 999.99);
    agregarProducto("Smartphone", "Telefonos", 15, 399.50);
 
    rol = iniciarSesion();
    if (rol == SIN_ACCESO) {
        cout << "Demasiados intentos. Programa terminado." << endl;
        return 0;
    }
 
    do {
        cout << endl << "====== SISTEMA DE TIENDA ======" << endl;
        cout << "1. Mostrar productos" << endl;
        cout << "2. Realizar compra" << endl;
        cout << "3. Consultar stock" << endl;
        if (rol == ADMIN) {
            cout << "4. Agregar o reabastecer producto" << endl;
        }
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        }
 
        switch (opcion) {
            case 1:
                mostrarProductos();
                break;
            case 2:
                realizarCompra();
                break;
            case 3:
                consultarStock();
                break;
            case 4:
                if (rol == ADMIN) {
                    reabastecer();
                } else {
                    cout << "Opcion invalida." << endl;
                }
                break;
            case 0:
                cout << "Gracias por usar el sistema. Adios!" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
 
    return 0;
}