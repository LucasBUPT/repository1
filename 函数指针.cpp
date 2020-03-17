#include<iostream>
using namespace std;

int compute(int a,int b,int(*func)(int,int)){
	return func(a, b);
}
int max(int a, int b) {
	return((a > b) ? a : b);
}
int min(int a, int b) {
	return((a < b) ? a : b);
}
int sum(int a, int b) {
	return a + b;
}

int main() {
	int a, b, result;
	cout << "输入整数a："; cin >> a;
	cout << "输入整数b："; cin >> b;

	result = compute(a, b, &max);
	cout << "Max is " << result << endl;
	result = compute(a, b, &min);
	cout << "Min is " << result << endl;
	result = compute(a, b, &sum);
	cout << "Sum is " << result << endl;
}