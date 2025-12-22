#include <iostream>
#include <map>
#include <string>
#include <memory>
using namespace std;

template<typename T>
class Node{
    private:
        Node<T>* next;
        T val;

    public:
        Node(T data){
            this->next = nullptr;
            val = data;
        }
        virtual ~Node() = default;
        template<typename U>
        friend class LinkedLst;
    };

template<typename T>
class LinkedLst{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size = 0;

    public:
        LinkedLst(){
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }
        

        LinkedLst(const LinkedLst& other){
            head = nullptr;
            tail = nullptr;
            size = 0;
            
            Node<T>* curr = other.head;
            while(curr != nullptr){
                addElem(curr->val);
                curr = curr->next;
            }
        }
        
        LinkedLst& operator=(const LinkedLst& other){
            if(this != &other){
                while(head != nullptr){
                    Node<T>* temp = head;
                    head = head->next;
                    delete temp;
                }
                head = nullptr;
                tail = nullptr;
                size = 0;

                Node<T>* curr = other.head;
                while(curr != nullptr){
                    addElem(curr->val);
                    curr = curr->next;
                }
            }
            return *this;
        }
        
        virtual ~LinkedLst(){
            while(head != nullptr){
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }



        void addElem(T data){
            Node<T>* node = new Node<T>(data);
            if (head == nullptr){
                head = node;
                tail = node;
                size++;
            }else{
                tail->next = node;
                tail = node;
                size++;
            }

        }

        void deleteElem (T data){
            Node<T>* curr = head;
            Node<T>* prev = nullptr;
            while(curr != nullptr){
                if (curr->val == data){
                    if (curr == head){
                        head = curr->next;
                        if(head == nullptr) tail = nullptr;
                        delete curr;
                        size--;
                        curr = head;
                    }else{
                        if (curr == tail){
                            tail = prev;
                            if (tail != nullptr) tail->next = nullptr;
                            delete curr;
                            size--;
                            curr = nullptr;
                        }else{
                            prev->next = curr->next;
                            delete curr;
                            size--;
                            curr = prev->next;
                        }
                    }
                }else{
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        T& operator[](int index){
            if (index < 0 || index >= size) {
                throw out_of_range("Неправильный индекс");
            }
            
            Node<T>* curr = head;
            int IndexC = 0;
            while(curr != nullptr){
                if (IndexC == index){
                    return curr->val;
                }
                curr = curr->next;
                IndexC++;
            }
            throw out_of_range("Неправильный индекс");
        }

        friend LinkedLst<T> operator+(const LinkedLst<T>& list1, const LinkedLst<T>& list2){
            LinkedLst<T> result;

            Node<T>* curr1 = list1.head;
            Node<T>* curr2 = list2.head;

            while(curr1 != nullptr && curr2 != nullptr){

                T sum = curr1->val + curr2->val;
                result.addElem(sum);

                curr1 = curr1->next;
                curr2 = curr2->next;
            }

            while(curr1 != nullptr){
                result.addElem(curr1->val);
                curr1 = curr1->next;
            }

            while(curr2 != nullptr){
                result.addElem(curr2->val);
                curr2 = curr2->next;
            }

        return result;
    }

    friend LinkedLst<T> operator-(const LinkedLst<T>& list1, const LinkedLst<T>& list2){
        LinkedLst<T> result;
        Node<T>* curr1 = list1.head;
        Node<T>* curr2 = list2.head;

        while (curr1 != nullptr && curr2 != nullptr){
            T razn = curr1->val - curr2->val;
            result.addElem(razn);

            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        while (curr1 != nullptr){
            result.addElem(curr1->val);
            curr1 = curr1->next;
        }

        while (curr2 != nullptr){
            result.addElem(curr2->val);
            curr2 = curr2->next;
        }

        return result;
    }

    friend ostream& operator<<(ostream& os, const LinkedLst<T>& list) {
        Node<T>* curr = list.head;
        while (curr != nullptr) {
            os << curr->val;
            if (curr->next != nullptr) {
                os << " -> ";
            }
            curr = curr->next;
        }
        os << " (size: " << list.size << ")";
        return os;
    }

    

    public:
        static void Menu(){
            int znach;
            bool flag = true;
            // Используем unique_ptr
            map<string, unique_ptr<LinkedLst<T>>> lists;
            while(flag){

                cout << endl;
                cout << "======= Меню =======" << endl;
                cout << "1: Добавить список." << endl;
                cout << "2: Добавить значение для Node (выход по 0)." << endl;
                cout << "3: Удалить значение Node." << endl;
                cout << "4: Сложение списков.(+)" << endl;
                cout << "5: Вычитание списков.(-)" << endl;
                cout << "6: Вывести значение по индексу.[]" << endl;
                cout << "7: Вывести весь список." << endl;
                cout << "8: Удалить весь список" << endl;  // Новая функция
                cout << "0: Выйти из программы." << endl;
                cout << "====================" << endl;

                cout << endl;
                cout << "Все списки: " << endl;
                if(lists.empty()){
                    cout << "(пусто)" << endl;
                }
                for (auto& elem: lists){
                    cout << elem.first << " | " << *elem.second << endl;
                }
                cout << endl;
                cout << "Введите команду: ";
                cin >> znach;
                string nazvan;

                switch (znach)
                {
                case 1: {
                    cout << "Введите название списка: " << endl;
                    cin >> nazvan;

                    if (lists.find(nazvan) != lists.end()){
                        cout << "Такое название уже есть" << endl;
                    }else{
                        // Используем make_unique вместо new
                        lists[nazvan] = make_unique<LinkedLst<T>>();
                        cout << "Список создан!" << endl;
                    }
                    break;
                }

                case 2: {
                    cout << "Введите название списка: " << endl;
                    cin >> nazvan;
                    T data;
                    bool flas = true;

                    if (lists.find(nazvan) != lists.end()){
                        while (flas){
                            cout << "Введите значение Node (0 для выхода): " << endl;
                            cin >> data;
                            if (data != 0){
                                lists[nazvan]->addElem(data);
                            }else{
                                flas = false;
                            }
                        }
                    }else{
                        cout << "Список не найден!" << endl;
                    }
                    break;
                }

                case 3: {
                    cout << "Введите название списка: " << endl;
                    cin >> nazvan;
                    T data;

                    if (lists.find(nazvan) != lists.end()){
                            cout << "Введите значение Node для удаления: " << endl;
                            cin >> data;
                            lists[nazvan]->deleteElem(data);
                            cout << "Значение удалено" << endl;
                            }else{
                                cout << "Список не найден!" << endl;
                            }
                    break;
                }


                case 4: {
                    string num1;
                    string num2;
                    string resultName;
                    cout << "1 список: " << endl;
                    cin >> num1;
                    cout << "2 список: " << endl;
                    cin >> num2;
                    cout << "Имя для результата: " << endl;
                    cin >> resultName;

                    if (lists.find(num1) != lists.end() && lists.find(num2) != lists.end()) {
                        // Автоматическое управление памятью
                        auto sum_result = make_unique<LinkedLst<T>>(*lists[num1] + *lists[num2]);
                        
                        cout << endl;
                        cout << num1 << ": " << *lists[num1] << endl;
                        cout << "+" << endl;
                        cout << num2 << ": " << *lists[num2] << endl;
                        cout << "Результат (" << resultName << "): " << *sum_result << endl;
                        
                        // Сохраняем результат
                        lists[resultName] = move(sum_result);
                    } else {
                        cout << "Списка нет!" << endl;
                    }
                    break;
                }
                
                case 5: {
                    string num1;
                    string num2;
                    string resultName;
                    cout << "1 список: " << endl;
                    cin >> num1;
                    cout << "2 список: " << endl;
                    cin >> num2;
                    cout << "Имя для результата: " << endl;
                    cin >> resultName;

                    if (lists.find(num1) != lists.end() && lists.find(num2) != lists.end()) {
                        auto raz_result = make_unique<LinkedLst<T>>(*lists[num1] - *lists[num2]);
                        
                        cout << endl;
                        cout << num1 << ": " << *lists[num1] << endl;
                        cout << "-" << endl;
                        cout << num2 << ": " << *lists[num2] << endl;
                        cout << "Результат (" << resultName << "): " << *raz_result << endl;
                        
                        lists[resultName] = move(raz_result);
                    } else {
                        cout << "Списка нет!" << endl;
                    }
                    break;
                }

                case 6: {
                    cout << "Введите название списка: " << endl;
                    cin >> nazvan;
                    int index;
                    cout << "Введите индекс: " << endl;
                    cin >> index;
                    if (lists.find(nazvan) != lists.end()){
                        try {
                            cout << "Список " << nazvan << ": " << *lists[nazvan] << endl;
                            cout << "Элемент с индексом " << index << ": " << (*lists[nazvan])[index] << endl;
                        } catch (const out_of_range& e) {
                            cout << "Ошибка: " << e.what() << endl;
                        }
                    } else {
                        cout << "Список не найден!" << endl;
                    }
                    break;
                }
                
                case 7:{
                    cout << "Введите название списка: " << endl;
                    cin >> nazvan;

                    if (lists.find(nazvan) != lists.end()){
                        cout << nazvan << ": " << *lists[nazvan] << endl;
                    }else{
                        cout << "Список не найден!" << endl;
                    }
                    break;
                }
                
                case 8: {
                    cout << "Введите название списка для удаления: " << endl;
                    cin >> nazvan;
                    
                    if (lists.find(nazvan) != lists.end()){
                        lists.erase(nazvan);
                        cout << "Список " << nazvan << " удален!" << endl;
                    }else{
                        cout << "Список не найден!" << endl;
                    }
                    break;
                }

                case 0:{
                    flag = false;
                    break;
                }
                
                default:{
                    cout << "Неверный выбор!" << endl;
                    break;
                }
                }
            }
            
            cout << "Программа завершена. Все списки удалены." << endl;
        }
};
    


int main(){

    char typeChoice;
    cout << "Введите тип данных: (i - int, d - double, f - float)" << endl;
    cin >> typeChoice;

    switch (typeChoice)
    {
    case 'i':
        LinkedLst<int>::Menu();
        break;

    case 'd':
        LinkedLst<double>::Menu();    
        break;

    case 'f':
        LinkedLst<float>::Menu();
        break;

    default:
        cout << "Неверный выбор, используется int по умолчанию " << endl;
        LinkedLst<int>::Menu();
        break;
    }
}