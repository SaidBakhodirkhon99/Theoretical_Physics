#include <math.h>

void gmetric(double r, double th, double (*g)[4], double parbh[])
{
	double gtt, grr, gthth, gpp, gtp;

	double mpar = parbh[0];
	double qpar = parbh[1];
	


	double t2 = 1/r;
	double t3 = 1/mpar;
	double t5 = pow(qpar,2);
	double t6 = (t2*t3*t5)/2.;
	double t7 = tanh(t6);
	double t8 = -t7;
	double t9 = 1 + t8;
	double t15 = pow(r,2);

	gtt = -1 + 2*mpar*t2*t9;
	grr = 1/(1 - 2*mpar*t2*t9);
	gthth = t15;
	gpp = t15*pow(sin(th),2);
	gtp = 0;




	g[0][0] = gtt;
	g[0][3] = gtp;
	g[1][1] = grr;
	g[2][2] = gthth;
	g[3][0] = g[0][3];
	g[3][3] = gpp;
}

void metric_dr_dr2(double r, double th, double (*g)[4], double (*dg)[4], double (*dg2)[4], double mpar, double qpar)
{
	
	double gtt, grr, gthth, gpp, gtp, dgttdr, dgtpdr, dgppdr, dgttdr2, dgtpdr2, dgppdr2;

      
      
      double t2 = 1/r;
      double t3 = 1/mpar;
      double t5 = pow(qpar,2);
      double t6 = (t2*t3*t5)/2.;
      double t7 = tanh(t6);
      double t8 = -t7;
      double t9 = 1 + t8;
      double t15 = pow(r,2);
      double t16 = sin(th);
      double t17 = pow(t16,2);
      double t20 = 1.0 / cosh(t6);
      double t21 = pow(t20,2);
      double t19 = pow(r,-3);


	gtt = -1 + 2*mpar*t2*t9;
	grr = 1/(1 - 2*mpar*t2*t9);
	gthth = t15;
	gpp = t15*t17;
	gtp = 0;

	dgttdr = t19*t21*t5 - (2*mpar*t9)/pow(r,2);
	dgppdr = 2*r*t17;
	dgtpdr = 0;
	
	dgttdr2 = (-4*t21*t5)/pow(r,4) + (pow(qpar,4)*t21*t3*t7)/pow(r,5) + 4*mpar*t19*t9;
	dgppdr2 = 2*t17;
	dgtpdr2 = 0;




	g[0][0] = gtt;
	g[0][3] = gtp;
	g[1][1] = grr;
	g[2][2] = gthth;
	g[3][0] = g[0][3];
	g[3][3] = gpp;
	
 	dg[0][0] = dgttdr;
	dg[0][3] = dgtpdr;
	dg[3][0] = dg[0][3];
	dg[3][3] = dgppdr;

	dg2[0][0] = dgttdr2;
	dg2[0][3] = dgtpdr2;
	dg2[3][0] = dg2[0][3];
	dg2[3][3] = dgppdr2;
}

