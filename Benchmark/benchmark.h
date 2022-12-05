#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "timer.h"
using namespace std::chrono;

class Benchmark {
    public:
        Benchmark() {
            sequenceForBenchMark();
        }

        void sequenceForBenchMark();
        void beginBenchmark(char seq);
        void generateArrayforBenchmark(int seq, int size, std::vector<int>& benchInsert, std::vector<int>& benchBubble, std::vector<int>& benchQuick, std::vector<int>& benchMerge);
        void InsertionSortForBenchMark(int size, std::vector<int> vect);
        void BubbleSortForBenchMark(int size, std::vector<int> vect);
        void QuickSortForBenchMark(std::vector<int>& vect, int low, int high);
        int PartitionForBenchMark(std::vector<int>& vect, int start, int end);
        void MergeSortForBenchMarking(std::vector<int>& vect);
        void FinalMergeForBenchMarking(std::vector<int>& vect, std::vector<int> left, std::vector<int> right);
};

inline void Benchmark::sequenceForBenchMark() {
    char seq;
    std::cout << "\n-----------------------------------------\n";
    std::cout << "a\tBenchmark in Sorted Sequence\n";
    std::cout << "b\tBenchmark in Reversed Sequence\n";
    std::cout << "c\tBenchmark in Random Sequence\n";
    std::cout << "d\tBenchmark in Partially Sorted Sequence\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Choose a sequence: ";
    
    std::cin >> seq;

    std::cout << "\nA benchmarking file has been created in your current directory..\n\n";

    beginBenchmark(seq);
}

inline void Benchmark::beginBenchmark(char seq) {
    int arr[13] = {100, 250, 500, 750, 1000, 1250, 2500, 3750, 5000, 6250, 7500, 8750, 10000};

    std::fstream fileOut;
    if(seq == 'a') {
        fileOut.open("Sorted.csv", std::ios::out | std::ios::app);
        fileOut << "\t\t\t\t\t\tResults of Benchmarking in Sorted Sequence\n\n\t";
    } else if(seq == 'b') {
        fileOut.open("Reversed.csv", std::ios::out | std::ios::app);
        fileOut << "\t\t\t\t\t\tResults of Benchmarking in Reversed Sequence\n\n\t";
    } else if(seq == 'c') {
        fileOut.open("Random.csv", std::ios::out | std::ios::app);
        fileOut << "\t\t\t\t\t\tResults of Benchmarking in Random Sequence\n\n\t";
    } else if(seq == 'd') {
        fileOut.open("PartiallySorted.csv", std::ios::out | std::ios::app);
        fileOut << "\t\t\t\t\t\tResults of Benchmarking in Partially Sorted Sequence\n\n\t";
    }

    fileOut << "\t\t" << 100 << "\t\t" << 250 << "\t\t" << 500 << "\t\t" << 750 << "\t\t" << 1000 << "\t" << 1250 << "\t" << 2500 << "\t" << 3750 << "\t" << 5000 << "\t" << 6250 << "\t" << 7500 << "\t" << 8750 << "\t" << 10000 << "\n";

    Timer timerr;
    std::vector<double> timeCount;
    for(int size = 0; size < 13; size++) {
        std::vector<int> benchInsert, benchBubble, benchMerge, benchQuick;
        
        generateArrayforBenchmark(seq, arr[size], benchInsert, benchBubble, benchQuick, benchMerge);

        timerr.start();
        //auto start = high_resolution_clock::now();
        InsertionSortForBenchMark(arr[size], benchInsert);
        //auto stop = high_resolution_clock::now();
        timerr.stop();
        //auto duration = duration_cast<microseconds>(stop - start);
        timeCount.push_back(timerr.getDuration());

        timerr.start();
        //start = high_resolution_clock::now();
        BubbleSortForBenchMark(arr[size], benchInsert);
        //auto stop = high_resolution_clock::now();
        timerr.stop();
        //auto duration = duration_cast<microseconds>(stop - start);
        timeCount.push_back(timerr.getDuration());

        timerr.start();
        //start = high_resolution_clock::now();
        QuickSortForBenchMark(benchQuick, 0, benchQuick.size() - 1);
        //auto stop = high_resolution_clock::now();
        timerr.stop();
        //auto duration = duration_cast<microseconds>(stop - start);
        timeCount.push_back(timerr.getDuration());

        timerr.start();
        //start = high_resolution_clock::now();
        MergeSortForBenchMarking(benchMerge);
        //auto stop = high_resolution_clock::now();
        timerr.stop();
        //auto duration = duration_cast<microseconds>(stop - start);
        timeCount.push_back(timerr.getDuration());
    }

    fileOut << "Insertion Sort\t";
    for(int i = 0; i < 52; i += 4) {
        fileOut << std::fixed << std::fixed << std::setprecision(0) << timeCount[i] << "\t";
        if(i == 48) {
            fileOut << "\nBubble Sort\t";
            i = 1;
        } else if(i == 49) {
            fileOut << "\nQuick Sort\t";
            i = 2;
        } else if(i == 50) {
            fileOut << "\nMerge Sort\t";
            i = 3;
        }
    } 
    fileOut << "\n";
}

inline void Benchmark::generateArrayforBenchmark(int seq, int size, std::vector<int>& benchInsert, std::vector<int>& benchBubble, std::vector<int>& benchQuick, std::vector<int>& benchMerge) {
    // Providing a seed value
    srand((unsigned) time(NULL));
    for(int i = 0; i < size; i++) {
        // Generate random numbers between 1 and 50000
        int random = 1 + (rand() % 50001);
        benchInsert.push_back(random);
        benchBubble.push_back(random);
        benchQuick.push_back(random);
        benchMerge.push_back(random);
    }
    if(seq == 'a') {
        std::sort(benchInsert.begin(), benchInsert.end());
        std::sort(benchBubble.begin(), benchBubble.end());
        std::sort(benchQuick.begin(), benchQuick.end());
        std::sort(benchMerge.begin(), benchMerge.end());
    } else if(seq == 'b') {
        std::sort(benchInsert.begin(), benchInsert.end());
        std::sort(benchBubble.begin(), benchBubble.end());
        std::sort(benchQuick.begin(), benchQuick.end());
        std::sort(benchMerge.begin(), benchMerge.end());
        std::reverse(benchInsert.begin(), benchInsert.end());
        std::reverse(benchBubble.begin(), benchBubble.end());
        std::reverse(benchQuick.begin(), benchQuick.end());
        std::reverse(benchMerge.begin(), benchMerge.end());
    } else if(seq == 'd') {
        std::sort(benchInsert.begin(), (benchInsert.begin() + benchInsert.size() / 2) - 1);
        std::sort(benchBubble.begin(), (benchBubble.begin() + benchBubble.size() / 2) - 1);
        std::sort(benchQuick.begin(), (benchQuick.begin() + benchQuick.size() / 2) - 1);
        std::sort(benchMerge.begin(), (benchMerge.begin() + benchMerge.size() / 2) - 1);
    }
}

inline void Benchmark::InsertionSortForBenchMark(int size, std::vector<int> vect) {
    for(int i = 0; i < size; i++) {
            int j = i - 1;
            int x = vect[i];
            while(j > -1 && vect[j] > x) {
                vect[j + 1] = vect[j];
                j--;
            }
            vect[j + 1] = x;
    }
}

inline void Benchmark::BubbleSortForBenchMark(int size, std::vector<int> vect) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(vect[j] > vect[j + 1]) {
                std::swap(vect[j], vect[j + 1]);
            }
        }
    }
}

inline void Benchmark::QuickSortForBenchMark(std::vector<int>& vect, int low, int high){
    if(low < high){
        int part = PartitionForBenchMark(vect, low, high);
        QuickSortForBenchMark(vect, low, part - 1);
        QuickSortForBenchMark(vect, part + 1, high);
    }
}

inline int Benchmark::PartitionForBenchMark(std::vector<int>& vect, int start, int end){
    int pivot = vect[end];
    int i = start - 1;
    for (int j=start; j<=end-1; j++){
        if(vect[j] < pivot){
            i++;
            std::swap(vect[i], vect[j]);
        }
    }
    std::swap(vect[i+1], vect[end]);

    return i+1;
}

inline void Benchmark::MergeSortForBenchMarking(std::vector<int>& vect){
    int vect_size = vect.size();
    //There is only one element
    if(vect_size < 2){
        return;
    }
    //Split elements_list in half as left and right
    int middle = vect_size / 2;
    std::vector<int> left;
    std::vector<int> right;
    //Fill left and right
    for(int i = 0; i < middle; i++){
        left.push_back(vect[i]);
    }
    for(int i = middle; i < vect_size; i++){
        right.push_back(vect[i]);
    }

    MergeSortForBenchMarking(left);
    MergeSortForBenchMarking(right);
    FinalMergeForBenchMarking(vect, left, right);
}

inline void Benchmark::FinalMergeForBenchMarking(std::vector<int>& vect, std::vector<int> left, std::vector<int> right){
    int left_size = left.size();
    int right_size = right.size();

    int left_idx = 0, right_idx = 0, list_idx = 0;

    while( left_idx < left_size && right_idx < right_size){
        if(left[left_idx] <= right[right_idx]){
            vect[list_idx] = left[left_idx];
            left_idx++;
        }
        else{
            vect[list_idx] = right[right_idx];
            right_idx++;
        }
        list_idx++;
    }
    while(left_idx < left_size){
        vect[list_idx] = left[left_idx];
        left_idx++;
        list_idx++;
    }
    while(right_idx < right_size){
        vect[list_idx] = right[right_idx];
        right_idx++;
        list_idx++;
    }
}

#endif