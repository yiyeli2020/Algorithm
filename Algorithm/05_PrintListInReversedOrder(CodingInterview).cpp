/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������6����β��ͷ��ӡ����
// ��Ŀ������һ��������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��

#include "List.h"
#include <stack>
#include<iostream>
using namespace std;
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> sta;
    while (pHead != NULL) {
        sta.push(pHead);
        pHead = pHead->m_pNext;
    }
    while (!sta.empty()) {
        ListNode* top = sta.top();
        cout << top->m_nValue << endl;
        sta.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
    if (pHead != NULL) {
        if (pHead->m_pNext != NULL) {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        cout << pHead->m_nValue << endl;
    }
}

// ====================���Դ���====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// ֻ��һ����������: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// ������
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
