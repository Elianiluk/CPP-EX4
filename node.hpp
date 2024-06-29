#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>

namespace std
{
    template <typename T>
    class Node
    {
    public:
        Node(T value) : value(value) {}

        T get_value() const { return value; }

        void add_child(Node<T> *child) {
            children.push_back(child);
        }


        void print_childs() const
        {
            std::cout << "main is:" << this->value << std::endl;
            for (const auto& child : children)
            {
                std::cout << "value: " << child->get_value() << std::endl;
            }
        }

        std::vector<Node<T>*>& get_children() { return children; }

        bool operator==(const Node& other) const
        {
            return value == other.value;
        }

        bool operator!=(const Node& other) const
        {
            return value != other.value;
        }

        friend std::ostream& operator<<(std::ostream& os, const Node<T>& node)
        {
            os << node.get_value();
            return os;
        }

    private:
        T value;
        std::vector<Node<T>*> children;
    };
}

#endif // NODE_HPP
