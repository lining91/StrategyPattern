#include <stdlib.h>

//	现金收费抽象类
class CCashSuper{
public:
	virtual int AcceptCash(int nMoney) = 0;
};

//	正常收费类
class CCashNormal : public CCashSuper{
public:
	int AcceptCash(int nMoney)
	{
		return nMoney;
	}
};

//	打折收费类
class CCashRebate : public CCashSuper{
public:
	CCashRebate(int nValue)
	{
		cout << "打折收费 构造函数" << endl;
		nRebate = nValue;
	}

	int AcceptCash(int nMoney)
	{
		return nMoney * nRebate / 100;
	}

private:
	int nRebate;
};

//	返利收费类
class CCashReturn : public CCashSuper{
public:
	CCashReturn(int nConValue, int nRetValue)
	{
		cout << "返利收费  构造函数" << endl;
		nCondition = nConValue;
		nReturn = nRetValue;
	}

	int AcceptCash(int nMoney)
	{
		if (nMoney < nCondition)
			return nMoney;

		return (nMoney - nReturn);
	}

private:
	int nCondition;
	int nReturn;
};



//	CCashContext类
class CCashContext{
public:
	CCashContext(int nType)
	{
		pcCash = NULL;
		switch(nType)
		{
		case (1):			//	普通
			pcCash = new CCashNormal();
			break;
		case (2):			//	打八折
			pcCash = new CCashRebate(80);
			break;
		case (3):			//	满300返100
			pcCash = new CCashReturn(300, 100);
		}

	}
	int GetResult(int nMoney)
	{
		return pcCash->AcceptCash(nMoney);
	}

public:
	CCashSuper* pcCash;
};
