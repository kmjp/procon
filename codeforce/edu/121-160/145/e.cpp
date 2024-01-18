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

int N,A,B;
int V[10101];

int ret[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) cin>>V[i];
	for(i=0;i<=A+B;i++) {
		int f=100000;
		deque<int> Q;
		vector<pair<int,int>> cand;
		for(x=0;x<=A;x++) {
			y=i-x;
			if(y>=0&&y<=B) {
				cand.push_back({x,y});
				f=min(f,x);
				Q.push_back(1);
			}
		}
		if(Q.empty()) continue;
		int mi=max(0,i-B);
		int ma=min(A,i);
		FOR(j,N) {
			if(V[j]>0) {
				f-=V[j];
				while(f<mi&&Q.size()>1) {
					f++;
					x=Q[0];
					Q.pop_front();
					Q[0]+=x;
				}
				if(f<mi) f=mi;
			}
			else {
				f-=V[j];
				while(f+Q.size()-1>ma&&Q.size()>1) {
					x=Q.back();
					Q.pop_back();
					Q.back()+=x;
				}
				if(f+Q.size()-1>ma) f=ma-(Q.size()-1);
			}
		}
		reverse(ALL(cand));
		FOR(x,Q.size()) while(Q[x]) {
			ret[cand.back().first][cand.back().second]=f+x;
			Q[x]--;
			cand.pop_back();
		}
		assert(cand.empty());
	}
	
	FOR(y,A+1) {
		FOR(x,B+1) cout<<ret[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
