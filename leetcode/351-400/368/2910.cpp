#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
		map<int,int> A,B;
		vector<int> C;
		FORR(n,nums) A[n]++;
		FORR(a,A) B[a.second]++;
		
		int num=nums.size();
		for(int i=1;i<=nums.size();i++) {
			int ok=0;
			FORR(b,B) {
				int n=b.first;
				int j;
				for(j=(n+i)/(i+1);j<=(n+(i-1))/i;j++) {
					int L=j*i,R=j*(i+1);
					if(L<=n&&n<=R) {
						ok+=j*b.second;
						break;
					}
				}
				if(j>(n+i)/(i+1)) ok=1<<30;
			}
			num=min(num,ok);
		}
		return num;
        
    }
};
