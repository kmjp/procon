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

int dp[50505][27*3];

int mcost[505050];
string memo[505050];
int N;
string S;

class Solution {
public:
	pair<int,string> hoge(int cur) {
		if(cur==N) return {0,""};
		if(mcost[cur]>=0) return {mcost[cur],memo[cur]};
		if(cur+3>N) return {1<<30,""};
		int mc=1<<30;
		string ret="",nexs;
		for(int len=3;len<=5;len++) if(cur+len<=N) {
			int i,j;
			int mca=1<<30;
			string cand="";
			FOR(i,26) {
				int sum=0;
				FOR(j,len) sum+=abs(i-(S[cur+j]-'a'));
				if(sum<mca) {
					mca=sum;
					cand=string(len,'a'+i);
				}
			}
			
			auto nex=hoge(cur+len);
			
			
			if(mca+nex.first<mc) {
				mc=mca+nex.first;
				ret=cand;
				nexs=cand+nex.second;
				nexs=nexs.substr(0,6);
			}
			if(mca+nex.first==mc) {
				string a1=cand+nex.second;
				a1=a1.substr(0,6);
				if(a1<nexs) {
					ret=cand;
					nexs=a1;
				}
			}
			
			
		}
		
		
		mcost[cur]=mc;
		memo[cur]=ret;
		return {mc,ret};
		
	}

    string minCostGoodCaption(string caption) {
		
		N=caption.size();
		S=caption;
		if(N<=2) return "";
        
        MINUS(mcost);
        
        string ret;
        int cur=0;
        while(cur<N) {
			auto a=hoge(cur);
			ret+=a.second;
			cur+=a.second.size();
		}
        
        return ret;
        
        
    }
};



