#include <iostream>
#include <string>
#include <memory>

enum class Insertion_method { push_back, push_front };

using namespace std;

template <typename value_type>
class List {
private:
struct node {
        value_type val;
       std::unique_ptr<node> next; // public since it does not compile
        node(const value_type v): val{v}, next{nullptr} {}
        ~node() = default;
  };
  

  
  
    std::unique_ptr<node> head;
    unsigned int _size;
    void push_back (const value_type& v); // append the newly created node at the end of the list
    void push_front (const value_type& v); // insert the newly created node in front of the list

public:


unsigned int size() const {return _size; } ; //returns the size

void insert(const value_type& v, const Insertion_method m); //insert the value in front or back, correspondig to the methodù
void print(); //prints the values
void reset(); //delete all the nodes
value_type prune_node(); // prune node storing the value at tail

List(){
    head = nullptr;
    _size = 0;
     };
~List() = default;


};

int main (){
    List<int> list;
    int value {55};
    list.print();
    cout << list.size() << endl; //expected 0
    list.insert( value, Insertion_method::push_front );
    cout << list.size() << endl; //expected 1
    list.print();
    list.insert( 77, Insertion_method::push_back);
    list.insert( 79, Insertion_method::push_back);
    cout << list.size() << endl; //expected 3
    list.print(); // expected 55 77 79
    int last_element {list.prune_node()};
    cout << last_element << endl; // expected 79
    list.print(); // expected 55 77
    list.reset();
    list.print(); // expected Null Pointer
    cout << list.size() << endl; //expected 0
    list.insert( 79, Insertion_method::push_back);
    list.print(); // expected 79
    last_element = list.prune_node();
    cout << last_element << endl; // expected 79
    cout << list.size() << endl; //expected 0;
    list.print(); //expected NUll pointer
    return 0;
    }
    
template <typename value_type>
void List<value_type>::print(){
if (head.get() == nullptr){
cout << "Null Pointer" << endl;
}
else{
    auto ptr_where = head.get();
    while (ptr_where != nullptr)
    {
        cout << ptr_where -> val << endl;
        ptr_where = ptr_where -> next.get();
    }
}
}



template<typename value_type>
void List<value_type>::push_back(const value_type& v) {
    if (!head){
        head.reset(new node(v));
    cout << "Sto qui" << endl;
    }
    else
    {
        //cout << "Sto qui su else" << endl;
        auto ptr = head.get();
        while (ptr -> next){
            ptr = ptr -> next.get();
            };
        ptr -> next.reset(new node(v));
    }
    _size = _size + 1;
}

template<typename value_type>
void List<value_type>::push_front(const value_type& v) {
    std::unique_ptr<node> p (new node(v));
    p -> next = std::move(head);
    head = std::move(p);
    _size = _size + 1;
}

template<typename value_type>
void List<value_type>::insert(const value_type& v, const Insertion_method m){
switch(m){
    case Insertion_method::push_back:
        push_back(v);
        break;
    case Insertion_method::push_front:
        push_front(v);      
        break;
}
}

template<typename value_type>
void List<value_type>::reset(){
    auto ptr = head.get();
    while (ptr -> next != nullptr){
    ptr -> next = std::move(head);
    head = nullptr;
    _size = 0;
}
}   


template<typename value_type>
value_type List<value_type>::prune_node()
{
    // This method does not handle the empty list case.
    auto prev_ptr = head.get();
    auto curr_ptr = prev_ptr;
    while (curr_ptr -> next != nullptr)
    {
        prev_ptr = curr_ptr;
        curr_ptr = curr_ptr -> next.get();
    }
    _size = _size - 1;
    if (prev_ptr == curr_ptr) // head points to the last item //Altrimenti non funziona, perché non entra nel ciclo while
    {    
        auto tmp = std::move(head);
        return tmp -> val;
    }
    else
    {
    auto tmp = std::move(prev_ptr -> next);
        return tmp -> val;
    
}
}

