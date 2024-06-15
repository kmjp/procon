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
string S;
int R[502020];
vector<int> add[502020];
ll dp[502020];

pair<vector<int>,pair<int,int> > manacher(string S) {
	int L=S.size(),i,j,k;
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && S[(i-j)/2]==S[(i+j+1)/2]) j++;
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k&&i+k<rad.size(); k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
	i=max_element(rad.begin(),rad.end())-rad.begin();
	return make_pair(rad,make_pair((i-(rad[i]-1))/2,(i+(rad[i]-1))/2));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		auto V=manacher(S).first;
		FOR(i,N+1) R[i]=1<<30, dp[i]=1,add[i].clear();
		for(i=1;i<V.size();i+=2) if(V[i]) {
			x=i/2+1-V[i]/2;
			add[x].push_back(V[i]+2*x);
		}
		ll ret=0;
		priority_queue<int, vector<int>, greater<int> > Q;
		FOR(i,N) {
			FORR(a,add[i]) Q.push(a);
			while(Q.size()&&Q.top()-2*i<=0) Q.pop();
			if(Q.size()) {
				x=Q.top()-2*i;
				ret+=dp[i];
				dp[i+x]+=dp[i];
			}
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
