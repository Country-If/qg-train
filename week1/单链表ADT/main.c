#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "linkedList.h"

void show();

void show()
{
    system("CLS");
    //�����ǽ���ʽ����
    printf("\n\n\n\n������ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.��������\n");
    printf("4.ɾ������\n");
    printf("5.��������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�ж������Ƿ�ɻ�\n");
    printf("9.��ת�����е�ż�����/�޴˹���\n");//����д 
    printf("10.�����м���\n");
    printf("11.�˳�\n");
    printf("\n�������Ӧ����(1-11)��");
}


int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
    	show();    
    	scanf("%d", &choice);
        switch(choice)
        {
            case 1: //����������
            {
                if(InitList(&head))        
                {
                    printf("���������ɹ�\n");
                }
                else
                {
                    printf("��������ʧ��\n");
                }    
                break;       
            }
            case 2: //��������
            {           
                DestroyList(&head);
                printf("�����������\n");
                break;
            }
            case 3: //��������
            {
            	if(head == NULL)
            	{
            		printf("����Ϊ�գ����ȴ�������\n");
				}
				else
				{
					printf("���������ݣ�");
                	scanf("%d", &num);
	                if(InsertList(head, num))
	                {
	                    printf("���ݲ���ɹ�\n");
	                }
	                else
	                {
	                    printf("���ݲ���ʧ��\n");
	                }
				}
                break;
            }
            case 4: //ɾ������
            {
                printf("����ɾ���ĸ����ݣ�");
                scanf("%d", &num);
                if(DeleteList(head, num))
                {
                    printf("����ɾ���ɹ�\n");
                }
                break;
            }
            case 5: //�������� 
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
                }
                else
                {
                    TraverseList(head);
                }
                break;
            }
            case 6: //�������� 
            {
                printf("������Ҫ���ҵ����ݣ�");
                scanf("%d", &num);
                if(SearchList(head, num))
                {
                    printf("��������\n");
                }
                else
                {
                    printf("����������\n");
                }
                break;
            }
            case 7: //��ת���� 
            {
                if(head == NULL || head->next == NULL) //�������������ֻ���������(���跴ת) 
                {
                    printf("�������������ֻ���������\n");
                }
                else
                {
                    if(ReverseList(&head))
                    {
                        printf("����ת�ɹ�\n");
                    }
                    else
                    {
                        printf("����תʧ��\n");
                    }
                }
                break;
            }
            case 8: //�ж������Ƿ�ɻ� 
            {
            	if(head == NULL || head->next == NULL)
            	{
            		printf("����Ϊ��\n");
				}
				else
				{
					if(IsLoopList(head))
	                {
	                    printf("����ɻ�\n");
	                }
	                else
	                {
	                    printf("����û�гɻ�\n");
	                }
				}
                break;
            }
            case 9: //��ת�����е�ż����� 
            {
                break;
            }
            case 10: //�����м��� 
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("���ǿ�����\n");
                }
                else
                {
                    printf("�����м�洢��ֵΪ%d\n", (FindMidNode(head))->data);
                }
                break;
            }
            case 11: //�������� 
            {
                DestroyList(&head);
                goto end;
            }
            default:
            {
            	printf("��������������!(1-11)\n");
				break;		
			}
        }
        getchar();
        system("pause");
    }while(1);

end:
	
    return 0;
}
