/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 * step1
 * 当然1文字違いを探していく問題なのはわかる
 * 最短距離を求めるのでbfsがいいだろう
 * visitedを管理しながらqueueにつっこんでいけば、hot→dot→hotのようなループが起こらず、queueには最大でも
 * wordListの要素数分しか入らないのでwordListの長さをNとしてqueueにはN個しか入らずN回のチェックで完了できる。
 * さてここまではよさそうだが以下がブルートフォース的
 * 各回のチェックで、N個から探すとそれにN回チェックが起こる(visited管理してもN^2/2回チェックになる)
 * かつ1文字違いの見つけ方でstringの長さ分かかる。
 * 制約をみるとN<=5000かつ文字の長さ10なので5000*5000*10= 2.5 *
 * 1e8のオーダー計算量はこれでも問題なさそう。
 * 一文字違い(あるいは一文字の追加削除)の見つけ方はleetcodeでもCTCIという本でも見たはずなのに思い出せない。
 * ラビンカーブだったか、文字列のhash計算してしまうのは26^10 がわからなくても20^10 =
 * 1e13程度なのでいけそうか とも思ったが、ASCII対応128文字とか20文字とかで容易に詰むので採用しない。
 * 諦めてブルートフォースで解く。ASCII以上になっても問題ないし20文字でも計算量2倍なので。
 * string_viewが頭をよぎったが自信がないのでstep2の宿題とする
 * vectorをわざわざ作るのはオーバーヘッドが大きいが、より汎用的な気がするのでqueueを引数でとってつっこむとはしなかった。
 * acには成功。
 *
 * */

// @lc code=start
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution
{
   public:
    bool differsByExactlyOneChar(const string& s1, const string& s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        int count = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                count++;
            if (count > 1)
                return false;
        }
        return count == 1;
    }

    vector<string> collectStringsDifferingByExactlyOneChar(const string& s, const vector<string>& wordList, vector<uint8_t>& used)
    {
        vector<string> result;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            if (differsByExactlyOneChar(s, wordList[i]))
            {
                result.push_back(wordList[i]);
                used[i] = 1;
            }
        }
        return result;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<uint8_t> used(wordList.size());
        using WordAndLadderLength = pair<string, int>;
        queue<WordAndLadderLength> candidates;
        candidates.emplace(beginWord, 1);
        while (candidates.size())
        {
            auto [word, ladderLen] = move(candidates.front());
            candidates.pop();

            if (word == endWord)
            {
                return ladderLen;
            }
            auto subStrings = collectStringsDifferingByExactlyOneChar(word, wordList, used);
            for (auto& subString : subStrings)
            {
                candidates.emplace(subString, ladderLen + 1);
            }
        }

        return 0;
    }
};
// @lc code=end
