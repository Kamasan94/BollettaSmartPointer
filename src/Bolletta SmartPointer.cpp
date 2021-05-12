//============================================================================
// Name        : Bolletta SmartPointer.cpp
// Author      : Marco Davanzo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bolletta.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	bolletta b;
	orario inizio(12,0,0);
	orario fine (13,0,0);
	telefonata t(inizio, fine, 333333333);
	orario i(15,0,0);
	orario f(23,0,0);
	telefonata p(i,f,4);
	b.Aggiungi_Telefonata(t);
	b.Sostituisci(t,p);
	cout << b;
	return 0;
}
