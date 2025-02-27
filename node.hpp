#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>

/*author: elian iluk
email: elian10119@gmail.com
id:214787483
*/

namespace std
{
    template <typename T>
    class Node
    {
    public:
        Node(T value) : value(value) {}

        T get_value() const { return value; }

        void add_child(Node<T> *child)
        {
            children.push_back(child);
        }

        void print_childs() const
        {
            std::cout << "main is:" << value << std::endl;
            for (const auto &child : children)
            {
                std::cout << "value: " << child->get_value() << std::endl;
            }
        }

        void swap(Node<T> &other)
        {
            std::swap(value, other.value);
        }

        std::vector<Node<T> *> &get_children() { return children; }
        const std::vector<Node<T> *> &get_children() const { return children; }

        bool operator==(const Node &other) const
        {
            return value == other.value;
        }

        void operator=(const Node &other)
        {
            value = other.value;
            children = other.children;
        }

        friend std::ostream &operator<<(std::ostream &os, const Node<T> &node)
        {
            os << node.get_value();
            return os;
        }

    private:
        T value;
        std::vector<Node<T> *> children;
    };
}

#endif // NODE_HPP
