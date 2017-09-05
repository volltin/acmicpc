```
int father[MAXN];

int findfather(int x)
{
    if (x == father[x]) {
        return x;
    }
    return father[x] = findfather(father[x]);
}

//使用前
father[findfather(x)] = y;
```



