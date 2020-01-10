#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
//Z URZYCIEM GAUSA
using namespace std;
double Transport(double randd);
double Zakwaterowanie(double randd);
double Food(double randd);
double Gauss(const double &mean, const double &std);

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
				transportFile << (int)Gauss(80, 0.6) << endl;
			else
				transportFile << (int)Gauss(100, 0.3) << endl;
		}
		else if (transportRand > 0.3 && transportRand <= 1.0) {
			//POCIAG DROGI CZY TANI 
			if (transportCosts <= 0.1) 
				transportFile << (int)Gauss(30, 0.3) << endl;
			else 
				transportFile << (int)Gauss(40, 0.7) << endl;
		}
	}//DALEKO
	else {
		if (transportRand <= 0.7) {
			//BENZYNA DROGA CZY TANIA 
			if (transportCosts <= 0.4)
				transportFile << (int)Gauss(130, 0.2) << endl;
			else
				transportFile << (int)Gauss(100, 0.8) << endl;
		}
		else {
			//POCIAG DROGI CZY TANI 
			if(transportCosts <= 0.2)
				transportFile << (int)Gauss(40, 0.1) << endl;
			else
				transportFile << (int)Gauss(60, 0.9) << endl;
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
			roomFile << (int)Gauss(90, 0.2) << endl;
		else
			roomFile << (int)Gauss(110, 0.8) << endl;
	}
	else if(randd > 0.1 && randd <=0.6){
		//POKOJ
		if (randRoom <= 0.3)
			roomFile << (int)Gauss(40, 0.4) << endl;
		else
			roomFile << (int)Gauss(80, 0.6) << endl;
	}
	else {
		//APARTAMENT
		if (randRoom <= 0.6)
			roomFile << (int)Gauss(150, 0.3) << endl;
		else
			roomFile << (int)Gauss(200, 0.7) << endl;
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
			foodFile << (int)Gauss(150, 0.1) << endl;
		else
			foodFile << (int)Gauss(80, 0.9) << endl;

	}//W POKOJU
	else {
		//TANIO CZY DROGO
		if(foodCosts <= 0.3)
			foodFile << (int)Gauss(50, 0.4) << endl;
		else
			foodFile << (int)Gauss(100, 0.6) << endl;
	}
	foodFile.close();
	return 0;

}

double Gauss(const double &mean, const double &std)
{
	static const double pii = 3.1415927;
	static const double r_max = RAND_MAX + 1;


	return std * sqrt(-2 * log((rand() + 1) / r_max))*sin(2 * pii*rand() / r_max) + mean;

}
