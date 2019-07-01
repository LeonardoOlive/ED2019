#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

struct Client{
    string id;
    int docs;
    int pac;

    Client(string id, int docs, int pac){
        this->id = id;
        this->docs = docs;
        this->pac = pac;
    }
};

struct Banco{
    vector <Client*> caixas;
    list <Client*> fila_entrada;
    queue <Client*> fila_saida;

void exibirTudo(){
list<Client*>::iterator a;
    int i = 0;
    for(i = 0; i < this->caixas.size(); i++){
        if(this->caixas[i] != nullptr){
            cout << "[" << this->caixas[i]->id << ":" << this->caixas[i]->docs << ":"  << this->caixas[i]->pac << "]";
        }else{
            cout << "[] "; 
        }  
    }
    puts("\n");
//fila_de_entrada
cout << "in: { ";
    for(a = this->fila_entrada.begin(); a != this->fila_entrada.end(); ++a)
        cout << (*a)->id << ":" << (*a)->docs << ":" << (*a)->pac << " "; 
cout << "}" << endl;
//fila_saida
cout << "out: {";
    while(!this->fila_saida.empty()){
            cout << this->fila_saida.front()->id << ":" << this->fila_saida.front()->docs << ":" << this->fila_saida.front()->pac << ";";
            this->fila_saida.pop();
    }
cout << "}" << endl;
}

void banco(int &document_perdido, int &document_processado){
    list<Client*> :: iterator a;
    int i = 0;
    while(!this->fila_saida.empty())
        this->fila_saida.pop();
    for(i = 0; i <= this->caixas.size(); i++){
        if(this->caixas[i] != nullptr){
            if(this->caixas[i]->docs > 0){
                this->caixas[i]->docs = this->caixas[i]->docs - 1;
                document_processado = document_processado + 1;
            }else{
                this->fila_saida.push(this->caixas[i]);
                this->caixas[i] = nullptr;
            }
        }else if(!this->fila_entrada.empty()){
            this->caixas[i] = this->fila_entrada.front();
            this->fila_entrada.pop_front();
        }
    }

    for( a = this->fila_entrada.begin(); a != this->fila_entrada.end(); ++a){
        if((*a)->pac > 0)
            (*a)->pac = (*a)->pac - 1;
        if((*a)->pac == 0 || (*a)->docs == 0){
            this->fila_saida.push(*a);
            document_perdido = document_perdido + (*a)->docs;
            a = this->fila_entrada.erase(a);
            a--;
        }
    }
}
};

int main(){
    Banco banco;
    string nome, comand;
    int i = 0, docs = 0, quantidade_c = 0, pac = 0, t = 0, documentos_pr = 0, documentos_pe = 0;
    auto ideal = 0;
    while(true){
        getline(cin, comand);
        stringstream dig(comand);
        dig >> comand;

        if(comand == "init"){
            dig >> quantidade_c;
            for(i = 0; i < quantidade_c; i++)
                banco.caixas.push_back(nullptr);
        }else if(comand == "in"){
            dig >> nome >> docs >> pac;
            Client * user = new Client(nome, docs, pac);
            banco.fila_entrada.push_back(user);
        }else if(comand == "show"){
            banco.exibirTudo();
        }else if(comand == "tic"){
            banco.banco(documentos_pe, documentos_pr);
            t++;
        }else if(comand == "end"){
            break;
        }else if(comand == "finish"){
            cout << "receveid: " << documentos_pr << endl;
            cout << "lost: " << documentos_pe << endl; 
            cout << "tic: " << t << endl;
        }
    }
    ideal = documentos_pr - (quantidade_c * 100);
    cout << "Quantidade ideal de caixas para maximizar o lucro: " << ideal << endl; 
}