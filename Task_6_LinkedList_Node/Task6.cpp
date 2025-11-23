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
            cout << "null " << size;
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

    };
   

int main(){
    LinkedLst list;
    list.addElem(13);
    list.addElem(26);
    list.addElem(44);
    list.addElem(54);
    list.printList();

    list.deleteElem(44);

    list.printList();
    cout << list[2] << endl;
    list[2] = 144;
    list.printList();

}