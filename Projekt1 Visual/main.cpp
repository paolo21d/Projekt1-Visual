#include <iostream>
#include <limits>
#include <vector>
#include "Bitowe.h"

using namespace std;

int main() {

	vector<Bitowe> lista;
	string wczytane, znak;
	int opcja, num1, num2;
	long long liczba;
	while (true) {
		cout << "MENU\tWybierz jeden z numerow:" << endl;
		cout << "1. Wprowadz liczbe w postaci dziesietnej" << endl;
		cout << "2. Wprowadz liczbe w postaci binarnej" << endl;
		cout << "3. Dodaj wprowadzone liczby" << endl;
		cout << "4. Odejmij wprowadzone liczby" << endl;
		cout << "5. Pomnoz wprowadzone liczby" << endl;
		cout << "6. Podziel wprowadzone liczby" << endl;
		cout << "7. Porownaj wprowadzone liczby" << endl;
		cout << "8. Wypisz wprowadzone liczby w postaci dziesietnej" << endl;
		cout << "9. Wypisz wprowadzone liczby w postaci binarnej" << endl;
		cout << "0. Zamknij" << endl;

		while (!(cin >> opcja)) {
			cout << "Blad podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (opcja == 1) { //wprowadzenie w postaci decymalnej
			lista.push_back(Bitowe());
			if (!lista.back().wczytajStringDecymalny())
				lista.pop_back();
		}
		else if (opcja == 2) { //wprowadzenie w postaci binarnej
			lista.push_back(Bitowe());
			if (!lista.back().wczytajStringBinarny())
				lista.pop_back();
		}
		else if (opcja == 3) { //dodanie
			cout << "Podaj numery liczb ktore chcesz dodac. ";
			while (!(cin >> num1 >> num2)) {
				cout << "Blad podaj jeszcze raz!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (num1 < 0 || num1 > lista.size() || num2 < 0 || num2 > lista.size()) {
				cout << "Bledne numery liczb!!" << endl;
				continue;
			}

			cout << "Dodawanie:" << endl;
			Bitowe suma = lista[num1] + lista[num2];
			lista[num1].wypiszBinarnie();
			cout << " + (";
			lista[num2].wypiszBinarnie();
			cout << ") = ";
			suma.wypiszBinarnie();
			cout << endl;
		}
		else if (opcja == 4) { //odjecie
			cout << "Podaj numery liczb ktore chcesz odjac. ";
			while (!(cin >> num1 >> num2)) {
				cout << "Blad podaj jeszcze raz!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (num1 < 0 || num1 > lista.size() || num2 < 0 || num2 > lista.size()) {
				cout << "Bledne numery liczb!!" << endl;
				continue;
			}
			cout << "Odejmowanie:" << endl;
			Bitowe suma = lista[num1] - lista[num2];
			lista[num1].wypiszBinarnie();
			cout << " - (";
			lista[num2].wypiszBinarnie();
			cout << ") = ";
			suma.wypiszBinarnie();
			cout << endl;
		}
		else if (opcja == 5) { //monozenie
			cout << "Podaj numery liczb ktore chcesz pomnozyc. ";
			while (!(cin >> num1 >> num2)) {
				cout << "Blad podaj jeszcze raz!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (num1 < 0 || num1 > lista.size() || num2 < 0 || num2 > lista.size()) {
				cout << "Bledne numery liczb!!" << endl;
				continue;
			}
			cout << "Mnozenie:" << endl;
			Bitowe iloczyn = lista[num1] * lista[num2];
			lista[num1].wypiszBinarnie();
			cout << " * (";
			lista[num2].wypiszBinarnie();
			cout << ") = ";
			iloczyn.wypiszBinarnie();
			cout << endl;
		}
		else if (opcja == 6) { //dzielenie
			cout << "Podaj numery liczb ktore chcesz podzielic. ";
			while (!(cin >> num1 >> num2)) {
				cout << "Blad podaj jeszcze raz!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (num1 < 0 || num1 > lista.size() || num2 < 0 || num2 > lista.size()) {
				cout << "Bledne numery liczb!!" << endl;
				continue;
			}
			cout << "Dzielenie:" << endl;
			Bitowe iloraz = lista[num1] / lista[num2];
			lista[num1].wypiszBinarnie();
			cout << " / (";
			lista[num2].wypiszBinarnie();
			cout << ") = ";
			iloraz.wypiszBinarnie();
			cout << endl;
		}
		else if (opcja == 7) { //porowananie
			cout << "Podaj numery liczb ktore chcesz porownac. ";
			while (!(cin >> num1 >> num2)) {
				cout << "Blad podaj jeszcze raz!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (num1 < 0 || num1 > lista.size() || num2 < 0 || num2 > lista.size()) {
				cout << "Bledne numery liczb!!" << endl;
				continue;
			}
			cout << "Porownanie liczb numer: " << num1 << " " << num2 << endl;
			lista[num1].wypiszBinarnie();
			if (lista[num1] > lista[num2])
				cout << " > ";
			else if (lista[num1] < lista[num2])
				cout << " < ";
			else
				cout << " = ";
			lista[num2].wypiszBinarnie();
			//Bitowe::porownajLiczby(lista[num1], lista[num2]);
			cout << endl;
		}
		else if (opcja == 8) { //wypisanie listy liczb decymalnie
			cout << "Lista liczb:" << endl;
			for (int i = 0; i < lista.size(); ++i) {
				cout << i << ": ";
				//lista[i].wypiszDecymalnie();
				cout << endl;
			}
		}
		else if (opcja == 9) { //wypisanie listy liczb binarnie
			cout << "Lista liczb:" << endl;
			for (int i = 0; i < lista.size(); ++i) {
				cout << i << ": ";
				lista[i].wypiszBinarnie();
				cout << endl;
			}
		}
		else if (opcja == 0) { //zamknij program
			//cout << lista.back().liczbaZnaczacych();
			break;
		}
		else { //blad wprowadzania
			cout << "Wprowadz poprawny numer opcji!!" << endl;
		}
	}


	// zamiana z stringa dziesietnego to na glupa dzielenie przez 2 tylko ze trzeba sobie samemu napisac dzielenie pisemne
	// kazda operacja arytmetyczna +-*/ ma byc napisana na bitach-pisemnie
	// rozmiar N to jest ilosc cyfr w dziesietnym, czyli przeliczyc ile max cyfr w dwojkowym bedzie c=chyba log2(wartosc_liczby_w_dziesietnej)+1 czyli tutaj pewnie n*log2(10) = ceil(3.4*n)+1
	return 0;
}
