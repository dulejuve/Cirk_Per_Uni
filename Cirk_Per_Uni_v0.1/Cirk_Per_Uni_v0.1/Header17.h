#include <iostream>

//#define sizeSbox 256
//#define binary 9
#define NumMatrx17 17

int CirMat17[binary256][NumMatrx17], CirMatPer17[binary256][NumMatrx17];
int InvPerm17[sizeSbox256];

#include "SetCirMatPer17.h"
//int STT17[binary256][sizeSbox256];
//int STT117[binary256][sizeSbox256];

using namespace std;

//==================Function Set Matrix Circulant========================
void SetMatCir17()
{
	int br = 0;

	for (int i = 0; i<NumMatrx; i++)
	{
		for (int j = 1; j<binary; j++)
		{
			CirMat17[j][i] = CirMatAll[br];
			//cout << CirMat[j][i] << " ";
			br++;
		}
	}
	cout << "\nPrint cyclic matrix:\n";
	for (int i = 0; i<binary; i++)
	{
		for (int j = 0; j<NumMatrx; j++)
		{
			cout << CirMat17[i][j] << " ";
		}
		cout << "\n";
	}
}
//=======================================================================
//Inverse STT, use inverse permutation array===========================
void InverzPer_Inv17()
{
	for (int i = 1; i<binary; i++)
	{
		for (int j = 1; j<sizeSbox; j++)
		{
			STT1_256[i][InvPerm17[j]] = STT256[i][j];
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
void PrintSST17()
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
void SetPerInvVect17()
{
	//=======in order save binar representation of the matrix============
	for (int y = 1; y<binary; y++)
	{
		int counterBin = (NumDigits*NumMatrx), binar;
		for (int q = NumMatrx - 1; q >= 0; q--)
		{
			//CirMatPer[y][q]=CirMat[y][tvFix[q]-1];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			CirMatPer17[y][q] = CirMat17[y][q];//CirMatPer[y][q]=CirMat[y][Per[q]-1];
			for (int bin = 0; bin<NumDigits; bin++)
			{
				binar = 1 & (CirMatPer17[y][q] >> bin);
				STT256[y][counterBin] = binar;
				counterBin--;
			}
		}
	}
	//====================================================================

	//************************Print the STT*******************************
	cout << "\nPrint STT table:\n";
	PrintSST17();
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
		InvPerm17[i] = sum;
		//cout << "\n";
	}
	//====================================================================

	InverzPer_Inv17(); //Function set invers table

	//************************Print the Invers STT************************
	cout << "\n\nPrint STT Invers table:\n";
	PrintSST17();
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

void main17()
{
	SetMatCir17(); // Function Set matrix circulante
	SetPerInvVect17(); //Set Inversan Permutation
	SetInputPar();
	SetCirMatPer17();
	EndOfProgram();
}