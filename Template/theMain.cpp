#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//テンプレート 型をパラメータにとっていろいろな型に対応できる機能
//             多態性の一つ（同じ関数や、クラスをいろんな型に対応させられる）

//オーバーロードで書く
//２つの整数のうち大きい方を返す
int myMax(int a, int b);
//２つの単精度実数（float）のうち大きい方を返す
float myMax(float a, float b);
//２つの倍精度実数（double）のうち大きい方を返す
double myMax(double a, double b);

int myMax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

float myMax(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

double myMax(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

//クラステンプレート
template <typename T>
class Vec2
{
	T x;
	T y;
public:
	T GetX() { return (x); }
	void SetX(T _x) { x = _x; }
	T GetY() { return (y); }
	void SetY(T _y) { y = _y; }
	T Length()const { return (sqrt(x * x + y * y)); }

	bool operator>(const Vec2<T>& other) {
		return (this->Length() > other.Length());
	}

	T tMax(T a, T b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	void PrintVec() { cout << "(x, y) = (" << x << ", " << y <<")"<< endl; }
};

//関数テンプレート
template<typename T>//型に指定できるのはintやfloatなどのプリミティブ型だけ 戻り値と引数がすべて一致しているときに使える
T tMax(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
//tMax<int>(10,20)
//tMax<double>(0.6,0.8)

int main()
{
//	int var1 = 10;
//	int var2 = 20;
//	int res = tMax<int>(var1, var2);
////	int res = myMax(var1, var2);
//	cout << "myMax 10 20 : " << res << endl;
//	
//	float var3 = 34.2;
//	float var4 = 25.6;
//	float res2 = tMax<float>(var3, var4);
////	float res2 = myMax(var3, var4);
//	cout << "myMax var3 var4 : " << res2 << endl;
//
//	double var5 = 0.0000035;
//	double var6 = 1e-15;//10のマイナス１５乗
//	double res3 = tMax<double>(var5, var6);
////	double res3 = myMax(var5, var6);
//	cout << "myMax var5 var6 : " << res3 << endl;

	Vec2<double> v1,v2;
	v1.SetX(3.5);
	v1.SetY(3.5);
	v2.SetX(6.5);
	v2.SetY(6.5);
	std::cout << "v1";
	v1.PrintVec();
	std::cout << "v2";
	v2.PrintVec();
	std::cout << "長いほうのベクトルの長さは" << v1.tMax(v1.Length(), v2.Length()) << endl;

	return 0;
}
