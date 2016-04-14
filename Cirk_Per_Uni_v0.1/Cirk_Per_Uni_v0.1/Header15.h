#include <iostream>

//#define sizeSbox 256
//#define binary 9
#define NumMatrx15 15

int CirMat15[binary256][NumMatrx15], CirMatPer15[binary256][NumMatrx15];
int InvPerm15[sizeSbox256];

#include "SetCirMatPer15.h"
//int STT15[binary256][sizeSbox256];
//int STT115[binary256][sizeSbox256];

using namespace std;

//==================Function Set Matrix Circulant========================
void SetMatCir15()
{
	int br = 0;

	for (int i = 0; i<NumMatrx; i++)
	{
		for (int j = 1; j<binary; j++)
		{
			CirMat15[j][i] = CirMatAll[br];
			//cout << CirMat[j][i] << " ";
			br++;
		}
	}
	cout << "\nPrint cyclic matrix:\n";
	for (int i = 0; i<binary; i++)
	{
		for (int j = 0; j<NumMatrx; j++)
		{
			cout << CirMat15[i][j] << " ";
		}
		cout << "\n";
	}
}
//=======================================================================
//Inverse STT, use inverse permutation array===========================
void InverzPer_Inv15()
{
	for (int i = 1; i<binary; i++)
	{
		for (int j = 1; j<sizeSbox; j++)
		{
			STT1_256[i][InvPerm15[j]] = STT256[i][j];
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
void PrintSST15()
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
void SetPerInvVect15()
{
	//=======in order save binar representation of the matrix============
	for (int y = 1; y<binary; y++)
	{
		int counterBin = (NumDigits*NumMatrx), binar;
		for (int q = NumMatrx - 1; q >= 0; q--)
		{
			//CirMatPer[y][q]=CirMat[y][tvFix[q]-1];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			CirMatPer15[y][q] = CirMat15[y][q];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			for (int bin = 0; bin<NumDigits; bin++)
			{
				binar = 1 & (CirMatPer15[y][q] >> bin);
				STT256[y][counterBin] = binar;
				counterBin--;
			}
		}
	}
	//====================================================================

	//************************Print the STT*******************************
	cout << "\nPrint STT table:\n";
	PrintSST15();
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
		InvPerm15[i] = sum;
		//cout << "\n";
	}
	//====================================================================

	InverzPer_Inv15(); //Function set invers table

	//************************Print the Invers STT************************
	cout << "\n\nPrint STT Invers table:\n";
	PrintSST15();
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

void main15()
{
	SetMatCir15(); // Function Set matrix circulante
	SetPerInvVect15(); //Set Inversan Permutation
	SetInputPar();
	SetCirMatPer15();
	EndOfProgram();
}