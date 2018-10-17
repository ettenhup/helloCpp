#include <iostream>
#include <vector>

// compile and link: g++ bindLapack.cpp -L/opt/intel/mkl/lib/intel64 -Wl,--no-as-needed -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl


extern "C" void dgetrf(int *M, int *N, double *A, int *LDA, int *IPIV, int *INFO );
extern "C" void dgetrs(char *TRANS, int *N, int *NRHS, double *A,
                      int *LDA, int *IPIV, double *B, int *LDB, int *INFO );


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

	dgetrf(&dim, &dim, &*a.begin(), &LDA, ipiv, &info);
	dgetrs(&trans, &dim, &nrhs, & *a.begin(), &LDA, ipiv, & *b.begin(), &LDB, &info);

	std::cout << "solution is:";
	std::cout << "[" << b[0] << ", " << b[1] << ", " << "]" << std::endl;
	std::cout << "Info = " << info << std::endl;

	return(0);
}
