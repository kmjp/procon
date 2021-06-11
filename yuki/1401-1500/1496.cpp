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
int P[202020],R[202020];
set<int> invalid;
ll S[202020];
ll A[202020];

ll hoge(int x) {
	auto it=invalid.lower_bound(x);
	int R=*it-1;
	int L=*prev(it)+1;
	int i,j;
	ll ret=0;
	if(x-L<R-x) {
		for(i=L;i<=x;i++) {
			if(S[x]-S[i-1]>A[x]) continue;
			int tar=x;
			for(j=20;j>=0;j--) if(tar+(1<<j)<=R&&S[tar+(1<<j)]-S[i-1]<=A[x]) tar+=1<<j;
			ret+=tar-x+1;
		}
	}
	else {
		for(i=x;i<=R;i++) {
			ll lef=A[x]-(S[i]-S[x-1]);
			if(S[i]-S[x-1]>A[x]) continue;
			int tar=x;
			for(j=20;j>=0;j--) if(tar-(1<<j)>=L&&S[i]-S[tar-(1<<j)-1]<=A[x]) tar-=1<<j;
			ret+=x-tar+1;
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		R[P[i]]=i;
		S[i]=S[i-1]+P[i];
	}
	for(i=1;i<=N;i++) cin>>A[R[i]];
	invalid.insert(0);
	invalid.insert(N+1);
	for(i=1;i<=N;i++) {
		x=R[i];
		cout<<hoge(x)<<endl;
		invalid.insert(x);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
