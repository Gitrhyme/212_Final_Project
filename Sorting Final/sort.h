// #ifndef and #define are header guards
//use is to prevent the header file from being included multiple times.
#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort {
    public:
        std::vector<int> elements_List;
        int num_of_elements;

        // Getter members
        int get_num_of_elements();
        std::vector<int> get_elements_List();

        //default constructor
        Sort();
        // Setter and getter for member variables
        void selection_sort();
        void merge_sort(std::vector<int>& list);
        void final_merge(std::vector<int>& list, std::vector<int> left, std::vector<int> right);
        void print();
        

};

#endif
