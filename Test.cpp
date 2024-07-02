// #include <iostream>
// #include <string>
#include "node.hpp"
#include "tree.hpp"
#include "doctest.h"
#include "Complex.hpp"

using namespace std;

TEST_CASE("check node")
{
    Node<int> root_node(2);
    CHECK(root_node.get_value()==2);
}

TEST_CASE("check root, binary tree")
{
    Node<double> root_node(2.0);
    Tree<double, 3> tree; 
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == root_node.get_value());
}

TEST_CASE("check root, complex tree")
{
    Node<Complex> root_node(Complex(1.1, 2.2));
    Tree<Complex,3> tree;
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == root_node.get_value());
}

TEST_CASE("check root, string tree")
{
    Node<string> root_node("lol");
    Tree<string, 3> tree;
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == root_node.get_value());
}

TEST_CASE("check add sub node")
{
    Node<string> root_node("lol");
    Tree<string, 3> tree;
    tree.add_root(root_node);
    Node<string> n1("jjjj");
    Node<string> n2("1.3");
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    CHECK(tree.get_root()->get_children().size() == 2);
}

TEST_CASE("check add sub node, binary tree")
{
    Node<double> root_node(2.0);
    Tree<double> tree; 
    tree.add_root(root_node);
    Node<double> n1(1.2);
    tree.add_sub_node(root_node, n1);
    CHECK(tree.get_root()->get_children().size() == 1);
}

TEST_CASE("check invalid number of childs")
{
    Node<string> root_node("lol");
    Tree<string, 3> tree;
    tree.add_root(root_node);
    Node<string> n1("jjjj2");
    Node<string> n2("1.3");
    Node<string> n3("1.4");
    Node<string> n4("1.5");
    Node<string> n5("1.6");
    Node<string> n6("1.7");
    

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n6);
    
    CHECK_THROWS(tree.add_sub_node(root_node, n4));
}

TEST_CASE("check pre order traversal")
{
    Node<string> root_node("lol");
    Tree<string,3> tree;
    tree.add_root(root_node);
    Node<string> n1("elian");
    Node<string> n2("iluk");
    Node<string> n3("is");
    Node<string> n4("the");
    Node<string> n5("best");
    Node<string> n6("programmer");
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    string pre_order = "";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        pre_order += (*it).get_value() + " ";
    }
    CHECK(pre_order == "lol elian is the iluk best programmer ");
}

TEST_CASE("check in order traversal")
{
    Node<int> root_node(1);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string in_order = "";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        in_order += to_string((*it).get_value());
        in_order += " ";
    }
    CHECK(in_order == "4 2 5 1 6 3 ");
}

TEST_CASE("check post order traversal")
{
    Node<int> root_node(1);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string post_order = "";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        post_order += to_string((*it).get_value());
        post_order += " ";
    }
    CHECK(post_order == "4 5 2 6 3 1 ");
}

TEST_CASE("check bfs scan")
{
    Node<int> root_node(1);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string bfs_scan = "";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        bfs_scan += to_string((*it));
        bfs_scan += " ";
    }
    CHECK(bfs_scan == "1 2 3 4 5 6 ");
}

TEST_CASE("check dfs scan")
{
    Node<int> root_node(1);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string dfs_scan = "";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        dfs_scan += to_string((*it));
        dfs_scan += " ";
    }
    CHECK(dfs_scan == "1 2 4 5 3 6 ");
}

TEST_CASE("check min heap")
{
    Node<int> root_node(12);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string min_heap = "";
    CHECK(tree.get_root()->get_value() == 12);
    tree.to_min_heap();
    CHECK(tree.get_root()->get_value() == 2);
    for (auto it = tree.begin_min_heap(); it != tree.end_min_heap(); ++it)
    {
        min_heap += to_string((*it));
        min_heap += " ";
    }
    CHECK(min_heap == "2 4 12 5 3 6 ");
}

TEST_CASE("check min heap, complex")
{
    Node<Complex> root_node(Complex(1.1, 2.2));
    Tree<Complex> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<Complex> n1(Complex(1.2, 2.3));
    Node<Complex> n2(Complex(1.3, 2.4));
    Node<Complex> n3(Complex(1.4, 2.5));
    Node<Complex> n4(Complex(1.5, 2.6));
    Node<Complex> n5(Complex(1.6, 2.7));
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string min_heap = "";
    CHECK(tree.get_root()->get_value() == Complex(1.1, 2.2));
    tree.to_min_heap();
    CHECK(tree.get_root()->get_value() == Complex(1.1, 2.2));
}

TEST_CASE("check min heap, string")
{
    Node<string> root_node("lol");
    Tree<string> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<string> n1("elian");
    Node<string> n2("iluk");
    Node<string> n3("is");
    Node<string> n4("the");
    Node<string> n5("best");
    Node<string> n6("programmer");
    // Node<double> n6(1.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string min_heap = "";
    CHECK(tree.get_root()->get_value() == "lol");
    tree.to_min_heap();
    CHECK(tree.get_root()->get_value() == "best");
}

TEST_CASE("check swap")
{
    Node<int> root_node(1);
    Node<int> n1(2);
    root_node.swap(n1);
    CHECK(root_node.get_value() == 2);
}

TEST_CASE("check operator==")
{
    Node<int> root_node(1);
    Node<int> n1(2);
    CHECK(root_node.get_value() != n1.get_value());
}

TEST_CASE("check operator=")
{
    Node<int> root_node(1);
    Node<int> n1(2);
    root_node = n1;
    CHECK(root_node.get_value() == 2);
}

TEST_CASE("bfs scan for non binary tree")
{
    Node<int> root_node(1);
    Tree<int, 3> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    Node<int> n6(7);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string bfs_scan = "";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        bfs_scan += to_string((*it));
        bfs_scan += " ";
    }
    CHECK(bfs_scan == "1 2 3 7 4 5 6 ");
}

TEST_CASE("dfs scan for non binary tree")
{
    Node<int> root_node(1);
    Tree<int, 3> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    Node<int> n6(7);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n6);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    string dfs_scan = "";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        dfs_scan += to_string((*it));
        dfs_scan += " ";
    }
    CHECK(dfs_scan == "1 2 4 5 3 6 7 ");
}

TEST_CASE("check operator<<")
{
    Node<int> root_node(1);
    std::stringstream ss;
    ss << root_node;
    CHECK(ss.str() == "1");
}

TEST_CASE("check get children")
{
    Node<int> root_node(1);
    Tree<int, 3> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);

    CHECK(tree.get_root()->get_children().size() == 3);
}

TEST_CASE("check get children, complex")
{
    Node<Complex> root_node(Complex(1.1, 2.2));
    Tree<Complex, 3> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<Complex> n1(Complex(1.2, 2.3));
    Node<Complex> n2(Complex(1.3, 2.4));
    Node<Complex> n3(Complex(1.4, 2.5));

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);

    CHECK(tree.get_root()->get_children().size() == 3);
}

TEST_CASE("check get children, string")
{
    Node<string> root_node("lol");
    Tree<string, 3> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<string> n1("elian");
    Node<string> n2("iluk");
    Node<string> n3("is");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);

    CHECK(tree.get_root()->get_children().size() == 3);
}

TEST_CASE("check get value")
{
    Node<int> root_node(1);
    CHECK(root_node.get_value() == 1);
}

TEST_CASE("check get value, complex")
{
    Node<Complex> root_node(Complex(1.1, 2.2));
    CHECK(root_node.get_value() == Complex(1.1, 2.2));
}

TEST_CASE("check get value, string")
{
    Node<string> root_node("lol");
    CHECK(root_node.get_value() == "lol");
}

TEST_CASE("check bfs for 4-tree")
{
    Node<int> root_node(1);
    Tree<int, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    Node<int> n6(7);
    Node<int> n7(8);
    Node<int> n8(9);
    
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(root_node, n4);
    
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);
    tree.add_sub_node(n1, n7);
    tree.add_sub_node(n1, n8);

    string bfs_scan = "";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        bfs_scan += to_string((*it));
        bfs_scan += " ";
    }
    CHECK(bfs_scan == "1 2 3 4 5 6 7 8 9 ");
}

TEST_CASE("check dfs for 4-tree")
{
    Node<int> root_node(1);
    Tree<int, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    Node<int> n6(7);
    Node<int> n7(8);
    Node<int> n8(9);
    
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(root_node, n4);
    
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);
    tree.add_sub_node(n1, n7);
    tree.add_sub_node(n1, n8);

    string dfs_scan = "";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        dfs_scan += to_string((*it));
        dfs_scan += " ";
    }
    CHECK(dfs_scan == "1 2 6 7 8 9 3 4 5 ");
}

TEST_CASE("check getRoot")
{
    Node<int> root_node(1);
    Tree<int, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == 1);
}

TEST_CASE("check getRoot, complex")
{
    Node<Complex> root_node(Complex(1.1, 2.2));
    Tree<Complex, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == Complex(1.1, 2.2));
}

TEST_CASE("check getRoot, string")
{
    Node<string> root_node("lol");
    Tree<string, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == "lol");
}

TEST_CASE("check add_root")
{
    Node<int> root_node(1);
    Tree<int, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == 1);
}

TEST_CASE("check add_root, complex")
{
    Node<Complex> root_node(Complex(1.1, 2.2));
    Tree<Complex, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == Complex(1.1, 2.2));
}

TEST_CASE("check add_root, string")
{
    Node<string> root_node("lol");
    Tree<string, 4> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == "lol");
}

