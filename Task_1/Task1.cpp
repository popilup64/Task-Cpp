#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <functional>
#include <map>
using namespace std;

template<typename T>
T safeInput(const string& s) {
    T value;
    while (true) {
        cout << s;
        
        if (cin >> value) {
            char extra;
            if (cin.get(extra)) {
                if (extra == ',') {
                    double fractional;
                    if (cin >> fractional) {
                        int digits = to_string((int)fractional).length();
                        value += fractional / pow(10, digits);
                        
                        if (cin.get(extra) && extra != '\n') {
                            cout << "Ошибка ввода!" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                        return value;
                    }
                }
                else if (extra != '\n') {
                    cout << "Ошибка ввода" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
            }
            return value;
        } else {
            cout << "Ошибка ввода" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Функция fx с использованием map вместо switch
double fx(double x, int variant) {
    static const map<int, function<double(double)>> functions = {
        {0, [](double x) { return x; }},
        {1, [](double x) { return x * x; }},
        {2, [](double x) { return exp(x); }},
        {3, [](double x) { return sin(x); }}
    };
    
    auto it = functions.find(variant);
    if (it != functions.end()) {
        return it->second(x);
    }
    
    throw invalid_argument("Выбрана неверная команда");
}

int main(){
    try{
        double x = safeInput<double>("Введите x: ");

        cout << "0 - f(x)" << endl;
        cout << "1 - f(x^2):" << endl;
        cout << "2 - f(e^x):" << endl;
        cout << "3 - f(sin(x)):" << endl;
        
        int var = safeInput<int>("Выбрать вид функции: ");

        double result;

        if (x > 0) {
            result = sin(x) * (pow(1 + abs(pow(fx(x, var), 4)), -1));
        } else {
            result = pow(pow(cos(x), 2), 1.0/3.0);
        }

        cout << "Ответ: " << result << endl;
    }
    catch (const invalid_argument & e){
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}