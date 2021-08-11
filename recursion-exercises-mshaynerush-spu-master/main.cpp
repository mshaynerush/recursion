#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;
using std::min;

unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output);
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t position = 0, size_t minPosition = 0);
void SelectionSort(int array[], size_t size, size_t index = 0);
int MinIndex(int array[], int i, int j);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}


	cout << "Testing Minimum Position Finding" << endl;

	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {

		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}
	return 0;
}

unsigned long long int Fibonacci(unsigned int n) {
        if(n <= 1){
            return n;
        } else {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
}
void PrintReverseString(const string& str, ostream& output){
        if(str.size() == 0) {
            str[0];
        } else {
            output << str[str.size() - 1];
            PrintReverseString(str.substr(0, str.size() - 1), output);
        }
}

// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t position, size_t minPosition) {
    if(position == size) {
        return minPosition;
    } else if(array[position] < array[minPosition]){
        return MinimumPosition(array, size, position + 1, position);
    } else {
        MinimumPosition(array, size, position + 1, minPosition);
    }
}
void SelectionSort(int array[], size_t size, size_t index){
    {
        // Return when starting and size are same
        if (index == size)
            return;

        // calling minimum index function for minimum index
        int k = MinIndex(array, index, size-1);

        // Swapping when index nd minimum index are not same
        if (k != index) {
            int a = array[k];
            array[k] = array[index];
            array[index] = a;
        }
        // Recursively calling selection sort function
        SelectionSort(array, size, index + 1);
    }
}
// Return minimum index
int MinIndex(int array[], int i, int j)
{
    if (i == j)
        return i;

    // Find minimum of remaining elements
    int k = MinIndex(array, i + 1, j);

    // Return minimum of current and remaining.
    return (array[i] < array[k])? i : k;
}