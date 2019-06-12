#include "stdafx.h"
#include <iostream>

using namespace std;
//1.возвращает указатель на измененный массив
//Ќаписать функцию на вход которой подаетс€ массив из N целых чисел, а на выходе получаетс€  этот же массив,
//но отсортированный таким образом, что последнее число равно сумме всех остальных, при условии что сумма элементов (n-1) имеетс€ в массиве
int* test_sort (int in[],int size) 
{
	int *backup = new int[size];
	bool exit=true;
	int elementofindex=0,element=0,result=0;
	for(int i = 0; i < size; i++)
	{
    	backup[i]=in[i];
	}
	while(exit)
	{
		result=0;
		for(int i = 0; i < size-1; i++)
		{
    		result=result+in[i];
		}
		if(result==in[size-1])
		{
			exit=false;
		}
		else
		{
			if(element+1>size-1)
				{
					elementofindex++;
					element=elementofindex;
					for(int i = 0; i < size; i++)
					{
    					in[i]=backup[i];
					}
				}	
				int c = in[element];
				in[element] =in[element+1];
				in[element+1] = c;
				element++;
				
		}
	}
return in;
}
//2. роме как вынести цикл сложени€ в рекурсивную ф-цию, больше ничего не придумал.
//» заменить цикл присваивани€ memcpy.
int Sum(int mass[], int size)
{
    if (size > 0)
        return mass[size-1] + Sum(mass, size-1);
    else
        return 0;
}
int* test_sort_2 (int in[],int size) 
{
	int *backup = new int[size];
	bool exit=true;
	int elementofindex=0,element=0,result=0;
	for(int i = 0; i < size; i++)
	{
    	backup[i]=in[i];
	}
	while(exit)
	{
		result=0;
		result=Sum(in,size-1);
		/*for(int i = 0; i < size-1; i++)
		{
    		result=result+in[i];
		}*/
		if(result==in[size-1])
		{
			exit=false;
		}
		else
		{
			if(element+1>size-1)
				{
					elementofindex++;
					element=elementofindex;
					memcpy( in, backup, sizeof( int) * 10 );
					/*for(int i = 0; i < size; i++)
					{
    					in[i]=backup[i];
					}*/
				}	
				int c = in[element];
				in[element] =in[element+1];
				in[element+1] = c;
				element++;
		}
	}
return in;
}

int main()
{
	int size,c;
    cout << "Enter size of array ";
    cin >> size;

    int *massiv = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> massiv[i];
    }
	massiv=test_sort_2(massiv,size);
	//massiv=test_sort(massiv,size);
    for (int i = 0; i < size; i++)
    {
    	cout << "Index " << i << " Number is " << massiv[i] << endl;
    }
    delete [] massiv;
	return 0;
}
