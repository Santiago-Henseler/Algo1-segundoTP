#include "iniciador.h"
#include "establecer_posiciones.h"

void iniciar_estado_comida(juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){
        for(int j = 0; j<juego->comida[i].tope_ingredientes; j++){
            juego->comida[i].ingrediente[j].esta_cocinado = false;
            juego->comida[i].ingrediente[j].esta_cortado = false;
        }
    }
}

void iniciar_comidas(juego_t* juego, int precio){

    if(precio <= 100 || precio <= 150 || precio > 150){
        juego->tope_comida = 2;

        // Inicializo la ensalada
        juego->comida[0].tipo = ENSALADA;
        juego->comida[0].ingrediente[0].tipo = LECHUGA;
        juego->comida[0].ingrediente[1].tipo = TOMATE;
        juego->comida[0].tope_ingredientes = 2;

        establecer_posicion_ingredientes(&juego->comida[0], *juego);
       
        // Inicializo la pizza
        juego->comida[1].tipo = PIZZA;
        juego->comida[1].ingrediente[0].tipo = MASA;
        juego->comida[1].ingrediente[1].tipo = JAMON;
        juego->comida[1].ingrediente[2].tipo = QUESO;
        juego->comida[1].tope_ingredientes = 3;
        
        establecer_posicion_ingredientes(&juego->comida[1], *juego);

    }
    if(precio <= 150 || precio > 150){
            // Inicializo Hamburgesa
        juego->comida[2].tipo = HAMBURGESA;
        juego->comida[2].ingrediente[0].tipo = LECHUGA;
        juego->comida[2].ingrediente[1].tipo = TOMATE;
        juego->comida[2].ingrediente[2].tipo = CARNE;
        juego->comida[2].ingrediente[3].tipo = PAN;
        juego->comida[2].tope_ingredientes = 4;

        establecer_posicion_ingredientes(&juego->comida[2], *juego);

        juego->tope_comida += 1;
    }
    if(precio > 150){
        // Inicializo sanguche
        juego->comida[3].tipo = SANGUCHE;
        juego->comida[3].ingrediente[0].tipo = LECHUGA;
        juego->comida[3].ingrediente[1].tipo = TOMATE;
        juego->comida[3].ingrediente[2].tipo = QUESO;
        juego->comida[3].ingrediente[3].tipo = PAN;
        juego->comida[3].ingrediente[4].tipo = JAMON;
        juego->comida[3].ingrediente[5].tipo = MILANESA;

        juego->comida[3].tope_ingredientes = 6;
        establecer_posicion_ingredientes(&juego->comida[3], *juego);

        juego->tope_comida += 1;
    }

    iniciar_estado_comida(juego);
}

void crear_mapa(juego_t* juego){

    juego->tope_paredes = LARGO_TABLERO;

    for(int i = 0; i < LARGO_TABLERO; i++){
            for(int j = 0; j < LARGO_TABLERO; j++){
                if(i == 0 || i == LARGO_TABLERO-1 || i == (LARGO_TABLERO-1)/10){
                    juego->paredes[j].fil = i;
                    juego->paredes[j].col = j;
                } else if(j == 0 || j == LARGO_TABLERO){
                    juego->paredes[j].fil = i;
                    juego->paredes[j].col = j;
                }
            }
        }
}

void iniciar_objetos(juego_t* juego){
    
    juego->tope_herramientas = 4;

    juego->herramientas[0].tipo = CUCHILLO;
    establecer_posicion_objetos(&juego->herramientas[0], *juego);

    juego->herramientas[1].tipo = CUCHILLO;
    establecer_posicion_objetos(&juego->herramientas[1], *juego);

    juego->herramientas[2].tipo = HORNO;
    establecer_posicion_objetos(&juego->herramientas[2], *juego);

    juego->herramientas[3].tipo = HORNO;
    establecer_posicion_objetos(&juego->herramientas[3], *juego);

}

void iniciar_obstaculos(juego_t* juego){

    juego->tope_obstaculos = MAX_AGUJEROS;

    for(int i = 0; i < juego->tope_obstaculos; i++){

        establecer_posicion_agujeros(&juego->obstaculos[i],*juego, i);

        juego->obstaculos[i].tipo = AGUJERO;
    }

}

void iniciar_personaje(juego_t* juego){

    juego->stitch.objeto_en_mano = ' ';
    juego->stitch.tipo = STICH;
    establecer_posicion_personajes(&juego->stitch, *juego);

    juego->reuben.objeto_en_mano = ' ';
    juego->reuben.tipo = RUBEN;
    establecer_posicion_personajes(&juego->reuben, *juego);
   
}

void iniciar_salida(juego_t* juego){
    establecer_posicion_salida(juego);
}

// FUNCION CREAR MAPA NO SIRVE
