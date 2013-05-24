#include <iostream>

#include "algebra_support.h"



int main (){
	

	RealVectorValue v1(1,0,0);
	RealVectorValue v2(0,1,0);
	
	RealVectorValue l1(1,2,3);
	RealVectorValue l2(4,5,6);
	RealVectorValue l3(7,8,9);
	
	//RealTensorValue m1(l1,l2,l3);
	
//	std::cout<<v1.cross(v2)<<std::endl;
	//std::cout<<m1.transpose()<<std::endl;
	//std::cout<<m1*v1<<std::endl;
	//std::cout<<"\n dyadic\n"<<dyad_prod(l1,l2)<<std::endl;
	
	
	
	
	//levi_civita test
	
	std::cout<<le_ci[0][1][2]<<" "<<le_ci[2][0][1]<<" "<<le_ci[1][2][0]<<std::endl;
	std::cout<<le_ci[0][2][1]<<" "<<le_ci[2][1][0]<<" "<<le_ci[1][0][2]<<std::endl;
	std::cout<<le_ci[0][1][0]<<" "<<le_ci[0][1][1]<<std::endl;
	
	
	std::cout<<"done\n";
	return 0;
}
