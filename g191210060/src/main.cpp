
/** 
* @file main.cpp
* @description Main fonksiyonu. Txt dosyasindan inputlari alip agaclara yerlestiriyor, ve cozumu sunuyor.
* @course 2.Ogretim B grubu
* @assignment 2. Odev
* @date 12/22/2023
* @author Alper Salih Aktaş
*/

#include <fstream>
#include <sstream>
#include "../include/treeparent.hpp"
#include <time.h>
#include <iomanip>
//returns the execution time as seconds for comparison.
double returnTime(clock_t start, clock_t end);

int main()  
{
    clock_t start, end;
    start = clock();
    system("cls");
    TreeParent* TP = new TreeParent();
    std::string line, key;
    int avlTreeCount = 0;
    std::fstream fs("txt/Veri.txt");
    while(std::getline(fs, line, '\n'))
    {
        avlTreeCount++;
        std::stringstream ss(line);
        Tree* tree = new Tree(avlTreeCount);
        while(ss >> key)
        {
            tree->insert(std::stoi(key));
        }
        tree->setStack();
        tree->setAsciiChar();
        TP->InsertTree(tree);
    }
    TP->solution();
    end = clock();
        double time_taken = returnTime(start, end);
    std::cout << "Time taken by program is : " << std::fixed 
        << time_taken << std::setprecision(5); 
    std::cout << " sec " << std::endl; 
    return 0;  
}
double returnTime(clock_t start, clock_t end)
{
    return double(end - start) / 1000.f; 
}