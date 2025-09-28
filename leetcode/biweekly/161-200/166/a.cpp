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
    string majorityFrequencyGroup(string s) {
		int C[256]={};
		int D[256]={};
		FORR(c,s) C[c]++;
		int i;
		FOR(i,256) if(C[i]) D[C[i]]++;
		int ma=1;
		FOR(i,256) if(D[i]>=D[ma]) ma=i;
		
		string v;
		FOR(i,256) if(C[i]==ma) v.push_back(i);
		return v;
		
        
    }
};


