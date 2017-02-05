#ifndef RegistadoPOINTER_H
#define RegistadoPOINTER_H

#include <iostream>
#include <string>
#include "Cliente.h"

class RegistadoPointer
{
public:
	RegistadoPointer(Registado* pointer);

	void setPointer(Registado* pointer);

	Registado* getPointer() const;

	bool operator<(const RegistadoPointer &rRHS) const;
	bool operator==(const RegistadoPointer &rRHS) const;

private:
	Registado* RegistadoPtr;
};

#endif