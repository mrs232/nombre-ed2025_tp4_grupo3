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
    float precio;
    string codigo;
    int stock;
};

// --- Clase Pedido ---
// Define los datos de un pedido realizado.
class Pedido {
private:
    vector<Producto> productosComprados; // Un conjunto de productos.
    float montoTotal;
};

// --- Clase Cliente ---
// Define los datos de un cliente.
class Cliente {
private:
    string nombre;
    string idCliente; // Se usa string por flexibilidad.
    vector<Pedido> historialCompras; // Lista de pedidos anteriores.
};

// --- Clase Carrito ---
// Define los datos del carrito de compras.
class Carrito {
private:
    vector<Producto> productosAnadidos; // Productos que el cliente ha agregado.
};
