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

int N,M;
int E[20];

int dp[1<<20][20];
int to[20];

void hoge(int mask,int from,int to,vector<int>& ret) {
	ret.push_back(to);
	if(from==to) return;
	int i;
	FOR(i,N) if((mask&(1<<i))&&(dp[mask^(1<<to)][from]&(1<<i))&&E[i]&(1<<to)) {
		hoge(mask^(1<<to),from,i,ret);
		return;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x]|=1<<y;
		E[y]|=1<<x;
	}
	FOR(i,N) if(E[i]==(1<<N)-1) {
		cout<<"Yes"<<endl;
		FOR(j,N) {
			if(i!=j) cout<<i+1<<" ";
			else cout<<(j?(j-1):j+1)<<" ";
		}
		cout<<endl;
		return;
	}
	FOR(i,N) dp[1<<i][i]=1<<i;
	int mask;
	int ok=0;
	FOR(mask,1<<20) {
		int e=0;
		FOR(i,N) if(mask&(1<<i)) e|=E[i];
		if(e==(1<<N)-1) {
			FOR(i,N) {
				FOR(j,N) if((dp[mask][i]&(1<<j))&&E[j]&(1<<i)) {
					vector<int> ret;
					hoge(mask,i,j,ret);
					reverse(ALL(ret));
					FOR(i,ret.size()) to[ret[i]]=ret[(i+1)%ret.size()]+1;
					FOR(i,N) if(to[i]==0) {
						FOR(j,N) if(to[j]&&E[i]&(1<<j)) {
							to[i]=j+1;
							break;
						}
					}
					cout<<"Yes"<<endl;
					FOR(i,N) cout<<to[i]<<" ";
					cout<<endl;
					return;
					
				}
			}
		}
		
		FOR(i,N) FOR(j,N) if(dp[mask][i]&(1<<j)) {
			FOR(k,N) if((mask&(1<<k))==0&&E[j]&(1<<k)) {
				dp[mask|(1<<k)][i]|=1<<k;
			}
		}
		
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
