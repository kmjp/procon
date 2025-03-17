#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    int totalNumbers(vector<int>& digits) {
		int a,b,c,N=digits.size();
		set<int> S;
		FOR(a,N) FOR(b,N) FOR(c,N) {
			if(a==b) continue;
			if(a==c) continue;
			if(b==c) continue;
			int x=digits[a]*100+digits[b]*10+digits[c];
			if(x>=100&&x%2==0) S.insert(x);
		}
        return S.size();
    }
};

