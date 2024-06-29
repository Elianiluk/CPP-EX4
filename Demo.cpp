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

    if (n1 != n2)
    {
        // std::cout << "n1 != n2" << std::endl;
    }

    if (n1 == n1)
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
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        std::cout << (*it).get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    std::cout << std::endl;

    std::cout << "In-order traversal:" << std::endl;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        std::cout << (*it) << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout << std::endl;

    std::cout << "Post-order traversal:" << std::endl;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        std::cout << (*it) << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    std::cout << std::endl;

    std::cout << "BFS traversal:" << std::endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout << std::endl;

    std::cout << "DFS traversal:" << std::endl;
    for (DFSIterator<double> it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        std::cout << *it << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout << std::endl;

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

    // three_ary_tree.print_tree();

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
