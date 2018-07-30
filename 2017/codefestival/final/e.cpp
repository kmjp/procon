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

int L,N;
string S;
vector<int> R[101010];
ll sum[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>N;
	L=S.size();
	
	FORR(c,S) c-='a';
	FOR(i,N) {
		cin>>x>>y;
		x--,y--;
		if(y<(L+1)/2) {
			R[x].push_back(y);
		}
		else if(x>=L/2) {
			R[L-1-y].push_back(L-1-x);
		}
		else {
			y=L-1-y;
			if(x<y) R[x].push_back(y-1);
			if(y<x) R[y].push_back(x-1);
		}
	}
	
	
	FOR(i,L/2) {
		if(i) sum[i]+=sum[i-1];
		int dif=((S[L-1-i]-(S[i]+sum[i]))%26+26)%26;
		sort(ALL(R[i]));
		if(R[i].size()>1) {
			FOR(j,R[i].size()-1) {
				if(R[i][j]!=R[i][j+1]) R[R[i][j]+1].push_back(R[i][j+1]);
			}
		}
		if(dif==0) continue;
		if(R[i].empty()) return _P("NO\n");
		sum[i]+=dif;
		sum[R[i][0]+1]-=dif;
	}
	_P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
