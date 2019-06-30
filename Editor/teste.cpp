#include <iostream>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;
struct Editor
{
    list<char>:: iterator cursor;
    list<char> texto;

    Editor(){
        this->cursor = texto.begin();
    }
    void mostrar(){
       // int i;
        if(this->texto.begin() != this->texto.end()){
            for(auto i = this->texto.begin(); i != this->texto.end(); i++){
                if(i == this->cursor)
                    cout << "|";
                cout << *i;
            }
            if(this->cursor == this->texto.end())
                cout << "|";
            }else{
                cout << "|";
            }
            cout << "\n";
    }
    void escrever(char letra){
        this->texto.insert(this->cursor, letra);
        this->cursor = this->cursor++;
    }
    //Movimentações do cursor;
    void retorna(){
        escrever('\n');
    }
    void backspace(){
       // char elemento;
        if(this->cursor != this->texto.begin()){
            auto elemento = this->cursor;
            elemento--;
            this->texto.erase(elemento);
        }
    }
    void deletar(){
       // char elemento;
        if(this->cursor != this->texto.end()){
            auto elemento = this->cursor;
            this->cursor++;
            this->texto.erase(elemento);
        }
    }
    void cursorDir(){
        this->cursor++;
    }
    void cursorEsq(){
        this->cursor--;
    }
    //Fila de ações
    void desfazer(){

    }
    void refazer(){

    }

    //Movimentação avançada
    void up(){
    //[para ver a quantidade de caracteres que a string de cima tem, eu conto do \n(a esquerda do cursor) ate o proximo /n que aparecer (decrementando uma marcação)]
    //[na string atual, conto a quantidade de caracteres que tem antes do cursor(ate o \n) e depois do cursor(ate o \n)]
        //vejo se as strings relacionadas tem o mesmo tamanho
            // conto quantos caracteres tem depois do '\n' e antes do cursor (na string atual),
            // depois so multiplica por 2 essa quantidade e decrementa o cursor essa quantidade de vezes
            //
        //contador que conte quantas letras a esquerda do cursor tem ate o \n
        //Caso o cursor esteja no fim da string: decrementa o cursor a a mesma quantidade de vezes(contador) que se tem caracteres na string a qual ele esta
        //O objetivo é saber quantos caracteres tem de uma posição da string atual do cursor, ate a mesma posição na string de cima
        //so decrementar essa quantidade, contando com o '\n' é claro
    // Se nao, lascou
    }
    void down(){

    }
};
int main(){
string entrada;
Editor * editor = new Editor();
    while(true){
        getline(cin, entrada);
        stringstream dig(entrada);
        char comand;
        while(dig >> comand){
            if(comand == 'R'){
                editor->retorna();
            }else if(comand == 'B'){
                editor->backspace();
            }else if(comand == 'D'){
                editor->deletar();
            }else if(comand == '>'){
                editor->cursorDir();
            }else if(comand == '<'){
                editor->cursorEsq();
            }else if(comand == 'Z'){
                cout << "função nao implementada ainda" << endl;
            }else if(comand == 'Y'){
                cout << "função não implementada ainda" << endl;
            }else if(comand == 'A'){
                cout << "função nao implementada ainda" << endl;
            }else if(comand == 'V'){
                cout << "função nao implementada ainda" << endl;
            }else{
                editor->escrever(comand);
                //cout << "DEU ERRO, KKJKKJKJ" << endl;
                //break;
            }
        }
        editor->mostrar();
    }
}
/*for(int i = 0; i < texto[]; i++){


    cin << texto <<;


}
}*/