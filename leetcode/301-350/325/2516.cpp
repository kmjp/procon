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
    int takeCharacters(string s, int k) {
        int C[3]={};
        int i;
        int N=s.size();
        FOR(i,N) {
			s[i]-='a';
			C[s[i]]++;
		}
		if(C[0]<k||C[1]<k||C[2]<k) return -1;
		int mi=N;
		int L=N-1,R=N;
		for(int L=N-1,R=N;L>=0;L--) {
			C[s[L]]--;
			while(R>L&& (C[0]<k||C[1]<k||C[2]<k)) {
				R--;
				C[s[R]]++;
			}
			if(R>=L)mi=min(mi,L+N-R);
		}
		
		return mi;
    }
};

