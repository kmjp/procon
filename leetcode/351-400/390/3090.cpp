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
    int maximumLengthSubstring(string s) {
		int a,b;
		int N=s.size();
		int ma=0;
		FOR(a,N) {
			map<char,int> M;
			for(b=1;a+b<=N;b++) {
				M[s[a+b-1]]++;
				if(M[s[a+b-1]]>2) break;
				ma=max(ma,b);
			}
		}
        return ma;
    }
};
