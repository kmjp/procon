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

int H,W,Q;
set<pair<int,int>> S;
string A[2020];
int B[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	
	FOR(y,H) {
		cin>>A[y];
		FOR(x,W) B[y][x]=A[y][x]=='#';
	}
	FOR(y,H-1) FOR(x,W-1) {
		if(B[y][x]^B[y][x+1]^B[y+1][x]^B[y+1][x+1]) S.insert({y,x});
	}
	while(1) {
		
		if(S.size()<=1) {
			cout<<"Yes"<<endl;
		}
		else if(S.size()==2 || S.size()==4) {
			set<int> R,C;
			FORR(s,S) R.insert(s.first),C.insert(s.second);
			if(R.size()*C.size()==S.size() && R.size()<4 && C.size()<4) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
		else {
			cout<<"No"<<endl;
		}
		
		if(--Q==0) break;
		
		int r,c;
		cin>>r>>c;
		r--,c--;
		B[r][c]^=1;
		for(y=max(0,r-1);y<=r&&y+1<=H-1;y++) for(x=max(0,c-1);x<=c&&x+1<=W-1;x++) {
			k=B[y][x]^B[y][x+1]^B[y+1][x]^B[y+1][x+1];
			if(k==0) S.erase({y,x});
			else S.insert({y,x});
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
