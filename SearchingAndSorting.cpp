#include <iostream>
#include <vector>

using namespace std;

/* Returns the position of the key within the vector.
 * Returns -1 if key not found.
 */
int linearSearch(vector<int> numbers, int key) {
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] == key) return i;
    }
    return -1;
}

/* Returns the position of the key within the vector.
 * Returns -1 if key not found.
 * REQUIRES VECTOR TO BE SORTED
 */
int binarySearchHelper(vector<int> numbers, int key, int start, int end) {

    if (start > end) return -1;
    if (start == end) {
        if (numbers[start] == key) {
            return start;
        } else {
            return -1;
        }
    }
    int mid = (start + end) / 2;

    if (numbers[mid] == key) return mid;
    if (numbers[mid] < key) return binarySearchHelper(numbers, key, mid + 1, end);
    return binarySearchHelper(numbers, key, start, mid -1);

}


int binarySearch(vector<int> numbers, int key) {

    return binarySearchHelper(numbers, key, 0, numbers.size()-1);

}


void selectionSort(vector<int> &numbers) {

    for (int i=0; i<numbers.size()-1; i++) {
        int minPos = i;
        for (int j=i; j<numbers.size(); j++) {
            if (numbers[j] < numbers[minPos]) {
                minPos = j;
            }
        }
        // Swap ith with minPos
        int temp = numbers[i];
        numbers[i] = numbers[minPos];
        numbers[minPos] = temp;
    }

}

void insertionSort(vector<int> &numbers) {



}

void merge(vector<int> left, vector<int> right, vector<int> &result) {



}

void mergeSort(vector<int> &numbers) {



}




int main() {

    cout << "Hello Worlds!" << endl;

    vector<int> myNumbers { 1,2,3,5,7,8 };


    cout << "Position of 1 is: " << binarySearch(myNumbers,1) << endl;
    cout << "Position of 2 is: " << binarySearch(myNumbers,2) << endl;
    cout << "Position of 3 is: " << binarySearch(myNumbers,3) << endl;
    cout << "Position of 5 is: " << binarySearch(myNumbers,5) << endl;
    cout << "Position of 7 is: " << binarySearch(myNumbers,7) << endl;
    cout << "Position of 8 is: " << binarySearch(myNumbers,8) << endl;
    cout << "Position of 9 is: " << binarySearch(myNumbers,9) << endl;

    vector<int> unsortedNumbers { 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    selectionSort(unsortedNumbers);
    cout  << "Sorted Numbers: ";
    for (int i=0; i<unsortedNumbers.size(); i++) {
        cout <<  unsortedNumbers[i] << ",";
    }
    cout << endl;
    unsortedNumbers;

    cout << "End" << endl;


}