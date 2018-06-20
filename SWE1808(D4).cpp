#include<cstdio>
 
int key[10];
int testcase, n;
 
int check(int num){
    int count = 0;
    while (num > 0){
        if (!key[num % 10]) return -1;
        else{
            num = num / 10;
            count++;
        }
    }
    return count;
}
int divide_check(int num){
    int c = 0;
    if (num < 10){
        if (key[num]) return 1;
        else return -1;
    }
    else{
        int recur_check = check(num);
        if (recur_check != -1) return recur_check;
        else{
            for (int i = num-1; i >= 2; i--){
                c = check(i);
                if( (c != -1)  && ( num % i == 0)){
                     
                    int temp = divide_check(num / i);
                    if (temp != -1){
                        return c + temp + 1;
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++){
        for (int j = 0; j < 10; j++){
            scanf("%d", &key[j]);
        }
        scanf("%d", &n);
        int re_check = divide_check(n);
        if (re_check != -1) re_check++;
        printf("#%d %d\n", i+1, re_check);
    }
    return 0;
}
