#include <stdio.h>
#include "xpaint.h"
#include "xvet.h"

void SWAP(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
 
    
    void Insertion(int vetor[], int tamanho){
        for(int i = 0; i < tamanho; i++){
            xs_partition(0, i);//linha de "execução"
            xd_vet(vetor, tamanho, "g", i);// mostra o primeiro valor do vetor
            for(int k = i; k > 0; k--){
                //Dentro os processados procura o menor elemento e organiza eles 
                if(vetor[k] < vetor[k - 1]){
                    xd_vet(vetor, tamanho, "ym", k, k-1);
                    SWAP(&vetor[k], &vetor[k-1]);
                    xd_vet(vetor, tamanho, "my", k, k-1);
                }else{
                    xd_vet(vetor, tamanho,"", k);
                    break;
                }
            }
            if(i < 2){
                xd_vet(vetor, tamanho, "w", i);
            }

        }
    }
            
int main(){
    x_open(600, 600);
    xs_log("imagens/");
    int vet[] = {32 , 30, 50, 10, 8, 15, 14 ,46, 39, 19, 23};
    int size = sizeof(vet)/ sizeof(int);
    xd_vet(vet, size, "");
    Insertion(vet, size);
    
    x_close();
}
