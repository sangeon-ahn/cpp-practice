#include <memory>
#include <optional>
#include <exception>
#include <iostream>
#include "node.h"

class LinkedList
{
    public:
        LinkedList() = default;
        ~LinkedList();
        LinkedList(const LinkedList& rhs) = default;

        Node* search(int item);
        Node* at(int index);
        Node* insert(int item);
        Node* insert(int item, int index);
        void delete_by_item(int item);
        void delete_by_index(int index);

    private:
        Node* m_head { new Node{} };
        Node* h_find_by_item(int item);
        Node* h_find_by_index(int index);
        Node* h_find_last();
        void delete_node(Node* prev);
};

void LinkedList::delete_node(Node* prev)
{
    Node* nxt = prev->getNext()->getNext();
    delete prev->getNext();

    prev->setNext(nxt);
}

LinkedList::~LinkedList()
{
    std::cout << "linkedlist destructor called." << std::endl;
    Node* curr { m_head };
    Node* nxt { m_head->getNext() };

    while (nxt) {
        delete curr;
        curr = nxt;
        nxt = nxt->getNext();
    }
    
    delete curr;
    curr = nullptr;
}

Node* LinkedList::search(int item)
{
    return h_find_by_item(item);
}

Node* LinkedList::at(int index)
{
    return h_find_by_index(index + 1);
}

Node* LinkedList::insert(int item)
{
    auto tail { h_find_last() };
    if (tail) {
        auto newP = new Node{item};
        tail->setNext(newP);
        return tail->getNext();
    }
    return nullptr;
}

Node* LinkedList::insert(int item, int index)
{
    auto target { h_find_by_index(index) };

    auto newP { new Node{item} };
    auto nxt { target->getNext() };

    target->setNext(newP);

    if (nxt) {
        newP->setNext(nxt);
    }

    return newP;
}

void LinkedList::delete_by_item(int item)
{
    Node* prev { m_head };
    Node* curr { prev->getNext() };

    while (curr) {
        if (curr->getItem() == item) {
            delete_node(prev);
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }

    throw std::invalid_argument{"해당 아이템이 없습니다."};
}

void LinkedList::delete_by_index(int index)
{
    int temp { 0 };
    Node* prev { m_head }; 
    Node* curr { prev->getNext() };

    while (temp < index) {
        if (!curr) {
            throw std::out_of_range{"리스트 범위 벗어나는 인덱스가 입력되었습니다."};
        }
        
        prev = curr;
        curr = curr->getNext();
        ++temp;
    }

    delete_node(prev);
}

Node* LinkedList::h_find_by_item(int item)
{
    Node* curr { m_head };
    
    while (curr) {
        if (curr->getItem() == item) {
            return curr;
        }
        curr = curr->getNext();
    }

    throw std::invalid_argument{"해당 아이템을 찾을 수 없습니다."};
}

Node* LinkedList::h_find_by_index(int index)
{
    Node* curr { m_head };
    int temp { 0 };

    while (curr && temp < index) {
        curr = curr->getNext();
        ++temp;
    }

    if (temp == index && curr) {
        return curr;
    }

    throw std::out_of_range{"해당 인덱스가 리스트 범위를 초과합니다."};
}

Node* LinkedList::h_find_last()
{
    Node* curr { m_head };
    
    while (curr->getNext()) {
        curr = curr->getNext();
    }

    return curr;
}
