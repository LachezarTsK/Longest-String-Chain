
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> wordsToChainLength;
        for (const auto& word : words) {
            wordsToChainLength[word] = 1;
        }
        auto comparatorSmallerToLargerLength = [](const string& first, const string & second) {
            return first.length() < second.length();
        };

        sort(words.begin(), words.end(), comparatorSmallerToLargerLength);
        int maxChainLength = 1;
        for (const auto& word : words) {

            int currentChainLength = 1;
            for (int i = 0; i < word.length(); ++i) {

                string previous = word.substr(0, i) + word.substr(i + 1, word.length());

                //C++20: wordsToChainLength.contains(previous)
                if (wordsToChainLength.find(previous) != wordsToChainLength.end()) {
                    currentChainLength = max(currentChainLength, 1 + wordsToChainLength[previous]);
                }
            }
            wordsToChainLength[word] = currentChainLength;
            maxChainLength = max(maxChainLength, currentChainLength);
        }
        return maxChainLength;
    }
};
