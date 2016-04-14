//Function reduction
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int reduceCPU_max(int *vals, int nvals)
	{
	int cmax=vals[0];

    for(int i=1; i<nvals; i++) 
	{
        cmax = max( abs(vals[i]), cmax); 
    }
    return cmax;
}

int reduceCPU_PTT(int nvals)
	{
	int cmax=PTT256[0];

    for(int i=1; i<nvals; i++) 
	{
        cmax = max( abs(PTT256[i]), cmax); 
    }
    return cmax;
}

int reduceCPU_PTT_All(int nvals)
	{
	int cmax=PTT_ALL_LIN256[0];

    for(int i=1; i<nvals; i++) 
	{
        cmax = max( abs(PTT_ALL_LIN256[i]), cmax); 
    }
    return cmax;
}


