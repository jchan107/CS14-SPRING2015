//Name: Jeremy Chan SID: 861169589 date: 4/19/2015
//Lecturer: Jacobs Lab Director: Dingwen

#ifndef _LAB3_H_
#define _LAB3_H_

#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

struct Node

{
    int m;//holds the m and n values
    int n;
    Node( int m,int n ) : m(m), n(n) {}//constructor
};

void preOrderTrav(int K, int M, int N)//recursive helper function for pre order traversal
{
    Node n1((2*M)-N,M);//creates the 3 children nodes
    Node n2((2*M) + N,M);
    Node n3(M + (2*N),N);
    
    cout << M << " " << N << endl;//prints the nodes in pre-order
    if(n1.m + n1.n < K)//only calls the function recursively if the sum of M and N in child node is less that K
    {
        preOrderTrav(K,n1.m,n1.n);
    }
    if(n2.m + n2.n < K)
    {
        preOrderTrav(K,n2.m,n2.n);
    }
    if(n3.m + n3.n < K)
    {
        preOrderTrav(K,n3.m,n3.n);
    }
}

void preOrder(int highestV)
{
    preOrderTrav(highestV,2,1);//calls the helper function on both sides of the root node
    preOrderTrav(highestV,3,1);
}

void postOrderTrav(int K, int M, int N)//recursive function for postorder traversing
{
    Node n1((2*M)-N,M);//creates the 3 child nodes
    Node n2((2*M) + N,M);
    Node n3(M + (2*N),N);
    

    if(n1.m + n1.n < K)//only preforms recursion if the sum of values, M and N, in child node are less than K
    {
        postOrderTrav(K,n1.m,n1.n);
    }
    if(n2.m + n2.n < K)
    {
        postOrderTrav(K,n2.m,n2.n);
    }
    if(n3.m + n3.n < K)
    {
        postOrderTrav(K,n3.m,n3.n);
    }
    cout << M << " " << N << endl;//prints the values in post-order
}

void postOrder(int highestV)
{
    postOrderTrav(highestV,2,1);//calls the post order helper function on both sides of root node
    postOrderTrav(highestV,3,1);
}

void sortedTrav(int K, int M, int N, priority_queue<pair<int,int>,// helper function for sorted order
vector<pair<int,int>>,greater<pair<int,int>>>&Q)//passes the priority queue in by reference
{
    Node n1((2*M)-N,M);//makes node for all three children
    Node n2((2*M) + N,M);
    Node n3(M + (2*N),N);
    
    pair<int, int> P(M,N);//pushes current node into the priority queue
    Q.push(P);
    if(n1.m + n1.n < K)//only recursively calls if the child node has a sum M + N which is less than 9
    {
        sortedTrav(K,n1.m,n1.n,Q);
    }
    if(n2.m + n2.n < K)
    {
        sortedTrav(K,n2.m,n2.n,Q);
    }
    if(n3.m + n3.n < K)
    {
        sortedTrav(K,n3.m,n3.n,Q);
    }
}

void sortedOrder(int highestV)
{
    typedef pair<int, int> P;//defines the pair
    priority_queue< P, vector<P>, greater<P> > Q;//creates priority queue with specifications as to order
    sortedTrav(highestV,2,1,Q);//gets from both sides of the parent node
    sortedTrav(highestV,3,1,Q);
    while(!Q.empty())//outputs all the values stored in the priority queue
    {
        cout << Q.top().first << " " << Q.top().second << endl;
        Q.pop();
    }
}
#endif