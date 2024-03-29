/**
 * Easy
 * 
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

     

    示例 1：

    输入：n = 2
    输出：2
    解释：有两种方法可以爬到楼顶。
    1. 1 阶 + 1 阶
    2. 2 阶
    示例 2：

    输入：n = 3
    输出：3
    解释：有三种方法可以爬到楼顶。
    1. 1 阶 + 1 阶 + 1 阶
    2. 1 阶 + 2 阶
    3. 2 阶 + 1 阶
     

    提示：

    1 <= n <= 45

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/climbing-stairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 使用动态规划解决 
// 时间复杂度O(n) 空间复杂度O(1)
// 重要的是依据数学归纳法找出 爬楼方式和楼层之间的递推公式
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> dp(2);
        int climbWays;
        dp[0] = 1; //dp[n - 1]代表的含义为达到第n阶有dp[n - 1]种方法
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            climbWays = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = climbWays;
        }
        return climbWays;
    }
};