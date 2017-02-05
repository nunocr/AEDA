#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "Empresa.h"
#include "Servico.h"
#include "Cliente.h"


class Interface {

public:
	Interface() {}

//private:
	int GetInput();

	void DisplayMenuInicial();
	void MenuInicial(Empresa* emp);

	void DisplayMenuPrincipal();
	void MenuPrincipal(Empresa* emp);

	void NovoFicheiro(Empresa* emp);
	void CarregaFicheiro(Empresa* emp);
	void GuardaFicheiro(Empresa* emp);

	Cliente* CriarCliente();
	Registado* CriarRegistado();
	Servico* CriarServico();
	Empresa* CriarEmpresa();

	void DisplayMenuPagamento();
	void MenuPagamento(Empresa* emp);
};










#endif /* INTERFACE_H */
