#include<iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
		enum InputType {  
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPONENT,
        }; 
		
		int transTable[][6] = {
            -1,  0,  3,  1,  2, -1,
            -1,  8, -1,  1,  4,  5,
            -1, -1, -1,  4, -1, -1,
            -1, -1, -1,  1,  2, -1,
            -1,  8, -1,  4, -1,  5,
            -1, -1,  6,  7, -1, -1,
            -1, -1, -1,  7, -1, -1,
            -1,  8, -1,  7, -1, -1,
            -1,  8, -1, -1, -1, -1,
        }; 
        
        int state = 0;  
        int i=0;
        int length= s.size();
        while (i<length)  
        {  
            InputType input = INVALID;  
            if (s[i] == ' ') input = SPACE;  
            else if (s[i] == '+' || s[i] == '-') input = SIGN;  
            else if (isdigit(s[i])) input = DIGIT;  
            else if (s[i] == '.') input = DOT;  
            else if (s[i] == 'e' || s[i] == 'E') input = EXPONENT;  
            state = transTable[state][input];  
            if (state == -1) return false;  
            ++i;  
        }  
        return state == 1 || state == 4 || state == 7 || state == 8;
        
    }
    
    bool isDigit(char t)
    {
    	return t<='9' && t>='0';
    }
};

int main()
{
	Solution *slt = new Solution();
	cout<<slt->isNumber("1234");
	return 0;
}
