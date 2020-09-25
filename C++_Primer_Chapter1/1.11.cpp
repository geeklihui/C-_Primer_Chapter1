/* 本例因为一个坑，研究了很久，具体，看下文吧！希望多年我再看到这个代码，能一眼看出问题......
* 因为前后想过多个方案，每个都用注释包裹，因此整体就不用注释包裹了，避免嵌套。
*/
// #include <iostream>
// int main()
// {
// 	int a = 0, b = 0;
// 	std::cout << "Please enter two numbers " << std::endl;
// 	std::cin >> a >> b;

	/* 以下是第一反应
	* 	while (a = b) {
	*	std::cout << a << std::endl;
	*	--a; // 万一 a 小于 b，就无限循环了，难道要用 if？
	* }
	*/

	/* 以下是计算差值的方式
	* int c = 0;
	* // 这里少一句取 c 绝对值。感觉不对，还没学到绝对值
	* while (c < 0){
	* std::cout<< a << std::endl; // 这里遇到一个难题，如何判断 a 和 b 谁大谁小呢？不能判断的话怎么决定是 --a 还是 ++a 呢？难道必须要用 if 吗?
	* --a;
	* c = a - b;
	* }
	* return 0;
	*/

	/*
	* 解题思路 3：程序本身强制按照 a > b 处理，若 a = b，直接结束；若 a < b，则直接将 a 和 b 的值互换，然后继续处理。
	* 	while (a = b) {
	*	std::cout << "No numbers beetween " << a << " and " << b << std::endl;
	*		}
	* while (a < b) {
	*	int c = 0;
	*	c = a;
	*	a = b;
	*	b = c;
	* }
	* while (a > b) {
	*	std::cout << a << std::endl;
	*	--a;
	* }
	return 0; 
	// 为什么不管输入的 a、b 大小如何，执行结果是一直循环输出 No numbers beetween b and b？
	*/
	
	/* 解题思路 3.1：改良 3：
	* 等于的判断逻辑有问题，若两数相等，确实会一直输出。现在还没学 break ，所以考虑直接在输出后随便给两个数赋相异的值。
	* 只有第一条改进还不够，两数赋值的改变会导致后续循环继续执行。所以还需要将等于的语句块放到最后。
	*	while (a < b) {
	*	int c = 0;
	*	c = a;
	*	a = b;
	*	b = c;
	*}
	* while (a > b) {
	*	std::cout << a << std::endl;
	*	--a;
	*}
	* while (a = b) {
	*	std::cout << "No numbers beetween " << a << " and " << b << std::endl;
	*	a = 1;
	*	b = 3;
	* }
	* return 0;
	// ？？？一直循环输出 No numbers beetween 3 and 3 是什么鬼？？？
	// 结合 3 和 3.1，为什么程序最后会把两个数的值都变成 b 的值呢？
	// 是怎么把 a 的值变成 b 的？程序里为一的更改 a 的值的代码就三处，第一个是交换 a、b 的值，可是这一处有 while 条件 a 小于 b 才执行，输入 10 和 5 也一样的问题，所以问题不在这一处；第二个是 --a ，最终会把 a 的值变成 b 不错，可是不是变成 3 啊！第三个是直接让 a = 1，a 都为 1 了，显然不等于 3 ，怎么会循环执行这个循环体呢？
	*/

	/* 解题思路 3.2：继续改良 3：
	* 不论如何，最终导致循环输出这句话的，是 a=b 的循环体。直接删除这一段试试看。
	* 	while (a < b) {
	*	int c = 0;
	*	c = a;
	*	a = b;
	*	b = c;
	*}
	* while (a > b) {
	*	std::cout << a << std::endl;
	*	--a;
	* }
	* return 0;
	// 居然成了！还有个小毛病就是一开始输出了 a ，最后却没输出 b 。需要把 --a 和输出 a 的顺序换一下。
	// 还是需要继续研究 3 和 3.1 为何会重复执行 a=b 的循环体。
	*/

	/* 解题思路 3.3：继续改良 3：
	* 卧槽！知道为什么了，符号 = 是赋值语句，不是比较！要用 == ！！！！！！！
	* 怎么发现的呢？就是当我把 3.1 中，最后给 a、b 各赋相异的值以后运行发现，前面输出的都是对的，最后还是会反复执行。
	* 比如，我输入 1 和 5，执行结果是：
	* 5 
	* 4 
	* 3
	* 2 
	* No numbers beetween 1 and 1
	* No numbers beetween 1 and 1
	* ......
	* 很奇怪对不对？这样的结果完全符合预期，这说明程序整体逻辑是没问题的，那为什么加了给 a、b 各赋相异的值这一句，就完全错了呢？
	* 再次进行尝试，去除所有逻辑，只保留最后的相等判断的循环体，看看我一开始直接告诉你 a 就是等于 b 的，执行完一遍循环体以后，a 和 b 不相等了，你还会持续执行循环吗？
	* #include <iostream>
	* int main()
	* {
	* int a = 0, b = 0;
    * while (a = b) {
	* 	std::cout << "No numbers beetween " << a << " and " << b << std::endl;
	* 	a = 1;
	* 	b = 3;
	* }
	* return 0;
	* }
	* 结果令人更加吃惊，程序没有任何输出！
	* 这怎么可能？怎么会没有任何输出？也就是说整个 while 没执行，直接 return 了？
	* 可是第一句不是给 a 和 b 赋值为 0 了吗？相等啊，为什么不执行呢？
	* 循环不执行 —— 问题一定出在 condition 上！仔细观察，仔细观察，仔细观察......哦！！！单等号是赋值，不是判断！！！
	* （不过到这里我还是没完全想明白，当 condition 是一句完全无法判断真假的语句，while 会怎么处理呢？3 和 3.1 中都是判断为真，一直循环执行 statements；上面的例子中却直接判断为假，不执行 statements。为什么呢？）
	*/
//	while (a < b) {
//		int c = 0;
//		c = a;
//		a = b;
//		b = c;
//	}

	/* 顺序调换以后，确实不输出最大值了，但还是会输出最小值。
	* while (a > b) {
	*	 --a; 
	*	 std::cout << a << std::endl;
	* }
	*/

//	while (a - b > 1) {
//		 --a; 
//		 std::cout << a << std::endl;
//		}
//	while (a == b) {
//		std::cout << "No numbers beetween " << a << " and " << b << std::endl;
//		a = 1;
//		b = 3;
//	}
//	return 0;
//	}

// 最后想说一句，一个 if 解决的事儿，我硬是前后想了 6 个方案，嗯，真的很 Geeklihui ！就是自信到觉得自己懂作者！就是能往死里研究透，牛角尖钻到底！作者肯定不想这个时候的初学者用 if 解决！就是要锻炼思维！这个时候能想到用 if 的，要么不是本书的适用读者，要么，就是不会做了，网上 copy 的。