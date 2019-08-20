/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// #include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr)
            return l2;
        
        if(l2 == nullptr)
            return l1;
        
    
        int sum = l1->val + l2->val;

        int a = sum % 10;
        int b = sum / 10;

        ListNode *ret = new ListNode(a);
        ListNode *head_node = ret;

       
        while (l1->next != nullptr && l2->next != nullptr)
        {
            
            l1 = l1->next;
            l2 = l2->next;

            /* code */
            sum = l1->val + l2->val + b;

            a = sum % 10;
            b = sum / 10;

            head_node->next = new ListNode(a);
            head_node = head_node->next;
        }

        while (l1->next != nullptr)
        {
            l1 = l1->next;
            sum = l1->val + b;
            a = sum % 10;
            b = sum / 10;

            head_node->next = new ListNode(a);
            head_node = head_node->next;
        }
        
        while (l2->next != nullptr)
        {
            l2 = l2->next;
            sum = l2->val + b;
            a = sum % 10;
            b = sum / 10;

            head_node->next = new ListNode(a);
            head_node = head_node->next;
        }

        if(b != 0)
        {
            head_node->next = new ListNode(b);
        }

        return ret;
        
    }
};

