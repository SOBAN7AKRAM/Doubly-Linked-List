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
class ForwardIterator
{  
private:
    Node<T>* current;
public: 
    ForwardIterator(Node<T>* node)
    {
        current = node;
    }
    T operator*()
    {
        return current -> value;
    }
    ForwardIterator<T>& operator++()
    {
        current = current -> next;
        return *this;
    }
    bool operator!=(const ForwardIterator<T>& other)
    {
        return current != other.current;
    }
    bool operator==(const ForwardIterator<T>& other)
    {
        return current == other.current;
    }


};
template <typename T>
class ReverseIterator
{
private:
    Node<T>* current;
public:
    ReverseIterator(Node<T>* node)
    {
        current = node;
    }
    T operator*()
    {
        return current -> value;
    }
    ReverseIterator<T>& operator++()
    {
        current = current -> prev;
        return *this;
    }
    bool operator!=(const ReverseIterator<T>& other)
    {
        return current != other.current;
    } 
    bool operator==(const ReverseIterator<T>& other)
    {
        return current == other.current;
    }
};
template <typename T>
class Iterator
{
private:
    Node<T>* current;
public:
    Iterator(Node<T>* node)
    {
        current = node;
    }
    T operator*()
    {
        return current -> value;
    }
    Iterator<T>& operator++()
    {
        current = current -> next;
        return *this;
    }
    Iterator<T>& operator--()
    {
        current = current -> prev;
        return *this;
    }
    bool operator!=(const Iterator<T>& other)
    {
        return current != other.current;
    }
    bool operator==(const Iterator<T>& other)
    {
        return current == other.current;
    }
    Node<T>* getNode()
    {
        return current;
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
        void insertAtAfter(T val, T key)
        {
            if (tail -> value == val)
            {
                insertAtTail(key);
                return;
            }
            Node<T>* temp = new Node<T>(key);
            Node<T>* slow = head;
            while (slow -> value != val)
            {
                slow = slow -> next;
            }
            temp -> next = slow -> next;
            slow -> next = temp;
            temp -> prev = slow;
            temp -> next -> prev = temp;

        }
        void insertAtBefore(T val, T key)
        {
            if (head -> value == val)
            {
                insertAtHead(key);
                return;
            }
            Node<T>* temp = new Node<T>(key);
            Node<T>* slow = head;
            while (slow -> value != val)
            {
                slow = slow -> next;
            }
            slow -> prev -> next = temp;
            temp -> prev = slow -> prev;
            temp -> next = slow;
            slow -> prev = temp;

        }
        void insertAtAfter(Node<T>* address, T val)
        {
            if (address == tail)
            {
                insertAtTail(val);
                return;
            }
            Node<T>* temp = new Node<T>(val);
            temp -> next = address -> next;
            temp -> prev = address;
            temp -> prev -> next = temp;
        }
        void insertAtBefore(Node<T>* address, T val)
        {
            if (address == head)
            {
                insertAtHead(val);
                return;
            }
            Node<T>* temp = new Node<T>(val);
            temp -> next = address;
            temp -> prev = address -> prev;
            address -> prev -> next = temp;
            address -> prev = temp;

        }
        void removeAtFront()
        {
            if (isEmpty())
            {
                cout << "List is Empty nothing to remove!" << endl;
                return;
            }
            else if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else 
            {
                Node<T>* temp = head;
                head = head -> next;
                head -> prev = nullptr;
                delete temp;
            }
        }
        void removeAtEnd()
        {
            if (isEmpty())
            {
                cout << "List is Empty nothing to remove!" << endl;
                return;
            }
            else if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else 
            {
                Node<T>* temp = tail;
                tail = tail -> prev;
                tail -> next = nullptr;
                delete temp;
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
        ForwardIterator<T> fbegin()
        {
            return ForwardIterator<T>(head);
        }
        ForwardIterator<T> fend()
        {
            return ForwardIterator<T>(nullptr);
        }
        ReverseIterator<T> rbegin()
        {
            return ReverseIterator<T>(tail);
        }
        ReverseIterator<T> rend()
        {
            return ReverseIterator<T>(nullptr);
        }
        Iterator<T> begin()
        {
            return Iterator<T>(head);
        }
        Iterator<T> end()
        {
            return Iterator<T>(nullptr);
        }
        Iterator<T> tailEnd()
        {
            return Iterator<T> (tail);
        }


        void splice(Node<T>* start, DoublyLinkedList<T> obj)
        {
            Node<T>* last = start -> next;
            Iterator<T> it = obj.begin();
            Node<T>* temp = it.getNode();
            Iterator<T> ib = obj.tailEnd();
            Node<T>* tempLast = ib.getNode();
            start -> next = temp;
            temp -> prev = start;
            last -> prev = tempLast;
            tempLast -> next = last;
            last -> next = nullptr; 
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
    DoublyLinkedList<int> obj2;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(6);
    obj.insertAtHead(0);


    obj2.insertAtTail(3);
    obj2.insertAtTail(4);
    obj2.insertAtTail(5);

    Iterator<int> it = obj.begin();
    ++it;
    ++it;
    Node<int>* temp = it.getNode();
    obj.splice(temp, obj2);
    obj.display();


    // obj.insertAtHead(-1);
    // obj.insertAtHead(-2);
    // obj.insertAtMid(0);
    // obj.reverse();
    // obj.insertAtAfter(2, 3);
    // obj.insertAtBefore(0, -1);
    // obj.removeAtFront();
    // obj.removeAtEnd();
    //cout <<endl;
    // Iterator<int> it = obj.tailEnd();
    // Node<int>* temp = it.getNode();
    // obj.insertAtAfter(temp, 3);
    // Iterator<int> b = obj.begin();
    // Node<int>* t = b.getNode();
    // obj.insertAtBefore(t, 8);
    // obj.display();
    // cout << endl;
    // ForwardIterator<int> it = obj.fbegin();
    // ForwardIterator<int> end = obj.fend();
    //  ReverseIterator<int> it = obj.rbegin();
    // ReverseIterator<int> end = obj.rend();
    // Iterator<int> it = obj.begin();
    // Iterator<int> end = obj.end();
    // while (it != end)
    // {
    //     cout << *it << " ";
    //     ++it;
    // } 


}

