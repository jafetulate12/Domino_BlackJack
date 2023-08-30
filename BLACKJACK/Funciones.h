#pragma once
// Funcion de Ayudas visuales:********************************************************
void disenos() {
	system("color f0");
	char corazones = 3;// ♥
	char diamantes = 4;//♦
	char treboles = 5;//♣
	char espadas = 6;//♠}
	for (int i = 0; i < 50; i++)
	{
		cout << "|" << corazones << "|" << treboles << "|" << espadas << "|" << diamantes << "|" << corazones << "|" << treboles << "|" << espadas << "|" << diamantes << "|" << corazones << "|" << treboles << "|" << espadas << "|" << diamantes << "|" << "\t\t\t";
	}

}

// Funcion de Ayudas visuales:********************************************************
void reglas() {
	system("cls");
	cout << "                                                        REGLAS\n ";
	cout << endl;
	cout << "  \t\t El juego consiste en alcanzar 21 puntos o lo mas cercano sin pasarse \n";
	cout << "  \t\t Las cartas J Q K equivalen a 10 puntos y el AS (A) equivale a 1 0 11 \n";
	cout << "  \t\t El valor del AS (A) va a ser asignado por el juego dependiendo la cantidad de puntos que tenga el jugador\n";
	cout << "  \t\t El juego sera para 3 Jugadores\n";
	cout << endl;
	cout << endl;
	cout << endl;
	system("pause");
	system("cls");
}

// Funcion de Ayudas visuales:********************************************************
void final() {
	system("pause");
	disenos();
	cout << "\n\n\n\n\n\n";
	system("pause");
	system("cls");
	cout << "************\n";
	cout << "   GRACIAS  \n";
	cout << "     POR    \n";
	cout << "    JUGAR   \n";
	cout << "************\n";
	system("pause");
	system("cls");
}

// Funcion repartir: *************************************************************
int Repartir(vector<int>CartasEnUso) {
	srand(time(NULL));// creamos la semilla
	bool retornar;
	int retVal;
	int i = 0;
	do {
		retornar = true;
		retVal = (rand() % 52);// igualamos la variable a el total del aleatorio

		if (CartasEnUso.size() != 0) {// si el tamaño del vector es diferente de 0
			for (int i = 0; i < CartasEnUso.size(); i++) {
				if (retVal == CartasEnUso.at(i)) {// si variable de aleatorio es igual a vector de cartas en uso
					retornar = false;             // en la posicion (i)
				}//retornar se vuelve falso
			}
		}
	} while (!retornar);
	return retVal;
}

// Funcion de Mazo numerico:********************************************************
int MazoNum(int x) {
	vector<int>baraja;
	//
	baraja.push_back(2);
	baraja.push_back(2);
	baraja.push_back(2);
	baraja.push_back(2);
	//
	baraja.push_back(3);
	baraja.push_back(3);
	baraja.push_back(3);
	baraja.push_back(3);
	//
	baraja.push_back(4);
	baraja.push_back(4);
	baraja.push_back(4);
	baraja.push_back(4);
	//
	baraja.push_back(5);
	baraja.push_back(5);
	baraja.push_back(5);
	baraja.push_back(5);
	//
	baraja.push_back(6);
	baraja.push_back(6);
	baraja.push_back(6);
	baraja.push_back(6);
	//
	baraja.push_back(7);
	baraja.push_back(7);
	baraja.push_back(7);
	baraja.push_back(7);
	//
	baraja.push_back(8);
	baraja.push_back(8);
	baraja.push_back(8);
	baraja.push_back(8);
	//
	baraja.push_back(9);
	baraja.push_back(9);
	baraja.push_back(9);
	baraja.push_back(9);
	//
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	//
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	//
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	//
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	baraja.push_back(10);
	//
	baraja.push_back(11);
	baraja.push_back(11);
	baraja.push_back(11);
	baraja.push_back(11);
	return baraja.at(x);// devuelve un elemento en una pocicion especifica del vector baraja
}

//Funcion de Menu:********************************************************************
int menu() {

	system("color f0");
	int op=1, opr = 0;
	string oo;
		cout << "       ***********************************\n";
		cout << "        Bienvenido al juego 21 Blackjack \n";
		cout << "       ***********************************\n";
		system("color f0");
		cout << "Empezar partida\n";
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "***************************************************************" << endl << endl;

		cout << " Digita cualquier tecla para comenzar --->\t   ";
		cin >> oo;
		return op;
}

//Funcion de Mazo con el nombre de la carta y su figura:*****************************
string MazoFig(int x) {
	vector<string>mano;// vector de las figuras
	char corazones = 3;// ♥
	char diamantes = 4;//♦
	char treboles = 5;//♣
	char espadas = 6;//♠}
	mano.push_back("2 ESPADAS");
	mano.push_back("2 CORAZONES");
	mano.push_back("2 DIAMANTES");
	mano.push_back("2 TREBOL");
	//
	mano.push_back("3 ESPADAS");
	mano.push_back("3 CORAZONES");
	mano.push_back("3 DIAMANTES");
	mano.push_back("3 TREBOL");
	//
	mano.push_back("4 ESPADAS");
	mano.push_back("4 CORAZONES");
	mano.push_back("4 DIAMANTES");
	mano.push_back("4 TREBOL");
	//
	mano.push_back("5 ESPADAS");
	mano.push_back("5 CORAZONES");
	mano.push_back("5 DIAMANTES");
	mano.push_back("5 TREBOL");
	//
	mano.push_back("6 ESPADAS");
	mano.push_back("6 CORAZONES");
	mano.push_back("6 DIAMANTES");
	mano.push_back("6 TREBOL");
	//
	mano.push_back("7 ESPADAS");
	mano.push_back("7 CORAZONES");
	mano.push_back("7 DIAMANTES");
	mano.push_back("7 TREBOL");
	//
	mano.push_back("8 ESPADAS");
	mano.push_back("8 CORAZONES");
	mano.push_back("8 DIAMANTES");
	mano.push_back("8 TREBOL");
	//
	mano.push_back("9 ESPADAS");
	mano.push_back("9 CORAZONES");
	mano.push_back("9 DIAMANTES");
	mano.push_back("9 TREBOL");
	//
	mano.push_back("10 ESPADAS");
	mano.push_back("10 CORAZONES");
	mano.push_back("10 DIAMANTES");
	mano.push_back("10 TREBOL");
	//
	mano.push_back("J ESPADAS");
	mano.push_back("J CORAZONES");
	mano.push_back("J DIAMANTES");
	mano.push_back("J TREBOL");
	//
	mano.push_back("Q ESPADAS");
	mano.push_back("Q CORAZONES");
	mano.push_back("Q DIAMANTES");
	mano.push_back("Q TREBOL");
	//
	mano.push_back("K ESPADAS");
	mano.push_back("K CORAZONES");
	mano.push_back("K DIAMANTES");
	mano.push_back("K TREBOL");
	//
	mano.push_back("A ESPADAS");
	mano.push_back("A CORAZONES");
	mano.push_back("A DIAMANTES");
	mano.push_back("A TREBOL");
	return mano.at(x);// devuelve un valor en la pocicion especifica del vector de numero nombre de carta
}
void comprobaciongane(int PuntJuga1, int PuntJuga2, int PuntJuga3,string nombre1,string nombre2,string nombre3) {

	if (PuntJuga1 == 21) {// hacemos las condiciones correspondientes para validar el ganador
		cout << "EL GANADOR ES --->   " << nombre1 << endl;
		final();
		
	}
	else if (PuntJuga2 == 21) {
		cout << "EL GANADOR ES --->    " << nombre2 << endl;
		final();
		
	}
	else if (PuntJuga3 == 21) {
		cout << "EL GANADOR ES --->    " << nombre3 << endl;
		final();
		
	}
	else if (PuntJuga1 > PuntJuga2 && PuntJuga1 > PuntJuga3 && PuntJuga1 < 21) {// validaciones de gane entre jugadores y que no se pasen de 21
		cout << " El ganador es --->    " << nombre1 << endl;
		final();
		
	}
	else if (PuntJuga2 > PuntJuga1 && PuntJuga2 > PuntJuga3 && PuntJuga2 < 21) {// validaciones de gane entre jugadores y que no se pasen de 2
		cout << " El ganador es --->    " << nombre2 << endl;
		final();
		
	}
	else if (PuntJuga3 > PuntJuga2 && PuntJuga3 > PuntJuga1 && PuntJuga3 < 21) {// validaciones de gane entre jugadores y que no se pasen de 2
		cout << " El ganador es --->   " << nombre3 << endl;
		final();
		
	}
	else if (PuntJuga1 == PuntJuga2) {
		cout << "EMPATE--> " << nombre1 << " Y    " << nombre2 << endl;
		final();
	}
	else if (PuntJuga1 == PuntJuga3) {
		cout << "EMPATE--> " << nombre1 << " Y    " << nombre3 << endl;
		final();
	}
	else if (PuntJuga2 == PuntJuga3) {
		cout << "EMPATE--> " << nombre2 << " Y    " << nombre3 << endl;
		final();
	}
	else if (PuntJuga2 == PuntJuga1) {
		cout << "EMPATE--> " << nombre2 << " Y    " << nombre1 << endl;
		final();
	}
	else if (PuntJuga3 == PuntJuga2) {
		cout << "EMPATE--> " << nombre3 << " Y    " << nombre2 << endl;
		final();
	}
	else if (PuntJuga3 == PuntJuga1) {
		cout << "EMPATE--> " << nombre3 << " Y    " << nombre1 << endl;
		final();
	}
	
}