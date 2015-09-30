#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Engine.h"

#define ENGINE_ERROR_NONE 0
#define ENGINE_ERROR_INVALID_PARAMETER -1
#define ENGINE_ERROR_FILE_OPEN_FAIL -2
#define ENGINE_ERROR_NULL_POINTER -3

int answer[3] = { 0, };
int generateNumber()
{
	int i, j;
	
	srand(time(NULL));
	
	for (i = 0; i < 3; i++)
	{
		answer[i] = rand() % 10;
		for (j = 0; j < i; j++)
			if (answer[i] == answer[j])
				i--;
	}
	//printf("generated Number : %d%d%d\n", answer[0], answer[1], answer[2]);
	return ENGINE_ERROR_NONE;
}

hint checkAnswer(int input)
{
	int i, j;
	int targetNumber[3] = { input / 100, (input % 100) / 10, ( (input % 100) % 10 ) / 1 };
	int ball = 0;
	int strike = 0;
	int isAnswer = 0;
	hint Hint = {input, ball, strike, isAnswer };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (targetNumber[i] == answer[j])
			{
				if (i == j) Hint.strike++;
				else Hint.ball++;
			}
		}
	}
	if (Hint.strike == 3)
		Hint.answer = 1;

	return Hint;
}

int initEngine(engine* Engine)
{
	if (NULL == Engine)
		return ENGINE_ERROR_NULL_POINTER;

	Engine->generateNumber = generateNumber;
	Engine->checkAnswer = checkAnswer;

	return ENGINE_ERROR_NONE;
}