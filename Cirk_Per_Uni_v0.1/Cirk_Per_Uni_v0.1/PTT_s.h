//Function Polarity true table (PTT) of S-box
#include <stdio.h> 
#include <iostream>

int PTT256[sizeSbox256], TT256[sizeSbox256], t256[binary256], PTT_ALL_LIN256[sizeSbox256];
int PTT16[sizeSbox16], TT16[sizeSbox16], t16[binary16], PTT_ALL_LIN16[sizeSbox16];

#include "FWT_s.h"		//CPU Fast Walsh Transformation
#include "MaxEle.h"	  //CPU function for find max element

using namespace std;

void TT_PTT256(int size, int bin, int mark, int *tvFix)
{
	int counterSboxVer=0; //counter for verification of linearity of whole S-box

	int m=bin-1;

	for(int e=1; e<=m; e++)
		t256[e]=e+1;

	for(int j=0; j<size; j++)
	{
		TT256[j]=0;
	}

	int i=1;
	int br=0;
	
	while(i!=m+1)
	{
		
		for(int j=0; j<size; j++)
		{
			TT256[j]=TT256[j]^STT256[i][j];
			
		if(TT256[j]==1)
			PTT256[j] = -1;
		else
			PTT256[j] = 1;

		}
		t256[0] = 1;
		t256[i - 1] = t256[i];
		t256[i] = i + 1;
		i = t256[0];

		FastWalshTransSbox_row(size);	//Find Walsh spectra on one row

		Lin=reduceCPU_PTT(size);		//Find Linearity on one row //max value from Walsh spectra

		//Out from the function if Linearity is Biger then (x) //=====We can fix parametar # minLin # =========
		//Linearity - Nonlinearity (60-98, 56-100, 48-104, 44-106, 40-108)
		//if(Lin>minLin)
		if(Lin>BorderLin)
		{
			return;
		}
		//if(counterSboxVer==255)
		PTT_ALL_LIN256[counterSboxVer]=Lin;
		counterSboxVer++;
	}

	Lin=reduceCPU_PTT_All(size-1); //Find Lin of S-box
	nl=sizeSbox/2-(Lin/2);		//Compute Nonlinearity
	//free(Max_Lin_row);
	//==================Save in file result for paramether with NonLinearity greater then (x)
	myfile.open(NameFile_OutputResult, ios::out | ios::app );
	myfile<< "Counter Permutation:" << PerCounterAll << " ";
	myfile << "Rank:"<< r << "\n";
	myfile << "Print Permutation:" << "\n";
	    for (int i=0;i<NumMatrx;i++)
		{	
			//myfile << Per[i] << " ";
			myfile << tvFix[i] << " ";
		}
		myfile << "\n";
		myfile << "Lin:"<<Lin <<"\n";
		myfile << "nl: " << nl << "\n";
		myfile << "Mark: " << mark << "\n\n";
		myfile.close(); // close the open file
	//========================================================
	if(minLin>Lin)
	{
	//Save result in file
	minLin=Lin;
	nl=sizeSbox/2-(Lin/2);
	maximumNL=nl;

	//Save Maximal NL, RANK and Permutation in File "MaxNL"
		SaveMaxNL.open("MaxNL");
		SaveMaxNL << minLin<<"\n";
		SaveMaxNL << maximumNL;
		SaveMaxNL << "\nRank:"<< r << "\n";
		
		SaveMaxNL << "Print Permutation" << "\n";
	    for (int i=0;i<NumMatrx;i++)
		{	
			//myfile << Per[i] << " ";
			SaveMaxNL << tvFix[i] << " ";
		}
		SaveMaxNL << "\n";
		SaveMaxNL.close();
	}
}

void TT_PTT16(int size, int bin, int mark, int *tvFix)
{
	int counterSboxVer = 0; //counter for verification of linearity of whole S-box

	int m = bin - 1;

	for (int e = 1; e <= m; e++)
		t16[e] = e + 1;

	for (int j = 0; j<size; j++)
	{
		TT16[j] = 0;
	}

	int i = 1;
	int br = 0;

	while (i != m + 1)
	{

		for (int j = 0; j<size; j++)
		{
			TT16[j] = TT16[j] ^ STT3_16[i][j];

			if (TT16[j] == 1)
				PTT16[j] = -1;
			else
				PTT16[j] = 1;

		}
		t16[0] = 1;
		t16[i - 1] = t16[i];
		t16[i] = i + 1;
		i = t16[0];

		FastWalshTransSbox_row16(size);	//Find Walsh spectra on one row

		Lin = reduceCPU_PTT16(size);		//Find Linearity on one row //max value from Walsh spectra

		//Out from the function if Linearity is Biger then (x) //=====We can fix parametar # minLin # =========
		//Linearity - Nonlinearity (60-98, 56-100, 48-104, 44-106, 40-108)
		//if(Lin>minLin)
		if (Lin>BorderLin)
		{
			return;
		}
		//if(counterSboxVer==255)
		PTT_ALL_LIN16[counterSboxVer] = Lin;
		counterSboxVer++;
	}

	Lin = reduceCPU_PTT_All16(size - 1); //Find Lin of S-box
	nl = sizeSbox / 2 - (Lin / 2);		//Compute Nonlinearity
	//free(Max_Lin_row);
	//==================Save in file result for paramether with NonLinearity greater then (x)
	myfile.open(NameFile_OutputResult, ios::out | ios::app);
	myfile << "Counter Permutation:" << PerCounterAll << " ";
	myfile << "Rank:" << r << "\n";
	myfile << "Print Permutation:" << "\n";
	for (int i = 0; i<NumMatrx; i++)
	{
		//myfile << Per[i] << " ";
		myfile << tvFix[i] << " ";
	}
	myfile << "\n";
	myfile << "Lin:" << Lin << "\n";
	myfile << "nl: " << nl << "\n";
	myfile << "Mark: " << mark << "\n\n";
	myfile.close(); // close the open file
	cout << "Lin:" << Lin << "\n";
	cout << "nl: " << nl << "\n";
	//========================================================
	if (minLin>Lin)
	{
		//Save result in file
		minLin = Lin;
		nl = sizeSbox / 2 - (Lin / 2);
		maximumNL = nl;

		//Save Maximal NL, RANK and Permutation in File "MaxNL"
		SaveMaxNL.open("MaxNL");
		SaveMaxNL << minLin << "\n";
		SaveMaxNL << maximumNL;
		SaveMaxNL << "\nRank:" << r << "\n";

		SaveMaxNL << "Print Permutation" << "\n";
		for (int i = 0; i<NumMatrx; i++)
		{
			//myfile << Per[i] << " ";
			SaveMaxNL << tvFix[i] << " ";
		}
		SaveMaxNL << "\n";
		SaveMaxNL.close();
	}
}