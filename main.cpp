#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/list.h"

using namespace std;

List ListFromString(string operation){
    List result;

    istringstream str(operation);
    float coefficient;
    int degree;

    while (str >> coefficient >> degree){
        result.Append(coefficient, degree);
    }

    return result;
}

int main() {
    // Carregar arquivo txt na raiz
    ifstream file("arquivo.txt");

    if (!file.is_open()){
        cerr << "Erro ao carregar o arquivo!" << endl;
        cout << "Pressione Enter para sair...";
        cin.get(); // Espera uma entrada
        return 1;
    }

    string line;
    string operation;

    while (getline(file, line)){
        if (line == "+"){
            cout << "========= SOMA ========" << endl;

            getline(file, operation);
            List p1 = ListFromString(operation);

            getline(file, operation);
            List p2 = ListFromString(operation);

            cout << "("<<p1<<") + ("<<p2<<")" << endl;
            cout << "Resultado: " << p1+p2 << endl << endl;
        }
        else if (line == "-"){
            cout << "====== SUBTRACAO ======" << endl;

            getline(file, operation);
            List p1 = ListFromString(operation);

            getline(file, operation);
            List p2 = ListFromString(operation);

            cout << "("<<p1<<") - ("<<p2<<")" << endl;
            cout << "Resultado: " << p1-p2 << endl << endl;
        }
        else if (line == "*"){
            cout << "==== MULTIPLICACAO ====" << endl;

            getline(file, operation);
            List p1 = ListFromString(operation);

            getline(file, operation);
            List p2 = ListFromString(operation);

            cout << "("<<p1<<") * ("<<p2<<")" << endl;
            cout << "Resultado: " << p1*p2 << endl << endl;
        }
        else if (line == "g" || line == "G"){
            cout << "========= GRAU ========" << endl;

            getline(file, operation);
            List p1 = ListFromString(operation);

            cout << "O Grau do Polinomio ("<<p1<<") eh: " << p1.degree() << endl << endl;
        }
        else if (line == "t" || line == "T"){

        }
        else if (line == "a" || line == "A"){

        }
        else if (line == "p" || line == "P"){

        }
        else {
            cerr << "Erro na leitura do arquivo, alguma operacao incorreta! Data: " << line << endl << endl;
        }
    }

    cout << "Pressione Enter para sair...";
    cin.get(); // Espera uma entrada
    return 0;
}