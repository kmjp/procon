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

int N;
string S[22];
int L[22];
int dp[1<<20][20];

int ig[20],im;
int C[20][20];

using VT = string;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1<<30;
	
	FOR(i,N) {
		cin>>S[i];
		L[i]=S[i].size();
	}
	FOR(x,N) FOR(y,N) if(x!=y) {
		string V=S[y]+S[x];
		auto Z=Zalgo(V);
		C[x][y]=L[y];
		
		if(S[x]==S[y]) {
			if(x<y) {
				ig[x]++;
				im|=1<<x;
			}
			continue;
		}
		
		FOR(i,L[x]) {
			if(Z[L[y]+i]+L[y]+i==L[x]+L[y]) chmin(C[x][y],L[y]-(L[x]-i));
			if(Z[L[y]+i]>=L[y]) {
				ig[y]++;
				im|=1<<y;
			}
		}
	}
	
	FOR(i,N) if(ig[i]==0) dp[(1<<i)^im][i]=L[i];
	int mi=1<<30;
	FOR(mask,1<<N) FOR(i,N) if(dp[mask][i]<1<<30) {
		FOR(x,N) if((mask&(1<<x))==0) chmin(dp[mask|(1<<x)][x],dp[mask][i]+C[i][x]);
		if(mask==(1<<N)-1) mi=min(mi,dp[mask][i]);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
