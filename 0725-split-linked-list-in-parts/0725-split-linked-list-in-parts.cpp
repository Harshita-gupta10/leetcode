/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> result(k, NULL);

        // find length
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        int eachBucketNode = len/k;
        int extraNode = len%k;

        // make fill k buckets
        curr = head;
        ListNode* prev = NULL;
        for(int i = 0; i < k; i++)
        {
            result[i] = curr;
            for(int count = 1; count <= len/k + (extraNode > 0 ? 1 : 0); count++)
            {
                prev = curr;
                curr = curr->next;
            }
            if(prev) prev->next = NULL;
            extraNode--;
        }
        return result;
    }
};