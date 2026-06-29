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

int N,K;
int L[202020],R[202020];
vector<pair<int,int>> V;
int ok(int v) {
	int i;
	ll cur=-1LL<<31;
	int num=0;
	int pos=0;
	while(1) {
		while(pos<N&&V[pos].second<cur+v) pos++;
		if(pos==N) break;
		cur=V[pos].first;
		num++;
		
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
		
	cin>>N>>K;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		V.push_back({R[i],L[i]});
	}
	sort(ALL(V));
		
	if(ok(1)<K) {
		cout<<-1<<endl;
		return;
	}
	int ret=1;
	for(i=30;i>=0;i--) if(ok(ret+(1<<i))>=K) ret+=1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
