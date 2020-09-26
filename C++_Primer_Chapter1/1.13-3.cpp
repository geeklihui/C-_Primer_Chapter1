/* 这一题的精华在，使用 for 的情况下，对于 a 的处理；以及初始化语句的巧妙加减 1 。
* #include<iostream>
*	int a = 0, b = 0;
*	std::cin >> a >> b;
*	for (int i = a - b - 1; i > 0; --i) {
*		--a;
*		std::cout << a << std::endl;
*		}
*	for (int i = a - b + 1 ; i < 0; ++i) {
*		++a;
*		std::cout << a << std::endl;
*		}
*	return 0;
* }
*/