# Procesamiento e Interpolación de Imágenes Táctiles para un Gripper Robótico utilizando C++ y Python
## 1.Descripción
Este repositorio contiene la cuarta practica de la asignatura de Sistemas Operativos desarollado en C++ y Python que tiene como objetivo trabajar el procesamiento de matrices táctiles, la interpolación bilineal, la comunicación en red mediante una arquitectura cliente-servidor (HTTP) y la visualización de datos científicos.
---

## 2. Estructura del repositorio

```
├── servidor.py                      # Servidor Python
├── procesador.cpp                   # Lógica en C++
├── main.cpp                         # Función Main
├── procesador.h                     # Header C++
├── cliente                          # Binario
├── imagenes/                        # Directorio imagenes
├── tactile_captures_50.json         # Archivo JSON
├── LICENSE             
└── README.md
```

---

## 3. Requisitos del sistema
- Sistema operativo Linux (probado en Arch)
- Python3
- Gcc/G++
- Python-pip

### Instalacion de las herramientas en Arch
```bash
sudo pacman -Syu base-devel curl nlohmann-json python-flask python-matplotlib python-numpy
```

---

## 4. Ejecución
```bash
./servidor.py &
./cliente
```

---

## 5. Salida esperada

 * Serving Flask app 'servidor'

 * Debug mode: off

WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.

 * Running on http://127.0.0.1:5000

Press CTRL+C to quit

127.0.0.1 - - [21/May/2026 16:21:59] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:21:59] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -


## 6. Autoría
* Alumno: David

## 7. Licencia
GLP-3.0 license
