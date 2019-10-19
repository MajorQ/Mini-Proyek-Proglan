#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define ST_NUM 100

typedef struct tm tm;

typedef struct {
  int day;
  int hour;
} entry;

entry entry101;
entry entry102;
entry entry103;
entry entry104;
entry entry105;
entry entry201;
entry entry202;
entry entry203;
entry entry204;
entry entry205;

typedef struct {
  char name[25];
  char number[13];
  char room[4];
  char tend[20];
  char time[50];
} hotel;

hotel room101;
hotel room102;
hotel room103;
hotel room104;
hotel room105;
hotel room201;
hotel room202;
hotel room203;
hotel room204;
hotel room205;

COORD coord={0,0};
int error=0;
int entryDay, entryHour, exitDay, exitHour;

void gotoxy(int x, int y);
void menu();
void box (int x);
void data_write();
void data_read();
void data_time(char *x);
void data_print(int input, int x, int y, int z);
int data_search(char input[], int *output);
void checkIn();
void checkOut();
void database();
void database_read();
void database_write(int input, int cost);
int cost(int x);
void room_list();
void error_room(int x);
void password();
void update (int x,char name[25],char time[50],char room[4],char number[12],char tend[10]);

int main () {
  system ("cls");
  system ("color e1");
  data_read();
  menu();
  data_write();
  //system ("pause");
  return main();
}

void gotoxy(int x, int y) {
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void box (int x){
  if (x==1) {
    system("cls");
    system ("color e1");
    printf ("\t\t\t\t\t _______________________________________________\n");
    printf ("\t\t\t\t\t|  ___________________________________________  |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |___________________________________________| |\n");
    printf ("\t\t\t\t\t|_______________________________________________|\n");
    gotoxy(45,3);
  }
  else if (x==2) {
    system("cls");
    system ("color e1");
    printf ("\t\t\t\t\t _______________________________________________\n");
    printf ("\t\t\t\t\t|  ___________________________________________  |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |                                           | |\n");
    printf ("\t\t\t\t\t| |___________________________________________| |\n");
    printf ("\t\t\t\t\t|_______________________________________________|\n");
    gotoxy(45,3);
  }
  else if (x==3){
    system("cls");
    system ("color e1");
    printf ("\t\t\t\t    _____________________________________________________\n");
    printf ("\t\t\t\t   |  _________________________________________________  |\n");
    printf ("\t\t\t\t   | |         |         |         |         |         | |\n");
    printf ("\t\t\t\t   | |    2    |    2    |    2    |    2    |    2    | |\n");
    printf ("\t\t\t\t   | |    0    |    0    |    0    |    0    |    0    | |\n");
    printf ("\t\t\t\t   | |    1    |    2    |    3    |    4    |    5    | |\n");
    printf ("\t\t\t\t   | |         |         |         |         |         | |\n");
    printf ("\t\t\t\t   | |_________|_________|_________|_________|_________| |\n");
    printf ("\t\t\t\t   | |         |         |         |         |         | |\n");
    printf ("\t\t\t\t   | |    1    |    1    |    1    |    1    |    1    | |\n");
    printf ("\t\t\t\t   | |    0    |    0    |    0    |    0    |    0    | |\n");
    printf ("\t\t\t\t   | |    1    |    2    |    3    |    4    |    5    | |\n");
    printf ("\t\t\t\t   | |         |         |         |         |         | |\n");
    printf ("\t\t\t\t   | |_________|_________|_________|_________|_________| |\n");
    printf ("\t\t\t\t   |_____________________________________________________|\n");
  }
}

void menu() {
  system("cls");
  system ("color e1");
  printf ("\t\t\t\t\t _______________________________________________\n");
  printf ("\t\t\t\t\t|  ___________________________________________  |\n");
  printf ("\t\t\t\t\t| |    _    ____ ____ ___  ____ ____ _  _     | |\n");
  printf ("\t\t\t\t\t| |    |    |  | | __ |__] |  | |  | |_/      | |\n");
  printf ("\t\t\t\t\t| |    |___ |__| |__] |__] |__| |__| | \\_     | |\n");
  printf ("\t\t\t\t\t| |                                           | |\n");
  printf ("\t\t\t\t\t| |                                           | |\n");
  printf ("\t\t\t\t\t| |               1. CHECK IN                 | |\n");
  printf ("\t\t\t\t\t| |               2. CHECK OUT                | |\n");
  printf ("\t\t\t\t\t| |               3. DATABASE                 | |\n");
  printf ("\t\t\t\t\t| |               4. EXIT                     | |\n");
  printf ("\t\t\t\t\t| |                                           | |\n");
  printf ("\t\t\t\t\t| |             SELECT: 1/2/3/4               | |\n");
  printf ("\t\t\t\t\t| |___________________________________________| |\n");
  printf ("\t\t\t\t\t|_______________________________________________|\n");
  gotoxy(0,20);

  switch (getch()){
    case '1':
      checkIn();
    break;
    case '2':
      checkOut();
    break;
    case '3':
      password();
    break;
    case '4':
      exit(0);
    break;
    default:
      gotoxy(46,12);
      printf (RED"Please input the following selection!");
      Sleep (1200);
      return menu();
  }
}

void data_time(char *x) {
  time_t currentTime;
	time(&currentTime);

	tm *timeinfo;
  timeinfo = localtime(&currentTime);
	entryDay= timeinfo->tm_mday;
	entryHour= timeinfo->tm_hour;
  exitDay= timeinfo->tm_mday;
  exitHour= timeinfo->tm_hour;
	strcpy(x, asctime(timeinfo));
}

void data_read() {
  int numr;
  char name[25], time[50], room[4], number[13], tend[20];
  FILE *f, *g;
  f = fopen("data1.csv", "r");
  g = fopen("data2.csv", "r");
  char buf[1000], buf2[1000], *tmp;

  while (fgets(buf, 1000, f)) {
    tmp = strtok(buf, ",");
    strcpy(name, tmp);
    tmp = strtok(NULL, ",");
    strcpy(number, tmp);
    tmp = strtok(NULL, ",");
    strcpy(room, tmp);
    tmp = strtok(NULL, ",");
    strcpy(tend, tmp);
    tmp = strtok(NULL, ",");
    strcpy(time, tmp);
    numr = atoi(room);
    fgets(buf2, 100, g);
    tmp = strtok(buf2, ",");
    entryDay = atoi(tmp);
    tmp = strtok(NULL, ",");
    entryHour = atoi(tmp);
    update(numr, name, time, room, number, tend);
  }
  fclose(f);
  fclose(g);
}

void data_write(){
  FILE *f, *g;
  f = fopen("data1.csv", "w");
  g = fopen("data2.csv", "w");

  if (strlen(room101.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room101.name, room101.number, room101.room, room101.tend, room101.time);
    fprintf(g, "%d,%d\n", entry101.day, entry101.hour);
  }
  if (strlen(room102.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room102.name, room102.number, room102.room, room102.tend, room102.time);
    fprintf(g, "%d,%d\n", entry102.day, entry101.hour);
  }
  if (strlen(room103.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room103.name, room103.number, room103.room, room103.tend, room103.time);
    fprintf(g, "%d,%d\n", entry103.day, entry103.hour);
  }
  if (strlen(room104.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room104.name, room104.number, room104.room, room104.tend, room104.time);
    fprintf(g, "%d,%d\n", entry104.day, entry104.hour);
  }
  if (strlen(room105.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room105.name, room105.number, room105.room, room105.tend, room105.time);
    fprintf(g, "%d,%d\n", entry105.day, entry105.hour);
  }
  if (strlen(room201.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room201.name, room201.number, room201.room, room201.tend, room201.time);
    fprintf(g, "%d,%d\n", entry201.day, entry201.hour);
  }
  if (strlen(room202.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room202.name, room202.number, room202.room, room202.tend, room202.time);
    fprintf(g, "%d,%d\n", entry202.day, entry202.hour);
  }
  if (strlen(room203.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room203.name, room203.number, room203.room, room203.tend, room203.time);
    fprintf(g, "%d,%d\n", entry203.day, entry203.hour);
  }
  if (strlen(room204.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room204.name, room204.number, room204.room, room204.tend, room204.time);
    fprintf(g, "%d,%d\n", entry204.day, entry204.hour);
  }
  if (strlen(room205.name) != 0) {
    fprintf(f, "%s,%s,%s,%s,%s", room205.name, room205.number, room205.room, room205.tend, room205.time);
    fprintf(g, "%d,%d\n", entry205.day, entry205.hour);
  }
  fclose(f);
  fclose(g);

}

void checkIn() {
  int numr, temp;
  char name[25], time[50], room[4], number[13], tend[10];

  box(1);
  printf ("Name\t : ");
  gets(name);
  box(1);
  printf ("Phone number : ");
  gets(number);
retry1:
  box(1);
  printf ("Room number  : ");
  gets(room);
  numr = atoi(room);
  error_room(numr);
  if (error == 1) {goto retry1;}

retry2:
  box(2);
  printf ("Tendency:");
  gotoxy(59,6);
  printf ("1. Vacation");
  gotoxy(59,7);
  printf ("2. Work");
  gotoxy(59,8);
  printf ("3. Others");
  gotoxy(58,12);
  printf ("SELECT: 1/2/3");
  gotoxy(0,20);

  switch (getch()){
    case '1':
      strcpy(tend, "Vacation");
    break;
    case '2':
      strcpy(tend,"Work");
    break;
    case '3':
      strcpy(tend, "Others");
    break;
    default:
      gotoxy(46,12);
      printf (RED"Please input the following selection!");
      Sleep (1200);
      goto retry2;
   }

retry3:
  box(2);
  printf ("Name\t  : %s", name);
  gotoxy(45,4);
  printf ("Phone number : %s", number);
  gotoxy(45,5);
  printf ("Room number  : %s", room);
  gotoxy(45,6);
  printf ("Tendency     : %s", tend);
  gotoxy(45,8);
  data_time(time);
  printf ("Entry time   : %s", time);
  gotoxy(58,12);
  printf ("CONFIRM[Y/N]");
  gotoxy(0,20);

  switch(getch()){
    case 'y':
      update(numr, name, time, room, number, tend);
      box(2);
      gotoxy(60,3);
      printf ("Thank You");
      gotoxy(55,4);
      printf ("For your reservation");
      if (entryHour >= 18 && entryHour<24) {
        gotoxy(58,7);
        printf (RED"Hot chocholate");
        gotoxy(64,8);
        printf (RED"&");
        gotoxy(53,9);
        printf (RED"Bathroom with hot water");
        gotoxy(49,12);
        printf (BLUE"It's ready for you in room %s", room);
        gotoxy(0,20);
      }
      else if (entryHour >= 7 && entryHour<12) {
        gotoxy(55,8);
        printf (RED"Breakfast & Hot tea");
        gotoxy(49,12);
        printf (BLUE"It's ready for you in room %s", room);
        gotoxy(0,20);
      }
      else {
        gotoxy(57,8);
        printf (RED"Enjoy your stay !");
        gotoxy(52,12);
        printf (BLUE"Room %s is ready for you", room);
        gotoxy(0,20);
      }
      getch();
    break;
    case 'n':
    printf(" ");
    break;
    default:
      gotoxy(46,12);
      printf (RED"Please input the following selection!");
      Sleep (1200);
      goto retry3;
  }
}

void checkOut () {
  char input[25], zero[] = "\0", time[50];
  int num, numr, i, room[10], bol = 0;

retry:
  box(1);
  printf ("Search : ");
  gets(input);
  num = data_search(input, room);
  if (num == 0) {
    box(1);
    printf (RED"Name not found!");
    fflush(stdin);
    Sleep(1000);
    goto retry;
  }
  if (num > 1) {
    for (i = 0; i < num; i++) {
      if (room[i] != 0) {
        gotoxy(45, 8 + (i * 3));
        printf("%d. ", i + 1);
        printf("Name: %s", input);
        gotoxy(48, 9 + (i * 3));
        printf("Room: %d", room[i]);
      }
    }
    gotoxy(45, 10 + (i * 3));
    printf("Enter room number: ");
    numr = atoi(gets(input));
    for (i = 0; i < num; i++) {
      if (numr == room[i]) {
        bol = 1;
      }
    }
    if (bol != 1) {
        gotoxy(45,3);
        printf (RED"Please input the correct room number!");
        fflush(stdin);
        Sleep (1200);
        checkOut();
      }
  } else if (num == 1) {
    numr = room[0];
  }

retry2:
  box(2);
  data_print(numr, 45, 3, 1);
  gotoxy(45,9);
  data_time(time);
  printf ("Exit time    : %s", time);
  gotoxy(45,11);
  printf(RED"\"Cost: $%d\"", cost(numr));
  gotoxy(58,12);
  printf (BLUE"CONFIRM[Y/N]");
  gotoxy(0,20);

  switch(getch()) {
    case 'y':
    database_write(numr, cost(numr));
    update(numr, zero, zero, zero, zero, zero);
    box(2);
    gotoxy(60,3);
    printf ("Thank You");
    gotoxy(54,4);
    printf ("For using our services");
    gotoxy(60,8);
    printf (RED"Farewell!");
    gotoxy(53,12);
    printf (BLUE"See you at another time");
    gotoxy(0,20);
    getch();
    break;
    case 'n':
    break;
    default:
      gotoxy(46,12);
      printf (RED"Please input the following selection!");
      Sleep (1200);
      goto retry2;
  }
}

int cost (int x){
  int price, room_cost=0, day;
  price=85;

  switch(x) {
    case 101:
      day=exitDay-entry101.day;
      exitHour>entry101.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 102:
      day=exitDay-entry102.day;
      exitHour>entry102.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 103:
      day=exitDay-entry103.day;
      exitHour>entry103.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 104:
      day=exitDay-entry104.day;
      exitHour>entry104.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 105:
      day=exitDay-entry105.day;
      exitHour>entry105.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 201:
      day=exitDay-entry201.day;
      exitHour>entry201.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 202:
      day=exitDay-entry202.day;
      exitHour>entry202.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 203:
      day=exitDay-entry203.day;
      exitHour>entry203.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 204:
      day=exitDay-entry204.day;
      exitHour>entry204.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
    case 205:
      day=exitDay-entry205.day;
      exitHour>entry205.hour ? day+=1:day+=0;
      room_cost= day*price;
    break;
  }
  room_cost==0 ? room_cost=price : room_cost=room_cost;
  return abs(room_cost);
}

void update (int x,char name[25],char time[50],char room[4],char number[12],char tend[10]) {
  switch (x) {
    case 101:
      strcpy(room101.name, name);
      strcpy(room101.number, number);
      strcpy(room101.room, room);
      strcpy(room101.tend, tend);
      strcpy(room101.time, time);
      entry101.day= entryDay;
      entry101.hour= entryHour;
    break;
    case 102:
      strcpy(room102.name, name);
      strcpy(room102.number, number);
      strcpy(room102.room, room);
      strcpy(room102.tend, tend);
      strcpy(room102.time, time);
      entry102.day= entryDay;
      entry102.hour= entryHour;
    break;
    case 103:
      strcpy(room103.name, name);
      strcpy(room103.number, number);
      strcpy(room103.room, room);
      strcpy(room103.tend, tend);
      strcpy(room103.time, time);
      entry103.day= entryDay;
      entry103.hour= entryHour;
    break;
    case 104:
      strcpy(room104.name, name);
      strcpy(room104.number, number);
      strcpy(room104.room, room);
      strcpy(room104.tend, tend);
      strcpy(room104.time, time);
      entry104.day = entryDay;
      entry104.hour = entryHour;
    break;
    case 105:
      strcpy(room105.name, name);
      strcpy(room105.number, number);
      strcpy(room105.room, room);
      strcpy(room105.tend, tend);
      strcpy(room105.time, time);
      entry105.day= entryDay;
      entry105.hour= entryHour;
    break;
    case 201:
      strcpy(room201.name, name);
      strcpy(room201.number, number);
      strcpy(room201.room, room);
      strcpy(room201.tend, tend);
      strcpy(room201.time, time);
      entry201.day= entryDay;
      entry201.hour= entryHour;
      break;
    case 202:
      strcpy(room202.name, name);
      strcpy(room202.number, number);
      strcpy(room202.room, room);
      strcpy(room202.tend, tend);
      strcpy(room202.time, time);
      entry202.day= entryDay;
      entry202.hour= entryHour;
    break;
    case 203:
      strcpy(room203.name, name);
      strcpy(room203.number, number);
      strcpy(room203.room, room);
      strcpy(room203.tend, tend);
      strcpy(room203.time, time);
      entry203.day= entryDay;
      entry203.hour= entryHour;
    break;
    case 204:
      strcpy(room204.name, name);
      strcpy(room204.number, number);
      strcpy(room204.room, room);
      strcpy(room204.tend, tend);
      strcpy(room204.time, time);
      entry204.day= entryDay;
      entry204.hour= entryHour;
    break;
    case 205:
      strcpy(room205.name, name);
      strcpy(room205.number, number);
      strcpy(room205.room, room);
      strcpy(room205.tend, tend);
      strcpy(room205.time, time);
      entry205.day= entryDay;
      entry205.hour= entryHour;
    break;
  }
}

int data_search(char input[], int *output) {
  int room[10], count = 0, i = 0;
  for (i = 0; i < 10; i ++) {
    output[i] = 0;
    room[i] = 0;
  }
  if (strcmp(room101.name, input) == 0) {
    room[count] = 101;
    count++;
  }
  if (strcmp(room102.name, input) == 0) {
  	room[count] = 102;
    count++;
  }
  if (strcmp(room103.name, input) == 0) {
  	room[count] = 103;
    count++;
  }
  if (strcmp(room104.name, input) == 0) {
  	room[count] = 104;
    count++;
  }
  if (strcmp(room105.name, input) == 0) {
  	room[count] = 105;
    count++;
  }
  if (strcmp(room201.name, input) == 0) {
  	room[count] = 201;
    count++;
  }
  if (strcmp(room202.name, input) == 0) {
  	room[count] = 202;
    count++;
  }
  if (strcmp(room203.name, input) == 0) {
  	room[count] = 203;
    count++;
  }
  if (strcmp(room204.name, input) == 0) {
  	room[count] = 204;
    count++;
  }
  if (strcmp(room205.name, input) == 0) {
  	room[count] = 205;
    count++;
  }
  for (i = 0; i < 10; i++) {
    if (room[i] != 0)
      output[i] = room[i];
  }
  return count;
}

void data_print(int input, int x, int y, int z) {
  gotoxy(x, y);
  switch(input) {
    case 101:
      printf ("Name\t  : %s", room101.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room101.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room101.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room101.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room101.time);
    break;
    case 102:
      printf ("Name\t  : %s", room102.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room102.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room102.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room102.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room102.time);
    break;
    case 103:
      printf ("Name\t  : %s", room103.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room103.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room103.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room103.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room103.time);
    break;
    case 104:
      printf ("Name\t  : %s", room104.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room104.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room104.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room104.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room104.time);
    break;
    case 105:
      printf ("Name\t  : %s", room105.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room105.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room105.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room105.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room105.time);
    break;
    case 201:
      printf ("Name\t  : %s", room201.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room201.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room201.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room201.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room201.time);
    break;
    case 202:
      printf ("Name\t  : %s", room202.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room202.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room202.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room202.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room202.time);
    break;
    case 203:
      printf ("Name\t  : %s", room203.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room203.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room203.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room203.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room203.time);
    break;
    case 204:
      printf ("Name\t  : %s", room204.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room204.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room204.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room204.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room204.time);
    break;
    case 205:
      printf ("Name\t  : %s", room205.name);
      gotoxy(x, y + 1);
      printf ("Phone number : %s", room205.number);
      gotoxy(x, y + 2);
      printf ("Room number  : %s", room205.room);
      gotoxy(x, y + 3);
      printf ("Tendency     : %s", room205.tend);
      gotoxy(x, y+4+z);
      printf ("Entry time   : %s", room205.time);
    break;
  }
}

void error_room(int numr){
  error=0;
  switch (numr) {
    case 101:
      if (strlen(room101.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 102:
      if (strlen(room102.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 103:
      if (strlen(room103.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 104:
      if (strlen(room104.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 105:
      if (strlen(room105.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 201:
      if (strlen(room201.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
      break;
    case 202:
      if (strlen(room202.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 203:
      if (strlen(room203.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 204:
      if (strlen(room204.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    case 205:
      if (strlen(room205.name) != 0) {
        gotoxy(45,3);
        printf (RED"Sorry, room %d has been booked :)", numr);
        error= 1;
        Sleep(1300);
        room_list();
      }
    break;
    default:
      gotoxy(45,3);
      printf (RED"Sorry, room not available :)");
      Sleep(1000);
      room_list();
      error=1;
    }
  }

void database() {
    int numr, i = 0;
  retry:
    box(2);
    printf ("Data type: ");
    gotoxy(58,6);
    printf ("1. Occupants");
    gotoxy(58,7);
    printf ("2. History");
    gotoxy(58,8);
    printf ("3. Data summary");
    gotoxy(58,12);
    printf ("SELECT: 1/2/3");
    gotoxy(0,20);

    switch (getch()){
      case '1':
        box(1);
        gotoxy(54,3);
        printf("CURRENT ROOM OCCUPANTS");
        if (strlen(room101.name) != 0) {
          (101, 45, 7 + (6*i));
          i++;
        }
        if (strlen(room102.name) != 0) {
          data_print(102, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room103.name) != 0) {
          data_print(103, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room104.name) != 0) {
          data_print(104, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room105.name) != 0) {
          data_print(105, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room201.name) != 0) {
          data_print(201, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room202.name) != 0) {
          data_print(202, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room203.name) != 0) {
          data_print(203, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room204.name) != 0) {
          data_print(204, 45, 7 + (6*i), 0);
          i++;
        }
        if (strlen(room205.name) != 0) {
          data_print(205, 45, 7 + (6*i), 0);
          i++;
        }
      break;
      case '2':
        box(1);
        gotoxy(54,3);
        printf("ROOM OCCUPANCY HISTORY");
        database_read();
      break;
      case '3':
        system("python C:/Users/aldoa/Desktop/project/graph.py");
      break;
      default:
        gotoxy(46,12);
        printf (RED"Please input the following selection!");
        Sleep (1200);
        goto retry;
     }
     getch();
  }

void room_list(){
  box(3);
  if (strlen(room201.name) != 0) {
    gotoxy(42,3);
    printf(RED"2");
    gotoxy(42,4);
    printf(RED"0");
    gotoxy(42,5);
    printf(RED"1");
  }
  if (strlen(room202.name) != 0) {
    gotoxy(52,3);
    printf(RED"2");
    gotoxy(52,4);
    printf(RED"0");
    gotoxy(52,5);
    printf(RED"2");
  }
  if (strlen(room203.name) != 0) {
    gotoxy(62,3);
    printf(RED"2");
    gotoxy(62,4);
    printf(RED"0");
    gotoxy(62,5);
    printf(RED"3");
  }
  if (strlen(room204.name) != 0) {
    gotoxy(72,3);
    printf(RED"2");
    gotoxy(72,4);
    printf(RED"0");
    gotoxy(72,5);
    printf(RED"4");
  }
  if (strlen(room205.name) != 0) {
    gotoxy(82,3);
    printf(RED"2");
    gotoxy(82,4);
    printf(RED"0");
    gotoxy(82,5);
    printf(RED"5");
  }
  if (strlen(room101.name) != 0) {
    gotoxy(42,9);
    printf(RED"1");
    gotoxy(42,10);
    printf(RED"0");
    gotoxy(42,11);
    printf(RED"1");
  }
  if (strlen(room102.name) != 0) {
    gotoxy(52,9);
    printf(RED"1");
    gotoxy(52,10);
    printf(RED"0");
    gotoxy(52,11);
    printf(RED"2");
  }
  if (strlen(room103.name) != 0) {
    gotoxy(62,9);
    printf(RED"1");
    gotoxy(62,10);
    printf(RED"0");
    gotoxy(62,11);
    printf(RED"3");
  }
  if (strlen(room104.name) != 0) {
    gotoxy(72,9);
    printf(RED"1");
    gotoxy(72,10);
    printf(RED"0");
    gotoxy(72,11);
    printf(RED"4");
  }
  if (strlen(room105.name) != 0) {
    gotoxy(82,9);
    printf(RED"1");
    gotoxy(82,10);
    printf(RED"0");
    gotoxy(82,11);
    printf(RED"5");
  }
  gotoxy(0,20);
  getch();
}

void database_read(){
  FILE *f;
  f = fopen("data3.csv", "r");
  char buf[1000], *tmp;
  char name[ST_NUM][25], time[ST_NUM][20], room[ST_NUM][4], number[ST_NUM][13], tend[ST_NUM][20];
  int cost[ST_NUM];
  int i = 0, j;
  while (fgets(buf, 1000, f)) {
    tmp = strtok(buf, ",");
    strcpy(name[i], tmp);
    tmp = strtok(NULL, ",");
    strcpy(number[i], tmp);
    tmp = strtok(NULL, ",");
    strcpy(room[i], tmp);
    tmp = strtok(NULL, ",");
    strcpy(tend[i], tmp);
    tmp = strtok(NULL, ",");
    cost[i] = atoi(tmp);
    tmp = strtok(NULL, ",");
    strcpy(time[i], tmp);
    i++;
  }
  Sleep(1000);
  fclose(f);
  for (j = 0; j < i; j++) {
    gotoxy(45, 7 + (7 * j));
    printf("Name: %s", name[j]);
    gotoxy(45, 8 + (7 * j));
    printf("Number: %s", number[j]);
    gotoxy(45, 9 + (7 * j));
    printf("Room: %s", room[j]);
    gotoxy(45, 10 + (7 * j));
    printf("Tendency: %s", tend[j]);
    gotoxy(45, 11 + (7 * j));
    printf("Cost: %d", cost[j]);
    gotoxy(45, 12 + (7 * j));
    printf("Entry Time: %s", time[i]);
  }
}

void database_write(int input, int cost) {
  FILE *f;
  f = fopen("data3.csv", "a");
  switch(input) {
    case 101:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room101.name, room101.number, room101.room, room101.tend, cost, room101.time);
    break;
    case 102:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room102.name, room102.number, room102.room, room102.tend, cost, room102.time);
    break;
    case 103:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room103.name, room103.number, room103.room, room103.tend, cost, room103.time);
    break;
    case 104:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room104.name, room104.number, room104.room, room104.tend, cost, room104.time);
    break;
    case 105:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room105.name, room105.number, room105.room, room105.tend, cost, room105.time);
    break;
    case 201:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room201.name, room201.number, room201.room, room201.tend, cost, room201.time);
      break;
    case 202:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room202.name, room202.number, room202.room, room202.tend, cost, room202.time);
    break;
    case 203:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room203.name, room203.number, room203.room, room203.tend, cost, room203.time);
    break;
    case 204:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room204.name, room204.number, room204.room, room204.tend, cost, room204.time);
    break;
    case 205:
      fprintf(f, "%s,%s,%s,%s,%d,%s\n", room205.name, room205.number, room205.room, room205.tend, cost, room205.time);
  }
  fclose(f);
}

void password() {
  char pass[50], user[15];
  char rPass[50]="proglanmantap";
  char rUser[15]="admin";

  int i=0;
  box(1);
  printf("User ID: ");
  gets(user);
  box(1);
  printf("password: ");

  do{
      pass[i]=getch();
      if(pass[i]== 8){
        i=i-2;
        printf("\b \b");
      }
      else if(pass[i]!='\r'){
          printf("*");
      }
      i++;
  }while(pass[i-1]!='\r');
  pass[i-1]='\0';

  if (strcmp(user, rUser)== 0){
    if (strcmp(pass, rPass)==0){
      database();
    }
    else {
      box(1);
      printf(RED"Wrong user ID or Password.");
      Sleep(1200);
      main();
    }
  }
  else {
    box(1);
    printf(RED"Wrong user ID or Password.");
    Sleep(1200);
    main();
  }
}
