#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

using std::swap;

//note returns INDEX of median
template<typename T> inline
int medianOf3(T A[], int l, int r){
	//this is overcommented... also, try and avoid using pointers
	T* a = A + l;//array name is just pointer to 1st (0 index) elem., + l shifts l*(T size)
	T* b = A + l + (r-l)/2;//middle item... int division rounds down
	T* c = A + r;

	//when a is a pointer, *a is the dereference operator (gives value a points to)
	T* m;
	if(*a < *b){
		if(*b < *c) m=b; 
		else if(*c < *a) m=a;
		else m=c;
	} else{ //b <=a
		if(*a < *c) m=a;
		else if(*c < *b) m=b;
		else m=c;
	}
	return m-A; //m-A is the number of elements from A[0]

}

//remember: l and r are INLCUSIVE (just like Lomuto)
template<typename T>
int hoarePartition(T A[], int l, int r){

	//set up variables for partition, left, and right indicies
	int med = medianOf3(A, l, r);
	swap(A[l], A[med]);
	int par = A[l];
	int i = l;
	int j = r + 1;
	
	//while i < j, find values and swap
	do
	{
		do
		{
			i = i + 1;
		} while (A[i] < par);
		do
		{
			j = j - 1;
		} while (A[j] > par);
		swap(A[i], A[j]);
	} while (i < j);
	
	//undo last swap and return
	swap(A[i], A[j]);
	swap(A[l], A[j]);
	return j;
}

template<typename T>
void quicksort(T A[], int l, int r){
	if (l < r)
	{
		int par = hoarePartition(A, l, r);
		quicksort(A, l, par-1);
		quicksort(A, par+1, r);
	}		
}


#endif
