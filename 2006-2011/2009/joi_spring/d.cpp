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

int W,H,N;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
string S;

ll mo=10000000;

ll from[1010];
ll to[1010];
ll hoge(vector<int> V,int W) {
	ZERO(from);
	from[0]=1;
	FORR(v,V) {
		ZERO(to);
		ll S=0;
		if(v==0) {
			for(int i=0;i<=W;i++) to[i]=S, (S+=from[i])%=mo;
		}
		else {
			for(int i=W;i>=0;i--) to[i]=S, (S+=from[i])%=mo;
		}
		
		swap(from,to);
	}
	return from[W];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N;
	cin>>S;
	
	ll ret=0;
	FOR(i,2) {
		vector<int> A[2];
		int d=i;
		A[d%2].push_back(d/2);
		FORR(c,S) {
			if(c=='L') d++;
			else d+=3;
			d%=4;
			A[d%2].push_back(d/2);
		}
		ret+=hoge(A[0],W)*hoge(A[1],H);
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
