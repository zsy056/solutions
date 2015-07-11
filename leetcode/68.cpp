/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if (words.size() == 0) {
            return result;
        }
        int currentWords = 0;
        int currentLineBegin = 0;
        int currentLineEnd = 0;
        int currentLength = 0;
        while (currentLineBegin < words.size()) {
            int wordLength = currentLineEnd < words.size() ?
                words[currentLineEnd].length() : 0;
            int lineLength = currentLength + wordLength
                + currentLineEnd - currentLineBegin;
            if (lineLength > maxWidth || currentLineEnd == words.size()) {
                int lineBegin = currentLineBegin;
                int lineEnd = currentLineEnd - 1;
                string line;
                if (lineEnd == words.size() - 1) {
                    line = makeLineL(words, maxWidth, lineBegin, lineEnd, currentLength);
                } else {
                    line = makeLine(words, maxWidth, lineBegin, lineEnd, currentLength);
                }
                result.push_back(move(line));

                currentLength = 0;
                currentLineBegin = currentLineEnd;
            } else {
                currentLength += words[currentLineEnd].length();
                ++currentLineEnd;
            }
        }
        return result;
    }

private:
    string makeLineL(
            const vector<string> &words,
            int maxWidth,
            int lineBegin,
            int lineEnd,
            int currentLength) {
        string line;
        for (int i=lineBegin; i<lineEnd; ++i) {
            line.append(words[i]);
            line.append(" ");
        }
        line.append(words[lineEnd]);
        if (maxWidth > line.length()) {
            string spaces(maxWidth - line.length(), ' ');
            line.append(spaces);
        }
        return line;
    }

    string makeLine(
            const vector<string> &words,
            int maxWidth,
            int lineBegin,
            int lineEnd,
            int currentLength) {
        string line;
        int lineWords = lineEnd - lineBegin + 1;
        int spaces = maxWidth - currentLength;
        int spacesPer = spaces / (lineWords == 1 ? 1 : lineWords - 1);
        int spaceExtra = spaces % (lineWords == 1 ? 1 : lineWords - 1);
        string space(spacesPer, ' ');

        for (int i=0; i<lineWords-1 || lineWords == 1; ++i) {
            line.append(words[lineBegin + i]);
            line.append(space);
            if (i < spaceExtra) {
                line.append(" ");
            }
            if (lineWords == 1) {
                break;
            }
        }
        if (lineWords > 1) {
            line.append(words[lineEnd]);
        }
        return line;
    }
};
