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
    char kthCharacter(long long k, vector<int>& operations) {
		int s=0;
		while(1LL<<(s+1)<k) s++;
		ll ret=0;
		ll P=1LL<<s;
		int i;
		k--;
		for(i=s;i>=0;i--) {
			cout<<i<<" "<<ret<<" "<<k<<endl;
			if(k>=1LL<<i) {
				k-=1LL<<i;
				if(operations[i]==1) ret++;
			}
		}
		return 'a'+ret%26;
        
    }
};
