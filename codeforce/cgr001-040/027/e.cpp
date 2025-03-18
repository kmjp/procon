#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int T;
ll X,Y,Z,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>Y>>Z>>K;
		ll ret=1LL<<60;
		
		ll SD=Z;
		ll cur=0;
		if(K<=1000) {
			for(i=1;i<=Z&&SD>0;i++) {
				cur+=X;
				if(i%K==0) {
					cur+=Y;
					SD-=i;
				}
				SD=max(0LL,SD);
				ll a=cur+((SD+i-1)/i)*Y;
				ret=min(ret,a);
			}
		}
		else {
			for(i=0;i*K<=Z&&SD>0&&ret>cur;i++) {
				int L=i*K+1;
				int R=(i+1)*K;
				
				int SL=L;
				if(L<=10000) {
					for(x=L;x<=min(R,10000);x++) {
						ll e=cur+(x-L+1)*X+(SD+x-1)/x*Y;
						ret=min(ret,e);
					}
					SL=10001;
				}
				if(SL<=R) {
					for(x=(SD+R-1)/R;x<=(SD+SL-1)/SL;x++) {
						int v=(SD+x-1)/x;
						v=max(v,L);
						ll e=cur+(v-L+1)*X+(SD+v-1)/v*Y;
						ret=min(ret,e);
					}
				}
				
				
				
				SD-=(R);
				cur+=K*X+Y;
				
			}
			
		}
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
