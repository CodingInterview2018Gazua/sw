//
//  main.cpp
//  LinkedList
//
//  Created by sw on 2018. 8. 15..
//  Copyright © 2018년 sw. All rights reserved.
//
//
//  algo.cpp
//  Algorithm
//
//  Created by sw on 2018. 8. 15..
//  Copyright © 2018년 sw. All rights reserved.
//

/*
 연결 리스트로 표현된 두 개의 수가 있다고 하자. 리스트의 각 노드는 해당 수의 각 자릿수를 표현한다. 이때 자릿수들은 역순으로 배열되는데, 1의 자릿수가 리스트의
 맨 앞에 오도록 배열된다는 뜻이다. 이 두수를 더하여 그 합을 연결 리스트로 반환하는 함수를 작성하라.
 
 입력 : (7->1->6) + (5->9->2). 즉 617+295
 결과 : 2->1->9. 즉 912
 
 ##각 자릿수가 정상적으로 배열된다고 가정하고 구현해 보자.
 입력 : (6->1->7) + (2->9->5) 즉 617+295
 출력 : 9->1->2 즉 912
 
 순환 연결 리스트가 주어졌을 때, 순환되는 부분의 첫 노드를 반환하는 알고리즘을 작성하라.
 -정의
 순환 연결 리스트 : 순환 연결 리스트는 노드의 next 포인터가 앞선 노드들 가운데 어느 하나를 가리키도록 설정되어 있는
 연결 리스트다(망가진 연결 리스트라고 볼 수 있다.)
 -예
 입력 : A->B->C->D->E->C (E의 next 노드가 D 앞에 있는 C로 설정되어 있다.)
 출력 : C
 
 주어진 연결 리스트가 회문(palindrome)인지 검사하는 함수를 작성하라.
 */

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Node{
    friend class SinglyList;
private:
    int data;
    Node* nextNode;
    
    Node(){
        data=0;
        nextNode=NULL;
    };
    Node(int data){
        data=data;
        nextNode=NULL;
    }
};

class SinglyList{
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    SinglyList();
    void push(int);
    void insert(int,int);
    Node* pop();
    void print();
    void divideList(int);
    void reverse();
    int getSum(int n);
    bool checkPalindrome();
};

SinglyList::SinglyList(){
    head=NULL;
    tail=NULL;
    size=0;
}
void SinglyList::push(int data){
    Node* newNode=new Node();
    newNode->data=data;
    if(head==NULL)
        head=tail=newNode;
    else{
        tail->nextNode=newNode;
        tail=newNode;
    }
    size++;
}
void SinglyList::insert(int n, int data){
    Node* newNode=new Node(data);
    Node* previous=head;
    while(n-1>0){
        previous=previous->nextNode;
    }
    newNode->nextNode=previous->nextNode;
    previous->nextNode=newNode;
    
    size++;
}
Node* SinglyList::pop(){
    size--;
    Node* returnNode = head;
    head=returnNode->nextNode;
    
    return returnNode;
}
void SinglyList::print(){
    Node* cur=head;
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur=cur->nextNode;
    }
    cout<<endl;
}
void SinglyList::reverse(){
    Node* cur=head;
    Node* next=NULL;
    Node* previous=NULL;
    
    while(cur!=NULL){
        next=cur->nextNode;
        cur->nextNode=previous;
        previous=cur;
        cur=next;
    }
    head=previous;
}
int SinglyList::getSum(int n){
    Node* current=head;
    int digit=n/2;
    int count=digit;
    int sum1=0;
    int sum2=0;
    while(current!=NULL){
        if(digit>0){
            sum1+=current->data*(pow(10,digit-1));
            digit--;
        } else{
            sum2+=current->data*(pow(10,count-1));
            count--;
        }
        current=current->nextNode;
    }
    return sum1+sum2;
}
bool SinglyList::checkPalindrome(){
    bool checked;
    string front="";
    string end="";
    
    Node* current=head;
    
    for(int i=0;i<size;i++){
        if(i<(size/2)){
            front.append(to_string(current->data));
        }else{
            end.append(to_string(current->data));
        }
        current=current->nextNode;
    }
    
    if(front.compare(end))
        checked=true;
    else
        checked=false;
    return checked;
}
int main(int argc, const char * argv[]) {
    SinglyList list = SinglyList();
    list.push(7);
    list.push(1);
    list.push(6);
    list.push(6);
    list.push(1);
    list.push(7);
    
    list.print();
    list.reverse();
    list.print();
    //list합계
    cout<<list.getSum(6)<<endl;
    //회문 판별
    cout<<list.checkPalindrome();
    return 0;
}
