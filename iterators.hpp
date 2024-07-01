#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "node.hpp"
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

namespace std
{
    template <typename T>
    class PreOrderIterator
    {
    public:
        PreOrderIterator(Node<T> *ptr) : current(ptr)
        {
            if (ptr)
            {
                stack.push(ptr);
            }
        }
        Node<T> &operator*() { return *current; }
        Node<T> *operator->() { return current; }
        PreOrderIterator &operator++()
        {
            if (stack.empty())
            {
                current = nullptr;
                return *this;
            }

            current = stack.top();
            stack.pop();

            auto &children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
            {
                stack.push(*it);
            }

            if (!stack.empty())
            {
                current = stack.top();
            }
            else
            {
                current = nullptr;
            }

            return *this;
        }
        bool operator!=(const PreOrderIterator &other) const { return current != other.current; }

    private:
        Node<T> *current;
        std::stack<Node<T> *> stack;
    };

    template <typename T>
    class InOrderIterator
    {
    public:
        InOrderIterator(Node<T> *root) : current(nullptr)
        {
            pushLeftMostNodes(root);
            if (!stack.empty())
            {
                current = stack.top();
                stack.pop();
            }
        }

        T operator*()
        {
            return current->get_value();
        }

        Node<T> *operator->()
        {
            return current;
        }

        InOrderIterator &operator++()
        {
            if (current == nullptr)
            {
                return *this;
            }

            if (current->get_children().size() > 1)
            {
                pushLeftMostNodes(current->get_children()[1]);
            }

            if (!stack.empty())
            {
                current = stack.top();
                stack.pop();
            }
            else
            {
                current = nullptr;
            }
            return *this;
        }

        bool operator==(const InOrderIterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const InOrderIterator &other) const
        {
            return !(*this == other);
        }

    private:
        Node<T> *current;
        std::stack<Node<T> *> stack;

        void pushLeftMostNodes(Node<T> *node)
        {
            while (node != nullptr)
            {
                stack.push(node);
                if (!node->get_children().empty())
                {
                    node = node->get_children()[0];
                }
                else
                {
                    node = nullptr;
                }
            }
        }
    };

    template <typename T>
    class PostOrderIterator
    {
    public:
        PostOrderIterator(Node<T> *root)
        {
            if (root)
            {
                putCorrectOrder(root);
                ++(*this); // Move to the first valid node
            }
            else
            {
                current = nullptr;
            }
        }

        T operator*()
        {
            return current->get_value();
        }

        Node<T> *operator->()
        {
            return current;
        }

        PostOrderIterator &operator++()
        {
            if (stack.empty())
            {
                current = nullptr;
                return *this;
            }

            current = stack.top();
            stack.pop();

            return *this;
        }

        bool operator==(const PostOrderIterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const PostOrderIterator &other) const
        {
            return !(*this == other);
        }

    private:
        Node<T> *current;
        std::stack<Node<T> *> stack;

        void putCorrectOrder(Node<T> *node)
        {
            if (!node)
                return;

            std::stack<Node<T> *> tempStack;
            tempStack.push(node);

            while (!tempStack.empty())
            {
                Node<T> *current = tempStack.top();
                tempStack.pop();
                stack.push(current);

                for (auto child : current->get_children())
                {
                    if (child)
                    {
                        tempStack.push(child);
                    }
                }
            }

            if (!stack.empty())
            {
                current = stack.top();
            }
            else
            {
                current = nullptr;
            }
        }
    };

    template <typename T>
    class BFSIterator
    {
    public:
        BFSIterator(Node<T> *root)
        {
            if (root != nullptr)
            {
                queue.push(root);
            }
        }

        T &operator*()
        {
            return queue.front()->get_value();
        }

        Node<T> *operator->()
        {
            return queue.front();
        }

        BFSIterator &operator++()
        {
            if (!queue.empty())
            {
                Node<T> *current = queue.front();
                queue.pop();
                auto &children = current->get_children();
                for (Node<T> *child : children)
                {
                    if (child != nullptr)
                    {
                        queue.push(child);
                    }
                }
            }

            return *this;
        }

        bool operator==(const BFSIterator &other) const
        {
            return queue == other.queue;
        }

        bool operator!=(const BFSIterator &other) const
        {
            return !(*this == other);
        }

    private:
        std::queue<Node<T> *> queue;
    };

    template <typename T>
    class DFSIterator
    {
    public:
        DFSIterator(Node<T> *root)
        {
            if (root == nullptr)
                return;
            // pushLeftMostNodes(root);
            stack.push(root);
        }

        T operator*()
        {
            return stack.top()->get_value();
        }

        Node<T> *operator->()
        {
            return stack.top();
        }

        DFSIterator &operator++()
        {
            Node<T> *node = stack.top();
            stack.pop();
            // push all the children of the node in reverse order
            for (int i = node->get_children().size() - 1; i >= 0; i--)
            {
                if (node->get_children().at(i) != nullptr)
                {
                    stack.push(node->get_children().at(i));
                }
            }
            return *this;
        }

        bool operator==(const DFSIterator &other) const
        {
            return stack == other.stack;
        }

        bool operator!=(const DFSIterator &other) const
        {
            return !(*this == other);
        }

    private:
        std::stack<Node<T> *> stack;

        void pushLeftMostNodes(Node<T> *node)
        {
            while (node != nullptr)
            {
                stack.push(node);
                if (!node->get_children().empty())
                {
                    node = node->get_children()[0];
                }
                else
                {
                    node = nullptr;
                }
            }
        }
    };

    template <typename T>
    class MinHeapConverter
    {
    public:
        MinHeapConverter(Node<T> *root) : root(root) {}

        void convertToMinHeap()
        {
            if (!root)
                return;

            std::cout << root->get_value() << std::endl;

            // Step 1: Store the tree nodes in a vector using an inorder traversal
            std::vector<Node<T> *> nodes;
            storeInorderNodes(root, nodes);

            // std::cout << "ssssss" << std::endl;

            // Step 2: Sort the vector based on the node values to maintain heap property
            std::sort(nodes.begin(), nodes.end(), [](Node<T> *a, Node<T> *b)
                      { return a->get_value() < b->get_value(); });

            // std::cout << "ddddd" << std::endl;

            // for (unsigned long i = 0; i < nodes.size(); i++)
            // {
            //     std::cout << nodes[i]->get_value() << " ";
            // }

            // std::cout << "pppp" << std::endl;

            // Step 3: Convert the sorted vector into a complete binary tree

            for (unsigned long i = 0; i < nodes.size(); i++)
            {
                nodes[i]->get_children().clear();
            }
            
            int n = nodes.size();
            for (int i = 0; i < n; ++i)
            {
                // nodes[i]->get_children().clear();
                if (2 * i + 1 < n)
                    nodes[i]->add_child(nodes[2 * i + 1]);
                if (2 * i + 2 < n)
                    nodes[i]->add_child(nodes[2 * i + 2]);
            }

            // Step 4: Update the root to the new tree structure
            if (nodes.size() > 0)
                root = nodes[0];

            // std::cout << root->get_value()<< "sss" << std::endl;
            // root->print_childs();

            
        }

        Node<T> *getRoot() const
        {
            return root;
        }

        class MinHeapIterator
        {
        public:
            MinHeapIterator(Node<T> *root) : root(root), currentIndex(0)
            {
                storeInorderNodes(root, nodes);
            }

            bool hasNext() const
            {
                return currentIndex < nodes.size();
            }

            Node<T> *next()
            {
                if (!hasNext())
                    return nullptr;
                return nodes[currentIndex++];
            }

        private:
            Node<T> *root;
            std::vector<Node<T> *> nodes;
            size_t currentIndex;

            void storeInorderNodes(Node<T> *node, std::vector<Node<T> *> &nodes)
            {
                if (!node)
                    return;
                storeInorderNodes(node->get_children()[0], nodes);
                nodes.push_back(node);
                storeInorderNodes(node->get_children()[1], nodes);
            }
        };

        MinHeapIterator begin()
        {
            return MinHeapIterator(root);
        }

    private:
        Node<T> *root;

        // template <typename T>
        void storeInorderNodes(Node<T> *node, std::vector<Node<T> *> &nodes)
        {
            if (!node)
                return;

            // Traverse left subtree
            if (node->get_children().size() > 0 && node->get_children()[0] != nullptr)
                storeInorderNodes(node->get_children()[0], nodes);

            // Store current node
            nodes.push_back(node);
            // std::cout << node->get_value() << " ";

            // Traverse right subtree
            if (node->get_children().size() > 1 && node->get_children()[1] != nullptr)
                storeInorderNodes(node->get_children()[1], nodes);
        }
    };

}

#endif // ITERATORS_HPP
