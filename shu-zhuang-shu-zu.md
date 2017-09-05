```
//一维
#define lowbit(x) (x&(-x))

int n, t[MAXN];

void change(int x,int p)
{
    while(x<=n)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
int sum(int k)
{
    int result=0;
    while(k>0)
    {
        result+=t[k];
        k-=lowbit(k);
    }
    return result;
}

//二维
#define lowbit(x) (x&(-x))

int n, m, t[MAXN][MAXN];

int sum(int i, int j){
    int result = 0;
    for(int x = i; x > 0; x -= lowbit(x)) {
        for(int y = j; y > 0; y -= lowbit(y)) {
            result += t[x][y];
        }
    }
    return result;
}
void change(int i, int j, int p) {
    for (int x = i; x <= n; x += lowbit(x)) {
        for (int y = j; y <= m; y += lowbit(y)) {
            t[x][y] += p;
        }
    }
}

```



