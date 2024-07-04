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

int te;
int N,T,Q;
string S[2];
set<int> same,dif;
set<pair<int,int>> block;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>te;
	while(te--) {
		same.clear();
		dif.clear();
		block.clear();
		
		cin>>S[0]>>S[1];
		N=S[0].size();
		FOR(i,N) {
			if(S[0][i]==S[1][i]) same.insert(i);
			else dif.insert(i);
		}
		cin>>T>>Q;
		for(i=1;i<=Q;i++) {
			while(block.size()&&block.begin()->first==i) {
				x=block.begin()->second;
				block.erase(block.begin());
				if(S[0][x]==S[1][x]) same.insert(x);
				else dif.insert(x);
				
			}
			
			cin>>x;
			if(x==1) {
				cin>>x;
				x--;
				same.erase(x);
				dif.erase(x);
				block.insert({i+T,x});
			}
			else if(x==2) {
				int a1,p1,a2,p2;
				cin>>a1>>p1>>a2>>p2;
				a1--,p1--,a2--,p2--;
				same.erase(p1);
				same.erase(p2);
				dif.erase(p1);
				dif.erase(p2);
				swap(S[a1][p1],S[a2][p2]);
				if(S[0][p1]==S[1][p1]) same.insert(p1);
				else dif.insert(p1);
				if(S[0][p2]==S[1][p2]) same.insert(p2);
				else dif.insert(p2);
				
			}
			else {
				if(dif.empty()) {
					cout<<"YES"<<endl;
				}
				else {
					cout<<"NO"<<endl;
				}
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
