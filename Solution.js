
/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function (words) {
    const wordsToChainLength = new Map();
    for (let word of words) {
        wordsToChainLength.set(word, 1);
    }
    words.sort((first, second) => first.length - second.length);

    let maxChainLength = 1;
    for (let word of words) {

        let currentChainLength = 1;
        for (let i = 0; i < word.length; ++i) {

            let previous = word.substring(0, i) + word.substring(i + 1, word.length);

            if (wordsToChainLength.has(previous)) {
                currentChainLength = Math.max(currentChainLength, 1 + wordsToChainLength.get(previous));
            }
            wordsToChainLength.set(word, currentChainLength);
        }
        maxChainLength = Math.max(maxChainLength, currentChainLength);
    }
    return maxChainLength;
};
