#include <iostream>
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
};
    
   

int main(){
    LinkedLst list1;
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

}