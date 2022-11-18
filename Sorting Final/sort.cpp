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

void Sort::merge_sort(std::vector<int>& list){
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

    merge_sort(left);
    merge_sort(right);
    final_merge(list, left, right);

}

void Sort::final_merge(std::vector<int>& list, std::vector<int> left, std::vector<int> right){
    int left_size = left.size();
    int right_size = right.size();

    int left_idx = 0, right_idx = 0, list_idx = 0;

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
    while(left_idx < left_size){
        list[list_idx] = left[left_idx];
        left_idx++;
        list_idx++;
    }
    while(right_idx < right_size){
        list[list_idx] = right[right_idx];
        right_idx++;
        list_idx++;
    }

}

void Sort::InsertionSort(){
    for (int i=1; i<num_of_elements; i++){
        int j = i-1;
        int x = A[i];
        while (j>-1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void Sort::print(){
    for (int i = 0; i < num_of_elements; i++)
    {
        std::cout << elements_List[i] << " ";
    }
    
}
