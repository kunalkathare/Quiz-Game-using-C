#include <stdio.h>
#include <stdlib.h>

int i, coins=0, highscore=0;
char name[20], input, ans;

void main_menu();
void correct();
void incorrect();
void play();
void high_score();
void alter_high_score();
void ask_question(int value_of_question_in_coins, char question[200] , char a[100] , char b[100] , char c[100] , char d[100] , char correct_ans_small, char correct_ans_capital);

void main()
{
	printf("Please type your name and press enter: ");
	fflush(stdin);
	gets(name);
	system("cls");
	printf("\nHello %s! \n ",name);
	printf("\n...........WELCOME TO............\n");
	printf("\n...........QUIZ GAME!............\n");
	main_menu();	
}

void main_menu()
{	
	char menu;
	printf("\n\n    MAIN MENU\n\n");
	printf("    Key    Function\n\n");
	printf("    P      Play\n");
	printf("    R      Rules\n");
	printf("    C      Credits\n");
	printf("    H      High score\n");
	printf("    E      Exit\n\n");
	printf("    Please type an input and press enter-");
	fflush(stdin);
	scanf("%c",&input);
	
	switch(input)
	{
		case 'P':  
		case 'p':
				system("cls");
				play();
	       		break;
	       		
	 	case 'R':
		case 'r':
				system("cls");
				printf("RULES:\n\nThe rules of the game are simple.\n\n");
				printf("The player is presented with a question having four options each.\n\n");
				printf("Each question carries a particular number of coins.\n\n");
				printf("The number of coins associated with each question is more than the number of coins carried by the previous one.\n\n");
				printf("Correct answer rewards the player with the coins associated with the question.\n\n");
				printf("An incorrect answer would lead to losing the game and the coins associated with the question.\n\n");
				printf("Press M to go to the main menu.\n");
				fflush(stdin);
				scanf("%c",&menu);
				
				if(menu=='m' || menu=='M')
				{
					system("cls");
					main_menu();
				}
	   			
	   			else
	   			{
					system("cls");
					printf("illegal input");
					main_menu();
				}
	   						
				break;
	   			
		case 'C':  
		case 'c':	
				system("cls");
				printf("\nThis program was made by Kunal, Durgesh & Kshitij.\n\n");
				printf("Press M to go to the main menu. ");
				fflush(stdin);
				scanf("%c",&menu);
				
				if(menu=='m' || menu=='M')
				{
					system("cls");
					main_menu();
				}
				else 
				{
					system("cls");
					printf("illegal input");
					main_menu();
				
				}
				
				break;
				
		case 'H': 
		case 'h':
				system("cls");
				high_score();
				printf("\n\nPress M to go back to the main menu. ");
				fflush(stdin);
				scanf("%c",&menu);
				
				if(menu=='m' || menu=='M')
				{
					system("cls");
					main_menu();
				}
				else 
				{
					system("cls");
					printf("illegal input");
					main_menu();
				
				}
				
				break;
				
		case 'E':  
		case 'e':
				printf("\nAre you sure you want to exit?[y-->exit/n-->back to main menu] ");	
				fflush(stdin);
				scanf("%c",&menu);
				
				if(menu== 'y' || menu=='Y')
				{	
					system("cls");
					printf("\nThank you for playing!");
					exit(0);
				}	
				else if(menu== 'N' || menu=='n')
				{
					system("cls");
					main_menu();
				}
				else 
				{
					system("cls");	
					printf("illegal input");
					main_menu();		
				}				
				
				break;
				
				
		default:system("cls");	
				printf("illegal input!\n\nPress E to exit\n\nPress any other key to go to main menu.");
				fflush(stdin);
				scanf("%s",&input);
				
				if(input== 'E' || input== 'e')
				{
					system("cls");
					exit(0);
				}
				else
				{
					system("cls");
					main_menu();		
				}
				break;			
	}	
}

void correct()
{
	printf("\n\nCorrect!\n\nScore=%d coins\n\nPress M to go to main menu.\n\nPress any other key to continue. ",coins);
	fflush(stdin);
	scanf("%c",&ans);
		
	if(ans =='m' || ans=='M')
	main_menu();
	else
	system("cls");
}
	
void incorrect()
{
		system("cls");
		printf("Your response is incorrect.\n");
		alter_high_score();
}
		

void high_score()
{
	FILE *fp1, *fp2;
	char ch;
	fp1=fopen("quiz_highscore.txt","r");
	fp2=fopen("quiz_highscore_holder.txt","r");
	
	if(fp1==NULL)
	printf("\n\nCannot open target file. Contact the developer.");
	
	printf("\nCurrent highscore is ");
	
	while((ch=getc(fp1))!=EOF)
	printf("%c",ch);
	
	printf(" coins.\nThis amazing feat was archieved by ");
	
	while((ch=getc(fp2))!=EOF)
	printf("%c",ch);
	
	printf(".");
	
	fclose(fp1);
	fclose(fp2);
	
}	
	
void alter_high_score()
{	
   FILE *fp, *fp1, *fp2;  
   char highscore_as_char[10];
   
   fp= fopen("quiz_highscore.txt", "r");  

   while(fscanf(fp, "%s", highscore_as_char)!=EOF)
   {  
   		//printf("%s ", buff );  
   }   
   
   highscore = atoi(highscore_as_char);
   
   if(coins>highscore)
   {
   		highscore=coins;
   		printf("\n\n************************************\nCongratulations %s!\nYou have made a new highscore of %d coins !\n************************************",name,coins);
   	
		fp1=fopen("quiz_highscore.txt","w");
		fp2=fopen("quiz_highscore_holder.txt","w");
	
		if(fp1==NULL || fp2 ==NULL)
		printf("\n\nCannot open target file. Contact the developer.");
		else
		{
			fprintf(fp1,"%d",coins); 
			fprintf(fp2,"%s",name); 				
		}
		
		   fclose(fp1);  
   	       fclose(fp2); 
   		}
   else if(coins<highscore)
   {
   		printf("\n\nYou have earned %d coins but that is not enough to beat the highscore...\nTry again!",coins);
   }
   else if(coins=highscore)
   {
   		printf("\n\n*****************************************\nYou have earned %d coins %s.\nThat is the same as the current highscore!\n*****************************************",coins,name);
   }
    
    printf("\n\npress E to exit.\n\nPress any other key to go back to main menu.");
    fflush(stdin);
	scanf("%s",&input);
				
	if(input== 'E' || input== 'e')
	{
		system("cls");
		exit(0);
	}
	else
	{
		system("cls");
		main_menu();		
	}
		
}

void ask_question(int value_of_question_in_coins,char question[100] , char a[50] , char b[50] , char c[50] , char d[50] , char correct_ans_small, char correct_ans_capital)
{
	printf("\nFor %d coins\n\nQuestion: %s?\n\nA)%s\n\nB)%s\n\nC)%s\n\nD)%s\n\nType your response and press enter-", value_of_question_in_coins, question, a, b, c, d);	
	fflush(stdin);
	scanf("%c",&ans);
	
	if(ans == correct_ans_capital || ans == correct_ans_small)
	{
		coins= coins+ value_of_question_in_coins;
		correct();
	}
	else
	{
		incorrect();
	}
}
	
void play()
{	
	ask_question(10,"What is the capital of India?", "Islamabad", "Delhi" , "Mumbai", "Jaipur", 'b', 'B');
	ask_question(20,"What is the capital of Nepal?", "Padampuri", "Newai", "Kathmandu", "Kumaribadi", 'c', 'C');
	ask_question(40,"Who was the first Indian to go to space?", "Rakesh Verma", "Rakesh Sharma", "Rakesh Shrivastav", "Rakesh J. Sharma", 'b', 'B');
	ask_question(100,"What hich of the following is not a fruit?", "Tomatoe", "Onion", "Apple", "Grape", 'b', 'B');
	ask_question(250,"What was the surname of the famous physist Stephan?", "Harvins", "Hawkings", "Hawkins", "Hawking", 'd', 'D');
	ask_question(600,"What is India's highest civillian honour?", "Paramveer chakra", "Bharat Ratna", "Mahaveer Ratna", "Tejaswi Chakra", 'b', 'B');
	ask_question(1000,"Who is also called the \"Missile man\" of India?", "Abdul kalam Azad", "A.P.J. Abdul Kalam Azad", "A.P.J Abdul Kalam", "Abdul Kalam", 'c', 'C');
	ask_question(2500,"What is the real colour of sunlight?", "White", "Blue", "Yellow", "Colourless", 'a', 'A');
	ask_question(5000,"What was Mahatma Gandhi\'s middle name?", "Karamvir", "Karamdas", "Karamchandra", "Karamkhot", 'c', 'C');
	ask_question(7500,"Why does most part of earth look blue from the space?", "Because clouds and sky are blue", "Because of god\'s will", "No one knows", "Because a large part of earth is covered in water", 'd', 'D');

}