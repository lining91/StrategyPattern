#include <iostream>
#include <stdio.h>
using namespace std;

#include "StrategyPattern.h"


//	����ģʽʵ��
void main()
{
	CCashContext* pcContext = new CCashContext(2);
	int nTotal = 0;
	int nMoney = 300;
	nTotal = nTotal + pcContext->GetResult(300);
	cout << "nTotal = " << nTotal << endl;
	system("pause");
}