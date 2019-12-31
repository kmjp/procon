#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> A;

vector<pair<int,int>> hoge(vector<int> A) {
	if(A.size()==4) {
		return {{0,0},{1,0},{1,1},{0,1}};
	}
	int i,N=A.size(),j;
	
	FOR(i,N) {
		if(A[i]==1 && A[(i+1)%N]==0) break;
	}
	vector<int> B;
	B.push_back(A[(i+N-1)%N]);
	FOR(j,N-3) B.push_back(A[(i+2+j)%N]);
	vector<pair<int,int>> P=hoge(B),R;
	while(P[0].first>=P[1].first) {
		FORR(p,P) {
			swap(p.first,p.second);
			p.first=-p.first;
		}
	}
	
	FORR(p,P) p.first*=2,p.second*=2;
	P.insert(P.begin()+1,{P[0].first+1,P[0].second});
	P.insert(P.begin()+2,{P[0].first+1,P[0].second+1});
	P[3].second++;
	vector<int> Xs,Ys;
	FORR(p,P) {
		Xs.push_back(p.first);
		Ys.push_back(p.second);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	
	FOR(j,N) {
		int x=lower_bound(ALL(Xs),P[(j-(i-1)+N)%N].first)-Xs.begin();
		int y=lower_bound(ALL(Ys),P[(j-(i-1)+N)%N].second)-Ys.begin();
		R.push_back({x,y});
	}
	
	return R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int rot=0;
	FOR(i,N) {
		cin>>x;
		A.push_back(x==90);
		if(A[i]==1) rot++;
		else rot--;
	}
	if(rot!=4) return _P("-1\n");
	
	auto ret=hoge(A);
	FORR(r,ret) cout<<r.first<<" "<<r.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
