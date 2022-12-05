#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort {
    private:
        std::vector<int> elements_List;
    
        int num_of_elements;
        int option;
        char seq;

        // Getter members
        int get_num_of_elements();

    public:
        //default constructor
        Sort();

        int printMenu();
        char getSequence();
        void generateVector();
        void InsertionSort();
        void BubbleSort();
        void QuickSort(std::vector<int> &list, int low, int high);
        int Partition(std::vector<int> &list, int start, int end);
        void MergeSort(std::vector<int>& list);
        void FinalMerge(std::vector<int>& list, std::vector<int> left, std::vector<int> right);
};

#endif