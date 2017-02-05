#ifndef SERVICO_H
#define SERVICO_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Utilidades.h"


//
//	PAGAMENTO DO SERVICO:
//
//		TODOS OS CLIENTES:
//			-numerario
//			-multibanco
//
//		CLIENTES REGISTADOS
//			-cartao de credito -> acrescimo de 5% do valor total do servico
//			-fim do mes -> acrescimo de 2% do valor total de todos os servicos ao fim do mes
//				NOTA: para viagens realizadas entre o primeiro e o ultimo dia
//					  do mes anterior
//
//



class Servico{

private:
  unsigned int id;
  std::string origem;
  std::string destino;
  unsigned int distancia;
  float valor; //depende da distancia, tempo de viagem e transito
  data_struct data_realizacao;
  tempo horas;
  bool estado;
  std::string tipo_pagamento;
  unsigned int NIF; //NIF do cliente que pagou o servico

public:
  Servico(){}
  Servico(std::string origem, std::string destino);
  Servico(std::string origem, std::string destino, data_struct dt, tempo horas);
//Servico(unsigned int id, std::string origem, std::string destino);
  ~Servico(){
    std::cout << "Servico terminado.\n";
  }
  bool operator== (const Servico &serv) const;

  std::string getOrigem() const;
  std::string getDestino() const;
  tempo getHoras() const;
  float getValor() const;
  data_struct getData() const;
  unsigned int getId() const;
  std::string getInformacao() const;
  bool getEstado() const;
  unsigned int getDefaultId() const;
  float getDefaultValor() const;
  tempo getInicioPeriodoTransito() const;
  tempo getFimPeriodoTransito() const;
  float getImpostoTransito() const;
  unsigned int getNIF() const;


  void setOrigem(std::string origem);
  void setDestino(std::string destino);
  void setData(data_struct dt);
  void setHoras(tempo horas);
  void setPago();
  void setTipoPagamento(std::string tipo);
  void setValor(float valor);
  void setNIF(unsigned int NIF);
  void setPeriodoTransito();
  void setImpostoTransito(float imposto);

};




#endif /* SERVICO_H */
