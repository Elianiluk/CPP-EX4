/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{

    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    // std::cout << root_node.get_value() << std::endl;
    // std::cout << tree.print() << std::endl;

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    tree.print_tree();
   
    n1.print_childs();

    if(n1 != n2)
    {
        // std::cout << "n1 != n2" << std::endl;
    }

    if(n1 == n1)
    {
        // std::cout << "n1 == n1" << std::endl;
    }
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    std::cout << "Pre-order traversal:" << std::endl;
    int i=1;
    for (auto it = tree.pre_order_begin(); it != tree.pre_order_end(); ++it)
    {
        std::cout << i << std::endl;
        std::cout << (*it).get_value() << " ";
        i++;
    }   

    std::cout << std::endl;

    std::cout << "In-order traversal:" << std::endl;
    for (auto it = tree.in_order_begin(); it != tree.in_order_end(); ++it)
    {
        std::cout << (*it).get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-order traversal:" << std::endl;
    for (auto it = tree.post_order_begin(); it != tree.post_order_end(); ++it)
    {
        std::cout << (*it).get_value() << " ";
    }
    std::cout << std::endl;

    // for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    // {
    //     cout << node->get_value() << endl;
    // } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // for (auto node : tree)
    // {
    //     cout << node.get_value() << endl;
    // } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // cout << tree; // Should print the graph using GUI.

    // Tree<double,3> three_ary_tree; // 3-ary tree.
    // three_ary_tree.add_root(root_node);
    // three_ary_tree.add_sub_node(root_node, n1);
    // three_ary_tree.add_sub_node(root_node, n2);
    // three_ary_tree.add_sub_node(root_node, n3);
    // three_ary_tree.add_sub_node(n1, n4);
    // three_ary_tree.add_sub_node(n2, n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    return 0;
}
