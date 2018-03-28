//
// Created by paolo on 11.03.2018.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "Bitowe.h"

using namespace std;

Bitowe::Bitowe() {
	pole.reset();
	ujemna = false;
}

Bitowe::Bitowe(std::bitset<N> lista) {
	ujemna = 0;
	for (int i = 0; i < N; ++i) {
		pole[i] = lista[i];
	}
}

Bitowe::Bitowe(string var) {

}

Bitowe::Bitowe(long long liczba) {
	int i = 0;
	ujemna = false;
	if (liczba < 0) {
		liczba = -liczba;
		ujemna = true;
	}
	while (liczba != 0) {
		this->pole[i] = liczba % 2;
		liczba %= 2;
		i++;
	}
}

bool Bitowe::wczytajStringBinarny() {
	string s, znak;
	cout << "Podaj znak +/- a nastepnie po spacji liczbe w postaci binarnej." << endl;
	while (!(cin >> znak >> s)) {
		cout << "Blad podaj jeszcze raz!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (s.size()>N) {
		cout << "Overload!" << endl;
		return false;
	}
	if (znak == "-") {
		this->ujemna = true;
	}
	else if (znak == "+") {
		this->ujemna = false;
	}
	else {
		cout << "Blad wprowadzania danych!" << endl;
		return false;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0')
			this->pole[i] = false;
		else if (s[i] == '1')
			this->pole[i] = true;
		else {
			this->pole.reset();
			cout << "Blad wprowadzania danych!" << endl;
			return false;
		}
	}
	//sprawdzenie - 0
	if (this->modul() == Bitowe() && this->ujemna)
		this->ujemna = false;
	cout << "Poprawnie wprowadzono" << endl;
	return true;
}

bool Bitowe::wczytajStringDecymalny() {
	string s, znak;
	cout << "Podaj znak +/- a nastepnie po spacji liczbe w postaci dziesietnej." << endl;
	while (!(cin >> znak >> s)) {
		cout << "Blad podaj jeszcze raz!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return false;
}

Bitowe &Bitowe::operator=(const Bitowe &p) {
	this->ujemna = p.ujemna;
	for (int i = 0; i < N; i++)
		this->pole[i] = p.pole[i];
	return *this;
}

///////Porownywanie
bool operator>(const Bitowe &l, const Bitowe &p) {
	if (l.ujemna && !p.ujemna)
		return false;

	for (int i = N - 1; i >= 0; i--) {
		if (l.pole[i] == 1 && p.pole[i] == 0)
			return true;
		else if (l.pole[i] == 0 && p.pole[i] == 1)
			return false;
	}
	return false;
}
bool operator<(const Bitowe &l, const Bitowe &p) {
	if (!l.ujemna && p.ujemna)
		return false;
	for (int i = N - 1; i >= 0; i--) {
		if (l.pole[i] == 0 && p.pole[i] == 1)
			return true;
		else if (l.pole[i] == 1 && p.pole[i] == 0)
			return false;
	}
	return false;
}
bool operator==(const Bitowe &l, const Bitowe &p) {
	if (l.ujemna != p.ujemna)
		return false;
	for (int i = 0; i < N; i++) {
		if (l.pole[i] != p.pole[i])
			return false;
	}
	return true;
}

ostream &operator<<(ostream &out, const Bitowe &p) {
	if (p.ujemna)
		out << "- ";
	else
		out << "+ ";
	for (int i = N - 1; i >= 0; i--)
		out << p.pole[i];
	return out;
}
//////Operatory arytmetyczne
Bitowe operator+(const Bitowe &l, const Bitowe &p) {
	Bitowe tmp;
	if ((!l.ujemna && !p.ujemna) || (l.ujemna && p.ujemna)) {
		int c = 0;
		tmp.ujemna = l.ujemna;
		for (int i = 0; i < N; ++i) {
			tmp.pole[i] = (l.pole[i] + p.pole[i] + c) % 2;
			c = (l.pole[i] + p.pole[i] + c) / 2;
		}
		if (c > 0) {
			cout << "Overload!";
			return l;
		}
		return tmp;
	}
	else if (l.ujemna && !p.ujemna) {
		Bitowe lzast = l;
		lzast.ujemna = false;
		tmp = p - lzast;
		return tmp;
	}
	else if (!l.ujemna && p.ujemna) {
		Bitowe pzast = p;
		pzast.ujemna = false;
		tmp = l - pzast;
		return tmp;
	}

}

Bitowe operator-(const Bitowe &l, const Bitowe &p) {
	Bitowe tmp;
	int tab[N];
	//cout << "odejm" << endl;
	if ((!l.ujemna && !p.ujemna && l.modul() == p.modul()) || (l.ujemna && p.ujemna && l.modul() == p.modul()) || (l.modul() == p.modul() && l.modul() == tmp)) {
		return tmp;
	}else if ((!l.ujemna && !p.ujemna && l.modul() > p.modul()) || (l.ujemna && p.ujemna && l.modul() > p.modul())) {
		//cout << "++ ml>mp || -- ml>mp" << endl;
		tmp.ujemna = l.ujemna;
		int c = 0;
		for (int i = 0; i < N; ++i) {
			tab[i] = l.pole[i] - p.pole[i] + c;
			if (tab[i] < 0) {
				tab[i] += 2;
				c = -1;
			}
			else
				c = 0;
		}
		for (int i = 0; i < N; ++i) {
			tmp.pole[i] = tab[i];
		}
		return tmp;
	}
	else if (!l.ujemna && !p.ujemna && l.modul() < p.modul()) {
		//cout << "++, ml < mp" << endl;
		tmp = p - l;
		tmp.ujemna = true;
		return tmp;
	}
	else if (l.ujemna && p.ujemna && l.modul() < p.modul()) {
		//cout << "-- ml<mp" << endl;
		Bitowe pzast = p;
		pzast.ujemna = false;
		tmp = pzast + l;
		tmp.ujemna = false;
		return tmp;
	}
	else if (l.ujemna && !p.ujemna) {
		//cout << "-+" << endl;
		Bitowe lzast = l;
		lzast.ujemna = false;
		tmp = lzast + p;
		tmp.ujemna = true;
		return tmp;
	}
	else if (!l.ujemna && p.ujemna) {
		//cout << "+-" << endl;
		Bitowe pzast = p;
		pzast.ujemna = false;
		tmp = l + pzast;
		return tmp;
	}
}

Bitowe operator*(const Bitowe &l, const Bitowe &p) {
	Bitowe tmp;
	Bitowe lkopia = l.modul();
	if (l.liczbaZnaczacych() + p.liczbaZnaczacych() > N) {
		cout << "Overload!!" << endl;
		return	 tmp;
	}
	////////
	for (int i = 0; i < N; i++) {
		if (p.pole[i] == 0) {
			continue;
		}
		else {
			tmp = tmp + (lkopia<<i);
		}
	}

	if (l.ujemna != p.ujemna)
		tmp.ujemna = true;
	else
		tmp.ujemna = false;
	return tmp;
}

Bitowe operator/(const Bitowe &l, const Bitowe &p) {
	Bitowe tmp;
	vector <bool> tab;
	Bitowe dzielnik = p.modul();
	Bitowe dzielna = l.modul();
	if (dzielnik == tmp) {
		cout << "Nie mozna dzielic przez 0!!!!!" << endl;
		return tmp;
	}
	if (l.liczbaZnaczacych() < p.liczbaZnaczacych())
		return tmp;
	dzielnik = dzielnik << (dzielna.liczbaZnaczacych() - dzielnik.liczbaZnaczacych());
	while (true) {
		if (dzielna > dzielnik || dzielna == dzielnik) {
			tab.push_back(true);
			dzielna = dzielna - dzielnik;
			dzielnik = dzielnik >> 1;
		}
		else {
			tab.push_back(false);
			dzielnik = dzielnik >> 1;
		}

		if (dzielnik < p.modul())
			break;
	}
	reverse(tab.begin(), tab.end());
	for (int i = 0; i < tab.size(); i++) {
		tmp.pole[i] = tab[i];
	}
	/////////
	if (l.ujemna != p.ujemna)
		tmp.ujemna = true;
	else
		tmp.ujemna = false;
	return tmp;
}
void Bitowe::porownajLiczby(const Bitowe &l, const Bitowe &p) {
	/*if (l == p) {
	cout << "Liczby sa rowne" << endl;
	} else if (!l.ujemna && p.ujemna) {
	cout << "Pierwsza liczba jest wieksza od drugiaj" << endl;
	} else if (l.ujemna && !p.ujemna) {
	cout << "Pierwsza liczba jest mniejsza od drugiej" << endl;
	} else if (!l.ujemna && !p.ujemna && l < p) {
	cout << "Pierwsza liczba jest mniejsza od drugiej" << endl;
	} else if (!l.ujemna && !p.ujemna && l > p) {
	cout << "Pierwsza liczba jest wieksza od drugiej" << endl;
	} else if (l.ujemna && p.ujemna && l < p) {
	cout << "Pierwsza liczba jest wieksza od drugiej" << endl;
	} else if (l.ujemna && p.ujemna && l > p) {
	cout << "Pierwsza liczba jest mniejsza od drugiej" << endl;
	} else {
	cout << "Error!" << endl;
	}*/
	if (l == p) {
		cout << "Liczby sa rowne" << endl;
	}
	else if (l < p) {
		cout << "Pierwsza liczba jest mniejsza od drugiej" << endl;
	}
	else if (l > p) {
		cout << "Pierwsza liczba jest wieksza od drugiej" << endl;
	}
	else {
		cout << "Error!" << endl;
	}
}
void Bitowe::wypiszBinarnie() {
	if (this->ujemna)
		cout << "- ";
	else
		cout << "+ ";
	for (int i = N - 1; i >= 0; --i) {
		cout << this->pole[i];
	}
}
void Bitowe::wypiszDecymalnie() {

}
Bitowe Bitowe::modul() const {
	Bitowe tmp = *this;
	tmp.ujemna = false;
	return tmp;
}
int Bitowe::liczbaZnaczacych() const {
	int ilosc = 0;
	for (int i = N - 1; i >= 0; i--, ilosc++) {
		if (this->pole[i] == true)
			break;
	}
	return N - ilosc;
}


Bitowe operator<<(const Bitowe &l, int ilosc) {
	Bitowe tmp;
	for (int i = N - 1 - ilosc; i >= 0; i--) {
		tmp.pole[i + ilosc] = l.pole[i];
	}
	return tmp;
}
Bitowe operator>> (const Bitowe &l, int ilosc) {
	Bitowe tmp;
	for (int i = 0; i < N-ilosc; i++) {
		tmp.pole[i] = l.pole[i + ilosc];
	}
	return tmp;
}


/*istream &operator>>(istream &input, const Bitowe &p) {
string s;
input>>s;
for(int i=0; i<s.length(); i++) {
if(s[i]!=0 && s[i]!=1){
p.pole.reset();
return  input;
}
}
return  input;
}*/