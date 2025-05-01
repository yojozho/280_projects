// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    sort(v);
    vector<vector<double>> temp;
    double num = v[0], frq = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            frq += 1;
        }
        else {
            temp.push_back({num, frq});
            num = v[i];
            frq = 1;
        }
        if (i == v.size() - 1) {
            temp.push_back({v[i], frq});
        }
    }
    return temp;
}

int count(vector<double> v) {
    return static_cast<double>(v.size());
}

double sum(vector<double> v) {
    assert(!v.empty());
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

double mean(vector<double> v) {
    assert(!v.empty());
    double total = sum(v);
    double num = count(v);;
    return total / num;
}

double median(vector<double> v) {
    assert(!v.empty());
    sort(v);
    int size = count(v);
    if (size % 2 == 0) {
        return (v[size/ 2] + v[(size / 2) - 1]) / 2;
    }
    else {
        return v[size / 2];
    }
}

double mode(vector<double> v) {
    assert(!v.empty());
    sort(v);
    vector<vector<double>> summary = summarize(v);
    double num = summary[0][0], frq = summary[0][1];
    for (int i = 1; i < summary.size(); ++i) {
        if (summary[i][1] > frq) {
            num = summary[i][0];
            frq = summary[i][1];
        }
    }
    return num;
}

double min(vector<double> v) {
    assert(!v.empty());
    sort(v);
    return v[0];
}

double max(vector<double> v) {
    assert(!v.empty());
    sort(v);
    return v[v.size() - 1];
}

double stdev(vector<double> v) {
    assert(v.size() > 1);
    vector<double> temp;
    double mean1 = mean(v);
    for (int i = 0; i < v.size(); ++i) {
        temp.push_back(pow((v[i] - mean1), 2));
    }
    return sqrt(sum(temp) / (count(temp) - 1));
}

double percentile(vector<double> v, double p) {
    assert(!v.empty());
    sort(v);
    assert(p >= 0 && p <= 1);
    double n, k, d;
    n = (p * (count(v) - 1));
    d = modf(n, &k);
    if (d == 0) {
        return v[k];
    }
    else {
        return v[k] + (d * (v[k + 1] - v[k]));
    }
}
