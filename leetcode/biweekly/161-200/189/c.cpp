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

ll p10[20];


class Solution {
public:
    int kthDigit(long long k) {
        p10[0]=1;
        int i;
        FOR(i,18) p10[i+1]=p10[i]*10;
        k++;
        
        if(k<=10) return k-1;
        
        FOR(i,18) {
			ll num=(i==0)?10:(p10[i+1]-p10[i])*(i+1);
			if(k>num) {
				k-=num;
				continue;
			}
			ll d=(k-1)/(i+1);
			if(i==1) {
				if(d/10%2==0) d=d/10*10+(9-d%10);
			}
			else {
				if(d/10%2==1) d=d/10*10+(9-d%10);
			}
			d+=p10[i];
			string V=to_string(d);
			cout<<d<<" "<<i+1<<" "<<V<<" "<<k<<endl;
			return V[(k-1)%(i+1)]-'0';
		}
		return 0;
        
        
    }
};

