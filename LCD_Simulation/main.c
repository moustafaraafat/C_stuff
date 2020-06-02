#include <stdio.h>
#define MAX_DIGITS 10
const char segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};
char digits[4][4*MAX_DIGITS];
int num_digit=0;
void clear_digit_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
	char c;
	setbuf(stdout, NULL);
	printf("Enter a number: ");
	while((c=getchar()) != '\n'){
		if(c>='0' && c<= '9') {
			process_digit(c-'0', num_digit);
			num_digit++;
		}
	}
	print_digits_array();
	return 0;
}

void clear_digit_array(void){
	for(int i=0;i<4;i++)
		for(int j=0; j<4*MAX_DIGITS; j++)
			digits[i][j]=' ';
}
void process_digit(int digit, int position){
	digits[0][4*position+1]=segments[digit][0]==0? ' ': '_';
	digits[1][4*position]=segments[digit][5]==0? ' ': '|';
	digits[1][4*position+1]=segments[digit][6]==0? ' ': '_';
	digits[1][4*position+2]=segments[digit][1]==0? ' ': '|';
	digits[2][4*position]=segments[digit][4]==0? ' ': '|';
	digits[2][4*position+1]=segments[digit][3]==0? ' ': '_';
	digits[2][4*position+2]=segments[digit][2]==0? ' ': '|';
}
void print_digits_array(void){
	for(int i=0; i<4; i++){
		for(int j=0; j<4*num_digit; j++){
			putchar(digits[i][j]);
		}
		putchar('\n');
	}
}
