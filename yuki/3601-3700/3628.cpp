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
ll N;
const ll mo=998244353;
ll di[1010];
ll p10[22];

ll dp[20][2][100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=999;i>=0;i--) {
		if(i/100>i%10+(i/10)%10) {
			di[i]=0;
		}
		else {
			di[i]=di[i+1]+1;
		}
	}
	
	p10[0]=1;
	FOR(i,20) p10[i+1]=p10[i]*10;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=(N%mo)*((N+1)%mo)%mo*((mo+1)/2)%mo+mo-100;
		ZERO(dp);
		dp[18][0][0]=1;
		
		for(int d=18;d>=0;d--) {
			int v=N/p10[d]%10;
			for(int le=0;le<=1;le++) {
				for(int s=0;s<100;s++) if(dp[d][le][s]) {
					for(int c=0;c<10;c++) {
						if(le==0&&c>v) continue;
						if(s/10>s%10+c) continue;
						if(d) {
							(dp[d-1][le|c<v][s%10*10+c]+=dp[d][le][s])%=mo;
						}
						else {
							(ret+=di[s*10+c]*dp[d][le][s])%=mo;
						}
					}
				}
			}
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
