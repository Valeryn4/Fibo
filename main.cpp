#include "header.h"

using namespace std;

void thread_f1(int i);
void thread_f2(int i);

 


int main(void)
{
	int i;
	cout << "Input index N Fibanachi: ";
	cin >> i;

	cout << "Start thread #1" << endl;
	thread thr1(thread_f1, i);
	cout << "Start thread #2" << endl;
	thread thr2(thread_f2, i);
	

	thr1.join();
	thr2.join();

	system("Pause");
	return 0;
}

void thread_f1(int i) {
	__int64 temp;
	temp = fib(i);
	cout << "\nStandart Fibanachi function Fib(i)";
	cout << "\nFib(i): " << temp << endl;
}

void thread_f2(int i) {
	__int64 temp;
	temp = fib_adv(i);
	cout << "\nAdvanced Fibanachi function fib_adv(i)";
	cout << "\n fib_adv(i) " << fib_adv(i);
}
