#ifndef FA_H
#define FA_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int move_to(string pattern, int state, int letter);
int next_state_mtx(string pattern);
vector<int> string_matching(string pattern, string text);

#endif