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
int N,Q;
vector<int> A[101010];
unordered_map<int,int> S[101010][18];
set<int> C[18];
int len[101010][18];

int X[101010],Y[101010];
int ret[101010];
map<int,int> cand;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) {
			cin>>x;
			A[i]={x};
			FOR(j,18) S[i][j].clear();
		}
		FOR(i,18) C[i].clear();
		
		FOR(i,Q) {
			cin>>X[i]>>Y[i];
			X[i]--;
			A[X[i]].push_back(min(102020,A[X[i]].back()+Y[i]));
		}
		cand.clear();
		cand[0]=1;
		
		FOR(j,18) {
			int cur=-1;
			FOR(i,N) {
				len[i][j]=0;
				if(A[i].back()<1<<j) {
					if(cur==-1) {
						cur=i;
						C[j].insert(i);
					}
					S[cur][j][A[i].back()]++;
					len[cur][j]++;
				}
				else {
					cur=-1;
				}
			}
			FORR(c,C[j]) if(S[c][j].size()==1<<j) cand[len[c][j]]++;
		}
		ret[Q-1]=cand.rbegin()->first;
		for(i=Q-2;i>=0;i--) {
			x=X[i+1];
			y=A[x].back();
			A[x].pop_back();
			FOR(j,18) {
				if(A[x].back()<(1<<j)&&y>=1<<j) {
					C[j].insert(x);
					S[x][j][A[x].back()]++;
					len[x][j]=1;
					if(S[x][j].size()==1<<j) cand[1<<j]++;
					
					if(x+1<N&&A[x+1].back()<1<<j) {
						assert(C[j].count(x+1));
						if(S[x][j].size()==1<<j) cand[1<<j]--;
						if(S[x+1][j].size()==1<<j) cand[len[x+1][j]]--;
						C[j].erase(x+1);
						swap(S[x][j],S[x+1][j]);
						len[x][j]+=len[x+1][j];
						S[x][j][A[x].back()]++;
						if(S[x][j].size()==1<<j) cand[len[x][j]]++;
					}
					auto it=C[j].find(x);
					if(it!=C[j].begin()) {
						k=*--it;
						if(k+len[k][j]==x) {
							if(S[x][j].size()==1<<j) cand[len[x][j]]--;
							if(S[k][j].size()==1<<j) cand[len[k][j]]--;
							len[k][j]+=len[x][j];
							C[j].erase(x);
							if(S[k][j].size()<S[x][j].size()) swap(S[k][j],S[x][j]);
							FORR2(a,b,S[x][j]) S[k][j][a]+=b;
							if(S[k][j].size()==1<<j) cand[len[k][j]]++;
						}
						
					}
					
				}
				else if(y<1<<j) {
					k=*--C[j].lower_bound(x+1);
					if(S[k][j].size()==1<<j) cand[len[k][j]]--;
					S[k][j][y]--;
					if(S[k][j][y]==0) S[k][j].erase(y);
					S[k][j][A[x].back()]++;
					if(S[k][j].size()==1<<j) cand[len[k][j]]++;
				}
			}
			while(cand.rbegin()->second==0) cand.erase(cand.rbegin()->first);
			ret[i]=cand.rbegin()->first;
		}
		FOR(i,Q) cout<<ret[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
