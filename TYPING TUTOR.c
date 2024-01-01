#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>   //line 238..
typedef struct report{
	int timetaken;
	int accuracy;
	struct report *next;
}report; //self referntial structure..

report *head = NULL;

int begin();
void progress();
void knowmore();
void nextwork();
void choices();
void store(report *);

void store(report *ptr)
{
	head = ptr;
	head = NULL;	
}
void purple()
{
	printf("\033[0;35m");
}
void yellow()
{
	printf("\033[0;33m");
}
void red()
{
	printf("\033[0;31m");
}
void blue()
{
	printf("\033[0;34m");
}
void green()
{
	printf("\033[0;32m");
}
void cyan()
{
	printf("\033[0;36m");
}

int homepage(void)
{
	purple();
	
	printf("WELCOME TO THE TYPING TUTOR!!");
	
	printf("\n\nWE WILL LET YOU KNOW  ABOUT YOUR TYPING SKILLS \n");	
	yellow();
	printf("\nENTER YOUR CHOICE.SELECT ANY NUMBER FROM 1 TO 4.\n");
	
	choices();	
}
void erase()
{
	FILE *clr;
	fopen("progress.txt","w");
	red();
	printf("All the progress has been erased.");
	printf("\n\n");
	nextwork();
}
void progress()
{
	FILE *prog;
	prog = fopen("progress.txt","r");
	char ch ;
	green();
	printf("NAME    LEVEL    CORRECT WORDS    INCORRECT WORDS   WPM    ACCURACY     DATE ");
	printf("\n\n");
	
	blue();
	while ((ch=getc(prog))!=EOF)
	{
		printf("%c",ch);
		
	}
	printf("\n\n");
	nextwork();
}
	

void choices() //1ST..
{
	int c;
	yellow();
	printf("\n1. Begin\n2.View your progress\n3. Erase all progress\n4. More about typing tutor\n\n");
	scanf("%d", &c);
	system("cls");
	switch(c){
        	case 1: begin();
        	        break;
		    case 2: progress();
			        break;
		    case 3: erase();
			        break;
        	case 4: knowmore();
                	break;
        	default:
			       printf("Please enter a valid option");
			choices();
    	}
}
int begin()
{
	int correct=0, wrong=0, i, x, timetaken;
	clock_t start, end;
	char a[1000], c ;
	char name[50] ; 
	int WPM ;
	int accuracy ;
	printf("Please enter your name: ");
	printf("\n\n");
	blue();
	scanf("%s",&name);
	sleep(1);
	system("cls");
	green();
	printf("Enter the mode.Select any number from 1 to 3.");
	printf("\n\n1. Easy \n2.Normal\n3.Hard\n");
	int o ; 
	scanf("%d",&o);
	system("cls");
	red();
	char k[] = "Gokaraju Lailavathi Womens Engineering College  is the sister concern of Gokaraju Rangaraju Institute of Engineering and Technology established in 2021 by Dr. G Gangaraju as a self-financed institute under the aegis of Gokaraju Rangaraju Educational Society with the sole purpose of promoting quality education. \n\n";
	char l[] = "Information technology (IT) is the use of any computers, storage, networking and other physical devices, infrastructure and processes to create, process, store, secure and exchange all forms of electronic data. \nTypically, IT is used in the context of business operations, as opposed to technology used for personal or entertainment purposes. \nThe commercial use of IT encompasses both computer technology and telecommunications.Although humans have been storing, retrieving, manipulating, and communicating information.  ";
	char b[] = "Information Technology in India is a vast industry which comprises information technology services, consulting, and outsourcing.\nThe IT industry accounted for 8% of India's GDP in 2020. The IT and BPM industry's revenue is estimated at US$ 227 billion in FY 2022, an increase of 15.5% YoY.\n The domestic revenue of the IT industry is estimated at US$ 49 billion and export revenue is estimated at US$ 178 billion in FY 2022. \nThe IT industry employed almost 0.5 million employees in FY 2022. The IT–BPM sector overall employs 5 million people as of March 2022.The Indian IT/ ITeS industry has a leading position globally and has been progressively contributing to the growth of exports and creation of employment opportunities. \n\n";
	
	printf("Enter the following words as it is as fast as you can:\n\n");
	sleep(1);
	switch(o)
	{
		case 1 :{
			
		 puts(k);
		        printf("\n\n");
		         start = clock();
		         blue();
		        scanf(" %[^\n]s", a);
	            printf("\n\n");
               	system("cls");
	            end= clock();
	            x = strlen(k);
	            int y = strlen(a);
	            for(i = 0 ; i < x ; i++){
	            if (a[i] == k[i])
	            correct++;
	            else
	            wrong++;
	}
	            timetaken = (int)(end-start) / CLOCKS_PER_SEC;
	
	            report *ptr;
	
	            ptr = (report*)malloc(sizeof(report*));
 	            ptr->timetaken = timetaken;
	
	            accuracy = (100*correct)/(correct+wrong);
	            WPM = y / timetaken ;
		         break;
		}
		case 2 :{
		
				puts(l);
		        printf("\n\n");
		        start = clock();
		         blue();
		        scanf(" %[^\n]s", a);
	            printf("\n\n");
	            system("cls");
	            end= clock();
	             x = strlen(l);
	             int p = strlen(a);
             	for(i = 0 ; i < x ; i++){
	                   if (a[i] == l[i])
	                   correct++;
	                else
	    
		
		           wrong++;
	
	}
	            timetaken = (int)(end-start) / CLOCKS_PER_SEC;
	
				report *ptr;
	
	            ptr = (report*)malloc(sizeof(report*));
	            ptr->timetaken = timetaken;
	
	           accuracy = (100*correct)/(correct+wrong);
	           WPM = p / timetaken ;
	           
		         break;
		
		}
		case 3 :{
		
				 puts(b);
		         printf("\n\n");
		         start = clock();
		         blue();
		         scanf(" %[^\n]s", a);
	             printf("\n\n");
	            system("cls");
	            end= clock();
	            x = strlen(b);
	            int r = strlen(a);
	           for(i = 0 ; i < x ; i++){
	                  if (a[i] == b[i])
	                correct++;
	                 else
	               wrong++;
	}
	timetaken = (int)(end-start) / CLOCKS_PER_SEC;
	
	report *ptr;
	
	ptr = (report*)malloc(sizeof(report*));
	ptr->timetaken = timetaken;
	
	accuracy = (100*correct)/(correct+wrong);
	WPM = r / timetaken ;
		         break;
	}
	}
	
	
	
	green(); 
	printf("CORRECT WORDS: %d\n\nINCORRECT WORDS: %d\n\nWPM: %d\n\nACCURACY: %d%%\n\n",correct,wrong,WPM,accuracy);
	time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
	FILE *pg;
	pg = fopen("progress.txt","a");
	fprintf(pg,  "%s\t%d\t\t%d\t\t%d\t     %d\t\t%d\t%d-%d-%d\n",name,o,correct,wrong, WPM, accuracy, tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	fclose(pg);	
	printf("\n\n");
	nextwork();	
}
void knowmore()
{
	FILE *fp ;
	fp = fopen("knowmore.txt","r");
	char info[1000];
	red(); 
	printf("**TYPING TUTOR***");
	printf("\n\n");
	cyan();
    while ( fgets( info, 1000, fp ) != NULL ) 
    { 
        printf("%s", info); 
    } 
    printf("\n\n");
    nextwork();
   
	
}
void nextwork()
{
	int c;
	yellow();
	printf("Do you want to continue?(1/0)");
	printf("\nEnter 1 for continue and 0 for choices..");
	scanf("%d", &c);
	switch(c){
		case 1: begin();
			break;
		case 0: choices();
			break;
		default:printf("wrong input");
			//nextwork();
			
	}
}

int main(void)
{
        homepage();
        return 0;
}