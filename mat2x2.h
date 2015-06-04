#pragma once

class Fab {
public:
	Fab();
	__int64 fibm(short n); //start
	struct mtx2x2 { __int64 _11 = 0, _12 = 0, _21 = 0, _22 = 0; };
	friend mtx2x2 operator*(Fab::mtx2x2 lhs, Fab::mtx2x2 rhs);
	mtx2x2 IntPower(mtx2x2 x, short power);
private:
	mtx2x2 fibMtx;
	mtx2x2 identity;
};

Fab::Fab() {
	fibMtx._11 = 1;
	fibMtx._12 = 1;
	fibMtx._21 = 1;

	identity._11 = 1;
	identity._22 = 1;
}

Fab::mtx2x2 operator*(Fab::mtx2x2 lhs, Fab::mtx2x2 rhs) {
	Fab::mtx2x2 out;
	out._11 = lhs._11*rhs._11 + lhs._12*rhs._21;
	out._12 = lhs._11*rhs._12 + lhs._12*rhs._22;
	out._21 = lhs._21*rhs._11 + lhs._22*rhs._21;
	out._22 = lhs._21*rhs._12 + lhs._22*rhs._22;
	return out;
}

Fab::mtx2x2 Fab::IntPower(mtx2x2 x, short power)
{
	if (power == 0) return identity;
	if (power == 1) return x;
	int n = 15;
	while ((power <<= 1) >= 0) n--;
	mtx2x2 tmp = x;
	while (--n > 0)
		tmp = (tmp * tmp) * (((power <<= 1) < 0) ? x : identity);
	return tmp;
}

__int64 Fab::fibm(short n)
{
	return IntPower(fibMtx, (short)(n - 1))._11;
}