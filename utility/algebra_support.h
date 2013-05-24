//stolen from libmesh
//with slight changes

#include "vector_value.h"
#include "tensor_value.h"


//Constructs the dyadic product w = u x v where x is the tensor product
inline void dyad_prod(RealTensorValue& w, RealVectorValue& u, RealVectorValue& v)
{
	w(0,0) = u(0)*v(0); w(0,1) = u(0)*v(1); w(0,2) = u(0)*v(2); 
	w(1,0) = u(1)*v(0); w(1,1) = u(1)*v(1); w(1,2) = u(1)*v(2); 
	w(2,0) = u(2)*v(0); w(2,1) = u(2)*v(1); w(2,2) = u(2)*v(2); 
}

inline RealTensorValue dyad_prod(RealVectorValue& u, RealVectorValue& v)
{
	RealTensorValue w;
	w(0,0) = u(0)*v(0); w(0,1) = u(0)*v(1); w(0,2) = u(0)*v(2); 
	w(1,0) = u(1)*v(0); w(1,1) = u(1)*v(1); w(1,2) = u(1)*v(2); 
	w(2,0) = u(2)*v(0); w(2,1) = u(2)*v(1); w(2,2) = u(2)*v(2); 
	return w;
}

//PI
static double PI     = 3.14159265358979323846264338328;

//Levi-Civita Tensor
			//	__k____
			//	  1	2    3
const double le_ci[3][3][3] = {	{{0.0, 0.0, 0.0}, // 1
				{0.0, 0.0,+1.0}, //  2	j		//i=1
				{0.0,-1.0, 0.0}}, // 3
						
				{{0.0, 0.0,-1.0},
				{0.0, 0.0, 0.0},			//i=2
				{1.0, 0.0, 0.0}},
								
				{{0.0, 1.0, 0.0},
			       {-1.0, 0.0, 0.0},			//i=3
				{0.0, 0.0, 0.0}} };
/*
inline double levi(int i, int j, int k){
	double lev = (i-j)*(j-k)*(k-i)*0.5;
	return lev;
}*/

inline double sgn(double val){
	if(val>=0.0) return 1.0;
	else return -1.0;
}
