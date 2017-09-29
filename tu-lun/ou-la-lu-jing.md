```
void dfs(int node) {
    REP(i, 0, 6) {
        if (m[node][i] != 0) {
        //枚举该点所连路径
            m[node][i]--;
            m[i][node]--;
            //递归
            dfs(i);
            //递归后存边
            cnt++;
            c[cnt].first = node;
            c[cnt].second = i;
        }
    }
}

for (int i = cnt; i > 0; i--) {
        //答案为倒序的
}
```



