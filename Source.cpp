#include "ArrayHW.h"

int main()
{
	int* array1 = new int[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Array <int, int> objI(9, array1);
	objI.findElementWithIndex(0);
	objI.getArray();
	objI.insertAtBeginning(444);
	objI.getArray();


	double* array2 = new double[9]{ 1.45, 2.45, 3.45, 4.45, 5.45, 6.45, 7.45, 8.45, 9.45 };
	Array <double, int> objD(9, array2);
	objD.getArray();
	objD.InsertBefore(454.333, 5);
	objD.getArray();
	objD.Erase();
	objI.Erase();

	string* string1 = new string[9]{ "1", "2", "3", "4", "55555", "6666", "7", "8", "9" };
	Array <string, int> objS(9, string1);
	objS.getArray();
	objS.insertAtBeginning("I am at the beginning");
	objS.getArray();
	objS.Erase();
	return 'nice';
}