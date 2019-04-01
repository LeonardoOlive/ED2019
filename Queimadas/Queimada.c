#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

int lados = sizeof(Lin) / sizeof(int);
int Lin[] = {0, -1, 0, 1}; //left, up, right, down
int Col[] = {-1, 0, 1, 0}; //left, up, right, down


const char ARV = '#';
const char FOG = 'o';
const char ESV = '.'; 
const char BURN = 'x';

void imprimir(int nl, int nc, char matriz[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            printf(" %c", matriz[l][c]);
        }
    }
    getchar();
}
void aleatorio(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        int esco = rand() % tam;
        int temp = vet[i];
        vet[i] = vet[esco];
        vet[esco] = temp;
    }

}

int burn(int nl, int nc, char matriz[nl][nc], int l, int c){
    if( (l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0; 

    if(matriz[l][c] != ARV)
        return 0;


    matriz[l][c] = FOG;
    imprimir(nl, nc, matriz);
    int cont = 1;
    int neib[] = {0, 1, 2, 3};
    aleatorio(neib, nl);
    for(int v = 0; v < nl; v++){
        int i = neib[v];
        cont += burn(nl, nc, matriz, l + Lin[i], c + Col[i]);
    }
    matriz[l][c] = BURN;
    imprimir(nl, nc, matriz);

    return cont;

}

int main(void)
{
    srand(time(NULL));

    int nl = 0;
    int nc = 0;
    int porce_arv = 0;

    printf("Diga como quer sua matriz!\n");
    scanf("%d %d", &nl, &nc);

    printf("Digite a porcentagem de arvores(max 100)\n");
    scanf("%d", &porce_arv);

    char matriz[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(rand() % 101 <= porce_arv)
                matriz[l][c] = ARV;
            
            else    
                matriz[l][c] = ESV;
        }
    }

    imprimir(nl, nc, matriz);

    printf("Onde você quer queimar?\n");
    int l = 0; 
    int c = 0; 
    scanf("%d %d", &l, &c);

    int total = 0;
    total = burn(nl, nc, matriz, l, c);
    imprimir(nl, nc, matriz);

    printf("temos um total de %d arvores queimadas", total);
    
    return 0;
}

