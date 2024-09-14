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

int N,Q;
ll X[202020];
ll S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<pair<int,int>> S;
	S={{-1,-(1<<30)},{N,1<<30}};
	FOR(i,N) {
		cin>>X[i];
		X[i]-=i;
		S.insert({i,X[i]});
	}
	ll ret=0;
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		x--;
		y-=x;
		
		
		auto it=prev(S.lower_bound({x+1,-(1<<30)}));
		int pos=it->second;
		if(pos<y) {
			if(it->first!=x) {
				it=S.insert({x,pos}).first;
			}
			while(next(it)->second<=y) {
				auto ne=*next(it);
				S.erase(next(it));
				S.erase({x,pos});
				ret+=1LL*(ne.second-pos)*(ne.first-x);
				pos=ne.second;
				it=S.insert({x,pos}).first;
			}
			if(pos<y) {
				auto ne=*next(it);
				ret+=1LL*(y-pos)*(ne.first-x);
				S.erase({x,pos});
				pos=y;
				it=S.insert({x,pos}).first;
			}
			
			
		}
		else if(y<pos) {
			if(next(it)->first!=x+1) {
				S.insert({x+1,pos});
			}
			it=prev(S.lower_bound({x+1,-(1<<30)}));
			k=it->first;
			while(y<=prev(it)->second) {
				auto pr=*prev(it);
				S.erase(prev(it));
				S.erase({k,pos});
				ret+=1LL*(pos-pr.second)*(x-k+1);
				k=pr.first;
				pos=pr.second;
				it=S.insert({k,pos}).first;
			}
			if(y<pos) {
				ret+=1LL*(pos-y)*(x-k+1);
				S.erase({k,pos});
				pos=y;
				it=S.insert({k,pos}).first;
			}
			
		}
		
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
