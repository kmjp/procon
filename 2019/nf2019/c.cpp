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

int N,M;
int H[101010];
int S[101010][3];
vector<int> add[101010][2];
int del[101010][2];
ll num[3];
ll W[101010],L[101010],D[103030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>H[i];
		FOR(j,3) S[i+1][j]=S[i][j]+(H[i]==j);
	}
	FOR(i,M) {
		cin>>x>>y;
		add[x-1][0].push_back(y);
		del[y][0]++;
		add[y][1].push_back(x-1);
		del[x-1][1]++;
	}
	
	ll valid=0;
	FOR(i,N) {
		valid-=del[i][0];
		FORR(a,add[i][0]) {
			valid++;
			FOR(j,3) num[j]+=S[a][j]-S[i][j];
		}
		num[H[i]]-=valid;
		W[i]+=num[(H[i]+1)%3];
		L[i]+=num[(H[i]+2)%3];
		D[i]+=num[(H[i]+3)%3];
	}
	ZERO(num);
	valid=0;
	for(i=N-1;i>=0;i--) {
		FORR(a,add[i+1][1]) {
			valid++;
			FOR(j,3) num[j]+=S[i+1][j]-S[a][j];
		}
		num[H[i]]-=valid;
		W[i]+=num[(H[i]+1)%3];
		L[i]+=num[(H[i]+2)%3];
		D[i]+=num[(H[i]+3)%3];
		valid-=del[i][1];
	}
	
	FOR(i,N) cout<<W[i]<<" "<<L[i]<<" "<<D[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
