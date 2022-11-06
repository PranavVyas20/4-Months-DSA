#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class temp{
    public:
    vector<string> v;
    int lvl;

    temp(vector<string> v, int lvl) {
        this -> v = v;
        this -> lvl = lvl;
    }
};

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // wordlist = [pat, bot, pot, poz, coz]
    // begin word = bat
    // end word = coz
    queue<temp> q;
    vector<string> v;
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string>> finalResult;

    v.push_back(beginWord);
    int lvl = 1;
    q.push(temp(v, lvl));

    while(!q.empty()) {
        temp frontTemp = q.front();
        vector<string> tempV = frontTemp.v;
        int tempLvl = frontTemp.lvl;
        q.pop();

        if(lvl != tempLvl) {
            // delete all the elements of frontV from the set
            for(int i = 0; i < tempV.size(); i++) {
                st.erase(tempV[i]);
            }
            lvl = tempLvl;
        }

        string word = tempV.back();

        if(word == endWord) {
            if(finalResult.size() == 0) {
                finalResult.push_back(tempV);
            }
            else if(finalResult[0].size() == tempV.size()) {
                finalResult.push_back(tempV);
            }
        }

        for(int i = 0; i < word.length(); i++) {
            char orgChar = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    tempV.push_back(word);
                    q.push(temp(tempV, tempLvl + 1));
                    tempV.pop_back();
                }
            }

            word[i] = orgChar;
        }
    }
    return finalResult;
}

int main(){

}

