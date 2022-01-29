#pragma once
#ifndef CAR_H 
#define CAR_H

//namespace sdds
namespace myCarNamespace
{
	struct Car
	{
		char licensePlate[9];	// character array 
		//char* makeModel = nullptr;	// character pointer to null adress
		/* Initialization to nullptr ensures that makeModel is not pointing
		to any valid dereferencable address.

		 The size of the array is a run-time variable and not an integer
		 constant or constant expression.  Note that the size of an array
		 allocated in static memory must be an integer constant or constant
		 expression. */
		char* make = nullptr;		//character pointer later defined as dataptr[x] = value OR *model=value
		char* model = nullptr;	//character pointer later defined as dataptr[x] = value OR *model=value
		int time;	// in military format (ie. 30 is 0:30 AM and 1325 is 1:25 PM)
	}; //struct Car* car = nullptr;


	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();



}

#endif // !CAR_H