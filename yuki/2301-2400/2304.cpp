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
int A[202020];
multiset<int> L[202020],R[202020];

int getML(int a) {
	return *L[a].rbegin();
}
int getMR(int a) {
	if(L[a].size()==R[a].size()) return *R[a].begin();
	return *L[a].rbegin();
}

void add(int t,int a) {
	L[t].insert(a);
	int x=*L[t].rbegin();
	L[t].erase(L[t].find(x));
	R[t].insert(x);
	if(R[t].size()>L[t].size()) {
		x=*R[t].begin();
		L[t].insert(x);
		R[t].erase(R[t].find(x));
	}
}

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	vector<int> s;
	FOR(i,N) {
		add(i,A[i]-i);
		s.push_back(i);
		while(s.size()>=2) {
			x=s.back();
			s.pop_back();
			y=s.back();
			s.pop_back();
			if(getML(y)<getMR(x)) {
				s.push_back(y);
				s.push_back(x);
				break;
			}
			if(L[x].size()<L[y].size()) swap(x,y);
			FORR(a,L[y]) add(x,a);
			FORR(a,R[y]) add(x,a);
			s.push_back(x);
		}
	}
	ll ret=0;
	FORR(a,s) {
		ll b=getML(a);
		
		FORR(v,L[a]) ret+=abs(b-v);
		FORR(v,R[a]) ret+=abs(b-v);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
