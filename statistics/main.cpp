// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include "p1_library.h"
#include <iostream>
using namespace std;

int main() {
    string file, column;
    vector<double> data;
    vector<vector<double>> summary;
    
    cout << "enter a filename" << endl;
    cin >> file;
    cout << "enter a column name" << endl;
    cin >> column;
    
    cout << "reading column " << column << " from " << file << endl;
    data = extract_column(file, column);
    
    summary = summarize(data);
    cout << "Summary (value: frequency)" << endl;
    for (int i = 0; i < summary.size(); ++i) {
        cout << summary[i][0] << ": " << summary[i][1] << endl;
    }
    
    cout << endl;
    cout << "count = " << count(data) << endl;
    cout << "sum = " << sum(data) << endl;
    cout << "mean = " << mean(data) << endl;
    cout << "stdev = " << stdev(data) << endl;
    cout << "median = " << median(data) << endl;
    cout << "mode = " << mode(data) << endl;
    cout << "min = " << min(data) << endl;
    cout << "max = " << max(data) << endl;
    
    cout << "  0th percentile = " << percentile(data, 0) << endl;
    cout << " 25th percentile = " << percentile(data, 0.25) << endl;
    cout << " 50th percentile = " << percentile(data, 0.5) << endl;
    cout << " 75th percentile = " << percentile(data, 0.75) << endl;
    cout << "100th percentile = " << percentile(data, 1) << endl;
    
    return 0;
}
