
#include <iostream>
#include "Car.h"
#include "cStrTools.h"
using namespace std;
using namespace sdds;

//namespace Ws2
//namespace sdds
namespace myCarNamespace
{
	struct Car* car = nullptr;	// car ptr
	/* In Car.cpp create a pointer to a Car structure.
	This pointer will hold a dynamic array of Car structures with an initial size
	(that we call allocation size). 
	As cars pass the border the elements of the dynamic array will be set to 
	the information of the car until the array is full. 
	In this case, a new array of dynamic cars with more memory will be allocated
	(the old size + allocation size) to replace the old array.*/

	//Car* car = nullptr;
	//car = new Car[allocSize];

	//const int allocationSize = 2; // an integer to hold the memory allocation and expansion size when needed
	int allocationSize = 2; // an integer to hold the memory allocation and expansion size when needed
	int numCars; // an integer to hold the number of cars currently in the dynamic array of cars pointed by The Car Pointer
	int carArrSize; //  an integer to hold the current allocation size of the array. This value is the maximum size that the Number Of Cars can grow up to (before reallocation for expansion).

	//car = new Car[allocationSize];
	//car = new Car[carArrSize];

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

		car = new Car[allocSize];	// had to be inside a function cus ???

		
		//*car = allocSize;
		//car = new Car[allocSize];
		
		//struct Car* car = nullptr;

		//car = new Car[allocSize];
		cout << "Hello i am in Car::INITIALIZE()" << endl;
	}

	void deallocate(Car& C)
	// Deletes the allocated memory pointed by the make and model pointer in the
	// Car structure, then set it to nullptr.
	{
		delete[] car;	// deletes the array to prevent memory leaks
		//delete car; // would delete a single-type variable (not array)
		// we initialized as an array in "car = new Car[allocSize];" so we delete as an array
		cout << "Hello i am in Car::DEALLOCATE()" << endl;
	}

	bool read(Car& C)
	{
		cout << "Hello i am in Car::READ() STARRT" << endl;

		bool flag = false;
		char tempMake[60];
		char tempModel[60];

		unsigned int unsInt = 60;
		unsigned int unsIntLic = 8;

		char a[] = {0};	// temp var (apparantly make should be tempVars???

		//sdds::read(car[1], unsInt, ',');

		sdds::read(car->make, unsInt, ',');
		//*tempMake = { sdds::read(car->make, unsInt, ',') };
		//&tempMake( sdds::read(car->make, unsInt, ',') );

		*tempMake = *car->make; // OR
		cout << "*tempMake = *car->Make" << tempMake << endl;

		sdds::strCpy(tempMake, car->make); // OR optn
		cout << "strcpy:" << tempMake << endl;

		//-----

		sdds::read(car->model, unsInt, ',');
		*tempModel = *car->model; // OR
		cout << "*tempModel = *car->Model" << tempModel << endl;

		sdds::strCpy(tempModel, car->model);	// OR optn
		cout << "strcpy:" << tempModel << endl;


		//if (((sdds::read(car->make, unsInt, ',') != 'X') && (sdds::read(car->model, unsInt, ',') != 'X')))

		//if (a != "X")
		//if (tempMake != "X")
		if (tempMake != "X" && tempModel != "X")
		{
			flag = true;
			//delete[] car;	// OR
			
			// lecture says steps for this:
			/* 1: allocate memory for new array (temp array, bigger mem alloc)
			*  2: copy old memory content to newly allocated memory
			*  3: dataSize (of old array) = newSize (of new array) AKA update size attribute for memory
			*  4: delete[] dataPtr; (delete old memory ptr)
			*  5: dataPtr = temp; AKA update the data ptr to point to newly allocated memory
			*/

			delete car->make;
			delete car->model;

			// allocate a dynamic array of characters pointed by the make and model of the Car
			// structure to the size of the make and model red from the console (plus the null byte)
			car->make[sdds::strLen(tempMake) + 1];
			car->model[sdds::strLen(tempModel) + 1];
			
			// and copy the make and model into it.
			sdds::strCpy(car->make, tempMake); 
			sdds::strCpy(car->model, tempModel);
			//-----------------
			
			// read the license plate up to 8 characters or up to the comma character (',');
			sdds::read(car->licensePlate, unsIntLic, ',');

			// read the integer value and store it in the time variable of the Car structure.
			// what int value lol
			car->time = 1;	// ??? temp
		}
		cout << "Hello i am in Car::READ()" << endl;
		return flag;
	}

	void print(const Car& C)
	// print the car in the following format: Time: Make and model, license plate<NEWLINE
	{
		cout << "Time: " << car->time << car->make << car->model << car->licensePlate << endl;
		cout << "Hello i am in Car::print()" << endl;
	}
	void record(const Car& C)
	// Records the passage of a car by adding its information to the Car Array
	{
		//if (numCars == sdds::strLen(carArrSize))
		if (numCars == carArrSize)
		{
			// in a temporary local car pointer dynamically allocate an array of cars to the size of the car array + the allocation size.
			struct Car* tempCar = nullptr;	// temp car ptr
			tempCar = new Car[carArrSize + allocationSize];	// has to be inside a function cus ???

			// copy all the cars from the old array to the new array (but do not deallocate the individual old cars since their make and model in memory are now pointed by the cars in the new array)
			for (int i = 0; i < numCars; ++i)
			{
				tempCar[i] = car[i];
			}

			// delete the old car array by deleting The Car Pointer
			delete[] car;

			// set The Car Pointer to the value of the temporary local car pointer
			car = tempCar;	// not sure abt this one // kinda confirmed by "see here" PDF

			// update the carr array size to the new size
			car[carArrSize + allocationSize];	// also not sure abt this one lol
			
		}
		// copy the car argument after the last occupied element of the car array pointed by The Car Pointer and add one to the number of cars.
		// wth does this mean lol ;v;

		cout << "Hello i am in Car::records()" << endl;	}
	void endOfDay()
	{
		/*
		for (int i = 0; i < numCars; ++i)
		{
			//printf(car[i]);
			//printf(car);
			//deallocate(car);
			print(*car);
			deallocate(*car);
		}
		*/

		print(*car);
		deallocate(*car);

		delete car;
		car = nullptr;

		//printf(car);
		cout << "Hello i am in Car::endOfDay()" << endl;
	}

}