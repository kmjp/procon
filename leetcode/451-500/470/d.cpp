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

ll p10[18];

class Solution {
public:
    long long countNoZeroPairs(long long n) {
		
		int i;
		p10[0]=1;
		FOR(i,17) p10[i+1]=p10[i]*10;
		
		ll ret=0;
		int mask;
		FOR(mask,1<<15) {
			ll v=n;
			FOR(i,15) if(mask&(1<<i)) v-=p10[i+1];
			ll pat=1;
			if(v<0) continue;
			v=n;
			FOR(i,15) if(v>0&&pat) {
				if(i&&(mask>>i)==0) {
					string s=to_string(v);
					if(count(ALL(s),'0')==0) ret+=pat*2;
				}
				ll a=v%10;
				if(mask&(1<<i)) a+=10;
				v-=a;
				v/=10;
				if(a>=2&&a<=18) {
					pat=pat*(9-abs(10-a));
				}
				else {
					pat=0;
				}
			}
			//cout<<mask<<" "<<v<<" "<<pat<<" "<<ret<<endl;
			ret+=pat;
		}
        return ret;
    }
};


