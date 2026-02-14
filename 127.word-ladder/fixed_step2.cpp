/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 * step2
 * auto currentはあとでqueueにintを入れる必要があると気づき急遽pairにしたのだが、ならtopを受けるとき2変数で受ければよかった。
 * distanceと書くとstd::distanceと衝突するので、絶対的にusing stdが悪だが、lenという名前にした。distのような略語は使わないべきと学習。
 * string_viewは復習。
 * 文字の長さが10なので、一文字違いを全てリストアップして、これらがwordListの中に含まれているかを調べるのが定石らしい。wordListはHash setにする。
 * また、上記のやり方だとqueueの長さが長くなってきたとき、そのすべてについて一文字違いをリストアップすることになるので、双方向bfsのほうがさらに効率がいい
 * containsとeraseを組み合わせると、findでイテレータを持つときと異なり2度探索が起こるが、コンパイラが将来最適化してくれることに期待して、読みやすい現方式でいいのではないか。hash setだし。
 * CTCIでは一文字違いを、一文字削除や一文字追加と同様に扱うことが可能なことを、2 pointerで示していたが、今回の問題とは関係なさそうだった。
 *
 * */

// @lc code=start

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.contains(endWord))
        {
            return 0;
        }

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};

        int step = 1;

        while (!beginSet.empty() && !endSet.empty())
        {
            if (beginSet.size() > endSet.size())
            {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextSet;
            for (string word : beginSet)
            {
                for (int i = 0; i < word.size(); ++i)
                {
                    char originalChar = word[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == originalChar)
                        {
                            continue;
                        }
                        word[i] = c;

                        if (endSet.contains(word))
                        {
                            return step + 1;
                        }

                        if (dict.contains(word))
                        {
                            nextSet.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }
            beginSet = move(nextSet);
            step++;
        }

        return 0;
    }
};
// @lc code=end
