#include "data_structures/Lista.h"
#include "core/reproductor.h"
#include "core/configuracion.h"
#include "core/archivos.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    Lista lista;
    Lista registros;
    
    cargarTxt(lista, registros);
    if (lista.getActual() == nullptr && lista.getStart() != nullptr) {
        lista.Cfg(lista.getStart());
    }
    cargarCfg(lista,registros);
    
    Node* actual;
    string opcion;
    
    do {
        actual = lista.getActual();
        mostrarMenu(actual, lista);
        cin >> opcion;
        for (char &c : opcion) {
		    c = toupper(c);
		}
        if (opcion == "W") {
            pausar(lista);
        }
        else if (opcion == "Q") {
        	actual = lista.getActual();
            if (actual != nullptr && actual->id == idcfg) {
                cout<<""<<endl;
            } else {
				if (actual != nullptr && actual->prev != nullptr) {
		        	int idActual = actual->id;
		            lista.anterior();
		            reproduciendo = true;
		            actual = lista.getActual();
					if (actual != nullptr && actual->id != idcfg) {
	                	registros.eliminar(actual->id);
		            }
		            registrar(actual, registros);
           		}
        	}
    	}	
        else if (opcion == "E") {
            if (idcfg == -1) {
                if (actual != nullptr) {
            		idcfg = actual->id;
            		cfgant = true;
            		reproduciendo = true;
        		}
            } else {
                lista.siguiente();
                reproduciendo = true;
                actual = lista.getActual();
                if (registros.getStart() == nullptr) {
                    registrar(actual, registros);
                }
                if (actual == nullptr) {
                    idcfg = -1;
                } else{
                	registrar(actual, registros);
				}
            }
        }
        else if (opcion == "S") {
            lista.alternarAleatorio();
            cfgant = true;
        }
        else if (opcion == "R") {
            lista.repeticion();
        }
        else if (opcion == "A") {
            string option2;
            do {
                menu_2(registros, actual, lista);
                cin >> option2;
                for (char &c : option2) {
                    c = toupper(c);
                }
                if (option2.length() > 1 && option2[0] == 'S') {
                    bool esNumero = true;
                    string numero;
                    for (size_t i = 1; i < option2.length(); i++) {
                        if (!isdigit(option2[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option2[i];
                    }
                    int numer;
                    if(cfgant == false){
                        numer = stoi(numero) - 1;
                    } else{
                        numer = stoi(numero);
                    }
                    cfgant = true;
                    if (esNumero) {
                        for (int i = 0; i < numer; i++) {
                            if (registros.getStart() == nullptr) {
                                registrar(actual, registros);
                            }
                            lista.siguiente();
                            reproduciendo = true;
                            actual = lista.getActual();
                            registrar(actual, registros);
                        }
                    } else {
                        cout << "Error: Ingrese un número después de S" << endl;
                    }
                }
            } while (option2 != "V");
        }
        else if (opcion == "L") {
			string option3;
            do{
                menu_3(registros, actual, lista);
                cin >> option3;
                for (char &c : option3) {
                    c = toupper(c);
                }
                if (option3.length() > 1 && option3[0] == 'R'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option3.length();i++){
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3[i];
                    }
                    if (esNumero) {
                        Node* temp = lista.buscar(stoi(numero));
                        reproduciendo=true;
                        cfgant = true;
                        lista.reproducirsong(temp->id);
                        actual=lista.getActual();
                        registrar(actual,registros);
                    } else {
                        cout << "Error: Ingrese un número después de R" << endl;
                    }
                }
                if (option3.length() > 1 && option3[0] == 'A'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option3.length();i++){
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3[i];                    }
                    if (esNumero) {
                        cfgant = true;
                        Node* temp = lista.buscar(stoi(numero));
                        reproduciendo=true;
                        lista.Songfin(temp->id,lista);
                    } else {
                        cout << "Error: Ingrese un número después de D" << endl;
                    }
                }
                if (option3 == "N"){
                    int idnew = lista.ultimaSong();
                    
                    int id,year,duracion;
                    string nombre, artista, album,ruta;
                    cout<<"Nombre de la cancion: "<<endl;
                    cin >> nombre;
                    cout<<"Artista: "<<endl;
                    cin >> artista;
                    cout<<"Album: "<<endl;
                    cin >> album;
                    cout<<"Año: "<<endl;
                    cin >> year;
                    cout<<"Duracion (en segundos): "<<endl;
                    cin >> duracion;
                    cout<<"Ruta de la cancion: "<<endl;
                    cin >> ruta;
                    Node* nuevo = new Node(idnew, nombre, artista, album, year, duracion, ruta);
                    lista.agregar(nuevo);
                    cfgant = true;
                }
                if (option3.length() > 1 && option3[0] == 'D'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option3.length();i++){
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3[i];
                        }
                    if (esNumero) {
                        cfgant = true;
                        lista.eliminar(stoi(numero));
                        registros.eliminar(stoi(numero));
                    } else {
                        cout << "Error: Ingrese un número después de D" << endl;
                    }
                }
            } while (option3 != "V");
        }
		else if (opcion == "x") {
            break;
        }
        else {
            cout << "opcion invalida" << endl;
        }
    } while (opcion != "X");
    
    guardarCfg(lista);
    
    return 0;
}