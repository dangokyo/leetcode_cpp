#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        int length = points.size();
        if(length<=2) return length;

		int i, j;     
		int duplicate;
		unordered_map<double, int> countMap; //map<slope, count>
		double slope;
		for(i=0; i<length-1; i++)
		{
			countMap.clear();
			duplicate = 1;
			countMap[INT_MAX] = 0;
			for(j=i+1; j<length; j++)
			{
				if(points[i].x == points[j].x && points[i].y==points[j].y)
				{
					duplicate++;
				}
				else if(points[i].y == points[j].y)
				{
					countMap[0]++;
				}
				else if(points[i].x == points[j].x)
				{
					countMap[INT_MAX]++;
				}
				else
				{
					slope = ((double)(points[j].y - points[i].y)) / (points[j].x - points[i].x);
					countMap[slope]++;
				}
				
			}
			
			unordered_map<double, int>::iterator MI = countMap.begin();
			unordered_map<double, int>::iterator ME = countMap.end();
			for(; MI!= ME; MI++)
			{
				if(MI->second + duplicate > ans) ans = MI->second + duplicate;
			}
			
		}   
        
        
        return ans;
    }
};

int main()
{
	vector<Point> in;
	Point p1(1,1);
	Point p2(1,3);
	Point p3(2,2);
	Point p4(3,3);
	Point p5(4,1);
	in.push_back(p1);
	in.push_back(p2);
	in.push_back(p3);
	in.push_back(p4);
	in.push_back(p5);
	Solution *slt = new Solution();
	cout<<slt->maxPoints(in);
	return 0;
}
