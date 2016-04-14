#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

//#define sizeSbox 256
//#define binary 9
//#define NumMatrx 15

//int CirMat[binary][NumMatrx], CirMatPer[binary][NumMatrx];
//int InvPerm[sizeSbox];

//int STT[binary][sizeSbox];
//int STT1[binary][sizeSbox];

//#################################################################
//int inputPar[5]; //input parametar 1. Input Divisor, 2. //Input Part, 3. Input ENTER 1, 4. Border Linearity 5. Make record of every XXXXXX
//unsigned int BorderLin;	//border for Linearity
//unsigned int maximumNL = 0, minLin = 100; //set inital value
//unsigned int Lin = 0, nl = 0; //varieble for linearity and non linearity
//unsigned __int64 PerCounterAll = 0, LastPermut;
//
//int SaveLastPerutation = 10000000; //Default value for Save Last Permutation 
//
//string NameFile_OutputResult; //string, name of the output file
//unsigned __int64 maxNL = 0, r; //variable, maxNL count permutation, r RANK
//
//ofstream SaveMaxNL, myfile; //File for writing Max compute paramether

int tvFix3_16[NumMatrx3_16], tv3_16[NumMatrx3_16]; //array for permutation int tvFix[NumMatrx];

//#include "PTT_s.h"		//Polarity true table
//#include "OutputResultFunc.h"


//#define SWAP(a,b) do {t=(a);(a)=(b);(b)=t;} while(0) //SWAP use for permutation

//#############################################################################

using namespace std;

//ofstream SavePermmyfile;//, SaveMaxNL; //Open file for writing
//ifstream fin("InputParameter"), LastPerm("SaveLastPerm"), OpenMaxNL("MaxNL"); // Open file for reading! //Configuration File on Star up


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

////============Function for calculation factorial============
//unsigned __int64 fact(int i)
//{
//	unsigned __int64 result = 1;
//	while (i > 0) {
//		result = result * i;
//		i = i - 1;
//	}
//	return(result);
//}
////=============================================================

//==============Function Read Last permutation, file SaveLastPerm=================================
//void ReadLastPer()
//{
//	if (LastPerm.is_open())
//	{
//		LastPerm >> LastPermut;
//	}
//	else //file could not be opened
//	{
//		cout << "Configuration File #SaveLastPerm# could not be opened, not exists." << endl;
//	}
//}
//================================================================================================
//======Function read Configuration file InputParameter===========================================
//bool InputFileConfiRead()
//{
//	string line;
//	bool existConf = false;
//	int brPar = 0;
//	//Open configuration file
//	if (fin.is_open())
//	{
//		existConf = true;
//		//file opened successfully so we are here
//		cout << "\nConfiguration File Opened successfully!. Reading FILE #InputParameter#\n";
//		while (getline(fin, line))
//		{
//			//cout << line << '\n';
//			inputPar[brPar] = atoi(line.c_str());
//			brPar++;
//		}
//		fin.close(); // Close that file!
//
//	}
//	else //file could not be opened
//	{
//		cout << "Configuration File #InputParameter# could not be opened, not exists." << endl;
//	}
//	return existConf;
//}
//================================================================================================
//==============Function Read Last Nonlinearity and Linearity, file MaxNL=========================
//bool ReadLastLinNL() //Linearity - Nonlinearity (60-98, 56-100, 48-104, 44-106, 40-108)
//{
//	bool LastLin = false;
//	int input_LIN_NL[5], brPar_LIN_NL = 0; //input parametar 1. Input Divisor, 2. //Input Part, 3. Input ENTER 1
//	string line1;
//	if (OpenMaxNL.is_open())
//	{
//		LastLin = true;
//		//file opened successfully so we are here
//		cout << "\nConfiguration File #Maximum Nonlinearity - Minimum Linearity# Opened successfully!\n";
//		while (getline(OpenMaxNL, line1))
//		{
//			//cout << line << '\n';
//			input_LIN_NL[brPar_LIN_NL] = atoi(line1.c_str());
//			brPar_LIN_NL++;
//		}
//		OpenMaxNL.close(); // Close that file!
//
//		minLin = input_LIN_NL[0];
//		maximumNL = input_LIN_NL[1];
//	}
//	else //file could not be opened
//	{
//		cout << "Configuration File #MaxNL# could not be opened, not exists." << endl;
//	}
//	return LastLin;
//}
//================================================================================================

//Inverse STT, use inverse permutation array======================================================
void InverzSTT3_16()
{
	for (int i = 1; i<binary; i++)
	{
		for (int j = 1; j<sizeSbox; j++)
		{
			STT1_3_16[i][InvPerm3_16[j]] = STT3_16[i][j];
			//	cout << InvPerm[j]<<" ";
		}
		//	cout<<"\n";
	}
	//	cout<<"Print Inverz Matrix\n";
	for (int i = 0; i<binary; i++)
	{
		for (int j = 0; j<sizeSbox; j++)
		{
			STT3_16[i][j] = STT1_3_16[i][j];
		}
	}
}
//================================================================================================

////Save every (x) permutation put mark of the RANK permutation //print of the display
//void SavePerm15()
//{
//	if (maxNL == SaveLastPerutation)
//	{
//		//Save Last Milion permutation in file "SaveLastPerm"
//		SavePermmyfile.open("SaveLastPerm");
//		SavePermmyfile << r;
//		SavePermmyfile.close();
//
//		cout << "Print Permutation:" << PerCounterAll << "\n";
//		cout << "Rank:" << r << "\n";
//		//cout << "maxNL:"<< maxNL <<"\n";
//		cout << "Nonlinearity(NL):" << maximumNL << " Linearity:" << minLin << "\n";
//		//cout << "nl: " << nl << "\n";
//		maxNL = 0;
//	}
//}
////=====================================================================

void CiklicMatrixPermute3_16()
{
	//===============in reverse order save binar representation of the matrix=============
	//for(int y=1; y<binary; y++)
	//{
	//	int counterBin=1, binar;
	//	for(int q=0; q<NumMatrx; q++)
	//	{			
	//		CirMatPer[y][q]=CirMat[y][tvFix[q]-1];//CirMatPer[y][q]=CirMat[y][Per[q]-1];

	//		for(int bin=0; bin<NumDigits; bin++)
	//		{
	//		//STT[q][counterBin]=1&(CirMatPer[y][q]>>bin);
	//		binar= 1&(CirMatPer[y][q]>>bin);
	//		STT[y][counterBin]=binar;
	//		counterBin++;
	//		}
	//	}
	//}
	//====================================================================================

	//=======in order save binar representation of the matrix============
	for (int y = 1; y<binary; y++)
	{
		int counterBin = (NumDigits*NumMatrx), binar;
		for (int q = NumMatrx - 1; q >= 0; q--)
		{
			//CirMatPer[y][q]=CirMat[y][tvFix[q]-1];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			CirMatPer3_16[y][q] = CirMat3_16[y][tvFix3_16[q] - 1];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			for (int bin = 0; bin<NumDigits; bin++)
			{
				binar = 1 & (CirMatPer3_16[y][q] >> bin);
				STT3_16[y][counterBin] = binar;
				counterBin--;
			}
		}
	}
	//==================================================================================

	//************************Print the STT******************************
	cout << "\nPrint the STT:\n";
	for(int j=0; j<binary; j++)
	{  
		for(int i = 0; i<sizeSbox; i++)
		{
		//cout << i <<":"<< STT[j][i] << " ";
		cout << STT3_16[j][i] << " ";
		}
		cout << "\n";
	}
	//********************************************************************

	//============================================================================
	//AllOtherFunction(1); //################# Function call****3-th paramether is mark (1-right, 2-inversion)
	TT_PTT16(sizeSbox, binary, 1, tvFix3_16);

	InverzSTT3_16(); //Inverse STT, use inverse permutation array

	//************************Print the STT*******************************
	cout << "\nPrint the STT Invers:\n";
	for(int j=0; j<binary; j++)
	{  
		for(int i = 0; i<sizeSbox; i++)
		{
		//cout << i <<":"<< STT[j][i] << " ";
		cout << STT3_16[j][i] << " ";
		}
		cout << "\n";
	}
	//********************************************************************

	//AllOtherFunction(2); //################# Function call****3-th paramether is mark (1-right, 2-inversion)
	TT_PTT16(sizeSbox, binary, 2, tvFix3_16);

	//==============================================================================
	SavePerm(); //Save every (x) permutation put mark of the RANK permutation //print of the display
}

////function _mr_unrank1 use from function get_permutation
//void _mr_unrank1(__int64 rank, int n, int *vec) {
//	unsigned __int64 t, q, r;
//	if (n < 1) return;
//
//	q = rank / n;
//	r = rank % n;
//	SWAP(vec[r], vec[n - 1]);
//	_mr_unrank1(q, n - 1, vec);
//}
//
///* Fill the integer array <vec> (of size <n>) with the
//* permutation at rank <rank>.
//*/
//void get_permutation(__int64 rank, int n, int *vec) {
//	int i;
//	for (i = 0; i < n; ++i) vec[i] = i;
//	_mr_unrank1(rank, n, vec);
//}

//****************************************************************************************************
void SetCirMatPer3_16()
{
	//int i, tv[NumMatrx15];//, tvFix[NumMatrx];			//int i, tv[NumPerEle], tvFix[NumPerEle];
	//int divisor, inputPart, enter;//, brSave=0;
	//unsigned __int64 PerCounter = fact(NumMatrx);		//unsigned __int64 PerCounter=fact(NumPerEle);
	//unsigned __int64 divisorRes, starRank, starRankPart, endRank, realCounter = 0;//, r;

	/////////////////////////////////////////////////////////////////
	//cout << "Permutations on " << NumMatrx << " element:\n"; //printf("Permutations on %d element:\n", NumPerEle);
	//cout << "Number of permutation:" << PerCounter << "\n";
	//cout << "Input integer (>0) to split permutation:\n";
	///////////////////////////////////////////////////////////////

	//ReadLastPer();
	////===============================
	//if (InputFileConfiRead()) //Input parameter call, Open InputParameter file
	//{
	//	divisor = inputPar[0];
	//	cout << "Input Divisor=" << divisor;
	//	divisorRes = PerCounter / divisor;
	//	cout << "\nEvery part will have: " << divisorRes << " permutation\n";

	//	inputPart = inputPar[1];
	//	cout << "Choosen part: " << inputPart << "\n";

	//	starRankPart = divisorRes*(inputPart - 1);
	//	starRank = divisorRes*(inputPart - 1);
	//	endRank = (divisorRes*inputPart) - 1;
	//	cout << "Star rank:" << starRank << "\n";
	//	cout << "End rank:" << endRank << "\n";

	//	if (LastPermut>starRank&&LastPermut<endRank) //set rank to start from diffrent rank
	//	{
	//		starRank = LastPermut;
	//		//realCounter = starRank - starRankPart;
	//		cout << "\nStart Permutation from Diffrent RANK:" << LastPermut << " LAST SAVE PERMUTATION\n";

	//		cout << "\nStar rank:" << starRank << "\n";
	//		cout << "End rank:" << endRank << "\n";
	//	}
	//	enter = inputPar[2];
	//	BorderLin = inputPar[3];
	//	cout << "Border Linearity:" << BorderLin << "\n";

	//	SaveLastPerutation = inputPar[4];
	//	cout << "Make record of every:" << SaveLastPerutation << " permutation\n";
	//}
	////====================================================================================================
	//else //===if file could not be opened
	//{
	//	//cout << "File could not be opened." << endl;
	//	cout << "Manual input of PARAMETERS." << endl;
	//	cout << "Input Divisor="; cin >> divisor;				//Input Divisor
	//	divisorRes = PerCounter / divisor;
	//	cout << "Every part will have " << divisorRes << " permutation\n";

	//	cout << "Choose which part will like to generate\n";
	//	cout << "Choose between 1 and " << divisor << "\n";
	//	cout << "Input="; cin >> inputPart;						//Input Part

	//	starRankPart = divisorRes*(inputPart - 1);
	//	starRank = divisorRes*(inputPart - 1);
	//	endRank = (divisorRes*inputPart) - 1;
	//	cout << "Star rank:" << starRank << "\n";
	//	cout << "End rank:" << endRank << "\n";

	//	cout << "Input Border Linearity:"; cin >> BorderLin;

	//	cout << "Input number for keep track of permutation:"; cin >> SaveLastPerutation;

	//	cout << "\nPress the ENTER 1 for start:";
	//	cout << "\nIf you want to star from different RANK ENTER 2:";
	//	cin >> enter; //input enter
	//}
	//if (ReadLastLinNL()) //========Open Configuration File #Maximum Nonlinearity - Minimum Linearity# last save values=======
	//{
	//	cout << "Minimum Linearity from last execution (Linearity):" << minLin << "\n";
	//	cout << "Maximum Nonlinearity from last execution (NL):" << maximumNL << "\n\n";
	//}
	//else
	//{
	//	cout << "Inital value for Linearity and Nonlinearity:\n";
	//	cout << "Linearity:" << minLin << "\n";
	//	cout << "NL:" << maximumNL << "\n\n";
	//}

	////========Check is Output file exist if exist create new file=====
	//string OutputResultBody = "OutputResult";//, NameFile_OutputResult;
	//int indexOutputResult = 0;

	//NameFile_OutputResult = IntToStringAndConcate(indexOutputResult, OutputResultBody); //Function for convert int to string IntToString

	////Function: Save OutputResult name, open new File for result if exit given name 
	//NameFile_OutputResult = FexistsNumber(indexOutputResult, OutputResultBody, NameFile_OutputResult);

	////Print name of the file where we save the result
	//cout << "Output file name: " << NameFile_OutputResult << " " << "\n\n";
	////==============================================================================================

	////=====Open file for writing inital data related with particular instance of the program 
	//myfile.open(NameFile_OutputResult); //=====Open file for writing the result
	////=======Save initial data for this instatce of the program
	//myfile << "Permutations on " << NumMatrx << " element:\n"; //printf("Permutations on %d element:\n", NumPerEle);
	//myfile << "Number of permutation:" << PerCounter << "\n";
	//myfile << "Input integer (>0) to split permutation:\n";
	//myfile << "Input Divisor=" << divisor;
	///////////////////////////////////////////////////////////////////////////////
	//myfile << "\nEvery part will have " << divisorRes << " permutation\n";
	//myfile << "Choose which part will like to generate\n";
	//myfile << "Choose between 1 and " << divisor << "\n";
	//myfile << "Input=" << inputPart << "\n";
	//myfile << "Border Linearity:" << BorderLin << "\n";
	////============================================================

	////start permutation from diffrent RANK
	//if (enter == 2)
	//{
	//	cout << "\nPlease input number between " << starRank << " and " << endRank << ":";
	//	cin >> starRank;
	//	realCounter = starRank - starRankPart;
	//	cout << "\nDifference betwen start RANK from chosen Part and new input RANK:" << realCounter;

	//	cout << "\nStar rank:" << starRank << "\n";
	//	cout << "End rank:" << endRank << "\n";

	//	cout << "\nPress the ENTER 1 for start:";
	//	cin >> enter;
	//}

	////start permutation
	//if (enter == 1)
	//{
	//	realCounter = starRank - starRankPart;
	//	cout << "\nDifference betwen start RANK from chosen Part and new input RANK: " << realCounter << "\n\n";
	//	myfile << "Star rank:" << starRank << "\n";
	//	myfile << "End rank:" << endRank << "\n";
	//	myfile << "\nDifference betwen start RANK from chosen Part and new input RANK: " << realCounter << "\n\n";
	//	myfile.close(); // close the open file

	//	cout << "Start...\n";

	for (r = starRank; r <= endRank; ++r)
	{
		get_permutation(r, NumMatrx, tv3_16); //get_permutation(r, NumPerEle, tv);

		for (int i = 0; i < NumMatrx; ++i)
		{
			if (tv3_16[i] == 0)
				tvFix3_16[i] = NumMatrx;
			else
				tvFix3_16[i] = tv3_16[i];

			//cout << tvFix[i] << " "; //print permutation
		}
		//cout << "\n";
		//=========================================================
		CiklicMatrixPermute3_16();
		PerCounterAll++;
		maxNL++;
		//=========================================================
	}
	//}
	//myfile.open(NameFile_OutputResult, ios::out | ios::app);
	//myfile << "\n" << "End of the program\n";
	//myfile.close(); // close the open file
	//cout << "\n" << "End of permutation\n";
}