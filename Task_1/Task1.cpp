#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
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
    

double fx (double x, int variant){

    switch (variant)
    {

    case 0:
        return x;
        break;

    case 1:
        return x * x;
        break;

    case 2:
        return exp(x);
        break;

    case 3:
        return sin(x);
        break;
    
    default:

    throw invalid_argument ("Выбрана неверная команда");
    return 0;
    }

}

int main(){
    try{
        double x = safeInput<double>("Введите x: ");

        cout << "0 - f(x)" << endl;
        cout << "1 - f(x^2):" << endl;
        cout << "2 - f(e^2):" << endl;
        cout << "3 - f(sin(x)):" << endl;
        
        int var = safeInput<int>("Выбрать вид функции: ");

        double result;

        if (x>0){

            result = sin(x) * (pow(1 + abs(pow(fx(x,var),4)),-1));
            
        }else{

            result = pow(pow(cos(x),2),1.0/3.0);
        }

        cout << "Ответ: "<<result << endl;
    }

    catch (const invalid_argument & e){
        cout << e.what() <<endl;
        return 1;
    }





    return 0;
}