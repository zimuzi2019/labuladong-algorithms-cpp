# labuladong-algorithms-cpp

记录用 c++ 在本地做《labuladong 的算法小抄》提到的题目

## 核心套路

前面树的题目先跳过不看 

----

**全排列**、N 皇后问题

----

**二叉树的最小高度**、解开密码锁的最少次数

----

**判断列表中是否有环、已知链表中含有环，返回环的起始位置、寻找无环链表的中点、寻找单链表的倒数第 k 个元素**

---

**二分查找、两数之和、反转数组**

```c++
int binary_search(int nums[]. int target) {
    int left = 0;
    int right = sizeof(nums)/sizeof(nums[0]);
    
    while(left <= right) {
        int mid = (right + left) / 2;
        if (nums[mid] ==  target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    
    return -1
}
```

二分查找寻找左侧和右侧边界的变体

---



快速排序实现：

``` c++
#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[left]; // 选择第一个元素作为基准
    int l = left + 1;
    int r = right;

    while (l <= r) {
        // 找到左边大于基准的元素
        while (l <= r && arr[l] <= pivot) {
            l++;
        }

        // 找到右边小于基准的元素
        while (l <= r && arr[r] > pivot) {
            r--;
        }

        // 如果左指针小于右指针，交换它们
        if (l < r) {
            swap(arr[l], arr[r]);
        }
    }

    // 将基准放到正确的位置
    swap(arr[left], arr[r]);

    // 递归排序左右子数组
    quicksort(arr, left, r - 1);
    quicksort(arr, r + 1, right);
}

int main() {
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

变体：找第 k 大数

```c++
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left]; // 选择第一个元素作为基准
    int l = left + 1;
    int r = right;

    while (l <= r) {
        while (l <= r && arr[l] <= pivot) {
            l++;
        }

        while (l <= r && arr[r] > pivot) {
            r--;
        }

        if (l < r) {
            swap(arr[l], arr[r]);
        }
    }

    swap(arr[left], arr[r]);

    return r; 
}

int findKthLargest(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            return findKthLargest(arr, left, pivotIndex - 1, k);
        } else {
            return findKthLargest(arr, pivotIndex + 1, right, k);
        }
    }

    return -1; // 不可能的情况
}

int main() {
    vector<int> arr = {3, 6, 8, 10, 1,  1};
    int k = 4; 
    int index = arr.size() - k;

    int result = findKthLargest(arr, 0, arr.size() - 1, index);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}

```





---

最小覆盖子串

**字符串排列**

**找所有字母异位词**

**最长无重复子串**

## 动态规划

凑硬币

-----

**最长递增子序列**

信封嵌套问题

**最大子数组问题**

**最长公共子序列**

编辑距离

**最长回文子序列**

**以最小插入次数构造回文串**

正则表达式

**不同的定义产生不同的解法**

**高楼扔鸡蛋**

**戳气球问题**

**0-1 背包问题**

**子集背包问题**

**完全背包问题**

**线性排列**、**环形排列**、树形排列

**目标和**

-----



**股票交易**

> 实际一般的股票交易根本不用动态规划那么复杂

## 数据结构

**单调栈**

单调队列

---

**判断回文链表**

反转链表、反转链表前 N 个节点

``` c++
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) { this->val = val; this->next = nullptr; }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        return prev;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);
    
    while (reversedHead != nullptr) {
        cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }
    
    return 0;
}
```

``` c++
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) { this->val = val; this->next = nullptr; }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfStart = reverseList(slow);

        ListNode* firstHalfStart = head;
        ListNode* secondHalfCopy = secondHalfStart;  // To restore the list later
        bool isPalindrome = true;
        while (secondHalfStart != nullptr) {
            if (firstHalfStart->val != secondHalfStart->val) {
                isPalindrome = false;
                break;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfStart = secondHalfStart->next;
        }

        reverseList(secondHalfCopy);  // Optional: Restore the list

        return isPalindrome;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    bool result = solution.isPalindrome(head);
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;  // Output: true

    return 0;
}

```

## 算法思维

**子集**、**组合**、**排列**

解数独

**括号生成**

华容道

**2Sum**、nSum

实现计算器

**摊烧饼**

**汉诺塔问题**

``` c++
#include <iostream>
using namespace std;

void solveHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << endl;
        return;
    }

    // Step 1: Move n-1 disks from fromRod to auxRod
    solveHanoi(n - 1, fromRod, auxRod, toRod);

    // Step 2: Move the nth disk from fromRod to toRod
    cout << "Move disk " << n << " from rod " << fromRod << " to rod " << toRod << endl;

    // Step 3: Move n-1 disks from auxRod to toRod
    solveHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 3;  // Number of disks
    solveHanoi(n, 'A', 'C', 'B');  // A is the source rod, C is the destination rod, B is the auxiliary rod
    return 0;
}

```

**前缀和解决子数组问题**

## 高频面试

素数筛

模幂运算

**KoKo 吃香蕉、运输货物**

**接雨水**

**有序数组去重**

**判断括号合法性**

**最长回文子串**

**跳跃游戏Ⅰ**、跳跃游戏Ⅱ

**无重叠区间**、**用最少的箭头射气球**

考场就座

Union-Find

## 附1：LeetCode 热题 100

### 书里有的

[1. 两数之和](https://leetcode.cn/problems/two-sum/)

[15. 三数之和](https://leetcode.cn/problems/3sum/)

[42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)

[3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

[438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/)

[560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

[239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)

[76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

[53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

[206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

[234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

[141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)

[142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

[25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

[98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

[105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

[236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

[124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/)

[46. 全排列](https://leetcode.cn/problems/permutations/)

[78. 子集](https://leetcode.cn/problems/subsets/)

[22. 括号生成](https://leetcode.cn/problems/generate-parentheses/)

[51. N 皇后](https://leetcode.cn/problems/n-queens/)

[20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

[739. 每日温度](https://leetcode.cn/problems/daily-temperatures/)

[121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

[55. 跳跃游戏](https://leetcode.cn/problems/jump-game/)

[45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

[198. 打家劫舍](https://leetcode.cn/problems/house-robber/)

[322. 零钱兑换](https://leetcode.cn/problems/coin-change/)

[300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

[416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)

[5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)

[1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)

[72. 编辑距离](https://leetcode.cn/problems/edit-distance/)

### 书里没有的

[49. 字母异位词分组]((https://leetcode.cn/problems/group-anagrams/))

[128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/)

[283. 移动零](https://leetcode.cn/problems/move-zeroes/)

[11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

[56. 合并区间](https://leetcode.cn/problems/merge-intervals/)

[189. 轮转数组](https://leetcode.cn/problems/rotate-array/)

[238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)

[41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/)

[73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)

[54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)

[48. 旋转图像](https://leetcode.cn/problems/rotate-image/)

[240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

[160. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

[21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

[2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)

[19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

[24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

[138. 随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/)

[148. 排序链表](https://leetcode.cn/problems/sort-list/)

[23. 合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

[146. LRU 缓存](https://leetcode.cn/problems/lru-cache/)

[94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

[104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

[226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

[101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree/)

[543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/)

[102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

[108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

[230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/)

[199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

[114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

[437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii/)

[200. 岛屿数量](https://leetcode.cn/problems/number-of-islands/)

[994. 腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/)

[207. 课程表](https://leetcode.cn/problems/course-schedule/)

[208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/)

[17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

[39. 组合总和](https://leetcode.cn/problems/combination-sum/)

[79. 单词搜索](https://leetcode.cn/problems/word-search/)

[131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/)

[35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/)

[74. 搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix/)

[34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

[33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)

[153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)

[4. 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

[155. 最小栈](https://leetcode.cn/problems/min-stack/)

[394. 字符串解码](https://leetcode.cn/problems/decode-string/)

[84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/)

[215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

[347. 前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/)

[295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/)

[763. 划分字母区间](https://leetcode.cn/problems/partition-labels/)

[70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

[118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

[279. 完全平方数](https://leetcode.cn/problems/perfect-squares/)

[139. 单词拆分](https://leetcode.cn/problems/word-break/)

[152. 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/)

[32. 最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/)

[62. 不同路径](https://leetcode.cn/problems/unique-paths/)

[64. 最小路径和](https://leetcode.cn/problems/minimum-path-sum/)

[136. 只出现一次的数字](https://leetcode.cn/problems/single-number/)

[169. 多数元素](https://leetcode.cn/problems/majority-element/)

[75. 颜色分类](https://leetcode.cn/problems/sort-colors/)

[31. 下一个排列](https://leetcode.cn/problems/next-permutation/)

[287. 寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/)

## 附2：其他面试题收集

1、双队列模拟栈

``` c++
#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q1, q2;

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int top = q1.front();
        q1.pop();

        swap(q1, q2);

        return top;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int top = q1.front();
        
        q2.push(top);
        q1.pop();

        swap(q1, q2);

        return top;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << "Top element: " << stack.top() << endl;  
    cout << "Pop element: " << stack.pop() << endl;  
    cout << "Top element after pop: " << stack.top() << endl; 
    cout << "Pop element: " << stack.pop() << endl; 
    cout << "Pop element: " << stack.pop() << endl;  
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; 

    return 0;
}
```

