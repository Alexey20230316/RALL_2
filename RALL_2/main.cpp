#include<iostream>

class Smart_arry
{
public:
	Smart_arry(int size);
	Smart_arry(const Smart_arry& other);
	void operator = (const Smart_arry& other);
	void add_element(int element);
	int get_element(int element);
	~Smart_arry();
private:
	int* arr;
	int i = 0;
	int size;
};

Smart_arry::Smart_arry(int size)
{
	this->size = size;
	this->arr = new int[size] {0};
}

Smart_arry::Smart_arry(const Smart_arry& other)
{
 this->size = other.size;
	this->arr = new int[size];
	for (int j = 0; j < size; j++)
	{
		this->arr[j] = other.arr[j];
	}
}

void Smart_arry::operator = (const Smart_arry& other)
{
	if (this->arr != nullptr)
	{
		delete this->arr;
	}
	this->size = other.size;
	this->arr = new int[size];
	for (int j = 0; j < size; j++)
	{
		this->arr[j] = other.arr[j];
	}
}

Smart_arry::~Smart_arry()
{
	delete[] arr;
}

void Smart_arry::add_element(int element)
{
	if (i >= size)
	{
		throw std::exception("No vacant tables!!!");
	}
	arr[i] = element;
	i = i++;
}
int Smart_arry::get_element(int element)
{
	if (element >= size)
	{
		throw std::exception("Index is greater than allowed!!! ");
	}
	return arr[element];
}

int main() {

	try
	{

		Smart_arry arr(5);
		arr.add_element(1);
		arr.add_element(2);
		arr.add_element(3);
		arr.add_element(4);
		arr.add_element(5);
		std::cout << arr.get_element(0) << std::endl;
		
		Smart_arry arr_2(3);
		arr_2.add_element(111);
		arr_2.add_element(222);
		arr_2.add_element(333);
		std::cout << arr_2.get_element(0) << std::endl;

		arr_2 = arr;
		std::cout << arr_2.get_element(0) << std::endl;
		

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}