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

int N,M,P,Q,R;

int hoge(int num,int v,deque<pair<int,int>> D) {
	int ret=0;
	FORR(r,D) {
		int n=min(num,r.second);
		num -= n;
		
		if(r.first<=v) ret += min(n,v-r.first+1);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	deque<pair<int,int>> V;
	cin>>N>>M>>P>>Q>>R;
	V.push_back({1,N});
	FOR(i,M) {
		cin>>x>>y;
		deque<pair<int,int>> A,B;
		y-=x;
		while(x) {
			if(V.front().second<=x) {
				A.push_back(V.front());
				x -= V.front().second;
				V.pop_front();
			}
			else {
				A.push_back({V.front().first,x});
				V.front().first += x;
				V.front().second -= x;
				x = 0;
			}
		}
		while(y) {
			if(V.front().second<=y) {
				B.push_back(V.front());
				y -= V.front().second;
				V.pop_front();
			}
			else {
				B.push_back({V.front().first,y});
				V.front().first += y;
				V.front().second -= y;
				y = 0;
			}
		}
		FORR(r,B) V.push_back(r);
		FORR(r,A) V.push_back(r);
	}
	
	cout<<hoge(Q,R,V)-hoge(P-1,R,V)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
