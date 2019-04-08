#include <stdio.h>
#include "xpaint.h"
#include "xvet.h"

void SWAP(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
    void bubbleShort(int vetor[], int tamanho){
    int aux = tamanho;
    for(int v1 = 0; v1 < tamanho; tamanho--){//depois que pecorre pela primeira vez e acha o maior, decrementa o tamanho do vetor, assim ele nao perde tempo pecorrendo um espaço desnecessario novamente;
        for(int v2 = 0; v2 < (tamanho - 1); v2++){
            xs_partition(v2, v2 + 1);// partição do valor 1 e partição do valor2
           
            //mostrar os elementos que ja estão trocados corretamente
            if(vetor[v2] < vetor[v2 + 1]){
                xs_pivot(vetor[v2 + 1]);
                    

                xd_vet(vetor, aux, "rr", v2, v2 + 1);
            }
            //Caso para quando precisar trocar o valor maior do indice antecessor com o valor menor do indice posterior
            if(vetor[v2] > vetor[v2 + 1]){
                xs_pivot(vetor[v2]);
                xd_vet(vetor, aux, "gg", v2, v2 + 1);
                SWAP(&vetor[v2], &vetor[v2 + 1]);
                xd_vet(vetor, aux, "yy", v2, v2 + 1);
            }
        }
    }
    xs_pivot(0);
    xs_partition(0, aux - 1);
    xd_vet(vetor, aux, "");
}

int main(){
     x_open(600, 600);
    xs_log("imagens/");
    int vet[] = {32 , 30, 50, 10, 8, 15, 14 ,46, 39, 19, 23};
    int size = sizeof(vet)/ sizeof(int);
    xd_vet(vet, size, "");
    bubbleShort(vet, size);
    
    x_close();
}
