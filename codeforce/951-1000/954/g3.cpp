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

int T,N;
vector<int> cand[505050];
vector<int> A[505050];
vector<int> B[505050];
int sum[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=500000;i++) for(j=i;j<=500000;j+=i) cand[j].push_back(i);
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=0;
		for(i=1;i<=N;i++) {
			A[i].clear();
			B[i].clear();
		}
		for(i=1;i<=N;i++) {
			int p;
			cin>>p;
			int a=p/__gcd(p,i);
			int b=i/__gcd(p,i);
			B[b].push_back(a);
			if(a%b==0) ret--;
			A[a].push_back(b);
		}
		
		for(i=1;i<=N;i++) if(B[i].size()) {
			for(int a=i;a<=N;a+=i) FORR(v,A[a]) sum[v]++;
			FORR(a,B[i]) FORR(d,cand[a]) ret+=sum[d];
			for(int a=i;a<=N;a+=i) FORR(v,A[a]) sum[v]=0;
		}
		
		cout<<ret/2<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
