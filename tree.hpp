#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include "node.hpp"
#include "iterators.hpp"
// #include "heapify.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>

namespace std
{
    template <typename T, int N = 2>
    class Tree
    {
    public:
        Tree() : root(nullptr) {}

        ~Tree() { if(root) remove(root); }

        void remove(Node<T> *node)
        {
            if(node->get_children().size() == 0)
            {
                delete node;
                return;
            }
            for (auto child : node->get_children())
            {
                remove(child);
            }
            delete node;
        }

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

        minHeapIterator<T> begin_min_heap() { return minHeapIterator<T>(root); }
        minHeapIterator<T> end_min_heap() { return minHeapIterator<T>(nullptr); }

        void to_min_heap()
        {
            if (!root)
                return;
            Heapify<T> heapify_instance(root);
            heapify_instance.heapify(root);
        }

        void print_tree()
        {
            if (!root)
            {
                std::cout << "Tree is empty." << std::endl;
                return;
            }

            print_subtree(root, "");
        }

        void visualize_tree() const
        {
            sf::RenderWindow window(sf::VideoMode(1600, 900), "Tree Visualization");

            sf::Font font;
            if (!font.loadFromFile("arial.ttf")) // Ensure the font file is in the correct location
            {
                std::cerr << "Error loading font\n";
                return;
            }

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear(sf::Color::Black);
                draw_node(window, root, 800, 50, 200, 100, font);
                window.display();
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const Tree<T, N> &tree)
        {
            tree.visualize_tree();
            return os;
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

        void draw_node(sf::RenderWindow &window, Node<T> *node, int x, int y, int hGap, int vGap, const sf::Font &font) const
        {
            if (!node)
                return;

            sf::CircleShape circle(30);
            circle.setFillColor(sf::Color::Red);
            circle.setOutlineColor(sf::Color::Black);
            circle.setOutlineThickness(2);
            circle.setPosition(x - 30, y - 30);

            sf::Text text;
            text.setFont(font);
            // if constexpr (std::is_same_v<T, double>)
            // {
            //     text.setString(std::to_string(node->get_value()));
            // }
            // else
            // {
            //     text.setString(node->get_value().toString());
            // }
            text.setString(to_string(node->get_value()));
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Black);
            text.setPosition(x - 10, y - 15);

            window.draw(circle);
            window.draw(text);

            int childY = y + vGap;
            int childX = x - (node->get_children().size() - 1) * hGap / 2;

            for (auto child : node->get_children())
            {
                int newX = childX + hGap;

                sf::Vertex line[] =
                    {
                        sf::Vertex(sf::Vector2f(x, y)),
                        sf::Vertex(sf::Vector2f(newX, childY))};

                window.draw(line, 2, sf::Lines);
                draw_node(window, child, newX, childY, hGap / 2, vGap, font);
                childX += hGap;
            }
        }
    };
}

#endif // TREE_HPP
