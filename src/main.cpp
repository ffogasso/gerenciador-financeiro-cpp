#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include "financeiro.hpp"

using namespace std;

// Le uma linha inteira para rejeitar numeros seguidos de texto ou outros valores.
template <typename T>
bool lerNumero(T& numero)
{
    string linha;
    if (!getline(cin, linha)) {
        return false;
    }
    istringstream entrada(linha);
    if (!(entrada >> numero)) {
        return false;
    }
    entrada >> ws;
    return entrada.eof();
}

int main()
{
    Financeiro financeiro;

    int opcao = -1;
    double valor;

    do {
        // Exibe menu principal
        cout << "\n===== GERENCIADOR FINANCEIRO =====\n";
        cout << "1 - Registrar Entrada\n";
        cout << "2 - Registrar saida\n";
        cout << "3 - Consultar saldo\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";

        // Verifica se a opcao digita eh valida
        if (!lerNumero(opcao)) {
            if (!cin) {
                break;
            }
            opcao = -1;
            cout << "Digite uma opcao valida!\n";
            continue;
        }

        // Executa a opcao escolhida
        switch (opcao) {
            case 1:
                cout << "Valor da entrada: R$:  ";

                if (!lerNumero(valor)) {
                    if (!cin) {
                        return 0;
                    }
                    cout << "Valor invalido!\n";
                    break;
                }
                if (!isfinite(valor) || valor <= 0 ||
                    !isfinite(financeiro.consultarSaldo() + valor)) {
                    cout << "Valor invalido! Use um valor positivo dentro do limite numerico.\n";
                } else {
                    financeiro.registrarEntrada(valor);
                    cout << "Entrada registrada!\n";
                }
                break;

            case 2:
                cout << "Valor de saida: R$ ";

                if (!lerNumero(valor)) {
                    if (!cin) {
                        return 0;
                    }
                    cout << "Valor invalido!\n";
                    break;
                }
                if (!isfinite(valor) || valor <= 0) {
                    cout << "Valor invalido! O valor deve ser positivo!\n";
                } else if (valor > financeiro.consultarSaldo()) {
                    cout << "Saldo insuficiente!\n";
                } else {
                    financeiro.registrarSaida(valor);
                    cout << "Saida registrada!\n";
                }
                break;

                case 3:
                    cout << fixed << setprecision(2);
                    cout << "Saldo atual: R$ "
                         << financeiro.consultarSaldo() << "\n";
                    break;

                case 0:
                    cout << "Encerrando o programa...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
                    break;
        }
    } while (opcao != 0);

    return 0;
}
