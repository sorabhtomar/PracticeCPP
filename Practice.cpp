#include <iostream>

using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while (T--)
	{
		int n, i, j;
		int count = 0;
		cin >> n;
		i = n; j = n;
		cout << i << " " << j << endl;
		while (i--)
		{
			j = i;
			cout << " IN I while" << endl;
			while (j > 0)
			{
				cout << j << endl;
				cout << " In j while" << endl;
				if ((j <= i) && (i*j <= n))
					count++;
				j--;
			}
		}
		cout << count << endl;

	}

	return 0;
}