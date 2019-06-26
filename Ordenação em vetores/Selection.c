#include "xpaint.h"
#include "xvet.h"


#define SWAP(a, b, tipo) do{tipo SWAP = a; a = b; b = SWAP;}while(0);

void selection(int vet[], int size){
    for(int i = 0; i < n ; i++){
        int menor = i;
        for(int j = i+1; j < n; j++){
            if(vet[j] < vet[menor])
                menor = j;
        }
        if(menor != i){
            SWAP(vet[i],vet[menor]);
        }

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
