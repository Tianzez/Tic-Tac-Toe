#include "game.h"


void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			arr[i][j] = ' ';
		}
	}
}

void Display(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; ++i)
	{
		printf(" %c | %c | %c \n",arr[i][0],arr[i][1],arr[i][2]);
		if (i != row - 1)
		{
			printf("--- --- ---\n");
		}
	}
	printf("\n");
}

void Manplay(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("请输入坐标（x，y）：");
		scanf_s("%d%d", &i, &j);
		if (i >= 1 && i <= 3 && j >= 1 && j <= 3)
		{
			if (arr[i - 1][j - 1] == ' ')
			{
				arr[i - 1][j - 1] = 'X';
				break;
			}
			else
			{
				printf("该位置被占\n");
			}
		}
		else
		{
			printf("坐标不合法\n");
		}
	}
}

int is_Full(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char is_Win(char arr[ROW][COL], int row, int col)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < row; i++) //判断行
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && (arr[i][1]) != ' ')
		{
			return arr[i][1];
		}
	}
	for (i = 0; i < row; i++) //判断列
	{
		if ((arr[0][j] == arr[1][j]) && (arr[1][j] == arr[2][j]) && (arr[1][j]) != ' ')
		{
			return arr[1][j];
		}
	}
	
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && (arr[0][0] != ' ')) //判断斜列
	{
		return arr[1][1];
	}
	else if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) && (arr[0][0] != ' '))
	{
		return arr[1][1];
	}
	else if (is_Full(arr, row, col) == 1)
	{
		return 'w';
	}
	else
	{
		return ' ';
	}
}

void Computerplay(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
		if (arr[i][j] == ' ')
		{
			arr[i][j] = 'O';
			break;
		}
	}
	system("cls");
}
