
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public int longestStrChain(String[] words) {
        Map<String, Integer> wordsToChainLength = new HashMap<>();
        for (String word : words) {
            wordsToChainLength.put(word, 1);
        }
        Arrays.sort(words, (first, second) -> first.length() - second.length());

        int maxChainLength = 1;
        for (String word : words) {

            int currentChainLength = 1;
            for (int i = 0; i < word.length(); ++i) {

                StringBuilder previous = new StringBuilder(word);
                previous.deleteCharAt(i);
                String previousToString = previous.toString();

                if (wordsToChainLength.containsKey(previousToString)) {
                    currentChainLength = Math.max(currentChainLength, 1 + wordsToChainLength.get(previousToString));
                }
            }
            wordsToChainLength.put(word, currentChainLength);
            maxChainLength = Math.max(maxChainLength, currentChainLength);
        }
        return maxChainLength;
    }
}
