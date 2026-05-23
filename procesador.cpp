#include "procesador.h"
#include <fstream>
#include <iostream>
#include <curl/curl.h>

// Comprobamos que el archivo exuste
json leerJSON(const std::string& ruta) {
    std::ifstream f(ruta);
    if (!f.is_open()) {
        std::cerr << "[Error] No se pudo encontrar el archivo '" << ruta << "'." << std::endl;
        exit(1);
    }
    return json::parse(f);
}

// Verificamos que la matriz sea 16x16
bool validar(const std::vector<std::vector<int>>& mat) {
    if (mat.size() != 16) return false;
    for (auto& fila : mat) {
        if (fila.size() != 16) return false;
    }
    return true;
}

std::vector<std::vector<double>> interpolar(const std::vector<std::vector<int>>& mat) {
    std::vector<std::vector<double>> nueva(128, std::vector<double>(128, 0));

    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            float x = j * 15.0f / 127.0f;
            float y = i * 15.0f / 127.0f;

            int x1 = (int)x, y1 = (int)y;
            int x2 = std::min(x1 + 1, 15);
            int y2 = std::min(y1 + 1, 15);

            float dx = x - x1, dy = y - y1;

            float arriba = mat[y1][x1] * (1 - dx) + mat[y1][x2] * dx;
            float abajo  = mat[y2][x1] * (1 - dx) + mat[y2][x2] * dx;

            nueva[i][j] = arriba * (1 - dy) + abajo * dy;
        }
    }
    return nueva;
}

// Enviar la matriz al servidor en Python
void enviarHTTP(int id, const std::vector<std::vector<double>>& mat) {
    if (CURL* curl = curl_easy_init()) {
        // Estructura JSON exigida por el servidor
        json payload = {{"capture_id", id}, {"width", 128}, {"height", 128}, {"data", mat}};
        std::string json_str = payload.dump();

        curl_slist* headers = curl_slist_append(NULL, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:5000/");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());

        curl_easy_perform(curl);

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}
