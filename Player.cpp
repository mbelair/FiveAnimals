//
// Authors:
// Alexandre D'Aoust - 7206757
// Maxime B�lair - 7432263 
// CSI2772 Project
//

#include "Player.h"

//why return ?!?! dis is stupid
void Player::swapSecretAnimal(Animal& animal) {
	Animal temp = animal;
	animal = secretAnimal;
	secretAnimal = temp;
}

Animal Player::getSecretAnimal() {
	return secretAnimal;
}

void Player::print() {
	cout << "Player Name: " << playerName << endl;
    cout << "Secret Animal: " << AnimalCard::getAnimalString(secretAnimal) << endl;
    cout << "Hand: " << endl << endl;
    hand.print();
}