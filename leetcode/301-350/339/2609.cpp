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
    int findTheLongestBalancedSubstring(string s) {
        int ma=0;
        int N=s.size();
        for(int len=2;len<=N;len+=2) {
			for(int i=0;i+len<=N;i++) {
				int j;
				for(j=0;j<len;j++) {
					if(j<len/2&&s[i+j]=='1') break;
					if(j>=len/2&&s[i+j]=='0') break;
				}
				if(j==len) ma=len;
			}
		}
        
		return ma;
    }
};
