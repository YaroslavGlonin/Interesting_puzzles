#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iso646.h>
using namespace std;
//3.
int game(int K, int X, int Y)
{
	int numx=X,sumx=0,sumy=0;
	while(true)
	{
		if(X<K) 
		{
			X++;
			sumx++;
		}
		else if((X-Y)<2)
		{
			X++;
			sumx++;
		}
		else break;
	}
	X=numx;
	while(true)
	{
		if(Y<K) 
		{
			Y++;
			sumy++;
		}
		else if((Y-X)<2)
		{
			Y++;
			sumy++;
		}
		else break;
	}
	if(sumx<=sumy and sumx!=0) return sumx;
	else if(sumx>=sumy and sumy!=0) return sumy;
	else return 1;
}
//4.
int game_2(int K,int X, int Y)
{
	int result=1;
	if(K-X<=K-Y)
	{
		if(X+(K-X)-Y>=2)
		{
			result = K-X;
		}
		else result=2;
	}
	else if(K-Y<=K-X)
	{
		if(Y+(K-Y)>=2)
		{
			result = K-Y;
		}
		else result=2;
	}
	if(result<=0) return 1;
	return result;
}
int main()
{
	cout << " Number of games " << game(5,5,5)  << endl;
	return 0;
}