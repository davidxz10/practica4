#include "procesador.h"

int main() {
    // 1. Lectura del archivo JSON
    json datos = leerJSON("tactile_captures_50.json");

    // 2. Iteración sobre las capturas
    for (const auto& cap : datos["captures"]) {
        int id = cap["id"];
        std::vector<std::vector<int>> matriz = cap["matrix"];

        // 3. Flujo condicional de validación, procesamiento y envío
        if (validar(matriz)) {
            auto ampliada = interpolar(matriz);
            enviarHTTP(id, ampliada);
        }
    }
    return 0;
}
