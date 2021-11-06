#include <stdio.h>

int main(){


    
}

int quicksort(int array[], int begin, int end){
    if(begin < end){
        int pos = partion(array,begin,end);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        if(i<=j){
            quicksort(array, begin, i-1);
            quicksort(array, i+1 , end);
        }
        else{
            quicksort(array, begin, j-1);
            quicksort(array, j+1 , end);
        }
    }
}

int partion(int array[], int begin, int end){
    int i = begin, j = end;
    const int pivot = array[(i+j)/2];
    while(true){
        while(i<j && array[i]<pivot){
            ++i;
        }
        while(i<j && array[j]>pivot){
            ++j;
        }
        if(i<j){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if(pivot != array[j]){
                --j;
            }
            if(pivot != array[i]){
                ++i;
            }
        }
        else{
            break;
        }
    }

    if(array[i])

    return i;
}