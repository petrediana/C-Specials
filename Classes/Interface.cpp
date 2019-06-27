#include "pch.h"
#include <iostream>
#include <string>

class Persoana {
protected:
	std::string nume;

public:
	virtual void info() = 0;
	virtual ~Persoana() {
		std::cout << "Destroyed -> Person\n";
	}

};

class Copil : public Persoana {
private:
	int varsta;
public:
	Copil() {
		this->varsta = 0;
		this->nume = "Anonim";
	}

	Copil(int v, std::string n) :varsta(v) {
		this->nume = n;
	}

	void info() {
		std::cout << "\nSunt un copil\nNume: " << this->nume << ", varsta: " << this->varsta;
	}

	~Copil() {
		std::cout << "Destroyed -> Child\n";
	}	
};


int main() {

	Persoana *p1 = new Copil();
	p1->info();

	Persoana *p2 = new Copil(10, "NumeCopil");
	p2->info();

	free(p2);
	free(p1);

	return 0;
}