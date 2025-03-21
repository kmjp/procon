#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int C[202020],L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>s>>L[i]>>R[i];
		C[i]=s==")";
	}
	int ng=0;
	multiset<int> cand;
	int cnt[2]={};
	ll sum=0;
	for(i=2*N-1;i>=0;i--) {
		cnt[C[i]]++;
		if(C[i]==0) {
			sum+=L[i];
			cand.insert(R[i]-L[i]);
		}
		else {
			sum+=R[i];
			cand.insert(L[i]-R[i]);
		}
		while(cand.size()>min(cnt[0],cnt[1])) cand.erase(cand.begin());
	}
	FORR(c,cand) if(c>=0) sum+=c;
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
