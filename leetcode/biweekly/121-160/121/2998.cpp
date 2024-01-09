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

int D[50505];

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        int i;
        FOR(i,50505) D[i]=1<<20;
        D[x]=0;
        queue<int> Q;
        Q.push(x);
        while(Q.size()) {
			x=Q.front();
			Q.pop();
			if(x==y) return D[x];
			if(x+1<=50500&&chmin(D[x+1],D[x]+1)) Q.push(x+1);
			if(x-1>=0&&chmin(D[x-1],D[x]+1)) Q.push(x-1);
			if(x%5==0&&chmin(D[x/5],D[x]+1)) Q.push(x/5);
			if(x%11==0&&chmin(D[x/11],D[x]+1)) Q.push(x/11);
		}
		return 0;
    }
};
