#include<stdio.h>
#include<string.h>

int Month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void menu();
int First_weekday_of_the_year(int year);
int Leap_year(int year);
int First_weekday_of_the_month(int year,int month);
void Print_calendar(int year,int month);

void menu(void){
	int input, quit;
	system("cls");//clear the screen
	printf("[Calendar Menu]\n");
	printf("1: One month\n2: A period of month\n3: A year\n4: Quit\nInput: ");
	scanf("%d", &input);
	
	system("cls");
	system("color 3");
	switch(input){
		case 1: One_month();
		break;
		case 2: A_period_of_month();
		break;
		case 3: A_year();
		break;
		case 4: return;
		default: menu();
	}
	printf("\nEnter 1 to try again.\nElse quit.\n");
	scanf("%d", &quit);
	if(quit == 1){
		menu();
	}
	else{
		return 0;
	}
}

int First_weekday_of_the_year(int year){
    int i = ((5 * (year - 1)/4-(year - 1)/100 + (year - 1)/400) % 7) + 1;
    return i;
}

int Leap_year(int year){
    return((year % 4 == 0 && year % 100 != 0)||year % 400 == 0);
}

int First_weekday_of_the_month(int year,int month){
    int total_day = 0;
    if(Leap_year(year) == 1) Month_day[2] = 29;
    else Month_day[2] = 28;
    for(int i = 0;i < month ; i++){
        total_day += Month_day[i];
    }
    total_day = total_day + First_weekday_of_the_year(year);
    return (total_day % 7);
}

void Print_calendar(int year,int month){
	printf("\n%d/%d", year, month);
    printf("\nSun\tMon\tTue\tWes\tThu\tFri\tSar\n");
    if(Leap_year(year) == 1) Month_day[2] = 29;
    else Month_day[2] = 28;
    int b;
    b = First_weekday_of_the_month(year, month);
    for(int i = 0; i < b ; i++){
        printf("\t");
    }
    for(int i = 1; i <= Month_day[month] ; i++){
        printf("%d\t",i);
        if((b+i)%7 == 0) printf("\n");
    }
	printf("\n");
}

void One_month(void){
	int year, month;
	printf("===One month===\n");
	printf("Year: ");
	scanf("%d", &year);
	printf("Month: ");
	scanf("%d", &month);
	Print_calendar(year, month);
}

void A_period_of_month(void){
	int f_year, f_month, t_year, t_month;
	printf("===A period of month===\n");
	printf("From year: ");
	scanf("%d", &f_year);
	printf("Month: ");
	scanf("%d", &f_month);
	printf("From year: ");
	scanf("%d", &t_year);
	printf("Month: ");
	scanf("%d", &t_month);
	for(int year = f_year; year <= t_year; year++){
		for(int month = f_month; month <= t_month; month++){
			Print_calendar(year, month);
		}
	}
}

void A_year(void){
	int year;
	printf("===A year===\n");
	printf("Which year: ");
	scanf("%d", &year);
	for(int month = 1; month <= 12; month++){
		Print_calendar(year, month);
	}
}

int main(){
	menu();
	return 0;
}