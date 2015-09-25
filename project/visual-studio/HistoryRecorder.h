typedef struct histroyRecorder
{
	int init();
	int start();
	int record(hint hint);
	int stop();
	int deinit();
	void print();
}HistroyRecorder;