#include "game.h"

void game()
{
	char ret = ' ';
	char Board[ROW][COL] = { 0 };
	InitBoard(Board, ROW, COL);
	Display(Board, ROW, COL);
	srand((int) time(NULL));
	while (1)
	{
		Manplay(Board, ROW, COL);
		Display(Board, ROW, COL);
		ret = is_Win(Board, ROW, COL);
		if (ret != ' ')
			break;
		Computerplay(Board, ROW, COL);
		Display(Board, ROW, COL);
		ret = is_Win(Board, ROW, COL);
		if (ret != ' ')
			break;
	}
	if (ret == 'X')
		printf("这局玩家胜利\n");
	else if (ret == 'O')
		printf("这局电脑胜利\n");
	else if (ret == 'w')
	{
		printf("平局\n");
	}

	
}

void menu()
{
	printf("**********************************\n");
	printf("***** 1. play       2. exit ******\n");
	printf("**********************************\n");
}

void test()
{
	do
	{
		menu();
		printf("请选择：");
		int input = 0;
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			exit(0);
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (1);
}

int main()
{
	test();
}
