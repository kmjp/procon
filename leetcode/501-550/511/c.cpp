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
    vector<bool> transformStr(string s, vector<string>& strs) {
		vector<bool> ret;
		int n1=count(ALL(s),'1');
		FORR(t,strs) {
			int n2=count(ALL(t),'1');
			int as=count(ALL(t),'?');
			if(n2>n1||as+n2<n1) {
				ret.push_back(0);
				continue;
			}
			int add0=as-(n1-n2);
			int cur=0;
			int i;
			FOR(i,s.size()) {
				char c=t[i];
				if(c=='?') {
					if(add0) {
						c='0';
						add0--;
					}
					else {
						c='1';
					}
				}
				if(s[i]=='1') cur++;
				if(c=='1') cur--;
				if(cur<0) break;
			}
			ret.push_back(i==s.size());
			
		}
		return ret;
        
    }
};


