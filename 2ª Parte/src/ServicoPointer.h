#ifndef SERVICOPOINTER_H
#define SERVICOPOINTER_H

#include <iostream>
#include <string>
#include "Servico.h"

class ServicoPointer
{
public:
	ServicoPointer(Servico* pointer);

	void setPointer(Servico* pointer);

	Servico* getPointer() const;

	bool operator<(const ServicoPointer &rRHS) const;
	bool operator==(const ServicoPointer &rRHS) const;

private:
	Servico* servicoPtr;
};

#endif