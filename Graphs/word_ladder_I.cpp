#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class temp{
    public:
    string word;
    int length;

    temp(string word, int length) {
        this -> word = word;
        this -> length = length;
    }

};
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        queue<temp> q;
        q.push(temp(beginWord, 1));

        // Insert all the words in the set
        for(int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]);
        }
        st.erase(beginWord);


        while(!q.empty()) {
            temp frontTemp = q.front();
            string frontWord = frontTemp.word;
            q.pop();
            if(frontWord == endWord) return frontTemp.length;

            int frontWordLen = frontTemp.word.length();
            // Replacing every char and checking if it exists in the wordList(set)
            for(int i = 0; i < frontWordLen; i++) {
                // Loop for char a to z
                char orgChar = frontWord[i];

                for(char ch = 'a'; ch <= 'z'; ch ++) {
                    frontWord[i] = ch;
                    // If word is found in the word list (set)
                    // add in q with len (frontTemp.length ++);
                    // remove frontword from the set
                    if(st.find(frontWord) != st.end()) {
                        q.push(temp(frontWord,frontTemp.length + 1));
                        st.erase(frontWord);
                    }
                }
                frontWord[i] = orgChar;
            }
        }
        return 0;
}
int main(){

}

