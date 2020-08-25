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

int H,W,M;
int R[303030];
int C[303030];
set<pair<int,int>> S;
pair<int,int> PR[303030],PC[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>M;
	FOR(i,M) {
		cin>>y>>x;
		y--,x--;
		R[y]++;
		C[x]++;
		S.insert({y,x});
	}
	
	FOR(i,H) PR[i]={-R[i],i};
	FOR(i,W) PC[i]={-C[i],i};
	
	sort(PR,PR+H);
	sort(PC,PC+W);
	
	int ma=0;
	FOR(y,H) if(PR[y].first) {
		FOR(x,W) {
			int ty=-PR[y].first;
			int tx=-PC[x].first;
			if(ty+tx<=ma) break;
			if(tx==0) break;
			int cnt=ty+tx-(S.count({PR[y].second,PC[x].second}));
			ma=max(ma,cnt);
		}
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
