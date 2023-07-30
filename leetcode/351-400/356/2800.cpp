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
    string minimumString(string a, string b, string c) {
		string R=string(501,'z');
		vector<string> S={a,b,c};
		sort(ALL(S));
		do {
			string C;
			FORR(s,S) {
				int pre=0;
				int i;
				for(i=0;i<=min(s.size(),C.size());i++) if(C.substr(C.size()-i)==s.substr(0,i)) pre=i;
				for(i=0;i+s.size()<=C.size();i++) if(C.substr(i,s.size())==s) pre=s.size();
				
				C+=s.substr(pre);
			}
			cout<<C<<endl;
			if(C.size()<R.size()) R=C;
			if(C.size()==R.size()) R=min(R,C);
		} while(next_permutation(ALL(S)));
		
		
		return R;
		
        
    }
};
