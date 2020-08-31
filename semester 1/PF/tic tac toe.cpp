#include <stdio.h>
#include <conio.h>

void board(char box[]);
int conditiontowin(char box[]);

int main()
{
	int player = 1, choice, c, GT;
	char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char symbol;
	
	printf("\t\t\t\t\t\tTic Tac Toe\n\n\n\t\t\t\t\tPlayer 1 = X & Player 2 = O\n\n\n\n");
	printf("Game Type:\n\n\n1: User Vs User\n2: User Vs Computer");
	printf("\n\n\nEnter Game Type(1/2): ");
	scanf("%d", &GT);
	
	switch(GT)
	{
		case 1:
			{
				do
	            {
		            board(box);
		            if(player%2)
		            {
			            player = 1;
		            }
		            else
		            {
			            player = 2;
		            }
		            
			        printf("\n\n\t\t\t\t\t  Player(%d) Proceed(1-9): ", player);
		            scanf("%d", &choice);
		            
		            if(player == 1)
		            {
			            symbol = 'X';
		            }
		            else
		            {
			            symbol = 'O';
		            }
		
		            if(choice == 1 && box[1] == '1')
		                box[1] = symbol;
			
		            else if(choice == 2 && box[2] == '2')
		                box[2] = symbol;
			
		            else if(choice == 3 && box[3] == '3')
		                box[3] = symbol;
			
		            else if(choice == 4 && box[4] == '4')
		                box[4] = symbol;
			
		            else if(choice == 5 && box[5] == '5')
		                box[5] = symbol;
			
		            else if(choice == 6 && box[6] == '6')
		                box[6] = symbol;
			
		            else if(choice == 7 && box[7] == '7')
		                box[7] = symbol;
			
		            else if(choice == 8 && box[8] == '8')
		                box[8] = symbol;
			
		            else if(choice == 9 && box[9] == '9')
		                box[9] = symbol;
		
		            else
		            {
			            printf("Invalid Move.");
			        player--;
		            }
		
		            player++;
		            c = conditiontowin(box);
		
	            }while(c == -1);
	            break;
			}
		case 2:
			{
				do
	            {
		            board(box);
		            if(player%2)
		            {
			            player = 1;
		            }
		            else
		            {
			            player = 2;
		            }
		            if(player == 1)
		            {
			            printf("\n\n\t\t\t\t\t  Player(%d) Proceed(1-9): ", player);
		                scanf("%d", &choice);
		            }
		            else
		            {
			            srand(time(NULL));
			            choice = rand()%9 + 1;
		            }
		
		            if(player == 1)
		            {
			            symbol = 'X';
		            }
		            else
		            {
			            symbol = 'O';
		            }
		
		            if(choice == 1 && box[1] == '1')
		                box[1] = symbol;
			
		            else if(choice == 2 && box[2] == '2')
		                box[2] = symbol;
			
		            else if(choice == 3 && box[3] == '3')
		                box[3] = symbol;
			
		            else if(choice == 4 && box[4] == '4')
		                box[4] = symbol;
			
		            else if(choice == 5 && box[5] == '5')
		                box[5] = symbol;
			
		            else if(choice == 6 && box[6] == '6')
		                box[6] = symbol;
			
		            else if(choice == 7 && box[7] == '7')
		                box[7] = symbol;
			
		            else if(choice == 8 && box[8] == '8')
		                box[8] = symbol;
			
		            else if(choice == 9 && box[9] == '9')
		                box[9] = symbol;
		
		            else
		            {
			            printf("Invalid Move.");
			        player--;
		            }
		
		            player++;
		            c = conditiontowin(box);
		
	            }while(c == -1);
	            break;
			}
		default:
			{
				printf("There Is No Another Game Type.");
				break;
			}
	}
	

    board(box);
    
    if(c == 1)
    {
    	player = --player;
    	if(player == 1)
    	{
    		printf("\n\n\t\t\t\t\t\tPlayer(%d) Wins!\n\n\n", player);
		}
    	else if(player == 2)
    	{
    		printf("\n\n\t\t\t\t\t\tComputer Wins!\n\n\n");
		}
	}
	else
	{
		printf("\n\n\t\t\t\t\t\tThe Game Is Drawn!");
	}
}

void board(char box[])
{
	system("cls");
	
	printf("\t\t\t\t\t\tTic Tac Toe\n\n\n\t\t\t\t\tPlayer 1 = X & Player 2 = O\n\n\n\n");
	
	printf("\t\t\t\t\t\t|\t|\t\n\t\t\t\t\t\t|\t|\t\n");
	
	printf("\t\t\t\t\t    %c\t|   %c\t|   %c\n", box[1], box[2], box[3]);
	printf("\t\t\t\t\t________|_______|________\n");
	
	printf("\t\t\t\t\t\t|\t|\t\n\t\t\t\t\t\t|\t|\t\n");
	printf("\t\t\t\t\t    %c\t|   %c\t|   %c\n", box[4], box[5], box[6]);
	
	printf("\t\t\t\t\t________|_______|________\n");
	printf("\t\t\t\t\t\t|\t|\t\n\t\t\t\t\t\t|\t|\t\n");
	
	printf("\t\t\t\t\t    %c\t|   %c\t|   %c\n", box[7], box[8], box[9]);
	printf("\t\t\t\t\t\t|\t|\t\n");
}

int conditiontowin(char box[])
{
	if((box[1] == box[2] && box[2] == box[3]) || (box[4] == box[5] && box[5] == box[6]) || (box[7] == box[8] && box[8] == box[9])
	|| (box[1] == box[5] && box[5] == box[9]) || (box[3] == box[5] && box[5] == box[7]) || (box[1] == box[4] && box[4] == box[7])
	|| (box[2] == box[5] && box[5] == box[8]) || (box[3] == box[6] && box[6] == box[9]))
	{
		return 1;
	}
	else if(box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] !='5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

