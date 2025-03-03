#include <iostream>
#include <string>
using namespace std;
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool isBad(const string &S) {
    int consonantCount = 0;
    int vowelCount = 0;
    for (char c : S) {
        if (c == '?') continue; 
        if (isVowel(c)) {
            vowelCount++;
            consonantCount = 0;
        } else {
            consonantCount++;
            vowelCount = 0;
        }
        if (consonantCount > 3 || vowelCount > 5) {
            return true; 
        }
    }
    return false;
}
string classifyString(string S) {
    if (isBad(S)) {
        return "BAD";
    }
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            if (i == 0 || !isVowel(S[i-1])) {
                S[i] = 'b'; 
            } else {
                S[i] = 'a'; 
            }
        }
        if (isBad(S)) {
            return "BAD";
        }
    }
    return "GOOD";
}

int main() {
    string S;
    cin >> S;
    cout << classifyString(S) << endl;
    
    return 0;
}
