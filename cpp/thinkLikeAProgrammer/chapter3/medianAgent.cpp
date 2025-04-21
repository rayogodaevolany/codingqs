#include <iostream>
using namespace std;

const int NUM_MONTHS = 12;
struct agentStruct {
    int monthlySales[NUM_MONTHS];
};

double arrayAverage(int intArray[], int ARRAY_SIZE) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += intArray[i];
    }
    double average = (sum + 0.5) / ARRAY_SIZE;
    return average;
}

int* selectionSort(int arr[], int ARRAY_SIZE) {
    //new array
    int *copy = new int[ARRAY_SIZE];
    //copy the inputted array
    for (int i=0;i<ARRAY_SIZE;i++) copy[i]=arr[i];

    // loop through every index
    int start = 0;
    int end = ARRAY_SIZE-1;
    for(int i = start+1 ;i<=end; i++){
        // for every index, decrement until the value before is not greater than the current value; otherwise stop once we're at the beginning of the loop
        for(int j = i; j> start && arr[j] < arr[j-1]; j--){
            // swap the current and the value behind
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
    }

    // return sorted copy of array
    return copy;
}

double arrayMedian(int intArray[], int ARRAY_SIZE){
    // this function returns the median of an array
    double res;
    // sort the array
    int* sortedArray = selectionSort(intArray, ARRAY_SIZE);
    // if the size is odd
    if (ARRAY_SIZE % 2 == 1) {
    //      index the middle and cast to double
        res = (double) intArray[ARRAY_SIZE/2];
    } else {
        // get the two middle values
        int middle = intArray[ARRAY_SIZE/2];
        int middle2 = intArray[ARRAY_SIZE/2 -1];
    //      average the two
        res = ((double)middle + (double)middle2)/2;
    }
    return res;
}

int main() {
    const int NUM_AGENTS = 3;
    agentStruct agents[NUM_AGENTS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    int highestMedian = arrayMedian(agents[1].monthlySales, NUM_MONTHS);
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        int agentMedian = arrayMedian(agents[agent].monthlySales, NUM_MONTHS);
        if (agentMedian > highestMedian)
            highestMedian = agentMedian;
    }
    cout << "Highest monthly median: " << highestMedian << "\n";

    return 0;
}
