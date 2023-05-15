#include <stdio.h>
#include "chambuchito.h"

// Declaración de constantes 
const int TAMANO_MAX = 30;
const int TAMANO_MIN = 15;

const char PAN_BLANCO = 'B';
const char PAN_INTEGRAL = 'I';
const char PAN_AVENA_MIEL = 'A';
const char PAN_QUESO_OREGANO = 'Q';

const char QUESO_DAMBO = 'D';
const char QUESO_CHEDDAR = 'C';
const char QUESO_GRUYERE = 'G';
const char SIN_QUESO = 'S';

const char ROAST_BEEF = 'R';
const char ATUN = 'A';
const char SOJA = 'S';
const char POLLITO = 'P';
const char SIN_PROTE = 'N';

const char NO_CALENTAR = 'N';
const char SI_CALENTAR = 'S';

const double AJUSTE_PRECIO = 0.3;

// PRE: - 
// POST: Selecciona el tamaNo de pan deseado por el usuario en un intervalo = [15,30]
void TAMANO_PAN(int* tamano){

    printf("¿De qué medida dese su chambuchito? El tamaNo es entre 15cm y 30cm\n");
    scanf("%i", tamano);

    while (*tamano > TAMANO_MAX || *tamano < TAMANO_MIN){
        if(*tamano > TAMANO_MAX){
            printf("Te exediste un poco, el tamaNo es entre 15cm y 30cm\n");
            scanf("%i", tamano); 
        }else{
            printf("Te quedaste medio corto, el tamaNo es entre 15cm y 30cm\n");
            scanf("%i", tamano);
        }
    }
}

// PRE: -
// POST: Selecciona el tipo de pan deseado por el usuario y agrega su valor al total
void TIPO_PAN(char* tipo_pan, int* total){

    printf("¿Qué pan desea? Tenemos blanco(B), integral(I), avena y miel(A) y queso y orégano(Q)\n");
    scanf(" %c", tipo_pan);

    while (*tipo_pan != PAN_BLANCO && *tipo_pan  != PAN_INTEGRAL && *tipo_pan != PAN_AVENA_MIEL && *tipo_pan != PAN_QUESO_OREGANO){
        printf("De ese pan no me queda, pero tenemos blanco(B), integral(I), avena y miel(A) y queso y orégano(Q)\n");
        scanf(" %c", tipo_pan);
    }

    if(*tipo_pan == PAN_BLANCO || *tipo_pan == PAN_INTEGRAL){
        *total += 5;
        }else if(*tipo_pan == PAN_AVENA_MIEL || *tipo_pan == PAN_QUESO_OREGANO){
            *total += 8;
        }
}

// PRE: -
// POST: Devuelve el tipo de queso deseado por el usuario y agrega su valor al total 
void TIPO_QUESO(char* tipo_queso, int* total){
    printf("¿Qué tipo de queso desea? Tenemos dambo(D), cheddar(C), gruyere(G) o podes elegir sin queso(S)\n");
    scanf(" %c", tipo_queso);

    while (*tipo_queso != QUESO_DAMBO && *tipo_queso  != QUESO_CHEDDAR && *tipo_queso != QUESO_GRUYERE && *tipo_queso != SIN_QUESO){
        printf("De ese queso no me queda, pero tenemos dambo(D), cheddar(C), gruyere(G) o podes elegir sin queso(S)\n");
        scanf(" %c", tipo_queso);
    }

    if(*tipo_queso == QUESO_CHEDDAR || *tipo_queso == QUESO_DAMBO){
        *total += 5;
        }else if(*tipo_queso == QUESO_GRUYERE){
            *total += 8;
        }
}

// PRE: -
// POST: Devuelve el tipo de proteina deseado por el usuario y agrega su valor al total
void TIPO_PROTEINA(char* tipo_proteina, int* total){
    printf("¿Qué tipo de proteina desea? Tenemos roast beef(R), atun(A), soja(S), soja(P) o podes elegir sin proteina(N)\n");
    scanf(" %c", tipo_proteina);

    while (*tipo_proteina != ROAST_BEEF && *tipo_proteina  != ATUN && *tipo_proteina != SOJA && *tipo_proteina != POLLITO && *tipo_proteina != SIN_PROTE){
        printf("De esa proteina no me queda, pero tenemos roast beef(R), atun(A), soja(S), soja(P) o podes elegir sin proteina(N)\n");
        scanf(" %c", tipo_proteina);
    }

    if(*tipo_proteina == ROAST_BEEF){
        *total += 7;
        }else if(*tipo_proteina == ATUN){
            *total += 9;
            }else if(*tipo_proteina == SOJA){
                *total += 3;
                }else if(*tipo_proteina == POLLITO){
                    *total += 5;
                }
}

//PRE: El usuario debio de elegir una proteina =! a atún
//POST: Se le pregunta n veces al usuario hasta que de una respuesta correcta
void CALENTAR(){
    char caletar = ' ';

    printf("¿Quiere que se lo calentemos? si(S) o no(N)");
    scanf(" %c", &caletar);

    while (caletar  != NO_CALENTAR && caletar != SI_CALENTAR){
        printf("Entonces... ¿Quiere que se lo calentemos? si(S) o no(N)");
        scanf(" %c", &caletar);
    }
}

//PRE: Recibir dos valores enteros validos
//POST: Devuelve el valor del sanguche a partir de una ecuación
int CALCULAR_PRECIO(int valor_total, int tamaNo){
    int respuesta = 0;

    respuesta =  (int)(valor_total * AJUSTE_PRECIO * tamaNo);
    return respuesta;
}

void calcular_precio_chambuchito(int* p_final){

    int valor_total = 0;
    int precio_sanguche = 0;

    int tamano = 0;
    TAMANO_PAN(&tamano);

    char tipo_pan = ' ';
    TIPO_PAN(&tipo_pan, &valor_total);

    char tipo_queso = ' ';
    TIPO_QUESO(&tipo_queso, &valor_total);

    char tipo_proteina = ' ';
    TIPO_PROTEINA(&tipo_proteina, &valor_total);

    if(tipo_proteina != ATUN){
        CALENTAR();
    }

    precio_sanguche = CALCULAR_PRECIO(valor_total, tamano);
    printf("El valor del pedido es -%i-\n", precio_sanguche);

    *p_final = precio_sanguche;
}