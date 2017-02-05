#include "Cliente.h"
#include "sequentialSearch.h"
#include "insertionSort.h"

//Cliente

/**
*Constructor de clienete
*@param nome, morada, NIF
*
*/




Cliente::Cliente(const std::string nome, const std::string morada, const unsigned int NIF){
  this->nome = nome;
  this->morada = morada;
  this->NIF = NIF;
}


/**
*Constructor de clienete
*@param nome, morada
*
*pode ser usado para clientes nao registados
*/

Cliente::Cliente(const std::string nome, const std::string morada){
  this->nome = nome;
  this->morada = morada;
  this->NIF = 0;
}


/**
*Constructor de clienete
*@param nome
*
*pode ser usado para clientes nao registados
*/

Cliente::Cliente(const std::string nome){
  this->nome = nome;
  this->morada = "";
  this->NIF = 0;
}




/**
*Operator =
*
*@param cli
*
*iguala o nome e a morada de um cliente ao nome e morada de outro cliente
*/

void Cliente::operator=(const Cliente &cli) {
		this->nome = cli.getNome();
		this->morada = cli.getMorada();
		this->NIF = cli.getNIF();
}



/**
*Informacao relativa a um cliente
*
*@return uma string com a morada, nome e NIF de um cliente, ja formatadoa
*
*/

std::string Cliente::getInformacao() const{
	std::ostringstream info;
	info << "nome: " << this->nome << "\nmorada: " << this->morada << "\nNIF: " << this->NIF;
	return info.str();
}




/**
*Pagamento de um servico em numerario
*
*@param serv
*
*efectua o pagamento do servico lancado como argumento pelo metodo
*de numerario
*atribui ao NIF do servico o NIF do cliente que o pagou, para ser guardado na empresa
*/

bool Cliente::pagamentoNumerario(Servico &serv){

	serv.setPago();
	serv.setTipoPagamento("numerario");
	serv.setValor(serv.getDefaultValor());
	serv.setNIF(this->NIF);
	return true;
}



/**
*Constructor de clienete
*@param nome, morada, NIF
*
*/

bool Cliente::pagamentoMultibanco(Servico &serv){

	serv.setPago();
	serv.setTipoPagamento("multibanco");
	serv.setValor(serv.getDefaultValor());
	serv.setNIF(this->NIF);
	return true;
}





//Cliente Registado


/**
*Operador = para a classe Registado, derivado da classe Cliente
*@param reg
*
*
*iguala o nome, morada, NIF e historico (historico de servicos requesitados do cliente registado)
*aos membros equivalentes de outro cliente registado
*/
void Registado::operator=(const Registado &reg) {
	this->nome = reg.getNome();
	this->morada = reg.getMorada();
	this->NIF = reg.getNIF();
	this->historico = reg.getHistorico();
}


/**
*@return historico
*
*retorna o historico de clientes requesitados de um cliente registado
*
*/

std::vector<Servico*> Registado::getHistorico() const{
	return historico;
}



/**
*@param nome, morada, NIF
*
*constructor da classe Registado, derivadaa da classe Cliente
*/

Registado::Registado(std::string nome, std::string morada, const unsigned int NIF) : Cliente(nome, morada, NIF){}





/**
*Constructor de Registado
*@param nome, morada, NIF
*
*/

Registado::Registado(std::string nome, std::string morada) : Cliente(nome, morada){
	this->NIF = 0;
}


/**
*@param nome
*
*Constructor de um cliente Registado
*/

Registado::Registado(std::string nome) : Cliente(nome){
	this->morada = "";
	this->NIF = NIF;
}



/**
*Informacao sobre um cliente Registado
*
*@param string
*
*retorna uma string com a informacao ja formatada relativamente a um cliente Registado
*
*/

std::string Registado::getInformacao() const{

	std::string info = "";
	info += Cliente::getInformacao();

	unsigned int servicos_por_pagar = 0;
	unsigned int servicos_pagos = 0;

	for(size_t i=0; i < historico.size(); i++){
		if(historico[i]->getEstado())
			servicos_pagos++;
		servicos_por_pagar++;
	}

	std::ostringstream info2;

	info2 << "Cliente Registado\n";
	info2 << info << "\nservicos pagos: " << servicos_pagos;
	info2 << "\nservicos por pagar: " << servicos_por_pagar;


	return info2.str();
}



/**
*Informacao relativa a sericos
*
*@return string
*
*Retorna uma string ja formatada com a informacao relativa aos servicos todos do historico de um cliente
*/

std::string Registado::getInformacaoServicos() const {

	std::ostringstream info;

	unsigned int servicos_por_pagar = 0;
	unsigned int servicos_pagos = 0;

	for (size_t i = 0; i < historico.size(); i++) {
		if (historico[i]->getEstado())
			servicos_pagos++;
		servicos_por_pagar++;
	}

	info << "NIF do cliente: " << this->NIF << "\n";
	info << "historico de servicos:\n";
	info << "\nservicos pagos: " << servicos_pagos;
	info << "\nservicos por pagar: " << servicos_por_pagar << "\n";

	for (size_t i = 0; i < historico.size(); i++) {
		info << historico[i]->getInformacao();
		//info << "\n-------------------------------------";
	}
	return info.str();
}




//METODOS RELATIVOS A PAGAMENTOS


/**
*Pagamento de um Servico de um cliente Registado
*
*@param serv
*
*@return bool
*
*efectua o pagamento de um servico a um cliente Registado
*segundo o metodo de pagamento por cartao de credito
*/



bool Registado::pagamentoCartaoCredito(Servico &serv){
	float valor = serv.getValor();
	valor += (5*valor)/100;
	serv.setPago();
	serv.setTipoPagamento("cartao de credito");
	serv.setValor(valor);
	this->historico.push_back(&serv);
	return true;
}



/**
*Pagamento de um Servico de um cliente Registado
*
*@param serv
*
*@return bool
*
*efectua o pagamento de um servico a um cliente Registado
*segundo o metodo de pagamento por multibanco
*/

bool Registado::pagamentoMultibanco(Servico &serv){
	serv.setPago();
	serv.setTipoPagamento("multibanco");
	serv.setValor(historico[0]->getDefaultValor());
	serv.setNIF(this->NIF);
	this->historico.push_back(&serv);
	return true;
}



/**
*Pagamento de um Servico de um cliente Registado
*
*@param serv
*
*@return bool
*
*efectua o pagamento de um servico a um cliente Registado
*segundo o metodo de pagamento por numerario
*/

bool Registado::pagamentoNumerario(Servico &serv){
	serv.setPago();
	serv.setTipoPagamento("numerario");
	serv.setValor(historico[0]->getDefaultValor());
	serv.setNIF(this->NIF);
	this->historico.push_back(&serv);
	return true;
}


/**
*Pagamento de um Servico de um cliente Registado
*
*@param servs
*
*@return bool
*
*efectua o pagamento dos servicos de um vector de servicos (historico) a um cliente Registado
*segundo o metodo de pagamento ao fim do mes
*/

bool Registado::pagamentoFimDoMes(std::vector<Servico *> servs) {
	//paga todos os servicos por pagar, chegado ao fim do mes
	return true;
}


/**
*Pagamento de um Servico de um cliente Registado
*
*@param id
*
*@return bool
*
*efectua o pagamento de um servico a um cliente Registado
*segundo o metodo de pagamento por numerario
*/

bool Registado::pagamentoNumerario(unsigned int id) {
	for (size_t i = 0; i < historico.size(); i++) {
		if (historico[i]->getId() == id && historico[i]->getEstado() == false) {
			historico[i]->setPago();
			historico[i]->setTipoPagamento("numerario");
			historico[i]->setValor(historico[i]->getDefaultValor());
			historico[i]->setNIF(this->NIF);
			return true;
		}
	}
	return false;
}

/**
*Pagamento de um Servico de um cliente Registado
*
*@param id
*
*@return bool
*
*efectua o pagamento de um servico a um cliente Registado
*segundo o metodo de pagamento por multibanco
*/

bool Registado::pagamentoMultibanco(unsigned int id) {
	for (size_t i=0; i < historico.size(); i++) {
		if (historico[i]->getId() == id && historico[i]->getEstado() == false) {
			historico[i]->setPago();
			historico[i]->setTipoPagamento("multibanco");
			historico[i]->setValor(historico[i]->getDefaultValor());
			historico[i]->setNIF(this->NIF);
			return true;
		}
	}
	return false;
}


/**
*Pagamento de um Servico de um cliente Registado
*
*@param id
*
*@return bool
*
*efectua o pagamento de um servico a um cliente Registado
*segundo o metodo de pagamento por cartao de credito
*/

bool Registado::pagamentoCartaoCredito(unsigned int id) {
	for (size_t i = 0; i < historico.size(); i++) {
		if (historico[i]->getId() == id && historico[i]->getEstado() == false) {
			float valor = historico[i]->getValor();
			valor += (5 * valor) / 100;
			historico[i]->setPago();
			historico[i]->setTipoPagamento("cartao de credito");
			historico[i]->setValor(valor);
			return true;
		}
	}
	return false;
}


/**
*Pagamento de um Servico de um cliente Registado
*
*@param ids
*
*@return bool
*
*efectua o pagamento de um vector de ids de servicos a um cliente Registado
*segundo o metodo de pagamento ao fim do mes
*/

bool Registado::pagamentoFimDoMes(std::vector<unsigned int> ids) {
	return true;
}



/**
*Adiciona um  Servico a um cliente Registado
*
*@param serv
*
*@return bool
*
*adiciona, se possivel, um servico ao historico de servicos de um cliente
*registado
*/

//bool Registado::adicionaServico(Servico &serv) {
bool Registado::adicionaServico(Servico* serv) {
	for (size_t i = 0; i < historico.size(); i++) {
		if (historico[i] == serv) {
			std::cout << "\nnao adicionou servico\n";
			return false;
		}
	}
	historico.push_back(serv);
	return true;
}





//Cliente Empresarial

/**
*Constructor de um cliente Empresarial, derivado de um cliente Registado
*
*@param nome, morada, int, NIF
*
*@return bool
*
*/

Empresarial::Empresarial(std::string nome, std::string morada, const unsigned int) : Registado(nome, morada, NIF){}

/**
*Constructor de um cliente Empresarial, derivado de um cliente Registado
*
*@param nome, morada
*
*@return bool
*
*/

Empresarial::Empresarial(std::string nome, std::string morada) : Registado(nome, morada){}

/**
*Constructor de um cliente Empresarial, derivado de um cliente Registado
*
*@param nome
*
*@return bool
*
*/

Empresarial::Empresarial(std::string nome) : Registado(nome){}


/**
*Obtem informacao de um cliente Empresarial
*
*
*@return string
*
*
*retorna uma string ja formatda com a informacao relativa a um cliente Empresarial
*/

std::string Empresarial::getInformacao() const{

	std::ostringstream info;
	info << "Cliente Registado Empresarial\n";
	info << Registado::getInformacao();
	return info.str();
}



/**
*Constructor de um cliente Empresarial, derivado de um cliente Registado
*
*@param nome, morada, int, NIF
*
*@return bool
*
*/

std::string Empresarial::getTipo() const {
	return "empresarial";
}





//Cliente Particular


/**
*Constructor de um cliente Particular, derivado de um cliente Registado
*
*@param nome, morada, int, NIF
*
*@return bool
*
*/


	Particular::Particular(std::string nome, std::string morada, const unsigned int NIF) : Registado(nome, morada, NIF){}

	/**
	*Constructor de um cliente Particular, derivado de um cliente Registado
	*
	*@param nome, morada, int
	*
	*
	*/

	Particular::Particular(std::string nome, std::string morada) : Registado(nome, morada){}


	/**
	*Constructor de um cliente Particular, derivado de um cliente Registado
	*
	*@param nome
	*
	*
	*/

	Particular::Particular(std::string nome) : Registado(nome){}


	/**
	*Obtem informacao relativa a um cliente Particular
	*
	*
	*@return string
	*
	*retorna uma string ja formatada com a informaca relativa a um cliente particular
	*/

	std::string Particular::getInformacao() const{

		std::ostringstream info;
		info << "Cliente Registado Particular\n";
		info << Registado::getInformacao();
		return info.str();
	}


	/**
	*Constructor de um cliente Particular, derivado de um cliente Registado
	*
	*@return string
	*
	*retorna uma string que representao o tipo de cliente (particular ou empresarial) de um cliente Registado
	*/

	std::string Particular::getTipo() const {
		return "particular";
	}






















