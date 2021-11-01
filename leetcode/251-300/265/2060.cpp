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

string A,B;
int memo[41][41][2020];
int ret=0;
class Solution {
public:
	void dfs(int a,int b,int dif) {
		if(memo[a][b][dif+1005]) return;
		memo[a][b][dif+1005]=1;
		if(a==A.size()&&b==B.size()) {
			if(dif==0) ret=1;
			return;
		}
		int i,j;
		
		if(dif==0) {
			if(a==A.size()) return;
			if(b==B.size()) return;
			
			if(isalpha(A[a])&&isalpha(B[b])) {
				if(A[a]==B[b]) dfs(a+1,b+1,0);
				return;
			}
			if(isalpha(A[a])) {
				for(i=1;i<=3;i++) {
					if(b+i>B.size()||isalpha(B[b+i-1])) break;
					int x=atoi(B.substr(b,i).c_str());
					dfs(a+1,b+i,-(x-1));
				}
			}
			else if(isalpha(B[b])) {
				for(i=1;i<=3;i++) {
					if(a+i>A.size()||isalpha(A[a+i-1])) break;
					int x=atoi(A.substr(a,i).c_str());
					dfs(a+i,b+1,x-1);
				}
			}
			else {
				for(i=1;i<=3;i++) {
					if(a+i>A.size()||isalpha(A[a+i-1])) break;
					for(j=1;j<=3;j++) {
						if(b+j>B.size()||isalpha(B[b+j-1])) break;
						int x=atoi(A.substr(a,i).c_str());
						int y=atoi(B.substr(b,j).c_str());
						dfs(a+i,b+j,x-y);
					}
				}
			}
		}
		if(dif>0) {
			if(b==B.size()) return;
			if(isalpha(B[b])) {
				dfs(a,b+1,dif-1);
			}
			else {
				for(i=1;i<=3;i++) {
					if(b+i>B.size()||isalpha(B[b+i-1])) break;
					int x=atoi(B.substr(b,i).c_str());
					dfs(a,b+i,dif-x);
				}
			}
		}
		if(dif<0) {
			if(a==A.size()) return;
			if(isalpha(A[a])) {
				dfs(a+1,b,dif+1);
			}
			else {
				for(i=1;i<=3;i++) {
					if(a+i>A.size()||isalpha(A[a+i-1])) break;
					int x=atoi(A.substr(a,i).c_str());
					dfs(a+i,b,dif+x);
				}
			}
		}
		
	}
    bool possiblyEquals(string s1, string s2) {
        ZERO(memo);
        A=s1;
        B=s2;
        ret=0;
        dfs(0,0,0);
        return ret;
        
    }
};
