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

int M,A;
string S;
vector<int> E;

vector<string> expression();
vector<string> term();
vector<string> factor();
vector<string> number();
int pos;

vector<string> expression() {
	vector<string> X=term();
	if(pos<E.size()&&E[pos]==10000+'$') {
		pos++;
		vector<string> Y=expression();
		vector<string> Z(M+1);
		
		int x,y;
		FOR(x,M+1) if(X[x].size()) FOR(y,M+1) if(Y[y].size()) {
			if(x+y<=M) {
				Z[x+y]=Y[y]+"+"+X[x];
			}
			if(y-x>=0) {
				Z[y-x]=Y[y]+"-"+X[x];
			}
		}
		return Z;
	}
	else {
		return X;
	}
	
}
vector<string> term() {
	vector<string> X=factor();
	if(pos<E.size()&&E[pos]==10000+'&') {
		pos++;
		vector<string> Y=term();
		vector<string> Z(M+1);
		
		int x,y;
		FOR(x,M+1) if(X[x].size()) FOR(y,M+1) if(Y[y].size()) {
			if(x*y<=M) {
				Z[x*y]=Y[y]+"*"+X[x];
			}
			if(x) Z[y/x]=Y[y]+"/"+X[x];
		}
		return Z;
	}
	else {
		return X;
	}
	
}
vector<string> factor() {
	
	
	if(E[pos]==10000+')') {
		pos++;
		vector<string> R=expression();
		FORR(r,R) if(r.size()) r='('+r+')';
		assert(E[pos]==10000+'(');
		pos++;
		return R;
	}
	else {
		return number();
	}
	
	
}
vector<string> number() {
	vector<string> R(M+1);
	R[E[pos]]=to_string(E[pos]);
	pos++;
	return R;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>A>>S;
	FORR(c,S) {
		if(c>='0'&&c<='9') {
			if(E.empty()||E.back()>=10000) E.push_back(0);
			E.back()=E.back()*10+c-'0';
			if(E.back()>M) {
				cout<<-1<<endl;
				return;
			}
		}
		else {
			E.push_back(10000+c);
		}
	}
	reverse(ALL(E));
	auto R=expression();
	if(R[A].empty()) cout<<-1<<endl;
	else cout<<R[A]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
