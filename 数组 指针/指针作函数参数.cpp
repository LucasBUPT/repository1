#include<iostream>
using namespace std;

void splitFloat(float x, int *intpart, float *fracpart) {            //�β���ָ��
	*intpart = static_cast<int>(x);
	*fracpart = x - *intpart;
}

int main() {
	cout << "Enter 3 float point numbers: " << endl;
	for (int i = 0; i < 3; i++) {
		float x, f;
		int n;
		cin >> x;
		splitFloat(x, &n, &f);                                        //������ַ��ʵ��
		cout << "Int Part= " << n << " Frac Part= " << f << endl;
	}
	return 0;
}