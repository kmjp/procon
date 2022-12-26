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

int N;
string K;
int C[10];

int num[505050][10];
int up[505050];
string incinc(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r=='9') r='0';
		else {
			r++;
			break;
		}
	}
	if(A.back()=='0') A += '1';
	reverse(A.begin(),A.end());
	return A;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	
	
	FOR(i,9) cin>>C[i+1];
	FOR(i,N) {
		FOR(j,10) num[i+1][j]=num[i][j];
		num[i+1][K[i]-'0']++;
	}

	if(K.size()>N) {
		cout<<-1<<endl;
		return;
	}
	if(K.size()<N) {
		string R;
		FOR(x,10) R+=string(C[x],'0'+x);
		cout<<R<<endl;
		return;
	}
	
	string R;
	for(i=N-1;i>=0;i--) {
		for(j=K[i]-'0'+1;j<=9;j++) {
			int ok=1;
			FOR(x,10) {
				if(x==j) {
					if(num[i][x]+1>C[x]) ok=0;
				}
				else {
					if(num[i][x]>C[x]) ok=0;
				}
			}
			if(ok==0) continue;
			
			R=K.substr(0,i);
			R+='0'+j;
			FORR(c,R) C[c-'0']--;
			FOR(x,10) R+=string(C[x],'0'+x);
			break;
			
		}
		if(R.size()) break;
	}
	
	if(R.empty()) cout<<-1<<endl;
	else cout<<R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
