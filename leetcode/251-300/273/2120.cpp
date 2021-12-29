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
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		vector<int> R;
		int i,j;
		FOR(i,s.size()) {
			int y=startPos[0];
			int x=startPos[1];
			for(j=i;j<s.size();j++) {
				if(s[j]=='R') x++;
				if(s[j]=='L') x--;
				if(x<0||x>=n) break;
				if(s[j]=='U') y--;
				if(s[j]=='D') y++;
				if(y<0||y>=n) break;
				
			}
			R.push_back(j-i);
		}
		return R;
        
    }
};
