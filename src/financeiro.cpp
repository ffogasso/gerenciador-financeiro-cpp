#include "financeiro.hpp"
#include <cmath>

// Inicializa saldo em zero
Financeiro::Financeiro() : saldo(0.0) {}

// Registra uma nova entrada
void Financeiro::registrarEntrada(double valor) {
    if (std::isfinite(valor) && valor > 0 && std::isfinite(saldo + valor)) {
        saldo += valor;
    }
}

// Registra uma nova saida
void Financeiro::registrarSaida(double valor) {
    if (std::isfinite(valor) && valor > 0 && valor <= saldo) {
        saldo -= valor;
    }
}

// Retorna o saldo atual
double Financeiro::consultarSaldo() const {
    return saldo;
}
