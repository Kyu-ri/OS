#include <stdio.h>
#include <string.h>
#include <stdlib.h> // �ڵ� �߰�
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"

#include "devices/timer.h"

#include "projects/crossroads/crossroads.h"
#include "projects/crossroads/mapdata.h"

void run_crossroads(char **argv, char **string) //string �߰�
{
	struct thread t1, t2;
	struct semaphore a1;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//Console clear
	char map[7][7];
	memcpy(map, map_draw_default, sizeof(map_draw_default));

	for (int i = 0; i<7; i++) {
		for (int j = 0; j<7; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // ó�� ��ġ�� ����
	timer_msleep(1500);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//Console clear
	for (int i = 0; i<7; i++) {
		for (int j = 0; j<7; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}/**/
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");// ó�� ��ġ�� ����
	char a[20];
	strlcpy(a, *string, 40);
	for (int i = 0; i<10; i++) { printf("%s", a); }
}