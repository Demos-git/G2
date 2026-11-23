#include <iostream>
#include <string>
#include <yo.cpp>
using namespace std;

int iniciarSesion() {
    const int INTENTOS = 3;

    for (int intento = 1; intento <= INTENTOS; intento++) {
        string usuario, contrasena;
        cout << "Ingrese su usuario: ";
        cin >> usuario;
        cout << "Ingrese su contrasena: ";
        cin >> contrasena;
        cin.ignore(10000, '\n');

        if (usuario == "admin" && contrasena == "admin246") {
            cout << "Bienvenido, administrador!\n\n";
            return ADMIN;
        } else if (usuario == "usuario" && contrasena == "usuario123") {
            cout << "Bienvenido, usuario!\n\n";
            return USUARIO;
        }
        cout << "Usuario o contrasena incorrectos. Intento "
             << intento << " de " << INTENTOS << ".\n\n";
    }
    return SIN_ACCESO;
}


