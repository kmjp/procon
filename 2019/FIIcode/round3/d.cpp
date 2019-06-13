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

int N,X;
int D[101010];
vector<pair<int,int>> E;
vector<int> A,C;
vector<pair<int,int>> B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>D[i];
		if(D[i]==1) {
			A.push_back(i);
		}
		else {
			B.push_back({D[i],i});
		}
	}
	sort(ALL(B));
	
	if(N==2) {
		cout<<"1 2"<<endl;
		return;
	}
	
	queue<vector<int>> Q;
	y=B.back().second;
	B.pop_back();
	Q.push({(X+1)/2-1,1,y});
	Q.push({X/2-1,1,y});
	FOR(i,D[y]-2) Q.push({X/2-1,0,y});
	X-=2;
	
	while(Q.size()) {
		auto a=Q.front();
		Q.pop();
		
		if(a[0]>0 && (a[1]||B.size()>X)) {
			y=B.back().second;
			B.pop_back();
			E.push_back({y,a[2]});
			D[a[2]]--;
			D[y]--;
			X-=a[1];
			FOR(i,D[y]) Q.push({a[0]-1,a[1]&&(i==0),y});
		}
		else {
			x=A.back();
			A.pop_back();
			D[a[2]]--;
			D[x]--;
			E.push_back({a[2],x});
		}
	}
	
	FORR(e,E) cout<<e.first+1<<" "<<e.second+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
