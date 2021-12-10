#include<iostream>
//#include "binary_tree.h"
using namespace std;

template <class T>
class binary_tree
{
public:
    binary_tree(const T &arg): value(arg), left(NULL), right(NULL) {}
    ~binary_tree() {}
    //=================================

    T get_value() { return this->value; }
    binary_tree<T> *go_right() { return this->right; }
    binary_tree<T> *go_left() { return this->left; }
    void set_left(binary_tree<T> *arg) { this->left = arg; }
    void set_right(binary_tree<T> *arg) { this->right = arg; }

    
    binary_tree *left, *right;
private:
    T value;
};
template <class T>
void parcurgere_postordine( binary_tree<T> arg ){
    if( arg.go_left() != NULL ) parcurgere_postordine( *arg.go_left() );
    if( arg.go_right() != NULL ) parcurgere_postordine( *arg.go_right() );
    cout << arg.get_value() << " ";

}
template <class T>
void parcurgere_preordine( binary_tree<T> arg ){
    cout << arg.get_value() << " ";
    if( arg.go_left() != NULL ) parcurgere_preordine( *arg.go_left() );
    if( arg.go_right() != NULL ) parcurgere_preordine( *arg.go_right() );
}
template <class T>
void parcurgere_inordine( binary_tree<T> arg ){
    if( arg.go_left() != NULL ) parcurgere_inordine( *arg.go_left() );
    cout << arg.get_value() << " ";
    if( arg.go_right() != NULL ) parcurgere_inordine( *arg.go_right() );
}
/* arborele binar:
      A
    /   \
   B     C
  / \   /  \
 D  0  0    E

*/
int main()
{
    binary_tree<char> root('A');
    binary_tree<char> roots_left('B'); root.set_left( &roots_left );
    binary_tree<char> roots_right('C'); root.set_right( &roots_right );

    binary_tree<char> roots_rights_right('E'); roots_right.set_right( &roots_rights_right );
    binary_tree<char> roots_lefts_left('D'); roots_left.set_left( &roots_lefts_left );
    // initialization

    cout<<"preordine:\n";
    parcurgere_preordine(root);
    
    cout<<"\n\ninordine:\n";
    parcurgere_inordine(root);

    cout<<"\n\npostordine:\n";
    parcurgere_postordine(root);
}