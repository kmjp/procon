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
ll K;
string S;
vector<int> E[101010];
int R[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
		((S[x]=='B')?B[y]:R[y])=1;
		((S[y]=='B')?B[x]:R[x])=1;
	}
	
	if(K%2==0) {
		FOR(i,N) {
			if(S[i]=='R') {
				cout<<"Second"<<endl;
			}
			else {
				x=0;
				FORR(e,E[i]) if(R[e]==0) x++;
				if(x) cout<<"First"<<endl;
				else cout<<"Second"<<endl;
			}
		}
	}
	else {
		FOR(i,N) {
			if(B[i]) {
				cout<<"First"<<endl;
			}
			else {
				cout<<"Second"<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
