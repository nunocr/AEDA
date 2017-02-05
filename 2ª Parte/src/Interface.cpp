#include "Interface.h"

/*
void Pausa() {
	do {
		std::cout << '\n' << "Press the Enter key to continue.";
	} while (std::cin.get() != '\n');

	std::cin.clear();
	return;
}
*/


/**
*limpa o input buffer
*
*
*/

void clearBuffer() {
	if (!std::cin.eof())
		std::cin.ignore(INT64_MAX, '\n');
}

/**
*faz uma pausa no programa (equivalente ao system("cls")
*
*
*/

void Pausa()
{
	clearBuffer();
	std::cin.get();
}

	
/**
*requesita um valor integral ao utilizador
*
*@return choice
*/

int Interface::GetInput() {
	int choice;
	std::cin >> choice;
	if (!std::cin.eof())
		std::cin.ignore(INT64_MAX, '\n');
	return choice;
}



/**
*mostra o menu inicial
*

*
*/

void Interface::DisplayMenuInicial() {
	std::cout << "= = = = M E N U  I N I C I A L = = = =\n\n";
	std::cout << "0 - Carregar ficheiro\n";
	std::cout << "1 - Novo ficheiro\n";
	std::cout << "2 - Sair\n";
}




/**
*mostra o menu principal
*
*
*/

void Interface::DisplayMenuPrincipal() {
	std::cout << "= = = = M E N U  P R I N C I P A L = = = =\n\n";
	std::cout << "0 - Informacao geral\n";
	std::cout << "1 - Informacao relativa aos Servicos\n";
	std::cout << "2 - Efectuar servico rapido (para clientes nao registados)\n";
	std::cout << "3 - Adicionar Registado (cliente registado)\n";
	std::cout << "4 - Remover Cliente\n";
	std::cout << "5 - Adicionar Servico a Cliente\n";
	std::cout << "6 - Pagamento de Servicos\n";
	std::cout << "7 - Carregar ficheiro\n";
	std::cout << "8 - Guardar sessao actual\n";
	std::cout << "9 - Menu de Estruturas de Dados\n";
	std::cout << "10 - Sair\n";
}



/**
*mostra o menu de pagamento
*
*
*/

void Interface::DisplayMenuPagamento() {
	system("cls");
	std::cout << "\n~Pagamento de Servicos~\n";
	std::cout << "\nTipo de pagamento:\n";
	std::cout << "0 - Multibanco\n";
	std::cout << "1 - Numerario\n";
	std::cout << "2 - Cartao de credito\n";
	std::cout << "3 - Fim do mes\n";
	std::cout << "4 - Sair";
}


/**
* @brief imprime o menu relativo as 3 estruturas de dados abordadas na segunda parte do trabalho
*/
void Interface::DisplayMenuEstruturasDados() {
	system("cls");
	std::cout << "~Estruturas de Dados~\n";
	std::cout << "0 - Informacao da BST de servicos\n";
	std::cout << "1 - Actualiza arvore de servicos realizados\n";
	std::cout << "2 - Informacao sobre clientes inativos (Hash Table)\n";
	std::cout << "3 - Actualiza tabela de clientes inativos\n";
	std::cout << "4 - Informacao sobre clientes em fila de espera (Priority Queue)\n";
	std::cout << "5 - Actualiza fila de clientes em espera\n";
	std::cout << "6 - Sair";

}

/**
/* @brief invoca o menu relativo as estruturas de dados e a sua logica
/* @param emp empresa do utilizador em questao
*/
void Interface::MenuEstruturasDados(Empresa* emp) {

	int escolha = 0;

	do {
		system("cls");
		DisplayMenuEstruturasDados();
		std::cout << "\n\nSua escolha: ";
		escolha = GetInput();

		switch (escolha) {
		
		case 0: {
			system("cls");
			std::cout << "BST info:\n\n";
			emp->printArvoreServicos();
			Pausa();
			break;
			}

		case 1: {
			system("cls");
			emp->updateArvoreServicos();
			std::cout << "BST actualizada!";
			Pausa();
			break;
			}

		case 2: {
			system("cls");
			std::cout << "Hash Table info:\n\n";
			emp->printTabelaClientesInativos();
			Pausa();
			break;
			}

		case 3: {
			system("cls");
			emp->updateTabelaClientesInativos();
			std::cout << "Hash Table actualizada!";
			Pausa();
			break;
			}

		case 4: {
			system("cls");
			std::cout << "Priority Queue info:\n\n";
			Pausa();
			break;
			}

		case 5: {
			//PRIORITY QUEUE UPDATE HERE
			break;
			}

		case 6:
			break;

		default:
			std::cout << "Escolha invalida!\n";
			break;
		}
	} while (escolha != 6);
}

/**
*invoca o menu de pagamento e a sua logica
*
*@param emp
*/

void Interface::MenuPagamento(Empresa* emp) {

	int escolha = 0;

	do {
		system("cls");
		DisplayMenuPagamento();
		std::cout << "\n\nSua escolha: ";
		escolha = GetInput();

		switch (escolha) {

		case 0: {
			//multibanco;
			unsigned int tempNIF;
			unsigned int servID;

			std::cout << "NIF do cliente a pagar:";
			std::cout << "\n\n" << emp->getNIFsClientes();
			std::cout << "\n\nSua escolha: ";
			std::cin >> tempNIF;

			std::cout << "ID do servico a pagar: ";
			std::cout << "\n\n";
			//std::cout << emp->getIDsServicos();
			std::cout << emp->getServicosByCliente(tempNIF);
			std::cin >> servID;

			if (emp->getRegistadoByNIF(tempNIF) != NULL) {
				if (emp->getServicoByID(servID) != NULL) {
					//if (emp->getRegistadoByNIF(tempNIF)->getHistorico()[servID]->getEstado() == true) {
					if (emp->getRegistadoByNIF(tempNIF)->getServicoByID(servID)->getEstado() != true) {
						emp->getRegistadoByNIF(tempNIF)->pagamentoMultibanco(servID);

	//BST RELATED CODE HERE
						//emp->addServicoBST(emp->getServicoByID(servID));
						emp->setNomeServico(emp->getRegistadoByNIF(tempNIF)->getNome(), servID);

	//...

						std::cout << "\nServico pago com exito!\n";
					}
					else { std::cout << "\nServico ja foi previamente pago!\n"; }
				}
			}

			Pausa();
			break;
		}

		case 1: {
			//numerario
			unsigned int tempNIF;
			unsigned int servID;

			std::cout << "NIF do cliente a pagar:";
			std::cout << "\n\n" << emp->getNIFsClientes();
			std::cout << "\n\nSua escolha: ";
			std::cin >> tempNIF;

			std::cout << "ID do servico a pagar: ";
			std::cout << "\n\n";
			//std::cout << emp->getIDsServicos();
			std::cout << emp->getServicosByCliente(tempNIF);
			std::cout << "\n\nSua escolha: ";
			std::cin >> servID;

			if (emp->getRegistadoByNIF(tempNIF) != NULL) {
				if (emp->getServicoByID(servID) != NULL) {
					//if (emp->getRegistadoByNIF(tempNIF)->getHistorico()[servID]->getEstado() == true) {
					if (emp->getRegistadoByNIF(tempNIF)->getServicoByID(servID)->getEstado() != true) {
						emp->getRegistadoByNIF(tempNIF)->pagamentoNumerario(servID);

		//BST RELATED CODE HERE
					//emp->addServicoBST(emp->getServicoByID(servID));
						emp->setNomeServico(emp->getRegistadoByNIF(tempNIF)->getNome(), servID);
		//...
						std::cout << "\nServico pago com exito!\n";
					}
					else { std::cout << "\nServico ja foi previamente pago!\n"; }
				}
			}

			Pausa();
			break;
		}

		case 2: {
			//cartao
			unsigned int tempNIF;
			unsigned int servID;

			std::cout << "NIF do cliente a pagar:";
			std::cout << "\n\n" << emp->getNIFsClientes();
			std::cout << "\n\nSua escolha: ";
			std::cin >> tempNIF;

			std::cout << "ID do servico a pagar: ";
			std::cout << "\n\n";
			//std::cout << emp->getIDsServicos();
			std::cout << emp->getServicosByCliente(tempNIF);
			std::cin >> servID;

			if (emp->getRegistadoByNIF(tempNIF) != NULL) {
				if (emp->getServicoByID(servID) != NULL) {
					//if (emp->getRegistadoByNIF(tempNIF)->getHistorico()[servID - 1]->getEstado() == true) {
					if(emp->getRegistadoByNIF(tempNIF)->getServicoByID(servID)->getEstado() != true) {
						emp->getRegistadoByNIF(tempNIF)->pagamentoCartaoCredito(servID);

		//BST RELATED CODE HERE
				//emp->addServicoBST(emp->getServicoByID(servID));
						emp->setNomeServico(emp->getRegistadoByNIF(tempNIF)->getNome(), servID);
		//...

						std::cout << "\nServico pago com exito!\n";
					}
					else { std::cout << "\nServico ja foi previamente pago!\n"; }
				}
			}

			Pausa();
			break;
		}

		case 3: {
			//fim de mes
			unsigned int tempNIF;
			std::vector<unsigned int> tempIDs;

			std::cout << "NIF do cliente a pagar:";
			std::cout << "\n\n" << emp->getNIFsClientes();
			std::cout << "\n\nSua escolha: ";
			std::cin >> tempNIF;

			for (size_t i = 0; i < emp->getRegistados().size(); i++) {
				for (size_t j = 0; j < emp->getRegistados()[i]->getHistorico().size(); j++) {
					if (emp->getRegistados()[i]->getHistorico()[j]->getEstado() == false) {
						tempIDs.push_back(emp->getRegistados()[i]->getHistorico()[j]->getId());
					}
				}
			}
			
			if (emp->getRegistadoByNIF(tempNIF) != NULL) {
				if (emp->getRegistadoByNIF(tempNIF)->pagamentoFimDoMes(tempIDs)) {
					std::cout << "\nServico pago com exito!\n";
				}
			}

			Pausa();
			break;
		}

		default:
			std::cout << "\nEscolha invalida!\n";
			break;
		}
	} while (escolha != 4);
}




/**
*invoca o menu principal e a sua logica
*
*@param emp
*/

void Interface::MenuPrincipal(Empresa* emp) {

	int escolha = 0;

	//emp->updateArvoreServicos();
	
	do {
		system("cls");
		DisplayMenuPrincipal();
		std::cout << "\n\nSua escolha: ";
		escolha = GetInput();
		switch (escolha) {
		case 0:
			system("cls");
			std::cout << emp->getInformacao();
			Pausa();

	//BST RELATED CODE HERE
		//	system("cls");
		//	std::cout << "BST info:\n\n";
		//	emp->printArvoreServicos();
		//	Pausa();
			break;

		case 1:
			system("cls");
			std::cout << emp->getInformacaoServicos();
			Pausa();
			break;

		case 2: {
			system("cls");

			std::string metodo;

			Cliente* cli;
			cli = CriarCliente();

			Servico* serv;
			serv = CriarServico();

			std::cout << "\n\nMetodo de pagamento: ";
			std::cin >> metodo;

			if (!emp->servicoRapido(serv, cli, metodo)) {
				std::cout << "Nao foi possivel realizar o servico!\n";;
				break;
			}

			delete cli;
			Pausa();
			break;
		}

		case 3: {
			system("cls");
			Registado* reg;
			reg = CriarRegistado();

			/*
			if (!emp->adicionaCliente(reg)) {
				std::cout << "\nNao foi possivel adicionar o Cliente Registado pretendido!\n";
				delete reg;
			}
			*/
			try {
				emp->adicionaCliente(reg);
			}
			catch (ClienteRepetido clirep) {
				clirep.printInfo();
			}
			break;
		}

		case 4: {
			unsigned int tempNIF;
			std::cout << emp->getNIFsClientes();
			std::cout << "\n\nNIF do Cliente a remover: ";
			std::cin.clear();
			std::cin >> tempNIF;

			for (size_t i = 0; i < emp->getRegistados().size(); i++) {
				if(tempNIF == emp->getRegistados()[i]->getNIF()){
					if (!emp->removeCliente(tempNIF))
						std::cout << "\nNao foi possivel remover o Cliente pretendido!\n";
					std::cout << "\nCliente removido do sistema com sucesso!\n";
					Pausa();
					break;
				}
			}
			//std::cout << "\nNIF invalido!\n";
			Pausa();
			break;
		}

		case 5: {
			system("cls");
			std::cout << "Adicionar Servico a Cliente\n";
			Servico* serv;
			unsigned int tempNIF;
			serv = CriarServico();

			if (serv == NULL)
				std::cout << "\nServico pretendido invalido!\n";
				

			std::cout << emp->getNIFsClientes();
			std::cout << "\nNIF: ";
			std::cin.clear();
			std::cin >> tempNIF;

			if (!emp->adicionaServicoCliente(serv, tempNIF)) {
				std::cout << "Nao foi possivel adicionar o Servico criado ao Cliente pretendido!\n";
				delete serv;
				Pausa();
			}
			break;
		}

		case 6:
			system("cls");
			//std::cout << "Pagamento de Servicos\n";
			MenuPagamento(emp);
			break;

		case 7:
			CarregaFicheiro(emp);
			break;

		case 8:
			GuardaFicheiro(emp);
			break;

		case 9:
			system("cls");
			MenuEstruturasDados(emp);
			break;

		case 10:
			break;

		default:
			std::cout << "Escolha invalida!\n";
			break;
		}
	} while (escolha != 10);
}



/**
*invoca o menu inicial e a sua logica
*
*@param emp
*/

void Interface::MenuInicial(Empresa* emp) {
	/*
	int escolha = 0;

	do {
		system("cls");
		DisplayMenuInicial();
		std::cout << "\n\nSua escolha: ";
		escolha = GetInput();
		switch (escolha) {
		case 0:
			//std::cout << "CarregarFicheiro()";
			break;
		case 1:
			NovoFicheiro(emp);
			break;
		case 2:
			system("cls");
			std::cout << "\n\nJe suis desoles...\n\n";
			break;
		default:
			break;
		}
	} while (escolha != 2);
	*/
	
	std::cout << "Welcome!";
	Pausa();
	system("cls");
	MenuPrincipal(emp);
	system("cls");
	std::cout << "\n\nJe suis desoles...\n\n";
	return;
}



/**
*solicita a criacao de um novo ficheiro para o inicio do programam
*
*@param emp
*/


void Interface::NovoFicheiro(Empresa* emp) {

	std::string nome_ficheiro;
	system("cls");
	std::cout << "Nome do ficheiro: ";
	std::cin.clear();
	std::cin >> nome_ficheiro;

	std::ofstream ficheiro;
	ficheiro.open(nome_ficheiro);
	if (!ficheiro.is_open()) {
		std::cout << "\n\nErro ao criar ficheiro\n\n";
		return;
	}
	ficheiro.close();

	//MenuPrincipal(emp);
	return;
}


/**
*guarda a sessao actual num ficheiro solicitado pelo utilizador
*
*@param emp
*/

void Interface::GuardaFicheiro(Empresa* emp) {

	std::string nome_ficheiro;
	std::string ficheiro_clientes, ficheiro_empresa, ficheiro_servicos;
	std::string tchk = "|";

	system("cls");
	std::cout << "Nome do ficheiro: ";
	std::cin >> nome_ficheiro;

	ficheiro_clientes = nome_ficheiro + "_clientes.txt";
	ficheiro_empresa = nome_ficheiro + "_empresa.txt";
	ficheiro_servicos = nome_ficheiro + "_servicos.txt";

	std::ofstream ficheiro_clientes_ofstream;
	ficheiro_clientes_ofstream.open(ficheiro_clientes);

	if (!ficheiro_clientes_ofstream.is_open()) {
		std::cout << "\n\nErro ao criar ficheiro (clientes)\n\n";
		Pausa();
		return;
	}

	else {
		for (size_t i = 0; i < emp->getRegistados().size(); i++) {
			ficheiro_clientes_ofstream << emp->getRegistados()[i]->getNome();
			ficheiro_clientes_ofstream << tchk;
			ficheiro_clientes_ofstream << emp->getRegistados()[i]->getMorada();
			ficheiro_clientes_ofstream << tchk;
			ficheiro_clientes_ofstream << emp->getRegistados()[i]->getNIF();
			ficheiro_clientes_ofstream << tchk;
			ficheiro_clientes_ofstream << emp->getRegistados()[i]->getTipo();
			ficheiro_clientes_ofstream << '\n';
		}
	}
	ficheiro_clientes_ofstream.close();

	std::ofstream ficheiro_empresa_ofstream;
	ficheiro_empresa_ofstream.open(ficheiro_empresa);
	if (!ficheiro_empresa_ofstream.is_open()) {
		std::cout << "\n\nErro ao criar ficheiro (empresa)\n\n";
		Pausa();
		return;
	}

	else {
		ficheiro_empresa_ofstream << emp->getNome();
		ficheiro_empresa_ofstream << tchk;
		ficheiro_empresa_ofstream << emp->getMorada();
		ficheiro_empresa_ofstream << '\n';
		}
	ficheiro_empresa_ofstream.close();



	std::ofstream ficheiro_servicos_ofstream;
	ficheiro_servicos_ofstream.open(ficheiro_servicos);
	if (!ficheiro_servicos_ofstream.is_open()) {
		std::cout << "\n\nErro ao criar ficheiro (clientes)\n\n";
		Pausa();
		return;
	}

	else {
		for (size_t i = 0; i < emp->getRegistados().size(); i++) {

		}
	}


}


/**
*carrega um ficheiro solicitado pelo utilizador para inicio do programa
*
*@param emp
*/

void Interface::CarregaFicheiro(Empresa* emp) {

	std::string nome_ficheiro;
	std::string ficheiro_clientes, ficheiro_empresa, ficheiro_servicos;
	std::string tchk;
	std::string linha;
	std::istringstream input;

	system("cls");
	std::cout << "Nome do ficheiro: ";
	std::cin >> nome_ficheiro;

	ficheiro_clientes = nome_ficheiro + "_clientes.txt";
	ficheiro_empresa = nome_ficheiro + "_empresa.txt";
	ficheiro_servicos = nome_ficheiro + "_servicos.txt";

	std::ifstream ficheiro_empresa_ifstream;
	ficheiro_empresa_ifstream.open(ficheiro_empresa);
	if (!ficheiro_empresa_ifstream.is_open()) {
		std::cout << "\n\nErro ao abrir ficheiro (empresa)\n\n";
		Pausa();
		return;
	}

	std::string nome_empresa;
	std::string morada_empresa;

	while (ficheiro_empresa_ifstream.good())
	{
		std::getline(ficheiro_empresa_ifstream, nome_empresa, '|');
		std::getline(ficheiro_empresa_ifstream, morada_empresa, '\n');
	}

	Empresa *tempemp = new Empresa(nome_empresa, morada_empresa);
	//emp = tempemp;

	emp->setNome(nome_empresa);
	emp->setMorada(morada_empresa);

	ficheiro_empresa_ifstream.close();

	std::ifstream ficheiro_clientes_ifstream;
	ficheiro_clientes_ifstream.open(ficheiro_clientes);
	if (!ficheiro_clientes_ifstream.is_open()) {
		std::cout << "\n\nErro ao abrir ficheiro (clintes)\n\n";
		Pausa();
		return;
	}

	//while (std::getline(ficheiro_clientes_ifstream, linha))
	while (ficheiro_clientes_ifstream.good())
	{
		//std::istringstream input(linha);

		std::string nome_clientes, morada_clientes, tipo_clientes;
		std::string NIF_string;
		unsigned int NIF_clientes;


		std::getline(ficheiro_clientes_ifstream, nome_clientes, '|');
		std::getline(ficheiro_clientes_ifstream, morada_clientes, '|');
		std::getline(ficheiro_clientes_ifstream, NIF_string, '|');
		std::getline(ficheiro_clientes_ifstream, tipo_clientes, '\n');
		std::cout << nome_clientes << std::endl << morada_clientes << std::endl << NIF_string << std::endl << tipo_clientes << std::endl;
		
		NIF_clientes = atoi(NIF_string.c_str());
		std::cout << NIF_clientes << std::endl;

		//ficheiro_clientes_ifstream >> nome_clientes >> tchk >> morada_clientes >> tchk >> NIF_clientes >> tchk >> tipo_clientes;
		
		if (tipo_clientes == "registado") {
			Registado* tempReg = new Registado(nome_clientes, morada_clientes, NIF_clientes);
			//tempemp->getRegistados().push_back(tempReg);
			emp->getRegistados().push_back(tempReg);
		}
		else if (tipo_clientes == "empresarial") {
			Empresarial* tempEmpr = new Empresarial(nome_clientes, morada_clientes, NIF_clientes);
			//tempemp->getRegistados().push_back(tempEmpr);
			emp->getRegistados().push_back(tempEmpr);
		}
		else if (tipo_clientes == "particular") {
			Particular* tempPart = new Particular(nome_clientes, morada_clientes, NIF_clientes);
			//tempemp->getRegistados().push_back(tempPart);
			emp->getRegistados().push_back(tempPart);
		}
		else {
			std::cout << "\n\nTipo de cliente invalido!\n\n";
			return;
		}
		
	}

		ficheiro_clientes_ifstream.close();


		std::ifstream ficheiro_servicos_ifstream;
		ficheiro_servicos_ifstream.open(ficheiro_servicos);
		if (!ficheiro_servicos_ifstream.is_open()) {
			std::cout << "\n\nErro ao abrir ficheiro (clintes)\n\n";
			Pausa();
			return;
		}

		while (ficheiro_clientes_ifstream.good())
		{
			//std::istringstream input(linha);

			std::string origem_servicos, destino_servicos;

			unsigned int horas_servicos, minutos_servicos;
			std::string horas_string, minutos_string;

			unsigned int dia_servicos, mes_servicos, ano_servicos;
			std::string dia_string, mes_string, ano_string;

			//ficheiro_clientes_ifstream >> nome_clientes >> tchk >> morada_clientes >> tchk >> NIF_clientes >> tchk >> tipo_clientes;
			
			std::getline(ficheiro_servicos_ifstream, origem_servicos, '|');
			std::getline(ficheiro_servicos_ifstream, destino_servicos, '|');
			std::getline(ficheiro_servicos_ifstream, dia_string, '/');
			std::getline(ficheiro_servicos_ifstream, mes_string, '/');
			std::getline(ficheiro_servicos_ifstream, ano_string, '|');
			std::getline(ficheiro_servicos_ifstream, horas_string, ':');
			std::getline(ficheiro_servicos_ifstream, minutos_string, '\n');

			dia_servicos = std::stoi(dia_string);
			mes_servicos = std::stoi(mes_string);
			ano_servicos = std::stoi(ano_string);
			horas_servicos = std::stoi(horas_string);
			minutos_servicos = std::stoi(minutos_string);

			tempo tempTempo;
			tempTempo.horas = horas_servicos;
			tempTempo.minutos = minutos_servicos;
			tempTempo.segundos = 0;

			data_struct tempData;
			tempData.dia = dia_servicos;
			tempData.mes = mes_servicos;
			tempData.ano = ano_servicos;

			Servico* tempServ = new Servico(origem_servicos, destino_servicos, tempData, tempTempo);

			//tempemp->getHistorico().push_back(tempServ);
			emp->getHistorico().push_back(tempServ);

			ficheiro_servicos_ifstream.close();
	}

		//emp = tempemp;
}


/**
*permite ao jogador criar a sua empresa
*
*@return Empresa*
*/

Empresa* Interface::CriarEmpresa() {
	std::string nome, morada;
	std::cout << "\nCriacao de uma Empresa:\n";
	std::cout << "Nome: ";
	std::cin.clear();
	std::cin >> nome;
	std::cout << "\nMorada: ";
	std::cin.clear();
	std::cin >> morada;

	Empresa* temp = new Empresa(nome, morada);
	return temp;
}



/**
*permite ao utilizador criar um servico
*
*@return Servico*
*/

Servico* Interface::CriarServico() {
	std::string origem, destino;
	unsigned int dia, mes, ano;
	unsigned int hora, minuto;
	data_struct data;
	tempo horas;

	std::cout << "\nCriacao de um Servico:\n";
	std::cout << "Origem: ";
	std::cin.clear();
	std::cin >> origem;
	std::cout << "\nDestino: ";
	std::cin.clear();
	std::cin >> destino;

	if (origem == destino) {
		std::cout << "\nPercurso invalido!\n";
		return NULL;
	}

	std::cout << "Ano: ";
	std::cin.clear();
	std::cin >> ano;

	if (ano < 0) {
		std::cout << "\nAno invalido!\n";
		return NULL;
	}

	std::cout << "\nMes: ";
	std::cin.clear();
	std::cin >> mes;

	if (mes > 12 || mes < 0) {
		std::cout << "\nMes invalido!\n";
		return NULL;
	}

	std::cout << "\nDia: ";
	std::cin.clear();
	std::cin >> dia;

	if (dia > 31 || dia < 0) {
		std::cout << "\nDia invalido!\n";
		return NULL;
	}

	std::cout << "\nHoras: ";
	std::cin.clear();
	std::cin >> hora;

	if (hora < 0 || hora > 24) {
		std::cout << "\nHoras invalidas!\n";
		return NULL;
	}

	std::cout << "\nMinutos: ";
	std::cin.clear();
	std::cin >> minuto;

	if (minuto < 0 || minuto > 60) {
		std::cout << "\nMinutos invalidos!\n";
		return NULL;
	}

	data.ano = ano;
	data.mes = mes;
	data.dia = dia;

	horas.horas = hora;
	horas.minutos = minuto;
	horas.segundos = 0;

	Servico* temp = new Servico(origem, destino, data, horas);
	return temp;
}

Cliente* Interface::CriarCliente() {
	std::string nome, morada;
	unsigned int NIF;

	std::cout << "\nCriacao de um Cliente:\n";	
	std::cout << "Nome: ";
	std::cin.clear();
	std::cin >> nome;
	std::cout << "\nMorada: ";
	std::cin.clear();
	std::cin >> morada;
	std::cout << "\nNIF: ";
	std::cin.clear();
	std::cin >> NIF;

	if (NIF < 0) {
		std::cout << "\nNIF invalido!\n";
		return NULL;
	}

	Cliente* cli = new Cliente(nome, morada, NIF);

	return cli;
}




/**
*«permite ao utilizador criar um cliente Registado
*
*@return Registado*
*/

Registado* Interface::CriarRegistado() {

	unsigned int tipo, NIF;
	std::string nome, morada;

	std::cout << "\nCriacao de um Registado:\n";
	std::cout << "0 - Cliente Registado Particular\n";
	std::cout << "1 - Cliente Registado Empresarial\n";
	std::cin.clear();
	std::cin >> tipo;
	std::cout << "Nome: ";
	std::cin.clear();
	std::cin >> nome;
	std::cout << "\nMorada: ";
	std::cin.clear();
	std::cin >> morada;
	std::cout << "\nNIF: ";
	std::cin.clear();
	std::cin >> NIF;

	if (NIF < 0) {
		std::cout << "\nNIF invalido!\n";
		return NULL;
	}

	switch (tipo) {
	case 0: {
		Registado* reg = new Particular(nome, morada, NIF);
		return reg;
	}

	case 1: {
		Registado* reg = new Empresarial(nome, morada, NIF);
		return reg;
	}

	default:
		std::cout << "\nTipo de Cliente invalido!\n";
		return NULL;
	}
}