
노드 필요
노드가 담는 값
- item 가리키는 포인터. 여기서 item은 또다른 객체의 주소값이면 될듯(x) -> 일단 int 타입 primitive 담도록 만든다.
- 다음 노드 가리키는 포인터

포인터 -> c면 포인터일텐데, c++면 unique_ptr? -> 동적할당임.힙에 저장할 때,
스택에 저장할 때는? 아하 stl template으로 만드는 vector은 내부적으로 동적할당이 이루어지는 자료구조다.
따라서, linked_list 또한 동적할당으로 만들면 되므로 unique_ptr로 받으면 될 것 같다.

그리고 일단 하나의 타입 특화된 링크드리스트를 구현한 후, 템플릿을 사용한 구현으로 개선해나가면 된다.


필요한 멤버변수: 리스트의 헤드
필요한 메서드: search, insert, delete, update
- search??
    - 인자: item 기준 가장 첫번째
- at
    - 인자: index
- insert?? item 값을 추가
    - 인자: (item)
    - overload1 인자: (item, order)
- delete
    - item 기준 첫번째 발견
    - index 기준

1. 일반 포인터 사용하여 구현
+ 참조 추가해서 구현.
2. 1번 결과 리팩토링
3. 스마트 포인터 사용하여 구현
4. 3번 결과 리팩토링
5. best practice 확인
