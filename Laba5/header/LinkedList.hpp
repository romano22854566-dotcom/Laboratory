#include <iostream>

template <typename Type>
class LinkedList {
private:
    struct Node {
        Type data;
        Node* next;
        Node(const Type& value): data(value),next(nullptr) {}
    };

    Node* head;
    int count;

public:
    LinkedList(): head(nullptr),count(0) {}
    ~LinkedList() { clear(); }

    void pushFront(const Type& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++count;
    }

    void pushBack(const Type& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        ++count;
    }

    bool popFront() {
        if (!head) return false;
        Node* temp = head;
        head = head->next;
        delete temp;
        --count;
        return true;
    }

    bool popBack() {
        if (!head) return false;
        if (!head->next) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        --count;
        return true;
    }

    bool removeAt(int index) {
        if (index < 0 || index >= count) return false;
        if (index == 0) return popFront();

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) temp = temp->next;

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        --count;
        return true;
    }

    void printList() const {
        if (isEmpty()) {
            std::cout << "Список пуст\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            std::cout << temp->data;
            if (temp->next) std::cout << " -> "; 
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void clear() {
        while (head) popFront();
    }

    bool isEmpty() const { return head == nullptr; }
    int size() const { return count; }
};


