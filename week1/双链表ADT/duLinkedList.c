#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if(List == NULL)//内存分配失败
    {
        return error;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return success;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : void
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(p->next == NULL)//当链表为空时，直接连接p、q
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return success;
    }
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p->next == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //找到删除结点的位置
        while(posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("找不到该数据\n");
                return error;
            }
        }
        if(posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        free(posNode);
        return success;
    }
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : void
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L) {
    if(L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }  
	else if(L->next == NULL)
	{
		printf("当前链表为空\n");
	}  
    else
    {
        DuLinkedList temp = L->next;
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
