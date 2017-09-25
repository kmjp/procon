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

int H,W;
string S[201];

int C[201][201];

void draw(int T,int L,int D,int R) {
	int y,x;
	S[T][1]=')';
	S[T][2]='(';
	S[T][3]=')';
	//cout<<T<<L<<D<<R<<endl;
	for(y=T;y<D;y++) for(x=L;x<R;x++) {
		if(((y-T)+(x-L))%2==0) S[y][x]='(';
		else S[y][x]=')';
	}
	for(x=R;x<100;x++) {
		if((x+(D-1))%2==0) S[D-1][x]='(';
		else S[D-1][x]=')';
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	vector<vector<int>> cand;
	FOR(y,90) FOR(x,y+1) {
		if(x==0 || x==y) C[y][x]=1;
		else C[y][x]=min((1<<30)-2,C[y-1][x]+C[y-1][x-1]);
		if(C[y][x]<=K && y%2==0 && (y-x+1)%2==0) cand.push_back({C[y][x],y,x});
	}
	
	sort(ALL(cand));
	reverse(ALL(cand));
	
	FOR(y,100) {
		S[y]=string(101,'.');
		if(y%2==0) S[y][0]=S[y][100]='(';
		else S[y][0]=S[y][100]=')';
		for(x=1;x<=3;x++) S[y][x]=')';
		for(x=97;x<=99;x++) S[y][x]='(';
	}
	
	
	int curh=0;
	FORR(c,cand) if(c[0]<=K) {
		K -= c[0];
		//cout<<c[2]<<" "<<c[1]-c[2]<<" "<<c[0]<<" --> "<<K<<endl;
		draw(curh,4,curh+c[1]-c[2]+1,4+c[2]+1);
		curh += c[1]-c[2]+2;
		if(curh%2==1) curh++;
	}
	
	if(K==1) {
		FOR(x,101) {
			if(x<50) S[99][x]='(';
			else S[99][x]=')';
		}
	}
	
	cout<<100<<" "<<101<<endl;
	FOR(y,100) {
		FOR(x,101) if(S[y][x]=='.') S[y][x]=')';
		cout<<S[y]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
