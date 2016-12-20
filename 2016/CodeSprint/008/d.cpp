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

int Q,N;
ll mo=1000000007;

int p3[101010],p4[101010],p5[101010],prime[101010];
map<int,int> dp[20];
int from[100],to[100];
int mp[100000];

ll ret[404040];
vector<int> ne[100000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=99999;i++) {
		j=i;
		y=0;
		while(j) y+=j%10, j/=10;
		prime[i]=(y>1);
		for(x=2;x*x<=y;x++) if(y%x==0) prime[i]=0;
	}
	FOR(i,1000) p3[i]=prime[i];
	FOR(i,10000) p4[i]=prime[i] & p3[i/10] & p3[i%1000];
	FOR(i,100000) p5[i]=prime[i] & p4[i/10] & p4[i%10000] & p3[i/100] & p3[i/10%1000] & p3[i%1000];
	
	for(i=1;i<=9;i++) dp[1][i]=1, ret[1]++;
	for(i=10;i<=99;i++) dp[2][i]=1, ret[2]++;
	for(i=100;i<=999;i++) if(p3[i]) dp[3][i]=1, ret[3]++;
	for(i=1000;i<=9999;i++) if(p4[i]) dp[4][i]=1;
	
	FOR(i,10000) FOR(x,10) if(p5[i*10+x]) ne[i].push_back((i*10+x)%10000);
	
	for(i=5;i<=10;i++) {
		FORR(r,dp[i-1]) {
			ret[i-1]+=r.second;
			FORR(v,ne[r.first]) {
				dp[i][v] += r.second;
				if(dp[i][v]>=mo) dp[i][v]-=mo;
			}
		}
		ret[i-1] %= mo;
		dp[i-1].clear();
	}
	
	set<int> S;
	vector<int> V;
	FORR(r,dp[10]) {
		S.insert(r.first);
		FORR(v,ne[r.first]) S.insert(v);
	}
	x=0;
	FORR(r,S) mp[r]=x++, V.push_back(r);
	FORR(r,V) from[mp[r]]=dp[10][r];
	
	for(i=11;i<=400002;i++) {
		ZERO(to);
		FORR(r,V) {
			ret[i-1]+=from[mp[r]];
			FORR(v,ne[r]) {
				to[mp[v]] += from[mp[r]];
				if(to[mp[v]]>=mo) to[mp[v]]-=mo;
			}
		}
		
		ret[i-1] %= mo;
		swap(from,to);
	}
	


	
	cin>>Q;
	while(Q--) {
		cin>>x;
		cout<<ret[x]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
