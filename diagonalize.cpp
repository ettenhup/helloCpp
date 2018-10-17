#include <iostream>
#include <vector>

// compile and link: g++ diagnoalize.cpp -L/opt/intel/mkl/lib/intel64 -Wl,--no-as-needed -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl


extern "C" void dsygv(int *ITYPE, char *JOBZ, char *UPLO, int *N, double *A,
                      int *LDA, double *B, int *LDB, double *W, double *WORK, 
                      int *LWORK, int *INFO );


int main ()
{
	char trans = 'N';
	int dim = 2;
	int nrhs = 1;
	int LDA = dim;
	int LDB = dim;
	int info;

	std::vector<double> a, b;

	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(-1);

	b.push_back(2);
	b.push_back(0);

	int ipiv[3];

	dgsygv(&dim, &dim, &*a.begin(), &LDA, ipiv, &info);

	std::cout << "solution is:";
	std::cout << "[" << b[0] << ", " << b[1] << ", " << "]" << std::endl;
	std::cout << "Info = " << info << std::endl;

	return(0);
}
