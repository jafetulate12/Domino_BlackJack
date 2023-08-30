// Proyecto FINAL  Jafet blackjack.cpp : 
// Jafet Daniel Ulate Alvarez
// 30-11-2022
// Juego de cartas que consiste en obtener 21 puntos o llegar lo mas cercano a obtener 21 puntos, se le da 2 cartas a cada jugador a el inicio 
// el juego sera para 3 personas y cada ronda los jugadores decidiran si tomar o no carta y seguidamente se hara la comprobacion 
// El programa se creara en el lenguaje de c++

#include <iostream> // librerias del sistema
#include <string> // librerias del sistema
#include <vector> // librerias del sistema
#include <iomanip> // librerias del sistema
#include <algorithm> // librerias del sistema
#include <cstdlib> // librerias del sistema
#include <time.h> // librerias del sistema
using namespace std;
#include "Funciones.h"
// Funciones dadas por la libreria "Funciones.h"
// libreria de el menu
// libreria de la funcion encargada de sacar y colocar las cartas
// libreria con los numeros de la baraja
// libreria con las figuras de la baraja
// libreria para mejoras visuales


int main()
{
	system("color f0");
	vector<int>CartasEnUso;// las cartas que se estan usando en el proceso.
	vector<int>ManoJ1_Num;// mano de cartas en numeros del jugador 1.
	vector<string>ManoJ1_Fig;// mano de cartas en figuras del jugador 1.
	vector<int>ManoJ2_Num;// mano de cartas en numeros del jugador 2.
	vector<string>ManoJ2_Fig;// mano de cartas en figuras del jugador 2.
	vector<int>ManoJ3_Num;// mano de cartas en numeros del jugador 3.
	vector<string>ManoJ3_Fig;// mano de cartas en figuras del jugador 3.
	int PuntJuga1 = 0, PuntJuga2 = 0, PuntJuga3 = 0;// variables contadoras para los puntos de cada jugador.
	string respuestaj1 = "S";// variables de texto para las condiciones de if
	string respuestaj2 = "S";// variables de texto para las condiciones de if
	string respuestaj3 = "S";// variables de texto para las condiciones de if
	bool sal1 = false, sal2 = false, sal3 = false;
	string nombre1 = "", nombre2 = "", nombre3 = "";// variables que almacenan los nombres de los jugadores.
	int op = 0;// variable que recibe la opcion que nosretorna la funcion de menu


	op = menu();// invocamos a el menu  y nos retorna una opcion que ya esta en el rango de opciones corracta
	switch (op) {// en base a la opcion que elegimos hacemos la opccion del case 1 o case 2,
	case 1:// en el caso 1 ejecutamos el juego.
		reglas();// mostramos las reglas del juego con una funcion void
		cout << " Escriba el nombre del Jugador #1\n\t";// solicitamos nombre y lo guardamos en la variable
		cin.ignore();
		getline(cin, nombre1, '\n');
		cout << " Escriba el nombre del Jugador #2\n\t";// solicitamos nombre y lo guardamos en la variable
		getline(cin, nombre2, '\n');
		cout << " Escriba el nombre del Jugador #3\n\t";// solicitamos nombre y lo guardamos en la variable
		getline(cin, nombre3);
		cout << "                                                     ESPERO QUE DISFRUTEN DEL JUEGO\n";
		cout << endl;
		disenos();// mostramos diseños de las cartas del naipe;
		cout << "\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		system("cls");

		cout << "                                                             Empecemos a jugar\n";
		cout << endl;
		system("pause");
		system("color f0");
		cout << " TURNO DEL JUGADOR #1-->      " << "\t" << nombre1;// Mostramos el noombre del jugador en turno
		cout << endl;
		cout << endl;
		for (int i = 0; i < 2; i++) {// hacemos un ciclo que se repite dos veces para dar dos cartas a el jugador
			CartasEnUso.push_back(Repartir(CartasEnUso));// retorna un valor aleatorio y revisa que no este repetido
			ManoJ1_Num.push_back(MazoNum(CartasEnUso.back()));// coloca al final del vector jugador numero el numero de indice que me arrojo el numero aleatorio
			ManoJ1_Fig.push_back(MazoFig(CartasEnUso.back()));// coloca al final del vector jugador numero el numero de indice que me arrojo el numero aleatorio
			PuntJuga1 += ManoJ1_Num.back();// sumamos los puntos de las cartas que se le dieron a el jugador
			cout << "\t\tTU MANO OBTUVO--->  \t\t" << "\t\t\t" << ManoJ1_Fig.back() << "\t\t\t" << "\n";// mostramos las cartas que se le dieron a el jugador
		}
		cout << "\t EN TU MANO TIENES UN PUNTAJE DE \t\t\t                " << PuntJuga1 << endl;// mostramos los puntos que suma el jugador
		if (PuntJuga1 < 21) {// corrobora si el jugador no acumula mas de 21
			cout << " Desea otra carta[S/N]?\n\t";
			cin >> respuestaj1;
			if (respuestaj1 == "S" || respuestaj1 == "s") {// valida que la respuesta sea si o no
				CartasEnUso.push_back(Repartir(CartasEnUso));// retorna un valor aleatorio y revisa que no este repetido
				ManoJ1_Num.push_back(MazoNum(CartasEnUso.back()));// coloca al final del vector jugador numero el numero de indice que me arrojo el numero aleatorio
				ManoJ1_Fig.push_back(MazoFig(CartasEnUso.back()));// coloca al final del vector jugador numero el numero de indice que me arrojo el numero aleatorio
				PuntJuga1 += ManoJ1_Num.back();// sumammos los puntos de los jugadores
				cout << "LA CARTA--->  " << ManoJ1_Fig.back() << "\n";// mustra la  nueva carta que se le dio a el jugador
				cout << "\t EN TU MANO TIENES UN PUNTAJE DE \t\t\t                " << PuntJuga1 << "\n";
				system("pause");
			}
		}
		cout << "_________________________________________________________________" << "\n"; cout << " TURNO DEL JUGADOR #2-->      " << "\t" << nombre2;// Mostramos el noombre del jugador en turno
		cout << endl;
	case 2:
		//****** 2
		for (int i = 0; i < 2; i++) {// hacemos un ciclo que se repite dos veces para dar dos cartas a el jugador
			CartasEnUso.push_back(Repartir(CartasEnUso));
			ManoJ2_Num.push_back(MazoNum(CartasEnUso.back()));
			ManoJ2_Fig.push_back(MazoFig(CartasEnUso.back()));
			PuntJuga2 += ManoJ2_Num.back();// sumamos los puntos de las cartas que se le dieron a el jugador
			cout << "\t\tTU MANO OBTUVO--->  \t\t" << "\t\t\t" << ManoJ2_Fig.back() << "\t\t\t" << "\n";// mostramos las cartas del jugador
		}
		cout << "\t EN TU MANO TIENES UN PUNTAJE DE \t\t\t                " << PuntJuga2 << endl;
		if (PuntJuga2 < 21) {
			cout << " Desea otra carta[S/N]?\n\t";
			cin >> respuestaj2;
			if (respuestaj2 == "S" || respuestaj2 == "s") {
				cout << "\n";
				CartasEnUso.push_back(Repartir(CartasEnUso));
				ManoJ2_Num.push_back(MazoNum(CartasEnUso.back()));
				ManoJ2_Fig.push_back(MazoFig(CartasEnUso.back()));
				PuntJuga2 += ManoJ2_Num.back();
				cout << "LA CARTA--->  " << ManoJ2_Fig.back() << "\n\n";// mostramos la nueva carta
				cout << "\t EN TU MANO TIENES UN PUNTAJE DE \t\t\t                " << PuntJuga2 << "\n";// muestra el nuevo puntaje
				system("pause");
			}
		}
	 case 3:
		//****3
			cout << "_________________________________________________________________" << "\n" << " TURNO DEL JUGADOR #3-->      " << "\t" << nombre3;// Mostramos el noombre del jugador en turno
			for (int i = 0; i < 2; i++) {// hacemos un ciclo que se repite dos veces para dar dos cartas a el jugador
				CartasEnUso.push_back(Repartir(CartasEnUso));
				ManoJ3_Num.push_back(MazoNum(CartasEnUso.back()));
				ManoJ3_Fig.push_back(MazoFig(CartasEnUso.back()));
				PuntJuga3 += ManoJ3_Num.back();// sumamos los puntos de las cartas que se le dieron a el jugador
				cout << "\t\tTU MANO OBTUVO---->  \t\t" << "\t" << ManoJ3_Fig.back() << "\t\t" << "\n";
			}
			cout << "\t EN TU MANO TIENES UN PUNTAJE DE \t\t\t                " << PuntJuga3 << endl;
			if (PuntJuga3 < 21) {
				cout << " Desea otra carta[S/N]?\n\t";
				cin >> respuestaj3;
				if (respuestaj3 == "S" || respuestaj3 == "s") {
					CartasEnUso.push_back(Repartir(CartasEnUso));
					ManoJ3_Num.push_back(MazoNum(CartasEnUso.back()));
					ManoJ3_Fig.push_back(MazoFig(CartasEnUso.back()));
					PuntJuga3 += ManoJ3_Num.back();
					cout << "LA CARTA--->   " << ManoJ3_Fig.back() << "\n\n";
					cout << "\t EN TU MANO TIENES UN PUNTAJE DE \t\t\t                " << PuntJuga3 << "\n";
					cout << "_________________________________________________________________\n";
					comprobaciongane(PuntJuga1, PuntJuga2, PuntJuga3, nombre1, nombre2, nombre3);
				}
				else if (respuestaj3 == "N" || respuestaj3 == "n"); {
					comprobaciongane(PuntJuga1, PuntJuga2, PuntJuga3, nombre1, nombre2, nombre3);
				}
				
				system("pause");
			}
			if (PuntJuga1 == 21) {// hacemos las condiciones correspondientes para validar el ganador
				cout << "EL GANADOR ES --->   " << nombre1 << endl;
	

			}
			else if (PuntJuga2 == 21) {
				cout << "EL GANADOR ES --->    " << nombre2 << endl;
				
			}
			else if (PuntJuga3 == 21) {
				cout << "EL GANADOR ES --->    " << nombre3 << endl;
				

			}
			else if (PuntJuga1 > PuntJuga2 && PuntJuga1 > PuntJuga3 && PuntJuga1 < 21) {// validaciones de gane entre jugadores y que no se pasen de 21
				cout << " El ganador es --->    " << nombre1 << endl;
		

			}
			else if (PuntJuga2 > PuntJuga1 && PuntJuga2 > PuntJuga3 && PuntJuga2 < 21) {// validaciones de gane entre jugadores y que no se pasen de 2
				cout << " El ganador es --->    " << nombre2 << endl;
				

			}
			else if (PuntJuga3 > PuntJuga2 && PuntJuga3 > PuntJuga1 && PuntJuga3 < 21) {// validaciones de gane entre jugadores y que no se pasen de 2
				cout << " El ganador es --->   " << nombre3 << endl;
				

			}
			else if (PuntJuga1 == PuntJuga2) {
				cout << "EMPATE--> " << nombre1 << " Y    " << nombre2 << endl;
				
			}
			else if (PuntJuga1 == PuntJuga3) {
				cout << "EMPATE--> " << nombre1 << " Y    " << nombre3 << endl;
				
			}
			else if (PuntJuga2 == PuntJuga3) {
				cout << "EMPATE--> " << nombre2 << " Y    " << nombre3 << endl;
				
			}
			else if (PuntJuga2 == PuntJuga1) {
				cout << "EMPATE--> " << nombre2 << " Y    " << nombre1 << endl;
				
			}
			else if (PuntJuga3 == PuntJuga2) {
				cout << "EMPATE--> " << nombre3 << " Y    " << nombre2 << endl;
				
			}
			else if (PuntJuga3 == PuntJuga1) {
				cout << "EMPATE--> " << nombre3 << " Y    " << nombre1 << endl;
				
			}

		system("color f0");
		final();
		break;
	}
}
