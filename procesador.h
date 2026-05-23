#ifndef PROCESADOR_H
#define PROCESADOR_H

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json leerJSON(const std::string& ruta);
bool validar(const std::vector<std::vector<int>>& mat);
std::vector<std::vector<double>> interpolar(const std::vector<std::vector<int>>& mat);
void enviarHTTP(int id, const std::vector<std::vector<double>>& mat);

#endif
