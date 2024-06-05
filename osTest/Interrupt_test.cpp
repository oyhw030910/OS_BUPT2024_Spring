#include<iostream>
#include"Interrupt.h"
using namespace std;
int main() {
	initTable();
	raiseInterrupt(timer);
	return 0;
}