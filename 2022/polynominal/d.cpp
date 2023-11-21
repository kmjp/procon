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


int T,H,W;
vector<int> A[101010];
int C[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int num=0;
		FOR(y,H) {
			A[y].resize(W);
			C[y]=0;
			FOR(x,W) {
				cin>>A[y][x];
				num+=A[y][x];
				C[y]+=A[y][x];
			}
		}
		if(num%H) {
			cout<<"-1"<<endl;
			continue;
		}
		num/=H;
		vector<pair<pair<int,int>,int>> cand;
		FOR(x,W) {
			vector<int> O,I;
			FOR(y,H) {
				if(C[y]>num&&A[y][x]) O.push_back(y);
				if(C[y]<num&&A[y][x]==0) I.push_back(y);
			}
			while(O.size()&&I.size()) {
				i=O.back();
				j=I.back();
				O.pop_back();
				I.pop_back();
				swap(A[i][x],A[j][x]);
				C[i]--;
				C[j]++;
				cand.push_back({{i,j},x});
			}
		}
		FOR(y,H) assert(C[y]==num);
		
		
		
		cout<<cand.size()<<endl;
		FORR2(a,b,cand) {
			cout<<a.first+1<<" "<<a.second+1<<" "<<b+1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
