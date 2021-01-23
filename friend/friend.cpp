/*
 * Purpose: demostrate the usage of friend function in a class
 *
 * Author: Lunsheng Wang <lunsheng.wang@gmail.com>
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h> //system()
#include "cursor.h"

class Line;
class Box{
	int color;
	int upx, upy;
	int lowx, lowy;

	public:
		friend int same_color(Line l, Box b);//Return 1 if same color, otherwise 0
		void set_color(int c); //Setter
		void define_box(int x1, int y, int x2, int y2);
		void show_box(void);
};

class Line {
	int color;
	int startx, starty;
	int length;

	public:
		friend int same_color(Line l, Box b); //So it can access my private member
		void set_color(int c);
		void define_line(int x, int y, int len);
		void show_line(void);

};

int same_color(Line l, Box b) //Friend function, not belong to both class
{
	if (l.color == b.color)
		return 1;

	return 0;
}

void Box::set_color(int c)
{
	if (c < FRONT_BLACK || c > FRONT_WHITE)
		printf("Invalid value, color range (%d - %d)\n",  FRONT_BLACK, FRONT_WHITE);

	color = c; //this->color = c;
}

void Box::define_box(int x1, int y1, int x2, int y2)
{
	upx = x1;
	upy = y1;
	lowx = x2;
	lowy = y2;
}

void Box::show_box(void)
{
	int i;

	SET_FRONT_COLOR(color);

	MOVETO(upx, upy);
	for (i = upx; i <= lowx; i++)
		printf("-");

	MOVETO(upx, lowy);
	for (i = upx; i <= lowx; i++)
		printf("-");

	MOVETO(upx-1, upy+1);
	for (i = upy+1; i <= lowy; i++) {
		printf("|");
		MOVETO(upx-1, i);
	}

	MOVETO(lowx+1, upy+1);
	for (i = upy+1; i <= lowy; i++) {
		printf("|");
		MOVETO(lowx+1, i);

	}
}

void Line::set_color(int c)
{
	if (c < FRONT_BLACK || c > FRONT_WHITE)
		printf("Invalid value, color range (%d - %d)\n",  FRONT_BLACK, FRONT_WHITE);

	color = c;
}

void Line::define_line(int x, int y, int len)
{
	startx = x;
	starty = y;
	length = len;
}

void Line::show_line(void)
{
	int i;
	SET_FRONT_COLOR(color);
	MOVETO(startx, starty);
	for (i = 0; i < length; i++)
		printf("-");
}


int main()
{
	Box b;
	Line l;

	//CLEAR();
	system("clear");
	b.define_box(10, 10, 15, 15);
	b.set_color(32);
	b.show_box();

	l.define_line(20, 20, 15);
	l.set_color(30);
	l.show_line();

	if (!same_color(l, b))
		std::cout << "\n Not the same!\n";

	getchar();
	l.define_line(25, 22, 10);
	l.set_color(32);
	l.show_line();

	if (same_color(l, b))
		std::cout << "\n Are the same color!\n";

	getchar();
	CLEAR();
	//system("clear");

	return 0;
}
