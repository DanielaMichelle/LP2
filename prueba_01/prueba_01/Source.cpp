#include "clasepadre.h"
#include "claseHijo.h"
#include "claseNieto.h"
#include <iostream>
using namespace std;

int main()
{
	cout << " CLASE PADRE" << endl;
	clasepadre Damian;
	Damian.reemplazo();
	Damian.refinamiento();

	cout << " CLASE HIJA" << endl;
	claseHijo Hil;
	Hil.reemplazo();
	Hil.refinamiento();

	cout << " CLASE NIETA" << endl;
	claseNieto niet;
	niet.reemplazo();
	niet.refinamiento();

	return 0;
}
