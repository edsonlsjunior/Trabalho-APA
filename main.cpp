#include <iostream>
#include "Sort.cpp"

using namespace std;

int main()
{
	vector<int> teste;
	for (int i = 100; i > 0; --i)
		{
		teste.push_back((i + 3)%37);
		cout << teste.back() << " ";
		}
		cout << endl;

	for (auto i : teste)
		cout << i << " ";
	
	return 0;
}