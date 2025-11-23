#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;


struct Horse_racing{
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

void addCompetition (vector<Horse_racing>& competition){
    Horse_racing NewCompetition;

    cout << endl;
    cout << "! Новая скачка !" << endl;

    cout << "Название скачек: ";
    getline(cin, NewCompetition.competition_name);

    cout << "Имя коня: ";
    getline (cin, NewCompetition.horse_name);

    cout << "Пол коня (M/W): " ;
    while(true){
        cin >> NewCompetition.horse_gender;
        cin.ignore();
        NewCompetition.horse_gender = toupper(NewCompetition.horse_gender);
        if (NewCompetition.horse_gender == 'M' || NewCompetition.horse_gender == 'W'){
            break;
        } else {
            cout << "Ошибка! Введите M (мужской) или W (женский)" << endl;
        }
    }

    cout << "Возраст коня: ";
    while(true){
    cin >> NewCompetition.horse_age;
    if(cin.fail()){
        cout << "Ошибка! Введите число!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (NewCompetition.horse_age > 20 || NewCompetition.horse_age <= 5){
        cout << "Возраст коня неправильный!" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else{
        cin.ignore();
        break;
        }
    }

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

    cout << "Возраст жокея: ";
    while(true){
    cin >> NewCompetition.jockey_age;
    if(cin.fail()){
        cout << "Ошибка! Введите число!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (NewCompetition.jockey_age > 60 || NewCompetition.jockey_age < 20){
        cout << "Возраст жокея неправильный" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else{
        cin.ignore();
        break;
        }
    }

    cout << "Рейтинг жокея: ";
    while(true){
    cin >> NewCompetition.jockey_rating;
    if(cin.fail()){
        cout << "Ошибка! Введите число!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if (NewCompetition.jockey_rating < 0 || NewCompetition.jockey_rating > 5){
        cout << "Ошибка в написании рейтинга" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else{
        cin.ignore();
        break;
        }
    }

    competition.push_back(NewCompetition);
    cout << "! Состязание создано !" << endl;
    cout << endl;

}

void ShowAllCompetitionOutFail (vector<Horse_racing>& competition){
        ofstream out("Res_competition");
        if (out.is_open()){
            cout << endl;
            out << "Все состязания" << endl;
            cout << "Все состязания" << endl;

            for (int i = 0; i < competition.size(); i++){
                out << "Состязание №" << i + 1 << ": " << endl;
                cout << "Состязание №" << i + 1 << ": " << endl;
                out << "Название: " << competition[i].competition_name << endl;
                cout << "Название: " << competition[i].competition_name << endl;
                out << "Имя коня: " << competition[i].horse_name << " (";
                cout << "Имя коня: " << competition[i].horse_name << " (";
                if (competition[i].horse_gender == 'M'){
                    out << "Конь" << ", "<<competition[i].horse_age << " лет)" << endl;
                    cout << "Конь" << ", "<<competition[i].horse_age << " лет)" << endl;
                }else{
                    out << "Лошадь" << ", "<<competition[i].horse_age << " лет)" << endl;
                    cout << "Лошадь" << ", "<<competition[i].horse_age << " лет)" << endl; 
                }
                out << "Владелец: " <<  competition[i].owner_name << " (" << "Адрес: " << competition[i].owner_adres << ", Телефон: " << competition[i].owner_number << " )" << endl;
                cout << "Владелец: " <<  competition[i].owner_name << " (" << "Адрес: " << competition[i].owner_adres << ", Телефон: " << competition[i].owner_number << " )" << endl;

                out << "Жокей: " << competition[i].jockey_name << " (" << "Адрес: " << competition[i].jockey_adres << ", Возраст: " << competition[i].jockey_age << ", Рейтинг: " << competition[i].jockey_rating << " )" << endl;
                cout << "Жокей: " << competition[i].jockey_name << " (" << "Адрес: " << competition[i].jockey_adres << ", Возраст: " << competition[i].jockey_age << ", Рейтинг: " << competition[i].jockey_rating << " )" << endl;
                out << endl;
                cout << endl;

            }
        }
        out.close();
    }


    void FoundHorse (vector<Horse_racing>& competition){
        if(competition.empty()){
            cout << "! Нет состязаний !" << endl;
            return;
        }
        string competition_found;
        cout << "Введите название скачек" << endl;
        getline(cin, competition_found);
        bool flag = false;

        for(auto& name : competition){
            if (name.competition_name == competition_found){
                cout << "Состязание: " << name.competition_name << endl;
                cout << "Конь: " << name.horse_name << endl;
                cout << "Владелец: " << name.owner_name << endl;
                cout << "Жокей: " << name.jockey_name << endl;

                flag = true;
            }
        
            }
        if (flag == false){
            cout << "! Состязание не найдено !" << endl;

        }



    }
    void delCompetition(vector<Horse_racing>& competition) {
    if(competition.empty()) {
        cout << "! Нет состязаний !" << endl;
        return;
    }
    
    string Name_competition;
    cout << "Введите название забега для удаления: ";
    getline(cin, Name_competition); 
    
    vector<int> indexes;
    cout << endl;
    cout << "Найденые забеги: " << endl;

    for (int i = 0; i < competition.size(); i++) {
        if(Name_competition == competition[i].competition_name) {
            indexes.push_back(i);
            cout << "[" << indexes.size() << "] "; 
            cout << "Название: " << competition[i].competition_name << endl;
            cout << "   Конь: " << competition[i].horse_name << endl;
            cout << "   Владелец: " << competition[i].owner_name << endl;
            cout << "   Жокей: " << competition[i].jockey_name << endl;
            cout << "------------------------" << endl;
        }
    }

    if (indexes.empty()) {
        cout << "Забега под названием '" << Name_competition << "' нет" << endl;
        return;
    }

    if (indexes.size() > 1) {
        cout << endl;
        cout << "Какой забег удалить? " << indexes.size() << endl;
        int nomer;
        cin >> nomer;
        cin.ignore();

        if (nomer < 1 || nomer > indexes.size()) {
            cout << "! Ошибка ввода ! Допустимый диапазон: 1-" << indexes.size() << endl;
            return; 
        }
 
        int indexDel = indexes[nomer - 1];
        competition.erase(competition.begin() + indexDel);
        cout << "Забег [" << nomer << "] удален" << endl;
    } else {
        int indexDel = indexes[0];
        competition.erase(competition.begin() + indexDel);
        cout << "Забег удален" << endl;
    }   
}
    void InFile(vector<Horse_racing>& competition) {
        ifstream in("Res_in.txt");
        
        if (in.is_open()){
        
            Horse_racing tempRace;
            
            while (getline(in, tempRace.competition_name)) {

                getline(in, tempRace.horse_name);

                in >> tempRace.horse_gender;    
                in.ignore();
                
                in >> tempRace.horse_age;
                in.ignore();
                
                getline(in, tempRace.owner_name);
                getline(in, tempRace.owner_adres);
                getline(in, tempRace.owner_number);
                getline(in, tempRace.jockey_name);
                getline(in, tempRace.jockey_adres);
                
                in >> tempRace.jockey_age;
                in.ignore();
                
                in >> tempRace.jockey_rating;
                in.ignore();
                
                in.ignore();
                
                competition.push_back(tempRace);
                cout << "Добавлен забег: " << tempRace.competition_name << endl;
            }
    }
        in.close();
        cout << "Данные загружены!" << endl;
        cout << endl;
}

int main(){
    vector<Horse_racing> competition;
    int meaning;


    bool flag = true;
    while(flag){
        cout << "0 - завершить программу" << endl;
        cout << "1 - добавить скачку (через консоль)" << endl;
        cout << "2 - вывести (в файл и консоль)" << endl;
        cout << "3 - найти скачку по названию забега"  << endl;
        cout << "4 - удалить скачку по названию забега" << endl;
        cout << "5 - Ввести значение забега из файла" << endl;
        cout << "Введите действие: ";
        cin >> meaning;
        cin.ignore();


        switch (meaning)
        {
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
        case 5:
            InFile(competition);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            flag = false;
            break;    
        default:
            cout << "Неверный ввод." << endl;
            break;
        }
    }
    
}
