#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
#include <algorithm>
#include <vector>

void Massivs(double mass [], int n){

    sort(mass, mass + n);
    vector <double> sorter (mass, mass + n);

    vector<double> result;

    sort(sorter.begin(), sorter.end());

    double sred = 0;

    for (int i = 0; i<n ; ++i){
        sred = sorter[sorter.size() / 2];
    }
    cout << "Медианное значение: ";
    cout << sred << endl;

    cout << endl;

    for (int j = 0; j<n; ++j){
        if (sorter[j] <= sred){
            result.push_back(sorter[j]);
        }
    }

    cout << "Результат: " << endl;

    for (int number : result){
        cout << number << "\t" ;
    }
    cout << endl;

}


template<typename T>
T safeInput(){
    T value;
    while (true)
    {
        cin >> value;

        if (cin.fail()){
            cout << "Ошибка ввод" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');

        }else{
            char extra;
            if (cin.get(extra) && extra != '\n'){
                cout << "Ошибка ввод"<< endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>:: max(), '\n');
                continue;
            }
            return value;

        }
    }
    
}




int main(){
    cout << "Кол-во элементов: " << endl;
    int n = safeInput<int>();

    double arr[n];
    int i = 0;

    cout << "Введите элементы: " << endl;
    while (i<n)
    {
        arr[i] = safeInput<double>();
        i++;
    }
    cout << endl;

    cout << "Массив: " << endl;
    for (int i = 0; i<n; ++i){
        cout << arr[i] << '\t';
    }
    cout << endl;
    cout << endl;
    
    Massivs(arr,n);

}