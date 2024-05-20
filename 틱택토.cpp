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
	int gameover = 0;	//0게임중 1플레이어승 2컴퓨터승 3무승부

	while (1) {	//게임 루프

		//게임판 그리기
		system("cls");
		printf("조승주의 틱택토\n게임판이 깨지지 않으려면 콘솔창 상단바를 우클릭, 속성에서 레거시 콘솔 사용, 래스터 글꼴로 변경후 콘솔 재실행\n");
		printf("플레이어:Ｏ	인공지능:Ｘ\n");
		printf("┌１┬２┬３┐\n");
		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0:	printf("１");	break;
			case 1:	printf("２");	break;
			case 2:	printf("３");	break;
			}
			for (int j = 0; j < 3; j++) {
				switch (map[i][j]) {
				case 0:	printf("　");	break;
				case 1:	printf("Ｏ");	break;
				case 2:	printf("Ｘ"); break;
				}
				printf("│");
			}
			if (i != 2) printf("\n├─┼─┼─┤\n");
		}
		printf("\n└─┴─┴─┘\n");
		
		switch (gameover) {
		case 0:
			while (1) {	//플레이어에게 입력받기
				printf("x y: ");
				int x, y;
				scanf("%d %d", &x, &y);
				x--;	y--;
				if (x < 0 || x > 2 || y < 0 || y > 2 || map[y][x])
					printf("다시 입력 ");
				else if (!map[y][x]) {
					map[y][x] = 1;
					break;
				}
			}
			break;
		case 1:	//플레이어 승리
			printf("승리! \n(1:다시시작 2:종료) 입력: ");
			while (1) {	
				int n;
				scanf("%d", &n);
				if (n == 1)			break;
				else if (n == 2)	return;
				else				printf("다시 입력: ");
			}
			break;
		case 2:	//인공지능 승리
			printf("패배! \n(1:다시시작 2:종료) 입력: ");
			while (1) {
				int n;
				scanf("%d", &n);
				if (n == 1)			break;
				else if (n == 2)	return;
				else				printf("다시 입력: ");
			}
			break;
		case 3:	//무승부
			printf("무승부! \n(1:다시시작 2:종료) 입력: ");
			while (1) {
				int n;
				scanf("%d", &n);
				if (n == 1)			break;
				else if (n == 2)	return;
				else				printf("다시 입력: ");
			}
			break;
		}

		if (gameover) {	//재시작
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					map[i][j] = 0;
			gameover = 0;
			continue;
		}
		gameover = 0;

		//플레이어 승리 체크
		for (int i = 0; i < 3; i++) {
			if (map[i][0] == 1 && map[i][1] == 1 && map[i][2] == 1)	gameover = 1;
			if (map[0][i] == 1 && map[1][i] == 1 && map[2][i] == 1)	gameover = 1;
		}
		if (map[0][0] == 1 && map[1][1] == 1 && map[2][2] == 1)	gameover = 1;
		if (map[0][2] == 1 && map[1][1] == 1 && map[2][0] == 1)	gameover = 1;

		if (gameover)	continue;

		int count = 0, num;



		//무승부 체크
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (!map[i][j])	count++;
			}
		if (!count) {
			gameover = 3;
			continue;
		}

		//인공지능-----------------------------------------------
		printf("\n인공지능이 생각중");
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);


		//한줄을 만들 수 있는지 확인
		for (int i = 0; i < 3; i++) {	//가로확인
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

		for (int i = 0; i < 3; i++) {	//세로확인
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

		//대각선확인
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

		//플레이어 한줄 막기
		bool put = false;

		for (int i = 0; i < 3; i++) {	//가로확인
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

		for (int i = 0; i < 3; i++) {	//세로확인
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

		//대각선확인
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

		//가운데가 비었으면 가운데에 두기
		if (!map[1][1]) {
			map[1][1] = 2;
			continue;
		}



		//모두 해당하지 않으면 임의로 두기
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
