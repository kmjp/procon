#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

void solve() {
	int i,j,k,l,r,x,y; string s;
	set<ll> R;
	
	FOR(i,100) {
		FOR(j,1000000) {
			ll a=j+(1LL<<29);
			a=a*a-50+i;
			ll d=(a-1)/4;
			
			//64bitなら以下のvolatile云々は不要でコメント通り1行で書ける。
			//32bit環境だと-msse2 -mfpmath=sseを付けるか、FPUのレジスタいじって80it→64bit精度にするか
			//以下のコードのように無理やりdoubleにキャストしてどうにかする
			
			//ll t=(ll)((-1 + sqrt(1+4*d)) / 2.0);
			volatile double c = 1 + 4*d;
			volatile ll b = c;
			ll t=(ll)((-1 + sqrt(b)) / 2.0);
			
			if(t*t+t>d || (t+1)*(t+1)+(t+1)<=d) {
				R.insert(d);
				if(R.size()==100000) {
					FORR(r,R) _P("%lld\n",r);
					return;
				}
			}
		}
	}
	return;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
