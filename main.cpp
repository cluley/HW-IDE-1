#include <iostream>
#include <fstream>

void wipe(int*& arr) {
	delete[] arr;
	arr = nullptr;
}

int main(int argc, char** argv) {
	std::ifstream input("in.txt");
	if (!input.is_open())
	{
		std::cout << "Failed to open the file!" << std::endl;
		exit(EXIT_FAILURE);
	}

	int size1;
	input >> size1;

	int* arr = new int[size1];

	for (int i = 0; i < size1; i++)
	{
		input >> arr[i];
	}

	int size2;
	input >> size2;

	int* mass = new int[size2];

	for (int i = 0; i < size2; i++)
	{
		input >> mass[i];
	}

	input.close();

	int temp = arr[0];
	for (int i = 0; i < size1; i++)
	{
		if (arr[i] == arr[size1 - 1])
		{
			arr[i] = temp;
		}
		else {
			arr[i] = arr[i + 1];
		}
	}

	temp = mass[size2 - 1];
	for (int i = (size2 - 1); i > -1; i--)
	{
		if (mass[i] == mass[0])
		{
			mass[i] = temp;
		}
		else {
			mass[i] = mass[i - 1];
		}
	}

	std::ofstream output("out.txt");
	output << size2 << '\n';

	for (int i = 0; i < size2; i++)
	{
		output << mass[i] << '\t';
	}
	output << '\n';

	output << size1 << '\n';

	for (int i = 0; i < size1; i++)
	{
		output << arr[i] << '\t';
	}

	output.close();
	wipe(arr);
	wipe(mass);

	return 0;
}