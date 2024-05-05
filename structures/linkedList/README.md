노드 멤버변수들
- item 가리키는 포인터. 여기서 item은 또다른 객체의 주소값이면 될듯(x) -> 일단 int 타입 primitive 담도록 만든다.
- 다음 노드 가리키는 포인터

포인터 -> c면 포인터일텐데, c++면 unique_ptr? -> 동적할당임. 힙에 저장할 때,
스택에 저장할 때는? 링크드 리스트를 스택에 만들었으면 리스트는 스코프 벗어나면 자동해제되고, 노드는 동적할당으로 만드므로 처리 해줘야 함.

stl template으로 만드는 vector은 내부적으로 동적할당이 이루어지는 자료구조다.
따라서, linked_list 노드 또한 동적할당으로 만들면 되므로 unique_ptr로 받으면 될 것 같다. -> 일단 일반 포인터로 구현하고 개선해나가기.

일단 하나의 타입 특화 링크드리스트를 구현한 후, 템플릿을 사용한 구현으로 개선해나간다.

멤버변수: 리스트의 헤드
메서드: search, insert, delete, update
- search
    - 가장 먼저 등장하는 item 노드 반환
    - 인자: item
- at
    - index번째 노드 반환
    - 인자: index
- insert
    - func1: item 노드를 맨 뒤에 추가
        - 인자: item
    - func2: item 노드를 index 위치에 추가
        - 인자: item, index
- delete
    - func1: item값 가지는 노드 삭제
        - 인자: item
    - func2: index 위치 노드 삭제
        - 인자: index

### 1단계: 일반 포인터 사용하여 구현
- 피드백: 참조자 사용하지 않았고 스마트 포인터가 아닌 일반 포인터로만 구현했기 때문에 destructor에서 수동 delete로 메모리 해제.
### 2단계: 참조자, 스마트 포인터 사용하여 구현
### 3단계: 템플릿 사용하여 구현
### 4단계: best practice 확인
