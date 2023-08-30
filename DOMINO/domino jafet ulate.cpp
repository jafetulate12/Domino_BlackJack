// Proyecto FINAL  Jafet domino.cpp : 
// Jafet Daniel Ulate Alvarez
// 9-11-2022
// El juego consiste en acabar primero las fichas y si ya nadie puede poner el que tenga menos fichas gana
// El programa se creara en el lenguaje de c++

#include <iostream>// librerias del sistema
#include <string>// librerias del sistema
#include<vector>// librerias del sistema
#include<iomanip>// librerias del sistema
#include<algorithm>// librerias del sistema
#include<cstdlib>// librerias del sistema
#include<time.h>// librerias del sistema
using namespace std;
#include"funcionesr.h"


int main()
{
	system("color f0");
	vector<int>CartasEnUso;// vector para repartir y verificar que no esten repetidas las fichas4
	// jugador 1
	vector<int>ManoJ1_FICHAIZQUIERDA;
	vector<int>ManoJ1_FICHADERECHA;
	// jugador 2
	vector<int>ManoJ2_FICHAIZQUIERDA;
	vector<int>ManoJ2_FICHADERECHA;
	//jugador 3
	vector<int>ManoJ3_FICHAIZQUIERDA;
	vector<int>ManoJ3_FICHADERECHA;
	// jugador 4
	vector<int>ManoJ4_FICHAIZQUIERDA;
	vector<int>ManoJ4_FICHADERECHA;
	// Meza de Juego
	vector<int>MEZAIZQUIERDA;
	vector<int>MEZADERECHA;
	int sumaj1=0, sumaj2=0, sumaj3=0, sumaj4=0;
	bool ganador;
	ganador = false;
	int RESPUESTA;//variable que controla puntaje
	int salida = 0;
	string respuestaj1, respuestaj2, respuestaj3, respuestaj4;// recibe las respuesta de si o no
	string nombre1 = "", nombre2 = "", nombre3 = "", nombre4 = "";// variables que almacenan los nombres de los jugadores.
	int op = 0;// variable que recibe la opcion que nosretorna la funcion de menu
	int opj1, opj2, opj3, opj4;// lee la opcion en el swthich de elejir ficha
	int i = 0;
	int t = 1;// variable que se usa para asisgnar el numero de ficha
	menu();
	reglas();
	cout << " Escriba el nombre del Jugador #1\n\t";// solicitamos nombre y lo guardamos en la variable
	getline(cin, nombre1, '\n');
	cout << " Escriba el nombre del Jugador #2\n\t";// solicitamos nombre y lo guardamos en la variable
	getline(cin, nombre2, '\n');
	cout << " Escriba el nombre del Jugador #3\n\t";// solicitamos nombre y lo guardamos en la variable
	getline(cin, nombre3, '\n');
	cout << " Escriba el nombre del Jugador #4\n\t";// solicitamos nombre y lo guardamos en la variable
	getline(cin, nombre4, '\n');

	// se le a el valor 6|6 a la mesa
	MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), 6);
	MEZADERECHA.insert(MEZADERECHA.begin(), 6);
	system("pause");
	system("cls");
	cout << " LAS FICHAS DEL JUGADOR #1-->      " << "\t" << nombre1;// Mostramos el noombre del jugador en turno
	cout << endl;
	asignarfichas(CartasEnUso, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA, nombre1);
	cout << "\n\n";
	//************************
	cout << " LAS FICHAS DEL JUGADOR #2-->      " << "\t" << nombre2;// Mostramos el noombre del jugador en turno
	cout << endl;
	asignarfichas(CartasEnUso, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA, nombre2);
	cout << "\n\n";
	//****************

	cout << "LAS FICHAS DEL JUGADOR #3-->      " << "\t" << nombre3;// Mostramos el noombre del jugador en turno
	cout << endl;
	asignarfichas(CartasEnUso, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA, nombre3);
	cout << "\n\n";

	//***********
	// repartimos las fichas del jugador 4 que son 6 por que la meza ya tiene una ficha y por defecto el jugador 4 tendra 6 fichas
	cout << " LAS FICHAS DEL JUGADOR #4-->      " << "\t" << nombre4;// Mostramos el noombre del jugador en turno
	cout << endl;
	for (int i = 0; i < 6; i++) {// hacemos un ciclo que se repite 6 veces para dar las fichas a el jugador
		CartasEnUso.push_back(Repartir(CartasEnUso));
		ManoJ4_FICHAIZQUIERDA.push_back(fichaisquierda(CartasEnUso.back()));
		ManoJ4_FICHADERECHA.push_back(fichasderecha(CartasEnUso.back()));
		cout << "\t" << "[" << ManoJ4_FICHAIZQUIERDA.back() << "|" << ManoJ4_FICHADERECHA.back() << "]  ";// mostramos las fichas que se le dieron a el jugador
	}
	cout << "\n\n";
	system("pause");
	system("cls");
	do
	{
		do
		{
			// jugador 1 ************************************************************************************************
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			cout << endl;
			cout << " TURNO DEL JUGADOR #1-->      " << "\t" << nombre1 << "\n";// Mostramos el noombre del jugador en turno
			MOSTRARFICHA(ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
			cout << endl;
			cout << "Desea colocar una ficha?  s/n \n";
			cin >> respuestaj1;
			if (respuestaj1 == "s") {// en este if seleccionamos la ficha que queremos colocar
				cout << "Cual ficha deseas colocar?\n\t";
				cin >> opj1;
				if (opj1 == 1) {
					colocarficha1(MEZAIZQUIERDA, MEZADERECHA, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
				}
				else if (opj1 == 2) {
					colocarficha2(MEZAIZQUIERDA, MEZADERECHA, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
				}
				else if (opj1 == 3) {
					colocarficha3(MEZAIZQUIERDA, MEZADERECHA, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
				}
				else if (opj1 == 4) {
					colocarficha4(MEZAIZQUIERDA, MEZADERECHA, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
				}
				else if (opj1 == 5) {
					colocarficha5(MEZAIZQUIERDA, MEZADERECHA, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
				}
				else if (opj1 == 6) {
					colocarficha6(MEZAIZQUIERDA, MEZADERECHA, ManoJ1_FICHAIZQUIERDA, ManoJ1_FICHADERECHA);
				}
			}
			t = 1;
			cout << endl;
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			system("pause");
			system("cls");
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			cout << endl;
			// jugador 2***********************************************************************************
			cout << " TURNO DEL JUGADOR #2-->      " << "\t" << nombre2 << "\n";// Mostramos el noombre del jugador en turno
			MOSTRARFICHA(ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
			cout << "Desea colocar una ficha?  s/n \n";
			cin >> respuestaj2;
			if (respuestaj2 == "s") {
				cout << "Cual ficha deseas colocar?\n\t";
				cin >> opj2;
				if (opj2 == 1) {
					colocarficha1(MEZAIZQUIERDA, MEZADERECHA, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
				}
				else if (opj2 == 2) {
					colocarficha2(MEZAIZQUIERDA, MEZADERECHA, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
				}
				else if (opj2 == 3) {
					colocarficha3(MEZAIZQUIERDA, MEZADERECHA, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
				}
				else if (opj2 == 4) {
					colocarficha4(MEZAIZQUIERDA, MEZADERECHA, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
				}
				else if (opj2 == 5) {
					colocarficha5(MEZAIZQUIERDA, MEZADERECHA, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
				}
				else if (opj2 == 6) {
					colocarficha6(MEZAIZQUIERDA, MEZADERECHA, ManoJ2_FICHAIZQUIERDA, ManoJ2_FICHADERECHA);
				}
			}
			t = 1;
			cout << endl;
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			system("pause");
			system("cls");
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			cout << endl;
			// jugador 3******************************
			cout << " TURNO DEL JUGADOR #3-->      " << "\t" << nombre3 << "\n";// Mostramos el noombre del jugador en turno
			MOSTRARFICHA(ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
			cout << "Desea colocar una ficha?  s/n \n";
			cin >> respuestaj3;
			if (respuestaj3 == "s") {
				cout << "Cual ficha deseas colocar?\n\t";
				cin >> opj3;
				if (opj3 == 1) {
					colocarficha1(MEZAIZQUIERDA, MEZADERECHA, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
				}
				else if (opj3 == 2) {
					colocarficha2(MEZAIZQUIERDA, MEZADERECHA, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
				}
				else if (opj3 == 3) {
					colocarficha3(MEZAIZQUIERDA, MEZADERECHA, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
				}
				else if (opj3 == 4) {
					colocarficha4(MEZAIZQUIERDA, MEZADERECHA, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
				}
				else if (opj3 == 5) {
					colocarficha5(MEZAIZQUIERDA, MEZADERECHA, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
				}
				else if (opj3 == 6) {
					colocarficha6(MEZAIZQUIERDA, MEZADERECHA, ManoJ3_FICHAIZQUIERDA, ManoJ3_FICHADERECHA);
				}
			}
			t = 1;
			cout << endl;
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			system("pause");
			system("cls");
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			cout << endl;
			// jugador 4 ************************************************************************************************
			cout << " TURNO DEL JUGADOR #4-->      " << "\t" << nombre4 << "\n";// Mostramos el noombre del jugador en turno
			MOSTRARFICHA(ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
			cout << "Desea colocar una ficha?  s/n \n";
			cin >> respuestaj4;
			if (respuestaj4 == "s") {
				cout << "Cual ficha deseas colocar?\n\t";
				cin >> opj4;
				if (opj4 == 1) {
					colocarficha1(MEZAIZQUIERDA, MEZADERECHA, ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
				}
				else if (opj4 == 2) {
					colocarficha2(MEZAIZQUIERDA, MEZADERECHA, ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
				}
				else if (opj4 == 3) {
					colocarficha3(MEZAIZQUIERDA, MEZADERECHA, ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
				}
				else if (opj4 == 4) {
					colocarficha4(MEZAIZQUIERDA, MEZADERECHA, ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
				}
				else if (opj4 == 5) {
					colocarficha5(MEZAIZQUIERDA, MEZADERECHA, ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
				}
				else if (opj4 == 6) {
					colocarficha6(MEZAIZQUIERDA, MEZADERECHA, ManoJ4_FICHAIZQUIERDA, ManoJ4_FICHADERECHA);
				}
			}
			t = 1;
			cout << endl;
			Mostrarmeza(MEZAIZQUIERDA, MEZADERECHA);
			system("pause");
			system("cls");

			for (int i = 0; i < 7; i++) {
				sumaj1 += ManoJ1_FICHAIZQUIERDA[i];
			}
			for (int i = 0; i < 7; i++) {
				sumaj2 += ManoJ2_FICHAIZQUIERDA[i];
			}
			for (int i = 0; i < 7; i++) {
				sumaj3 += ManoJ3_FICHAIZQUIERDA[i];
			}
			for (int i = 0; i < 6; i++) {
				sumaj4 += ManoJ4_FICHAIZQUIERDA[i] + 8;
			}
			if (sumaj1 == 56) {
				cout << "GANO EL JUGADOR #1-->" << nombre1;
				RESPUESTA = 2;
				ganador = true;
			}
			else if (sumaj2 == 56) {
				cout << "GANO EL JUGADOR #2-->" << nombre2;
				RESPUESTA = 2;
				ganador = true;
			}
			else if (sumaj3 == 56) {
				cout << "GANO EL JUGADOR #3-->" << nombre3;
				RESPUESTA = 2;
				ganador = true;
			}
			else if (sumaj4 == 56) {
				cout << "GANO EL JUGADOR #4-->" << nombre4;
				RESPUESTA = 2;

				ganador = true;
			}
			else {
				RESPUESTA = 1;
				ganador = false;
			}
			// al final de la ronda s epregunta si se quiere seguir jugando 
			cout << "AUN TIENEN FICHAS?\n";
			cout << "\tSi respuesta es (1) el juego continuara\n\t";
			cout << "\tSi respuesta es (2) el juego terminara y ganara el jugador con menos fichas\n\t";
			cin >> RESPUESTA;

		} while (RESPUESTA!=2);
	} while (RESPUESTA !=2 );
	if (ManoJ1_FICHAIZQUIERDA.size() < ManoJ2_FICHAIZQUIERDA.size() && ManoJ1_FICHAIZQUIERDA.size() < ManoJ3_FICHAIZQUIERDA.size() && ManoJ1_FICHAIZQUIERDA.size() < ManoJ4_FICHAIZQUIERDA.size()) {
		cout << "EL GANADOR ES : " << nombre1 << "\t" << "con el menor numero de fichas\n";
	}
	else if (ManoJ2_FICHAIZQUIERDA.size() < ManoJ1_FICHAIZQUIERDA.size() && ManoJ2_FICHAIZQUIERDA.size() < ManoJ3_FICHAIZQUIERDA.size() && ManoJ2_FICHAIZQUIERDA.size() < ManoJ4_FICHAIZQUIERDA.size()) {
		cout << "EL GANADOR ES : " << nombre2<<"\t" << "con el menor numero de fichas\n";
	}
	else if (ManoJ3_FICHAIZQUIERDA.size() < ManoJ1_FICHAIZQUIERDA.size() && ManoJ3_FICHAIZQUIERDA.size() < ManoJ2_FICHAIZQUIERDA.size() && ManoJ3_FICHAIZQUIERDA.size() < ManoJ4_FICHAIZQUIERDA.size()) {
		cout << "EL GANADOR ES : " << nombre3 << "\t" << "con el menor numero de fichas\n";
	}
	else if (ManoJ4_FICHAIZQUIERDA.size() < ManoJ1_FICHAIZQUIERDA.size() && ManoJ4_FICHAIZQUIERDA.size() < ManoJ3_FICHAIZQUIERDA.size() && ManoJ4_FICHAIZQUIERDA.size() < ManoJ2_FICHAIZQUIERDA.size()) {
		cout << "EL GANADOR ES : " << nombre4 << "\t" << "con el menor numero de fichas\n";
	}
	final();
}
