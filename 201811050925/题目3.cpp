#include "iostream"
#include "algorithm"
using namespace std;

struct student {
	int chinese;//语文成绩
	int math;//数学成绩
	int english;//英语成绩
	int num;//序号
	int sum;//总分
}s[100];

int cmp(student p1, student p2) {
	if (p1.sum == p2.sum && p1.chinese != p2.chinese) {
		return p1.chinese > p2.chinese;
	}//总分相同，语文成绩高排在前
	if (p1.sum == p2.sum && p1.chinese == p2.chinese) {
		return p1.num < p2.num;
	}//总分相同，语文成绩相同，序号小在前
	else {
		return p1.sum > p2.sum;
	}//否则总分越高在越前
}
int main()
{
	int n;//人数
    cout<<"请输入参评学生人数:"; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s[i].num = i;
		cin >> s[i].chinese >> s[i].math >> s[i].english;
		s[i].sum = s[i].chinese + s[i].math + s[i].english;
	}
	sort(1 + s, 1 + n + s, cmp);//排序

	for (int i = 1; i <= 5; i++) 
	{//输出前5名
		cout << s[i].num << "  " << s[i].sum << endl;;
	}
	return 0;
}
