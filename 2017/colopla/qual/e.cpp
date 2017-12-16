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

int K;

pair<vector<pair<int,int>>,vector<pair<int,int>>> hoge(int H,int W) {
	vector<pair<int,int>> A,B;
	K-=H*W-H-W+2;
	int x,y;
	for(x=W;x>0;x-=2) {
		A.push_back({x,H});
		A.push_back({x-1,H});
		A.push_back({x-1,0});
		A.push_back({x-2,0});
	}
	for(y=0;y<H;y+=2) {
		if(y) B.push_back({0,y});
		B.push_back({0,y+1});
		B.push_back({W,y+1});
		B.push_back({W,y+2});
	}
	return {A,B};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>K;
	K--;
	vector<pair<int,int>> V;
	int H=0,W=0;
	V.push_back({0,0});
	
	for(x=1500;x>=2;x-=2) {
		H=W=0;
		if(x*x-x-x+2<=K && x*x-x-x+2>0) {
			H=W=x;
		}
		else if(x*(x-2)-x-(x-2)+2<=K && x*(x-2)-x-(x-2)+2>0) {
			H=x,W=x-2;
		}
		if(H&&W) {
			auto P=hoge(H,W);
			vector<pair<int,int>> V2;
			int a=V[0].first,b=V[0].second;
			
			P.first.pop_back();
			FORR(e,P.first) V2.push_back({e.first+a,e.second+b});
			if(V.size()!=1) {
				V.erase(V.begin());
				V.pop_back();
			}
			FORR(v,V) V2.push_back(v);
			FORR(e,P.second) V2.push_back({e.first+a,e.second+b});
			
			swap(V,V2);
			
		}
	}
	
	
	while(K--) {
		x=V[0].first;
		y=V[0].second;
		
		vector<pair<int,int>> V2;
		V2.push_back({x+1,y+1});
		V2.push_back({x+1,y});
		if(V.size()!=1) {
			V.pop_back();
			V.erase(V.begin());
		}
		FORR(v,V) V2.push_back(v);
		V2.push_back({x,y+1});
		V2.push_back({x+1,y+1});
		swap(V,V2);
		reverse(ALL(V));
	}
	
	vector<pair<int,int>> R;
	R=V;
	R.pop_back();
	cout<<R.size()<<endl;
	FORR(v,R) cout<<v.first<<" "<<v.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
