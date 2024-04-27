#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-k-sorted-lists/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class cmp
{
public:
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        int n = lists.size();
        if (n == 0)
        {
            return NULL;
        }
        ListNode *head = new ListNode(1);
        ListNode *temp = head;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        for (int i = 0; i < n; i++)
        {
            if (lists[i] != NULL)
            {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            if (curr->next)
            {
                pq.push(curr->next);
            }
            temp->next = curr;
            temp = temp->next;
        }

        return head->next;
    }
};

int main()
{

    return 0;
}