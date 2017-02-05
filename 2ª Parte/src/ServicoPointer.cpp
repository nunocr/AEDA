#include "ServicoPointer.h"

ServicoPointer::ServicoPointer(Servico* pointer) {
	this->servicoPtr = pointer;
}


void ServicoPointer::setPointer(Servico* pointer) {
	this->servicoPtr = pointer;
}

Servico* ServicoPointer::getPointer() const {
	return this->servicoPtr;
}


bool ServicoPointer::operator<(const ServicoPointer &rRHS) const {
	return this->getPointer()->getNome() < rRHS.getPointer()->getNome();
}

bool ServicoPointer::operator==(const ServicoPointer &rRHS) const {
	return this->getPointer() == rRHS.getPointer();
}
