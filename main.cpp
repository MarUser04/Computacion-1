#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
 
#define f 30
#define c 30

 //prototipo
void cursor ( int x, int y );
void construir(int mapa[f][c], int nivel);
void imprimir (int mapa[f][c]);
void diamantes ();
void jugar(int mapa[f][c], int nivel);
void creditos();



int main(int argc, char** argv) {
	
	srand(time(0));
	system("color 6");
    int mp[f][c], vec[5], nivel=1;
    printf("\tDigger.\n sin movimiento de enemigos, nivel facil\ version 1.1");
    system("pause>null");
    system("cls");
    
    construir(mp, nivel);
    imprimir( mp);
	//diamantes();
    jugar(mp, nivel);
    
   
	
	system("pause>null");
	return 0;
}

void cursor ( int x, int y )
{
  COORD coord = {x, y};
  SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
}

void construir(int mapa[f][c], int nivel)
{
    int aux[f][c]={ { 5, 5, 5,5,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5, 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
			        {5, 0,7,7 ,7,7 ,7 , 7, 7,7, 7, 7, 7, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },   
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 6, 6, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 6, 6, 0, 0, 5 }, 
                    {5, 0, 0,0 ,6,6 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,6,6 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 7, 7, 7, 7, 7, 3, 7,7 ,7,7 ,7 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 6, 6, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 6, 6, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 7,7 ,7,7 ,7 , 7, 3,7, 7, 7, 7, 0, 5 }, 
                    {5, 0, 0,0 ,6,6 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,6,6 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,7 ,7,7 ,7, 3, 7,7, 7, 7, 7, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 }, 
					{ 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5, 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5 }
                };
                 

  
                 
                 
        int i, j;
         
       for(i=0 ;i<f; i++)
        {
            for(j=0; j<c; j++)
            {
                if(nivel==1)
                {
                 mapa[i][j]=aux[i][j];
                }
               

            }
        }
}



void diamantes(){
	
	int aux1=0, aux2=0;
	int vec1[5], vec2[5];
	
	for(int i=0; i<5; i++)
	{
			aux1=rand()%29-3;
			aux2=rand()%29-3;	
		
			vec1[i]=aux1;
			vec2[i]=aux2;
	}
	

	for(int i=0; i<5; i++)
	{
		cursor(vec1[i], vec2[i]);
		printf("%c", 04);
	}
	
}

void imprimir(int mapa[f][c])
{
    int x, y;
     
    for(x=0; x<f; x++)
    {
        printf("\n");
        for(y=0; y<c; y++)
        {
            if(mapa[x][y]==0)
                printf("%c", 178);
            if(mapa[x][y]==5)
                printf("%c", 254);
            if(mapa[x][y]==2)
                printf("%c", 16);
            if(mapa[x][y]==7)
            	printf(" ");
            if(mapa[x][y]==6)
            	printf("%c", 04);
            if(mapa[x][y]==3)
            	printf("%c", 02);
     
        }
    }
}



void jugar(int mapa[f][c], int nivel)
{
    int fp=2, cp=2, puntaje=0, f_e=2, c_e=7;
    char tecla;
    //diamantes();
	cursor(40, 2);
	printf("\tSCORE: %d", puntaje);
	if(kbhit){
		
    while(tecla!='x')
    {
    	
    	
        tecla=getch();
       	if(tecla=='x')
    		exit(0);
      
		mapa[fp][cp]=7;
		mapa[f_e][c_e]=3;

       
        if(tecla== 'd' && (mapa[fp][cp+1]==0 || mapa[fp][cp+1]==7 || mapa[fp][cp+1]==6))
        {
            cp++;
            
        }
         
        if(tecla== 'a' && (mapa[fp][cp-1]==0  || mapa[fp][cp-1]==7 || mapa[fp][cp-1]==6))    
        {
            cp--;
              
        }
         
        if(tecla== 's' && (mapa[fp+1][cp]==0 || mapa[fp+1][cp]==7 || mapa[fp+1][cp]==6))
        {
            fp++;
            
        }
         
        if(tecla== 'w' &&  (mapa[fp-1][cp]==0 || mapa[fp-1][cp]==7 || mapa[fp-1][cp]==6))
        {
            fp--;
        	
        }
        
      
        if(mapa[fp][cp]==6)
        {
        	puntaje+=10;
		}
		
		if(puntaje== 160 )
		{
			/*cursor(15, 15);
     		printf("GANASTE!!!");
     		break;*/
     		system("cls");
            nivel++;
            construir(mapa, nivel);
            imprimir(mapa);
		}
     
     	//enemigo
    if(kbhit)
    {
    if(mapa[f_e][c_e+1]==7)
     	{
     	
     		cursor(f_e, c_e);
     		printf(" ");
     		c_e++;
     		//cursor(f_e, c_e++);
     		//printf("%c", 02);
     		
		 }	
		  if(mapa[f_e][c_e+1]==7)
     	{
     	
     		cursor(f_e, c_e);
     		//printf(" ");
     		mapa[f_e][c_e]=7;
     		system("cls");
     		c_e++;
     		//cursor(f_e, c_e++);
     		//printf("%c", 02);
     
		 }
	}
     	
     
     	//
     	if(mapa[fp][cp+1]==3 || mapa[fp][cp-1]==3  || mapa[fp+1][cp]==3  || mapa[fp-1][cp]==3)
     	{
     		cursor(15, 15);
     		printf("GAME OVER\n\t\tpresione una letra..");
     		system("pause>null");
     		system("cls");
     		creditos();
     		break;
		 }
     	
        mapa[fp][cp]=2;
      
        if(mapa[fp][cp]==6)
        {
        	 system("cls"); 
	     	imprimir(mapa);
	     	//diamantes();
	     	cursor(40, 2);
			printf("\tSCORE: %d", puntaje);
		}
	else
		{
			 system("cls"); 
	     	imprimir(mapa);
	     	//diamantes();
	     	cursor(40, 2);
			printf("\tSCORE: %d", puntaje);
		}
      
        Sleep(120);
   	
		}
	}
}

void creditos()
{
system("cls");
printf("FIN DEL JUEGO");
printf("\nDIGGER ALPHA 1.1\nGRACIAS POR JUGAR\nUNET 2016");
system("pause>null");


}
