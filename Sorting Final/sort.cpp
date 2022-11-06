#include <iostream>
#include <vector>
#include "sort.h"

Sort::Sort() {
    num_of_elements = get_num_of_elements();
    elements_List = get_elements_List();
}

int Sort::get_num_of_elements(){
    std::cout << "How many elements are in your list?" << std::endl;
    int n;
    std::cin >> n;
    return n;
}

std::vector<int> Sort::get_elements_List(){
    std::vector<int> list;
    std::cout << "Enter elements..." << std::endl;
    for (int i = 0; i < num_of_elements; i++)
    {
        int value;
        std::cin >> value;
        list.push_back(value);
    }
    return list;
}

void Sort::selection_sort(){
    for(int i = 0; i < num_of_elements-1; i++){
        int min = i;
        for(int j = i + 1; j < num_of_elements; j++){
            if(elements_List[j] < elements_List[min]){
                min = j;
            }
        }
        int temp = elements_List[i];
        elements_List[i] = elements_List[min];
        elements_List[min] = temp;
    }
}

void Sort::print(){
    for (int i = 0; i < num_of_elements; i++)
    {
        std::cout << elements_List[i] << " ";
    }
    
}