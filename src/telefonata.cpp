/*
 * telefonata.cpp
 *
 *  Created on: 10 mag 2021
 *      Author: poold
 */

#include "telefonata.h"

telefonata::telefonata(const orario& i, const orario& f, int n): inizio(i), fine(f), numero(n) {};

telefonata::telefonata() {
	inizio = 0;
	fine = 0;
	numero = 0;
}

orario telefonata::Inizio() const {return inizio;}
orario telefonata::Fine() const {return fine;}
int telefonata::Numero() const {return numero;}

bool telefonata::operator== (const telefonata& o) const {
	return inizio == o.inizio && fine == o.fine && numero == o.numero;
}

ostream& operator<<(ostream& os, const telefonata& t) {
	return os << "INIZIO: "<< t.Inizio() << " FINE: " << t.Fine() << " NUMERO: " << t.Numero();
}
