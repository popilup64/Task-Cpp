#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

void Massiv(const double* arr, int n) {
    cout << endl << "Результат:" << endl;
    for (int i = 0; i < n; ++i) {
        // Лямбда
        auto countOccurrences = [&](double value) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (value == arr[j]) {
                    count++;
                }
            }
            return count;
        };
        
        int count = countOccurrences(arr[i]);
        if (count % 2 != 0) {
            cout << arr[i] << "\t";
        }
    }
    cout << endl;
}

template<typename T>
auto safeInput() -> T {
    T value;
    while (true) {
        cin >> value;

        if (cin.fail()) {
            cout << "Ошибка ввод" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            char extra;
            if (cin.get(extra) && extra != '\n') {
                cout << "Ошибка ввод" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            return value;
        }
    }
}

int main() {
    cout << "Введи кол-во элементов: " << endl;

    auto n = safeInput<int>();
    
    // Использую vector
    vector<double> arr(n);
    
    cout << "Введите значения переменных" << endl;

    for (auto& elem : arr) {
        elem = safeInput<double>();
    }
    
    cout << endl << "Массив: " << endl;

    for (const auto& elem : arr) {
        cout << elem << "\t";
    }
    cout << endl;

    Massiv(arr.data(), n);
    
    return 0;
}