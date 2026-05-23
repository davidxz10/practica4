from flask import Flask, request
import matplotlib.pyplot as plt
import numpy as np
import os

app = Flask(__name__)

# Creamos la carpeta automáticamente si no existe
carpeta_destino = "imagenes"
os.makedirs(carpeta_destino, exist_ok=True)

@app.route('/', methods=['POST'])
def recibir():
    datos = request.json
    
    # Generamos la imagen
    plt.imshow(np.array(datos['data']), cmap="inferno") 
    plt.colorbar(label="Presion")                       
    plt.title("Mapa tactil")                            
    
    # Guardamos la imagen dentro de la carpeta 
    ruta_guardado = os.path.join(carpeta_destino, f"capture_{datos['capture_id']}.png")
    plt.savefig(ruta_guardado)
    plt.close()
    
    return "OK"

if __name__ == '__main__': 
    app.run(port=5000)
