#include <iostream>
#include "node.hpp"
#include "iterators.hpp"

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
        Node<T>& begin_pre_order() { return *root; }
        Node<T>& end_pre_order() { return *root; }
        Node<T>& begin_post_order() { return *root; }
        Node<T>& end_post_order() { return *root; }
        Node<T>& begin_in_order() { return *root; }
        Node<T>& end_in_order() { return *root; }
        Node<T>& begin_bfs_scan() { return *root; }
        Node<T>& end_bfs_scan() { return *root; }
        Node<T>& begin() { return *root; }
        Node<T>& end() { return *root; }

        PreOrderIterator<T> pre_order_begin() { 
            // std::cout << "pre_order_begin" << std::endl;
            return PreOrderIterator<T>(root); 
        }
        PreOrderIterator<T> pre_order_end() {
            // std::cout << "pre_order_end" << std::endl;
            return PreOrderIterator<T>(nullptr); 
        }
        InOrderIterator<T> in_order_begin() { return InOrderIterator<T>(root); }
        InOrderIterator<T> in_order_end() { return InOrderIterator<T>(nullptr); }
        PostOrderIterator<T> post_order_begin() { return PostOrderIterator<T>(root); }
        PostOrderIterator<T> post_order_end() { return PostOrderIterator<T>(nullptr); }

        T print(){return root->get_value();}

        void print_tree()
        {
            if (!root)
            {
                std::cout << "Tree is empty." << std::endl;
                return;
            }

            print_subtree(root, "");
        }

        void print_subtree(Node<T>* node, const std::string& prefix)
        {
            if (!node)
            {
                return;
            }

            std::cout << prefix << node->get_value() << std::endl;

            auto& children = node->get_children();
            for (size_t i = 0; i < children.size(); ++i)
            {
                bool is_last = (i == children.size() - 1);
                print_subtree(&children[i], prefix + (is_last ? "└── " : "├── "));
            }
        }
    private:
        Node<T> *root;
        // int num;
    };
} 