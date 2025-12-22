#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Company_employee
{
    public:
        virtual void showSalary() const = 0;
        virtual void showPost() const = 0;
        virtual void showAge() const = 0;
        
        virtual ~Company_employee() = default;

};

class Manager : public Company_employee{

    public:
        int ManagerAge;
        int ManagerSalary;
        int teamSize;
        string meetingTopic;
    public:
    Manager(int age = 30, int salary = 100000, int team = 5, string meeting = "Общее собрание"){
        ManagerAge = age;
        ManagerSalary = salary;
        teamSize = team;
        meetingTopic = meeting;
    }
        void showSalary() const override{
            cout << "Зарплата: " << ManagerSalary << " руб." << endl;
        }
        void showPost() const override{
            cout << "Работает: менеджером" << endl;
        }
        void showAge() const override{
            if (ManagerAge > 18 && ManagerAge < 65){
                cout << "Возраст: " << ManagerAge << " лет"<< endl;
            }else{
                cout << "Неверный возраст" << endl;
            }
        }
        void manageTeam(){
            if (teamSize > 0){
                cout << "Управляет командой из " << teamSize << " человек" << endl;
            }else{
                cout << "Неверное кол-во человек" << endl;
            }
        }
        void showMeetingTopic(){
            cout << "Проводит собрание по теме: " << meetingTopic << endl;
        }

};

class Administrator : public Company_employee{

    public:
        int AdministratorAge;
        int AdministratorSalary;
        int countDoc;
        Administrator(int age = 35, int salary = 60000, int count = 10){
            AdministratorAge = age;
            AdministratorSalary = salary;
            countDoc = count;
        }
        
        void showSalary() const override{
            cout << "Зарплата: " << AdministratorSalary << " руб." << endl;
        }
        void showPost() const override{
            cout << "Работает: администратором" << endl;
        }
        void showAge() const override{
            if (AdministratorAge > 18 && AdministratorAge < 65){
                cout << "Возраст: " << AdministratorAge << " лет"<< endl;
            }else{
                cout << "Неверный возраст" << endl;
            }
        }
        void processDocuments(){
            if (countDoc > 0){
                cout << "Обработано документов: " << countDoc << endl;
            }
            cout << "Неверное кол-во документов" << endl;
        }
};

class Programmer : public Company_employee{
    public:
        int ProgrammerAge;
        int ProgrammerSalary;
        string ProgrammingLanguage;

        Programmer(int age = 25, int salary = 90000, string language = "C++"){
            ProgrammerAge = age;
            ProgrammerSalary = salary;
            ProgrammingLanguage = language;
        }
        
        void showPost() const override{
            cout << "Работает: программистом" << endl;
        }
        void showSalary() const override{
            cout << "Зарплата: " << ProgrammerSalary << " руб." << endl;
        }
        void showAge() const override{
            if (ProgrammerAge > 18 && ProgrammerAge < 65){
                cout << "Возраст: " << ProgrammerAge << " лет"<< endl;
            }else{
                cout << "Неверный возраст" << endl;
            }
        }
        void showProgrammingLanguage(){
            cout << "Язык программирования: " << ProgrammingLanguage << endl;
        }
};

int main(){
    unique_ptr<Manager> manager = make_unique<Manager>(25, 140000, 12, "Финансы");
    manager->showPost();
    manager->showSalary();
    manager->showAge();
    manager->manageTeam();
    manager->showMeetingTopic();
    
    cout << endl;
    
    unique_ptr<Manager> manager2 = make_unique<Manager>(); 
    unique_ptr<Manager> manager3 = make_unique<Manager>(40);
    
    unique_ptr<Administrator> admin = make_unique<Administrator>(36, 80000, 67);
    admin->showPost();
    admin->showSalary();
    admin->showAge();
    admin->processDocuments();

    cout << endl;

    unique_ptr<Programmer> program = make_unique<Programmer>(28, 110000, "Java");
    program->showPost();
    program->showSalary();
    program->showAge();
    program->showProgrammingLanguage();

}