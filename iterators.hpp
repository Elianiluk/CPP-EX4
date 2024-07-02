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

        Node<T> &operator*() { return *current; }

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
                postOrder(root);
                ++(*this); // Move to the first valid node
            }
            else
            {
                current = nullptr;
            }
        }

        Node<T> &operator*() { return *current; }

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

        void postOrder(Node<T> *node)
        {
            if (node == nullptr)
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

        T operator*()
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
    class Heapify
    {
    public:
        Heapify(Node<T> *root) : root(root) {}

        void heapify(Node<T> *node)
        {
            if (!node)
                return;

            auto &children = node->get_children();
            for (auto child : children)
            {
                heapify(child);
            }

            Node<T> *minChild = nullptr;
            for (auto child : children)
            {
                if (!minChild || child->get_value() < minChild->get_value())
                {
                    minChild = child;
                }
            }

            if (minChild && minChild->get_value() < node->get_value())
            {
                node->swap(*minChild);
                heapify(minChild);
            }
        }

    private:
        Node<T> *root;
    };

    template <typename T>
    class minHeapIterator
    {
    public:
        minHeapIterator(Node<T> *root)
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

        minHeapIterator &operator++()
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

        bool operator==(const minHeapIterator &other) const
        {
            return stack == other.stack;
        }

        bool operator!=(const minHeapIterator &other) const
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
}

#endif // ITERATORS_HPP
