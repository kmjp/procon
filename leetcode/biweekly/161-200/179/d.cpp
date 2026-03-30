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

int D[5050];
ll from[5050],to[5050];
const ll mo=1000000007;
class Solution {
public:
    int countArrays(vector<int>& digitSum) {
		int i;
		FOR(i,5001) {
			int x=i,d=0;
			while(x) d+=x%10,x/=10;
			D[i]=d;
		}
		ZERO(from);
		from[0]=1;
		FORR(d,digitSum) {
			ZERO(to);
			ll sum=0;
			FOR(i,5001) {
				(sum+=from[i])%=mo;
				if(D[i]==d) {
					to[i]=sum;
				}
			}
			swap(from,to);
		}
		ll ret=0;
		FOR(i,5001) ret+=from[i];
		return ret%mo;
        
    }
};
