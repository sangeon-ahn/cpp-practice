
#ifndef NODE
#define NODE
#include <memory>
#include <iostream>
class Node
{
    public:
        Node() = default;
        Node(int item) : m_item{item} {}
        ~Node();

        int getItem() const { return m_item; }
        void setItem(int item) { m_item = std::move(item); }
        Node* getNext() {return m_next;}
        void setNext(Node* p) {m_next = std::move(p); }

    private:
        int m_item {0};
        Node* m_next {nullptr};
};

Node::~Node()
{
    std::cout << "Node destructor called." << std::endl;
}

#endif