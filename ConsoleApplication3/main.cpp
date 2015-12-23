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
		//std::cout << "Player " << !atTurn << " wins with " << currMoves-- << " moves!\n";
		//std::cout << "Points: " << size - (currMoves--) << std::endl;
		delete[] arr;
		return true;
	}

	//take 1 coin:
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		bool* temp = new bool[size];
		for (size_t i = 0; i < size; i++)
			temp[i] = arr[i];
		temp[startPoints[i]] = false;
		function(temp, size, currMoves + 1, !(atTurn), min, max);
	}

	//take 2 coins:
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		bool* temp = new bool[size];
		for (size_t i = 0; i < size; i++)
			temp[i] = arr[i];
		if (startPoints[i] + 1 < size)
		{
			if (temp[startPoints[i]] == true && temp[startPoints[i] + 1] == true)
			{
				temp[startPoints[i]] = false;
				temp[startPoints[i] + 1] = false;
				function(temp, size, currMoves + 1, !(atTurn), min, max);
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
				function(temp, size, currMoves + 1, !(atTurn), min, max);
			}
			else
			{
				delete[] temp;
			}

		}
	}

	//take 3 coins:
	for (size_t i = 0; i < startPoints.size(); i++)
	{
		bool* temp = new bool[size];
		for (size_t i = 0; i < size; i++)
			temp[i] = arr[i];
		if (startPoints[i] + 2 < size)
		{
			if (temp[startPoints[i]] == true && temp[startPoints[i] + 1] == true && temp[startPoints[i] + 2] == true)
			{
				temp[startPoints[i]] = false;
				temp[startPoints[i] + 1] = false;
				temp[startPoints[i] + 2] = false;
				function(temp, size, currMoves + 1, !(atTurn), min, max);
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
				function(temp, size, currMoves + 1, !(atTurn), min, max);
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
				function(temp, size, currMoves + 1, !(atTurn), min, max);
			}
			else
			{
				delete[] temp;
			}
		}
	}
	//end of take 3 coins
	
	delete[] arr;
}

int main()
{
	size_t N = 10;
	clock_t begin = clock();
	

	bool* arr2 = new bool[N];

	for (size_t i = 0; i < N; i++)
	{
		arr2[i] = true;
	}

	///TEST	
	std::cout << "Calculating...\n";
	function(arr2, N, 0, false, 0, 0);
	std::cout << "DONE!\n";

	clock_t end = clock();
	double elapsedSecs = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Time: " << elapsedSecs << std::endl;

	return 0;
}