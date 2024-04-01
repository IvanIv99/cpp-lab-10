#include <iostream>
#include <string>

template <typename T>
class MyDeck {

private:
    class Node {
    public:
        T data;
        Node* previous;
        Node* next;
        Node(T item,Node* previousNode,Node* nextNode):
                data(item), previous(previousNode), next(nextNode) {}
    };
    Node* begin;
    Node* end;
    size_t Size;

public:
    MyDeck() :begin(nullptr), end(nullptr), Size(0) {}
    void push_back(T item){
        if (begin==nullptr){
            begin=new Node(item,nullptr,nullptr);
            end=begin;
        }
        else{
            end->next=new Node(item,end,nullptr);
            end=end->next;
        }
        Size++;
    }

    void pop_back(){
        if (end!=nullptr){
            end=end->previous;
            if (end!=nullptr){
                end->next=nullptr;
            }
            else{
                begin=nullptr;
            }
            Size--;
        }
    }
    void push_front(T item){
        if (begin==nullptr){
            begin=new Node(item,nullptr,nullptr);
            end=begin;
        }
        else{
            begin->previous=new Node(item,nullptr,begin);
            begin=begin->previous;
        }
        Size++;
    }
    void pop_front(){
        if (begin!=nullptr){
            begin=begin->next;
            if (begin!=nullptr){
                begin->previous=nullptr;
            }
            else{
                end=nullptr;
            }
            Size--;
        }
    }
    size_t size() const{
        return Size;
    }

    friend std::ostream& operator<<(std::ostream& o, const MyDeck<T>& Deck){
        Node *a=Deck.begin;
        while (a!=nullptr)
        {
            o << a->data << " ";
            a=a->next;
        }
        return o;
    }
};

int main(){
    MyDeck<int> Deck;
    Deck.push_back(2);
    Deck.push_back(3);
    Deck.push_front(1);

    std::cout << Deck.size() << std::endl;

    std::cout << Deck << std::endl;

    Deck.pop_back();
    std::cout << Deck << std::endl;

    Deck.pop_front();
    std::cout << Deck << std::endl;

    return 0;
}
