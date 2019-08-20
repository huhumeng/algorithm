/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#ifdef __APPLE__
#include "common.h"
#endif
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        // if(l1 == nullptr && l2 == nullptr){
        //     return nullptr;
        // }

        ListNode *head = new ListNode(0);
        ListNode *ret = head;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                ListNode *temp = new ListNode(l1->val);
                ret->next = temp;
                ret = temp;
                l1 = l1->next;
            }
            else
            {
                ListNode *temp = new ListNode(l2->val);
                ret->next = temp;
                ret = temp;
                l2 = l2->next;
            }
        }

        while (l1 != nullptr)
        {
            ListNode *temp = new ListNode(l1->val);
            ret->next = temp;
            ret = temp;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            ListNode *temp = new ListNode(l2->val);
            ret->next = temp;
            ret = temp;
            l2 = l2->next;
        }

        return head->next;
    }
};
