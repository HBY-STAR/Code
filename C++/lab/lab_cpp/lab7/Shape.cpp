#include <iostream>

using namespace std;

//这里定义了π的值
const float pai = 3.1415926;

// 抽象类
class Shape
{
public:
	virtual float area() const // 计算面积
	{
		return 0.0;
	}
	virtual float volume() const // 计算体积
	{
		return 0.0;
	}
	virtual void shapeName() const = 0; // 纯虚函数 ——形状名
};

//声明"点"类
class Point : public Shape
{
public:
	Point(float = 0, float = 0);   //构造函数
	void setPoint(float, float);   //设置点的坐标x,y
	float getX() const;			   //获取 x 坐标
	float getY() const;			   //获取 y 坐标
	virtual void shapeName() const //输出形状名
	{
		cout << "Point:";
	}
	// 重载操作符 <<，使得能够用 cout<< 来输出成员变量
	friend ostream &operator<<(ostream &, const Point &);

protected:
	float x, y; // 点的坐标x,y
};

// 声明"圆"类
class Circle : public Point
{
public:
	Circle(float x = 0, float y = 0, float r = 0); //构造函数
	void setRadius(float);						   //设置圆的半径radius
	float GetRadius() const;					   //获得圆的半径radius
	virtual float area() const;					   //计算圆的面积
	virtual void shapeName() const				   //输出形状名
	{
		cout << "Circle:";
	}
	// 重载操作符 <<，使得能够用 cout<< 来输出成员变量
	friend ostream &operator<<(ostream &, const Circle &);

protected:
	float radius; // 圆的半径
};

// 声明"圆柱"类
class Cylinder : public Circle
{
public:
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0); //构造函数
	void setHeight(float h);									  //设置圆柱的高height
	float GetHeight();											  //获取圆柱的高height
	virtual float area() const;									  //计算圆柱的表面积
	virtual float volume() const;								  //计算圆柱的体积
	virtual void shapeName() const								  //输出形状名
	{
		cout << "Cylinder:";
	}
	// 重载操作符 <<，使得能够用 cout<< 来输出成员变量
	friend ostream &operator<<(ostream &, const Cylinder &);

protected:
	float height; // 圆柱的高度
};

int main()
{
	Point point(1.1, 2.2);
	Circle circle(3.3, 4.4, 5.5);
	Cylinder cylinder(6.6, 7.7, 8.8, 9.9);
	// 补全调用部分，静态关联，直接调用各个 shapeName，输出各个成员变量（直接用 cout）
	point.shapeName();
	cout << point << endl;
	circle.shapeName();
	cout << circle << endl;
	cylinder.shapeName();
	cout << cylinder << endl;

	Shape *pt;
	// 补全调用部分，使用基类指针进行动态关联
	pt = &point;
	pt->shapeName();
	cout << " x: " << point.getX() << " y: " << point.getY() << endl;
	pt = &circle;
	pt->shapeName();
	cout << " x: " << circle.getX() << " y: " << circle.getY() << " radius: " << circle.GetRadius() << endl;
	pt = &cylinder;
	pt->shapeName();
	cout << " x: " << cylinder.getX() << " y: " << cylinder.getY() << " radius: " << cylinder.GetRadius() << " height: " << cylinder.GetHeight() << endl;
	return 0;
}
/*****************************Point**********************************/
Point::Point(float X, float Y)
{
	x = X;
	y = Y;
}
void Point::setPoint(float X, float Y)
{
	x = X;
	y = Y;
}
float Point::getX() const
{
	return x;
}
float Point::getY() const
{
	return y;
}
ostream &operator<<(ostream &output, const Point &point)
{
	output << " x: " << point.x << " y: " << point.y;
	return output;
}
/********************************************************************/

/****************************Circle**********************************/
Circle::Circle(float X, float Y, float R)
{
	x = X;
	y = Y;
	radius = R;
}
void Circle::setRadius(float R)
{
	radius = R;
}
float Circle::GetRadius() const
{
	return radius;
}
float Circle::area() const
{
	return pai * radius * radius;
}
ostream &operator<<(ostream &output, const Circle &circle)
{
	output << " x: " << circle.x << " y: " << circle.y << " radius: " << circle.radius;
	return output;
}
/********************************************************************/

/***************************Cylinder*********************************/
Cylinder::Cylinder(float X, float Y, float R, float H)
{
	x = X;
	y = Y;
	radius = R;
	height = H;
}
void Cylinder::setHeight(float H)
{
	height = H;
}
float Cylinder::GetHeight()
{
	return height;
}
float Cylinder::area() const
{
	return pai * radius * radius * 2.0 + 2.0 * pai * radius * height;
}
float Cylinder::volume() const
{
	return pai * radius * radius * height;
}
ostream &operator<<(ostream &output, const Cylinder &cylinder)
{
	output << " x: " << cylinder.x << " y: " << cylinder.y << " radius: " << cylinder.radius << " height: " << cylinder.height;
	return output;
}
/********************************************************************/