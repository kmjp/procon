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

string S;
int cur;


class Solution {
public:
	bool eval() {
		if(S[cur]=='f') {
			cur++;
			return false;
		}
		else if(S[cur]=='t') {
			cur++;
			return true;
		}
		else if(S[cur]=='!') {
			cur+=2;
			bool ret=eval();
			cur++;
			return !ret;
		}
		else if(S[cur]=='&') {
			cur+=2;
			bool ret=eval();
			while(S[cur]==',') {
				cur++;
				ret=ret&eval();
			}
			cur++;
			return ret;
		}
		else {
			cur+=2;
			bool ret=eval();
			while(S[cur]==',') {
				cur++;
				ret=ret|eval();
			}
			cur++;
			return ret;
		}
		
	}
    bool parseBoolExpr(string expression) {
        S=expression;
        cur=0;
        return eval();
    }
};
