#ifndef FINANCEIRO_HPP
#define FINANCEIRO_HPP

class Financeiro {
    private:
    // proteger o saldo de alterações diretas de outras partes do programa
        double saldo;
    
    public:
    // metodos que outras partes do programa podem utilizar
    Financeiro();
    
    void registrarEntrada(double valor);
    void registrarSaida(double valor);
    double consultarSaldo() const;
};
#endif