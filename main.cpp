#include<iostream>
#include<string>
#include<vector>
#include"./FA.h"

using namespace std;

//EXAMPLE USAGE
int main() {
    
    string pattern = "books";
    string text = "books in this bookstore are interesting";
    vector<int> matched = string_matching(pattern, text);

    cout<<"Pattern: "<<pattern<<endl;
    cout<<"Text: "<<text<<endl;

    if(matched.size() == 0) {
        cout<<"No matches."<<endl;
    }

    for(int i = 0; i<matched.size(); i++) {
        cout<<"Found match at letter: "<<matched[i]<<endl;
    }

    return 0;
}