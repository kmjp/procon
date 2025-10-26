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
    string lexSmallest(string s) {
		vector<string> S;
		int i,N=s.size();
		FOR(i,N) {
			reverse(s.begin(),s.begin()+i+1);
			S.push_back(s);
			reverse(s.begin(),s.begin()+i+1);
			reverse(s.end()-i-1,s.end());
			S.push_back(s);
			reverse(s.end()-i-1,s.end());
		}
		return *min_element(ALL(S));
        
    }
};
