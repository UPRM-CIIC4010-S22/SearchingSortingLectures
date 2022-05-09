#include <iostream>
#include <vector>
#include <algorithm>

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

    for (int i=1; i<numbers.size(); i++) {
        int j=i;
        while ((j>0) && (numbers[j] < numbers[j-1])) {
            int temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            j--;
        }
    }

}

void merge(vector<int> left, vector<int> right, vector<int> &result) {

    int i=0;
    int j=0;
    int k=0;
    while ((i<left.size()) && (j<right.size())) {
        if (left[i] < right[j]) {
            result[k] = left[i];
            i++;
        } else {
            result[k] = right[j];
            j++;
        }
        k++;
    }
    while (i<left.size()) {
        result[k] = left[i];
        i++; k++;
    }
    while (j<right.size()) {
        result[k] = right[j];
        j++; k++;
    }

}

void mergeSort(vector<int> &numbers) {

    if (numbers.size() <=1) return;
    int mid = numbers.size() / 2;
    vector<int> leftHalf;
    for (int i = 0; i<mid; i++) {
        leftHalf.push_back(numbers[i]);
    }
    mergeSort(leftHalf);
    vector<int> rightHalf;
    for (int i=mid; i<numbers.size(); i++) {
        rightHalf.push_back(numbers[i]);
    }
    mergeSort(rightHalf);
    merge(leftHalf, rightHalf, numbers);

}


bool decreasingComparador(int a, int b) { return a > b; }


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
    
    vector<int> unsortedNumbers { 5, 7, 6, 8, 4, 3, 0, 1, 2 };
    sort(unsortedNumbers.begin(), unsortedNumbers.end(),[](int  a, int b) { return a > b; });

    // [](double x) { return x * x;}  --->  f(x) = x^2

    cout  << "Sorted Numbers: ";
    for (int i=0; i<unsortedNumbers.size(); i++) {
        cout <<  unsortedNumbers[i] << ",";
    }
    cout << endl;

    cout << "End" << endl;


}