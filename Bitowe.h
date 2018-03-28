//
// Created by paolo on 11.03.2018.
//

#ifndef PROI_P1_BITOWE_H
#define PROI_P1_BITOWE_H

#include <bitset>
#include <iostream>

#define N 10

class Bitowe {
private:
	std::bitset<N> pole;
	bool ujemna;
public:
	Bitowe();
	Bitowe(long long liczba);
	//Bitowe(std::string var);
	Bitowe(std::bitset<N> lista);

	//~Bitowe();
	bool wczytajStringBinarny();
	Bitowe &operator=(const Bitowe &p);

	static void porownajLiczby(const Bitowe &l, const Bitowe &p);
	void wypiszBinarnie();
	Bitowe modul() const;
	int liczbaZnaczacych() const;

	friend std::ostream &operator<<(std::ostream &out, const Bitowe &p);
	friend Bitowe operator+ (const Bitowe &l, const Bitowe &p);
	friend Bitowe operator- (const Bitowe &l, const Bitowe &p);
	friend Bitowe operator* (const Bitowe &l, const Bitowe &p);
	friend Bitowe operator/ (const Bitowe &l, const Bitowe &p);
	friend bool operator> (const Bitowe &l, const Bitowe &p);
	friend bool operator< (const Bitowe &l, const Bitowe &p);
	friend bool operator== (const Bitowe &l, const Bitowe &p);

	friend Bitowe operator<<(const Bitowe &l, int ilosc);
	friend Bitowe operator>>(const Bitowe &l, int ilosc);
	//friend std::istream &operator>>(std::istream &input, const Bitowe &p);
};


#endif //PROI_P1_BITOWE_H
