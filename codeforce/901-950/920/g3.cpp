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

int T,H,W,K;
vector<string> S;
vector<int> X[202020],Y[202020],D[202020];



vector<string> rotate(vector<string> S) {
	vector<string> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(string(H,' '));
	FOR(y,H) FOR(x,W) T[W-1-x][y]=S[y][x]; //left
	//FOR(y,H) FOR(x,W) T[x][y]=S[H-1-y][x]; //right
	return T;
}

int get(int y1,int x1,int y2,int x2) {
	if(y1==y2) {
		if(y1>=H) return 0;
		return X[y1+1][min(W,x2+1)]-X[y1+1][x1];
	}
	if(x1==x2) {
		if(y1>=H) return 0;
		return Y[min(H,y2+1)][x2+1]-Y[y1][x1+1];
	}
	assert(y1+x1==y2+x2);
	if(y1+x1>(H-1+W-1)) return 0;
	assert(y1>=y2);
	if(y1>=H) {
		int d=y1-(H-1);
		y1-=d;
		x1+=d;
	}
	if(x2>=W) {
		int d=x2-(W-1);
		x2-=d;
		y2+=d;
	}
	if(y2>=H) return 0;
	if(x1>=W) return 0;
	if(y1<y2) return 0;
	return D[y1+1][x1]-D[y2][x2+1];
	
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		K=min(K,H+W);
		S.resize(H);
		FOR(y,H) cin>>S[y];
		int ret=0;
		FOR(i,4) {
			S=rotate(S);
			swap(H,W);
			FOR(y,H+1) {
				X[y].clear();
				Y[y].clear();
				D[y].clear();
				X[y].resize(W+1);
				Y[y].resize(W+1);
				D[y].resize(W+1);
			}
			FOR(y,H) FOR(x,W) {
				X[y+1][x+1]=X[y+1][x]+(S[y][x]=='#');
				Y[y+1][x+1]=Y[y][x+1]+(S[y][x]=='#');
				D[y+1][x]=D[y][x+1]+(S[y][x]=='#');
			}
			int cur=0;
			FOR(y,K+1) cur+=get(y,0,y,K-y);
			ret=max(ret,cur);
			FOR(y,H) {
				int tcur=cur;
				FOR(x,W-1) {
					ret=max(ret,cur);
					cur-=get(y,x,y+K,x);
					cur+=get(y+K,x+1,y,x+K+1);
					ret=max(ret,cur);
				}
				cur=tcur;
				cur-=get(y,0,y,K);
				cur+=get(y+K+1,0,y+1,K);
				ret=max(ret,cur);
			}
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
