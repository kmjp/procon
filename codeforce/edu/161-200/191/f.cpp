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

ll N,A,B;

vector<ll> D1,D2;
ll TD1[2020][2020];
ll TD2[2020][2020];
vector<int> C1[2020],C2[2020];
ll memo[2020][2020];

ll dfs(int x,int y) {
	if(x==0&&y==0) return 0;
	if(memo[x][y]>=0) return memo[x][y];
	ll ret=1LL<<60;
	FORR(d1,C1[x]) FORR(d2,C2[y]) if(d1+d2) ret=min(ret,max(D1[d1],D2[d2])+dfs(TD1[x][d1],TD2[y][d2]));
	return memo[x][y]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	ll g=__gcd(A,B);
	A/=g;
	B/=g;
	
	D1.clear();
	D2.clear();
	for(i=1;i*i<=A;i++) if(A%i==0) {
		D1.push_back(i);
		if(i*i!=A) D1.push_back(A/i);
	}
	for(i=1;i*i<=B;i++) if(B%i==0) {
		D2.push_back(i);
		if(i*i!=B) D2.push_back(B/i);
	}
	sort(ALL(D1));
	sort(ALL(D2));
	int L1=D1.size();
	int L2=D2.size();
	FOR(i,L1) {
		x=0;
		C1[i].clear();
		for(j=i;j>=0;j--) {
			if(D1[i]%D1[j]==0) C1[i].push_back(j);
			while(x<i&D1[i]>D1[x]*D1[j]) x++;
			if(D1[i]%D1[j]==0&&D1[x]*D1[j]==D1[i]) TD1[i][j]=x;
		}
		reverse(ALL(C1[i]));
	}
	FOR(i,L2) {
		x=0;
		C2[i].clear();
		for(j=i;j>=0;j--) {
			if(D2[i]%D2[j]==0) C2[i].push_back(j);
			while(x<i&D2[i]>D2[x]*D2[j]) x++;
			if(D2[i]%D2[j]==0&&D2[x]*D2[j]==D2[i]) TD2[i][j]=x;
		}
		reverse(ALL(C2[i]));
	}
	MINUS(memo);
	cout<<dfs(L1-1,L2-1)<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
