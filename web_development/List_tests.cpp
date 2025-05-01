// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_list_empty) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_list_size_push) {
    List<int> empty1;
    empty1.push_back(1);
    ASSERT_EQUAL(empty1.front(), 1);
    ASSERT_EQUAL(empty1.front(), empty1.back());
    
    List<int>empty2;
    empty2.push_front(1);
    ASSERT_EQUAL(empty1.front(), 1);
    ASSERT_EQUAL(empty2.front(), empty2.back());
    
    List<int> list1;
    ASSERT_EQUAL(list1.size(), 0);
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    ASSERT_EQUAL(list1.size(), 3);
    ASSERT_EQUAL(list1.front(), 0);
    ASSERT_EQUAL(list1.back(), 2);
    
    List<int> list2;
    for (int i = 0; i < 4; ++i) {
        list2.push_front(i);
    }
    ASSERT_EQUAL(list2.size(), 4);
    ASSERT_EQUAL(list2.front(), 3);
    ASSERT_EQUAL(list2.back(), 0);
    
    List<int> list3;
    ASSERT_EQUAL(list3.size(), 0);
    for (int i = 1; i < 5; ++i) {
        list3.push_front(i);
    }
    ASSERT_EQUAL(list3.size(), 4);
    ASSERT_EQUAL(list3.front(), 4);
    ASSERT_EQUAL(list3.back(), 1);
    
    empty1.clear();
    empty2.clear();
    list1.clear();
    list2.clear();
    list3.clear();
}

TEST(test_list_pop) {
    List<int> empty1;
    empty1.push_back(1);
    ASSERT_EQUAL(empty1.size(), 1);
    empty1.pop_front();
    ASSERT_TRUE(empty1.empty());
    
    List<int>empty2;
    empty2.push_front(1);
    ASSERT_EQUAL(empty2.size(), 1);
    empty2.pop_back();
    ASSERT_TRUE(empty2.empty());
    
    List<int> list1;
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    ASSERT_EQUAL(list1.size(), 3);
    list1.pop_front();
    ASSERT_EQUAL(list1.front(), 1);
    ASSERT_EQUAL(list1.back(), 2)
    list1.pop_front();
    ASSERT_EQUAL(list1.front(), 2);
    list1.pop_front();
    ASSERT_TRUE(list1.empty());
    
    List<int> list2;
    for (int i = 0; i < 3; ++i) {
        list2.push_back(i);
    }
    ASSERT_EQUAL(list2.size(), 3);
    list2.pop_back();
    ASSERT_EQUAL(list2.front(), 0);
    ASSERT_EQUAL(list2.back(), 1);
    list2.pop_back();
    ASSERT_EQUAL(list2.back(), 0);
    list2.pop_back();
    ASSERT_TRUE(list2.empty());
    
    empty1.clear();
    empty2.clear();
    list1.clear();
    list2.clear();
}

TEST(test_list_clear) {
    List<int> list1;
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    ASSERT_EQUAL(list1.size(), 3);
    list1.clear();
    ASSERT_TRUE(list1.empty());
    
    List<int> list2;
    for (int i = 0; i < 10; ++i) {
        list2.push_back(i);
    }
    ASSERT_EQUAL(list2.size(), 10);
    list2.clear();
    ASSERT_TRUE(list2.empty());
    
    list1.clear();
    list2.clear();
}

TEST(test_list_copy) {
    List<int> list1;
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    List<int> list2;
    for (int i = 1; i < 4; ++i) {
        list2.push_front(i);
    }
    //list1: 0, 1, 2
    //list2: 3, 2, 1
    list1 = list2;
    ASSERT_EQUAL(list1.front(), 3);
    ASSERT_EQUAL(list1.back(), 1);
    for (int i = 2; i > 0; --i) {
        list1.pop_front();
        ASSERT_EQUAL(list1.front(), i);
    }
    
    List<int> list3;
    for (int i = 0; i < 10; ++i) {
        list3.push_back(i);
    }
    List<int> list4;
    for (int i = 10; i > 0; --i) {
        list4.push_front(i);
    }
    //list3: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //list4: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    list3 = list4;
    ASSERT_EQUAL(list3.front(), 1);
    ASSERT_EQUAL(list3.back(), 10);
    for (int i = 9; i > 0; --i) {
        list3.pop_back();
        ASSERT_EQUAL(list3.back(), i);
    }
    
    list1.clear();
    list2.clear();
    list3.clear();
    list4.clear();
}

TEST(test_iterator_constructors) {
    List<int> list1;
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list1.begin();
         it != list1.end(); ++it) {
        ASSERT_EQUAL(*it, j);
        j++;
    }
    
    list1.clear();
}
TEST(test_iterator_begin_end) {
    List<int> empty_list;
    ASSERT_EQUAL(empty_list.begin(), empty_list.end());
    
    List<int> list1;
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    List<int>::Iterator it1 = list1.begin();
    ASSERT_EQUAL(*it1, 0);
    list1.pop_front();
    it1 = list1.begin();
    ASSERT_EQUAL(*it1, 1);
    list1.pop_front();
    it1 = list1.begin();
    ASSERT_EQUAL(*it1, 2);
    list1.pop_front();
    it1 = list1.begin();
    ASSERT_EQUAL(it1, list1.end());
    
    empty_list.clear();
    list1.clear();
}
TEST(test_iterator_erase) {
    List<int> empty1;
    empty1.push_back(1);
    empty1.push_back(2);
    empty1.push_back(3);
    List<int>:: Iterator track_empty1 = empty1.begin();
    empty1.erase(track_empty1);
    ASSERT_EQUAL(empty1.front(), 2);
    track_empty1 = empty1.begin();
    ++track_empty1;
    empty1.erase(track_empty1);
    ASSERT_EQUAL(empty1.front(), 2);
    ASSERT_EQUAL(empty1.front(), empty1.back());
    
    List<int> list1;
    for (int i = 0; i < 3; ++i) {
        list1.push_back(i);
    }
    //0, 1, 2
    List<int>::Iterator it1 = list1.begin();
    ASSERT_EQUAL(list1.size(), 3);
    list1.erase(it1);
    ASSERT_EQUAL(list1.size(), 2);
    ASSERT_EQUAL(list1.front(), 1);
    it1 = list1.begin();
    ++it1;
    list1.erase(it1);
    ASSERT_EQUAL(list1.size(), 1);
    ASSERT_EQUAL(list1.back(), 1);
    
    List<int> list2;
    list2.push_back(0);
    list2.push_back(1);
    list2.push_back(3);
    list2.push_back(2);
    List<int>::Iterator it2 = list2.begin();
    ASSERT_EQUAL(list2.size(), 4);
    ++it2;
    ++it2;
    list2.erase(it2);
    ASSERT_EQUAL(list2.size(), 3);
    int j = 0;
    for (List<int>::Iterator it = list2.begin();
         it != list2.end(); ++it) {
        ASSERT_EQUAL(*it, j)
        j++;
    }
    
    empty1.clear();
    list1.clear();
    list2.clear();
}

TEST(test_iterator_insert) {
    List <int> empty;
    empty.push_back(1);
    List<int>::Iterator track_empty = empty.begin();
    empty.insert(track_empty, 0);
    ASSERT_EQUAL(empty.front(), 0);
    ASSERT_EQUAL(empty.back(), 1);
    
    List<int> empty2;
    empty.push_front(2);
    empty.push_front(1);
    List<int>::Iterator track_empty2 = empty2.end();
    empty2.insert(track_empty2, 3);
    ASSERT_EQUAL(empty2.back(), 3);
    
    List<int> list1;
    for (int i = 0; i < 3; i += 2) {
        list1.push_back(i);
    }
    //list1: 0, 2
    List<int>::Iterator it1 = list1.begin(); // 0
    ASSERT_EQUAL(list1.size(), 2);
    ++it1; //points to 2
    list1.insert(it1, 1); // insert 1 so 0, 1, 2
    ASSERT_EQUAL(list1.size(), 3);
    
    int j = 0;
    for (List<int>::Iterator track_it1 = list1.begin();
         track_it1 != list1.end(); ++track_it1) {
        ASSERT_EQUAL(*track_it1, j);
        j++;
    }
    
    List<int> list2;
    for (int i = 1; i < 3; ++i) {
        list2.push_back(i);
    }
    List<int>::Iterator it2 = list2.begin();
    ASSERT_EQUAL(list2.size(), 2);
    list2.insert(it2, 0);
    ASSERT_EQUAL(list2.size(), 3);
    
    int k = 0;
    for (List<int>::Iterator track_it2 = list2.begin();
         track_it2 != list2.end(); ++track_it2) {
        ASSERT_EQUAL(*track_it2, k);
        k++;
    }
    
    List<int> list3;
    list3.push_back(1);
    List<int>::Iterator it3 = list3.begin();
    ASSERT_EQUAL(list3.size(), 1);
    list3.insert(it3, 0);
    ASSERT_EQUAL(list3.size(), 2);
    ASSERT_EQUAL(list3.front(), 0);
    
    empty.clear();
    empty2.clear();
    list1.clear();
    list2.clear();
    list3.clear();
}

TEST(test_iterator_public_operators) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list1.begin();
    ASSERT_TRUE(it1 == it2);
    ASSERT_EQUAL(*it1, 1);
    ++it1;
    ASSERT_EQUAL(*it1, 2);
    ASSERT_TRUE(it1 != it2);
    --it1;
    ASSERT_EQUAL(*it1, 1);
    
    list1.clear();
}

TEST_MAIN()
