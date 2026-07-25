/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode * s1 , *s2 , *head,*temp,*thead;

    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    s1 = list1;
    s2 = list2;
    

    if(s1->val < s2->val){
        temp = s1;
        head = temp;
        s1=s1->next;
    }else{
        temp = s2;
        head = temp;
        s2=s2->next;
    }
    thead = head;
    
    while(temp->next!=NULL && s1!=NULL && s2!=NULL){
        if(s1->val <= s2->val){
            temp = s1;
            head->next = temp;
            head = temp;
            s1 = s1->next;
        }
        else{
            temp = s2;
            head->next = temp;
            head = temp;
            s2 = s2->next;
        }
    }
    if(s1!=NULL) head->next = s1;
    if(s2!=NULL) head->next = s2;

    return thead;
}