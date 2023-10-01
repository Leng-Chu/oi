#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
#define STR_SIZE 10000
#define EVAL_OUTPUT_FILE "./_eval.score"

FILE *fpin, *fpout, *fpans, *fprlt;
/* Output message and exit */
void output(char *s, int d)
{
	if (fprlt) {
		fprintf (fprlt, "%s\n%d\n", s, d);
		fclose(fprlt);
	}
	exit(d != 0);
}

/* Open files and check */
void open_files(char *in, char *out, char *ans, char *eval_output)
{
	if ((fprlt = fopen (eval_output, "w")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", EVAL_OUTPUT_FILE);
		output ("Can not open eval record file!", 0);
	}

	if ((fpin = fopen (in, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", out);
		output ("Can not open input file!", 0);
	}

	if ((fpout = fopen (out, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", out);
		output ("Can not open player's output file!", 0);
	}

	if ((fpans = fopen (ans, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", ans);
		output ("Can not open standard answer!", 0);
	}
}

int a[2222222];
std::deque<int> q[333];

int specialJudge(FILE *in, FILE *out, FILE *ans){
// TODO: write your special judge here
	int T;
	fscanf(in, "%d", &T);
	while(T--){
		int n,m,k;
		fscanf(in, "%d%d%d", &n,&m,&k);
		for(int i=1;i<=m;++i){
			fscanf(in, "%d", a+i);
		}
		int now=1;
		int op;
		if(fscanf(out, "%d", &op)!=1){
			return 0;
		}
		if(op<m||op>2*m){
			return 0;
		}
		for(int i=1;i<=op;++i){
			int v,s1,s2;
			if(fscanf(out, "%d", &v)!=1){
				return 0;
			}
			if(v==1){
				if(fscanf(out, "%d", &s1)!=1){
					return 0;
				}
				if(s1<=0||s1>n){
					return 0;
				}
				if(now<=m){
					if(!q[s1].empty()&&a[now]==q[s1].back()){
						q[s1].pop_back();
					}
					else{
						q[s1].push_back(a[now]);
					}
					++now;
				}
			}
			else if(v==2){
				if(fscanf(out, "%d%d", &s1, &s2)!=2){
					return 0;
				}
				if(s1<=0||s1>n||s2<=0||s2>n||s1==s2){
					return 0;
				}
				if(!q[s1].empty()&&!q[s2].empty()&&q[s1].front()==q[s2].front()){
					q[s1].pop_front();
					q[s2].pop_front();
				}
			}
			else return 0;
		}
		if(now<=m){
			return 0;
		}
		for(int i=1;i<=n;++i){
			if(q[i].size()){
				return 0;
			}
		}
	}
	return 1;
}

int main (int argc, char *argv[])
{
	if (argc != 4) {
		fprintf (stderr, "Usage: mason_e <in> <out> <ans>\n");
		output ("Invalid Call!", 0);
	}

	open_files (argv[1], argv[2], argv[3], EVAL_OUTPUT_FILE);

	/* compare the contents */
	if (specialJudge(fpin, fpout, fpans))
		output("Right Output!!!", 10);
	else
		output ("Wrong Answer", 0);
	return 0;
}
