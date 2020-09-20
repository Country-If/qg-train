#include "linkedList.h"
#include<stdlib.h>
#include<stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    LinkedList list;
    
    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    list->next = NULL;
    *L = list;
    
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, ElemType data) {
	LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
    if(newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while(current->next != NULL)
    {
    	current = current->next;
	}
	current->next = newNode;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType e) {
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if(posNode == NULL)
    {
        printf("该链表为空，无法删除\n");
    }
    else
    {
        while(posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("没有该数据\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return SUCCESS;
    }    
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L) {
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)  
    {    
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    while(L != NULL )
    {      
        if(L->data == e)
        {
            return SUCCESS;
        }
        L = L->next;
    }
    return error;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LNode *temp, *p1, *p2;//p1p2用于反转链表，temp用于储存反转后的头结点
	
	p1 = (*L)->next;
	p2 = p1->next;
	p1->next = NULL;
	temp = p1; 
	while(p2 != NULL) //p2为null时p1指向最后 
	{
		p1 = p2;
		p2 = p1->next;
		p1->next = temp;
		temp = p1;
	}
	(*L)->next = temp;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if((fast = fast->next->next) == NULL)
		return error; 
        if(fast == slow)
        return SUCCESS;
    }
    return error;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
 
LNode* ReverseEvenList(LinkedList *L) {

}         

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
