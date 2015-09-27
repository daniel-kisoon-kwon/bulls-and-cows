#pragma once

typedef struct _hint
{
	int targetNumber;
	int ball;
	int strike;
	int answer;
}hint;

typedef int(*funcPtrGenerateNumber)();
typedef hint(*funcPtrCheckAnswer)(int input);

typedef struct _engine
{
	funcPtrGenerateNumber generateNumber;
	funcPtrCheckAnswer checkAnswer;
}engine;

int initEngine(engine *Engine);