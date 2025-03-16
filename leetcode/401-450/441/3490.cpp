#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

vector<string> V;
int p10[10];
int fact[10];

class Solution {
public:

	void dfs(string& S,int nex,int sum,int mul) {
		if(mul%sum==0) {
			V.push_back(S);
		}
		if(S.size()<9) {
			for(int i=nex;i<=9;i++) {
				S+='0'+i;
				dfs(S,i,sum+i,mul*i);
				S.pop_back();
			}
		}
	}
	
	int have0(int v) {
		int from[2][2][2]={};
		from[0][0][0]=1;
		int i;
		for(int d=9;d>=0;d--) {
			int to[2][2][2]={};
			int t=v/p10[d]%10;
			int le,po,h0;
			FOR(le,2) FOR(po,2) FOR(h0,2) {
				FOR(i,10) {
					if(le==0&&i>t) continue;
					
					to[le|(i<t)][po|(i>0)][h0|((i==0)&&po)]+=from[le][po][h0];
					
				}
			}
			swap(to,from);
		}
		int ret=from[0][1][1]+from[1][1][1];
		return ret;
	}
	int pat(vector<int> P) {
		int num=0;
		FORR(p,P) num+=p;
		int ret=fact[num];
		FORR(p,P) ret/=fact[p];
		return ret;
	}
	
	int hoge(string a,string b) {
		vector<int> V(10);
		FORR(c,a) V[c-'0']++;
		int N=a.size();
		int ret=0,i,d;
		FOR(d,N) {
			int c=b[d]-'0';
			FOR(i,c) {
				if(V[i]) {
					V[i]--;
					ret+=pat(V);
					V[i]++;
				}
			}
			if(V[c]==0) return ret;
			V[c]--;
		}
		ret++;
		return ret;
	}
	
	
    int beautifulNumbers(int l, int r) {
        
        V.clear();
        string S;
        int i;
		p10[0]=1;
		fact[0]=1;
        for(i=1;i<=9;i++) {
			fact[i]=fact[i-1]*i;
			p10[i]=p10[i-1]*10;
			S+='0'+i;
			dfs(S,i,i,i);
			S.pop_back();
		}
		
		int sum=0;
		string L=to_string(l);
		string R=to_string(r);
		FORR(v,V) {
			if(v.size()<L.size()) continue;
			if(v.size()>R.size()) continue;
			string a=v;
			string TL=to_string(l-1);
			string TR=R;
			if(TL.size()<a.size()) TL=string(a.size(),'0');
			if(TR.size()>a.size()) TR=string(a.size(),'9');
			sum+=hoge(a,TR)-hoge(a,TL);
			
		}
		sum+=have0(r)-have0(l-1);
		
		return sum;
    }
};


