#pragma once

#include "Engine.h"
#include "HistoryRecorder.h"

engine* createEngeine();
histroyRecorder* createHistroyRecorder();
void freeMemory();
void scanfForAnswer(int* number);
void clearEnter();