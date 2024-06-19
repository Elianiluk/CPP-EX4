// Node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

namespace std
{
    template <typename T>
    class Node
    {
    public:
        Node(T value) : value(value) {}
        T get_value() const { return value; }
        void add_child(Node<T>& child) { children.push_back(child); }
        void print_childs() const
        {
            std::cout << "main is:" <<this->value << std::endl;
            for (auto child : children)
            {
                std::cout << "value: " << child.get_value() << std::endl;
            }
        }

        std::vector<Node<T>> get_children() const { return children; }

        bool operator==(const Node& other) const
        {
            return value == other.value;
        }

        // Overload the inequality operator
        bool operator!=(const Node& other) const
        {
            return value != other.value;
        }

    private:
        T value;
        std::vector<Node<T>> children;
    };
} // namespace ariel

#endif // NODE_HPP
