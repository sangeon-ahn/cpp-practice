#include <iostream>
// #include "node.h"
#include "linkedList.h"

using namespace std;

int main()
{
    try {
        LinkedList ll;

        // insert 테스트
        ll.insert(10);
        ll.insert(20);

        // insert 테스트 2
        ll.insert(100, 1);
        cout << ll.at(1)->getItem() << endl;
        
        // at 테스트
        auto res = ll.at(0);
        cout << res->getItem() << endl;

        // search 테스트
        cout << ll.search(20)->getItem() << endl;

        // delete 테스트1
        ll.delete_by_index(0);
        cout << ll.at(0)->getItem() << endl; 

        // delete 테스트2
        ll.delete_by_item(20);
        cout << ll.at(0)->getItem() << endl;

        // 링크드리스트 메모리 해제 테스트
        LinkedList* ll2 {new LinkedList{}};

        ll2->insert(1);
        ll2->insert(2);
        ll2->insert(3);
        ll2->insert(4);

        delete ll2;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}