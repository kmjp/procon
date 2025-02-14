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
int P[5050];
ll A[5050];
ll P2[10]={2,4,6,5,3,1};
ll A2[10]={1,9,2,25,2,9};

ll hoge(int a,int b) {
	if(a>b) swap(a,b);
	/*
	a=P2[a];
	b=P2[b];
	ll sum=0;
	for(int i=min(a,b);i<=max(a,b);i++) sum+=A2[i-1];
	return sum;
	*/
	
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	ll x;
	cin>>x;
	return x;
	
}


void solve() {
	int i,j,k,l,r,x,y; 
	
	cin>>N;
	ll s=hoge(0,1);
	int cur=1;
	for(i=2;i<N;i++) {
		ll v=hoge(0,i);
		if(v>s) {
			s=v;
			cur=i;
		}
	}
	vector<pair<ll,int>> V;
	FOR(i,N) if(i!=cur) V.push_back({hoge(i,cur),i});
	int rev=0;
	if(cur!=1) {
		ll s2=hoge(1,cur);
		if(s2>s) rev=1;
	}
	sort(ALL(V));
	ll pre=0;
	if(rev==0) P[cur]=N;
	else P[cur]=1;
	pre=A[P[cur]]=V.back().first-hoge(V.back().second,V[0].second);
	
	
	FOR(i,N-1) {
		x=V[i].second;
		ll v=V[i].first-pre;
		pre=V[i].first;
		if(rev==0) P[x]=N-1-i;
		else P[x]=i+2;
		A[P[x]]=v;
	}
	cout<<"!";
	FOR(i,N) cout<<" "<<P[i];
	FOR(i,N) cout<<" "<<A[i+1];
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
