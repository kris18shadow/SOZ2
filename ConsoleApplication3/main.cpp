#include <iostream>
#include <vector>
#include <ctime>


bool function(bool* arr, size_t size, size_t currMoves, bool atTurn, size_t min, size_t max)
{
	std::vector<size_t> startPoints;

	//available start coins indexes:
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == true)
			startPoints.push_back(i);
	}

	if (startPoints.size() == 0)
	{
		if (atTurn)
		{
			std::cout << "{0, ";
			std::cout << max << ", ";
			std::cout <<  size - currMoves << "}\n";
		}

		if (!atTurn)
		{
			std::cout << "{0, ";
			std::cout << max << ", ";
			std::cout << - int(size - currMoves) << "}\n";
		}
		
		delete[] arr;

		return true;
	}

	//take 3 coins:
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		bool* temp = new bool[size];

		for (size_t j = 0; j < size; j++)
			temp[j] = arr[j];

		if (startPoints[i] + 2 < size)
		{
			if (temp[startPoints[i]] == true && temp[startPoints[i] + 1] == true && temp[startPoints[i] + 2] == true)
			{
				temp[startPoints[i]] = false;
				temp[startPoints[i] + 1] = false;
				temp[startPoints[i] + 2] = false;
				if(function(temp, size, currMoves + 1, !(atTurn), min, 3))
					return true;
			}
			else
			{
				delete[] temp;
			}
		}
		else
			if (startPoints[i] + 2 == size)
			{
				if (temp[startPoints[i]] == true && temp[startPoints[i] + 1] == true && temp[0] == true)
				{
					temp[startPoints[i]] = false;
					temp[startPoints[i] + 1] = false;
					temp[0] = false;
					if(function(temp, size, currMoves + 1, !(atTurn), min, 3))
						return true;
				}
				else
				{
					delete[] temp;
				}
			}
			else
				if (startPoints[i] + 2 > size)
				{
					if (temp[startPoints[i]] == true && temp[0] == true && temp[1] == true)
					{
						temp[startPoints[i]] = false;
						temp[0] = false;
						temp[1] = false;
						if(function(temp, size, currMoves + 1, !(atTurn), min, 3))
							return true;
					}
					else
					{
						delete[] temp;
					}
				}
	}
	//end of take 3 coins

	//take 2 coins:
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		bool* temp = new bool[size];

		for (size_t j = 0; j < size; j++)
			temp[j] = arr[j];

		if (startPoints[i] + 1 < size)
		{
			if (temp[startPoints[i]] == true && temp[startPoints[i] + 1] == true)
			{
				temp[startPoints[i]] = false;
				temp[startPoints[i] + 1] = false;
				if(function(temp, size, currMoves + 1, !(atTurn), min, 2))
					return true;
			}
			else
			{
				delete[] temp;
			}
		}
		else
			if (startPoints[i] + 1 == size)
			{
				if (temp[startPoints[i]] == true && temp[0] == true)
				{
					temp[startPoints[i]] = false;
					temp[0] = false;
					if(function(temp, size, currMoves + 1, !(atTurn), min, 2))
						return true;
				}
				else
				{
					delete[] temp;
				}

			}
	}

	//take 1 coin:
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		bool* temp = new bool[size];

		for (size_t j = 0; j < size; j++)
			temp[j] = arr[j];

		temp[startPoints[i]] = false;
		if(function(temp, size, currMoves + 1, !(atTurn), min, 1))
			return true;
	}

	delete[] arr;
}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error! Invalid number of arguments!\n";
		return 1;
	}

	size_t N = atoi(argv[1]);
	clock_t begin = clock();

	bool* arr2 = new bool[N];

	for (size_t i = 0; i < N; i++)
	{
		arr2[i] = true;
	}
		
	std::cout << "Calculating...\n";
	function(arr2, N, 0, false, 0, 0);

	clock_t end = clock();
	double elapsedSecs = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Time: " << elapsedSecs << " seconds." << std::endl;

	return 0;
}