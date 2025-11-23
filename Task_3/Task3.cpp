#include <iostream>
#include <fstream>
#include <string> 
#include <cctype>
using namespace std;

int main(){
    string line;

    int skolkoBukv[26] = {0};

    ifstream in("f1.txt");
    ofstream out("f2.txt");

    if (in.is_open() && out.is_open()){
        
        while (getline (in, line))
        {   

            for (char c : line){
                char lowerC = tolower(c);
                if (lowerC >= 'a' && lowerC <= 'z'){
                    int index = lowerC - 'a';
                    skolkoBukv[index]++;
                }
            }

            cout << line << endl;
        }
        cout << endl;


        for (int i = 0; i<26; i++){
            char bukva = 'a' + i;
                out << bukva << " -> " << skolkoBukv[i] << endl;
                cout << bukva << " -> " << skolkoBukv[i] << endl;
            }  

    }
        
    in.close();
    out.close();
}