#include "Cadastro.h"
#include <algorithm>


Cadastro::Cadastro(string fileName){
    this->fileName = fileName;
    //recupera();
}

Cadastro::~Cadastro(){
    }

/*void Cadastro::recupera(){
    int tam;
    string nome;
    double tamanho;
    int qtdePatas;
    string especie;
    string cor;
    int cff;
    Formigueiro* formigueiro;
    Formiga* formiga;
    int tipo;
    int QtdQueCarrega;
    double velocidade;
    double qtdJaCarregada;
    int QtdOvos;
    int QtdOvosJaPostos;
    double requisito;
    string patente;
    int experiencia;
    FormigaOP* fop;
    FormigaRainha* fr;
    FormigaSoldado* fs;

    ifstream entrada(fileName, ios::binary);
    if (entrada.is_open()) {

        Formigas.clear();
        while(entrada.good()){
            
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);
            entrada.read(reinterpret_cast<char *>(&nome[0]), tam);

            entrada.read(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            
            entrada.read(reinterpret_cast<char*>(&especie)
            entrada.read(reinterpret_cast<char *>(&especie[0]), tam);
            entrada.read(reinterpret_cast<char *>(&cor), sizeof(cor));
            entrada.read(reinterpret_cast<char *>(&cff), sizeof(cff));
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            formigueiro = NULL;
            if (tam > 0){
                formigueiro = new Formigueiro();
                formigueiro->setNome(nome);
            }
            entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
            switch(tipo){
                case 0:
                    entrada.read(reinterpret_cast<char *>(&QtdQueCarrega), sizeof(QtdQueCarrega));
                    entrada.read(reinterpret_cast<char *>(&velocidade), sizeof(velocidade));
                    entrada.read(reinterpret_cast<char *>(&qtdJaCarregada), sizeof(qtdJaCarregada));
                    Formigas.push_back( new FormigaOP(nome,tamanho,qtdePatas,especie,cor,cff,"Operaria",QtdQueCarrega,velocidade));
                    dynamic_cast<FormigaOP*>(formiga)->setQtdJaCarregada(qtdJaCarregada);
                    break;
                case 1:
                    entrada.read(reinterpret_cast<char *>(&QtdOvos), sizeof(QtdOvos));
                    entrada.read(reinterpret_cast<char *>(&QtdOvosJaPostos), sizeof(QtdOvosJaPostos));
                    entrada.read(reinterpret_cast<char *>(&requisito), sizeof(requisito));
                    Formigas.push_back(new FormigaRainha(nome,tamanho,qtdePatas,especie,cor,cff,"Rainha",QtdOvos));
                    dynamic_cast<FormigaRainha*>(formiga)->setQtdOvosJaPostos(QtdOvosJaPostos);
                    dynamic_cast<FormigaRainha*>(formiga)->setRequisito(requisito);
                    break;
                case 2:
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    patente.resize(tam);
                    entrada.read(reinterpret_cast<char *>(&patente[0]), tam);
                    entrada.read(reinterpret_cast<char *>(&experiencia), sizeof(experiencia));
                    Formigas.push_back(new FormigaSoldado(nome,tamanho,qtdePatas,especie,cor,cff,"Soldado",patente,experiencia));
                    break;

            }
            entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));


        }
        entrada.close();
}
}*/


void Cadastro::grava(){
    //Atributos da Formiga Operaria
    int QtdQueCarrega;
    double velocidade;
    double qtdJaCarregada;
    //Atributos da formiga Rainha
    int QtdOvos;
    int QtdOvosJaPostos;
    double requisito;
    

    //Atributos da formiga soldado
    string patente;
    int experiencia;
    
    string funcao;
    int tam; int tipo; 
    string nome;
    double tamanho;
    int qtdePatas;
    string especie;
    string cor;
    int cff;
    Formigueiro* formigueiro;
    Formiga* formiga;
    FormigaOP* fop;
    FormigaRainha* fr;
    FormigaSoldado* fs;

    
    ofstream saida(fileName, ios::binary);
    for (unsigned long int i = 0; i < Formigas.size(); i++){
        
        
        tipo = Formigas[i]->getTipo();
        saida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        nome = Formigas[i]->getNome();
        tam = nome.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&nome[0]), tam);

        tamanho = Formigas[i]->getTamanho();
        saida.write(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));

        qtdePatas = Formigas[i]->getQtdePatas();
        saida.write(reinterpret_cast<char *>(&qtdePatas), sizeof(qtdePatas));

        especie = Formigas[i]->getEspecie();
        tam = especie.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&especie[0]), tam);

        cor = Formigas[i]->getCor();
        tam = cor.size();

        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&cor[0]), tam);

        cff = Formigas[i]->getCff();
        saida.write(reinterpret_cast<char *>(&cff), sizeof(cff));

       
        formigueiro = Formigas[i]->getFormigueiro();
        if (formigueiro == NULL){
            tam = 0;
            saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        }
        
        else{
            tam = formigueiro->getNome().size();
            saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
            saida.write(reinterpret_cast<char *>(&formigueiro->getNome()[0]), tam);
        }
        switch (tipo) {
            case 0: {
                fop = dynamic_cast<FormigaOP*>(Formigas[i]);
                funcao = fop->getFuncao();
                tam = funcao.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&funcao[0]), tam); 
                QtdQueCarrega = fop->getQtdQueCarrega();
                saida.write(reinterpret_cast<char *>(&QtdQueCarrega), sizeof(QtdQueCarrega));
                velocidade = fop->getVelocidade();
                saida.write(reinterpret_cast<char *>(&velocidade), sizeof(velocidade));
                qtdJaCarregada = fop->getQtdJaCarregada();
                saida.write(reinterpret_cast<char *>(&qtdJaCarregada), sizeof(qtdJaCarregada));
                break;
            }
            case 2: {
                fs = dynamic_cast<FormigaSoldado*>(Formigas[i]);
                funcao = fs->getFuncao();
                tam = funcao.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&funcao[0]), tam);
                patente = fs->getPatente();
                tam = patente.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&patente[0]), tam);
                experiencia = fs->getExperiencia();
                saida.write(reinterpret_cast<char *>(&experiencia), sizeof(experiencia));
                break;
            }
            case 1: {
                fr = dynamic_cast<FormigaRainha*>(Formigas[i]);
                funcao = fr->getFuncao();
                tam = funcao.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&funcao[0]), tam);
                QtdOvos = fr->getQtdOvos();
                saida.write(reinterpret_cast<char *>(&QtdOvos), sizeof(QtdOvos));
                QtdOvosJaPostos = fr->getQtdOvosJaPostos();
                saida.write(reinterpret_cast<char *>(&QtdOvosJaPostos), sizeof(QtdOvosJaPostos));
                requisito = fr->getRequisito();
                saida.write(reinterpret_cast<char *>(&requisito), sizeof(requisito));
                break;
            }
        }

    }
    cout << "grava com sucesso" << endl;
    saida.close();

}

bool Cadastro::adiciona(){
    int QtdQueCarrega;
    double velocidade;
    
    string patente;
    int experiencia;
    int escolha;
    
    int tipo =-3;
    string nome;
    double tamanho;
    int qtdePatas;
    string especie;
    string cor;
    int cff;
    Formigueiro* formigueiro =NULL;
    Formiga* f =NULL;
    int indice;

while(tipo < 0 || tipo > 2){
    cout<< "Qual o tipo de Formiga que você quer adicionar?:" <<endl;
    cout<< "0 - Operaria" <<endl;
    cout<< "1 - Soldado" <<endl;
    cout<< "2 - Rainha" <<endl;
    cin >> tipo;
}
    switch (tipo){
        case 0:
            cout << "Digite o nome da formiga: ";
            cin >> nome;
            cout << "Digite o tamanho da formiga (Em cm): ";
            cin >> tamanho;
            qtdePatas=4;
            cout << "Digite a especie da formiga: ";
            cin >> especie;
            cout << "Digite a cor da formiga: ";
            cin >> cor;
            cout << "Digite o CFF da formiga (Cadastro de Formiga Fisica): ";
            cin >> cff;
            
            cout << "Digite a quantidade que a formiga carrega (Em gramas): ";
            cin >> QtdQueCarrega;
            cout << "Digite a velocidade da formiga (Em cm/s): ";
            cin >> velocidade;
            f = dynamic_cast<Formiga*>(new FormigaOP(nome,tamanho,qtdePatas,especie,cor,cff,"Operaria",QtdQueCarrega,velocidade));
            cout <<"chegou aqui" <<endl;
            break;
        case 1:
            
            cout << "Digite o nome da formiga: ";
            cin >> nome;
            cout << "Digite o tamanho da formiga: ";
            cin >> tamanho;
            cout << "Digite a especie da formiga: ";
            cin >> especie;
            cout << "Digite a cor da formiga: ";
            cin >> cor;
            cout << "Digite o CFF da formiga: ";
            cin >> cff;

            cout << "Informe qual a patente da formiga soldado: " <<endl;
            cout << "1.Recruta" << endl;
            cout << "2.Cabo" << endl;
            cout << "3.Sargento" << endl;
            cout << "4.Tenente" << endl;
            cout << "5.Coronel" << endl;
            cin >> escolha; 
            switch(escolha){
                case 1:
                    patente = "Recruta";
                    break;
                case 2:
                    patente = "Cabo";
                    break;
                case 3:
                    patente = "Sargento";
                    break;
                case 4: 
                    patente = "Tenente";
                    break;
                case 5:
                    patente= "Coronel";
                    break;
            }
            cout << "Informe os anos de experiencia do soldado: ";
            int idade;
            cin >> idade;
            
            f = dynamic_cast<Formiga*>(new FormigaSoldado(nome,tamanho,qtdePatas,especie,cor,cff,"Soldado",patente,idade));
            break;
        case 2:
            cout << "Digite o nome da formiga: ";
            cin >> nome;
            cout << "Digite o tamanho da formiga: ";
            cin >> tamanho;
            cout << "Digite a especie da formiga: ";
            cin >> especie;
            cout << "Digite a cor da formiga: ";
            cin >> cor;
            cout << "Digite o CFF da formiga: ";
            cin >> cff;
            
            f = dynamic_cast<Formiga*>(new FormigaRainha(nome,tamanho,qtdePatas,especie,cor,cff,"Rainha",0));
            break;
    }
    Formigas.push_back(f);
    cout<<"Formiga adicionada com sucesso!" <<endl;
    grava();
    return true;
}

bool Cadastro::atualiza(int cff){
    string patente;
    bool ok = false;
    int pos =indice(cff);
    int tipo =Formigas[pos]->getTipo();
    if (pos != -1){
        Formigas[pos]->imprime();
    
        switch(tipo){
            case 0:
                cout << "Digite a nova quantidade que a formiga carrega (Em gramas): ";
                int QtdQueCarrega;
                cin >> QtdQueCarrega;
                dynamic_cast<FormigaOP*>(Formigas[pos])->setQtdQueCarrega(QtdQueCarrega);
                cout << "Digite a  nova velocidade da formiga (Em cm/s): ";
                double velocidade;
                cin >> velocidade;
                dynamic_cast<FormigaOP*>(Formigas[pos])->setVelocidade(velocidade);
                grava();
                ok = true;
                break;
            case 1:
                cout << "Informe qual a nova patente da formiga soldado: " <<endl;
                cout << "1.Recruta" << endl;
                cout << "2.Cabo" << endl;
                cout << "3.Sargento" << endl;
                cout << "4.Tenente" << endl;
                cout << "5.Coronel" << endl;
                int escolha;
                cin >> escolha; 
                switch(escolha){
                    case 1:
                        patente = "Recruta";
                        break;
                    case 2:
                        patente = "Cabo";
                        break;
                    case 3:
                        patente = "Sargento";
                        break;
                    case 4: 
                        patente = "Tenente";
                        break;
                    case 5:
                        patente= "Coronel";
                        break;
                }
                cout << "Informe os anos de experiencia do soldado: ";
                int idade;
                cin >> idade;
                dynamic_cast<FormigaSoldado*>(Formigas[pos])->setPatente(patente);
                dynamic_cast<FormigaSoldado*>(Formigas[pos])->setExperiencia(idade);
                grava();
                ok = true;
                break;
            case 2:
                cout << "Digite o novo requisito da rainha: ";
                double requisito;
                cin >> requisito;
                dynamic_cast<FormigaRainha*>(Formigas[pos])->setRequisito(requisito);
                grava();
                ok = true;
                break;
        }
    }
    return ok;
}

bool Cadastro::remove(int cff){
    int pos = indice(cff);
    if (pos != -1){
        Formigas.erase(Formigas.begin() + pos);
        grava();
        return true;
    }
    return false;
}

int Cadastro::indice(int cff){
    long unsigned int tam = Formigas.size();
    long unsigned int pos = -1;

    for (int i = 0; i < Formigas.size(); i++){
        if (Formigas[i]->getCff() == cff){
            pos = i;
        }
    }
    return pos;;
}

void Cadastro::imprime(bool sorted){
    vector<Formiga*> Formiguinhas = Formigas;
    /*if (sorted){
        sort(Formigas.begin(), Formigas.end(), [](Formiga* a, Formiga* b){
            return a->getNome() < b->getNome();
        });
    }*/
    for (int i = 0; i < Formigas.size(); i++){
        Formigas[i]->imprime();
    }
}

void Cadastro::imprime(int CFF){
    int pos = indice(CFF);
    if (pos != -1){
        Formigas[pos]->imprime();
        cout << "-----------------------------------" << endl;
    }
}

char Cadastro::opcao(){
    char opcao;
    cout << "Escolha uma opcao: " << endl;
    cout << "a - Adicionar Formiga" << endl;
    cout << "r - Remover Formiga" << endl;
    cout << "i - Imprimir Formigas" << endl;
    cout << "u - Atualizar Formigas" << endl;
    cout << "s - ANTagonizar sistema (Sair)" << endl;
    cin >> opcao;
    return opcao;
}

