#include <stdlib.h>

//	�ֽ��շѳ�����
class CCashSuper{
public:
	virtual int AcceptCash(int nMoney) = 0;
};

//	�����շ���
class CCashNormal : public CCashSuper{
public:
	int AcceptCash(int nMoney)
	{
		return nMoney;
	}
};

//	�����շ���
class CCashRebate : public CCashSuper{
public:
	CCashRebate(int nValue)
	{
		cout << "�����շ� ���캯��" << endl;
		nRebate = nValue;
	}

	int AcceptCash(int nMoney)
	{
		return nMoney * nRebate / 100;
	}

private:
	int nRebate;
};

//	�����շ���
class CCashReturn : public CCashSuper{
public:
	CCashReturn(int nConValue, int nRetValue)
	{
		cout << "�����շ�  ���캯��" << endl;
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



//	CCashContext��
class CCashContext{
public:
	CCashContext(int nType)
	{
		pcCash = NULL;
		switch(nType)
		{
		case (1):			//	��ͨ
			pcCash = new CCashNormal();
			break;
		case (2):			//	�����
			pcCash = new CCashRebate(80);
			break;
		case (3):			//	��300��100
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
