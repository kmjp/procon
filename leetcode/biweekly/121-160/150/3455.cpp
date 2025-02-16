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

class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
		string A[3];
		set<int> OK[3];
		int x=0,i,j;
		FORR(c,p) {
			if(c=='*') x++;
			else A[x]+=c;
		}
		int N=s.size();
		FOR(x,3) {
			string V=A[x]+"*"+s+"$";
			auto Z=Zalgo(V);
			FOR(i,N+1) {
				if(Z[A[x].size()+1+i]>=A[x].size()) OK[x].insert(i);
			}
		}
		int mi=1<<20;
		OK[1].insert(1<<20);
		OK[2].insert(2<<20);
		FORR(a,OK[0]) {
			int b=a+A[0].size();
			b=*OK[1].lower_bound(b);
			b=*OK[2].lower_bound(b+A[1].size());
			mi=min(mi,b+(int)A[2].size()-a);
		}
        if(mi>1<<19) mi=-1;
        return mi;
    }
};


