#include "RegistadoPointer.h"

RegistadoPointer::RegistadoPointer(Registado* pointer) {
	this->RegistadoPtr = pointer;
}


void RegistadoPointer::setPointer(Registado* pointer) {
	this->RegistadoPtr = pointer;
}

Registado* RegistadoPointer::getPointer() const {
	return this->RegistadoPtr;
}


bool RegistadoPointer::operator<(const RegistadoPointer &rRHS) const {
	return this->getPointer()->getNome() < rRHS.getPointer()->getNome();
}

bool RegistadoPointer::operator==(const RegistadoPointer &rRHS) const {
	return this->getPointer() == rRHS.getPointer();
}
