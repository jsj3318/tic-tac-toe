#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

void main() {
	srand(time(NULL));

	int map[3][3] =	{{0,0,0},
					 {0,0,0}, 
					 {0,0,0}};
	int gameover = 0;	//0������ 1�÷��̾�� 2��ǻ�ͽ� 3���º�

	while (1) {	//���� ����

		//������ �׸���
		system("cls");
		printf("�������� ƽ����\n�������� ������ �������� �ܼ�â ��ܹٸ� ��Ŭ��, �Ӽ����� ���Ž� �ܼ� ���, ������ �۲÷� ������ �ܼ� �����\n");
		printf("�÷��̾�:��	�ΰ�����:��\n");
		printf("��������������\n");
		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0:	printf("��");	break;
			case 1:	printf("��");	break;
			case 2:	printf("��");	break;
			}
			for (int j = 0; j < 3; j++) {
				switch (map[i][j]) {
				case 0:	printf("��");	break;
				case 1:	printf("��");	break;
				case 2:	printf("��"); break;
				}
				printf("��");
			}
			if (i != 2) printf("\n��������������\n");
		}
		printf("\n��������������\n");
		
		switch (gameover) {
		case 0:
			while (1) {	//�÷��̾�� �Է¹ޱ�
				printf("x y: ");
				int x, y;
				scanf("%d %d", &x, &y);
				x--;	y--;
				if (x < 0 || x > 2 || y < 0 || y > 2 || map[y][x])
					printf("�ٽ� �Է� ");
				else if (!map[y][x]) {
					map[y][x] = 1;
					break;
				}
			}
			break;
		case 1:	//�÷��̾� �¸�
			printf("�¸�! \n(1:�ٽý��� 2:����) �Է�: ");
			while (1) {	
				int n;
				scanf("%d", &n);
				if (n == 1)			break;
				else if (n == 2)	return;
				else				printf("�ٽ� �Է�: ");
			}
			break;
		case 2:	//�ΰ����� �¸�
			printf("�й�! \n(1:�ٽý��� 2:����) �Է�: ");
			while (1) {
				int n;
				scanf("%d", &n);
				if (n == 1)			break;
				else if (n == 2)	return;
				else				printf("�ٽ� �Է�: ");
			}
			break;
		case 3:	//���º�
			printf("���º�! \n(1:�ٽý��� 2:����) �Է�: ");
			while (1) {
				int n;
				scanf("%d", &n);
				if (n == 1)			break;
				else if (n == 2)	return;
				else				printf("�ٽ� �Է�: ");
			}
			break;
		}

		if (gameover) {	//�����
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					map[i][j] = 0;
			gameover = 0;
			continue;
		}
		gameover = 0;

		//�÷��̾� �¸� üũ
		for (int i = 0; i < 3; i++) {
			if (map[i][0] == 1 && map[i][1] == 1 && map[i][2] == 1)	gameover = 1;
			if (map[0][i] == 1 && map[1][i] == 1 && map[2][i] == 1)	gameover = 1;
		}
		if (map[0][0] == 1 && map[1][1] == 1 && map[2][2] == 1)	gameover = 1;
		if (map[0][2] == 1 && map[1][1] == 1 && map[2][0] == 1)	gameover = 1;

		if (gameover)	continue;

		int count = 0, num;



		//���º� üũ
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (!map[i][j])	count++;
			}
		if (!count) {
			gameover = 3;
			continue;
		}

		//�ΰ�����-----------------------------------------------
		printf("\n�ΰ������� ������");
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);


		//������ ���� �� �ִ��� Ȯ��
		for (int i = 0; i < 3; i++) {	//����Ȯ��
			count = 0;

			for (int j = 0; j < 3; j++) {
				if (map[i][j] == 2)	count++;
				if (map[i][j] == 0)	num = j;
			}
			if (count == 2 && !map[i][num]) {
				map[i][num] = 2;
				gameover = 2;
				break;
			}
		}
		if (gameover)	continue;

		for (int i = 0; i < 3; i++) {	//����Ȯ��
			count = 0;

			for (int j = 0; j < 3; j++) {
				if (map[j][i] == 2)	count++;
				if (map[j][i] == 0)	num = j;
			}
			if (count == 2 && !map[num][i]) {
				map[num][i] = 2;
				gameover = 2;
				break;
			}
		}
		if (gameover)	continue;

		//�밢��Ȯ��
		count = 0;
		for (int i = 0; i < 3; i++) {
			if (map[i][i] == 2)	count++;
			if (map[i][i] == 0)	num = i;
		}
		if (count == 2 && !map[num][num]) {
			map[num][num] = 2;
			gameover = 2;
			continue;
		}

		count = 0;
		for (int i = 0; i < 3; i++) {
			if (map[i][2 - i] == 2)	count++;
			if (map[i][2 - i] == 0)	num = i;
		}
		if (count == 2 && !map[num][2 - num]) {
			map[num][2 - num] = 2;
			gameover = 2;
			continue;
		}

		//�÷��̾� ���� ����
		bool put = false;

		for (int i = 0; i < 3; i++) {	//����Ȯ��
			count = 0;

			for (int j = 0; j < 3; j++) {
				if (map[i][j] == 1)	count++;
				if (map[i][j] == 0)	num = j;
			}
			if (count == 2 && !map[i][num]) {
				map[i][num] = 2;
				put = true;
				break;
			}
		}
		if (put)	continue;

		for (int i = 0; i < 3; i++) {	//����Ȯ��
			count = 0;

			for (int j = 0; j < 3; j++) {
				if (map[j][i] == 1)	count++;
				if (map[j][i] == 0)	num = j;
			}
			if (count == 2 && !map[num][i]) {
				map[num][i] = 2;
				put = true;
				break;
			}
		}
		if (put)	continue;

		//�밢��Ȯ��
		count = 0;
		for (int i = 0; i < 3; i++) {
			if (map[i][i] == 1)	count++;
			if (map[i][i] == 0)	num = i;
		}
		if (count == 2 && !map[num][num]) {
			map[num][num] = 2;
			continue;
		}

		count = 0;
		for (int i = 0; i < 3; i++) {
			if (map[i][2 - i] == 1)	count++;
			if (map[i][2 - i] == 0)	num = i;
		}
		if (count == 2 && !map[num][2 - num]) {
			map[num][2 - num] = 2;
			continue;
		}

		//����� ������� ����� �α�
		if (!map[1][1]) {
			map[1][1] = 2;
			continue;
		}



		//��� �ش����� ������ ���Ƿ� �α�
		count = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) 
				if (!map[i][j])	count++;

		num = rand() % count + 1;
		count = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				if (!map[i][j]) {
					count++;
					if (count == num) {
						map[i][j] = 2;
						put = true;
						break;
					}
				}
			if (put)	break;
		}
		

	}
}
