#include <stdio.h>
#include <iostream>

using namespace std;

struct posn {
	int x;
	int y;
};

void foo (int *p1, int *p2) {
	p1 = p2;
	*p1 = 25;
	*p2 = 35;
}
void swap(struct posn *p1, struct posn *p2) {
	p1->x = p2->x;
	p2->x = p1->x;
	p2->y = p1->y;
	p1->y = p2->y;
}

int main () {
	int x = 10;
	int y = 20;
	foo(&x, &y);
	struct posn p1 = {42, 24};
	struct posn p2 = {21, 12};
	swap(&p1, &p2);
	cout << x << " " << y << endl;
	cout << p1.x << " " << p1.y << endl;
	cout << p2.x << " " << p2.y << endl;
	return 0;
}
