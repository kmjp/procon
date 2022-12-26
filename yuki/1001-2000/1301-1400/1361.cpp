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

int A,B,C,D;
ll S;
ll V[4][1000];
ll Z[4];
vector<pair<ll,ll>> X[3],Y[3];

ll hoge(ll v,int a,int b) {
	ll ret=0;
	FORR(x,X[a]) {
		ll y=v/x.first;
		if(y*x.first<=v) y++;
		pair<ll,ll> s={y,-1LL<<60};
		int num=lower_bound(ALL(Y[b]),s)-Y[b].begin();
		ret+=num;
	}
	return ret;
}
vector<ll> hoge2(ll v,int a,int b) {
	ll ret=0;
	FORR(x,X[a]) if(v%x.first==0) {
		ll y=v/x.first;
		pair<ll,ll> s={y,-1LL<<60};
		int num=lower_bound(ALL(Y[b]),s)-Y[b].begin();
		
		if(num<Y[b].size()&&Y[b][num].first==y) {
			return {v,x.second/100000-50000,x.second%100000-50000,Y[b][num].second/100000-50000,Y[b][num].second%100000-50000};
		}
		
	}
	return {};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D>>S;
	FOR(i,A) {
		cin>>V[0][i];
		if(V[0][i]==0) Z[0]=i;
	}
	FOR(i,B) {
		cin>>V[1][i];
		if(V[1][i]==0) Z[1]=i;
	}
	FOR(i,C) {
		cin>>V[2][i];
		if(V[2][i]==0) Z[2]=i;
	}
	FOR(i,D) {
		cin>>V[3][i];
		if(V[3][i]==0) Z[3]=i;
	}
	int a,b,c,d;
	FOR(a,A) FOR(b,B) {
		ll c=V[0][a]*V[1][b];
		ll v=(V[0][a]+50000)*100000+V[1][b]+50000;
		if(c<0) X[0].push_back({-c,v});
		if(c==0) X[1].push_back({c,v});
		if(c>0) X[2].push_back({c,v});
	}
	FOR(a,C) FOR(b,D) {
		ll c=V[2][a]*V[3][b];
		ll v=(V[2][a]+50000)*100000+V[3][b]+50000;
		if(c<0) Y[0].push_back({-c,v});
		if(c==0) Y[1].push_back({c,v});
		if(c>0) Y[2].push_back({c,v});
	}
	FOR(i,3) sort(ALL(X[i])),sort(ALL(Y[i]));
	ll mi=X[0].size()*Y[2].size()+X[2].size()*Y[0].size();
	ll pl=X[0].size()*Y[0].size()+X[2].size()*Y[2].size();
	ll zero=1LL*A*B*C*D-mi-pl;
	if(S<=mi) {
		S=mi+1-S;
		
		ll ret=1LL<<60;
		for(i=59;i>=0;i--) if(hoge(ret-(1LL<<i),0,2)+hoge(ret-(1LL<<i),2,0)>=S) ret-=1LL<<i;
		vector<ll> A=hoge2(ret,0,2);
		if(A.empty()) A=hoge2(ret,2,0);
		
		cout<<-A[0]<<endl;
		cout<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[4]<<endl;
		
	}
	else if(S<=mi+zero) {
		cout<<0<<endl;
		cout<<V[0][Z[0]]<<" "<<V[1][Z[1]]<<" "<<V[2][Z[2]]<<" "<<V[3][Z[3]]<<endl;
	}
	else {
		S-=mi+zero;
		ll ret=1LL<<60;
		for(i=59;i>=0;i--) if(hoge(ret-(1LL<<i),0,0)+hoge(ret-(1LL<<i),2,2)>=S) ret-=1LL<<i;
		vector<ll> A=hoge2(ret,0,0);
		if(A.empty()) A=hoge2(ret,2,2);
		
		cout<<A[0]<<endl;
		cout<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[4]<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
