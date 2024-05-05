#include <memory>
#include <optional>
#include <exception>
#include <iostream>
// #include "node.h"

class LinkedList
{
    private:
        class Node
        {
            public:
                Node() = default;
                Node(int item) : m_item{item} {}
                ~Node();

                int getItem() const { return m_item; }
                void setItem(int item) { m_item = std::move(item); }
                void setNext(Node* p) {m_next = std::move(p); }
                Node* getNext() {return m_next;}
            private:
                int m_item {0};
                Node* m_next {nullptr};
        };

        LinkedList::Node* m_head { new LinkedList::Node{} };
        LinkedList::Node* h_find_by_item(int item);
        LinkedList::Node* h_find_by_index(int index);
        LinkedList::Node* h_find_last();
        void delete_node(LinkedList::Node* prev);

    public:
        LinkedList() = default;
        ~LinkedList();
        LinkedList(const LinkedList& rhs) = default;

        LinkedList::Node* search(int item);
        LinkedList::Node* at(int index);
        LinkedList::Node* insert(int item);
        LinkedList::Node* insert(int item, int index);
        void delete_by_item(int item);
        void delete_by_index(int index);
};

LinkedList::Node::~Node()
{
    std::cout << "LinkedList::Node destructor called." << std::endl;
}

void LinkedList::delete_node(LinkedList::Node* prev)
{
    LinkedList::Node* nxt = prev->getNext()->getNext();
    delete prev->getNext();

    prev->setNext(nxt);
}

LinkedList::~LinkedList()
{
    std::cout << "linkedlist destructor called." << std::endl;
    LinkedList::Node* curr { m_head };
    LinkedList::Node* nxt { m_head->getNext() };

    while (nxt) {
        delete curr;
        curr = nxt;
        nxt = nxt->getNext();
    }
    
    delete curr;
    curr = nullptr;
}

LinkedList::Node* LinkedList::search(int item)
{
    return h_find_by_item(item);
}

LinkedList::Node* LinkedList::at(int index)
{
    return h_find_by_index(index + 1);
}

LinkedList::Node* LinkedList::insert(int item)
{
    auto tail { h_find_last() };
    if (tail) {
        auto newP = new LinkedList::Node{item};
        tail->setNext(newP);
        return tail->getNext();
    }
    return nullptr;
}

LinkedList::Node* LinkedList::insert(int item, int index)
{
    auto target { h_find_by_index(index) };

    auto newP { new LinkedList::Node{item} };
    auto nxt { target->getNext() };

    target->setNext(newP);

    if (nxt) {
        newP->setNext(nxt);
    }

    return newP;
}

void LinkedList::delete_by_item(int item)
{
    LinkedList::Node* prev { m_head };
    LinkedList::Node* curr { prev->getNext() };

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
    LinkedList::Node* prev { m_head }; 
    LinkedList::Node* curr { prev->getNext() };

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

LinkedList::Node* LinkedList::h_find_by_item(int item)
{
    LinkedList::Node* curr { m_head };
    
    while (curr) {
        if (curr->getItem() == item) {
            return curr;
        }
        curr = curr->getNext();
    }

    throw std::invalid_argument{"해당 아이템을 찾을 수 없습니다."};
}

LinkedList::Node* LinkedList::h_find_by_index(int index)
{
    LinkedList::Node* curr { m_head };
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

LinkedList::Node* LinkedList::h_find_last()
{
    LinkedList::Node* curr { m_head };
    
    while (curr->getNext()) {
        curr = curr->getNext();
    }

    return curr;
}
