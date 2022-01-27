
#include <iostream>
using namespace std;

//namespace Ws2
namespace sdds
{

	struct Car* car = nullptr;
	car = new Car[allocSize];


	//const int allocationSize = 2; // an integer to hold the memory allocation and expansion size when needed
	int allocationSize = 2; // an integer to hold the memory allocation and expansion size when needed
	int numCars; // an integer to hold the number of cars currently in the dynamic array of cars pointed by The Car Pointer
	int carArrSize; //  an integer to hold the current allocation size of the array. This value is the maximum size that the Number Of Cars can grow up to (before reallocation for expansion).

	void VBPLE_Title()
	{
		cout << "Vehicle Border Passing Log Entry\n" 
			<< "Enter the data in the following format:\n"
			<< "Make and model,LicensePlate,MilitaryTime<ENTER>\n"
			<< "Exit the program by entering the following:\n"
			<< "X,<ENTER>"
			<< endl;
	}

	void initialize(int allocSize)
	{
		//struct Car car[const allocSize];
		//allocSize = ((const) allocSize;
		//Car = new car[allocSize];

		//struct Car* car[allocationSize] = {};
		//struct Car* car = {};

		numCars = 0;
		carArrSize = allocSize;
		allocationSize = allocSize;
		//struct Car* car = nullptr;

		//car = new Car[allocSize];



	}
}