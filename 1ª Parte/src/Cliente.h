#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


#include "Servico.h"



class Cliente{

protected:
  std::string nome;
  std::string morada;
  unsigned int NIF;

public:

//CONSCTRUCTORS
  Cliente(){}
  Cliente(const std::string nome , const std::string morada, const unsigned int NIF);
  Cliente(const std::string nome, const std::string morada);
  Cliente(std::string nome);
  ~Cliente(){
    std::cout << "Cliente " << nome << " terminado.\n";
  }

  bool operator== (const Cliente &cli) const {
	  return NIF == cli.getNIF();
  }

  bool operator< (const Cliente &cli) const {
	  return nome < cli.getNome();
  }

 void operator= (const Cliente &cli);

//METODOS GET
std::string getNome() const{ return nome; }
std::string getMorada() const{ return morada; }
unsigned int getNIF() const{ return NIF; }
virtual std::string getInformacao() const;

//METODOS SET
void setNome(std::string nome){ this->nome = nome; }
void setMorada(std::string morada){ this->morada = morada; }
void setNIF(unsigned int NIF){ this->NIF = NIF; }


//METODOS RELATIVOS A SERVICOS
virtual bool pagamentoNumerario(Servico &serv);
virtual bool pagamentoMultibanco(Servico &serv);

};





class Registado : public Cliente{

private:

  std::vector<Servico *> historico;

public:

  Registado(){}
  Registado(std::string nome, std::string morada, const unsigned int NIF);
  Registado(std::string nome, std::string morada);
  Registado(std::string nome);

  std::vector<Servico *> getHistorico() const;
  virtual std::string getInformacao() const;

  //METODOS RELATIVOS A SERVICOS

  void operator=(const Registado &reg);

  virtual std::string getInformacaoServicos() const;
  virtual std::string getTipo() const { return "registado";  }



  virtual bool pagamentoNumerario(Servico &serv);
  virtual bool pagamentoMultibanco(Servico &serv);
  virtual bool pagamentoCartaoCredito(Servico &serv);
  virtual bool pagamentoFimDoMes(std::vector<Servico *> servs);
  

  virtual bool pagamentoNumerario(unsigned int id);
  virtual bool pagamentoMultibanco(unsigned int id);
  virtual bool pagamentoCartaoCredito(unsigned int id);
  virtual bool pagamentoFimDoMes(std::vector<unsigned int> ids);
  
  //bool adicionaServico(Servico &serv);
  bool adicionaServico(Servico* serv);


};





class Empresarial : public Registado{

private:


public:
	Empresarial(){}
	Empresarial(std::string nome, std::string morada, const unsigned int NIF);
	Empresarial(std::string nome, std::string morada);
	Empresarial(std::string nome);
	virtual std::string getInformacao() const;
	virtual std::string getTipo() const;
};




class Particular : public Registado{

private:

public:
	Particular(){}
	Particular(std::string nome, std::string morada, const unsigned int NIF);
	Particular(std::string nome, std::string morada);
	Particular(std::string nome);
	virtual std::string getInformacao() const;
	virtual std::string getTipo() const;


};


#endif /* CLIENTE_H */
