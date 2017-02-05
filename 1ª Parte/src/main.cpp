#include <iostream>
#include "Servico.h"
#include "Cliente.h"
#include "Empresa.h"
#include "Utilidades.h"
#include "sequentialSearch.h"
#include "insertionSort.h"
#include "Interface.h"



/**
*inicializa o programa
*
*
*/

int main(){

	//criacao do Servico nulo para inicializacao do periodo de maior transito que influenciara os valores dos posteriores servicos
	
	/**
	*criacao de um servico nulo para definir o periodo de maior transito
	*
	*o servico nuloe tem id = 0
	*/
	
	tempo tt;
	tt.horas = 0;
	tt.minutos = 0;
	tt.segundos = 0;
	data_struct dd;
	dd.dia = 0;
	dd.mes = 0;
	dd.ano = 0;

	Servico* default_serv = new Servico("-", "-", dd, tt);
	default_serv->setPeriodoTransito();

/*
  Cliente* cli0 = new Cliente("Um pacato fazendeiro", "a sua tendinha de comercio", 0101001);
  Cliente* cli1 = new Registado("Joaquim Alberto Malaquias", "Gaia Porto Porto Porto", 123456);
  Cliente* cli2 = new Registado("Desmond Wolf", "Somewhere in London");
  Cliente* cli3 = new Registado("Piero Scaruffi");
*/ 



/**
*criacao de clientes, clientes registados, empresariais e particulares
*
*usado ao testar o programa
*/

  Registado* cli11 = new Registado("Joaquim Alberto Malaquias", "Gaia Porto Porto Porto", 123456);
  Registado* cli12 = new Registado("Joaquina Alberta Malaquias", "Almada Lisboa Lisboa Lisboa", 123456);

  Registado* cli4 = new Empresarial("Anthony Fantano", "Memelandia", 666);
  Registado* cli9 = new Empresarial("Anthony Fantano", "Memelandia", 666);
  Registado* cli10 = new Empresarial("Cal Cuchesta", "Memelandia", 665);
  Registado* cli5 = new Particular("Harambe", "Memelandia", 420);
  Registado* cli6 = new Particular("Harambe", "Memelandia", 420);
  Registado* cli7 = new Particular("Harambe", "Memelandia", 419);
  Registado* cli8 = new Particular("Scarce", "Memelandia", 419);


  Registado* cli1 = new Registado("Joaquim Alberto Malaquias", "Gaia Porto Porto Porto", 123456);
  Registado* cli2 = new Registado("Desmond Wolf", "Somewhere in London", 77777);
  Registado* cli3 = new Registado("Piero Scaruffi", "Somewhere in Italy", 420666);



  /**
  *criacao de Servicos para testar o programa
  *
  *
  */



	tempo t0;
	t0.horas = 10;
	t0.minutos = 30;
	t0.segundos = 0;

	data_struct d0;
	d0.ano = 2016;
	d0.mes = 12;
	d0.dia = 1;

	Servico* serv0 = new Servico("Lisboa", "Porto", d0, t0);


	tempo t1;
	t1.horas = 12;
	t1.minutos = 40;
	t1.segundos = 0;

	data_struct d1;
	d1.ano = 2016;
	d1.mes = 11;
	d1.dia = 30;

	Servico* serv1 = new Servico("Braga", "Porto", d1, t1);


	tempo t2;
	t2.horas = 16;
	t2.minutos = 0;
	t2.segundos = 0;

	data_struct d2;
	d2.ano = 2016;
	d2.mes = 12;
	d2.dia = 2;

	Servico* serv2 = new Servico("Coimbra", "Braga", d2, t2);



	/**
	*criacao de uma empresa para testar o programa
	*
	*
	*/

  Empresa emp1("Evil Corp", "wherever the NSA headquarters are");

  /*


  /**
  *teste de lancamento de excepcoes
  *
  *
  */

  try{
	  
	  emp1.adicionaCliente(cli1);
	  
	  emp1.adicionaCliente(cli2);
	  emp1.adicionaCliente(cli3);
	  

	  emp1.adicionaCliente(cli4);
	  emp1.adicionaCliente(cli5);
	  

	  emp1.adicionaCliente(cli11);
	  emp1.adicionaCliente(cli12);

	  //emp1.adicionaCliente(cli6);
	  //emp1.adicionaCliente(cli7);
	  //emp1.adicionaCliente(cli8);
	  //emp1.adicionaCliente(cli9);
	  //emp1.adicionaCliente(cli10);
	  //emp1.adicionaCliente(cli3);
  }
    catch(ClienteRepetido clirep){
	  clirep.printInfo();
  }
  	catch(ClienteInexistente clinex){
  	  clinex.printInfo();
  }

	  //std::cout << emp1.getInformacao();
	  
	  
	  /*
	  std::cout << "~~~~~~~~Servicos~~~~~~~~~";
	  std::cout << "\n\n" << serv0->getInformacao();
	  std::cout << "\n" << serv1->getInformacao() << "\n";
	  std::cout << serv2->getInformacao() << "\n";
	  */

	  //std::cout << "\n\n\n\n";

	  /*
	  try {
		  //emp1.removeCliente(123456);
		  emp1.removeCliente(10);
		  emp1.removeCliente(cli2);
	  }
	  catch (ClienteInexistente clinex) {
		  clinex.printInfo();
	  }
	  */


	  /**
	  *adicionamentos de servico em Clientes
	  *
	  *para testar o programa
	  */
 
	  emp1.adicionaServicoCliente(serv0, 123456);
	  emp1.adicionaServicoCliente(serv1, 123456);
	  emp1.adicionaServicoCliente(serv2, 123456);

	  emp1.adicionaServicoCliente(serv0, 420666);
	  
	  emp1.adicionaServicoCliente(serv1, 420);
	  emp1.adicionaServicoCliente(serv2, 420);
	  
	  //std::cout << emp1.getInformacao();
	  
	  //std::cout << cli1->getInformacao();
	  /*
	  std::cout << "\n\n\n";
	  cli1->pagamentoCartaoCredito(0);
	  std::cout << emp1.getInformacao();
	  */
	  
	  //std::cout << "\n\n\n\n";
	  //std::cout << emp1.getInformacaoServicos();


	  /**
	  *inicializa a parte relativa a manipulacao do programa pelo utilizador,
	  *atraves da inicializacao da interface
	  *
	  */

	  Empresa *emperor = new Empresa();
	  
	  Interface face;
	  face.MenuInicial(&emp1);
	  face.MenuInicial(emperor);

  return 0;
}
