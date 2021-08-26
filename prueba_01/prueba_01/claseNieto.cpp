#include "claseNieto.h"
#include <iostream>
using namespace std;

void claseNieto::refinamiento()
{
	claseHijo::refinamiento();
	cout << "refinando clase Nieto" << endl;
	cout << " ======================== " << endl;
}
void claseNieto::reemplazo()
{
	cout << "reeeplazo clase Nieto" << endl;
	cout << " ======================== " << endl;
}