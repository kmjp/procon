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

int N,Q;
int X[1010101];
int same[1010101];
ll S;
int L,R;

ll dp[101];
int num[1010101];
ll hoge(int k,vector<int>& V) {
	int i;
	int B=V.size();
	dp[0]=1;
	ll sum=1;
	int cnum=0;
	int cur=1,pre=0;
	FORR(v,V) num[v]=0;
	for(;cur<=B;cur++) {
		if(num[V[cur-1]]++==0) cnum++;
		while(cnum>k) {
			sum-=dp[pre];
			if(--num[V[pre]]==0) cnum--;
			pre++;
		}
		dp[cur]=sum;
		if(sum>1LL<<60) return sum;
		sum+=dp[cur];
	}
	return dp[B];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i];
		if(i) same[i]=same[i-1]+(X[i]==X[i-1]);
	}
	cin>>Q;
	while(Q--) {
		cin>>L>>R>>S;
		L--;
		if(R-L>=100) {
			int cand=same[R-1]-same[L];
			if(cand>=61||S<(1LL<<cand)) {
				cout<<0<<endl;
			}
			else {
				cout<<1<<endl;
			}
			continue;
		}
		vector<int> V;
		for(i=L;i<R;i++) V.push_back(X[i]);
		int TL=0,TR=V.size()+2;
		while(TL+1<TR) {
			int TM=(TL+TR)/2;
			ll ret=hoge(TM,V);
			if(ret<=S) {
				TL=TM;
			}
			else {
				TR=TM;
			}
		}
		if(TL>V.size()) {
			cout<<-1<<endl;
		}
		else {
			cout<<TL<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
