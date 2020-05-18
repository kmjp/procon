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


int N,M,Q;
int A[202020];
vector<pair<int,int>> T[202020];
vector<int> ev[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i];
		A[i]--;
		T[i].push_back({0,0});
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		T[x-1].push_back({i+1,0});
	}
	FOR(i,M) {
		int cur=A[i];
		if(i==0) {
			T[0][0].second=A[0];
			FOR(x,T[i].size()) if(x) {
				T[i][x].second=T[i][x-1].second;
				if(T[i][x].second>0) T[i][x].second--;
				else T[i][x].second++;
				if(T[i][x].second>=N) return _P("NO\n");
			}
		}
		else {
			x=0;
			y=0;
			T[i][0].second=A[i-1];
			while(x<T[i].size()-1||y<T[i-1].size()-1) {
				if(x<T[i].size()-1&&y<T[i-1].size()-1) {
					if(T[i][x+1].first<T[i-1][y+1].first) x++;
					else y++;
				}
				else if(x<T[i].size()-1) {
					x++;
					
				}
				else {
					y++;
				}
				T[i][x].second=max(T[i][x].second,T[i-1][y].second);
			}
			FOR(x,T[i].size()-1) T[i][x+1].second=max(T[i][x+1].second,T[i][x].second-1);
			for(x=T[i].size()-2;x>=0;x--) T[i][x].second=max(T[i][x].second,T[i][x+1].second-1);
			cur=A[i];
			FORR(t,T[i]) {
				if(t.first>0) {
					if(t.second<cur-1) cur--;
					else cur++;
				}
				if(cur<=t.second || cur>=N) return _P("NO\n");
				t.second=cur;
			}
		}
	}
	cout<<"YES"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
