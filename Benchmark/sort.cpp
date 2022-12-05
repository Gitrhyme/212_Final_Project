#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "sort.h"

Sort::Sort() {
    option = printMenu();
    seq = getSequence();
    num_of_elements = get_num_of_elements();
    generateVector();
    if(option == 1) {
        InsertionSort();
    } else if(option == 2) {
        BubbleSort();
    } else if(option == 3) {
        QuickSort(elements_List, 0, elements_List.size() - 1);
        std::cout << "\nAfter Sorting:\n";
        for(int i = 0; i < elements_List.size(); i++) {
            std::cout << elements_List[i] << "   ";
        }
        std::cout << std::endl << std::endl;
    } else if(option == 4) {
        MergeSort(elements_List);
        std::cout << "\nAfter Sorting:\n";
        for(int i = 0; i < elements_List.size(); i++) {
            std::cout << elements_List[i] << "   ";
        }
        std::cout << std::endl << std::endl;
    }
    
}

int Sort::get_num_of_elements(){
    if(option != 5) {
        std::cout << "\nHow many elements are in your array: ";
        int n;
        std::cin >> n;
        return n;
    }
    
    return 0;
}

//menu option to choose what algorithm to be implemented.
int Sort::printMenu() {
    std::cout << "\nSorting Algorithm Project\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "1\tImplement Insertion Sort Algorithm\n"; 
    std::cout << "2\tImplement Bubble Sort Algorithm\n";
    std::cout << "3\tImplement Quick Sort Algorithm\n";
    std::cout << "4\tImplement Merge Sort Algorithm\n";
    std::cout << "5\tQuit Program\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Choose an option: ";
    int option;
    std::cin >> option;

    switch(option) {
        case 1:
            std::cout << "\n\nImplementing Insertion Sort Algorithm\n";
            std::cout << "-----------------------------------------\n";
            break;
        case 2:
            std::cout << "\n\nImplementing Bubble Sort Algorithm\n";
            std::cout << "-----------------------------------------\n";
            break;
        case 3: 
            std::cout << "\n\nImplementing Quick Sort Algorithm\n";
            std::cout << "-----------------------------------------\n";
            break;
        case 4:
            std::cout << "\n\nImplementing Merge Sort Algorithm\n";
            std::cout << "-----------------------------------------\n";
            break;
        case 5:
            std::cout << "\nQuitting Program...\n\n\n";
            break;
    }

    return option;
}

// menu option for user to choose a sequence
char Sort::getSequence() {
    char s;
    if(option != 5) {
        std::cout << "a\tSorted Sequence\n";
        std::cout << "b\tReversed Sequence\n";
        std::cout << "c\tRandom Sequence\n";
        std::cout << "d\tPartially Sorted Sequence\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Choose a sequence: ";
        
        std::cin >> s;
    }

    return s;
}
// function to generate vectors
void Sort::generateVector() {
    if(option != 5) {
        // Providing a seed value
        srand((unsigned) time(NULL));
        for(int i = 0; i < num_of_elements; i++) {
            // Generate random numbers between 1 and 50000
            int random = 1 + (rand() % 50001);
            elements_List.push_back(random);
        }
        if(seq == 'a') {
            std::sort(elements_List.begin(), elements_List.end());
        } else if(seq == 'b') {
            std::sort(elements_List.begin(), elements_List.end());
            std::reverse(elements_List.begin(), elements_List.end());
        } else if(seq == 'd') {
            std::sort(elements_List.begin(), (elements_List.begin() + elements_List.size() / 2) - 1);
        }

        std::cout << "\nBefore Sorting:\n";
        //prints out the generated vector
        for(int i = 0; i < elements_List.size(); i++) {
            std::cout << elements_List[i] << "   ";
        }
        std::cout << std::endl;
    } 
    
}

// code for insertion sort
void Sort::InsertionSort() {
    // first for loop to 
    for(int i = 0; i < num_of_elements; i++) {
        int j = i - 1;
        int x = elements_List[i];
        //move the elements that are greater than the key to one position ahead 
        // of their current positions
        while(j > -1 && elements_List[j] > x) {
            elements_List[j + 1] = elements_List[j];
            j--;
        }
        elements_List[j + 1] = x;
    }
    std::cout << "\nAfter Sorting:\n";
    //loop to print out the sorted array
    for(int i = 0; i < elements_List.size(); i++) {
        std::cout << elements_List[i] << "   ";
    }
    std::cout << std::endl << std::endl;
}

void Sort::BubbleSort() {
    //nested loop to traverse the input array using i and j 
    for(int i = 0; i < num_of_elements; i++) {
        for(int j = 0; j < num_of_elements - i - 1; j++) {
            //if the list at j is greater than the list at (j+1) 
            // then swap these adjacent elements
            if(elements_List[j] > elements_List[j + 1]) {
                std::swap(elements_List[j], elements_List[j + 1]);
            }
        }
    }
    std::cout << "\nAfter Sorting:\n";
    //loop to print the sorted array
    for(int i = 0; i < elements_List.size(); i++) {
        std::cout << elements_List[i] << "   ";
    }
    std::cout << std::endl << std::endl;
}

//this function implements the quicksort 
// low represents the starting index
// high represents the ending index
void Sort::QuickSort(std::vector<int>& list, int low, int high){
    if(low < high){
        // part is the partioning index 
        int part = Partition(list, low, high);
        // sorts elements before and after partition 
        QuickSort(list, low, part - 1);
        QuickSort(list, part + 1, high);
    }
}

int Sort::Partition(std::vector<int>& list, int start, int end){
    // pivot
    int pivot = list[end];
    int i = start - 1;
    for (int j=start; j<=end-1; j++){
        //if the current element is smaller than the pivot 
        if (list[j] < pivot){
            // increment index of the smaller element
            i++;
            std::swap(list[i], list[j]);
        }
    }
    // then swap
    std::swap(list[i+1], list[end]);
    return i+1;
}

void Sort::MergeSort(std::vector<int>& list){
    int list_size = list.size();
    //There is only one element
    if(list_size < 2){
        return;
    }
    //Split elements_list in half as left and right
    int middle = list_size/2;
    std::vector<int> left;
    std::vector<int> right;
    //Fill left and right
    for(int i = 0; i < middle; i++){
        left.push_back(list[i]);
    }
    for(int i = middle; i < list_size; i++){
        right.push_back(list[i]);
    }

    MergeSort(left);
    MergeSort(right);
    FinalMerge(list, left, right);
}

void Sort::FinalMerge(std::vector<int>& list, std::vector<int> left, std::vector<int> right){
    int left_size = left.size();
    int right_size = right.size();
    
    // initial index of first sub-array ----  left_idx
    // initial index of second sub-array ----- right_idx
    // initial index of merged array ----- list_idx
    int left_idx = 0, right_idx = 0, list_idx = 0;
    // merge the list vector back into vectors{left and right}
    while( left_idx < left_size && right_idx < right_size){
        if(left[left_idx] <= right[right_idx]){
            list[list_idx] = left[left_idx];
            left_idx++;
        }
        else{
            list[list_idx] = right[right_idx];
            right_idx++;
        }
        list_idx++;
    }
    //copy the remaining elements of left vector, if there are any
    while(left_idx < left_size){
        list[list_idx] = left[left_idx];
        left_idx++;
        list_idx++;
    }
    //copy the remianing elements of right vector, if there are any
    while(right_idx < right_size){
        list[list_idx] = right[right_idx];
        right_idx++;
        list_idx++;
    }
}
    //std::ofstream outputFile("Sorted.csv");











