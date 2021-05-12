/*
 * bolletta.cpp
 *
 *  Created on: 12 mag 2021
 *      Author: poold
 */


#include "bolletta.h"
using std::ostream; using std::endl;

//Metodi di smartp

//COSTRUTTORE
bolletta::smartp::smartp(nodo* p) : punt(p) {
	if (punt) punt->riferimenti++;
}

//COSTRUTTORE DI COPIA
bolletta::smartp::smartp(const smartp& s) : punt(s.punt) {
	if (punt) punt->riferimenti++;
}

//DISTRUTTORE
bolletta::smartp::~smartp() {
	if (punt) {
		punt->riferimenti--;
		if (punt->riferimenti == 0) {
			delete punt;
		}
	}

}

//DISUGUAGLIANZA
bool bolletta::smartp::operator !=(const smartp& s) const {
	return punt != s.punt;
}

//ASSEGNAZIONE
bolletta::smartp& bolletta::smartp::operator=(const smartp& s) {
	if (this!=&s) {
		nodo* p = punt;
		punt = s.punt;
		if (punt) punt->riferimenti++;
		if (p) {
			p->riferimenti--;
			if(p->riferimenti == 0) delete p;
		}
	}
	return *this;
}

//DEREFERENZIAZIONE
bolletta::nodo& bolletta::smartp::operator*() const {
	return *punt;
}

//SELEZIONE MEMBRO
bolletta::nodo* bolletta::smartp::operator ->() const {
	return punt;
}

//UGUAGLIANZA
bool bolletta::smartp::operator ==(const smartp& s) const {
	return punt == s.punt;
}




//Metodi di nodo

//Costruttori
bolletta::nodo::nodo(): riferimenti(0) {}

bolletta::nodo::nodo(const telefonata& t, const smartp& s) : info(t), next(s), riferimenti(0) {}

//Metodi di bolletta
bool bolletta::Vuota() const { return first == 0; }

void bolletta::Aggiungi_Telefonata(const telefonata& t)
{
	first = new nodo(t,first);
}

telefonata bolletta::Estrai_Una()
{
	telefonata aux = first->info;
	first = first->next;
	return aux;
}

void bolletta::Togli_Telefonata(const telefonata& t)
{
	smartp p = first, prec, q;
	smartp original = first;
	first = 0;
	while(p!=0 && !(p->info==t))
	{
		q = new nodo(p->info, p->next); //fa una copia dei nodi che precedono eventualmente la telefonata da togliere
		//e li inserisce nella nuova lista puntata da first
		if (prec == 0) first = q;
		else prec->next = q;
		prec = q;
		p = p->next;
	}
	//se p == 0 la telefonata non è stata trovata, ho inutilmente copiato la lista, quindi ripristino la situazione originale
	if (p==0) {first = original;}
	else if (prec == 0) first = p->next;
	else prec->next = p->next;
}

void bolletta::Sostituisci(const telefonata& t1, const telefonata& t2)
{
	smartp p = first, prec, q;
	smartp original = first;
	first = 0;
	while(p!=0 && !(p->info == t1))
	{
		q = new nodo(p->info, p->next);
		if(prec == 0) first = q;
		else prec->next = q;
		prec = q;
		p = p->next;
	}

	if (p == 0)
	{
		first = original;
		return;
	}
	else if (prec == 0) first = new nodo(t2,p->next);
	else
		prec->next = new nodo(t2,p->next);
}

ostream& operator<<(ostream& os, const bolletta& b) {
	if(b.Vuota()) os << "BOLLETTA VUOTA" << endl;
	else {
		os << "TELEFONATE IN BOLLETTA" << endl;
		bolletta::smartp p = b.first;
		int i = 1;
		while (p!=0) {
			os << i++ << ") " << p->info << endl;
			p = p->next;
		}
	}
	return os;
}






