#include <iostream>
using namespace std;

int** paper;
int minus_paper = 0, zero_paper = 0, one_paper = 0;

void find(int start_x, int start_y, int size) {
	//cout << "x = " << start_x << " y = " << start_y << " size " << size << endl;

	// 크기가 1이면 
	if (size == 1) {
		if (paper[start_x][start_y] == -1) minus_paper++;
		else if (paper[start_x][start_y] == 0) zero_paper++;
		else if (paper[start_x][start_y] == 1) one_paper++;
		return;
	}

	for (int i = start_x; i < start_x + size; i++)
		for (int j = start_y; j < start_y + size; j++) {
			// 요소가 하나라도 다르면 바로 자식 함수 생성 
			if (paper[start_x][start_y] != paper[i][j]) {
				for (int z = 0; z < 3; z++)
					for (int r = 0; r < 3; r++)
						find(start_x + (size / 3)*z, start_y + (size / 3)*r, size / 3);
				return;
			}
		}

	// 요소가 전부 다 같으면 추가해주기 
	if (paper[start_x][start_y] == -1) minus_paper++;
	else if (paper[start_x][start_y] == 0) zero_paper++;
	else if (paper[start_x][start_y] == 1) one_paper++;
	return;

}

int main() {
	int total_size;
	cin >> total_size;

	// 2차원 배열 동적 생성 
	paper = (int**)malloc(sizeof(int*)*total_size);
	for (int i = 0; i < total_size; i++)
		paper[i] = (int*)malloc(sizeof(int)*total_size);

	// 정보 입력
	for (int i = 0; i < total_size; i++)
		for (int j = 0; j < total_size; j++)
			cin >> paper[i][j];

	find(0, 0, total_size);

	cout << minus_paper << endl << zero_paper << endl << one_paper;

	return 0;
}
