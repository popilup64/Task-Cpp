#include <iostream>
#include <forward_list>
using namespace std;

// Лямбда
auto print_flist = [](const forward_list<int>& f_list) {
    for (int n : f_list) {
        cout << n << "\t";
    }
    cout << endl;
};

// Лямбда
auto init_flist = []() {
    forward_list<int> result;
    auto iter = result.before_begin();

    cout << "Введите значения элементов (завершение по 0):" << endl;
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        iter = result.insert_after(iter, num);
    }
    cout << "Результат:" << endl;
    print_flist(result);
    cout << endl;
    return result;
};

int main() {
    forward_list<int> numbers = init_flist();
    forward_list<int> res_m;
    forward_list<int> res_b;
    auto curr = numbers.begin();
    auto end = numbers.end();

    auto iter_b = res_b.before_begin();
    auto iter_m = res_m.before_begin();

    int znach;
    cout << "Введите значение:" << endl;
    cin >> znach;

    while (curr != end) {
        if (*curr > znach) {
            iter_b = res_b.insert_after(iter_b, *curr);
        }
        if (*curr < znach) {
            iter_m = res_m.insert_after(iter_m, *curr);
        }
        curr++;
    }

    cout << endl;
    cout << "Лист с большими элементами:" << endl;
    print_flist(res_b);

    cout << endl;
    cout << "Лист с меньшими элементами:" << endl;
    print_flist(res_m);
}