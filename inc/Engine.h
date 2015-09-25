typedef struct hint
{
	int targetNumber;
	int ball;
	int strike;
	bool answer;
}hint;

typedef struct engine
{
	int generateNumber();
	hint getHint(int input);
}engine;