    #include <iostream>
    #include <map>
    #include <string>
    using namespace std;

    class Node{
        private:
            Node* next;
            int val;

        public:
            Node(int data){
                this->next = nullptr;
                val = data;
            }
            virtual ~Node() = default;
            friend class LinkedLst;
        };


    class LinkedLst{
        private:
            Node* head;
            Node* tail;
            int size = 0;

        public:
            LinkedLst(){
                this->head = nullptr;
                this->tail = nullptr;
                this->size = 0;
            }
            virtual ~LinkedLst() = default;



            void addElem(int data){
                Node* node = new Node(data);
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

            void deleteElem (int data){
                Node* curr = head;
                Node* prev = nullptr;
                while(curr != nullptr){
                    if (curr->val == data){
                        if (curr == head){
                            head = curr->next;
                            size--;
                        }else{
                            if (curr == tail){
                                tail = prev;
                                if (tail != nullptr) tail->next = nullptr;
                                size--;
                            }else{
                                prev->next = curr->next;
                                size--;
                            }
                        }
                    }else{
                        prev = curr;
                    }
                    curr = curr->next;
                }
            }

            void printList(){
                Node* curr = head;
                while(curr != nullptr){
                    cout << curr->val << " -> "; 
                    curr = curr->next;
                }
                cout << "null, size: " << size;
                cout << endl;
            }

            int& operator[](int index){
                if (index < 0 || index >= size) {
                    throw out_of_range("Неправильный индекс");
                }
                
                Node* curr = head;
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

            friend LinkedLst operator+(const LinkedLst& list1, const LinkedLst& list2){
                LinkedLst result;

                Node* curr1 = list1.head;
                Node* curr2 = list2.head;

                while(curr1 != nullptr && curr2 != nullptr){

                    int sum = curr1->val + curr2->val;
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

        friend LinkedLst operator-(const LinkedLst& list1, const LinkedLst& list2){
            LinkedLst result;
            Node* curr1 = list1.head;
            Node* curr2 = list2.head;

            while (curr1 != nullptr && curr2 != nullptr){
                int razn = curr1->val - curr2->val;
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

        public:
            static void Menu(){
                int znach;
                bool flag = true;
                map<string, LinkedLst*> lists;
                while(flag){

                    cout << endl;
                    cout << "======= Меню =======" << endl;
                    cout << "1: Добавить список." << endl;
                    cout << "2: Добавить значение для Node." << endl;
                    cout << "3: Удалить значение Node." << endl;
                    cout << "4: Сложение списков.(+)" << endl;
                    cout << "5: Вычитание списков.(-)" << endl;
                    cout << "6: Вывести значение по индексу.[]" << endl;
                    cout << "7: Вывести весь список." << endl;
                    cout << "0: Выйти из программы." << endl;
                    cout << "====================" << endl;

                    cout << endl;
                    cout << "Все списки: " << endl;
                    for (auto& elem: lists){
                        cout << elem.first << " | size: " << elem.second->size << endl;
                    }
                    cout << endl;

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
                            lists[nazvan] = new LinkedLst();
                            cout << "Список создан!" << endl;
                        }
                        break;
                    }

                    case 2: {
                        cout << "Введите название списка: " << endl;
                        cin >> nazvan;
                        int data;
                        bool flas = true;

                        if (lists.find(nazvan) != lists.end()){
                            while (flas){
                                cout << "Введите значение Node: " << endl;
                                cin >> data;
                                if (data != 0){
                                    lists[nazvan]->addElem(data);
                                }else{
                                    flas = false;
                                }
                            }
                        }
                        break;
                    }

                    case 3: {
                        cout << "Введите название списка: " << endl;
                        cin >> nazvan;
                        int data;

                        if (lists.find(nazvan) != lists.end()){
                                cout << "Введите значение Node: " << endl;
                                cin >> data;
                                lists[nazvan]->deleteElem(data);
                                }else{
                                    cout << "Такого элемента нет!" << endl;
                                }
                        break;
                    }
    

                    case 4: {
                        string num1;
                        string num2;
                        string result;
                        cout << "1 список: " << endl;
                        cin >> num1;
                        cout << "2 список: " << endl;
                        cin >> num2;

                        if (lists.find(num1) != lists.end() && lists.find(num2) != lists.end()) {
                            lists[result] = new LinkedLst();
                            
                            LinkedLst sum_result = *lists[num1] + *lists[num2];
                            
                            cout << "Результат:" << endl;
                            sum_result.printList();
                    } else {
                        cout << "Списка нет!" << endl;
                    }
                    break;
                    }
                    
                    case 5: {
                        string num1;
                        string num2;
                        string result;
                        cout << "1 список: " << endl;
                        cin >> num1;
                        cout << "2 список: " << endl;
                        cin >> num2;

                        if (lists.find(num1) != lists.end() && lists.find(num2) != lists.end()) {
                            lists[result] = new LinkedLst();
                            
                            LinkedLst raz_result = *lists[num1] - *lists[num2];
                            
                            cout << "Результат:" << endl;
                            raz_result.printList();
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
                            lists[nazvan]->printList();
                        }
                        break;
                    }

                    default:{
                        cout << "Неверный выбор!" << endl;
                    break;
                    }

                    case 0:{
                        flag = false;
                        break;
                    }
                    }
                        
                }
            }
    };
        
    

    int main(){

        LinkedLst::Menu();

    /* LinkedLst list1;
        LinkedLst list2;

        list1.addElem(13);
        list1.addElem(26);
        list2.addElem(44);
        list2.addElem(54);
        list2.addElem(15);
        list2.addElem(33);

        list2.deleteElem(15);
        
        LinkedLst sum = list1 + list2;
        LinkedLst raz = list2 - list1;

        cout << "1 список: ";
        list1.printList();
        cout << "2 список: ";
        list2.printList();
        cout << endl;

        cout << "(+): ";
        sum.printList();
        cout << "(-): ";
        raz.printList();
        */

    }