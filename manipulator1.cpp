#include <iostream>
using namespace std;

/*Есть два манипулятора. Их инструменты находятся в точках О1 и О2 в декартовой системе координат (X, Y).
У каждого манипулятора есть свой радиус эффективного действия R1 и R2. 
Есть точка P1 - точка. Определите, каким манипулятором лучше дойти до точки P1
Если оба манипулятора не могут достать, то вывести OUT RANGE.
Если точка доступна одному манипулятору - то использовать его
*/
/*Пусть  xm, ym - координаты манипулятора, а xp, yp - координаты точки, до которой манипулятору нужно дотянуться
Пишу класс distance, который будет вычислять кратчайшее расстояние до точки от манипулятора. Перегружаю операторы сравнения, чтобы можно
было определить каким из манипуляторов к ней лучше тянуться
*/
class Distance
{
	double xm, ym, xp, yp;
public:
	Distance(double, double, double, double);
	bool operator ==(const Distance&)const;
	bool operator <(const Distance&)const;
	bool operator>(const Distance&)const;

	bool operator ==(const double )const;
	bool operator <(const double)const;
	bool operator>(const double)const;
};

Distance::Distance(double xm, double ym, double xp, double yp)
{
	this->xm = xm;
	this->xp = xp;
	this->ym = ym;
	this->yp = yp;
}

/*если предположить, что манипулятор может двигаться по прямой в любом направлении, то можна воспользоваться теоремой Пифагора, 
по нахождению расстояния. Корень можно не извлекать, поскольку нам требуется определить что ближе, а не значение расстояния.
*/
bool Distance::operator==(const Distance& rv) const
{
	if ((xm -xp)*(xm-xp) + (ym-yp) *( ym-yp) == (rv.xm-rv.xp) *(rv.xm-rv.xp) + (rv.ym-rv.yp) *(rv.ym-rv.yp))
	{return true; }
	return false;
}

bool Distance::operator==(const double rv) const
{
	if ((xm - xp) * (xm - xp) + (ym - yp) * (ym - yp) == rv*rv)
	{
		return true;
	}
	return false;
}

bool Distance::operator <( const Distance& rv) const
{
	if ((xm - xp) * (xm - xp) + (ym - yp) * (ym - yp) < (rv.xm - rv.xp) * (rv.xm - rv.xp) + (rv.ym - rv.yp) * (rv.ym - rv.yp))
	{
		return true;
	}
	return false;
}

bool Distance::operator < (const double rv) const
{
	if ((xm - xp) * (xm - xp) + (ym - yp) * (ym - yp) < rv*rv)
	{
		return true;
	}
	return false;
}

bool Distance::operator > (const Distance& rv) const
{
	if ((xm - xp) * (xm - xp) + (ym - yp) * (ym - yp) > (rv.xm - rv.xp) * (rv.xm - rv.xp) + (rv.ym - rv.yp) * (rv.ym - rv.yp))
	{
		return true;
	}
	return false;
}

bool Distance::operator > (const double rv) const
{
	if ((xm - xp) * (xm - xp) + (ym - yp) * (ym - yp) > rv*rv)
	{
		return true;
	}
	return false;
}


int main()
{
	setlocale(LC_ALL, "rus");

	double xm_1, xm_2, xp, ym_1, ym_2, yp;
	double r1, r2;
	cout << "Введите координаты первого манипулятора: " << endl<<"x = ";
	cin >> xm_1;
	cout << "y = ";
	cin >> ym_1;
	cout << "Теперь радиус эффективного действия первого манипулятора: " << endl << "r1 = ";
	cin >> r1;
	cout << "Введите координаты второго манипулятора:" << endl << "x = ";
	cin >> xm_2;
	cout<< "y = ";
cin >> ym_2;
cout << "Теперь радиус эффективного действия второго манипулятора: " << endl << "r2 = ";
cin >> r2;
	cout << "Введите координаты точки, до которой должен добраться один из манипуляторов:" << endl<<"x = ";
	cin >> xp;
	cout << "y = ";
	cin >> yp;

	Distance d1(xm_1, ym_1, xp, yp), d2(xm_2, ym_2, xp, yp);

	if (d1 > r1 && d2 > r2)
	{
		cout << "OUT RANGE" << endl;
	}
	else if (!(d1 > r1) && d2 >  r2)
	{
		cout << "используем манипулятор номер 1" << endl;
	}
	else if (d1 > r1 && !(d2 > r2))
	{
		cout << "используем манипулятор номер 2" << endl;
	}
	else {
		if (d1 < d2)
		{
			cout << "используем манипулятор номер 1 " << endl;
		}
		else if (d1 == d2)
		{
			cout << "Расстояние одинаковое, можно использовать любой из манипуляторов" << endl;
		}
		else if (d2 < d1)
		{
			cout << "используем манипулятор номер  2" << endl;
		}
	}
}

