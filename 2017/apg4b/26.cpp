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
string S[100];
int cur;
map<string,int> I;
map<string,vector<int>> V;


int int_term() {
	int v;
	if(S[cur][0]>='1'&&S[cur][0]<='9') {
		v=S[cur][0]-'0';
	}
	else v=I[S[cur]];
	cur++;
	
	return v;
}

int int_expression() {
	int v=int_term();
	
	while(S[cur]=="+"||S[cur]=="-") {
		if(S[cur]=="+") {
			cur++;
			v+=int_term();
		}
		else {
			cur++;
			v-=int_term();
		}
	}
	return v;
}

vector<int> vec_term() {
	vector<int> R;
	
	if(S[cur]=="[") {
		cur++;
		while(1) {
			R.push_back(int_expression());
			if(S[cur]=="]") break;
			cur++;
		}
		cur++;
	}
	else {
		R=V[S[cur]];
		cur++;
	}
	return R;
}

vector<int> vec_expression() {
	vector<int> R=vec_term();
	int i;
	
	while(S[cur]=="+"||S[cur]=="-") {
		string op=S[cur];
		cur++;
		vector<int> R2=vec_term();
		FOR(i,R.size()) {
			if(op=="+") {
				R[i]+=R2[i];
			}
			else {
				R[i]-=R2[i];
			}
		}
	}
	
	return R;
	
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		FOR(L,100) {
			cin>>S[L];
			if(S[L]==";") break;
		}
		
		if(S[0]=="int") {
			cur=3;
			I[S[1]]=int_expression();
		}
		if(S[0]=="vec") {
			cur=3;
			V[S[1]]=vec_expression();
		}
		if(S[0]=="print_int") {
			cur=1;
			x=int_expression();
			cout<<x<<endl;
		}
		if(S[0]=="print_vec") {
			cur=1;
			auto vec=vec_expression();
			cout << "[ ";
			for (int i = 0; i < vec.size(); i++) {
				cout << vec.at(i) << " ";
			}
			cout << "]" << endl;
		}
		assert(cur==L);
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
