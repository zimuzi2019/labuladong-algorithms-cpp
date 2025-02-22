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

