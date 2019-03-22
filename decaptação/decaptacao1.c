#include <stdio.h>
#include <stdbool.h>
// n = numespro desp participantesps
// esp = espscolhido
// t = tamanho
// v = vesptor

// função para imprimir o vesptor sabespndo quespm espsta morto ou é o espscolhido
void Vet(int v[], int n, int esp){
    int i;
    printf("[");
    for(i = 0; i < n; i++){
        if(v[i] != 0){
            if(i == esp)
                printf(" %d>", v[i]);
            else
                printf(" %d", v[i]);
        }
    }
        printf(" ]\n");
}
// procurar os vivos
int ProcurarV(int v[], int n, int esp){
    int size = n;
    int posi = (esp + 1) % size;
    while(v[posi] == 0){
        posi = (posi + 1) % size;
    }
    return posi;
}


int main(){
    int n = 0, esp = 0, i = 0, fase = 0, t = 0;
    int Morto;
    //printf("Digite o numero de participantes:\n");
    scanf("%d", &n);
    //printf("escolha se o elemento 1 sera positivo ou negativo:\n");
    scanf("%d", &fase);
    int v[n];
    for(i = 0; i < n; i++){
        v[i] = (i + 1) * fase;
        fase = fase * -1;
    }
    //printf("escolha um numero:\n");
    scanf("%d", &esp);
    esp = esp - 1;
    Vet(v, n, esp);
    t = n;
    while(t>1){
        Morto = ProcurarV(v, n , esp);
        v[Morto] = 0;
        esp = ProcurarV(v, n, Morto);
        Vet(v, n, esp);
        t--;
    }
}
