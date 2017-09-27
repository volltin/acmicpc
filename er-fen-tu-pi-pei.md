# 二分图匹配

```
int match[N];       //右边点匹配点
bool vis[N];         //右边点是否被用
int ans;

vector<int>edgex[N];//左边点的边 右边点不用

bool dfs(int x) {
    for(auto it : edgex[x]) {   //枚举左边点连向的右边点
        if (!vis[it]) {
            vis[it] = true;
            if (!match[it] || dfs(match[it])) {
                match[it] = x;
                return true;
            }
        }
    }
    return false;
}

int Hungarian() {
    ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) {
            ans++;
        }
    }
    return ans; //返回最大匹配数
}
```



