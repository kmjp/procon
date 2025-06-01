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
int N;
int A[1010101];
ll X[1010101];
ll Y[1010101];
const ll mo=998244353;
ll win[1010101],lose[1010101];
unordered_map<ll,ll> lose_sum,win_sum1,win_sum2;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			win[i+1]=lose[i+1]=0;
		}
		reverse(A,A+N);
		
		lose_sum.clear();
		win_sum1.clear();
		win_sum2.clear();
		ll lst=0,ws1t=0,ws2t=0;
		lose_sum[0]=1;
		lose[0]=1;
		lst=1;
		
		int nim=0,ma=0;
		FOR(i,N) {
			nim^=A[i];
			if(A[i]>1) {
				FORR2(a,b,win_sum1) (win_sum2[a]+=b)%=mo;
				(ws2t+=ws1t)%=mo;
				ws1t=0;
				win_sum1.clear();
			}
			// nim‚Æmisere nim
			(win[i+1]+=mo+lst-lose_sum[nim])%=mo;
			(lose[i+1]+=lose_sum[nim])%=mo;
			(win[i+1]+=win_sum1[nim])%=mo;
			(lose[i+1]+=mo+ws1t-win_sum1[nim])%=mo;
			(win[i+1]+=mo+ws2t-win_sum2[nim])%=mo;
			(lose[i+1]+=win_sum2[nim])%=mo;

			(lose_sum[nim]+=lose[i+1])%=mo;
			(win_sum1[nim]+=win[i+1])%=mo;
			(lst+=lose[i+1])%=mo;
			(ws1t+=win[i+1])%=mo;
		}
		cout<<win[N]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
