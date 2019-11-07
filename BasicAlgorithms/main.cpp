#include <cstdio>
#include <string>
#include  "DynamicArray.cpp"
#include <iostream>
using std::string;

int main() {
	{ // Динамический массив. Вывод (100 0 1 2 4)
	
		dynamic_array da = dynamic_array(sizeof(int));
		for (int i = 0; i < 5; i++)
			da.add((unsigned char*)&i);
		da.remove(3);
		int e = 100;
		da.insert((unsigned char*)&e, 0);

		for (int i = 0; i < da.get_size(); i++)
			std::cout << *(int*)da.get(i) << " ";
	}
	return 0;
}