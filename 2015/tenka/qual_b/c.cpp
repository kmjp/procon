#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll L;
ll mo=1000000007;
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L;
	
	ll ma=L/4;
	while(4*(ma+1)+1<=L) ma++;
	while(4*(ma)+1>L) ma--;
	ret = (ma%mo)*((ma-1)%mo)%mo*((mo+1)/2)%mo;
	if(ma>=4) (ret += ((ma-2)%mo)*((ma-3)%mo)%mo*((mo+1)/2)%mo)%=mo;
	
	for(ll xx=ma+1;xx+(xx+1)+2<=L;xx++) {
		ll a=2;
		ll b=L-(xx+xx+1);
		if(a>b) continue;
		ret += b-a+1+mo;
		if(a<=xx-1 && xx-1<=b) ret--;
		if(a<=xx && xx<=b) ret--;
		if(a<=xx+1 && xx+1<=b) ret--;
		ret %=mo;
		
		if(a<=xx-1 && xx-1<=b) {
			ll bn=L-(xx+9999+xx+9999+1);
			if(bn>=2 && (a<=xx+10000 && xx+10000<=bn)) {
				bn-=4;
				ll b1=L-(xx+1+xx+1+1)-4;
				(ret += (b1+bn)*9999/2)%=mo;
				ret %= mo;
				xx+=9999;
			}
		}
		else if((a<=xx-1 && xx-1<=b)==0) {
			ll bn=L-(xx+9999+xx+9999+1);
			if(bn>=2) {
				bn-=1;
				ll b1=L-(xx+1+xx+1+1)-1;
				(ret += (b1+bn)*9999/2)%=mo;
				xx+=9999;
			}
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
