#include <iostream>

//#define sizeSbox 256
//#define binary 9
#define NumMatrx51 51

int CirMat51[binary256][NumMatrx51], CirMatPer51[binary256][NumMatrx51];
int InvPerm51[sizeSbox256];

#include "SetCirMatPer51.h"
//int STT15[binary256][sizeSbox256];
//int STT115[binary256][sizeSbox256];

using namespace std;

//==================Function Set Matrix Circulant========================
void SetMatCir51()
{
	int br = 0;

	for (int i = 0; i<NumMatrx; i++)
	{
		for (int j = 1; j<binary; j++)
		{
			CirMat51[j][i] = CirMatAll[br];
			//cout << CirMat[j][i] << " ";
			br++;
		}
	}
	cout << "\nPrint cyclic matrix:\n";
	for (int i = 0; i<binary; i++)
	{
		for (int j = 0; j<NumMatrx; j++)
		{
			cout << CirMat51[i][j] << " ";
		}
		cout << "\n";
	}
}
//=======================================================================
//Inverse STT, use inverse permutation array===========================
void InverzPer_Inv51()
{
	for (int i = 1; i<binary; i++)
	{
		for (int j = 1; j<sizeSbox; j++)
		{
			STT1_256[i][InvPerm51[j]] = STT256[i][j];
			//	cout << InvPerm[j]<<" ";
		}
		//	cout<<"\n";
	}
	//	cout<<"Print Inverz Matrix\n";
	for (int i = 0; i<binary; i++)
	{
		for (int j = 0; j<sizeSbox; j++)
		{
			STT256[i][j] = STT1_256[i][j];
		}
	}
}
//=======================================================================

//=======================================================================
void PrintSST51()
{
	for (int j = 0; j<binary; j++)
	{
		for (int i = 0; i<sizeSbox; i++)
		{
			//cout << i <<":"<< STT[j][i] << " ";
			cout << STT256[j][i] << " ";
		}
		cout << "\n";
	}
}

//=======================================================================

//=======================================================================
void SetPerInvVect51()
{
	//=======in order save binar representation of the matrix============
	for (int y = 1; y<binary; y++)
	{
		int counterBin = (NumDigits*NumMatrx), binar;
		for (int q = NumMatrx - 1; q >= 0; q--)
		{
			//CirMatPer[y][q]=CirMat[y][tvFix[q]-1];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			CirMatPer51[y][q] = CirMat51[y][q];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			for (int bin = 0; bin<NumDigits; bin++)
			{
				binar = 1 & (CirMatPer51[y][q] >> bin);
				STT256[y][counterBin] = binar;
				counterBin--;
			}
		}
	}
	//====================================================================

	//************************Print the STT*******************************
	cout << "\nPrint STT table:\n";
	PrintSST51();
	//********************************************************************

	//========Convert binar to decimal and print==========================
	cout << "\nPrint Invers Permutation element:\n";

	for (int i = 0; i<sizeSbox; i++)
	{
		int decimal = 0, counterBin = 0, bin, sum = 0;
		for (int j = binary - 1; j>0; j--)
		{
			//decimal=decimal+STT[j][i]<<j;
			bin = STT256[j][i];
			decimal = bin << counterBin;
			//cout <<" "<< decimal << " ";
			counterBin++;
			sum = sum + decimal;
			//cout << i <<":"<< STT[j][i] << " ";

		}
		cout << i << ":" << sum << ", ";
		InvPerm51[i] = sum;
		//cout << "\n";
	}
	//====================================================================

	InverzPer_Inv51(); //Function set invers table

	//************************Print the Invers STT************************
	cout << "\n\nPrint STT Invers table:\n";
	PrintSST51();
	//********************************************************************

	//********************Convert binar to decimal and print**************
	//cout << "\nPrint Invers S-box:\n";
	//
	//for(int i = 0; i<sizeSbox; i++)
	//{  
	//	int decimal=0, counterBin=0, bin, sum=0;
	//	for(int j=binary-1; j>0; j--)
	//	{
	//		//decimal=decimal+STT[j][i]<<j;
	//		bin=STT[j][i];
	//		decimal=bin<<counterBin;
	//		//cout <<" "<< decimal << " ";
	//		counterBin++;
	//		sum=sum+decimal;
	//	//cout << i <<":"<< STT[j][i] << " ";
	//	
	//	}
	//	cout <<i<<":"<< sum << ", ";
	//	//SboxInv[i]=sum;
	//	//cout << "\n";
	//}
	//********************************************************************
}

void main51()
{
	SetMatCir51(); // Function Set matrix circulante
	SetPerInvVect51(); //Set Inversan Permutation
	SetInputPar();
	SetCirMatPer51();
	EndOfProgram();
}