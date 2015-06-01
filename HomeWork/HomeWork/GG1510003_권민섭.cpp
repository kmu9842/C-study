#include <stdio.h>

#define MAX 5

struct student {
	int Num;
	int kor;
	int eng;
	int math;
	int sum;
	float avg;
	int suk;
};

void main() {

	int sw,suks[2][5],count = 1;
	student st[5];

	st[0].Num = 1; st[0].kor = 90; st[0].eng = 78; st[0].math = 82;
	st[1].Num = 3; st[1].kor = 94; st[1].eng = 80; st[1].math = 88;
	st[2].Num = 2; st[2].kor = 65; st[2].eng = 77; st[2].math = 78;
	st[3].Num = 4; st[3].kor = 78; st[3].eng = 66; st[3].math = 95;
	st[4].Num = 5; st[4].kor = 89; st[4].eng = 54; st[4].math = 65;

	for (int i = 0;i < MAX ; i++) {
		st[i].sum = st[i].kor + st[i].eng + st[i].math; st[i].avg = st[i].sum / 3;
	}

	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			if (st[i].Num > st[j].Num) {
				count++;
			}
		}
		suks[0][count - 1] = i;
		count = 1;
	}

	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			if (st[i].sum < st[j].sum) {
				count++;
			}
		}
		st[i].suk = count;
		suks[1][count - 1] = i;
		count = 1;
	}

	while (1) {
		printf("----------------------------------------------\n");
		printf("- 1. �й��� ����                             -\n");
		printf("- 2. ������ ����                             -\n");
		printf("- 3. ���� ���� ����                          -\n");
		printf("- 4. ����                                    -\n");
		printf("----------------------------------------------\n");
		scanf("%d", &sw);
		switch (sw) {
		case 1:
			printf("�й� ���� ���� ���� �հ� ��� ����\n");
			for (int i = 0;i < MAX; i++) {
				printf(" %d   %d   %d   %d   %d  %.2f  %d\n", 
					st[suks[0][i]].Num, st[suks[0][i]].kor, st[suks[0][i]].eng, st[suks[0][i]].math, st[suks[0][i]].sum, st[suks[0][i]].avg, st[suks[0][i]].suk);
			}
			break;
		case 2:
			printf("�й� ���� ���� ���� �հ� ��� ����\n");
			for (int i = 0;i < MAX; i++) {
				printf(" %d   %d   %d   %d   %d  %.2f  %d\n",
					st[suks[1][i]].Num, st[suks[1][i]].kor, st[suks[1][i]].eng, st[suks[1][i]].math, st[suks[1][i]].sum, st[suks[1][i]].avg, st[suks[1][i]].suk);
			}
			break;
		case 3:
			int i;
			printf("�й� �Է� : ");
			scanf("%d", &i);
			printf("�й� ���� ���� ���� �հ� ��� ����\n");
			printf(" %d   %d   %d   %d   %d  %.2f  %d\n",
				st[suks[1][i]].Num, st[suks[1][i]].kor, st[suks[1][i]].eng, st[suks[1][i]].math, st[suks[1][i]].sum, st[suks[1][i]].avg, st[suks[1][i]].suk);
			
			break;
		case 4:
			break;
		default:
			break;
		}

		if (sw == 4) {
			break;
		}
	}

}