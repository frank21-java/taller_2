#pragma once

class Sistema {
private:
    Lista lista;
    Lista registros;

    void menuPrincipal();
    void menuLista();
    void menuCanciones();

public:
    void iniciar();
};