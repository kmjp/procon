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

int N,X,Y;
string S,T;

string hoge(string A) {
	vector<pair<int,int>> V;
	FORR(a,A) {
		a-='0';
		if(V.empty()||V.back().first!=a) V.push_back({a,0});
		V.back().second++;
	}
	string R;
	vector<int> col={1};
	vector<int> num={0};
	int n1=0;
	int ind1=0;
	int i,j;
	FORR2(c,n,V) {
		if(c==0) {
			while(n>=X) {
				num[ind1]+=X;
				n-=X;
			}
			while(n--) {
				col.push_back(0);
				num.push_back(n1);
				n1=0;
			}
		}
		else {
			while(n>=Y) {
				n1+=Y;
				n-=Y;
			}
			while(n--) {
				ind1=col.size();
				col.push_back(1);
				num.push_back(0);
			}
		}
	}
	FOR(i,col.size()) {
		if(col[i]==0) {
			FOR(j,num[i]) R+='1';
			R+='0';
		}
		else {
			if(i) R+='1';
			FOR(j,num[i]) R+='0';
		}
	}
	FOR(i,n1) R+='1';
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>S>>T;
	string V=hoge(S);
	string W=hoge(T);
	
	if(V==W) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
