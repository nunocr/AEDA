#include "Empresa.h"
#include "sequentialSearch.h"
#include "insertionSort.h"
#include <algorithm>
#include <stdlib.h>


	Empresa::Empresa(std::string nome){
		this->nome = nome;
		this->morada = "";
	}

	Empresa::Empresa(std::string nome, std::string morada){
		this->nome = nome;
		this->morada = morada;
	}

//
//	std::vector<Empresarial *> Empresa::getEmpresariais() const{
//		return clientes_empresariais;
//	}
//
//	std::vector<Particular *> Empresa::getParticulares() const{
//		return clientes_particulares;
//	}


	std::string Empresa::getNome() const {
		return this->nome;
	}

	std::string Empresa::getMorada() const {
		return this->morada;
	}
	
//std::vector<Cliente *> Empresa::getRegistados() const{
	std::vector<Registado *> Empresa::getRegistados() const{
	return clientes;
	}


	vector<Servico *> Empresa::getHistorico() const {
		return this->historico;
	}

	Registado* Empresa::getRegistadoByNIF(unsigned int NIF) const {
		for (size_t i = 0; i < this->getRegistados().size(); i++) {
			if (NIF = this->getRegistados()[i]->getNIF()) {
				return this->getRegistados()[i];
			}
		}
		return NULL;
	}

	Servico* Empresa::getServicoByID(unsigned int servID) const {
		for (size_t i = 0; i < this->getRegistados().size(); i++) {
			for (size_t j = 0; j < this->getRegistados()[i]->getHistorico().size(); j++) {
				if (this->getRegistados()[i]->getHistorico()[j]->getId() == servID) {
					return this->getRegistados()[i]->getHistorico()[j];
				}
			}
		}
				return NULL;
	}



//bool compAptCli(const Registado* &cli1, const Registado* &cli2){
//
//	return(cli1->getNome() < cli2->getNome());
//}

bool registadosIguais(const Registado* cli1, const Registado* cli2){
	bool foo = (cli1->getNIF() == cli2->getNIF());
	return foo;
}

bool registadosIguais(const Registado cli1, const Registado cli2) {
	bool foo = (cli1.getNIF() == cli2.getNIF());
	return foo;
}

/*
bool registadosIguais(const Registado* cli1, const Registado* cli2) {
	bool foo = (cli1->getNIF() == cli2->getNIF());
	return foo;
}
*/

bool Empresa::adicionaCliente(Registado* cli){
//bool Empresa::adicionaCliente(const Cliente* cli){

	/*
	if (find(clientes.begin(), clientes.end(), cli) != clientes.end()) {
		clientes.push_back(cli);
		return true;
	}
	*/

	
		//if(sequentialSearch(clientes, cli) != -1){
		for(size_t i=0; i < clientes.size(); i++){
			if(*clientes[i] == *cli){
			throw ClienteRepetido(cli->getNome(), cli->getMorada(), cli->getNIF());
			return false;
			}
		}
		clientes.push_back(cli);
		//NOTA: FAZER UM INSERTION SORT PARA COMPARABLE* JA QUE ESTE ORDENA OS ENDERCOS, NAO OS CLIENTES
		std::sort(clientes.begin(),clientes.end());
		//insertionSort(clientes);
		return true;
		
	//return false;
}



//bool Empresa::removeCliente(Registado &cli){
bool Empresa::removeCliente(Registado* cli){
	/*
	unsigned int indice = sequentialSearch(clientes, &cli);
		if(indice == -1){
			throw ClienteInexistente(cli.getNome(), cli.getMorada(), cli.getNIF());
			return false;
		}
	*/
	for (size_t i = 0; i < clientes.size(); i++) {
		if (*clientes[i] == *cli) {
			clientes.erase(clientes.begin() + i);
			return true;
		}
	}
		throw ClienteInexistente(cli->getNome(), cli->getMorada(), cli->getNIF());
		return false;

		//clientes.erase(clientes.begin() + indice);
		//return true;
	}


bool Empresa::removeCliente(unsigned int NIF) {
	for (size_t i = 0; i < clientes.size(); i++) {
		if (clientes[i]->getNIF() == NIF) {
			clientes.erase(clientes.begin() + i);
			return true;
		}
	}
	throw ClienteInexistente("-", "-", NIF);
	return false;
}



std::string Empresa::getInformacao() const{

	std::ostringstream info;
	info << "\n.:Informacao da Empresa:.\n\n";
	info << "nome: " << this->nome;
	info << "\nmorada: " << this->morada;
	info << "\nnr de clientes: " << clientes.size() << "\n\n";
	info << "Clientes:\n\n";
	for(size_t i=0; i < clientes.size(); i++){
		info << clientes[i]->getInformacao();
		info << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
	return info.str();
}

std::string Empresa::getInformacaoServicos() const {
	std::ostringstream info;

	info << "~Historico de Servicos~\n\n";
	for (size_t i = 0; i < clientes.size(); i++) {
		info << clientes[i]->getInformacaoServicos();
		info << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}

	info << "\n\nServicos de clientes nao registados:\n\n";
	for (size_t i = 0; i < historico.size(); i++) {
		info << historico[i]->getInformacao();
		info << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}

	return info.str();
}

std::string Empresa::getNIFsClientes() const {
	std::ostringstream info;

	info << "~NIFs dos Clientes~\n\n";
	for (size_t i = 0; i < clientes.size(); i++) {
		info << clientes[i]->getNIF() << " | ";
	}
	return info.str();
}

std::string Empresa::getIDsServicos() const {
	std::ostringstream info;

	for (size_t i = 0; i < this->getRegistados().size(); i++) {
		for (size_t j = 0; j < this->getRegistados()[i]->getHistorico().size(); j++) {
			info << this->getRegistados()[i]->getHistorico()[j]->getId() << " | ";
		}
	}
	return info.str();
}



std::string Empresa::getServicosByCliente(unsigned int NIF) const {
	std::ostringstream info;

	for (size_t i = 0; i < this->getRegistados().size(); i++) {
		if(this->getRegistados()[i]->getNIF() == NIF){
			for (size_t j = 0; j < this->getRegistados()[i]->getHistorico().size(); j++){
				if(this->getRegistados()[i]->getHistorico()[j]->getEstado() == false)
					info << this->getRegistados()[i]->getHistorico()[j]->getId() << " | ";
				}
		}
	}
		return info.str();
}


bool Empresa::adicionaServicoCliente(Servico* serv, unsigned int NIF) {
	
	if (serv == NULL) {
		return false;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (clientes[i]->getNIF() == NIF) {
			clientes[i]->adicionaServico(serv);
			this->historico.push_back(serv);
			return true;
		}
	}
	std::cout << "\nCliente Inexistente!\n";
	//might want to throw exception here (ClienteInexistente)
	return false;
}

bool Empresa::servicoRapido(Servico* serv, Cliente* cli, std::string metodo_pagamento) {

	float valor = serv->getValor();

	for (size_t i = 0; i < this->getRegistados().size(); i++) {
		if (this->getRegistados()[i]->getNIF() == cli->getNIF()) {
			std::cout << "\n\nCliente ja esta registado no sistema!\n\n";
			return false;
		}
	}


	if (metodo_pagamento != "numerario" && metodo_pagamento != "cartao de credito" && metodo_pagamento != "multibanco") {
		std::cout << "\nMetodo de pagamento invalido!\n";
		return false;
	}

	if (metodo_pagamento == "cartao de credito") {
		valor += (5 * valor) / 100;
	}

	serv->setPago();
	serv->setTipoPagamento(metodo_pagamento);
	serv->setValor(valor);
	serv->setNIF(cli->getNIF());
	this->getHistorico().push_back(serv);

	return true;
}

bool Empresa::pagamentoServicoCliente(unsigned int NIF) {

	std::string tipo_pagamento;

	for (size_t i = 0; i < clientes.size(); i++) {
		if (clientes[i]->getNIF() == NIF) {
			std::cout << "tipo de pagamento: ";
			std::cin >> tipo_pagamento;

			if (tipo_pagamento == "numerario") {
				std::cout << "blah blah blah";
			}
			return true;
		}
	}

	return false;
}
