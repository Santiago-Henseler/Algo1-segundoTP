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

        juego->tope_comida = 0;

        // Inicializo la ensalada
        if(juego->comida_actual == ENSALADA){
            juego->comida[juego->tope_comida].tipo = ENSALADA;

            juego->comida[juego->tope_comida].tope_ingredientes = 0;
            juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = LECHUGA;
            juego->comida[juego->tope_comida].tope_ingredientes++;
            juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = TOMATE;
            juego->comida[juego->tope_comida].tope_ingredientes++;

            establecer_posicion_ingredientes(&juego->comida[juego->tope_comida], *juego);
            juego->tope_comida++;
        }else if(juego->comida_actual == PIZZA){    // Inicializo la pizza
            juego->comida[juego->tope_comida].tipo = PIZZA;

            juego->comida[juego->tope_comida].tope_ingredientes = 0;
            juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = MASA;
            juego->comida[juego->tope_comida].tope_ingredientes++;
            juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = JAMON;
            juego->comida[juego->tope_comida].tope_ingredientes++;
            juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = QUESO;
            juego->comida[juego->tope_comida].tope_ingredientes++;

            establecer_posicion_ingredientes(&juego->comida[juego->tope_comida], *juego);

            juego->tope_comida++;
        }

 
    if(precio > SEGUNDO_MENU && juego->comida_actual == HAMBURGESA){
        // Inicializo Hamburgesa
        juego->comida[2].tipo = HAMBURGESA;

        juego->comida[juego->tope_comida].tope_ingredientes = 0;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = LECHUGA;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = TOMATE;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = CARNE;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = PAN;
        juego->comida[juego->tope_comida].tope_ingredientes++;

        establecer_posicion_ingredientes(&juego->comida[juego->tope_comida], *juego);
        juego->tope_comida++;
    }

    if(precio > TERCER_MENU){
        // Inicializo sanguche
        juego->comida[juego->tope_comida].tipo = SANGUCHE;

        juego->comida[juego->tope_comida].tope_ingredientes = 0;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = LECHUGA;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = TOMATE;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = QUESO;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = PAN;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = JAMON;
        juego->comida[juego->tope_comida].tope_ingredientes++;
        juego->comida[juego->tope_comida].ingrediente[juego->comida[juego->tope_comida].tope_ingredientes].tipo = MILANESA;
        juego->comida[juego->tope_comida].tope_ingredientes++;


        establecer_posicion_ingredientes(&juego->comida[juego->tope_comida], *juego);

        juego->tope_comida++;
    }

    iniciar_estado_comida(juego);
}

void crear_mapa(juego_t* juego){

    juego->tope_paredes = 0;

    for(int i = 0; i < LARGO_TABLERO; i++){
            for(int j = 0; j <= LARGO_TABLERO; j++){
                    if(i == 0 || i == 20 || i == 10){
                        juego->paredes[juego->tope_paredes].fil = i;
                        juego->paredes[juego->tope_paredes].col = j;
                        juego->tope_paredes++;
                        
                    }else if(j == 0 || j == LARGO_TABLERO){
                        juego->paredes[juego->tope_paredes].fil = i;
                        juego->paredes[juego->tope_paredes].col = j;
                        juego->tope_paredes++;
                    }
            }
        }
}

void iniciar_objetos(juego_t* juego){
    
    juego->tope_herramientas = 0;

    juego->herramientas[juego->tope_herramientas].tipo = CUCHILLO;
    establecer_posicion_objetos(&juego->herramientas[juego->tope_herramientas], *juego);

    juego->tope_herramientas++;

    juego->herramientas[juego->tope_herramientas].tipo = CUCHILLO;
    establecer_posicion_objetos(&juego->herramientas[juego->tope_herramientas], *juego);

    juego->tope_herramientas++;

    juego->herramientas[juego->tope_herramientas].tipo = HORNO;
    establecer_posicion_objetos(&juego->herramientas[juego->tope_herramientas], *juego);

    juego->tope_herramientas++;

    juego->herramientas[juego->tope_herramientas].tipo = HORNO;
    establecer_posicion_objetos(&juego->herramientas[juego->tope_herramientas], *juego);

    juego->tope_herramientas++;
}

void iniciar_obstaculos(juego_t* juego){
    juego->tope_obstaculos = 0;

    for(int i = 0; i < MAX_AGUJEROS; i++){
        establecer_posicion_agujeros(&juego->obstaculos[i],*juego, i);
        juego->tope_obstaculos++;
        juego->obstaculos[i].tipo = AGUJERO;
    }

}

void iniciar_personaje(juego_t* juego){

    juego->stitch.objeto_en_mano = SIN_OBJETO_EN_MANO;
    juego->stitch.tipo = STICH;
    establecer_posicion_personajes(&juego->stitch, *juego);

    juego->reuben.objeto_en_mano = SIN_OBJETO_EN_MANO;
    juego->reuben.tipo = RUBEN;
    establecer_posicion_personajes(&juego->reuben, *juego);
   
}

void iniciar_salida(juego_t* juego){
    establecer_posicion_salida(juego);
}

void iniciar_fuego_matafuego(juego_t* juego){
    
    juego->obstaculos[juego->tope_obstaculos].tipo = FUEGO;
    juego->tope_obstaculos++;

    juego->herramientas[juego->tope_herramientas].tipo = MATAFUEGO;
    juego->tope_herramientas++;

    int posicion = rand() % 19 + 1;

    if(posicion < 10){
        posicion = 0;
    }else{
        posicion = 1;
    }

    for(int i = 0; i < juego->tope_obstaculos; i++){
        if(juego->obstaculos[i].tipo == FUEGO){
            
            establecer_posicion_fuego_matafuego(juego, posicion, &juego->obstaculos[i]);
        }
    }
    for(int i = 0; i < juego->tope_herramientas; i++){
        if(juego->herramientas[i].tipo == MATAFUEGO){
            
            establecer_posicion_fuego_matafuego(juego, posicion, &juego->herramientas[i]);
        }
    }
}

