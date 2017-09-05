```
int kmpnext[MAXLEN];

void makenext (char p[]) {
    int len = (int)strlen(p);
    kmpnext[0] = 0;
    for (int k = 0, i = 1; i < len; i++) {
        while (k > 0 && p[i] != p[k]) {
            k = kmpnext[k - 1];
        }
        if (p[i] == p[k]) {
            k++;
        }
        kmpnext[i] = k;
        //cout << kmpnext[i] << endl;
    }
}

//b串在a串中出现的位置
int main(int argc, const char * argv[]) {
    cin >> a >> b;
    makenext(b);
    int lena = (int)strlen(a);
    int lenb = (int)strlen(b);
    for (int i = 0, j = 0; i < lena; i++) {
        while (j > 0 && a[i] != b[j]) {
            j = kmpnext[j - 1];
        }
        if (a[i] == b[j]) {
            j++;
        }
        if (j == lenb) {
            cout << i - j + 1 << endl;
            break;
            //j = kmpnext[j - 1]; //用于需要寻找多次匹配统计次数的手动回溯
        }
    }
    return 0;
}
```



