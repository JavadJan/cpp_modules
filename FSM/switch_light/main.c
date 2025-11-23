#include <stdio.h>

enum state {
	OFF,
	ON
};

int main()
{
	enum state swtch = OFF;
	printf("Enter 1 to turn \033[1;32mON\033[0m, Enter 0 to turn \033[1;31mOFF\033[0m\n");
	int input = -1;
	while (1)
	{
		printf("current state: %s\n", swtch == OFF ? "\033[1;31mOFF\033[0m" : "\033[1;32mON\033[0m");
		scanf("%d", &input);
		switch (swtch)
		{
		case ON:
		{
			if (input == 1)
			{
				printf("Light is already on\n");
			}
			else if (input == 0)
			{
				printf("Light tured OFF\n");
				swtch = OFF;
			}
			else
			{
				printf("Invalid input, press 0 or 1\n");
			}
			break;
		}
		case OFF:
		{
			if (input == 0)
			{
				printf("Light is already OFF\n");
			}
			else if (input == 1)
			{
				printf("Light tured ON\n");
				swtch = ON;
			}
			else
			{
				printf("Invalid input, press 0 or 1\n");
			}
			break;
		}
		default:
			break;
		}
	}
}