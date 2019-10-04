#include "pch.h"
#include "Tamgiac.h"

Tamgiac::Tamgiac()
{
}
Tamgiac::Tamgiac(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 = (p1.x + p2.x) / 2;
	y1 = p1.y;
	x2 = p1.x;
	y2 = p2.y;
	x3 = p2.x;
	y3 = p2.y;

}
Tamgiac::Tamgiac(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1;
	x2 = mx2;
	x3 = mx3;
	y1 = my1;
	y2 = my2;
	y3 = my3;
}
void Tamgiac::thietlap(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1;
	x2 = mx2;
	x3 = mx3;
	y1 = my1;
	y2 = my2;
	y3 = my3;
}
CPoint Tamgiac::getA()
{
	return CPoint(x1, y1);
}
CPoint Tamgiac::getB()
{
	return CPoint(x2, y2);
}
CPoint Tamgiac::getC()
{
	return CPoint(x3, y3);
}
void Tamgiac::draw(CClientDC* pdc)
{
	pdc->MoveTo(x1, y1);

	//CString ta, tb, tc;
	//ta.Format(_T("(%d,%d)"), x1, y1);
	//tb.Format(_T("(%d,%d)"), x2, y2);
	//tc.Format(_T("(%d,%d)"), x3, y3);

	pdc->LineTo(x2, y2);
	pdc->LineTo(x3, y3);
	pdc->LineTo(x1, y1);
	//tc.Format(_T("%f"), dientich());
}
float Tamgiac::dientich()
{
	float s = 0;
	float p = 0;
	s = (float)((0.5) * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)));
	return s;
}

int Tamgiac::tronghinh(CPoint p)
{
	Tamgiac tg1, tg2, tg3;
	tg1.thietlap(x1, y1, x2, y2, p.x, p.y);
	tg2.thietlap(x2, y2, x3, y3, p.x, p.y);
	tg3.thietlap(x3, y3, x1, y1, p.x, p.y);
	int kq = -1;
	if ((tg1.dientich() + tg2.dientich() + tg3.dientich()) == dientich())
		kq = 1;
	return kq;
}
void Tamgiac::dichuyeny(int my)
{
	y1 += my;
	y2 += my;
	y3 += my;
}
void Tamgiac::dichuyenx(int mx)
{
	x1 += mx;
	x2 += mx;
	x3 += mx;
}
void Tamgiac::dichuyen(int mx, int my)
{
	y1 += my;
	y2 += my;
	y3 += my;
	x1 += mx;
	x2 += mx;
	x3 += mx;
}

Tamgiac::~Tamgiac()
{
}
