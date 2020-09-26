/* 所以昨天折磨了我几个小时的 1.11，其实根本没考虑 a 小于 b 的情况？？？
* #include<iostream>
* int main()
* {
* 	int a = 0, b = 0;
* 	std::cout << "Please enter two numbers" << std::endl;
* 	std::cin >> a >> b;
* 	if (a <= b) {
* 		int c = 0;
* 		c = b;
* 		b = a;
* 		a = c;
* 	}
* 	while (a - b > 1) {
* 		--a;
* 		std::cout << a << std::endl;
* 	}
* 	return 0;
* }
*/