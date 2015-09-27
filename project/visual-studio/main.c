#include<stdio.h>
#include "main.h"
#include "HistoryRecorder.h"
#include "Engine.h"
#include "SystemManager.h"
#include "ErrorDefine.h"

void showMenu()
{
	int selectMenu = 0;

	while (1)
	{
		printf("** Bulls And Cows **\n");
		printf("  1. Start Game\n");
		printf("  2. Exit Game\n");

		printf(" [] select Number : ");
		scanf("%d", &selectMenu);
		clearEnter();

		switch (selectMenu)
		{
			case 1:
				startGame();
				break;
			case 2:
				exitGame();
				exit(0);
				break;
			default:
				printf("[Error] Invalid value selected!\n");
				showMenu();
				break;
		}
	}
}

int startGame()
{
	int i=1;
	int number = -1;
	hint Hint = { -1, -1, -1, -1 };
	engine* Engine = createEngeine();
	histroyRecorder* HistoryManager = createHistroyRecorder();

	if (ERR_NULL_POINTER == initEngine(Engine))
	{
		printf("Init Engine failed!\n");
		exit(1);
	}

	if (ERR_NULL_POINTER == initHistoryRecorder(HistoryManager))
	{
		printf("Init HistoryManager failed! - File open failed!\n");
		exit(1);
	}

	Engine->generateNumber();

	while (Hint.answer != 1)
	{
		printf("\nGuess Number('0' for exit game) : ");
		scanfForAnswer(&number);
		Hint = Engine->checkAnswer(number);

		switch (number)
		{
			case 0:
				exitGame();
				showMenu();
				break;
			case ERR_INVALID_PARAMETER:
				printf("[Error] Invalid value selected!\n");
				break;
			default:
				break;
		}

		if (number > 0 && Hint.answer != 1)
		{
			if (ERR_FILE_OPEN_FAIL == HistoryManager->record(Hint))
			{
				printf("Record error! - File open failed!\n");
				exit(1);
			}
			HistoryManager->print();
			i++;
		}
	}
	printf("\nCorrect!!\n", number);
	printf("Answer : %d\n\n", number);
	printf("Trying count : %d\n\n", i);
	showMenu();
	return 0;
}

int exitGame()
{
	remove("temp.txt");
	freeMemory();
	return 0;
}

int main(int argc, char *argv[])
{
	showMenu();
}
