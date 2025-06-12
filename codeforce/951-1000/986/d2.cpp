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

int T,N;
int P[3][202020];
int R[3][202020];

int ma[3];
int from[202020];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,3) {
			FOR(j,N) {
				cin>>P[i][j];
				from[j]=-1;
				R[i][P[i][j]]=j;
			}
			
		}
		from[0]=0;
		ZERO(ma);
		for(i=1;i<N;i++) {
			from[i]=-1;
			FOR(j,3) {
				if(P[j][i]<P[j][ma[j]]) from[i]=(j*1000000)+ma[j];
			}
			if(from[i]!=-1) {
				FOR(j,3) if(P[j][ma[j]]<P[j][i]) ma[j]=i;
			}
		}
		
		if(from[N-1]==-1) {
			cout<<"NO"<<endl;
		}
		else {
			vector<pair<int,int>> R;
			int cur=N-1;
			while(cur) {
				R.push_back({from[cur]/1000000,cur+1});
				cur=from[cur]%1000000;
			}
			reverse(ALL(R));
			cout<<"YES"<<endl;
			cout<<R.size()<<endl;
			FORR2(a,b,R) cout<<"qkj"[a]<<" "<<b<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
