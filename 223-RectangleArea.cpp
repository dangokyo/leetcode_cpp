#include<iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans = (C-A)*(D-B) + (G-E)*(H-F);
        if(A>=G || C<=E || D<=F || B>= H) return ans;
        
        int x1, x2, y1, y2;
        x1 = max(A, E);
        x2 = min(C, G);
        y1 = max(B, F);
        y2 = min(D, H);
        ans = ans - (x2-x1)*(y2-y1);
        return ans;
        
    }
};

int main()
{
    Solution *slt = new Solution();
    cout<<slt->computeArea(-3, 0, 3, 4, 0, -1, 9, 2)<<endl;
    getchar();
    return 0;
}
