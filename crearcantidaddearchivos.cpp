/*  un programa en c++ con las siguientes caracterisiticas:
 * 1). que sea para windows.
 * 2). que pregunte al usuario cuantos archivos desea crear y de acuerdo a la cantidad cree los archivos correspondientes.
 * 3). los archivos creados se deben llamar file1, file2, file3, y asi sucesivamente hasta llegar a la cantidad escrita por el usuario.
 * 4). crea una funcion que agregue texto a los archivos creados y que de acuerdo al numero de archivo debe crearle una linea de texto,
 * si el file2 debe crearle, 2 lineas de texto, si es el file 3 debe crearles 3 lineas de texto y asi sucesivamente.
 * 5). crea una funcion que permita buscar el archivo mas grande osea que contenga mas lineas por ejemplo el file1 solo tiene una linea,
 * file2 tiene 2 lineas, file3 tiene 3 lineas entonces lo que debe hacer esta funcion es escoger el 3 ya que es el que contiene mas lineas.
 */

#include <iostream>
#include <filesystem>
#include <fstream> 
#include <windows.h>

using namespace std;

void agregarTexto(int cantidadArchivos, string carpetaDestino) {
    // Agregar texto a los archivos en la carpeta de destino
    for (int i = 1; i <= cantidadArchivos; i++) {
        // Definir el nombre del archivo
        string nombreArchivo = "file" + to_string(i) + ".txt";
        string rutaArchivo = carpetaDestino + nombreArchivo;

        // Crear el archivo si no existe
        if (!filesystem::exists(rutaArchivo)) {
            ofstream archivos(rutaArchivo);
            archivos.close();
        }

        // Abrir el archivo y agregar texto
        ofstream archivo(rutaArchivo, ios_base::app);
        for (int j = 1; j <= i; j++) {
            archivo << "Línea " << j << " del archivo " << nombreArchivo << endl;
        }
        archivo.close();
    }

    // Abrir la carpeta de destino en el explorador de archivos
    ShellExecute(NULL, "open", carpetaDestino.c_str(), NULL, NULL, SW_SHOWDEFAULT);
}

void buscarArchivoMasGrande(string carpetaDestino) {
    int tamanoMaximo = 0;
    string archivoMasGrande;
    for (const auto &archivo : filesystem::directory_iterator(carpetaDestino)) {
        if (filesystem::is_regular_file(archivo)) {
            int tamanoArchivo = filesystem::file_size(archivo);
            if (tamanoArchivo > tamanoMaximo) {
                tamanoMaximo = tamanoArchivo;
                archivoMasGrande = archivo.path().string();
            }
        }
    }
    if (tamanoMaximo > 0) {
        cout << "El archivo mas grande en " << carpetaDestino << " es: " << archivoMasGrande << endl;
    } else {
        cout << "No se encontraron archivos en " << carpetaDestino << endl;
    }
}

int main() {
    // Definir directorios de destino
    string parDir = "C:\\Users\\leste\\OneDrive\\Documentos\\par";
    string imparDir = "C:\\Users\\leste\\OneDrive\\Escritorio\\impar";

    // Preguntar al usuario cuántos archivos desea crear
    int cantidadArchivos;
    cout << "¿Cuántos archivos desea crear?" << endl;
    cin >> cantidadArchivos;

    // Determinar el directorio de destino según la cantidad de archivos
    string carpetaDestino;
    if (cantidadArchivos % 2 == 0) {
        carpetaDestino = parDir;
    } else {
        carpetaDestino = imparDir;
    }

    // Ejecutar la función agregarTexto y buscarArchivoMasGrande
    agregarTexto(cantidadArchivos, carpetaDestino);
    buscarArchivoMasGrande(carpetaDestino);

    return 0;
}