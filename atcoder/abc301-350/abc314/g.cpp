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

int N,M,H;
ll A[303030],B[303030];
ll Bsum[303030];

set<pair<ll,int>> X,Y;
int cur=0;
ll sum=0;

void add(int cur,int num) {
	int b=B[cur];
	if(X.count({Bsum[b],b})) {
		X.erase({Bsum[b],b});
		sum+=A[cur];
		Bsum[b]+=A[cur];
		X.insert({Bsum[b],b});
	}
	else {
		Y.erase({Bsum[b],b});
		Bsum[b]+=A[cur];
		Y.insert({Bsum[b],b});
	}
	
	if(X.size()&&Y.size()&&X.rbegin()->first>Y.begin()->first) {
		auto p=*Y.begin();
		auto q=*X.rbegin();
		sum-=q.first;
		sum+=p.first;
		Y.erase(p);
		X.erase(q);
		X.insert(p);
		Y.insert(q);
	}
}
void del(int cur,int num) {
	int b=B[cur];
	if(X.count({Bsum[b],b})) {
		X.erase({Bsum[b],b});
		Bsum[b]-=A[cur];
		sum-=A[cur];
		X.insert({Bsum[b],b});
	}
	else {
		Y.erase({Bsum[b],b});
		Bsum[b]-=A[cur];
		Y.insert({Bsum[b],b});
	}
	if(X.size()&&Y.size()&&X.rbegin()->first>Y.begin()->first) {
		auto p=*Y.begin();
		auto q=*X.rbegin();
		sum-=q.first;
		sum+=p.first;
		Y.erase(p);
		X.erase(q);
		X.insert(p);
		Y.insert(q);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>H;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		B[i]--;
	}
	
	FOR(i,M) X.insert({0,i});
	
	FOR(i,M+1) {
		if(i) {
			auto p=*X.rbegin();
			X.erase(p);
			sum-=p.first;
			Y.insert(p);
		}
		while(cur<N) {
			add(cur,i);
			if(sum>=H) {
				del(cur,i);
				break;
			}
			cur++;
		}
		cout<<cur<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
