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

int N,D[101];
int cnt[13];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cnt[0]=2;
	FOR(i,N) {
		cin>>x;
		cnt[x]++;
		if(x==12) if(cnt[x]>1) return _P("0\n");
		if(cnt[x]>2) return _P("0\n");
	}
	
	int ma=0;
	for(int mask=0;mask<1<<12;mask++) {
		vector<int> V;
		FOR(i,12) {
			if(cnt[i]==2) V.push_back(i),V.push_back(24-i);
			if(cnt[i]==1) {
				if(mask&(1<<i)) V.push_back(i);
				else V.push_back(24-i);
			}
		}
		if(cnt[12]) V.push_back(12);
		
		sort(ALL(V));
		int dm=24;
		FOR(i,V.size()-1) dm=min(dm,V[i+1]-V[i]);
		ma=max(ma,dm);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
