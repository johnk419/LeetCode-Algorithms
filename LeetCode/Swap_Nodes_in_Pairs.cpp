// Question : https://leetcode.com/problems/swap-nodes-in-pairs/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* newHead = head->next;
        if (head->next != NULL) {
            if (newHead->next != NULL) {
                head->next = newHead->next;
            } else {
                head->next = NULL;
            }
            newHead->next = head;
        } else {
            return head;
        }
        while (head->next != NULL) {
            ListNode* previous = head;
            head = head->next;
            
            ListNode* temp = head->next;
            if (head->next != NULL) {
                if (previous != NULL) {
                    previous->next = head->next;
                } 
                if (temp->next != NULL) {
                    head->next = temp->next;
                } else {
                    head->next = NULL;
                }
                temp->next = head;
            }
        }
        return newHead;
    }
};