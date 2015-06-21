// 3-LongSubstring.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
		int tmp_len = 0;
		int ans = 0;

		if(length == 1)
		{
			return 1;
		}

		int start, pos;

		for(start=0; start < length;)
		{
			if(ans > length - start)
			{
				break;
			}

			tmp_len = 0;
			
			for(pos = 1; pos < length - start; pos++)
			{
				++tmp_len;
				string tmp = s.substr(start, pos);
				string::size_type position = tmp.find(s[start + pos]);
				//cout<<tmp<<" Position: "<<start<<" "<<pos<<" "<<position<<endl;
				if(start + pos ==length - 1 && position == tmp.npos)
				{
					ans = tmp_len+1;
					return ans;
				}

				if(position != tmp.npos)
				{

					int k = start + pos;
					start = start + position;
					do
					{
						if(s[start] == s[k])
						{
							k++;
							start++;
						}
						else break;
					} while (k<length);
					
					//cout<<"test:"<<start<<' '<<k<<endl;
					if(ans < tmp_len)
					{
						ans = tmp_len;
						//cout<<tmp<<' '<<tmp.size()<<endl;
					}

					break;
				}

			}

		}

		return ans;
    }
};

int main()
{
	Solution *slt = new Solution();
	char x;
	//string in = "msboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuu";
	//string in = "qrsvbspk";
	//string in = "xnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxz";
	//cout <<slt->lengthOfLongestSubstring(in)<<endl;
	cout<<slt<<endl;
    cin>>x;
	return 0;
}

