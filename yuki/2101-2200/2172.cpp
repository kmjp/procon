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


int N,L;
string T,S[101010];
ll nex[101010][55];
ll num[101010][55];

int stt[1024][257];
const ll mo=998244353;
const char base='\0';
void CreateSTT(string& pat) {
	int x,y,z,l;
	ZERO(stt);
	l=pat.size();
	FOR(x,l+1) {
		FOR(y,256) {
			string pre=pat.substr(0,x)+(char)(base+y);
			for(z=1;z<=min(pat.size(),pre.size());z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[x][y]=z;
		}
		if(x!=l) stt[x][y]=x+1;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	L=T.size();
	CreateSTT(T);
	
	FOR(i,N) {
		cin>>s;
		if(s=="~") {
			cin>>x>>y;
			x--,y--;
			FOR(j,L+1) {
				nex[i][j]=nex[y][nex[x][j]];
				num[i][j]=(num[x][j]+num[y][nex[x][j]])%mo;
			}
		}
		else {
			FOR(j,L+1) {
				nex[i][j]=j;
				FORR(c,s) {
					nex[i][j]=stt[nex[i][j]][c];
					if(nex[i][j]==L) num[i][j]++;
				}
			}
		}
	}
	
	cout<<num[N-1][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
