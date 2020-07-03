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

string A,B;
vector<pair<char,int>> X,Y;
int N,M;
int memo[4040][4040];

vector<pair<char,int>> conv(string S) {
	vector<pair<char,int>> R;
	int i=0;
	while(i<S.size()) {
		if(i+1<S.size()&&S[i+1]=='?') {
			R.push_back({S[i],0});
			i+=2;
		}
		else if(i+1<S.size()&&S[i+1]=='*') {
			R.push_back({S[i],2});
			i+=2;
		}
		else {
			R.push_back({S[i],1});
			i++;
		}
	}
	//FORR(r,R) cout<<(char)r.first<<r.second<<" ";
	//cout<<endl;
	return R;
}

int hoge(int x,int y) {
	if(memo[x][y]>=0) return memo[x][y];
	if(x==N&&y==M) return 0;
	int ret=1<<30;
	
	if(x==N) {
		ret=(Y[y].second==1)+hoge(x,y+1);
	}
	else if(y==M) {
		ret=(X[x].second==1)+hoge(x+1,y);
	}
	else {
		ret=min(ret,1+hoge(x+1,y+1));
		ret=min(ret,1+hoge(x+1,y));
		ret=min(ret,1+hoge(x,y+1));
		if(X[x].second==0||X[x].second==2) ret=min(ret,hoge(x+1,y));
		if(Y[y].second==0||Y[y].second==2) ret=min(ret,hoge(x,y+1));
		
		if(X[x].first==Y[y].first) {
			ret=min(ret,hoge(x+1,y+1));
			if(Y[y].second==2) ret=min(ret,hoge(x+1,y));
			if(X[x].second==2) ret=min(ret,hoge(x,y+1));
		}
		
		
	}
	//cout<<x<<y<<" "<<ret<<endl;
	return memo[x][y]=ret;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	X=conv(A);
	Y=conv(B);
	N=X.size();
	M=Y.size();
	
	MINUS(memo);
	cout<<hoge(0,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
