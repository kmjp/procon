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

int pre[101010];
int suf[101010];

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
		int i;
		int N=s.size();
		FOR(i,t.size()) {
			if(i) pre[i]=pre[i-1];
			else pre[i]=0;
			if(pre[i]<s.size()&&s[pre[i]]==t[i]) pre[i]++;
		}
		suf[t.size()]=0;
		for(i=t.size()-1;i>=0;i--) {
			suf[i]=suf[i+1];
			if(suf[i]<N&&s[N-1-suf[i]]==t[i]) suf[i]++;
		}
		if(t.size()<s.size()) return 0;
		FOR(i,t.size()) {
			int sum=0;
			sum=1+suf[i+1];
			if(i) sum+=pre[i-1];
			if(sum>=N) return 1;
		}
		return 0;
        
    }
};
