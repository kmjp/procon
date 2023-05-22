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
	int can(int num,int sum) {
		string s=to_string(num);
		reverse(ALL(s));
		int N=s.size();
		int mask;
		int i;
		FOR(mask,1<<N) {
			int val=0,p=1;
			FOR(i,N) {
				val+=(s[i]-'0')*p;
				p*=10;
				if(mask&(1<<i)) p=1;
			}
			if(val==sum) {
				return 1;
			}
		}
		return 0;
		
	}
    int punishmentNumber(int n) {
        int ret=0,i;
        for(i=1;i<=n;i++) if(can(i*i,i)) ret+=i*i;
        return ret;
    }
};
