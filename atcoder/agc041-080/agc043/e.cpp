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

int N,L;
string A;
int ismin[256];


vector<pair<int,int>> construct(int mask) {
	vector<pair<int,int>> V;
	
	int i;
	FOR(i,N) if(mask&(1<<i)) {
		if(__builtin_popcount(mask)==1) {
			V.push_back({i,1});
			V.push_back({i+1,1});
			V.push_back({i+1,0});
			V.push_back({i,0});
		}
		else {
			vector<pair<int,int>> W=construct(mask^(1<<i));
			V.push_back({i,1});
			while(V.back().first+1<W[0].first) {
				V.push_back(V.back());
				V.back().first++;
			}
			FORR(w,W) V.push_back(w);
			V.push_back(W.back());
			V.back().second=1;
			while(V.back().first>i) {
				V.push_back(V.back());
				V.back().first--;
			}
			V.push_back({i,0});
			V.push_back({i+1,0});
			V.push_back({i+1,1});
			reverse(ALL(W));
			while(V.back().first<W[0].first) {
				V.push_back(V.back());
				V.back().first++;
			}
			
			FORR(w,W) V.push_back(w);
			while(V.back().first>i+1) {
				V.push_back(V.back());
				V.back().first--;
			}
			V.push_back({i+1,0});
			V.push_back({i,0});
		}
		break;
	}
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	L=1<<N;
	FORR(c,A) c-='0';
	FOR(x,L) FOR(y,L) if((x&y)==y && A[x] && A[y]==0) return _P("Impossible\n");
	FOR(x,L) ismin[x]=A[x]==0;
	FOR(x,L) if(A[x]==0) FOR(y,L) if((x&y)==y && y<x && A[y]==0) ismin[y]=0;
	
	vector<pair<int,int>> W;
	W.push_back({0,0});
	FOR(x,L) if(A[x]==0) {
		vector<pair<int,int>> V=construct(x);
		FOR(i,V[0].first) W.push_back({i,1});
		FORR(v,V) W.push_back(v);
		for(i=V[0].first;i>=0;i--) W.push_back({i,1});
		W.push_back({0,0});
	}
	cout<<"Possible"<<endl;
	cout<<W.size()-1<<endl;
	FORR(w,W) cout<<w.first<<" "<<w.second<<endl;
	/*
	FOR(i,W.size()-1) {
		cout<<i<<" "<<W[i].first<<" "<<W[i].second<<" "<<W[i+1].first<<" "<<W[i+1].second<<endl;
		assert(abs(W[i].first-W[i+1].first)+abs(W[i].second-W[i+1].second)==1);
	}
	*/
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
