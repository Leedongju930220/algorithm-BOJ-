#include<iostream>
#include<string>

using namespace std;


int main(){
	bool flag = true;
	string s[51];
	int N;
	scanf("%d", &N);
	for (int i = 0 ; i < N ; i++){
		cin >> s[i];
	}
	int size = s[0].length();

	for (int i = 0; i < size; i++){
		flag = true;
		for (int j = 1; j < N; j++){
			if (s[0].at(i) != s[j].at(i)){
				flag = false;
				printf("?");
				break;
			}
		}
		if (flag == true){
			printf("%c", s[0].at(i));
		}
	}

	return 0;
}
