#pragma once

#include <stdio.h>
#include "Engine.h"

typedef struct histroyRecorder
{
	int (*record)(hint hint);
	void (*print)();
}histroyRecorder;

int initHistoryRecorder(histroyRecorder* HistoryRecorder);