/* 									Project No : 5 

						Group Name : Born To Code
						Leader Name : Ali Shah Pervez ( 14K-2045 )
						Group Member : Hammad Waseem ( 14K-2185 )
						Section : B
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"AH.h"
void key ( int ) ;
void encrypt ( char [] , int ) ;
void decrypt ( char [] , char [] , int ) ;

// 					Initialize Globally All Keys


int main ( void ) 
{
	printf("\t\t   **Welcome to A.H Spy Software**\n\t\t**developed by Ali Shah and Hammad**\n");
	FILE *input;
	FILE *output;
	char File[20];
	char E[size] , D[size]  ;
	int menu  , i = 0,temp , j = 0 , count = 0 , count_1 = 0 , cmp ;
	
	do
	{
		printf("\n\n\t\t\t!!  ****** MENU ******  !!\n\n") ;
		printf("1) Encrypt ") ;
		printf("\n2) Decrypt ") ;
		printf("\n3) Exit ") ;
		printf("\n\nEnter a Menu Number ==>  ") ;
		scanf("%d",&menu) ;
		
		switch ( menu ) 
		{
			case 1 :
				
				for ( i=0 ; i<size ; i++ )
				{
					D[i] = '\0' ;
				}
				
				fflush (stdin) ;
				printf("Enter a File name (.txt)  ==>  ");
				gets(File);
				input=fopen(File,"r");
		
	
				
// 			If no file present of that name
				
				if ( input == NULL )
				{
					printf("\n\nThere is No file available\n\n\t\tTry Again\n\n");
					continue ;
				}
				printf("\nEnter a Key ==>  ") ;
				gets ( k ) ;
				fflush (stdin) ;

/*			Initialize encrypt array and key arrya with null character.. Because if we use this function again	
   					Last encrypt file and key will remove. And initialize with null 
*/

				for ( i=0 ; i<size ; i++ ) 
				{
					E[i] = '\0' ; 
					 
				}			

// 			Copy All data of File in to Array
						while( !feof(input) )
	{
		
		fscanf(input,"%[^NULL]s",E);
  	
		 
	}
		        fgets(E,size,input);
				l = strlen ( k ) ;
				len= strlen(E);
				key ( l ) ;
				encrypt ( E , l ) ;
				printf("\n\n");
				puts ( E ) ;
				
// 			Copy data into Cipher Text

				output=fopen("cipher.txt","w+");
	            fputs(E , output);
				count ++ ;
				break ;
				
			case 2 :

// 			If we Encrypted any file count will plus . If Count is zero means there is no file encrypted

				if ( count == 0 ) 
				{
					printf("\n\nThere is No file Uploade . Please Upload File first ") ;
					continue ;
				}
				fflush (stdin) ;
				printf("Enter a Key ==>  ") ;
				gets ( k_temp ) ;
				
				cmp = strcmp ( k_temp , k ) ;
				
// 			Compare both the Keys .. If cmp is zero means both are not equal .
				
				if ( cmp != 0 )
				{
					count_1 ++ ;

// 					5 chances for user to put a wrong key

					if ( count_1 == 5 ) 
					{
						printf("\n\n\t\tYou Entered a 5 times wrong Key.\nYour file have been crush.");
					   	int x;
						fclose(output);
						
// 						If user Entered 5 times Wrong key . Then Cipher File will crash.
	                    
						x = remove("cipher.txt");
						return 0 ;
					} 
					printf(" \n\n\t\tYou Entered a Wrong Key ") ;
					continue ;
				}
				
				decrypt (  E , D , l ) ;
				
				printf("\n\n") ;
				puts ( D ) ;
				
				break ;
			
			case 3 :
				printf("\n\n\t\t!!...Thank You For Using Our Software...!! \n\n");
				break ;
				
			default :
				printf("\n\nSorry !! . You Entered a Wrong Menu Number. Please Try Again ") ;
				break ;
		}
	} while ( menu != 3) ;
	
	getch () ;
	return 0 ;
	
}
