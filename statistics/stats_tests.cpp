/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

void test_sum_small_data_set();
void test_stats_summarize();
void test_stats_count();
void test_stats_sum();
void test_stats_mean();
void test_stats_median();
void test_stats_mode();
void test_stats_min();
void test_stats_max();
void test_stats_stdev();
void test_stats_percentile();

// Add prototypes for you test functions here.

int main() {
    test_sum_small_data_set();
    test_stats_summarize();
    test_stats_count();
    test_stats_sum();
    test_stats_mean();
    test_stats_median();
    test_stats_mode();
    test_stats_min();
    test_stats_max();
    test_stats_stdev();
    test_stats_percentile();

  return 0;
}

void test_sum_small_data_set() {
    cout << "test_sum_small_data_set" << endl;

    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);

    assert(sum(data) == 6);
    assert(count(data) == 3);
    assert(mean(data) == 2);
    assert(median(data) == 2);
    assert(mode(data) == 1);
    assert(min(data) == 1);
    assert(max(data) == 3);
    assert(stdev(data) == sqrt(1.0));
    assert(percentile(data, 0) == 1);
    assert(percentile(data, 0.25) == 1.5);
    assert(percentile(data, 0.5) == 2);
    assert(percentile(data, 0.75) == 2.5);
    assert(percentile(data, 1) == 3);
           

    cout << "PASS!" << endl;
}

void test_stats_summarize() {
    cout << "test_stats_summarize" << endl;
    
    vector<double> v1 = {0, 1, 2};
    vector<vector<double>> e1 = {{0, 1}, {1, 1}, {2, 1}};
    vector<vector<double>> a1 = summarize(v1);
    assert(e1 == a1);
    
    vector<double> v2 = {0, 1, 0, 1};
    vector<vector<double>> e2 = {{0, 2}, {1, 2}};
    vector<vector<double>> a2 = summarize(v2);
    assert(e2 == a2);
    
    cout << "PASS!" << endl;
}

void test_stats_count() {
    cout << "test_stats_count" << endl;
    
    vector<double> v1 = {0, 1, 2};
    
    double e1 = 3.0;
    double a1 = count(v1);
    assert(e1 == a1);
    
    vector<double> v2 = {};
    
    double e2 = 0.0;
    double a2 = count(v2);
    assert(e2 == a2);
    
    cout << "PASS!" << endl;
}

void test_stats_sum() {
    cout << "test_stats_sum" << endl;
    
    //basic tests
    vector<double> v1 = {0, 1, 2};
    
    double e1 = 3.0;
    double a1 = sum(v1);
    assert (e1 == a1);
    
    vector<double> v2 = {1};
    
    double e2 = 1.0;
    double a2 = sum(v2);
    assert(e2 == a2);
    
    cout << "PASS!" << endl;
}

void test_stats_mean() {
    cout << "test_stats_mean" << endl;
    
    //basic tests
    vector<double> v1 = {1, 2, 3};
    
    double e1 = 2.0;
    double a1 = mean(v1);
    assert(e1 == a1);
    
    //edge tests
    vector<double> v2 = {3, 4};
    
    double e2 = 3.5;
    double a2 = mean(v2);
    assert(e2 == a2);
    
    vector<double> v3 = {3, 4, 6};
    
    double e3 = 13.0 / 3.0;
    double a3 = mean(v3);
    assert(e3 == a3);
    
    cout << "PASS!" << endl;
}

void test_stats_median() {
    cout << "test_stats_median" << endl;
    
    vector<double> v1 = {1, 2, 3};
    
    double e1 = 2;
    double a1 = median(v1);
    assert(e1 == a1);
    
    vector<double> v2 = {3, 4};
    
    double e2 = 3.5;
    double a2 = median(v2);
    assert(e2 == a2);
    
    cout << "PASS!" << endl;
    
}

void test_stats_mode() {
    cout << "test_stats_mode" << endl;
    
    //basic tests
    vector<double> v1 = {1, 2, 2};
    double e1 = 2;
    double a1 = mode(v1);
    assert(e1 == a1);
    
    vector<double> v4  = {1, 2, 1, 2, 2};
    double e4 = 2;
    double a4 = mode(v4);
    assert(e4 == a4);
    
    //edge tests
    vector<double> v2 = {1, 2, 3};
    
    double e2 = 1;
    double a2 = mode(v2);
    assert(e2 == a2);
    
    vector<double> v3 = {1, 1, 2, 2};
    double e3 = 1;
    double a3 = mode(v3);
    assert(e3 == a3);
    
    cout << "PASS!" << endl;
}
void test_stats_min(){
    cout << "test_stats_min" << endl;
    
    vector<double> v1 = {0, 1, 2};
    
    double e1 = 0;
    double a1 = min(v1);
    assert(e1 == a1);
    
    vector<double> v2 = {2, 3, 1};
    double e2 = 1;
    double a2 = min(v2);
    assert(e2 == a2);
    
    cout << "PASS!" << endl;
    
}

void test_stats_max(){
    cout << "test_stats_max" << endl;
    vector<double> v1 = {0, 1, 2};
    
    double e1 = 2;
    double a1 = max(v1);
    assert(e1 == a1);
    
    vector<double> v2 = {2, 3, 1};
    double e2 = 3;
    double a2 = max(v2);
    assert(e2 == a2);
    
    cout << "PASS!" << endl;
}

void test_stats_stdev() {
    cout << "test_stats_stdev" << endl;
    
    //basic tests
    vector<double> v1 = {1, 2, 3};
    
    double e1 = 1;
    double a1 = stdev(v1);
    assert(e1 = a1);
    
    vector<double> v2 = {1, 1, 1};
    double e2 = 0;
    double a2 = stdev(v2);
    assert(e2 == a2);
    
    vector<double> v3 = {6, 7, 8, 9, 10};
    double e3 = sqrt(5.0/2.0);
    double a3 = stdev(v3);
    assert(e3 == a3);
    
    cout << "PASS!" << endl;
}

void test_stats_percentile() {
    cout << "test_stats_percentile" << endl;
    
    //basic test
    vector<double> v1 = {15, 20, 35, 40, 50};
    double e1 = 29;
    double a1 = percentile(v1, 0.4);
    assert(e1 == a1);
    
    vector<double> v2 = {7, 6, 9, 8, 10};
    double e2 = 6;
    double a2 = percentile(v2, 0);
    assert(e2 == a2);
    
    double e3 = 7;
    double a3 = percentile(v2, 0.25);
    assert(e3 == a3);
    
    double e4 = 8;
    double a4 = percentile(v2, 0.5);
    assert(e4 == a4);
    
    double e5 = 9;
    double a5 = percentile(v2, 0.75);
    assert(e5 == a5);
    
    double e6 = 10;
    double a6 = percentile(v2, 1);
    assert(e6 == a6);
    
    cout << "PASS!" << endl;
}

