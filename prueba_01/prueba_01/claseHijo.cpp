#include "claseHijo.h"
#include "clasepadre.h"
#include <iostream>
using namespace std;

void claseHijo::refinamiento()
{
	clasepadre::refinamiento();
	cout << "refinando clase Hijo" << endl;
	cout << " ======================== " << endl;
}
void claseHijo::reemplazo()
{
	cout << "reeeplazo clase Hijo" << endl;
	cout << " ======================== " << endl;
}