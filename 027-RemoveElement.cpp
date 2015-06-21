#include<iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        int i;
        for(i=0; i<n; i++)
        {
            if(A[i]!=elem)
                A[index++] = A[i];
        }
        return index;
        
    }
};
