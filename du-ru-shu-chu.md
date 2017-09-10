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

## 超级快速读入

```cpp
const int File_Length=1<<27;//可以修改，表示输入文件不会超过的长度
char buf[File_Length],*inf=buf;
int read(){//这是一个读不进负数的数字读入
    int k=0;
    while(!isdigit(*inf))++inf;
    while(isdigit(*inf)){
        k=k*10+(*inf-'0');
        ++inf;
    }
    return k;
}
int main(){
    //freopen(***); //开文件必须在fread前面
    fread(buf, 1, N, stdin);//读入整个输入文件
    *****
    return 0;
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



