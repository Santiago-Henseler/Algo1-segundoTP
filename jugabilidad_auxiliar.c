#include "jugabilidad_auxiliar.h"

bool no_tiene_objeto_en_mano(personaje_t personaje){

    return personaje.objeto_en_mano == SIN_OBJETO_EN_MANO;
}

bool mesa_vacia(int fil, int col){

    return distancia_manhattan(POSICION_MESA, POSICION_MESA, fil,col) != 0;
}

bool esta_listo(int i, comida_t comida){
    bool rta = false;

    if(ingrediente_de_ruben(i,  comida)){
        rta = comida.ingrediente[i].esta_cocinado;
    }else{
        rta = comida.ingrediente[i].esta_cortado;
    }

    return rta;
}

int distancia_manhattan(int fil1, int col1, int fil2, int col2){
    int distancia = 0;
    int fila = 0;
    int columna = 0;

    fila = fil1 - fil2;
    
    if(fila < 0){
        fila *= -1;
    }

    columna = col1 - col2;

    if(columna < 0){
        columna *= -1;
    }

    distancia = fila + columna;

    return distancia;
}

bool puede_usar_herramienta(personaje_t personaje, juego_t juego, char herramienta){
    bool rta = false;

    for(int i = 0; i < juego.tope_herramientas; i++){
    
        if(herramienta == CUCHILLO){
            if(juego.herramientas[i].tipo == herramienta && distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, personaje.posicion.fil, personaje.posicion.col) == 0){
                
                rta = true;
            }
        }else{
            if(juego.herramientas[i].tipo == HORNO &&  distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, personaje.posicion.fil, personaje.posicion.col) == 1){
            
                rta = true;
            }
        }
    }
    return rta;
}

bool ya_entregado(juego_t juego, char comida){
    bool rta = false;

    for(int i = 0; i < juego.tope_comida; i++){
        if(comida == juego.comida_lista[i].tipo){
            rta = true;
        }
    }
    return rta;
}

bool termino_comida(juego_t juego){
    bool rta = false;

    for(int i = 0; i< juego.tope_comida; i++){
        
        if(juego.comida_actual == juego.comida[i].tipo){
            if(juego.comida[i].tope_ingredientes == juego.tope_comida_lista){
                rta = true;
            }
        }
    }
    return rta; 
}

bool puede_avanzar(int fil, int col){
    bool rta = true;

    if(col == 0 || col == 20){
        rta = false;
    }else if(fil == 0 || fil == 10 || fil == 20){
        rta = false;
    }
    return rta;
}

void hud(juego_t juego){

    char objeto = SIN_OBJETO_EN_MANO;

    if(juego.personaje_activo == 'S'){
        objeto = juego.stitch.objeto_en_mano;
    }else{
        objeto = juego.reuben.objeto_en_mano;
    }

    printf("Personaje activo: %c Objeto activo: %c\n", juego.personaje_activo, objeto);
}