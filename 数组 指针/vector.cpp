#include<iostream>
#include<vector>
using namespace std;

double average(const vector<double> &arr) {
	double sum = 0;
	for (unsigned i = 0; i < arr.size(); i++)
		sum += arr[i];
	return sum / arr.size();
}

int main() {
	unsigned n;
	cout << "n=";
	cin >> n;

	vector<double>arr(n);                      //创建数组对象
	cout << "Input " << n << " real numbers:" << endl;
	for (unsigned i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Average= " << average(arr) << endl;
	return 0;
}