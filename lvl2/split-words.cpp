#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to split a string manually
vector<string> manualSplit(const string& text) {
    vector<string> words;
    string word;
    
    for (char ch : text) {
        if (ch == ' ') {  // Space indicates word boundary
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) words.push_back(word);  // Add last word

    return words;
}

// Function to split a string using stringstream
vector<string> streamSplit(const string& text) {
    vector<string> words;
    string word;
    stringstream ss(text);  // Create a string stream
    
    while (ss >> word) {  // Extract words
        words.push_back(word);
    }
    
    return words;
}

// Function to display words
void displayWords(const vector<string>& words, const string& method) {
    cout << method << ": ";
    for (const string& word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;
}

int main() {
    string text = "C++ is an amazing language!";
    
    // Manual Split
    vector<string> manualWords = manualSplit(text);
    displayWords(manualWords, "Manual Split");
    
    // Using stringstream
    vector<string> streamWords = streamSplit(text);
    displayWords(streamWords, "StringStream Split");
    
    return 0;
}
