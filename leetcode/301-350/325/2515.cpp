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
    int closetTarget(vector<string>& words, string target, int startIndex) {
		int mi=100000;
		int i;
		int N=words.size();
		FOR(i,words.size()) if(target==words[i]) {
			mi=min(mi,abs(i-startIndex));
			mi=min(mi,abs(N+i-startIndex));
			mi=min(mi,abs(-N+i-startIndex));
		}
		if(mi==100000) mi=-1;
		return mi;
        
    }
};

