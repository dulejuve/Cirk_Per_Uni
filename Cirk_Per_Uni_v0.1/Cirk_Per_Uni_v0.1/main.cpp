#include <iostream>
#include <string>

#define sizeSbox256 256
#define binary256 9

#define sizeSbox16 16
#define binary16 5

int sizeSbox, binary, NumMatrx, NumDigits;

int STT256[binary256][sizeSbox256];
int STT1_256[binary256][sizeSbox256];

int STT3_16[binary256][sizeSbox256];
int STT1_3_16[binary256][sizeSbox256];

int *CirMatAll; //Dinamic variable for all circulan matrix //int CirMatAll[NumMatrxFix*(binaryFix - 1)];

#include "SetPar.h"
#include "IOFile.h"

#include "Header.h"
#include "PTT_s.h"		//Polarity true table


#include "Header15.h"
#include "Header17.h"
#include "Header51.h"
#include "Header3_16.h"


using namespace std;

int main() {

	string ResPer = "resper_3_16", ResMat = "resmat_3_16"; //String for name of the file with inverse permutation and cyclic matrix

	//=====Call function in SetPar input permutation file
	SetPar(ResPer); //Permutation file have number of element plus 1

	//============Call function in SetPar count number of circulan matrix
	readNumOfMatrix(ResMat); //circulant matrix

	cout << "Configuration for next parameter: \n";
	cout << "Size S-box: " << sizeSbox << "\n";
	cout << "Binary: " << binary << "\n";
	cout << "Number of Cyclic Matrix: " << NumMatrx << "\n";
	NumDigits = (sizeSbox - 1) / NumMatrx;
	cout << "Number of digits for element of the matrix: " << NumDigits << "\n";

	int num_element_CM = NumMatrx*(binary - 1);
	//Allocate memory block. Allocates a block of size bytes of memory
	CirMatAll = (int *)malloc(sizeof(int)* num_element_CM);

	//==============Sbox 8x8====================
	//============Call function in IOFile256 open file circulant matrix
	cout << "Print cyclic matrix element:\n";
	readFromFileResm(ResMat); //circulant matrix
	//=====Call function in IOFile256 input permutation file
	//ReadFilePermut(ResPer); //Permutation file


	if (NumMatrx == 15)
	{
		main15();
	//===========Call function from SetCirMatPer15 === write cyclic matrix 1D array into 2D array
		//SetMatCir(); // Function Set matrix circulante
		//SetPerInvVect(); //Set Inversan Permutation
		//SetCirMatPer();
	}

	if (NumMatrx == 17)
	{
		main17();
	//	//===========Call function from SetCirMatPer17 === write cyclic matrix 1D array into 2D array
	//	SetMatCir(); // Function Set matrix circulante
	//	SetPerInvVect(); //Set Inversan Permutation
	//	SetCirMatPer();
	}

	if (NumMatrx == 51)
	{
		main51();
		//	//===========Call function from SetCirMatPer17 === write cyclic matrix 1D array into 2D array
		//	SetMatCir(); // Function Set matrix circulante
		//	SetPerInvVect(); //Set Inversan Permutation
		//	SetCirMatPer();
	}

	if (NumMatrx == 3)
	{
		main3_16();
		//	//===========Call function from SetCirMatPer17 === write cyclic matrix 1D array into 2D array
		//	SetMatCir(); // Function Set matrix circulante
		//	SetPerInvVect(); //Set Inversan Permutation
		//	SetCirMatPer();
	}


	cout << "\n\nEnd\n";
	return 0;
}