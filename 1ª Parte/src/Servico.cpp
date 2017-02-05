
#include "Servico.h"
#include "sequentialSearch.h"
#include "insertionSort.h"
#include <stdlib.h>



static unsigned int default_id = 0;
static float default_valor = 15;
static float imposto_transito = 20.5; //em percentagem

static tempo inicio_periodo_transito;
static tempo fim_periodo_transito;


/**
*obtem o inicio do periodo de maior transico
*
*
*@return tempo
*
*/

tempo Servico::getInicioPeriodoTransito() const {
	return inicio_periodo_transito;
}


/**
*obtem o fim do periodo de maior transico
*
*
*@return tempo
*
*/

tempo Servico::getFimPeriodoTransito() const {
	return fim_periodo_transito;
}

/**
*obtem o imposto sobre servico devido a hora de maior transito
*
*@return tempo
*
*/

float Servico::getImpostoTransito() const {
	return imposto_transito;
}




/**
*define o periodo de maior transito
*
*/

void Servico::setPeriodoTransito() {
	unsigned int horas_inicio, minutos_inicio;
	unsigned int horas_fim, minutos_fim;
	
	std::cout << "Definir periodo de maior transito:\n";
	std::cout << "Inicio de periodo:\n";
	std::cout << "horas: ";
	std::cin.clear();
	std::cin >> horas_inicio;
	std::cout << "\nminutos: ";
	std::cin.clear();
	std::cin >> minutos_inicio;
	std::cout << "\nFim de periodo: ";
	std::cin.clear();
	std::cin >> horas_fim;
	std::cout << "\nhoras: ";
	std::cin.clear();
	std::cin >> minutos_fim;
	std::cout << "\nminutos: ";

	inicio_periodo_transito.horas = horas_inicio;
	inicio_periodo_transito.minutos = minutos_inicio;
	inicio_periodo_transito.segundos = 0;

	fim_periodo_transito.horas = horas_fim;
	fim_periodo_transito.minutos = minutos_fim;
	fim_periodo_transito.segundos = 0;

	system("cls");
}



/**
*define o imposto sobre servico devido a maior hora de transito
*
@param imposto
*
*
*/

void Servico::setImpostoTransito(float imposto) {
	if (imposto < 0 || imposto > 100) {
		std::cout << "\nimposto de transito invalido\n";
		return;
	}
	imposto_transito = imposto;
}


/**
*obtem o id de um servico
*
*
*@return default_id
*
*/

unsigned int Servico::getDefaultId() const{
	return default_id;
}

/**
*obtem o valor de um servico
*
*@return default_valor
*
*/

float Servico::getDefaultValor() const {
		return default_valor;
	}



/**
*Constructor de um Servico (viagem)
*
*
@param origem, destino
*
*/

    Servico::Servico(std::string origem, std::string destino){
    	this->id = default_id;
    	this->origem = origem;
    	this->destino = destino;
    	this->estado = false;
    	this->tipo_pagamento = "";
    	this->distancia = 0;
		this->NIF = 0;
		if (
			((horas.horas >= getInicioPeriodoTransito().horas) && (horas.horas <= getFimPeriodoTransito().horas))
			|| ((horas.horas == getInicioPeriodoTransito().horas) && (horas.minutos >= getInicioPeriodoTransito().minutos))
			|| ((horas.horas == getFimPeriodoTransito().horas) && horas.minutos <= getFimPeriodoTransito().minutos))
			this->valor = getDefaultValor() + (getImpostoTransito() / 100);
		else this->valor = default_valor; //VALOR VARIA DE ACORDO COM A DISTANCIA E HORA
    	default_id++;
    }


	/**
	*Constructor de um Servico (viagem)
	*
	*
	@param origem, destino, dt, horas
	*
	*constroi um servico, podendo ser definidos nao so a origem e o destino tal como a data e horas
	*/

    Servico::Servico(std::string origem, std::string destino, data_struct dt, tempo horas){
    	this->id = default_id;
      	this->origem = origem;
   	 	this->destino = destino;
   	 	this->estado = false;
   	 	this->data_realizacao.dia = dt.dia;
   	 	this->data_realizacao.mes = dt.mes;
   	    this->data_realizacao.ano = dt.ano;
   	    this->horas.horas = horas.horas;
   	 	this->horas.minutos = horas.minutos;
   	 	this->horas.segundos = horas.segundos;
   	 	this->tipo_pagamento == "";
   	 	this->distancia = 0;
		this->NIF = 0;

		if (
			((horas.horas >= getInicioPeriodoTransito().horas) && (horas.horas <= getFimPeriodoTransito().horas))
			|| ((horas.horas == getInicioPeriodoTransito().horas) && (horas.minutos >= getInicioPeriodoTransito().minutos))
			|| ((horas.horas == getFimPeriodoTransito().horas) && horas.minutos <= getFimPeriodoTransito().minutos)			)
		this->valor = getDefaultValor() + (getImpostoTransito() / 100);
		else this->valor = default_valor;
   	 	default_id++;
    }





	/**
	*Retorna uma string que representa a origem de um Ser ico
	*
	*
	@return string
	*
	*/

  std::string Servico::getOrigem() const{
	  return origem;
  }


  /**
  *retorna uma string que representa o destino de um Servico
  *
  *@return string
  */

  std::string Servico::getDestino() const{
	  return destino;
  }





  /**
  *Retorna a data de um Servico
  *
  *
  @return data_struct
  */

  data_struct Servico::getData() const{
	  return data_realizacao;
  }

  /**
  *Retorna as horas de um Servico
  *
  *
  *@return tempo
  */

  tempo Servico::getHoras() const{
	  return horas;
  }

  /**
  *retorna i valor de um Servico
  *
  *@return float
  */

  float Servico::getValor() const{ //dependera da distancia, tempo de viagem e transito
	  if(
		  ((horas.horas >= getInicioPeriodoTransito().horas) && (horas.horas <= getFimPeriodoTransito().horas))
	||	  ((horas.horas == getInicioPeriodoTransito().horas) && (horas.minutos >= getInicioPeriodoTransito().minutos))
	||    ((horas.horas == getFimPeriodoTransito().horas) && horas.minutos <= getFimPeriodoTransito().minutos)			)
	  return valor + (getImpostoTransito() / 100);
	  else return valor;
  }


  /**
  *Retorna o esstado de um servico (pago ou por pagar)
  *
  *@return estado
  */

  bool Servico::getEstado() const{
	  return estado;
  }

  /**
  *retorna o Id de um Servicod
  *
  *@return 
  *
  */

  unsigned int Servico::getId() const{
	  return id;
  }


  /**
  *´Devolve o NIF do cliente qeu pagou o Servico
  *
  *@return int
  *
  */

  unsigned int Servico::getNIF() const {
	  return NIF;
  }



  /**
  *define a origem de um Servico
  *
  @param origem
  *
  */

  void Servico::setOrigem(std::string origem){
	  this->origem = origem;
  }
  
  /**
  *define o destino de um Servico
  *
  *
  @param destino
  *
  */

   void Servico::setDestino(std::string destino){
	   this->destino = destino;
   }



   /**
   *define a data de um Servico
   *
   *
   @param dt
   *
   */

   void Servico::setData(data_struct dt){
	   this->data_realizacao.dia = dt.dia;
	   this->data_realizacao.mes = dt.mes;
	   this->data_realizacao.ano = dt.ano;

   }

   /**
   *define as horas de um Servico
   *
   *
   @param origem, destino
   *
   */

   void Servico::setHoras(tempo horas){
	   this->horas.horas = horas.horas;
	   this->horas.minutos = horas.minutos;
	   this->horas.segundos = horas.segundos;
   }


   /**
   *coloca o estado do Servico como "pago"
   *
   *
   */

   void Servico::setPago(){
	   this->estado = true;
   }




   /**
   *define o tipo de pagamento de um servico
   *
   *
   */

   void Servico::setTipoPagamento(std::string tipo){
	   this->tipo_pagamento = tipo;
   }


   /**
   *define o valor de um Servico
   *
   *@ valor
   *
   *
   */

   void Servico::setValor(float valor){
	   if(valor < 0)
		   this->valor = default_valor;
	   this->valor = valor;
   }



   /**
   *coloca o estado do Servico como "pago"
   *
   *
   */

   void Servico::setNIF(unsigned int NIF) {
	   this->NIF = NIF;
   }







   /**
   *retorna uma string ja formatada com todas as informacoes relativas a um Servico
   *
   *@return string
   *
   */

   std::string Servico::getInformacao() const{

	   std::ostringstream info;

	   info << "\nid: " << this->id << "\norigem: " << this->origem << "\ndestino: " << this->destino;
	   info << "\nvalor: " << this->valor << "\ndata: " << this->data_realizacao.dia << "/" << this->data_realizacao.mes << "/" << this->data_realizacao.ano;
	   //info << "\nhoras: " << horas.horas << ":" << horas.minutos << ":" horas.segundos;
	   info << "\nestado: ";
	   if(this->estado){
		   info << "pago";
		   info << "\ntipo de pagamento: " << this->tipo_pagamento;
	   }
	   else { info << "por pagar\n"; }
	   //info << "\nNIF do comprador: " << this->NIF;

		return info.str();
   }



   /**
   *operador== para a classe Servico
   *
   *
   */

   bool Servico::operator== (const Servico &serv) const{
	   return(
		   (this->horas.horas == serv.getHoras().horas) &&
		   (this->horas.minutos == serv.getHoras().minutos) &&
		   (this->data_realizacao.ano == serv.getData().ano) &&
		   (this->data_realizacao.mes == serv.getData().mes) &&
		   (this->data_realizacao.dia == serv.getData().dia) &&
		   (this->origem == serv.getOrigem()) &&
		   (this->destino == serv.getDestino())
		   );
   }









