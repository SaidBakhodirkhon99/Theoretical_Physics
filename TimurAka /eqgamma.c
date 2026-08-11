
#include <math.h>
void equations(double varst[], double diffs[], double impact_par, double parbh[])
{

      double r, th;
      double kt, kphi;
      double kt2, kr2, kth2, kp2, ktp, krth;
      double ch_rtt, ch_rtp, ch_rrr, ch_rrth, ch_rthth, ch_rpp;
      double ch_thtt, ch_thtp, ch_thrr, ch_thrth, ch_ththth, ch_thpp;
      double gtt, gtp, gurr, guthth, gpp;
      double dgttdr, dgtpdr, dgrrdr, dgrrdth, dgththdr, dgppdr, dgttdth, dgtpdth, dgththdth, dgppdth;
      double hgurr, hguthth;
      double denom;




	// par
	double mpar = parbh[0];
	double qpar = parbh[1];
      	r = varst[0];
      	th = varst[1];

   
      
     	double t2 = 1/r;
 	double t3 = 1/mpar;
 	double t5 = pow(qpar,2);
 	double t6 = (t2*t3*t5)/2.;
 	double t7 = tanh(t6);
 	double t8 = -t7;
 	double t9 = 1 + t8;
 	double t18 = pow(r,-2);
 	double t19 = pow(r,-3);
 	double t20 = 1.0 / cosh(t6);
 	double t21 = pow(t20,2);
 	double t16 = -2*mpar*t2*t9;
 	double t17 = 1 + t16;
 	double t13 = sin(th);
 	double t14 = pow(t13,2);
 	double t12 = pow(r,2);


      gtt = -1 + 2*mpar*t2*t9;
      gpp = t12*t14;
      gtp = 0;
      gurr = t17;
      guthth = t18;
      dgttdr = t19*t21*t5 - 2*mpar*t18*t9;
      dgrrdr = -((-(t19*t21*t5) + 2*mpar*t18*t9)/pow(t17,2));
      dgththdr = 2*r;
      dgppdr = 2*r*t14;;
      dgtpdr = 0;
      dgttdth = 0;
      dgrrdth = 0;
      dgththdth = 0;
      dgppdth = 2*t12*t13*cos(th);
      dgtpdth = 0;


                        
      hgurr = 0.5*gurr;
      hguthth = 0.5*guthth;
      
      ch_rtt = -hgurr*dgttdr;
      
      ch_rtp = -hgurr*dgtpdr;
      
      ch_rrr = hgurr*dgrrdr;
      
      ch_rrth = hgurr*dgrrdth;
      
      ch_rthth = -hgurr*dgththdr;
      
      ch_rpp = -hgurr*dgppdr;
      
      ch_thtt = -hguthth*dgttdth;
      
      ch_thtp = -hguthth*dgtpdth;
      
      ch_thrr = -hguthth*dgrrdth;
      
      ch_thrth = hguthth*dgththdr;
      
      ch_ththth = hguthth*dgththdth;
      
      ch_thpp = -hguthth*dgppdth;
      
      denom = (gtt*gpp-gtp*gtp);
      
      kt = -(gpp+impact_par*gtp)/denom;
      
      kphi = (gtp+impact_par*gtt)/denom;

      diffs[4] = kphi;
      
     // KPHI=kphi;
      //printf("%f  %f \n",kphi,vars[0]);

      diffs[0] = varst[2];
      //KR = vars[2];
      
      diffs[1] = varst[3];
      
      kt2 = kt*kt;
      kr2 = varst[2]*varst[2];
      kth2 = varst[3]*varst[3];
      kp2 = kphi*kphi;
      ktp = kt*kphi;
      krth = varst[2]*varst[3];
      
      diffs[2] = -(ch_rtt*kt2+ch_rrr*kr2+ch_rthth*kth2+ch_rpp*kp2+2.0*(ch_rtp*ktp+ch_rrth*krth));
                        
      diffs[3] = -(ch_thtt*kt2+ch_thrr*kr2+ch_ththth*kth2+ch_thpp*kp2+2.0*(ch_thtp*ktp+ch_thrth*krth));
}
