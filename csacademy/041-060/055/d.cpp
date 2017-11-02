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

int H,W,K;
string S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	vector<int> cand;
	int need=0;
	FOR(x,W/2) {
		int a=0,b=0;
		FOR(y,H) a+=S[y][x]!=S[y][W-1-x];
		FOR(y,H/2) {
			map<char,int> m;
			m[S[y][x]]++;
			m[S[y][W-1-x]]++;
			m[S[H-1-y][x]]++;
			m[S[H-1-y][W-1-x]]++;
			int mi=4;
			FORR(r,m) mi=min(mi,4-r.second);
			b+=mi;
		}
		if(H%2==1) b+=S[H/2][x]!=S[H/2][W-1-x];
		need+=a;
		cand.push_back(b-a);
	}
	sort(ALL(cand));
	reverse(ALL(cand));
	while(K>=2) {
		need+=cand.back();
		cand.pop_back();
		K-=2;
	}
	if(W%2) {
		int dif=0;
		FOR(y,H/2) dif+=S[y][W/2]!=S[H-1-y][W/2];
		cand.push_back(dif);
		sort(ALL(cand));
		reverse(ALL(cand));
	}
	if(K) {
		need+=cand.back();
	}
	cout<<need<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
