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

int N,K;
int P[1010][1010];
vector<int> E[1010][1010];
pair<int,int> pat[2][1010];
int ret[1010];
int used[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		FOR(j,N) {
			cin>>P[i][j+1];
			if(P[i][j+1]) E[i][P[i][j+1]].push_back(j+1);
		}
	}
	
	set<int> S;
	if(K==0||K==N-1) {
		if(K==0) S.insert(N);
		else S.insert(1);
	}
	else {
		set<int> S1={1},S2={N};
		x=0;
		MINUS(pat);
		FOR(i,N-1) if(x==0) {
			if(i<K) {
				FORR(s,S2) if(P[i][s]&&S2.count(P[i][s])==0) {
					pat[0][P[i][s]]={i,s};
					S2.insert(P[i][s]);
					break;
				}
			}
			else {
				FORR(s,S1) if(P[i][s]&&S1.count(P[i][s])==0) {
					pat[1][P[i][s]]={i,s};
					S1.insert(P[i][s]);
					break;
				}
			}
			FORR(s,S1) if(S2.count(s)) x=s;
		}
		S.insert(x);
		FOR(i,2) {
			y=x;
			int tar=(i==0)?N:1;
			while(y!=tar) {
				j=pat[i][y].second;
				ret[j]=pat[i][y].first+1;
				used[pat[i][y].first]=1;
				y=j;
				S.insert(y);
			}
		}
	}
	FOR(i,N-1) if(used[i]==0) {
		FORR(s,S) FORR(e,E[i][s]) if(S.count(e)==0) {
			ret[e]=i+1;
			S.insert(e);
			goto out;
		}
		out:
		;
	}
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<ret[i+1]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
