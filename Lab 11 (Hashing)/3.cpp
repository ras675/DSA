#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> Sentence(const string& s) {
    vector<string> words;
    string word;

    for (char c :s){
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word = word+c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

void OccurWords(const vector<string>& words) {
    unordered_map<string, int> wordCount;

    for (const string& word : words) {
        wordCount[word]++;
    }

    for (const auto& entry : wordCount) {
        if (entry.second > 1) {
            cout << entry.first << " " << entry.second << endl;
        }
    }
}

int main() {
    string s;

    getline(cin, s);

    vector<string> words = Sentence(s);

    OccurWords(words);

    return 0;
}

