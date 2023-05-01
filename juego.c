#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chambuchito.h"
#include "cocineritos.h"

int main(){

    int precio = 10;
    juego_t juego;
    srand((unsigned)time(NULL));

    char movimiento = ' ';
    
    //calcular_precio_chambuchito(&precio);

    inicializar_juego(&juego, precio);
    
    imprimir_terreno(juego);

    while(estado_juego(juego) == 0){
        printf("realiza movimento");
        scanf(" %c", &movimiento);
        realizar_jugada(&juego, movimiento);
    }
    
    return 0;
} 

