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
int H,W;
int A[1010][1010];
vector<int> R[4],C[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,4) {
			R[i].clear();
			C[i].clear();
		}
		cin>>H>>W;
		FOR(y,H) {
			cin>>s;
			k=0;
			FOR(x,W) {
				A[y][x]=s[x]-'0';
				k^=A[y][x];
			}
			R[k].push_back(y);
		}
		FOR(x,W) {
			k=0;
			FOR(y,H) k^=A[y][x];
			C[k].push_back(x);
		}
		int ret=0;
		for(i=1;i<=3;i++) while(R[i].size()&&C[i].size()) {
			ret++;
			A[R[i].back()][C[i].back()]^=i;
			R[i].pop_back();
			C[i].pop_back();
		}
		for(i=1;i<=3;i++) for(j=i+1;j<=3;j++) {
			k=i^j;
			while(R[i].size()&&R[j].size()&&C[k].size()) {
				ret+=2;
				A[R[i].back()][C[k].back()]^=i;
				A[R[j].back()][C[k].back()]^=j;
				R[i].pop_back();
				R[j].pop_back();
				C[k].pop_back();
			}
			while(C[i].size()&&C[j].size()&&R[k].size()) {
				ret+=2;
				A[R[k].back()][C[i].back()]^=i;
				A[R[k].back()][C[j].back()]^=j;
				R[k].pop_back();
				C[i].pop_back();
				C[j].pop_back();
			}
		}
		for(i=1;i<=3;i++) for(j=1;j<=3;j++) if(i!=j) {
			while(R[i].size()>=2&&C[j].size()>=2) {
				ret+=3;
				A[R[i].back()][C[j].back()]^=i;
				A[R[i][R[i].size()-2]][C[j][C[j].size()-2]]^=j;
				A[R[i][R[i].size()-2]][C[j].back()]^=i^j;
				R[i].pop_back();
				R[i].pop_back();
				C[j].pop_back();
				C[j].pop_back();
			}
		}
		for(i=1;i<=3;i++) {
			FORR(r,R[i]) A[r][0]^=i, ret++;
			FORR(c,C[i]) A[0][c]^=i, ret++;
		}
		cout<<ret<<endl;
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x];
			cout<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
