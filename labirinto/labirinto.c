#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Pos{
    int l, c;
}Pos;

#define capturar_vizinhos(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};


void aleatoriar(Pos vet[], int size){
    int i, posicao;
    Pos aux;
    for(i = 0; i < size; i++){
        posicao = rand() % size;
        aux = vet[i];
        vet[i] = vet[posicao];
        vet[posicao] = aux;
    }
}

bool semelhantes(int nlin, int ncol, char matriz[nlin][ncol], char value, int lin, int col){
    int i;
    if((lin < 0) || (lin >= nlin) || (col < 0) || (col >= ncol)){
        return false;
    }else
        return matriz[lin][col] == value;
}

void exibir(int nlin, int ncol, char matriz[nlin][ncol]){
    int auxl = 0, auxc = 0;

    for(auxl = 0; auxl < nlin; auxl++){
        for(auxc = 0; auxc < ncol; auxc++){
            printf("%c", matriz[auxl][auxc]);
        }
       // printf("\n");
    }
}

bool procurar_saida(int lin, int col, int nlin, int ncol, char matriz[nlin][ncol], char mvisited[lin][col],int lsaida, int csaida){
    int i = 0;

    if((lin >= nlin) || (lin < 0) || (col >= ncol) || (col < 0))
        return false;
    if(matriz[lin][col] != ' ')
        return false;

     matriz[lin][col] = '.';
    
    if(lin == lsaida && col == csaida) // objetivo: fazer com que a coordenada(lin, col) seja igual a coordenada da saida
        return true;

    if(procurar_saida(lin, col - 1, nlin, ncol, matriz, mvisited, lsaida, csaida) == true)
        return true;

    if(procurar_saida(lin - 1, col, nlin, ncol, matriz, mvisited, lsaida, csaida) == true)
        return true;

    if(procurar_saida(lin + 1, col, nlin, ncol, matriz, mvisited, lsaida, csaida) == true)
        return true;

    if(procurar_saida(lin, col + 1, nlin, ncol, matriz, mvisited, lsaida, csaida) == true)
        return true;

    matriz[lin][col] = ' ';// objetivo falhou
    return false;
}

bool visitados(int lin, int col, int nlin, int ncol, int matriz[nlin][ncol]){
    if(matriz[lin][col] == '.')
        return true;
}


bool podeFurar(int nlin, int ncol, char matriz[nlin][ncol], int lin, int col){
    int i = 0, cont = 0;
    Pos vizinhos[] = capturar_vizinhos(lin, col);
    if(!semelhantes(nlin, ncol, matriz, '#', lin, col))
        return false;
    
    for(i = 0; i < 4; i++){
        if(semelhantes(nlin, ncol, matriz, '#', vizinhos[i].lin, vizinhos[i].col))
            cont++;
    }
        if(cont < 3)
            return false;
        return true;
}
void furar(int nlin, int ncol, char matriz[nlin][ncol], int lin, int col){
    if(!podeFurar(nlin, ncol, matriz, lin, col))
        return;
    
    matriz[lin][col] = ' '; // furando
    Pos vizinhos[] = capturar_vizinhos(lin , col);
    aleatoriar(vizinhos, 4);
    for(int i = 0; i < 4; i++){
        furar(nlin, ncol, matriz, vizinhos[i].lin, vizinhos[i].col);
    }

}

int main(int argc, char * argv[]){
	srand(time(NULL));
	int i;
	int nl = 0, nc = 0;
    int l_ini = 0, c_ini = 0, l_end = 0, c_end = 0;
	
	
	printf("tamanho da matriz: ");
	scanf("%d %d", &nl, &nc);
	char matriz[nl][nc];
	char matriz_visitados[nl][nc];
	char * posicao = &matriz[0][0];
	
	for(i = 0; i < nl * nc; i++)
		posicao[i] = '#';
	
	furar(nl, nc, matriz, 1 ,1);
    exibir(nl, nc, matriz);
	
	printf("cordenadas de inicio: \n");
	scanf("%d %d",&l_ini, &c_ini);
	
	printf("coordenadas de fim: \n");
	scanf("%d %d", &l_end, &c_end);

	while(procurar_saida(l_ini, c_ini, nl, nc, matriz, matriz_visitados, l_end, c_end)){
		printf("novas coordenadas de fim: \n");
		scanf("%d %d", &l_end, &c_end);
	}
	procurar_saida(l_ini, c_ini, nl, nc, matriz, matriz_visitados, l_end, c_end);
	exibir(nl, nc, matriz);
	
	return 0;
}
