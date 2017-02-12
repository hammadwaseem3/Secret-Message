#include<stdio.h>
#include<conio.h>
#include<string.h>
#define size 10000 
int l ,len ;
char keytemp[size] , k[size] , k_temp[size] , k1[size] , k2[size] , k3[size] , k4[size] ;
char k5[size] , k6[size] , k7[size] , k8[size] , k9[size] , k10[size] ;

void key ( int n ) 
{
// 			We use this method for generate a key . Every time we minus 5 from our key and gets a new key
	int i , j = 5 ;
	for ( i=0 ; i<n ; i++)
	{
		k1[i] = k [i] - j ;
		k2[i] = k1 [i] - j ;
		k3[i] = k2 [i] - j ;
		k4[i] = k3 [i] - j ;
		k5[i] = k4 [i] - j ;
		k6[i] = k5 [i] - j ;
		k7[i] = k6 [i] - j ;
		k8[i] = k7 [i] - j ;
		k9[i] = k8 [i] - j ;
		k10[i] = k9 [i] - j ;
	}
}

void encrypt ( char A[size] , int l ) 
{
	
	int i = 0 , j = 0 ;

/* 		First Alphabet was pick first. Then we zor first alphabet with first alphabet of key 1 and then
				zor that answer with key2 abd so on. */
	
	while(A[i] != '\0')
	{
		A[i]=A[i] ^ k1[j];
		A[i]=A[i] ^ k2[j];
		A[i]=A[i] ^ k3[j];
		A[i]=A[i] ^ k4[j];
		A[i]=A[i] ^ k5[j];
		A[i]=A[i] ^ k6[j];
		A[i]=A[i] ^ k7[j];
		A[i]=A[i] ^ k8[j];
		A[i]=A[i] ^ k9[j];
		A[i]=A[i] ^ k10[j];
		
// 		This is Condition that if we reached to last alphabet of key . Then Key will reset for zero .
		
		if(j == l)
		{
			j=0;
		}
		else
		{
			j++;
		}
		
		i++;
	}
	A[i]=l+50;  // at the end of an array lenth of key is place with addition 50 that no one get that this is length of key.
	i++;  // only developer know that minus 50 i get lenght of key.
	j=0;
	while(k[j] != '\0')
	{
		A[i]=k[j]+5; // key is hiding at the end of array with addition so no one get the key ..!
		i++;
		j++;
	}
}

void decrypt ( char A[size] , char B[size] , int l )
{
	int i = 0 , j = 0 ;

// 	Perform same Zor Operation in reverse. 
	
	while(i < len )
	{
		B[i]= k10[j] ^ A[i] ;
		B[i]= k9[j] ^ B[i] ;
		B[i]= k8[j] ^ B[i] ;
		B[i]= k7[j] ^ B[i] ;
		B[i]= k6[j] ^ B[i] ;
		B[i]= k5[j] ^ B[i] ;
		B[i]= k4[j] ^ B[i] ;
		B[i]= k3[j] ^ B[i] ;
		B[i]= k2[j] ^ B[i] ;
		B[i]= k1[j] ^ B[i] ;

// 		This is Condition that if we reached to last alphabet of key . Then Key will reset for zero .		
		
		if(j==l)
		{
			j=0;
		}
		else
		{
			j++;
		}
		
		i++;
	}
	B[i] = '\0' ;
}
