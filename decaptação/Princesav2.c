#include <stdio.h>
#include <stdbool.h>
// n = numero de participantes
// esp = escolhido
// t = tamanho
// v = vetor

// fun??o para imprimir o vetor sabendo quespm esta morto ou ? o escolhido
void Vet(int v[], int n, int esp){
    int i;
    printf("[");
    for(i = 0; i < n; i++){
        if(v[i] != 0){
            if(i == esp){
                if(v[i] < 0)
                    printf(" <%d", v[i]);   
                else
                printf(" %d>", v[i]);
        }else
            printf(" %d", v[i]);
        }
    }
            printf(" ]\n");
}

int ProcurarV(int v[], int n, int esp){
    int size = n;
    int posi = (esp + 1) % size;
    while(v[posi] == 0){
        posi = (posi + 1) % size;
    }
    return posi;
}

int ProcurarVi(int v[], int n, int esp){
    int size = n;
    int posi = (esp - 1) % size;
    if(posi < 0){
        posi = size - 1;
    while(v[posi] == 0){
        posi = (posi - 1) % size;
        if(posi < 0){
            posi = size - 1;
        }
    }
    return posi;
}

int main(){
    int n = 0, esp = 0, i = 0, fase = 0, t = 0;
    int Vivo;
   //printf("Digite o numero de participantes:\n");
    scanf("%d", &n);
   //printf("escolha um numero:\n");
    scanf("%d", &esp);
    //printf("escolha se o elemento 1 sera positivo ou negativo:\n");
    scanf("%d", &fase);
    int v[n];
    Vivo = n;
    Vet(v, n, esp);
    int aux1 = 0, aux2 = 0;
    aux1 = esp+1;

    while(Vivo > 1){
        if(v[esp] < 0){
            aux1 = ProcurarVi(v,n, esp);
            v[aux1] = 0;
            aux2 = esp+1;
        for(i = 0; i < aux2; i++){
            esp = ProcurarVi(v, n, esp;
            aux1 = esp;
        }

    }else{
        aux1 = ProcurarVi(v, n, esp);
        v[aux1] = 0;
        aux2 = esp+1;
        for(i = 0; i < aux2; i++){
            esp = ProcurarV(v, n, esp);
            aux1 = esp;
        }
    }
    Vet(v, n, esp);
    Vivo = Vivo - 1;
    }
}
