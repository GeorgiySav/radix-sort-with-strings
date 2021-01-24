#include <iostream>
#include <random>
#include <string>
#include <stdio.h>

//variable for the list
std::string arr[30];

//variable for the temporay list
std::string arr1[30];

//variable to count the amount of a specific number
int count[92];

//finds the longest length so that it can add zeros infront of numbers that aren't big enough
int length = 0;

//what digit to look in the number
int pos = 1;

//sets the subroutines
void findhighestlength();
void countnums();
void change();

int main()
{
	//random generator
	std::mt19937 randomGenerator(time(NULL));
	std::uniform_int_distribution<int> random(33, 126);

	//sets all values in the array to a random string of characters
	for (int i = 0; i < std::size(arr); i++)
	{
		//loops 3 times as thats the length each value will be
		for (int j = 0; j < 3; j++)
		{
			//generates a random number and converts it to ascii, then will be added to the array value
			arr[i] = arr[i] + char((random(randomGenerator)));
		}
	}


	//finds the longest length in the array, used when generating random numbers, 1 isn't as long as 100, so 1 has to be set to 001
	findhighestlength();

	std::cout << "Longest Length: " << length << "\n";

	//adds zeros infront of values that aren't as long as the longest value
	for (int i = 0; i < std::size(arr); i++)
	{
		//loops through all values in the list and compares its length to the longest length
		if (std::size(arr[i]) < length)
		{
			//if it is, then it will find how many zeros is needed to put added

			//clears the value so it can modified
			std::string temp = arr[i];
			arr[i] = "";

			//loops until all zeros are added
			for (int j = 0; j < length - std::size(temp); j++)
			{
				arr[i] = arr[i] + "0";
			}
			//adds original value back to the value
			arr[i] = arr[i] + temp;
		}
	}


	//displays all values in the array

	std::cout << "Values in the array: " << "\n";
	for (int i = 0; i < std::size(arr); i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
	std::cout << "\n";

	//the sorting
	do
	{
		//counts the amount of each number is in the list
		countnums();

		//orders the list
		change();

		//resets all values in count so it can be used again
		for (int i = 0; i < std::size(count); i++)
		{
			count[i] = 0;
		}

		//changes the position so it change the numbers on the different digit
		pos++;

		std::cout << "\n";
		std::cout << "\n";

		//does this until pos reaches the length
	} while (pos <= length);

}

//finds the highest length
void findhighestlength()
{
	//loops through all values in the array and compares it to the longest, if its longer, then the length will change to that length
	for (int i = 0; i < std::size(arr); i++)
	{
		if (std::size(arr[i]) > length)
		{
			length = std::size(arr[i]);
		}
	}
}

//counts the amount of each number
void countnums()
{
	//loops through all values in the array
	for (int i = std::size(arr) - 1; i > -1; i--)
	{
		//temp is set to the value at pos in the value
		int temp = int(arr[i][std::size(arr[i]) - pos]) - 33;
		count[temp]++;
	}

	//adds the numbers in count so that the numbers know where to go
	for (int i = 1; i < std::size(count); i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	std::cout << "\n";
	std::cout << "\n";
}

void change()
{
	int temp = 0;

	//loops through all values in the array and puts them into the correct spot in the temporay array
	for (int i = std::size(arr) - 1; i > -1; i--)
	{
		temp = int(arr[i][std::size(arr[i]) - pos]) - 33;
		count[temp]--;
		arr1[count[temp]] = arr[i];
	}

	//puts those values back into the original array
	for (int i = 0; i < std::size(arr); i++)
	{
		arr[i] = arr1[i];
	}

	std::cout << "New array: " << "\n";
	for (int i = 0; i < std::size(arr); i++)
	{
		std::cout << arr[i] << " ";
	}
}
