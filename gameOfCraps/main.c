#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


int roll_dice(void);
bool play_game(void);
int main(void) {
	int lose=0, win=0, game;
	char c;
	setbuf(stdout, NULL);
	srand((unsigned)time(NULL));
	game = play_game();
	while(1){
		if(game == true){
			printf("You win!\n\n");
			win++;
		}
		else{
			printf("You lose!\n\n");
			lose++;
		}
		printf("Play again? ");
		scanf(" %c",&c);
		if(c == 'y' || c == 'Y') printf("\n");
		else if(c == 'n' || c == 'N'){
			printf("\nWins: %d  Loses: %d\n", win, lose);
			break;
		}
		game = play_game();
	}


	return 0;
}

int roll_dice(void){
	int roll;
	roll = rand() % 6 + 1;
	roll += rand() % 6 + 1;
	printf("You rolled: %d\n", roll);
	return roll;
}
bool play_game(void){
	int roll= roll_dice(), roll2;
	switch (roll){
	case 7: case 11: return true;
	case 2: case 3: case 12: return false;
	default: {
		printf("Your point: %d\n", roll);
		while(1){
			roll2=roll_dice();
			if(roll2==roll) return true;
			else if(roll2==7) return false;
		}
	}
	}

}
