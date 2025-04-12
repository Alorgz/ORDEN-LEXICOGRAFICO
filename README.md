# Generador de Combinaciones en Orden Lexicográfico

Este programa explora la combinatoria generando todas las posibles combinaciones de **r** elementos extraídos de un conjunto de **n** elementos. Las combinaciones se producen en orden lexicográfico y se almacenan en un archivo CSV. Además, se realiza una comparación entre el número de combinaciones generadas y el valor teórico de C(n, r) para asegurar la exactitud del algoritmo.

---

## Autora

**ALONDRA RODRIGUEZ ROBLES**

---

## Requisitos del Sistema

- **Compilador C++:**  
  Es recomendable utilizar *g++* versión 7.0 o superior, ya que el programa requiere características de C++11 o posteriores.

- **Plataforma:**  
  El código es compatible con Windows, Linux, macOS o cualquier sistema que admita compiladores modernos de C++.

---

## Cómo Compilar y Ejecutar

### Compilación

En la terminal, dirígete al directorio donde se encuentre el archivo fuente y ejecuta el siguiente comando:

```bash
g++ -O2 -std=c++11 main.cpp -o combinaciones
