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
    string findLexSmallestString(string s, int a, int b) {
		set<string> S;
		queue<string> Q;
		S.insert(s);
		Q.push(s);
		int i,N=s.size();
		while(Q.size()) {
			s=Q.front();
			Q.pop();
			//rot
			string t;
			FOR(i,N) t+=s[(i+N-b)%N];
			if(S.count(t)==0) {
				S.insert(t);
				Q.push(t);
			}
			
			FOR(i,N) if(i%2==1) {
				s[i]+=a;
				if(s[i]>'9') s[i]-=10;
			}
			if(S.count(s)==0) {
				S.insert(s);
				Q.push(s);
			}
			
			
		}
		
		return *S.begin();
        
    }
};

