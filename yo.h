#pragma once
#include <string>
using namespace std;

const int MAX = 100;

extern string nombres[MAX];
extern int cantidades[MAX];
extern string categorias[MAX];
extern float precios[MAX];
extern int total;

int leerEntero(const string& mensaje);
float leerFloat(const string& mensaje);
string leerLinea(const string& mensaje);

int buscarProducto(const string& nombre);
bool agregarProducto(const string& nombre, int cantidad,
                     const string& categoria, float precio);
bool venderProducto(const string& nombre, int cantidad);
void mostrarInventario();
void cargarInventarioInicial();
void procesoAdmin();
void procesoUsuario();