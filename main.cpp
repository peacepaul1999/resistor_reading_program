#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct
{
    char color[10];
    int band1,band2,band3;float band4;int band5;
} r5band;

r5band R[13] = {
 {"black" ,-1,0,0 ,1e0 ,-1},{"brown" ,1 ,1,1 ,1e1 ,1 },
 {"red" ,2 ,2,2 ,1e2 ,2 },{"orange",3 ,3,3 ,1e3 ,-1},
 {"yellow",4 ,4,4 ,1e4 ,-1},{"green" ,5 ,5,5 ,1e5 ,-1},
 {"blue" ,6 ,6,6 ,1e6 ,-1},{"purple",7 ,7,7 ,1e7 ,-1},
 {"grey" ,8 ,8,8 ,1e8 ,-1},{"white" ,9 ,9,9 ,1e9 ,-1},
 {"gold" ,-1,-1,-1,1e-1,5 },{"silver",-1,-1,-1,1e-2,10},
 {"none" ,1,1,1,1e-1,20 } };

r5band findband(char color[10])
{
   int i;
   for (i=0;i<12;i++)
   if (strcmp(color,R[i].color)==0)
   break;
   return R[i];
}

float ohm_to_kohm(float copy_r)
{
    return copy_r / 1000.0;
}

float ohm_to_mohm(float copy_r)
{
    return copy_r / 1000000.0;
}

main()
{
	char text[5][10];
   char copy_text[20];
   char unit;
   int ch = 0;
   int b1,b2,b3,b5;
   float b4,Rval;

   printf("--------- Program Reading Resistor ---------\n");

   printf("Please enter the details as follows. By defining the following words : \n\n");
   printf("black,brown,red,orange,yellow,green,blue,purple,grey,white,gold,silver \n");
   printf("**note If there is no color bar, use the word none. \n\n"); 

   for(int i=0;i<5;i++)
   {
     printf("Enter color of band #%d: ",i+1);
     scanf("%s",&text[i]);
   }

   b1 = findband(text[0]).band1;
   b2 = findband(text[1]).band2;
   b3 = findband(text[2]).band3;
   b4 = findband(text[3]).band4;
   b5 = findband(text[4]).band5;
   
   Rval=((b1*100)+(b2*10)+b3)*b4;
   float R ; 
    
   if (Rval >= 1000.0)
   {
      R = ohm_to_kohm(Rval); 
      unit = 'K';
   }
   if (Rval >= 1000000.0)
   {
      R = ohm_to_mohm(Rval); 
      unit = 'M';
   }

   printf("--------------------------------------------\n\n"); 
   printf("R = %.2f%c ohm %c%d%%",R,unit,64,b5);
   printf("\n--------------------------------------------\n"); 
   getch();
}