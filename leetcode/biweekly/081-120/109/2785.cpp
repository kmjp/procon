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
    string sortVowels(string s) {
		string v;
		map<char,int> M;
		M['a']=M['i']=M['u']=M['e']=M['o']=1;
		M['A']=M['I']=M['U']=M['E']=M['O']=1;
		
		FORR(c,s) {
			if(M[c]) {
				v+=c;
				c='*';
			}
		}
		sort(ALL(v));
		reverse(ALL(v));
		FORR(c,s) if(c=='*') {
			c=v.back();
			v.pop_back();
		}
		return s;
		
        
    }
};
