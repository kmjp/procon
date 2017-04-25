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

int K;
pair<int,int> P[101010];
int X[101010];
vector<int> VX;
int ID[101010];
int ok[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x>>y>>K;
	
	FOR(i,K) cin>>P[i+1].first>>P[i+1].second;
	P[K+1]={(1<<30)-1,(1<<30)-1};
	K+=2;
	sort(P,P+K);
	
	VX.push_back(0);
	VX.push_back(1<<30);
	FOR(i,K) VX.push_back(P[i].second);
	sort(ALL(VX));
	VX.erase(unique(ALL(VX)),VX.end());
	
	vector<int> A(K+2,1<<20);
	vector<int> lowest(K+2,0);
	int ma=-1;
	FOR(i,K) {
		X[i]=lower_bound(ALL(VX),P[i].second)-VX.begin();
		ID[i]=lower_bound(ALL(A),X[i]+1)-A.begin();
		A[ID[i]]=X[i];
		ma=max(ma,A[ID[i]]);
	}
	
	for(i=K-1;i>=0;i--) {
		if(i==K-1 || lowest[ID[i]+1]>=X[i]) {
			ok[ID[i]]++;
			lowest[ID[i]]=max(lowest[ID[i]],X[i]);
		}
	}
	
	cout<<count(ok,ok+K+2,1)-2<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
