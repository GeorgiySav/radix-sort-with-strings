#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <array>

const int LIST_SIZE = 50;

//variable for the list
std::array <std::string, LIST_SIZE>LIST = {};

//variable for the temporay list
std::array <std::string, LIST_SIZE>TEMP_LIST = {};

const int ASCIIstart = 65;
const int ASCIIend = 90;
const int itemLength = 2;

//variable to count the number of a specific character
std::array <int, ASCIIend - ASCIIstart + 1> count = {};

//finds the longest length so that it can add zeros infront of numbers that aren't big enough
int longestLength = 0;

//what digit to look in the number
int pos = 1;

//finds the longes length
void findLongestLength() {
	//loops through all values in the LISTay and compares it to the longest, if its longer, then the length will change to that length
	for (int i = 0; i < std::size(LIST); i++) {
		if (std::size(LIST[i]) > longestLength) {
			longestLength = std::size(LIST[i]);
		}
	}
}

//counts the amount of each character
void countnums() {
	//loops through all values in the LISTay
	for (int i = std::size(LIST) - 1; i > -1; i--) {
		count[int(LIST[i][std::size(LIST[i]) - pos]) - ASCIIstart]++;
	}

	//adds the numbers in count so that the characters know where to go
	for (int i = 1; i < std::size(count); i++) {
		count[i] = count[i] + count[i - 1];
	}

	std::cout << "\n";
	std::cout << "\n";
}

void change() {
	//loops through all values in the LISTay and puts them into the correct spot in the temporay LISTay
	for (int i = std::size(LIST) - 1; i > -1; i--) {
		count[int(LIST[i][std::size(LIST[i]) - pos]) - ASCIIstart]--;
		TEMP_LIST[count[int(LIST[i][std::size(LIST[i]) - pos]) - ASCIIstart]] = LIST[i];
	}

	//puts those values back into the original LISTay
	LIST = TEMP_LIST;

	std::cout << "New LISTay: " << "\n";
	for (int i = 0; i < std::size(LIST); i++) {
		std::cout << LIST[i] << " ";
	}
}

int main() {

	//random generator
	std::mt19937 randomGenerator(time(NULL));
	std::uniform_int_distribution<int> random(ASCIIstart, ASCIIend);
	
	//sets all values in the array to a random string of characters
	for (int i = 0; i < std::size(LIST); i++) {

		//loops 3 times as thats the length each value will be
		for (int j = 0; j < itemLength; j++) {

			//generates a random number and converts it to ascii, then will be added to the LISTay value
			LIST[i] = LIST[i] + char((random(randomGenerator)));

		}

	}

	//finds the longest length in the LISTay, used when generating random numbers, 1 isn't as long as 100, so 1 has to be set to 001
	findLongestLength();
	
	std::cout << "Longest Length: " << longestLength << "\n";
	
	//adds spaces infront of values that aren't as long as the longest value
	for (int i = 0; i < std::size(LIST); i++) {

		//loops through all values in the list and compares its length to the longest length
		if (std::size(LIST[i]) < longestLength) {

			//if it is, then it will find how many zeros is needed to put added
	
			//clears the value so it can modified
			std::string temp = LIST[i];
			LIST[i] = "";
	
			//loops until all zeros are added
			for (int j = 0; j < longestLength - std::size(temp); j++) {
				LIST[i] = LIST[i] + " ";
			}
			//adds original value back to the value
			LIST[i] = LIST[i] + temp;

		}

	}
	
	
	//displays all values in the LISTay
	
	std::cout << "Values in the LISTay: " << "\n";
	for (int i = 0; i < std::size(LIST); i++) {
		std::cout << LIST[i] << " ";
	}
	
	std::cout << "\n";
	std::cout << "\n";
	
	//the sorting
	while (pos <= longestLength) {
		//counts the number of each character is in the list
		countnums();
	
		//orders the list
		change();
	
		//resets all values in count so it can be used again
		count = {};
	
		//changes the position so it change the numbers on the different digit
		pos++;
		
		std::cout << "\n";
		std::cout << "\n";
	
		//does this until pos reaches the length
	}

}