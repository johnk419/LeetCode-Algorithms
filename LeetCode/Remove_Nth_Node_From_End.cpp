// Question : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* currentNode = head;
        vector<ListNode*> array;
        
        if (currentNode->next == NULL) {
            return NULL;
        }
        
        int index = 0;
        while (currentNode->next != NULL) {
            array.push_back(currentNode);
            currentNode = currentNode->next;
            index++;
        }
        
        if (n > index) {
            return array[0]->next;;
        } else if (n != 1) {
            array[index - (n)]->next = array[index - (n)]->next->next;
            
        } else {
            array[index - (n)]->next = NULL;
        }
        return array[0];
    }
};