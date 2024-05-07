#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//�e���v���[�g �^���p�����[�^�ɂƂ��Ă��낢��Ȍ^�ɑΉ��ł���@�\
//             ���Ԑ��̈�i�����֐���A�N���X�������Ȍ^�ɑΉ���������j�A

//�I�[�o�[���[�h�ŏ���
//�Q�̐����̂����傫������Ԃ�
int myMax(int a, int b);
//�Q�̒P���x�����ifloat�j�̂����傫������Ԃ�
float myMax(float a, float b);
//�Q�̔{���x�����idouble�j�̂����傫������Ԃ�
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

//�N���X�e���v���[�g
template <typename T>
class Vec2
{
	T x;
	T y;
public:
	inline T GetX() { return x; }
	inline void SetX(T _x) { x = _x; }
	inline T GetY() { return y; }
	inline void SetY(T _y) { y = _y; }
	inline T Length()const { return sqrt(x * x + y * y); }
	inline bool operator>(const Vec2& other)const {
		return Length() > other.Length();
	}
	inline T tMax(T a, T b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	inline void PrintVec() { cout << "(x, y) = (" << x << ", " << y <<")"<< endl; }
};

//�֐��e���v���[�g
template<typename T>//�^�Ɏw��ł���̂�int��float�Ȃǂ̃v���~�e�B�u�^���� �߂�l�ƈ��������ׂĈ�v���Ă���Ƃ��Ɏg����
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
//	double var6 = 1e-15;//10�̃}�C�i�X�P�T��
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
	std::cout << "�����ق��̃x�N�g���̒�����" << v1.tMax(v1.Length(), v2.Length()) << endl;

	return 0;
}
