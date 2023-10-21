#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T value;
    Node<T> *next;
    Node<T> *prev;
    Node(T val)
    {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};
template <typename T>
class DoublyLinkedList
{
    private: 
        Node<T>* head;
        Node<T>* tail;
    public:
        DoublyLinkedList()
        {
            head = nullptr;
            tail = nullptr;
        } 
        bool isEmpty()
        {
            return head == nullptr;
        }
        void insertAtTail(T val)
        {
            Node<T>* temp = new Node<T>(val);
            if (isEmpty())
            {
                head = temp;
                tail = temp;
            }
            else 
            {
                tail -> next = temp;
                temp -> prev = tail;
                tail = temp;
            }
        }
        void insertAtHead(T val)
        {
            Node<T>* temp = new Node<T>(val);
            if (isEmpty())
            {
                head = temp;
                tail = temp;
            }
            else
            {
                head -> prev = temp;
                temp -> next = head;
                head = temp;
            }
        }
        void insertAtMid(T val)
        {
            Node<T>* temp = new Node<T>(val);
            if (isEmpty())
            {
                head = temp;
                tail = temp;
            }
            else
            {
                Node<T>* fast = head -> next;
                Node<T>* slow = head;
                while (fast != nullptr && fast -> next != nullptr)
                {
                    fast = fast -> next -> next;
                    slow = slow -> next;
                }
                slow -> next -> prev = temp;
                temp -> next = slow -> next;
                temp -> prev = slow;
                slow -> next = temp;

            }
        }
        void reverse()
        {
            Node<T>* temp = tail;
            while (temp != nullptr)
            {
                cout << temp -> value <<" ";
                temp = temp -> prev;
            }
            
        }
        void display()
        {
            Node<T>* temp = head;
            while (temp != nullptr)
            {
                cout << temp -> value <<" ";
                temp = temp -> next;
            }
        }
};


int main()
{
    DoublyLinkedList<int> obj;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtHead(0);
    obj.insertAtHead(-1);
    obj.insertAtHead(-2);
    obj.insertAtMid(0);
    // obj.reverse();
    obj.display();


}

