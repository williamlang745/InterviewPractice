#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    int chars_per_cycle = (numRows * 2 ) - 2;
    int full_cycles = s.size() / chars_per_cycle;
    int left_over_chars = s.size() % chars_per_cycle;

    vector<int> row_indexes;
    for (int i = 0; i < numRows; i++) {
        int row_index = 0;
        if(i == 0) { // first row index is zero
            row_index = 0;
        } else if (i == 1) { // count number in first row
            row_index = full_cycles + (left_over_chars > 0 ? 1 : 0);
        } else { // Middle rows
            int extras = 0;
            if (left_over_chars > i - 1) extras++;
            if (left_over_chars > chars_per_cycle - (i - 1)) extras++;
            row_index = (full_cycles * 2) + extras;
        }
        if(i > 0) row_index += row_indexes[i-1];
        row_indexes.push_back(row_index);
    }

    string output = s;
    int o_index = 0;
    while(1) {
        // loop front
        for(int i = 0; i < row_indexes.size(); i++) {
            if(row_indexes[i] >= s.size()) break;
            output[o_index++] = s[row_indexes[i]++];
        }
        if(o_index >= s.size()) break;

        // loop back
        for(int i = row_indexes.size() - 2; i >= 1; i--) {
            if(row_indexes[i] >= s.size()) break;
            output[o_index++] = s[row_indexes[i]++];
        }
        if(o_index >= s.size()) break;
    }
    return output;
}