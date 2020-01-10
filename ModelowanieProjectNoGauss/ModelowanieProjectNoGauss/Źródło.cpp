#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
//Z URZYCIEM GAUSA
using namespace std;
double Transport(double randd);
double Zakwaterowanie(double randd);
double Food(double randd);
double Randomizer(int val1, int val2);

int main() {

	for (int i = 0;i < 2000;i++) {
		double randd = rand() / (float)RAND_MAX;
		Transport(randd);
		Zakwaterowanie(randd);
		Food(randd);
	}
	system("pause");
}


//TRANSPORT
double Transport(double randd) {
	fstream transportFile;
	transportFile.open("transport.txt", ios::out | ios::app);
	double transportRand = rand() / (float)RAND_MAX;
	double transportCosts = rand() / (float)RAND_MAX;
	double koszt = 0.0;
	//BLISKO
	if (randd <= 0.3) {

		//SAMOCHOD CZY POCIAG
		if (transportRand <= 0.3) {
			//BENZYNA DROGA CZY TANIA
			if (transportCosts <= 0.3)
				transportFile << (int)Randomizer(80, 90) << endl;
			else
				transportFile << (int)Randomizer(100, 120) << endl;
		}
		else if (transportRand > 0.3 && transportRand <= 1.0) {
			//POCIAG DROGI CZY TANI 
			if (transportCosts <= 0.1)
				transportFile << (int)Randomizer(30, 20) << endl;
			else
				transportFile << (int)Randomizer(40, 50) << endl;
		}
	}//DALEKO
	else {
		if (transportRand <= 0.7) {
			//BENZYNA DROGA CZY TANIA 
			if (transportCosts <= 0.4)
				transportFile << (int)Randomizer(130,150) << endl;
			else
				transportFile << (int)Randomizer(100, 120) << endl;
		}
		else {
			//POCIAG DROGI CZY TANI 
			if (transportCosts <= 0.2)
				transportFile << (int)Randomizer(40, 50) << endl;
			else
				transportFile << (int)Randomizer(60, 70) << endl;
		}
	}
	transportFile.close();
	return 0;
}


//ZAKWATEROWANIE
double Zakwaterowanie(double randd) {
	fstream roomFile;
	roomFile.open("apartaments.txt", ios::out | ios::app);

	double randRoom = rand() / (float)RAND_MAX;

	if (randd <= 0.1)
	{
		//HOTEL
		if (randRoom <= 0.3)
			roomFile << (int)Randomizer(90, 100) << endl;
		else
			roomFile << (int)Randomizer(110, 130) << endl;
	}
	else if (randd > 0.1 && randd <= 0.6) {
		//POKOJ
		if (randRoom <= 0.3)
			roomFile << (int)Randomizer(40, 60) << endl;
		else
			roomFile << (int)Randomizer(80, 100) << endl;
	}
	else {
		//APARTAMENT
		if (randRoom <= 0.6)
			roomFile << (int)Randomizer(150, 180) << endl;
		else
			roomFile << (int)Randomizer(200, 230) << endl;
	}
	roomFile.close();
	return 0;
}


//JEDZENIE
double Food(double randd) {
	fstream foodFile;
	foodFile.open("food.txt", ios::out | ios::app);
	double foodCosts = rand() / (float)RAND_MAX;

	if (randd <= 0.4)
	{
		//RESTAURACJA DROGA CZY TANIA 
		if (foodCosts <= 0.3)
			foodFile << (int)Randomizer(150, 170) << endl;
		else
			foodFile << (int)Randomizer(80, 100) << endl;

	}//W POKOJU
	else {
		//TANIO CZY DROGO
		if (foodCosts <= 0.3)
			foodFile << (int)Randomizer(50, 80) << endl;
		else
			foodFile << (int)Randomizer(100, 130) << endl;
	}
	foodFile.close();
	return 0;

}

double Randomizer(int val1, int val2) {
	return val1 + int((val2 - val1 + 1)* rand() / RAND_MAX + 1.0);
}