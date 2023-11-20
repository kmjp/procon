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
    int findMinimumOperations(string s1, string s2, string s3) {
		int same=0;
		int i;
		FOR(i,1000) {
			if(s1.size()<=i) break;
			if(s2.size()<=i) break;
			if(s3.size()<=i) break;
			if(s1[i]!=s2[i]) break;
			if(s1[i]!=s3[i]) break;
			if(s2[i]!=s3[i]) break;
			same++;
		}
		cout<<same<<endl;
        if(same==0) return -1;
        return s1.size()+s2.size()+s3.size()-same*3;
    }
};
