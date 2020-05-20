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



vector<string> V[101010];

class Solution {
public:
    string arrangeWords(string text) {
		int i;
		FOR(i,101010) V[i].clear();
		text+=" ";
		string cur;
		FORR(c,text) {
			if(c==' ') {
				V[cur.size()].push_back(cur);
				cur="";
			}
			else {
				cur+=c;
			}
		}
		
		string R;
		FOR(i,101005) FORR(v,V[i]) {
			if(v[0]>='A' && v[0]<='Z') v[0]+='a'-'A';
			if(R.empty()) {
				if(v[0]>='a' && R[0]<='z') v[0]+='A'-'a';
				R=v;
			}
			else {
				R+=" "+v;
			}
		}
		return R;
        
    }
};
