#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char color[10];
    int band1,band2,band3;float band4;int band5;
} r5band;

r5band R[13] = {
 {"black" ,-1,0,0 ,1e0 ,-1},{"brown" ,1 ,1,1 ,1e1 ,1},
 {"red" ,2 ,2,2 ,1e2 ,2 },{"orange",3 ,3,3 ,1e3 ,-1},
 {"yellow",4 ,4,4 ,1e4 ,-1},{"green" ,5 ,5,5 ,1e5 ,-1},
 {"blue" ,6 ,6,6 ,1e6 ,-1},{"purple",7 ,7,7 ,1e7 ,-1},
 {"grey" ,8 ,8,8 ,1e8 ,-1},{"white" ,9 ,9,9 ,1e9 ,-1},
 {"gold" ,-1,-1,-1,1e-1,5},{"silver",-1,-1,-1,1e-2,10}};

r5band findband(char color[10])
{
   int i;
   for (i=0;i<12;i++)
   if (strcmp(color,R[i].color)==0)
   break;
   return R[i];
}

char text[5][10];
char unit;

int b1=0,b2=0,b3=0,b5=0;
float b4=0.0,Rval=0.0;

float ohm_to_kohm(float copy_r)
{
    return copy_r / 1000.0;
}

float ohm_to_mohm(float copy_r)
{
    return copy_r / 1000000.0;
}

void four_band_cal(int status)
{
   system("cls");
   printf("--------- Program Reading Resistor(4-band) ---------\n");
   printf("Please enter the details as follows. By defining the following words : \n\n");
   printf("black,brown,red,orange,yellow,green,blue,purple,grey,white,gold,silver \n\n");

   for(int i=0;i<status;i++)
   {
     printf("Enter color of band #%d: ",i+1);
     scanf("%s",&text[i]);
   }

   b1 = findband(text[0]).band1;
   b2 = findband(text[1]).band2;
   b3 = findband(text[2]).band4;
   b5 = findband(text[3]).band5;

   Rval=((b1*10)+b2)*b3;

   float R=0.0 ; 
    
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

}

void five_band_cal(int status)
{
   system("cls");
   printf("--------- Program Reading Resistor(4-band) ---------\n");
   printf("Please enter the details as follows. By defining the following words : \n\n");
   printf("black,brown,red,orange,yellow,green,blue,purple,grey,white,gold,silver \n\n");

   for(int i=0;i<status;i++)
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

   float R=0.0 ; 
    
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

}

main()
{
	int ch = 0;

   fl:
   printf("--------- Program Reading Resistor ---------\n");
   printf("Please select the following options \n");
   printf("1. Read the 4-band resistor value \n");
   printf("2. Read the 5-band resistor value. \n");
   printf("3. Exit to Program \n");
   printf("Select to :");
   scanf("%d",&ch);

   switch(ch)
   {
      case 1 : four_band_cal(4);              
               break;
      case 2 : five_band_cal(5);
               break;
      case 3 : goto ex; break;
      default: system("cls");  
               printf("Program Error ");
               goto fl;
   }
   
   ex:
   printf("\n--------------- Thank You ------------------\n");
   getch();
}