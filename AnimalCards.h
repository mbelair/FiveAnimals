//
// Authors:
// Alexandre D'Aoust - 7206757
// Maxime B�lair - 7432263 
// CSI2772 Project
//

#ifndef ANIMALCARDS_H
#define ANIMALCARDS_H

#include <iostream>

using namespace std;

#include <time.h>
#include <random>

enum class Animal { BEAR, DEER, HARE, MOOSE, WOLF, JOKER, START };
enum class Orientation { UP, DOWN };
enum class EvenOdd { EVEN, ODD };

string getAnimalString(const Animal animal);
char getAnimalChar(const Animal animal);
Animal getAnimal(string animal);
Animal getAnimal(char animal);

class AnimalCard {

protected:

	Orientation _orientation;
	EvenOdd _evenOdd;
	Animal _animals[2][2];

	AnimalCard(Animal a0, Animal a1, Animal a2, Animal a3) {
		_animals[0][0] = a0;
		_animals[0][1] = a1;
		_animals[1][0] = a2;
		_animals[1][1] = a3;
	}

public:
    
	virtual void setOrientation(Orientation o) { _orientation = o; };
	//virtual void setRow(EvenOdd eo) { _evenOdd = eo; }; Pas besoin, il y a le parametre directement dans printRow
	virtual void printRow(EvenOdd);
	virtual Animal getAnimal(int i, int j) {
		if (_orientation == Orientation::UP) return _animals[i][j];
		else return _animals[i == 0 ? 1 : 0][j == 0 ? 1 : 0];
	};

};


class NoSplit : public AnimalCard {
public: NoSplit(Animal a0) : AnimalCard(a0, a0, a0, a0) {}
};

class SplitTwo : public AnimalCard {
public: SplitTwo(Animal a0, Animal a1, bool sideways) : AnimalCard(a0, (sideways) ? a0 : a1, (sideways) ? a1 : a0, a1) {}
};

class SplitThree : public AnimalCard {
public:
	// Places the animals according to the given direction (0..3).
	// a0 is always the animal with two representations.
	SplitThree(Animal a0, Animal a1, Animal a2, int dir) :
    AnimalCard(
        (dir == 0 || dir == 3) ? a0 : a1,
        (dir == 0 || dir == 1) ? a0 : ((dir == 2) ? a2 : a1),
        (dir == 2 || dir == 3) ? a0 : ((dir == 0) ? a1 : a2),
        (dir == 1 || dir == 2) ? a0 : a2
    ) {}
};

class SplitFour : public AnimalCard {
public: SplitFour(Animal a0, Animal a1, Animal a2, Animal a3) : AnimalCard(a0, a1, a2, a3) {}
};

class Joker : public NoSplit {
public: Joker() : NoSplit(Animal::JOKER) {}
};

class StartCard : public NoSplit {
public: StartCard() : NoSplit(Animal::START) {}
};

#endif