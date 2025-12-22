#include <iostream>
#include <fstream>
#include <string> 
#include <cctype>
#include <array> 
using namespace std;

int main() {
    string line;

    array<int, 26> skolkoBukv = {0}; 
    
    ifstream in("f1.txt");
    ofstream out("f2.txt");

    if (in.is_open() && out.is_open()) {
        auto processLine = [&skolkoBukv](const string& str) {
            for (char c : str) {
                char lowerC = tolower(c);
                if (lowerC >= 'a' && lowerC <= 'z') {
                    int index = lowerC - 'a';
                    skolkoBukv[index]++;
                }
            }
        };

        while (getline(in, line)) {
            processLine(line); 
            cout << line << endl;
        }
        cout << endl;

        char bukva = 'a';
        for (int count : skolkoBukv) {
            out << bukva << " -> " << count << endl;
            cout << bukva << " -> " << count << endl;
            bukva++;
        }
    }
    
    in.close();
    out.close();
    
    return 0;
}