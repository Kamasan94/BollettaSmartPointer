/*
 * bolletta.h
 *
 *  Created on: 12 mag 2021
 *      Author: poold
 */

#ifndef BOLLETTA_H_
#define BOLLETTA_H_

#include<iostream>
#include "telefonata.h"

using std::ostream;

class bolletta {
public:
	bool Vuota() const;
	void Aggiungi_Telefonata(const telefonata&);
	void Togli_Telefonata(const telefonata&);
	telefonata Estrai_Una();
	void Sostituisci(const telefonata&, const telefonata&);
	friend ostream& operator<<(ostream&, const bolletta&);
private:
	class nodo;
	class smartp {
	public:
		nodo* punt;	//unico campo dati
		smartp(nodo* p = 0);
		smartp(const smartp&);
		~smartp();
		smartp& operator=(const smartp&);
		nodo& operator*() const;
		nodo* operator->() const;
		bool operator==(const smartp&) const;
		bool operator!=(const smartp&) const;
	};

	class nodo {
	public:
		nodo();
		nodo(const telefonata&, const smartp&);
		telefonata info;
		smartp next;
		int riferimenti;
	};

	smartp first;
};



#endif /* BOLLETTA_H_ */
