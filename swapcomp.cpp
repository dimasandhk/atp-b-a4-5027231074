#include <iostream>
#include <string>
using namespace std;
// KODE DIMAS ANDHIKA DIPUTRA 5027231074

int swapBubble = 0;
int compBubble = 0;
// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
  bool swapped; // Flag to track whether any swaps were made in a pass

  for (int i = 0; i < n - 1; i++) {
    swapped = false; // Initialize as false for each pass

    // One pass through the array
    for (int j = 0; j < n - i - 1; j++) {
      // Compare adjacent elements and swap if they are in the wrong order
      compBubble++;
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapBubble++;
        swapped = true; // Set the flag to true if a swap occurred
      }
    }

    // If no swaps were made in a pass, the array is already sorted
    if (!swapped) {
      break;
    }
  }
}

int swapQuick = 0;
int compQuick = 0;
// Function to partition the array
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    // If the current element is smaller than or equal to the pivot
    if (arr[j] <= pivot) {
      compQuick++;
      swapQuick++;
      i++;
      // Swap arr[i] and arr[j]
      swap(arr[i], arr[j]);
    }
  }

  // Swap arr[i + 1] and arr[high] (pivot)
  swap(arr[i + 1], arr[high]);
  swapQuick++;

  return i + 1;
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // Partition the array and get the index of the pivot element
    int pivotIndex = partition(arr, low, high);

    // Recursively sort the two subarrays
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int swapInsertion = 0;
int compInsertion = 0;
// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1] that are greater than key
    // to one position ahead of their current position
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
      swapInsertion++;
      compInsertion++;
    }
    arr[j + 1] = key;
    swapInsertion++;
  }
}

int swapSelection = 0;
int compSelection = 0;
void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < size; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        compSelection++;
      }
    }
    swap(arr[i], arr[minIndex]);
    swapSelection++;
  }
}


void printRes(string name, int swap, int comp) {
  cout << name << " Sort = " << swap << " swaps, " << comp << " comparisons";
  if (name != "Quick") cout << endl;
}

void resetCounter() {
  swapBubble = 0; // Bubble
  compBubble = 0;
  swapQuick = 0; // Quick
  compQuick = 0;
  swapInsertion = 0; // Insertion
  compInsertion = 0;
  swapSelection = 0; // Selection
  compSelection = 0;
}

// KODE DIMAS ANDHIKA DIPUTRA 5027231074
int main() {
  // 10 DATA
  int arr1B[] = {10, 7, 5, 1, 3, 5, 3, 8, 9, 6};
  int arr1I[] = {10, 7, 5, 1, 3, 5, 3, 8, 9, 6};
  int arr1Q[] = {10, 7, 5, 1, 3, 5, 3, 8, 9, 6};
  int arr1S[] = {10, 7, 5, 1, 3, 5, 3, 8, 9, 6};
  int n = 10;
  bubbleSort(arr1B, n);
  insertionSort(arr1I, n);
  selectionSort(arr1S, n);
  quickSort(arr1Q, 0, n - 1);
  cout << "10 Data: " << "{10, 7, 5, 1, 3, 5, 3, 8, 9, 6}" << endl;
  printRes("Bubble", swapBubble, compBubble);
  printRes("Insertion", swapInsertion, compInsertion);
  printRes("Selection", swapSelection, compSelection);
  printRes("Quick", swapQuick, compQuick);

  resetCounter();
  cout << endl << endl;

  // 20 DATA
  int arr2B[] = {10, 5, 15, 20, 7, 2, 11, 1, 2, 8, 6, 20, 13, 6, 14, 5, 9, 7, 10, 13};
  int arr2I[] = {10, 5, 15, 20, 7, 2, 11, 1, 2, 8, 6, 20, 13, 6, 14, 5, 9, 7, 10, 13};
  int arr2Q[] = {10, 5, 15, 20, 7, 2, 11, 1, 2, 8, 6, 20, 13, 6, 14, 5, 9, 7, 10, 13};
  int arr2S[] = {10, 5, 15, 20, 7, 2, 11, 1, 2, 8, 6, 20, 13, 6, 14, 5, 9, 7, 10, 13};
  n = 20;
  bubbleSort(arr2B, n);
  insertionSort(arr2I, n);
  selectionSort(arr2S, n);
  quickSort(arr2Q, 0, n - 1);
  cout << "20 Data: " << "{10, 5, 15, 20, 7, 2, 11, 1, 2, 8, 6, 20, 13, 6, 14, 5, 9, 7, 10, 13}" << endl;
  printRes("Bubble", swapBubble, compBubble);
  printRes("Insertion", swapInsertion, compInsertion);
  printRes("Selection", swapSelection, compSelection);
  printRes("Quick", swapQuick, compQuick);

  resetCounter();
  cout << endl << endl;

  // 30 DATA
  int arr3B[] = {22, 9, 2, 14, 1, 24, 12, 6, 29, 5, 20, 23, 22, 29, 10, 21, 10, 21, 14, 10, 1, 27, 4, 18, 16, 1, 10, 5, 19, 23};
  int arr3I[] = {22, 9, 2, 14, 1, 24, 12, 6, 29, 5, 20, 23, 22, 29, 10, 21, 10, 21, 14, 10, 1, 27, 4, 18, 16, 1, 10, 5, 19, 23};
  int arr3Q[] = {22, 9, 2, 14, 1, 24, 12, 6, 29, 5, 20, 23, 22, 29, 10, 21, 10, 21, 14, 10, 1, 27, 4, 18, 16, 1, 10, 5, 19, 23};
  int arr3S[] = {22, 9, 2, 14, 1, 24, 12, 6, 29, 5, 20, 23, 22, 29, 10, 21, 10, 21, 14, 10, 1, 27, 4, 18, 16, 1, 10, 5, 19, 23};
  n = 30;
  bubbleSort(arr3B, n);
  insertionSort(arr3I, n);
  selectionSort(arr3S, n);
  quickSort(arr3Q, 0, n - 1);
  cout << "30 Data: " << "{22, 9, 2, 14, 1, 24, 12, 6, 29, 5, 20, 23, 22, 29, 10, 21, 10, 21, 14, 10, 1, 27, 4, 18, 16, 1, 10, 5, 19, 23}" << endl;
  printRes("Bubble", swapBubble, compBubble);
  printRes("Insertion", swapInsertion, compInsertion);
  printRes("Selection", swapSelection, compSelection);
  printRes("Quick", swapQuick, compQuick);

  resetCounter();
  cout << endl << endl;

  // 40 DATA
  int arr4B[] = {6, 26, 33, 38, 18, 1, 25, 29, 24, 16, 19, 34, 36, 13, 27, 21, 19, 33, 28, 22, 37, 9, 33, 1, 19, 17, 40, 35, 2, 25, 7, 31, 3, 21, 24, 6, 21, 19, 36, 21};
  int arr4I[] = {6, 26, 33, 38, 18, 1, 25, 29, 24, 16, 19, 34, 36, 13, 27, 21, 19, 33, 28, 22, 37, 9, 33, 1, 19, 17, 40, 35, 2, 25, 7, 31, 3, 21, 24, 6, 21, 19, 36, 21};
  int arr4Q[] = {6, 26, 33, 38, 18, 1, 25, 29, 24, 16, 19, 34, 36, 13, 27, 21, 19, 33, 28, 22, 37, 9, 33, 1, 19, 17, 40, 35, 2, 25, 7, 31, 3, 21, 24, 6, 21, 19, 36, 21};
  int arr4S[] = {6, 26, 33, 38, 18, 1, 25, 29, 24, 16, 19, 34, 36, 13, 27, 21, 19, 33, 28, 22, 37, 9, 33, 1, 19, 17, 40, 35, 2, 25, 7, 31, 3, 21, 24, 6, 21, 19, 36, 21};
  n = 40;
  bubbleSort(arr4B, n);
  insertionSort(arr4I, n);
  selectionSort(arr4S, n);
  quickSort(arr4Q, 0, n - 1);
  cout << "40 Data: " << "{6, 26, 33, 38, 18, 1, 25, 29, 24, 16, 19, 34, 36, 13, 27, 21, 19, 33, 28, 22, 37, 9, 33, 1, 19, 17, 40, 35, 2, 25, 7, 31, 3, 21, 24, 6, 21, 19, 36, 21}" << endl;
  printRes("Bubble", swapBubble, compBubble);
  printRes("Insertion", swapInsertion, compInsertion);
  printRes("Selection", swapSelection, compSelection);
  printRes("Quick", swapQuick, compQuick);

  resetCounter();
  cout << endl << endl;

  // 50 DATA
  int arr5B[] = {4, 43, 25, 3, 33, 35, 24, 12, 41, 2, 23, 50, 37, 29, 19, 9, 36, 18, 4, 45, 10, 9, 35, 15, 3, 36, 25, 39, 20, 2, 49, 14, 13, 41, 9, 29, 4, 41, 8, 7, 47, 37, 40, 3, 23, 22, 16, 41, 17, 49};
  int arr5I[] = {4, 43, 25, 3, 33, 35, 24, 12, 41, 2, 23, 50, 37, 29, 19, 9, 36, 18, 4, 45, 10, 9, 35, 15, 3, 36, 25, 39, 20, 2, 49, 14, 13, 41, 9, 29, 4, 41, 8, 7, 47, 37, 40, 3, 23, 22, 16, 41, 17, 49};
  int arr5Q[] = {4, 43, 25, 3, 33, 35, 24, 12, 41, 2, 23, 50, 37, 29, 19, 9, 36, 18, 4, 45, 10, 9, 35, 15, 3, 36, 25, 39, 20, 2, 49, 14, 13, 41, 9, 29, 4, 41, 8, 7, 47, 37, 40, 3, 23, 22, 16, 41, 17, 49};
  int arr5S[] = {4, 43, 25, 3, 33, 35, 24, 12, 41, 2, 23, 50, 37, 29, 19, 9, 36, 18, 4, 45, 10, 9, 35, 15, 3, 36, 25, 39, 20, 2, 49, 14, 13, 41, 9, 29, 4, 41, 8, 7, 47, 37, 40, 3, 23, 22, 16, 41, 17, 49};
  n = 50;
  bubbleSort(arr5B, n);
  insertionSort(arr5I, n);
  selectionSort(arr5S, n);
  quickSort(arr5Q, 0, n - 1);
  cout << "50 Data: " << "{4, 43, 25, 3, 33, 35, 24, 12, 41, 2, 23, 50, 37, 29, 19, 9, 36, 18, 4, 45, 10, 9, 35, 15, 3, 36, 25, 39, 20, 2, 49, 14, 13, 41, 9, 29, 4, 41, 8, 7, 47, 37, 40, 3, 23, 22, 16, 41, 17, 49}" << endl;
  printRes("Bubble", swapBubble, compBubble);
  printRes("Insertion", swapInsertion, compInsertion);
  printRes("Selection", swapSelection, compSelection);
  printRes("Quick", swapQuick, compQuick);

  return 0;
}
