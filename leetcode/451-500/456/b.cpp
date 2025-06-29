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
	int common(string a,string b) {
		int i;
		FOR(i,min(a.size(),b.size())) if(a[i]!=b[i]) return i;
		return i;
	}
    vector<int> longestCommonPrefix(vector<string>& words) {
        int i,N=words.size();
        vector<int> ret(N);
        int pre=0;
        for(i=2;i<N;i++) {
			pre=max(pre,common(words[i-1],words[i-2]));
			ret[i]=pre;
		}
		pre=0;
		for(i=N-3;i>=0;i--) {
			pre=max(pre,common(words[i+1],words[i+2]));
			ret[i]=max(ret[i],pre);
		}
		for(i=1;i<N-1;i++) ret[i]=max(ret[i],common(words[i-1],words[i+1]));
		
		return ret;
        
    }
};
