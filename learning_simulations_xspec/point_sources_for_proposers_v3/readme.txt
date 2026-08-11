These set of response and background files were generated using
NuSTAR observations. The ARF was generated using the "point" source
option. 

File nomenclature:

point_30arcsecRad_1arcminOA.arf = 
	"Point" source ARF
	Extracted using a circular extraction region with a radius of 30 arcseconds
	Off-axis angle is 1-arcminute
 
Similarly:
 
point_60arcsecRad_1arcminOA.arf = 
	"Point" source ARF
	Extracted using a circular extraction region with a radius of 60 arcseconds
	Off-axis angle is 1-arcminute

bgd_30arcsec.pha = Background for 30'' radius extraction region
nustar.rmf = Response file for sources near the optical axis.
 

To simulate an exposure, set up your model first, e.g.:

mo powerlaw
2.1
1.0

Adjust you flux to the desired level, e.g.:

We want 2-10 keV flux of 1e-12 ergs/cm^2/sec

flux 2 10
-> Model Flux    0.3525 photons (2.2295e-09 ergs/cm^2/s) range (2.0000 - 10.000 keV)

newpar 2 0.448e-2

flux 2 10
->  Model Flux 0.0015765 photons (9.9562e-12 ergs/cm^2/s) range (2.0000 - 10.000 keV)

Now, do a simulation using fakeit. The correct responses are shown below for
the queries assuming a weak source at 1 arcminute off-axis with a 30 ks exposure:

XSPEC12> fakeit bgd_30arcsec.pha
For fake spectrum #1 response file is needed: nustar.rmf
   ...and ancillary file: point_30arcsecRad_1arcminOA.arf
 Use counting statistics in creating fake data? (y): y
 Input optional fake file prefix: weak_source_1arcminOA
 Fake data file name (nobgdtest2.fak.fak): weak_source_1arcminOA.fak
 Exposure time, correction norm, bkg exposure time (1.00000, 1.00000, 1.00000): 30e3, 1, 30e3


