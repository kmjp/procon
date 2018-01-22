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

int N,K;

int W[5020][5020];
int B[5020][5020];

int WW(int x,int y) {
	if(x>=0 && y>=0) return W[y][x];
	return 0;
}
int BB(int x,int y) {
	if(x>=0 && y>=0) return B[y][x];
	return 0;
}

pair<int,int> hoge(int X,int Y) {
	int w=WW(Y+K,X+K)-WW(Y,X+K)-WW(Y+K,X)+WW(Y,X);
	int b=BB(Y+K,X+K)-BB(Y,X+K)-BB(Y+K,X)+BB(Y,X);
	return make_pair(w,b);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y>>s;
		x%=2*K;
		y%=2*K;
		if(s=="W") W[y][x]++;
		else B[y][x]++;
	}
	
	for(y=0;y<=5010;y++) for(x=0;x<=5010;x++) {
		B[y][x] = B[y][x]+(y?B[y-1][x]:0)+(x?B[y][x-1]:0)-((y&&x)?B[y-1][x-1]:0);
		W[y][x] = W[y][x]+(y?W[y-1][x]:0)+(x?W[y][x-1]:0)-((y&&x)?W[y-1][x-1]:0);
	}
	int ma=0;
	for(x=-2*K;x<=0;x++) {
		for(y=-K;y<=0;y++) {
			int ok=0;
			FOR(i,4) FOR(j,4) {
				auto p=hoge(x+i*K,y+j*K);
				if((i+j)%2) ok+=p.first;
				if((i+j)%2==0) ok+=p.second;
			}
			ma=max(ma,ok);
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
