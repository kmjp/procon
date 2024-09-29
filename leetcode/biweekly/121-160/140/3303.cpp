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

using VT = string;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

int L[301010],R[303030];
class Solution {
public:
    int minStartingIndex(string s, string pattern) {
		int N=s.size();
		int M=pattern.size();
		string v=pattern+"*"+s;
		auto Z=Zalgo(v);
		int i;
		FOR(i,N) L[i]=Z[M+1+i];
		reverse(ALL(pattern));
		reverse(ALL(s));
		v=pattern+"*"+s;
		Z=Zalgo(v);
		FOR(i,N) R[N-i]=Z[M+1+i];
		
		for(i=0;i+M<=N;i++) {
			if(L[i]+R[i+M]>=M-1) return i;
		}
		return -1;
        
    }
};
