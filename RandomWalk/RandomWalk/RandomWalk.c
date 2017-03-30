#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ITERATION 50000

typedef struct Bugs {
	int ibug;
	int jbug;
}bugs;

bool CanMove(bugs bug, int imove_k, int jmove_k, int n, int m);
void Move(bugs *bug, int imove_k, int jmove_k);
bool Check(int* count[], int n, int m);
int Display(int* count[], int n, int m);

int main(void) {
	int **count;
	int n, m;
	bugs bug;
	int imove[8] = { -1,0,1,1,1,0,-1,-1 };
	int jmove[8] = { 1,1,1,0,-1,-1,-1,0 };
	int iteration = 0;
	int move_index = 0;
	bool canMove = false;
	bool over = false;
	
	printf("Input n m : ");
	scanf_s("%d %d", &n, &m);
	while (1) {
		if (n > 2 && n <= 40 && m >= 2 && m <= 20) {
			count = (int**)calloc(n, sizeof(int));
			for (int i = 0; i < n; i++) {
				count[i] = (int*)calloc(m, sizeof(int));
			}
			break;
		}
		else {
			printf("Please put the range of 2 < n <= 40 && 2 <= m <= 20 \n");
			printf("Input n m : ");
			scanf_s("%d %d", &n, &m);
		}
	}
	printf("Input bug's coordinate (ibug, jbug) : ");
	scanf_s("%d %d", &bug.ibug, &bug.jbug);
	while (1) {
		if (bug.ibug > 0 && bug.ibug <= n && bug.jbug > 0 && bug.jbug <= m) {
			count = (int**)calloc(n, sizeof(int));
			for (int i = 0; i < n; i++) {
				count[i] = (int*)calloc(m, sizeof(int));
			}
			break;
		}
		else {
			printf("Please put the range of 2 < n <= 40 && 2 <= m <= 20 \n");
			printf("Input bug's coordinate (ibug, jbug) : ");
			scanf_s("%d %d", &bug.ibug, &bug.jbug);
		}
	}
	bug.ibug--;
	bug.jbug--;
	count[bug.ibug][bug.jbug]++;
	while (over != true) {
		if (iteration < ITERATION) {
			if (iteration % 1000 == 0) {
				printf("%d\n", iteration);
			}
			srand(time(NULL));
			move_index = rand() % 8;
			canMove = CanMove(bug, imove[move_index], jmove[move_index], n, m);
			if (canMove == true) {
				Move(&bug, imove[move_index], jmove[move_index]);
//				printf("(%d, %d)\n", bug.ibug, bug.jbug);
				count[bug.ibug][bug.jbug] += 1;
			}
			else {
				continue;
			}
			iteration++;
			if (Check(count, n, m) == true) {
				printf("move time : %d \n", Display(count, n, m));
				printf("bug : (%d, %d)", bug.ibug, bug.jbug);
				over = true;
			}
		}
		else {
			printf("exceeded iteration\n");
			break;
		}
	}

}

bool CanMove(bugs bug, int imove_k, int jmove_k, int n, int m) {
	bool istrue = false;
	if (bug.ibug + imove_k < n && bug.ibug + imove_k >= 0 && bug.jbug + jmove_k < m && bug.jbug + jmove_k >= 0) {
		istrue = true;
	}
	else {
		istrue = false;
	}
	return istrue;
}

void Move(bugs *bug, int imove_k, int jmove_k) {
	bug->ibug = bug->ibug + imove_k;
	bug->jbug = bug->jbug + jmove_k;
}

bool Check(int* count[], int n, int m) {
	bool istrue = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (count[i][j] >= 1) {
				continue;
			}
			else {
				istrue = false;
				return istrue;
			}
		}
	}
	return istrue;
}

int Display(int* count[], int n, int m) {
	int move_time = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", count[i][j]);
			move_time = move_time+ count[i][j];
		}
		printf("\n");
	}
	return move_time - 1;
}