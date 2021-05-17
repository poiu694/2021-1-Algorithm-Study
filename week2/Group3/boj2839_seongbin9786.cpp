#include <stdio.h>

/*
	[Bronze 1]
	설탕 배달
	
	사탕 가게에 설탕을 정확하게 N 킬로그램 배달
	봉지에 담겨져 있고,	봉지는 3, 5킬로그램 있음
	최대한 적은 봉지만 들고 가려고 함

	N <= 5,000, 1초 // 그냥 막 해도 된다는 소리

	18 > 4
	만약 정확히 N 킬로그램을 만들 수 없다면 -1 출력

	---
	3*A + 5*B = N이 되는 A, B 중 A+B가 최소가 되는 값 = ?

	이게 왜 그리디일지 생각해보자
*/

using namespace std;

int main()
{
    int sum, a = 0, b = 0, n;
    scanf("%d", &n);

    /*
	그냥 5를 계속 빼는 게 최선이 아닌 것 같다
	수학적인 규칙은 없을 것 같음
	-1을 계산하는 것도 쉽진 않을듯?
	N에 집중할 게 아니라, a, b에 집중해볼까?
	N / b 를 한 다음, 몫만 곱하고, 그 나머지를 3으로 채운다.
	안 되는 경우 5를 또 빼고 3으로 채운다.
	이렇게 해서 3으로만 채웠는데도 일치하는 경우가 없으면 -1 반환
	*/
    sum = n;
    b = sum / 5;
    sum %= 5;

    a = sum / 3;
    sum %= 3;
    while (sum >= 0 && b >= 0)
    {
        // 만약 합이 n이면 종료
        if (a * 3 + b * 5 == n)
        {
            printf("%d\n", a + b);
            return 0;
        }
        // b를 하나 빼고 n에다 5를 더함
        b--;
        sum += 5;

        // a를 최대한 많게 하자
        a += sum / 3;
        sum %= 3;
    }
    printf("-1\n");
    return 0;
}