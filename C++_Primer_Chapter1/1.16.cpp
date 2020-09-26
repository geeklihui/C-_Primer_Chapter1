/* 把输入语句作为判断条件，效果居然是支持未知的连续输入。这算是这次学习以来学到的第一个新知识了。
* #include<iostream>
* int main() {
*	int a = 0, sum = 0;
*	while (std::cin >> a) {
*		sum += a;
*	}
*	std::cout << sum << std::endl;
*	return 0;
* }
*/