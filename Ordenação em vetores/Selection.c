#include "xpaint.h"
#include "xvet.h"

//Arquivo que o professor ensinou em sala

#define SWAP(a, b, tipo) do{tipo SWAP = a; a = b; b = SWAP;}while(0);

//find inicio de menor na partição [inicio, fim[
int find_indiceMenor(int vet[], int size, int inicio, int fim){
    int imenor = inicio;
    for(int i = inicio + 1; i < fim; i++ ){
        if(vet[i] < vet[imenor]){
            imenor = i;
            //achar o amarelo(menor) e troca com o verde
        xd_vet(vet, size, "gr", i, imenor);
        }
    }
        return imenor;
}

void selection(int vet[], int size){
    for(int i = 0; i < size; i++){
        xs_partition(i, size-1);
        int imenor = find_indiceMenor(vet, size, i, size);
        //Pega o Vermelhor (maior valor) e troca com o menor(rosa)
        xd_vet(vet, size, "mr", imenor, i);
        SWAP(vet[i], vet[imenor], int);
       // xd_vet(vet, size, "mr", imenor, i);
    }
}

int main(){
    x_open(600, 700);
    xs_log("imagens/");
    int vet[] = {52 , 30, 50, 10, 8, 15, 14 ,86, 89, 69, 63};
    int size = sizeof(vet)/ sizeof(int);
    xd_vet(vet, size, "");
    selection(vet, size);
    
    x_close();
}
