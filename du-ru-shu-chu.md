# 读入输出

## 从文件读入输出

```cpp
freopen("data.in", "r", stdin);
freopen("data.out", "w", stdout);
```

## 快速读入

```cpp
template<class T>
inline void read(T& num) {
    bool start=0, neg=0;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=1;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
```

## 加速 cin

```cpp
#define endl "\n"
#define IOS_ONLY do{ios_base::sync_with_stdio(false);std::cin.tie(NULL);} while(0)

int main()
{
    IOS_ONLY;
}
```



