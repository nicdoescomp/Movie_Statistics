//
//  main.cpp
//  A2_COSC_1437_014
//
//  Created by Nicholas Brown on 1/21/25.
//


#include <iostream>
using namespace std;

double median(int *arr, int size);
int mode(int *arr, int size);
int *makeArray(int arr); // Did not use but will ask the teacher for guidance.
void getMovieData(int *arr, int size);
void selectionSort(int arr[], int size);
double average(int *arr, int size);

// Added personal functions below.
void swap (int &a, int &b);
bool isEven (int num);

int main() {
    
    int size;
    cout << "Number of students surveyed: ";
    cin >> size;
    
//declare the pointer into the dynamic array.
    int *arr = new int[size];
// new - allocates memory of whatever it is pointing to and returns the memory which is originally stored by the variable array.
  
    getMovieData(arr, size);
    

    
    selectionSort(arr, size);
    
    cout << "Average: " << average(arr,size) << endl;

    cout << "Median: " << median(arr,  size) << endl;

    cout << "Mode: " << mode(arr, size) << endl;

    
    
// Deallocates memory for program efficientnes.
    delete [] arr;
    arr = nullptr;

    
    
    return 0;
}



// Function to get user's data.
void getMovieData(int *arr, int size){
    
    
    cout << "Number of movies seen by each student: ";
    
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
    
   
    
}


// Function to get user's average.
double average(int *arr, int size){
    
    
    int sum = 0;
    double avg = 0.0;
    
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    
    
    //static cast is needed for me to return a double value because if i don't my function will return a integer value instead.
    avg = static_cast<double>(sum) / size;


    return avg;
}

// Function I personally added in to make the swapping functionality easier to read.
void swap(int& a, int& b){
    
    int temp = a;
    a = b;
    b = temp;
}


// Function that is for the selection sort algorithm.
void selectionSort(int arr[], int size){
    
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
            
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
        
        
    }
    
    // Testing to see if this sorts my array (delete later)
    cout << "This is your array sorted: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

// Function to help differentiate between and even or odd dataset.
bool isEven (int num){
    
    return num % 2 == 0;
    
    
}



 //Function to get the user's median. odd size numbers work fine but even numbers need to be worked on further. W.I.P (01/26/25)
double median(int *arr, int size){
    int result = size;

    // Comparing my isEven function to differentiate if array size is even or odd.
        if (isEven(result)) {
            return (*(arr + size / 2 - 1) + *(arr + size / 2)) / 2.0;
        } else {
            return *(arr + size / 2);
        }

    }

int mode(int *arr, int size){
    int maxVal= 0;
    int counter = 0;
    int modeValue = *(arr + 0);
    
    // the most reoccuring element in a set
    
    for (int i = 0; i < size; i++) {
        counter = 0;

        
        for (int j = 0; j < size; j++){
            
            if (arr[j] == arr[i]) {
                counter++;
            }
            // this defaults and looks at the next available element.
            }
        
        
        // So if the array element has a counter greater than the current maxVal I want to set it as the new maxVal and for where ever the array is stopped at I want to set it as the modeValue so that i can return the actual element instead of it's reoccurance.
        if (counter > maxVal) {
            maxVal = counter;
            modeValue = arr[i];
        }
    }
    
    return modeValue;
    
    
}
    




