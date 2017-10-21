#ifndef   __GAME_H__
#define   __GAME_H__

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char arr[ROW][COL], int row, int col);
void Display(char arr[ROW][COL], int row, int col);
void Manplay(char arr[ROW][COL], int row, int col);
char is_Win(char arr[ROW][COL], int row, int col);
void Computerplay(char arr[ROW][COL], int row, int col);

#endif  //__GAME_H__
