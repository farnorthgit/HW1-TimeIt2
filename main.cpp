#if 0
Use the StopWatch class you previously wrote to time the same algorithms, but this time to read Gutenberg Project books – at least five – with std::string.
        Time how long it takes to read the file with at least three kinds of containers –list, vector, etc.
        Time how long it takes to find a random string inside each of those containers.
        Time how long it takes to sort each container.
        Take the output and graph it in Microsoft Excel, Gnuplot, Python with matplotlib, or R.
        What can you say about the comparative asymptotic performance for those containers and algorithms?
        What can you say about the amount of memory that is used by your program for each book compared to the original size of the book?
#endif

#include "StopWatch.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
#include <algorithm>
using std::find;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <list>
using std::list;

bool readFile(const string &filename, list<string> &gutenberg) {
    string line;
    ifstream fin ("constitutionText.txt");
    if (!fin) return false;
    while (true) {
        fin >> line;
        if (!fin) break;
        gutenberg.push_back(line);
        cout << line << " ";
    }
    return true;
}

int main() {
    // declare the list that will contain the book
    list<string> gutenberg;
    // declare the timer
    StopWatch timer;

    // start the timer to track how long to read file into list
    timer.start();
    bool readsuccess = readFile("constitutionText.txt", gutenberg);
    timer.stop();
    if (!readsuccess) {cout << "file read failed"; return 1;}
    else {
        cout << endl << timer.milli() << " milliseconds to read into a list." << endl;
        cout << timer.second() << " seconds to read into a list." << endl;
    }

    // prepare to find solution and then proceed with doing so
    string solution = "Twelfth";
    timer.start();
    auto findIter = find(gutenberg.begin(), gutenberg.end(), "Twelfth");
    timer.stop();
    cout << endl << "The solution is " << *findIter << endl;
    cout << timer.milli() << " milliseconds to find the solution." << endl;
    cout << timer.second() << " seconds to find the solution." << endl;


    timer.start();
    gutenberg.sort();
    timer.stop();
    cout << endl << "The book is now sorted." << endl;
    cout << timer.milli() << " milliseconds to sort." << endl;
    cout << timer.second() << " seconds to sort." << endl;
    for (auto l : gutenberg)
        cout << l << " ";
    //        if (find(vv.begin(), vv.end(), solution) != vv.end())
//            std::cout << "vv contains: " << solution << '\n';
//        else std::cout << "v does not contain: " << solution << '\n';
}
