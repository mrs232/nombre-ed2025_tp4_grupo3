//Tienda Online xd
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

public:
    // Constructor
    Producto(string nombre, float precio, string codigo, int stock) {
        this->nombre = nombre;
        this->precio = precio;
        this->codigo = codigo;
        this->stock = stock;
    }

    // Getters
    string getNombre() { return nombre; }
    float getPrecio() { return precio; }
    string getCodigo() { return codigo; }
    int getStock() { return stock; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setPrecio(float precio) { this->precio = precio; }
    void setCodigo(string codigo) { this->codigo = codigo; }
    void setStock(int stock) { this->stock = stock; }
     virtual ~Producto() {} // Destructor virtual para uso con herencia

};

class ProductoFisico : public Producto {
private:
    float peso; // en kilogramos

public:
    ProductoFisico(string nombre, float precio, string codigo, int stock, float peso)
        : Producto(nombre, precio, codigo, stock) {
        this->peso = peso;
    }

    float getPeso() { return peso; }
    void setPeso(float peso) { this->peso = peso; }
};



// --- Clase Pedido ---
// Define los datos de un pedido realizado.
class Pedido {
private:
    vector<Producto> productosComprados; // Un conjunto de productos.
    float montoTotal;

public:
// Constructor
    Pedido(vector<Producto> productosComprados, float montoTotal) {
        this->productosComprados = productosComprados;
        this->montoTotal = montoTotal;
    }
    //Mostrar resumen del pedido
    void mostrarResumen() {
        cout << "Resumen del Pedido:" << endl;
      for(int i=0;i<productosComprados.size(); i++)
        {
            cout << "Producto: " << productosComprados[i].getNombre() << endl;
            cout << "Precio: $" << productosComprados[i].getPrecio() << endl;
            cout << "Codigo: " << productosComprados[i].getCodigo() << endl;
            cout << "Stock: " << productosComprados[i].getStock() << endl;
            cout << "------------------------" << endl;
        }
        cout << "Monto Total: $" << montoTotal << endl;
    }


    // Getters
    vector<Producto> getProductosComprados() { return productosComprados; }
    float getMontoTotal() { return montoTotal; }

    // Setters
    void setProductosComprados(vector<Producto> productos) { this->productosComprados = productos; }
    void setMontoTotal(float monto) { this->montoTotal = monto; }
};

// --- Clase Cliente ---
// Define los datos de un cliente.
class Cliente {
private:
    string nombre;
    string idCliente; // Se usa string por flexibilidad.
    vector<Pedido> historialCompras; // Lista de pedidos anteriores.

public:
    // Constructor
    Cliente(string nombre, string idCliente) {
        this->nombre = nombre;
        this->idCliente = idCliente;
    }

    // Getters
    string getNombre() { return nombre; }
    string getIdCliente() { return idCliente; }
    vector<Pedido> getHistorialCompras() { return historialCompras; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setIdCliente(string id) { this->idCliente = id; }
    void setHistorialCompras(vector<Pedido> historial) { this->historialCompras = historial; }
};

// --- Clase Carrito ---
// Define los datos del carrito de compras.
class Carrito {
private:
    vector<Producto> productosAnadidos; // Productos que el cliente ha agregado.

public:
    // Constructor
    Carrito(vector<Producto> productosAnadidos) {
        this->productosAnadidos = productosAnadidos;
    }
    //Agregar producto al carrito
    void anadirProducto(Producto producto) 
    {
        productosAnadidos.push_back(producto);
    }
    // Eliminar producto del carrito
    void eliminarProducto(string codigo) 
    {
        for (auto it = productosAnadidos.begin(); it != productosAnadidos.end(); ++it) {
            if (it->getCodigo() == codigo) {
                productosAnadidos.erase(it);
                break;
            }
        }
    }

    // Getters
    vector<Producto> getProductosAnadidos() { return productosAnadidos; }

    // Setters
    void setProductosAnadidos(vector<Producto> productos) { this->productosAnadidos = productos; }
};

