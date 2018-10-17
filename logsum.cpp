#include <stdio.h>
#include <math.h>

template<typename T>
T logsum(T logA, T logB){
	if ( !std::isfinite(logA) ) return logA<0 ? logB : INFINITY;
	if ( !std::isfinite(logB) ) return logB<0 ? logA : INFINITY;
	if (logA < logB){
		return logB + std::log(1+std::exp(logA-logB));
	} else {
		return logA + std::log(1+std::exp(logB-logA));
	}
}

int main(){
	float logA = 0.5;
	float logB = 1.3;
	printf(" Obtained %f %f\n",std::exp(logsum(logB,logA)),std::exp(logA)+std::exp(logB));
	logA = -INFINITY;
	logB = 1.3;
	printf(" Obtained %f %f\n",std::exp(logsum(logB,logA)),std::exp(logA)+std::exp(logB));
	return 0;
}
