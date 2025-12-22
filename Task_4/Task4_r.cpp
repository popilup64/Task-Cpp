#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

struct Horse_racing {
    string horse_name;
    char horse_gender;
    int horse_age;

    string owner_name;
    string owner_adres;
    string owner_number;

    string jockey_name;
    string jockey_adres;
    int jockey_age;
    double jockey_rating;

    string competition_name;
};

// Лямбда
template<typename T>
auto safeInput = [](const string& prompt, T min_val, T max_val) -> T {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Ошибка! Введите число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (value < min_val || value > max_val) {
            cout << "Ошибка! Значение должно быть от " << min_val << " до " << max_val << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            return value;
        }
    }
};

void addCompetition(vector<Horse_racing>& competition) {
    Horse_racing NewCompetition;

    cout << endl << "! Новая скачка !" << endl;

    cout << "Название скачек: ";
    getline(cin, NewCompetition.competition_name);

    cout << "Имя коня: ";
    getline(cin, NewCompetition.horse_name);

    cout << "Пол коня (M/W): ";
    while (true) {
        cin >> NewCompetition.horse_gender;
        cin.ignore();
        NewCompetition.horse_gender = toupper(NewCompetition.horse_gender);
        if (NewCompetition.horse_gender == 'M' || NewCompetition.horse_gender == 'W') {
            break;
        } else {
            cout << "Ошибка! Введите M (мужской) или W (женский)" << endl;
        }
    }

    NewCompetition.horse_age = safeInput<int>("Возраст коня: ", 6, 20);

    cout << "ФИО владельца: ";
    getline(cin, NewCompetition.owner_name);

    cout << "Адрес владельца: ";
    getline(cin, NewCompetition.owner_adres);

    cout << "Телефон владельца: ";
    getline(cin, NewCompetition.owner_number);

    cout << "ФИО жокея: ";
    getline(cin, NewCompetition.jockey_name);

    cout << "Адрес жокея: ";
    getline(cin, NewCompetition.jockey_adres);

    NewCompetition.jockey_age = safeInput<int>("Возраст жокея: ", 20, 60);

    NewCompetition.jockey_rating = safeInput<double>("Рейтинг жокея: ", 0.0, 5.0);

    competition.push_back(NewCompetition);
    cout << "! Состязание создано !" << endl << endl;
}

void ShowAllCompetitionOutFail(const vector<Horse_racing>& competition) {
    ofstream out("Res_competition");
    if (out.is_open()) {
        cout << endl;
        out << "Все состязания" << endl;
        cout << "Все состязания" << endl;

        int i = 1;
        for (const auto& race : competition) {
            out << "Состязание №" << i << ": " << endl;
            cout << "Состязание №" << i << ": " << endl;
            out << "Название: " << race.competition_name << endl;
            cout << "Название: " << race.competition_name << endl;
            
            out << "Имя коня: " << race.horse_name << " (";
            cout << "Имя коня: " << race.horse_name << " (";
            out << (race.horse_gender == 'M' ? "Конь" : "Лошадь") << ", " << race.horse_age << " лет)" << endl;
            cout << (race.horse_gender == 'M' ? "Конь" : "Лошадь") << ", " << race.horse_age << " лет)" << endl;
            
            out << "Владелец: " << race.owner_name << " (Адрес: " << race.owner_adres 
                << ", Телефон: " << race.owner_number << ")" << endl;
            cout << "Владелец: " << race.owner_name << " (Адрес: " << race.owner_adres 
                << ", Телефон: " << race.owner_number << ")" << endl;

            out << "Жокей: " << race.jockey_name << " (Адрес: " << race.jockey_adres 
                << ", Возраст: " << race.jockey_age << ", Рейтинг: " << race.jockey_rating << ")" << endl;
            cout << "Жокей: " << race.jockey_name << " (Адрес: " << race.jockey_adres 
                << ", Возраст: " << race.jockey_age << ", Рейтинг: " << race.jockey_rating << ")" << endl;
            
            out << endl;
            cout << endl;
            i++;
        }
    }
    out.close();
}

void FoundHorse(const vector<Horse_racing>& competition) {
    if (competition.empty()) {
        cout << "! Нет состязаний !" << endl;
        return;
    }
    
    string competition_found;
    cout << "Введите название скачек: ";
    getline(cin, competition_found);
    
    auto it = find_if(competition.begin(), competition.end(),
        [&competition_found](const Horse_racing& race) {
            return race.competition_name == competition_found;
        });
    
    if (it != competition.end()) {
        cout << "Состязание: " << it->competition_name << endl;
        cout << "Конь: " << it->horse_name << endl;
        cout << "Владелец: " << it->owner_name << endl;
        cout << "Жокей: " << it->jockey_name << endl;
    } else {
        cout << "! Состязание не найдено !" << endl;
    }
}

void delCompetition(vector<Horse_racing>& competition) {
    if (competition.empty()) {
        cout << "! Нет состязаний !" << endl;
        return;
    }
    
    string Name_competition;
    cout << "Введите название забега для удаления: ";
    getline(cin, Name_competition);
    
    vector<int> indexes;
    cout << endl << "Найденные забеги: " << endl;

    int i = 0;
    for (const auto& race : competition) {
        if (race.competition_name == Name_competition) {
            indexes.push_back(i);
            cout << "[" << indexes.size() << "] ";
            cout << "Название: " << race.competition_name << endl;
            cout << "   Конь: " << race.horse_name << endl;
            cout << "   Владелец: " << race.owner_name << endl;
            cout << "   Жокей: " << race.jockey_name << endl;
            cout << "------------------------" << endl;
        }
        i++;
    }

    if (indexes.empty()) {
        cout << "Забега под названием '" << Name_competition << "' нет" << endl;
        return;
    }

    if (indexes.size() > 1) {
        cout << endl << "Какой забег удалить? (1-" << indexes.size() << "): ";
        int nomer = safeInput<int>("", 1, indexes.size());
        
        int indexDel = indexes[nomer - 1];
        competition.erase(competition.begin() + indexDel);
        cout << "Забег [" << nomer << "] удален" << endl;
    } else {
        competition.erase(competition.begin() + indexes[0]);
        cout << "Забег удален" << endl;
    }
}

int main() {
    vector<Horse_racing> competition;
    int meaning;

    bool flag = true;
    while (flag) {
        cout << "\n0 - завершить программу" << endl;
        cout << "1 - добавить скачку (через консоль)" << endl;
        cout << "2 - вывести (в файл и консоль)" << endl;
        cout << "3 - найти скачку по названию забега" << endl;
        cout << "4 - удалить скачку по названию забега" << endl;
        cout << "5 - Ввести значение забега из файла" << endl;
        
        cout << "Введите действие: ";
        meaning = safeInput<int>("", 0, 5);
        cin.ignore();

        switch (meaning) {
            case 1:
                addCompetition(competition);
                break;
            case 2:
                ShowAllCompetitionOutFail(competition);
                break;
            case 3:
                FoundHorse(competition);
                break;
            case 4:
                delCompetition(competition);
                break;
            case 5: {
                ifstream in("Res_in.txt");
                if (in.is_open()) {
                    Horse_racing tempRace;
                    while (getline(in, tempRace.competition_name) && 
                           getline(in, tempRace.horse_name)) {
                        in >> tempRace.horse_gender >> tempRace.horse_age;
                        in.ignore();
                        getline(in, tempRace.owner_name);
                        getline(in, tempRace.owner_adres);
                        getline(in, tempRace.owner_number);
                        getline(in, tempRace.jockey_name);
                        getline(in, tempRace.jockey_adres);
                        in >> tempRace.jockey_age >> tempRace.jockey_rating;
                        in.ignore(numeric_limits<streamsize>::max(), '\n');
                        competition.push_back(tempRace);
                        cout << "Добавлен забег: " << tempRace.competition_name << endl;
                    }
                    in.close();
                    cout << "Данные загружены!" << endl << endl;
                }
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                flag = false;
                break;
            default:
                cout << "Неверный ввод." << endl;
                break;
        }
    }
    
    return 0;
}