#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chambuchito.h"
#include "cocineritos.h"

int main(){

    int precio = 0;
    char movimiento = ' ';
    
    juego_t juego;
    srand((unsigned)time(NULL));

    calcular_precio_chambuchito(&precio);

    inicializar_juego(&juego, precio);
    
    imprimir_terreno(juego);

    while(estado_juego(juego) == 0){

        imprimir_terreno(juego);
        printf("realiza movimento");
        scanf(" %c", &movimiento);
        
        realizar_jugada(&juego, movimiento);
    }
    
    if(estado_juego(juego) == 1){

        printf("Felicidades ganaste!!");
    }else if(estado_juego(juego) == -1){

        printf("Perdiste :( ");
    }

    return 0;
} 

