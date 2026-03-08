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
	int sorted(string s) {
		int N=s.size();
		int i;
		FOR(i,N-1) if(s[i]>s[i+1]) return 0;
		return 1;
	}
    int minOperations(string s) {
		int N=s.size();
		int i;
		if(sorted(s)) return 0;
		string s1=s,s2=s;
		sort(s1.begin(),s1.begin()+N-1);
		sort(s2.begin()+1,s2.begin()+N);
		if(sorted(s1)||sorted(s2)) return 1;
		sort(s1.begin()+1,s1.begin()+N);
		sort(s2.begin(),s2.begin()+N-1);
		if(sorted(s1)||sorted(s2)) return 2;
		sort(s1.begin(),s1.begin()+N-1);
		sort(s2.begin()+1,s2.begin()+N);
		if(sorted(s1)||sorted(s2)) return 3;
		return -1;
		
		
        
    }
};


