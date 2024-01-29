#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>

void logging(); //Funcion para la herramienta logging

void herramienta_assert(); //Funcion para la herramienta assert

void dividir(int a, int b) {    //Funcion dividir para ejemplo de la herramienta throw
    if (b == 0) {
        // Lanzar una excepción en lugar de usar 'raise'
        throw std::runtime_error("Error: División por cero");
    }

    int resultado = a / b;
    std::cout << "Resultado de la división: " << resultado << std::endl;
}

int main() {
    try {
        dividir(10, 2);
        dividir(8, 0);  // Esto provocará una excepción
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }
    logging();
    herramienta_assert();
    return 0;
}

void logging(){
    // Configurar el registro en un archivo
    std::ofstream logfile("logfile.txt");
    if (!logfile.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return;
    }

    // Redirigir la salida estándar a la consola y al archivo de registro
    std::streambuf* original_cout = std::cout.rdbuf(logfile.rdbuf());

    try {
        std::cout << "Inicio del programa" << std::endl;

        // Simular una operación que puede generar un error
        int divisor = 0;
        if (divisor == 0) {
            std::cerr << "Error: División por cero" << std::endl;
            throw std::runtime_error("Error: División por cero");
        } else {
            float resultado = 10 / static_cast<float>(divisor);
            std::cout << "Resultado de la división: " << resultado << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    std::cout << "Fin del programa" << std::endl;

    // Restaurar la salida estándar original
    std::cout.rdbuf(original_cout);
}

void herramienta_assert(){
    int divisor = 0;

    // Utilizando assert para verificar que el divisor no sea cero
    assert(divisor != 0);

    // El código continuará aquí si la aserción es verdadera
    std::cout << "Divisor no es cero. Continuando con la ejecución." << std::endl;
}


