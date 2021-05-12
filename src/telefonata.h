/*
 * telefonata.h
 *
 *  Created on: 10 mag 2021
 *      Author: poold
 */

#ifndef TELEFONATA_H_
#define TELEFONATA_H_

#include <iostream>
#include "orario.h"

using std::ostream;

class telefonata {
public:
	telefonata();
	telefonata(const orario&,const orario& ,int);
	orario Inizio() const;
	orario Fine() const;
	int Numero() const;
	bool operator== (const telefonata&) const;
private:
	orario inizio;
	orario fine;
	int numero;
};

ostream& operator<<(ostream&, const telefonata&);


#endif /* TELEFONATA_H_ */
