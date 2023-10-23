#include"Date.h"
void Test1() {
	Date d1(2023, 8, 23);
	Date d2;
	d1.Print();
	d2.Print();
}
void Test2() {
	Date d1(2023, 8, 23);
	Date d2(2000, 1, 1);
	if (d1 != d2) {
		cout << "unequal"<<endl;
	}
}
void Test3() {
	Date d1(2023, 8, 23);
	Date d2(2000, 1, 1);
	cout << (d1 > d2) << endl;
	cout << (d1 <= d2)<<endl;
}
void Test4() {
	Date d1(2023, 12, 21);   //+  +=
	Date d2(d1);
	(d1 + 40).Print();
	(d2 += 700).Print();
	
	//Date d3(d1);   //-  -=
	//Date d4(2023, 3, 2);
	//(d3 -= 400).Print();
	//(d4 - 40).Print();
}
void Test5() {
	Date d1(2023, 1, 1);   //++
	Date d2(d1);
	(++d1).Print();
	(d2++).Print();

	Date d3(2023, 1, 1);
	Date d4(d3);
	(--d3).Print();
	(d4--).Print();
}
void Test6() {
	Date d1(2023, 8, 24);
	Date d2(2024, 1, 1);

	printf("%d\n", d2 - d1);
}
void Test7() {
	Date d1(2023, 2,13);
	Date d2(2025, 1,15);
	printf("%d\n", d1-d2);
}
void Test8() {
	Date d1(2023, 2, 13);
	Date d2(2025, 1, 15);
	int a=d1.GetMonthDay(2023,2);
	int b=d2.ConverttoDay(2025, 1, 15);
	printf("%d %d\n", a,b);
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	//Test6();
	//Test7();
	//Test8();
	return 0;
}