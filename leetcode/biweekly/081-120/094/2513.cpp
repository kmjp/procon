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
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll K=1LL<<40;
        int i;
        ll LCM=1LL*divisor1/__gcd(divisor1,divisor2)*divisor2;
        for(i=39;i>=0;i--) {
			ll T=K-(1LL<<i);
			ll ngb=T/LCM;
			ll ng1=T/divisor1-ngb;
			ll ng2=T/divisor2-ngb;
			ll ngo=ng1+ng2+ngb;
			ll okb=T-ngo;
			ll ok1=T-T/divisor1-okb;
			ll ok2=T-T/divisor2-okb;
			cout<<T<<" "<<ng1<<" "<<ng2<<" "<<ngb<<" "<<ngo<<" : "<<ok1<<" "<<ok2<<" "<<okb<<endl;
			if(ok1+okb>=uniqueCnt1&&ok2+okb>=uniqueCnt2&&ok1+ok2+okb>=uniqueCnt1+uniqueCnt2) K=T;
		}
		return K;
        
    }
};
