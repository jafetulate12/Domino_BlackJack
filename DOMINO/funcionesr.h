#pragma once
// Funcion de Ayudas visuales:********************************************************
void reglas() {
	system("cls");
	cout << "                                                        REGLAS\n ";
	cout << endl;
	cout << "  \t\t El juego consiste en colocar las fichas con las caras iguales\n";
	cout << "  \t\t Cuando usted desee colocar una ficha el sistema validara si la ficha tiene alguna cara que coincida con los extremos \n";
	cout << "  \t\t Y de manera automatica se asignara a la pocicion donde coincida\n";
	cout << "  \t\t El gane se dara de dos maneras\n";
	cout << "  \t\t 1- El primer jugador que se quede sin fichas\n";
	cout << "  \t\t 2- Si al final de la ronda los jugadores deciden terminar el juego, ganara el jugador con menor numero de fichas en su mano\n";
	cout << "  \t\t El juego sera para 4 Jugadores\n";
	cout << "  \t\t El juego inicia con la ficha [6|6] en la mesa\n";
	cout << endl;
	cout << endl;
	cout << endl;
	system("pause");
	system("cls");
}

// Funcion de Ayudas visuales:********************************************************
void final() {
	system("pause");
	system("cls");
	cout << "************\n";
	cout << "            \n";
	cout << "     ADIOS  \n";
	cout << "            \n";
	cout << "************\n";
	system("pause");
	system("cls");
}

// Funcion repartir: *************************************************************
int Repartir(vector<int>CartasEnUso) {
	srand(time(NULL));
	bool retornar;
	int retVal;
	int i = 0;
	do {
		retornar = true;
		retVal = (rand() % 27);

		if (CartasEnUso.size() != 0) {
			for (int i = 0; i < CartasEnUso.size(); ++i) {
				if (retVal == CartasEnUso.at(i)) {
					retornar = false;
				}
			}
		}
	} while (!retornar);
	return retVal;
}

// Funcion de Mazo numerico:********************************************************
int fichaisquierda(int x) {
	vector<int>baraja;
	//
	baraja.push_back(0);
	baraja.push_back(0);
	baraja.push_back(0);
	baraja.push_back(0);
	//
	baraja.push_back(0);
	baraja.push_back(0);
	baraja.push_back(0);
	baraja.push_back(1);
	//
	baraja.push_back(2);
	baraja.push_back(3);
	baraja.push_back(4);
	baraja.push_back(5);
	//
	baraja.push_back(6);
	baraja.push_back(2);
	baraja.push_back(3);
	baraja.push_back(4);
	//
	baraja.push_back(5);
	baraja.push_back(6);
	baraja.push_back(3);
	baraja.push_back(4);
	//
	baraja.push_back(5);
	baraja.push_back(6);
	baraja.push_back(4);
	baraja.push_back(5);
	//
	baraja.push_back(6);
	baraja.push_back(5);
	baraja.push_back(6);
	

	return baraja.at(x);
}

//Funcion de Menu:********************************************************************
void menu() {
	system("color f0");
	int op, opr = 0;
	cout << "       ***********************************\n";
	cout << "                     DOMINO \n";
	cout << "       ***********************************\n";
	system("color f0");           
	cout << "COMENZEMOS A JUGAR\n";
	cout << "\t****************" << endl << endl;
	system("pause");
	system("cls");
}

//Funcion de Mazo con el nombre de la carta y su figura:*****************************
int fichasderecha(int x) {
	vector<int>baraja;
	//
	baraja.push_back(0);
	baraja.push_back(1);
	baraja.push_back(2);
	baraja.push_back(3);
	//
	baraja.push_back(4);
	baraja.push_back(5);
	baraja.push_back(6);
	baraja.push_back(1);
	//
	baraja.push_back(1);
	baraja.push_back(1);
	baraja.push_back(1);
	baraja.push_back(1);
	//
	baraja.push_back(1);
	baraja.push_back(2);
	baraja.push_back(2);
	baraja.push_back(2);
	//
	baraja.push_back(2);
	baraja.push_back(2);
	baraja.push_back(3);
	baraja.push_back(3);
	//
	baraja.push_back(3);
	baraja.push_back(3);
	baraja.push_back(4);
	baraja.push_back(4);
	//
	baraja.push_back(4);
	baraja.push_back(5);
	baraja.push_back(5);

	return baraja.at(x);
}
// mostramos las fichas de los jugadores
void MOSTRARFICHA(vector<int>&ManoJ1_FICHAIZQUIERDA, vector<int>&ManoJ1_FICHADERECHA) {
	cout << "\t\tTUS FICHAS SON---> \n";
	int t = 1;
	for (int i = 0; i < ManoJ1_FICHAIZQUIERDA.size(); i++) {
		cout << t++ << "----->" << "[" << ManoJ1_FICHAIZQUIERDA[i] << "|" << ManoJ1_FICHADERECHA[i] << "]" << "\t\t\t" << "\n";
	}
}
// mostramos el valor de la meza actual
void Mostrarmeza(vector<int>&MEZAIZQUIERDA, vector<int>&MEZADERECHA) {
	cout << "\tMEZA ACTUAL\n";
	for (int i = 0; i < MEZAIZQUIERDA.size(); i++) {// hacemos un ciclo que se repite dos veces para dar dos cartas a el jugador
		cout << "[" << MEZAIZQUIERDA[i] << "|" << MEZADERECHA[i] << "]   ";// mostramos las cartas que se le dieron a el jugador
	}
}
// asignamos las fichas a los vectores de los jugadores
void asignarfichas(vector<int>&CartasEnUso,vector<int>&ManoJ1_FICHAIZQUIERDA, vector<int>&ManoJ1_FICHADERECHA, string nombre) {
	int t = 1;
	for (int i = 0; i < 7; i++) {// hacemos un ciclo que se repite dos veces para dar dos cartas a el jugador
		CartasEnUso.push_back(Repartir(CartasEnUso));
		ManoJ1_FICHAIZQUIERDA.push_back(fichaisquierda(CartasEnUso.back()));
		ManoJ1_FICHADERECHA.push_back(fichasderecha(CartasEnUso.back()));
		cout << "\t" << "[" << ManoJ1_FICHAIZQUIERDA.back() << "|" << ManoJ1_FICHADERECHA.back() << "]  ";// mostramos las cartas que se le dieron a el jugador
	}
}
//************
// igualamos a 8 la ficha luego de colocarla
void colocarficha1(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {
	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a 0 inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[0]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[0]);
		ManoJ_FICHAIZQUIERDA[0] = 8;
		ManoJ_FICHADERECHA[0] = 8;
	}
	else if (ManoJ_FICHAIZQUIERDA[0] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[0]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[0]);
		ManoJ_FICHAIZQUIERDA[0] = 8;
		ManoJ_FICHADERECHA[0] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[0] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[0]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[0]);
		ManoJ_FICHAIZQUIERDA[0] = 8;
		ManoJ_FICHADERECHA[0] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[0] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[0]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[0]);
		ManoJ_FICHAIZQUIERDA[0] = 8;
		ManoJ_FICHADERECHA[0] = 8;
		cout << "Su ficha se inserto al lado izquierdo\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[0] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[0]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[0]);
		ManoJ_FICHAIZQUIERDA[0] = 8;
		ManoJ_FICHADERECHA[0] = 8;
		cout << "Su ficha se inserto al lado izquierdo de manera inversa\n";
	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "\tSu ficha no se puede agregar a la mesa de ninguna mesa\n";
	}

}
void colocarficha2(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {
	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a 0 inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[1]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[1]);
		ManoJ_FICHAIZQUIERDA[1] = 8;
		ManoJ_FICHADERECHA[1] = 8;
	}
	else if (ManoJ_FICHAIZQUIERDA[1] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[1]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[1]);
		ManoJ_FICHAIZQUIERDA[1] = 8;
		ManoJ_FICHADERECHA[1] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[1] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[1]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[1]);
		ManoJ_FICHAIZQUIERDA[1] = 8;
		ManoJ_FICHADERECHA[1] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[1] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[1]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[1]);
		ManoJ_FICHAIZQUIERDA[1] = 8;
		ManoJ_FICHADERECHA[1] = 8;
		cout << "Su ficha se inserto al lado izquiero\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[1] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[1]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[1]);
		ManoJ_FICHAIZQUIERDA[1] = 8;
		ManoJ_FICHADERECHA[1] = 8;
		cout << "Su ficha se inserto al lado izquierdo a el lado inverso\n";
	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "\tSu ficha no se puede agregar a la mesa de ninguna mesa\n";

	}
}
void colocarficha3(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {
	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a o inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[2]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[2]);
		ManoJ_FICHAIZQUIERDA[2] = 8;
		ManoJ_FICHADERECHA[2] = 8;
	}
	else if (ManoJ_FICHAIZQUIERDA[2] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[2]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[2]);
		ManoJ_FICHAIZQUIERDA[2] = 8;
		ManoJ_FICHADERECHA[2] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[2] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[2]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[2]);
		ManoJ_FICHAIZQUIERDA[2] = 8;
		ManoJ_FICHADERECHA[2] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[2] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[2]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[2]);
		ManoJ_FICHAIZQUIERDA[2] = 8;
		ManoJ_FICHADERECHA[2] = 8;
		cout << "Su ficha se inserto al lado izquierdo\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[2] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[2]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[2]);
		ManoJ_FICHAIZQUIERDA[2] = 8;
		ManoJ_FICHADERECHA[2] = 8;
		cout << "Su ficha se inserto al lado izquierdo de manera inversa\n";
	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "\tSu ficha no se puede agregar a la mesa de ninguna mesa\n";
		
	}
}
void colocarficha4(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {
	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a o inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[3]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[3]);
		ManoJ_FICHAIZQUIERDA[3] = 8;
		ManoJ_FICHADERECHA[3] = 8;
	}
	else if (ManoJ_FICHAIZQUIERDA[3] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[3]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[3]);
		ManoJ_FICHAIZQUIERDA[3] = 8;
		ManoJ_FICHADERECHA[3] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[3] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[3]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[3]);
		ManoJ_FICHAIZQUIERDA[3] = 8;
		ManoJ_FICHADERECHA[3] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[3] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[3]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[3]);
		ManoJ_FICHAIZQUIERDA[3] = 8;
		ManoJ_FICHADERECHA[3] = 8;
		cout << "Su ficha se inserto al lado izquierdo\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[3] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[3]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[3]);
		ManoJ_FICHAIZQUIERDA[3] = 8;
		ManoJ_FICHADERECHA[3] = 8;
		cout << "Su ficha se inserto al lado izquierdo de manera inversa\n";
	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "Su ficha no se puede agregar a la mesa de ninguna mesa\n";
		
	}
	
}
void colocarficha5(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {
	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a o inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[4]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[4]);
		ManoJ_FICHAIZQUIERDA[4] = 8;
		ManoJ_FICHADERECHA[4] = 8;
	}
	else if (ManoJ_FICHAIZQUIERDA[4] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[4]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[4]);
		ManoJ_FICHAIZQUIERDA[4] = 8;
		ManoJ_FICHADERECHA[4] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[4] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[4]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[4]);
		ManoJ_FICHAIZQUIERDA[4] = 8;
		ManoJ_FICHADERECHA[4] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[4] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[4]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[4]);
		ManoJ_FICHAIZQUIERDA[4] = 8;
		ManoJ_FICHADERECHA[4] = 8;
		cout << "Su ficha se inserto al lado izquierdo\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[4] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[4]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[4]);
		ManoJ_FICHAIZQUIERDA[4] = 8;
		ManoJ_FICHADERECHA[4] = 8;
		cout << "Su ficha se inserto al lado izquierdo de manera inversa \n";
	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "\tSu ficha no se puede agregar a la mesa de ninguna mesa\n";
	}
}
void colocarficha6(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {

	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a o inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[5]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[5]);
		ManoJ_FICHAIZQUIERDA[5] = 8;
		ManoJ_FICHADERECHA[5] = 8;
	
	}
	else if (ManoJ_FICHAIZQUIERDA[5] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[5]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[5]);
		ManoJ_FICHAIZQUIERDA[5] = 8;
		ManoJ_FICHADERECHA[5] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[5] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[5]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[5]);
		ManoJ_FICHAIZQUIERDA[5] = 8;
		ManoJ_FICHADERECHA[5] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[5] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[5]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[5]);
		ManoJ_FICHAIZQUIERDA.erase(ManoJ_FICHAIZQUIERDA.begin() + 5);
		ManoJ_FICHADERECHA.erase(ManoJ_FICHADERECHA.begin() + 5);
		cout << "Su ficha se inserto al lado izquierdo\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[5] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[5]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[5]);
		ManoJ_FICHAIZQUIERDA[5] = 8;
		ManoJ_FICHADERECHA[5] = 8;
		cout << "Su ficha se inserto al lado izquierdo de manera inversa\n";

	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "\tSu ficha no se puede agregar a la mesa de ninguna mesa\n";
		
	}
}
void colocarficha7(vector<int>& MEZAIZQUIERDA, vector<int>& MEZADERECHA, vector<int>& ManoJ_FICHAIZQUIERDA, vector<int>& ManoJ_FICHADERECHA) {

	if (MEZAIZQUIERDA.size() && MEZADERECHA.size() == 0) {//si el tamaño de la mesa es igual a o inserta cualquier ficha
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[6]);
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[6]);
		ManoJ_FICHAIZQUIERDA[6] = 8;
		ManoJ_FICHADERECHA[6] = 8;
	
	}
	else if (ManoJ_FICHAIZQUIERDA[6] == MEZADERECHA.back()) {// si la ficha en el extremoizquierdo es igual a el xtremo derecho de la mesa
		MEZAIZQUIERDA.push_back(ManoJ_FICHAIZQUIERDA[6]);// inserta la ficha en el orden normal
		MEZADERECHA.push_back(ManoJ_FICHADERECHA[6]);
		ManoJ_FICHAIZQUIERDA[6] = 8;
		ManoJ_FICHADERECHA[6] = 8;
		cout << "Su ficha se inserto al lado derecho\n";
	}
	else if (ManoJ_FICHADERECHA[6] == MEZADERECHA.back()) {//si la ficha en el extremo derecho es igual a el extremo derecho d la mesa la inserta al revez
		MEZAIZQUIERDA.push_back(ManoJ_FICHADERECHA[6]);
		MEZADERECHA.push_back(ManoJ_FICHAIZQUIERDA[6]);
		ManoJ_FICHAIZQUIERDA[6] = 8;
		ManoJ_FICHADERECHA[6] = 8;
		cout << "Su ficha se inserto al lado derecho de manera inversa\n";
	}
	else if (ManoJ_FICHADERECHA[6] == MEZAIZQUIERDA.front()) {// si la ficha en el extremo izquierdo es igual al el principio de la mesa en el extremo derecho
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHAIZQUIERDA[6]);//la ingresa de primero
		MEZADERECHA.insert(ManoJ_FICHADERECHA.begin(), ManoJ_FICHADERECHA[6]);
		ManoJ_FICHAIZQUIERDA[6] = 8;
		ManoJ_FICHADERECHA[6] = 8;
		cout << "Su ficha se inserto al lado izquierdo\n";
	}
	else if (ManoJ_FICHAIZQUIERDA[6] == MEZAIZQUIERDA.front()) {//si la ficha en el extremo izquierdo es igual a el extremo izquierdo de la mesa la inserta al revez
		MEZAIZQUIERDA.insert(MEZAIZQUIERDA.begin(), ManoJ_FICHADERECHA[6]);
		MEZADERECHA.insert(MEZADERECHA.begin(), ManoJ_FICHAIZQUIERDA[6]);
		ManoJ_FICHAIZQUIERDA[6] = 8;
		ManoJ_FICHADERECHA[6] = 8;
		cout << "Su ficha se inserto al lado izquierdo de manera inversa\n";
	}
	else {
		cout << "Se hicieron todas las comprobaciones respectivas\t\n";
		cout << "\tSu ficha no se puede agregar a la mesa de ninguna mesa\n";
	
	}
}