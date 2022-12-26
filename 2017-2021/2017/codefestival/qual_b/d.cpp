#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S;
int from[4];
int to[4];

ll hoge(string S) {
	vector<int> V;
	V.push_back(0);
	FORR(c,S) {
		if(c=='0') V.push_back(0);
		else V.back()++;
	}
	
	ZERO(from);
	for(int i=1;i<V.size();i++) {
		
		// 0-none 1-left 2-right 3-keep
		if(V[i]==1) {
			to[0]=max({from[0],from[1]+V[i-1]-1,from[2]+1,from[3]+V[i-1]});
			to[1]=max({from[0],from[1]+V[i-1]-1,from[3]+V[i-1]});
			to[2]=max({from[0],from[1],         from[2],from[3]});
		}
		else {
			to[0]=max({from[0],from[1]+V[i-1]-1,from[2]+V[i]});
			to[1]=max({from[0],from[1]+V[i-1]-1,from[3]+V[i-1]});
			to[2]=max({from[0],from[1]+V[i-1]-1,from[2]+V[i]-1,from[3]+V[i-1]});
		}
		to[3]=max({from[0],from[1],from[2],from[3]});
		
		
		swap(from,to);
	}
	int ret=max({from[0],from[1],from[2],from[3]});
	//cout<<S<<" "<<ret<<endl;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	N+=2;
	S+="00";
	ll ret=0;
	FOR(i,N) {
		if(S[i]=='0') continue;
		for(j=i+1;j<N;j++) {
			if(S[j]=='0' && S[j+1]=='0') {
				ret+=hoge(S.substr(i,j-i));
				i=j+1;
				break;
			}
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
