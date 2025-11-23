#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void Massiv(double* arr, int n){

    cout << endl;
    cout << "Результат:" << endl;

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (*(arr + i) == *(arr + j)) {
                count += 1;
            }
        }
        if (count % 2 != 0) {
                cout << *(arr + i) << "\t";
            }
        }
        cout << endl;
    }


//Обработка ошибок
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

    cout << "Введи кол-во элементво: " << endl; 

    int n = safeInput<int>();
    double arr[n];
    int i {};

    cout << "Введите значения переменных"<< endl;

    while (i < n){
        arr[i] = safeInput<double>();
        i++;
    }
    cout << endl;

    cout <<"Массив: "<< endl;



    for (int i = 0; i < n ; ++i){

        cout << arr[i] << "\t";
    
    }
    cout << endl;

    Massiv(arr, n);
}


