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
    bool isPossibleToRearrange(string s, string t, int k) {
		vector<string> A,B;
		int i,j;
		FOR(i,k) {
			string a,b;
			FOR(j,s.size()/k) {
				a+=s[i*s.size()/k+j];
				b+=t[i*s.size()/k+j];
			}
			A.push_back(a);
			B.push_back(b);
		}
		sort(ALL(A));
		sort(ALL(B));
		return A==B;
        
    }
};


