#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "node.hpp"
#include <stack>

namespace std
{
    template <typename T>
    class PreOrderIterator
    {
    public:
        PreOrderIterator(Node<T>* ptr) : current(ptr) 
        {
            // std::cout<<"PreOrderIterator"<<std::endl;
            stack.push(nullptr);
            if (ptr)
            {
                stack.push(ptr);
            }
        }
        Node<T>& operator*() { return *current; }
        PreOrderIterator& operator++()
        {
            if (stack.empty())
            {
                current = nullptr;
                return *this;
            }

            current = stack.top();
            stack.pop();

            auto& children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
            {
                stack.push(&(*it));
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
        bool operator!=(const PreOrderIterator& other) const { return current != other.current; }
        bool operator==(const PreOrderIterator& other) const { return current == other.current; }

    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
    };

    template <typename T>
    class InOrderIterator
    {
    public:
        InOrderIterator(Node<T>* ptr) : current(ptr) 
        {
            while (ptr)
            {
                stack.push(ptr);
                if (!ptr->get_children().empty())
                {
                    ptr = &ptr->get_children()[0];
                }
                else
                {
                    ptr = nullptr;
                }
            }
            if (!stack.empty())
            {
                current = stack.top();
                stack.pop();
            }
        }
        Node<T>& operator*() { return *current; }
        InOrderIterator& operator++()
        {
            if (!current)
            {
                return *this;
            }
            if (!stack.empty())
            {
                current = stack.top();
                stack.pop();
                std::vector<Node<T>> children = current->get_children();
                for (size_t i = 1; i < children.size(); ++i)
                {
                    Node<T>* ptr = &children[i];
                    while (ptr)
                    {
                        stack.push(ptr);
                        if (!ptr->get_children().empty())
                        {
                            ptr = &ptr->get_children()[0];
                        }
                        else
                        {
                            ptr = nullptr;
                        }
                    }
                }
            }
            else
            {
                current = nullptr;
            }
            return *this;
        }
        bool operator!=(const InOrderIterator& other) const { return current != other.current; }

    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
    };

    template <typename T>
    class PostOrderIterator
    {
    public:
        PostOrderIterator(Node<T>* ptr) 
        {
            if (ptr)
            {
                pushLeftMostNodes(ptr);
                current = stack.top();
                stack.pop();
            }
        }
        Node<T>& operator*() { return *current; }
        PostOrderIterator& operator++()
        {
            if (stack.empty())
            {
                current = nullptr;
            }
            else
            {
                current = stack.top();
                stack.pop();
            }
            return *this;
        }
        bool operator!=(const PostOrderIterator& other) const { return current != other.current; }

    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
        
        void pushLeftMostNodes(Node<T>* node)
        {
            while (node)
            {
                stack.push(node);
                std::vector<Node<T>> children = node->get_children();
                if (!children.empty())
                {
                    node = &children.back();
                }
                else
                {
                    break;
                }
            }
        }
    };
}

#endif // ITERATORS_HPP
