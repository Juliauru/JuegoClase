#include "Vector.h"
#include <math.h>
Vector::Vector(float xv, float yv) {
	x = xv;
	y = yv;
}
Vector::~Vector() {

}
float Vector::modulo() {
	return (float)sqrt(x*x + y * y);
}
float Vector::argumento() {
	return (float)atan2(y, x);
}
Vector Vector::unitario() {
	Vector retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001) {
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}
Vector Vector::operator - (Vector &v) {
	Vector res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector Vector::operator + (Vector &v) {
	Vector res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}
Vector Vector::operator + (float a) {
	Vector res;
	res.x = x + a;
	res.y = y;
	return res;
}
float Vector::operator * (Vector &v) {
	float res;
	res = (x*v.x) + (y*v.y);
	return res;
}
Vector Vector::operator * (float p) {
	Vector res;
	res.x = x * p;
	res.y = y * p;
	return res;
}
void Vector::setValor(float vx, float vy) {
	x = vx;
	y = vy;
}