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

int T;
int A,B,N,M;
set<pair<int,int>> Rs,Cs;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		int L=1,R,U=1,D;
		cin>>D>>R>>N>>M;
		Rs.clear();
		Cs.clear();
		FOR(i,N) {
			cin>>y>>x;
			Rs.insert({y,x});
			Cs.insert({x,y});
		}
		int ret[2]={};
		FOR(i,M) {
			cin>>s>>k;
			if(s=="U") {
				U+=k;
				while(Rs.size()&&Rs.begin()->first<U) {
					ret[i%2]++;
					Cs.erase({Rs.begin()->second,Rs.begin()->first});
					Rs.erase(Rs.begin());
				}
			}
			if(s=="D") {
				D-=k;
				while(Rs.size()&&Rs.rbegin()->first>D) {
					ret[i%2]++;
					Cs.erase({Rs.rbegin()->second,Rs.rbegin()->first});
					Rs.erase(*Rs.rbegin());
				}
			}
			if(s=="L") {
				L+=k;
				while(Cs.size()&&Cs.begin()->first<L) {
					ret[i%2]++;
					Rs.erase({Cs.begin()->second,Cs.begin()->first});
					Cs.erase(Cs.begin());
				}
			}
			if(s=="R") {
				R-=k;
				while(Cs.size()&&Cs.rbegin()->first>R) {
					ret[i%2]++;
					Rs.erase({Cs.rbegin()->second,Cs.rbegin()->first});
					Cs.erase(*Cs.rbegin());
				}
			}
			
		}
		cout<<ret[0]<<" "<<ret[1]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
