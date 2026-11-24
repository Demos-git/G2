# Sistema de Tienda

Programa de consola en C++ que junta tres partes: un login, un menú y la revisión de inventario.

## Qué hace

- Pide usuario y contraseña (3 intentos).
- Muestra un menú según el rol.
- Permite ver los productos, consultar el stock y realizar compras con factura (subtotal, IVA del 13 % y total).
- El administrador también puede agregar productos nuevos o reabastecer los que ya existen.

## Usuarios de prueba

| Rol | Usuario | Contraseña |
|---|---|---|
| Administrador | `admin` | `admin246` |
| Usuario | `usuario` | `usuario123` |

## Archivos

| Archivo | Qué contiene |
|---|---|
| `Menu.cpp` | El `main()`, el menú y las compras |
| `login.cpp` / `login.h` | El inicio de sesión |
| `yo.cpp` / `yo.h` | El inventario (agregar, vender, mostrar) |
| `un_archivo/Menu.cpp` | La misma tienda, todo junto en un solo archivo |

## Productos iniciales

- Bocina Bluetooth: 10 unidades, $25.99
- Laptop gamer: 5 unidades, $999.99
- Smartphone: 15 unidades, $399.50