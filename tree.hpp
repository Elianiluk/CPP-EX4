#include <iostream>
#include "node.hpp"

namespace std
{
    template <typename T, int N=2> class Tree
    {
    public:
        Tree() : root(nullptr) {}
        void add_root(Node<T>& root){this->root = &root;}
        void add_sub_node(Node<T>& parent, Node<T>& child){
            if(parent.get_children().size() < N)
                parent.add_child(child);
            else
                cout << "The parent has reached the maximum number of children" << endl;
        }
        Node<T> begin_pre_order(){return *root;}
        Node<T> end_pre_order();
        Node<T> begin_post_order();
        Node<T> end_post_order();
        Node<T> begin_in_order();
        Node<T> end_in_order();
        Node<T> begin_bfs_scan();
        Node<T> end_bfs_scan();
        Node<T> begin();
        Node<T> end();
        T print(){return root->get_value();}
    private:
        Node<T> *root;
        // int num;
    };
} 