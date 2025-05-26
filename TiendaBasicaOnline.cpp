//Tienda Online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- Declaraciones anticipadas ---
// Las clases Cliente, Producto, Pedido y Carrito se declaran aquí para que puedan ser referenciadas entre sí.
class Producto;
class Pedido;

// --- Clase Producto ---
// Define los datos básicos de un producto.
class Producto {
private:
    string nombre;
    double precio;
    string codigo;
    int stock;
};

// --- Clase Pedido ---
// Define los datos de un pedido realizado.
class Pedido {
private:
    vector<Producto> productosComprados; // Un conjunto de productos.
    double montoTotal;
};

