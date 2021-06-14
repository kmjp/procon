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



class Solution {
public:
	int N;
	string S;
	int cur;
	pair<int,int> dfs2() {
		if(S[cur]=='(') {
			cur++;
			pair<int,int> ret=dfs();
			cur++;
			return ret;
		}
		else {
			vector<pair<int,int>> P;
			string op;
			if(S[cur]=='0') {
				P.push_back({0,1});
			}
			else {
				P.push_back({1,0});
			}
			cur++;
			return P[0];
		}
	}
	pair<int,int> dfs() {
		vector<pair<int,int>> P;
		string op;
		P.push_back(dfs2());
		while(cur<N&&(S[cur]=='&'||S[cur]=='|')) {
			op+=S[cur];
			cur++;
			P.push_back(dfs2());
		}
		reverse(ALL(P));
		reverse(ALL(op));
		while(op.size()) {
			auto x=P.back();
			P.pop_back();
			auto y=P.back();
			P.pop_back();
			
			int n0,n1;
			if(op.back()=='|') {
				n0=min({x.first+y.first,x.first+1,y.first+1});
				n1=min(x.second,y.second);
			}
			else {
				n0=min(x.first,y.first);
				n1=min({x.second+y.second,x.second+1,y.second+1});
			}
			P.push_back({n0,n1});
			op.pop_back();
		}
		return P[0];
	}
	
    int minOperationsToFlip(string expression) {
		S=expression;
		N=S.size();
		cur=0;
		auto p=dfs();
		return max(p.first,p.second);
        
    }
};
