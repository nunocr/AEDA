#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include <string>
#include "Cliente.h"
#include "BST.h"

#include "ServicoPointer.h"
#include "RegistadoPointer.h"
#include <unordered_set>

//Hash Table declaration

struct hRegistadoPointer {
	int operator() (const RegistadoPointer & sP1) const {
		unsigned sum = 0;

		for (auto i = 0; i < sP1.getPointer()->getNome().size(); i++) {
			sum += (int)sP1.getPointer()->getNome()[i];
		}
		return sum % 127;
	}

	bool operator() (const RegistadoPointer & sP1, const RegistadoPointer sP2) const {
		return sP1.getPointer()->getNome() == sP2.getPointer()->getNome();
	}
};

typedef unordered_set<RegistadoPointer, hRegistadoPointer, hRegistadoPointer> tabHCliente;


class Empresa{

private:
	std::string nome;
	std::string morada;
	std::vector<Registado *> clientes;
	std::vector<Servico *> historico;
	BST<ServicoPointer*> arvore_servicos;
	tabHCliente tabela_clientes_inativos;

public:
	Empresa():arvore_servicos(nullptr) {}
	Empresa(std::string nome);
	Empresa(std::string nome, std::string morada);

	void setNome(std::string nome);
	void setMorada(std::string morada);

	std::string getNome() const;
	std::string getMorada() const;
	std::vector<Registado *> getRegistados() const;
	Registado* getRegistadoByNIF(unsigned int NIF) const;
	Servico* getServicoByID(unsigned int servID) const;

	bool adicionaCliente(Registado *cli);	
	bool removeCliente(Registado *cli);
	bool removeCliente(unsigned int NIF);

	std::vector<Servico *> getHistorico() const;
	std::string getInformacao() const;
	std::string getInformacaoServicos() const;
	std::string getNIFsClientes() const;
	std::string getIDsServicos() const;
	std::string getServicosByCliente(unsigned int NIF) const;

	bool adicionaServicoCliente(Servico* serv, unsigned int NIF);
	bool servicoRapido(Servico* serv, Cliente* cli, std::string metodo_pagamento);
	bool pagamentoServicoCliente(unsigned int NIF);
	bool setNomeServico(std::string nome, unsigned int servID);

	//BST
	BST<ServicoPointer*> getArvoreServicos() const;
	bool addServicoBST(Servico* serv);
	void printArvoreServicos() const;
	void updateArvoreServicos();

	//Hash Table
	tabHCliente getTabelaClientesInativos() const;
	void printTabelaClientesInativos() const;
	bool updateTabelaClientesInativos();

};





class ClienteRepetido{
	private:
		std::string nome;
		std::string morada;
		unsigned int NIF;
	public:
		ClienteRepetido(){}
		ClienteRepetido(std::string nome, std::string morada){
			this->nome = nome;
			this->morada = morada;
			this->NIF = 0;
		}
		ClienteRepetido(std::string nome, std::string morada, unsigned int NIF){
			this->nome = nome;
			this->morada = morada;
			this->NIF = NIF;
		}

		void printInfo(){
			std::cout << "Cliente Repetido!\n";
			std::cout << "nome: " << this->nome;
			std::cout << "\nmorada: " << this->morada;
			std::cout << "\nNIF: " << this->NIF << "\n";
		}
};

class ClienteInexistente{
private:
	std::string nome;
	std::string morada;
	unsigned int NIF;
public:
	ClienteInexistente(){}
	ClienteInexistente(std::string nome, std::string morada){
	this->nome = nome;
	this->morada = morada;
	this->NIF = 0;
	}
	ClienteInexistente(std::string nome, std::string morada, unsigned int NIF){
	this->nome = nome;
	this->morada = morada;
	this->NIF = NIF;
	}
	void printInfo(){
		std::cout << "Cliente Inexistente!\n";
		std::cout << "nome: " << this->nome;
		std::cout << "\nmorada: " << this->morada;
		std::cout << "\nNIF: " << this->NIF << "\n";
		}
};










#endif /* EMPRESA_H */
