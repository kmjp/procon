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

int H,W,N;
int X[202020],Y[202020];
vector<int> Ys[202020];
set<pair<int,int>> S;
set<int> fail[202020];

bitset<201010> B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>Y[i]>>X[i];
		Y[i]--;
		X[i]--;
		Ys[Y[i]].push_back(X[i]);
		S.insert({Y[i],X[i]});
	}
	
	FORR(s,S) {
		y=s.first-1;
		x=s.second;
		if(y>=0 && (S.count({y+1,x})||y==H-1)) fail[y].insert(x);
	}
	
	B[0]=1;
	for(y=0;y<H-1;y++) {
		FORR(f,fail[y]) if(B[f]) {
			cout<<y+1<<endl;
			return;
		}
		FORR(x,Ys[y+1]) B[x]=0;
		B |= B<<1;
		FORR(x,Ys[y+1]) B[x]=0;
		
		
	}
	
	cout<<H<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
