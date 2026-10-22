Rama 2 (Carrito y Facturación)

Descripción
Este módulo se encarga de administrar el proceso de compra dentro del sistema de la tienda. Su función es organizar los productos que el cliente desea comprar, verificar que estén disponibles y calcular el monto que deberá pagar al finalizar la compra.
1. Gestión del carrito
Permite guardar temporalmente los productos seleccionados por el cliente, junto con la cantidad que desea comprar. Para organizar esta información se pueden utilizar arreglos o vectores, facilitando el manejo de varios productos en una misma compra.

2. Verificación del stock
Antes de confirmar la compra, el sistema revisa que exista suficiente inventario de cada producto. Esto ayuda a evitar que se vendan unidades que la tienda no tiene disponibles y permite informar al cliente si debe reducir la cantidad solicitada.

3. Cálculos de la compra
El sistema suma el precio de cada producto multiplicado por su cantidad para obtener el subtotal. Después calcula el 13 % de IVA y lo suma al subtotal para determinar el total final que debe pagar el cliente.

4. Generación de la factura
Al terminar los cálculos, el programa muestra en la consola un comprobante con el nombre de los productos, las cantidades, los precios, el subtotal, el IVA y el total a pagar. De esta manera, el cliente puede revisar el detalle de su compra.

Fórmulas principales
Subtotal: suma de (precio unitario × cantidad).
IVA: subtotal × 0.13.
Total a pagar: subtotal + IVA.