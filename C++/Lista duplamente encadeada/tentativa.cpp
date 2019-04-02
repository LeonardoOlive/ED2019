#include <iostream>
#include <sstream>

using namespace std;

//Estrutura do Nós
struct No{
    No * proximo;
    No * anterior;
    int number;
    No(int number = 0, No * anterior = NULL, No * proximo = NULL){
        this->number = number;
        this->anterior = anterior;
        this->proximo=proximo;
    }
};
//Estrutura da Lista 
struct Lista{
    No * inicio;
    No * fim;

    Lista(){
        inicio = new No();
        fim = new No();
        inicio->proximo = fim;
        fim->anterior = inicio;
    }




    void mostrar(){
        cout<< "[ ";
        No * no = inicio->proximo;
        while(no != fim){
            cout<< no->number <<" ";
            no = no->proximo;
        }
        cout<< " ]\n";
    }



    void inserir(No * apont, int valor){
        No * no = new No(valor, apont, apont->proximo);
        apont->proximo = no;
        no->proximo->anterior = no;
    }



    void inserir_incio(int valor){
        inserir(inicio->proximo, valor);
    }



    void inserir_fim(int valor){
        inserir(fim, valor);
    }



    void remover(No * apont){
        apont->anterior->proximo = apont->proximo;
        apont->proximo->anterior = apont->anterior;
        delete apont;
    }


    void checarIndo(){
        if(inicio->proximo == fim){
            return;
        }
        remover(inicio->proximo);
    }


    void checarVoltando(){
        if(inicio->proximo == fim){
            return;
        }
        remover(fim->proximo);
    }
};

    void Printar(Lista list, int escolha){
        cout<<"[";
        No * no = list.inicio->proximo;
            while(no != list.fim){
                if((no->number == escolha) || (no->number == escolha*(-1))){
                    if(no->number<0){
                        cout<< "<" << no->number << " ";
                    }else if(no->number >0){
                        cout<< no->number << ">" << " ";
                    }
                }else{
                    cout<< no->number <<" ";
                }
                    no = no->proximo;
            }
            cout<<"]\n";
    }



int main(){
    Lista list;
    int numeroT;
    int escolhido;
    int fase;
    int i;
    cin >> numeroT;
    cin >> escolhido;
    cin >> fase;
    for(i = 0; i < numeroT; i++){
        list.inserir_fim(i*fase);
        fase = fase * -1;
    }
Printar(list,escolhido);

  No * aux = list.inicio->proximo;

   
    int aux1;
    while(list.inicio->proximo->proximo != list.fim){
        if((aux->number == escolhido) || (aux->number == escolhido * (-1))){
            if(aux->number > 0){
                if(aux->proximo == list.fim){
                    aux = list.fim;
                    list.remover(aux->proximo);
                }else
                    list.remover(aux->proximo);
            
                if(escolhido < 0){
                    aux1 = escolhido * -1;
                }else
                    aux1 = escolhido;


                for(i = 0; i < aux1; i++){
                    aux = aux->proximo;
                    if(aux == list.fim){
                        aux = list.inicio->proximo;
                    }

                }


                escolhido = aux->number;
                Printar(list, escolhido);

            }else{
               if(aux->anterior == list.inicio){
                   aux = list.fim;
                   list.remover(aux->anterior);
               }else
                    list.remover(aux->anterior);

               if(escolhido < 0){
                   aux1 = escolhido * (-1);
               }else{
                   aux1 = escolhido;
               }
               for(i = 0; i < aux1;i++){
                   aux = aux->anterior;
                   if(aux == list.inicio){
                       aux = list.inicio->anterior;
                   }
               }
               escolhido = aux->number;
               Printar(list, escolhido);
            }

        }
        else
            aux = aux->proximo;
    }
    
}
