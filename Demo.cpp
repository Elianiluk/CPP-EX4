/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

using namespace std;

int main()
{

    Node<double> root_node(2.0);
    Tree<double, 3> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);
    Node<double> n6(1.0);

    // Node<Complex> root_node(Complex(1.1, 2.2));
    // Tree<Complex,3> tree;
    // tree.add_root(root_node);
    // Node<Complex> n1(Complex(1.2, 2.3));
    // Node<Complex> n2(Complex(1.3, 2.4));
    // Node<Complex> n3(Complex(1.4, 2.5));
    // Node<Complex> n4(Complex(1.5, 2.6));
    // Node<Complex> n5(Complex(1.6, 2.7));
    // Node<Complex> n6(Complex(1.7, 2.8));

    // Node<string> root_node("lol");
    // Tree<string, 3> tree;
    // tree.add_root(root_node);
    // Node<string> n1("jjjj2");
    // Node<string> n2("1.3");
    // Node<string> n3("1.4");
    // Node<string> n4("1.5");
    // Node<string> n5("1.6");
    // Node<string> n6("1.7");
    

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    tree.print_tree();

    std::cout << "Pre-order traversal:" << std::endl;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        std::cout << (*it).get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    std::cout << std::endl;

    std::cout << "In-order traversal:" << std::endl;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        std::cout << (*it).get_value() << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout << std::endl;

    std::cout << "Post-order traversal:" << std::endl;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        std::cout << (*it).get_value() << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    std::cout << std::endl;

    std::cout << "BFS traversal:" << std::endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout << std::endl;

    std::cout << "DFS traversal:" << std::endl;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        std::cout << *it << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout << std::endl;

    std::cout << "Min Heap Tree traversal:" << std::endl;
    std::cout << "Before Min Heap Tree traversal:" << std::endl;
    std::cout << tree;
    std::cout << "After Min Heap Tree traversal:" << std::endl;
    tree.to_min_heap();
    std::cout << tree;

    std::cout << "\nMin Heap Iteration:" << std::endl;
    for (auto it = tree.begin_min_heap(); it != tree.end_min_heap(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
