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
int L[101010],R[101010],A[101010];
int Q;
int X[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> ev;
	FOR(i,N) {
		cin>>L[i]>>R[i]>>A[i];
		if(A[i]>200000) continue;
		ev.push_back({L[i],i});
		ev.push_back({R[i],2000000+i});
	}
	set<int> alone;
	map<int,int> M;
	FOR(i,202020) alone.insert(i);
	
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i];
		ev.push_back({X[i],1000000+i});
	}
	
	sort(ALL(ev));
	FORR2(a,i,ev) {
		if(i<1000000) {
			alone.erase(A[i]);
			M[A[i]]++;
		}
		else if(i>=2000000) {
			i-=2000000;
			M[A[i]]--;
			if(M[A[i]]==0) alone.insert(A[i]);
		}
		else {
			cout<<*alone.begin()<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
