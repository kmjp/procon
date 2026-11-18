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
int H,W,D;
string S[2020];
ll from[2020];
ll from2[2020];
ll fromS[2020];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>D;
		int PD=0;
		while((PD+1)*(PD+1)+1*1<=D*D) PD++;
		FOR(y,H) cin>>S[y];
		
		for(y=H-1;y>=0;y--) {
			if(y==H-1) {
				FOR(x,W) from[x]=(S[y][x]=='X');
			}
			else {
				FOR(x,W) fromS[x+1]=(fromS[x]+from[x])%mo;
				FOR(x,W) {
					if(S[y][x]=='X') from[x]=(fromS[min(W,x+PD+1)]-fromS[max(0,x-PD)]+mo)%mo;
					else from[x]=0;
				}
			}
			FOR(x,W) fromS[x+1]=(fromS[x]+from[x])%mo;
			FOR(x,W) {
				if(S[y][x]=='X') (from[x]+=(fromS[min(W,x+D+1)]-fromS[max(0,x-D)]-from[x]+2*mo))%=mo;
			}
			
		}
		ll ret=0;
		FOR(x,W) ret+=from[x];
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
