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
    int distMoney(int money, int children) {
		int ma=-1;
		int i;
		FOR(i,children+1) {
			if(8*i>money) continue;
			int lef=money-8*i;
			if(lef<children-i) continue;
			if(i==children&&lef) continue;
			if(lef==4&&i+1==children) continue;
			ma=max(ma,i);
		}
        return ma;
    }
};
