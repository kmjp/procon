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

int H,W;
multiset<int> M;
set<pair<int,int>> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(x,W) {
		S.insert({x,x});
		M.insert(0);
	}
	S.insert({-1,-2000000});
	M.insert(20202020);
	S.insert({W,W});
	
	FOR(y,H) {
		int A,B;
		cin>>A>>B;
		A--,B--;
		while(1) {
			auto it=S.lower_bound({A,0});
			if(it->first>B) break;
			if(next(it)->first<=B+1) {
				M.erase(M.find(it->first-it->second));
				S.erase(it);
			}
			else {
				x=it->second;
				M.erase(M.find(it->first-it->second));
				S.erase(it);
				S.insert({B+1,x});
				M.insert({B+1-x});
			}
		}
		x=*M.begin()+y+1;
		if(x>=H+W) x=-1;
		cout<<x<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
