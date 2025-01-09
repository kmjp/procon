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

int T;
int N,A[202020];
vector<int> ret;

void hoge(vector<pair<int,int>>& V) {
	if(V.empty()) return;
	ret.push_back(V[0].second);
	
	assert(V.size()<=3);
	
	if(V.size()==3) {
		ll turn=V[1].first/V[0].first;
		ll dam=V[1].first*turn - 1LL*V[0].first*turn*(turn+1)/2;
		if(dam<V[2].first) ret.push_back(V[2].second);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(j,2001) {
			A[N]=A[0];
			FOR(i,N) if(A[i]) A[i+1]-=min(A[i+1],A[i]);
			A[0]=A[N];
		}

		int cur=0;
		while(1) {
			if(A[cur]==0) break;
			A[(cur+1)%N]-=min(A[cur],A[(cur+1)%N]);
			cur=(cur+1)%N;
		}
		ret.clear();
		vector<pair<int,int>> V;
		for(i=1;i<=N;i++) {
			if(A[(cur+i)%N]==0) {
				hoge(V);
				V.clear();
			}
			else {
				V.push_back({A[(cur+i)%N],(cur+i)%N});
			}
		}
		sort(ALL(ret));
		cout<<ret.size()<<endl;
		FORR(a,ret) cout<<a+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
