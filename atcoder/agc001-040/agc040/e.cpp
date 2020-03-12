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
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<vector<int>> V;
	V.push_back({0,1,0});
	for(i=1;i<=N+1;i++) {
		if(i!=N+1) cin>>A[i];
		vector<vector<int>> W;
		
		if(A[i]==A[i-1]) {
			continue;
		}
		if(A[i]>A[i-1]) {
			int D=A[i]-A[i-1];
			FORR(v,V) {
				W.push_back({0,v[0],v[2]+2});
				W.push_back({v[0],v[0]+D,v[2]+1});
				W.push_back({v[0]+D,A[i]+1,v[2]});
			}
		}
		else {
			int D=A[i-1]-A[i];
			FORR(v,V) {
				W.push_back({0,min(max(v[0]-D,0),A[i]+1),v[2]+2});
				W.push_back({min(max(v[0]-D,0),A[i]+1),min(v[0],A[i]+1),v[2]+1});
				W.push_back({min(v[0],A[i]+1),A[i]+1,v[2]});
			}
		}
		
		sort(ALL(W));
		V.clear();
		FORR(w,W) {
			if(w[0]==w[1]) continue;
			while(V.size() && V.back()[2]>=w[2]) {
				if(V.back()[0]>=w[0]) {
					V.pop_back();
				}
				else {
					V.back()[1]=w[0];
					break;
				}
			}
			if(V.size()&&V.back()[2]<=w[2]) continue;
			V.push_back(w);
		}
	}
	
	cout<<V[0][2]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
