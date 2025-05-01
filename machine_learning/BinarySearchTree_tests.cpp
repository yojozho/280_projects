// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <sstream>


TEST(test_1) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
    tree.insert(4);
    ASSERT_FALSE(tree.empty());
    
    ASSERT_TRUE(tree.size() == 1);
    ASSERT_TRUE(tree.height() == 1);
    
    ASSERT_TRUE(tree.find(4) != tree.end());
    
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    ASSERT_TRUE(tree.size() == 7);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(*tree.find(7) == 7);
    ASSERT_TRUE(*tree.find(1) == 1);
    ASSERT_TRUE(tree.find(9) == tree.end());
    ASSERT_TRUE(tree.check_sorting_invariant());
    ASSERT_EQUAL(*tree.max_element(), 7);
    ASSERT_EQUAL(*tree.min_element(), 1);
    
    
    ASSERT_TRUE(*tree.min_greater_than(1) == 2);
    ASSERT_TRUE(*tree.min_greater_than(2) == 3);
    ASSERT_TRUE(*tree.min_greater_than(4) == 5);
    ASSERT_TRUE(tree.min_greater_than(7) == tree.end());
    
    std::ostringstream os1;
    tree.traverse_inorder(os1);
    ASSERT_EQUAL(os1.str(), "1 2 3 4 5 6 7 ");
    
    std::ostringstream os2;
    tree.traverse_preorder(os2);
    ASSERT_EQUAL(os2.str(), "4 2 1 3 6 5 7 ");
}

TEST(test_2) {
    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    BinarySearchTree<int>::Iterator it = tree.find(1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it,3);
    
    BinarySearchTree<int> tree_copy(tree);
    ASSERT_TRUE(tree.size() == 7);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(tree_copy.size() == 7);
    ASSERT_TRUE(tree_copy.height() == 3);
    BinarySearchTree<int>::Iterator it1;
    int i = 1;
    for (it1 = tree_copy.begin(); it1 != tree_copy.end(); it1++) {
        ASSERT_EQUAL(*it1, i);
        ++i;
    }
    
    BinarySearchTree<int> second_tree = tree;
    ASSERT_TRUE(tree.size() == 7);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(second_tree.size() == 7);
    ASSERT_TRUE(second_tree.height() == 3);
    BinarySearchTree<int>::Iterator it2;
    i = 1;
    for (it2 = second_tree.begin(); it2 != second_tree.end(); ++it2) {
        ASSERT_EQUAL(*it2, i);
        ++i;
    }
    BinarySearchTree<int>::Iterator it3 = second_tree.find(1);
    *it3 = 8;
    ASSERT_TRUE(!second_tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.find(1) == 1);
    *it3 = 1;
    it3 = second_tree.find(4);
    *it3 = 9;
    ASSERT_TRUE(!second_tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.find(4) == 4);
    *it = 1;
    ASSERT_TRUE(!second_tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.find(4) == 4);
    *it3 = 4;
    it3 = second_tree.find(7);
    *it3 = 9;
    ASSERT_TRUE(second_tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.find(7) == 7);
    *it3 = 5;
    ASSERT_TRUE(!second_tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.find(7) == 7);
}


TEST_MAIN()
