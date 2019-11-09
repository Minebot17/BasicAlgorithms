#include <cstdio>
#include <string>
#include  "DynamicArray.cpp"
#include <iostream>
using std::string;

int main() {
	{ // Динамический массив. Вывод (100 0 1 2 4)
	
		dynamic_array<int> da = dynamic_array<int>();
		for (int i = 0; i < 5; i++)
			da.add(i);
		da.remove(3);
		da.insert(100, 0);

		for (int i = 0; i < da.get_size(); i++)
			std::cout << da.get(i) << " ";
	}
	return 0;
}