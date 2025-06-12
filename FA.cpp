#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int ascii_len = 128;
//ATUOMATON ASSUMES THAT THE SYMBOL LIST IS AN ASCII TABLE

int move_to(string pattern, int state, int letter) {
    string curr = pattern.substr(0, state);
    curr = curr + (char)letter;

    for(int i=0; i<state+1; i++) {
        string p_prefix = pattern.substr(0, state+1-i);
        string c_suffix = curr.substr(i, state+1);
        if(p_prefix == c_suffix) {
            return state+1-i;
        }
    }
    return 0;
}

vector<vector<int>> next_state_mtx(string pattern) {
    int m = pattern.length();
    vector<vector<int>> next_state(m+1, vector<int>(ascii_len, 0));

    for(int i=0; i<m+1; i++) {
        for(int j=0; j<ascii_len; j++) {
            next_state[i][j] = move_to(pattern, i, j);
        }
    }

    return next_state;
}

vector<int> string_matching(string pattern, string text) {
    vector<int> solution;
    vector<vector<int>> fa = next_state_mtx(pattern);
    int state = 0;
    int n = text.length();
    int m = pattern.length();
    for(int i=0; i<n; i++) {
        state = fa[state][(int)text[i]];
        if(state == m) { solution.push_back(i+1-m); }
    }

    return solution;
}