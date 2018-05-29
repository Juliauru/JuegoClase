#pragma once
class Vector {
public:
	float x;
	float y;


	Vector(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector();
	float modulo();
	float argumento();
	Vector unitario();
	Vector operator - (Vector &);
	Vector operator + (Vector &);
	Vector operator +(float a);
	float operator * (Vector &);
	Vector operator * (float);
	void setValor(float vx, float vy);	
};



