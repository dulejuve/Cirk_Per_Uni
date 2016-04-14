//Fast Walsh Transformation function CPU - Sbox
#include <iostream>
#include <math.h>
#include <stdio.h> 

using namespace std;

void FastWalshTransSbox(int n, int nsbox, int *BoolSbox, int *walshvec)
{
	int temp=0, j=1; 
	for(int i=0; i<n; i++)
	{
		walshvec[i]=0;
		walshvec[i]=BoolSbox[i];
	}

	while(j<nsbox)
	{
	for(int i=0; i<n; i++){
		if((i&j)==0)
			{
		temp=walshvec[i];

		walshvec[i]=(walshvec[i]+walshvec[i+j]);
		walshvec[i+j]=(-walshvec[i+j]+temp);
			}
		}
	j=j*2;
	}
}

void FastWalshTransSbox_row(int nsbox)
{
	int temp=0, j=1; 
	
	while(j<nsbox)
	{
	for(int i=0; i<nsbox; i++){
		if((i&j)==0)
			{
		temp=PTT256[i];

		PTT256[i]=(PTT256[i]+PTT256[i+j]);
		PTT256[i+j]=(-PTT256[i+j]+temp);
			}
		}
	j=j*2;
	}
}