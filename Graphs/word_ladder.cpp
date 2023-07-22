#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    string word;
    int level; 

    Node(string word, int level) {
        this -> word = word;
        this -> level = level;
    }
};

bool isPresentInList(string word, vector<string> wordList) {
            for(auto it: wordList) {
                if (word == it) return true;
            }
            return false;
        }

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<Node> q;
    q.push( Node(beginWord, 0));
    int ans = 0;

    while(! q.empty()) {
        Node frontNode = q.front();
        
        ans = frontNode.level;
        q.pop();

        
        for(int i = 0; i < frontNode.word.length(); i++) {
            char ch = frontNode.word[i];
            string newWord = frontNode.word;

            for( auto alphabet = 'a'; alphabet <= 'z'; alphabet++) {
                if(alphabet != ch)  {
                    newWord[i] = alphabet;
                    if(newWord == endWord) {
                        return ans +
                    }
                    if(newWord != frontNode.word && isPresentInList(newWord, wordList)) {
                        q.push( Node(newWord, frontNode.level + 1) );
                    }
                }
            }
        }
    } 
    return ans;       
}
int main(){





}

