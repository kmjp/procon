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
int N,M;
ll A[303030],S[303030];
ll B;

const ll mo=1000000007;
int cost[303030];
ll pat[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
		}
		
		
		FOR(i,N+1) {
			cost[i]=1<<30;
			pat[i]=0;
		}
		cost[0]=0;
		pat[0]=1;
		while(M--) {
			cin>>B;
			
			map<int,ll> C;
			C[1<<30]=1;
			C[0]=1;
			for(int L=0,R=1;R<=N;R++) {
				while(S[R]-S[L]>B) {
					C[cost[L]]-=pat[L];
					if(C[cost[L]]==0) C.erase(cost[L]);
					L++;
				}
				
				auto it=C.begin();
				if(chmin(cost[R],it->first+M)) pat[R]=0;
				if(cost[R]==it->first+M) {
					pat[R]+=it->second;
					if(pat[R]>=mo) {
						pat[R]%=mo;
						if(pat[R]==0) pat[R]=mo;
					}
				}
				C[cost[R]]+=pat[R];
			}
		}
		
		
		if(cost[N]==1<<30) {
			cout<<-1<<endl;
		}
		else {
			cout<<cost[N]<<" "<<pat[N]%mo<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
