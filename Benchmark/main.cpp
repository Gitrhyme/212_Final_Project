#include <iostream>
#include "sort.h"
#include "benchmark.h"

int main() {

    std::cout << "\nSorting Algorithm Project\n";
    std::cout << "---------------------------------------------------------------\n";
    std::cout << "Implement or Benchmark algorithms? (Y for former, N for latter): ";
    char letter;
    std::cin >> letter;

    if(letter == 'Y') {
        Sort sortArray;
    } else if(letter == 'N') {
        Benchmark algo;
    }
}