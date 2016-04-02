/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int date1, date2;
	int month1, month2;
	int year1 = 0;
	int year2 = 0;
	int no_of_days = 0;
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//int ldays_in_month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	date1 = date1head->data * 10 + date1head->next->data;
	date2 = date2head->data * 10 + date2head->next->data;
	for (int i = 1; i < 3; i++){
		date1head = date1head->next;
		date2head = date2head->next;
	}
	month1 = date1head->data * 10 + date1head->next->data;
	month2 = date2head->data * 10 + date2head->next->data;
	for (int i = 1; i < 3; i++){
		date1head = date1head->next;
		date2head = date2head->next;
	}
	for (int i = 1; i <= 4; i++){
		year1 += year1 * 10 + date1head->data;
		date1head = date1head->next;
		year2 += year2 * 10 + date2head->data;
		date2head = date2head->next;
	}
	int years = 0;
	if (year1 < year2){
		no_of_days = days_in_month[month1] - date1;
		for (int i = month1 + 1; i < 12; i++){
			no_of_days += days_in_month[i];
		}
	}
	else{
		no_of_days = days_in_month[month2] - date1;
		for (int i = month2 + 1; i < 12; i++){
			no_of_days += days_in_month[i];
		}
	}
	if (year1 < year2){
		years = year2 - year1;
	}
	else{
		years = year1 - year2;
	}
	no_of_days += years * 365;
	//for leap years
	if (year1 % 4 == 0 || year1 % 400 == 0){
			no_of_days += 1;
	}
	else if (year2 % 4 == 0 || year2 % 400 == 0){
		no_of_days += 1;
	}
	else{
		if (years > 0){
			for (int i = year1; i < year2; i++){
				if (i % 4 == 0 || i % 400 == 0)
					no_of_days += 1;
			}
		}
	}
	return no_of_days;
}