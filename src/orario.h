/*
 * orario.h
 *
 *  Created on: 10 mag 2021
 *      Author: poold
 */

#ifndef ORARIO_H_
#define ORARIO_H_

#include <iostream>
using namespace std;

class orario {
private:
	int sec;
public:
	orario (int =0, int =0, int =0);
	int Ore() const;
	int Minuti() const;
	int Secondi () const;
	orario operator+ (const orario&) const;
	orario operator- (const orario&) const;
	bool operator== (const orario&) const;
	bool operator< (const orario&) const;
	bool operator> (const orario&) const;
};

ostream& operator<<(ostream&, const orario&);



#endif /* ORARIO_H_ */
