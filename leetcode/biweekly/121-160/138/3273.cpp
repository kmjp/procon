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

vector<int> D,H;
bool cmp(int a,int b) {
	ll v1=1LL*D[a]*H[a]+1LL*D[b]*(H[a]+H[b]);
	ll v2=1LL*D[b]*H[b]+1LL*D[a]*(H[a]+H[b]);
	return v1<v2;
}

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        D=damage;
        H=health;
        vector<int> A;
        int i,N=damage.size();
        FOR(i,N) {
			H[i]=(H[i]+power-1)/power;
			A.push_back(i);
		}
        sort(ALL(A),cmp);
        ll ret=0;
        ll turn=0;
        FOR(i,N) {
			turn+=H[A[i]];
			ret+=D[A[i]]*turn;
		}
		return ret;
    }
};

