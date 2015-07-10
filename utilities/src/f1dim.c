extern int ncom;	/* defined in LINMIN */
extern double *pcom,*xicom,(*nrfunc)();

double my_f1dim(x)
double x;
{
	int j;
	double f,*xt,*my_vector();
	void my_free_vector();

	xt=my_vector(1,ncom);
	for (j=1;j<=ncom;j++) xt[j]=pcom[j]+x*xicom[j];
	f=(*nrfunc)(xt);
	my_free_vector(xt,1,ncom);
	return f;
}
