#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *link;
};

struct HeadNode{
    Node *head;
};

class List{
    public:
    HeadNode *H;
    List(){
        H = new HeadNode;
        H->head = NULL;
    }
    void push_back(int value){
        Node* _new = new Node;
        Node* _back;
        _new -> data = value;
        _new -> link = NULL;
        if(H->head == NULL){
            H -> head = _new;
            return;
        }
        else{
            _back = H -> head; // 탐색 시작
            while(_back -> link != NULL){
                _back = _back -> link;
            }
            _back -> link = _new; //연결
        }
        // 모든 노드를 거쳐야 하므로 시간 복잡도는 O(N)
    }
    void push_front(int value){
        Node* _new = new Node;
        _new -> data = value;
        _new -> link = NULL;
        if(H->head == NULL) H -> head = _new;
        else{
            _new -> link = H -> head; // 연결
        }
        H->head = _new;
        // 가장 앞에 삽입할 때는 O(1)
    }
    void pop_back(){
        if(H -> head == NULL) return; // 예외처리
        else if(H -> head -> link == NULL){ // 노드가 하나만 있는 경우
            delete H->head; // 메모리 누수 방지는 언제나 중요
            H-> head = NULL; 
            return;
        }
        else{
            Node * _back;
            Node * _del;
            _back = H->head;
            _del = _back -> link;
            while(_del -> link != NULL){
                _back = _del;
                _del = _back -> link; // _back 과 _del 동시에 이동
            }
            delete _del;
            _back -> link = NULL;
        }
    }
    void pop_front(){
        if(H -> head == NULL) return;
        else if(H-> head -> link == NULL){
            delete H-> head;
            H->head = NULL;
        }
        else{
            Node *tmp = H -> head;
            //반환 필요하면 int data = tmp -> data;
            H -> head = H->head->link; //두 번째 노드를 헤드 노드로 설정
            delete tmp;
        }
    }

    int find(int data_to_find){
        int idx = 0;
        Node *node = H -> head;
        if(node == NULL) return -1;
        while(node -> data != data_to_find){
            if(node -> link == NULL) return -1;
            node = node -> link;
            idx++;
        }
        return idx;
    }

    void replace(int idx, int data_to_replace){
        int cnt = 0;
        Node *node = H -> head;
        while(cnt != idx){
            if(node -> link == NULL){
                cout<<"fail to replace\n";
                return;
            }
            node = node -> link;
            cnt++;
        }
        node -> data = data_to_replace;
        return;
    }

    int size(){
        int res = 0;
        Node *node = H->head;
        while(node != NULL){
            node = node -> link;
            res++;
        }
        return res;
    }
    
    void print(int idx){
        int cnt = 0;
        Node *node = H->head;
        while(cnt != idx){
            if(node -> link == NULL){
                cout<<"Wrong Index Error\n";
            }
            node = node -> link;
            cnt++;
        }
        cout << node->data;
    }
    void print_all(){
        Node *node = H -> head;
        while(node != NULL){
            cout<< node -> data<<" ";
            node = node -> link;
        }
    }
    void debug(){
        cout<<"#current list size : "<<size()<<endl;
        cout<<"#current list items : ";
        print_all();
        cout<<endl;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    List list;

    int n;
    cout<<"\n == push front  check ==\n";
    for(int i = 0; i< 10; ++i){
        list.push_front(i);
    }
    list.debug();
    cout<<"\n == push back check == \n";
    for(int i = 0; i < 10; ++i){
        list.push_back(i);
    }
    list.debug();

    cout<<"\n == pop_back, pop front check ==\n";
    for(int i = 0; i < 20; ++i){
        list.pop_front();
    }
    list.push_front(1);
    list.debug();


    return 0;
}