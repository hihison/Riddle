#include <stdio.h>
#include <stdlib.h>
#define MAX 90
#include <string.h>
#include <dos.h>
#include <iostream>
#include <unistd.h>
#include <time.h>

void delay(int sec) 
{ 
	time_t _t; 
	_t = time (NULL); // ?????? 
	while(time (NULL) <= _t + sec){}; // ????? 
} 
int readfile (){
	FILE *fPtr;
	int read;
    fPtr = fopen("user_profile/data.txt", "r");
    fscanf(fPtr, "%d", &read);
    fclose(fPtr);
     
    printf("recent score : %d", read);
     
    return read;
}

void savefile (int score){
	FILE *fPtr;
    fPtr = fopen("user_profile/data.txt", "w");
    fprintf(fPtr, "%d", score);
    fclose(fPtr);
    //return 0;
}

void str_low(char *str1, char *strlow){
int i=0,temp=0;
for (int j = 0  ; j <= strlen(str1)-1; j++ ){
	
	if (str1[j]>=97 || str1[j]<=63) strlow[i++] = str1[j]; 
		else {
		temp=str1[j]+32;
		strlow[i++]=temp;
		}
	}strlow[i]='\0';
}


int str_check(char *str1, char *strck){
int i=0,wrong=0; int temp;
for (int j = 0  ; j <= strlen(str1)-1; j++ ){
	temp = strlen(str1) -1 ;
	do{ 
		if(str1[j]== strck[j]) wrong=0; else wrong=1;
	} while ( j==strlen(str1) || wrong!=1 ) ;
	}
		if (wrong==1) {
			for (int k = 0 ; k<= temp; k++) {
				
				strck[k] = '\0';
			}
		return 1;
		
		} 
		else return 0;
}

	FILE *question;		FILE *ansfile;
	char data[999], data2[999];

int  main () {
	char q[MAX][MAX] ;
	char a[MAX][MAX] ;
	char answer[MAX][MAX];
	char anslow[MAX][MAX];
	char choice;
	int counter=0;
	int score = readfile();
		question = fopen("gamedata/question.txt", "r");
		while (fgets(data,999,question)!=NULL){
			strcpy(q[counter],data);
			counter=counter+1;
		} fclose(question); 
		
		ansfile = fopen("gamedata/answer.txt", "r");

		for (int get = 0; get<=counter ; get++){
			data2[get] = fscanf(ansfile,"%s",a[get]);
		}fclose(ansfile);

	int count = 1;

	for (int i = 0 ; i <= counter-1 ; i++ ){



	do{
		system("COLOR F0");
		system("cls");
	    printf("Recent score : %d \n", score);
		printf("%s\n",q[i]);

		printf("Answer Here: ");
	
		scanf("%s",&answer[i]);
		str_low(answer[i],anslow[i]);
	
	
		printf("you typed : %s , Sure? (Y/N) \n",anslow[i]);
		scanf("%s",&choice);
		} while (choice!=89 && choice!=121);
			int iscorrect = strcmp(anslow[i],a[i]);
		
			if (iscorrect==0) {
				score=score+5;
				savefile (score);
				system("color 2F");	
				printf("you are right!\n") ;
				delay(0.2);
	
				system("color F2");	
				printf("scores + 5\n") ;
				delay(0.2);
	
				system("color 2F");	
				
				printf("You now have scores : %d  \n",score) ;
				delay(0.2);
	
				system("color F2");	
				printf("Congratulations !\n") ;
				delay(1);
			}
			 else {
			    score=score-5;
			 	savefile (score);
				system("COLOR 4F"); 	
		    	printf("Wrong, the answer is %s\n",a[i]);
 		    	delay(0.2);

			    system("COLOR F4"); 	
			    printf("Unluckly , you lose $5\n");
 			    delay(0.2);		

			    system("COLOR 4F"); 
			    printf("You now have scores : %d  \n",score) ;
 			    delay(1);	

			}
	}
	system("COLOR 61"); 	
	system("cls");
	printf("You totally have scores %d", score);
	system("pause");
	
	
}
