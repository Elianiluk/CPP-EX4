#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include "node.hpp"
#include "iterators.hpp"

namespace std
{
    template <typename T, int N = 2>
    class Tree
    {
    public:
        Tree() : root(nullptr) {}

        void add_root(Node<T> &root)
        {
            this->root = &root;
        }

        void add_sub_node(Node<T> &parent, Node<T> &child)
        {
            if (parent.get_children().size() < N)
            {
                parent.add_child(&child);
            }
            else
            {
                std::cout << "The parent has reached the maximum number of children" << std::endl;
            }
        }

        PreOrderIterator<T> begin_pre_order() { return PreOrderIterator<T>(root); }
        PreOrderIterator<T> end_pre_order() { return PreOrderIterator<T>(nullptr); }
        InOrderIterator<T> begin_in_order() { return InOrderIterator<T>(root); }
        InOrderIterator<T> end_in_order() { return InOrderIterator<T>(nullptr); }
        PostOrderIterator<T> begin_post_order() { return PostOrderIterator<T>(root); }
        PostOrderIterator<T> end_post_order() { return PostOrderIterator<T>(nullptr); }
        BFSIterator<T> begin_bfs_scan() { return BFSIterator<T>(root); }
        BFSIterator<T> end_bfs_scan() { return BFSIterator<T>(nullptr); }
        DFSIterator<T> begin_dfs_scan() { return DFSIterator<T>(root); }
        DFSIterator<T> end_dfs_scan() { return DFSIterator<T>(nullptr); }

        void print_tree()
        {
            if (!root)
            {
                std::cout << "Tree is empty." << std::endl;
                return;
            }

            print_subtree(root, "");
        }

    private:
        Node<T> *root;

        void print_subtree(Node<T> *node, const std::string &prefix)
        {
            if (!node)
            {
                return;
            }

            std::cout << prefix << node->get_value() << std::endl;

            auto &children = node->get_children();
            for (size_t i = 0; i < children.size(); ++i)
            {
                bool is_last = (i == children.size() - 1);
                print_subtree(children[i], prefix + (is_last ? "└── " : "├── "));
            }
        }
    };
}

#endif // TREE_HPP
