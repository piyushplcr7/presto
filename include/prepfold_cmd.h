#ifndef __prepfold_cmd__
#define __prepfold_cmd__
/*****
  command line parser interface -- generated by clig 
  (http://wsd.iitb.fhg.de/~geg/clighome/)

  The command line parser `clig':
  (C) 1995-2004 Harald Kirsch (clig@geggus.net)
*****/

typedef struct s_Cmdline {
  /***** -ncpus: Number of processors to use with OpenMP */
  char ncpusP;
  int ncpus;
  int ncpusC;
  /***** -o: Root of the output file names */
  char outfileP;
  char* outfile;
  int outfileC;
  /***** -filterbank: Raw data in SIGPROC filterbank format */
  char filterbankP;
  /***** -psrfits: Raw data in PSRFITS format */
  char psrfitsP;
  /***** -noweights: Do not apply PSRFITS weights */
  char noweightsP;
  /***** -noscales: Do not apply PSRFITS scales */
  char noscalesP;
  /***** -nooffsets: Do not apply PSRFITS offsets */
  char nooffsetsP;
  /***** -wapp: Raw data in Wideband Arecibo Pulsar Processor (WAPP) format */
  char wappP;
  /***** -window: Window correlator lags with a Hamming window before FFTing */
  char windowP;
  /***** -topo: Fold the data topocentrically (i.e. don't barycenter) */
  char topoP;
  /***** -invert: For rawdata, flip (or invert) the band */
  char invertP;
  /***** -zerodm: Subtract the mean of all channels from each sample (i.e. remove zero DM) */
  char zerodmP;
  /***** -absphase: Use the absolute phase associated with polycos */
  char absphaseP;
  /***** -barypolycos: Force the use of polycos for barycentered events */
  char barypolycosP;
  /***** -debug: Show debugging output when calling TEMPO for polycos */
  char debugP;
  /***** -samples: Treat the data as samples and not as finite-duration integrated data */
  char samplesP;
  /***** -normalize: Bandpass flatten the data by normalizing the subbands */
  char normalizeP;
  /***** -numwapps: Number of WAPPs used with contiguous frequencies */
  char numwappsP;
  int numwapps;
  int numwappsC;
  /***** -if: A specific IF to use if available (summed IFs is the default) */
  char ifsP;
  int ifs;
  int ifsC;
  /***** -clip: Time-domain sigma to use for clipping (0.0 = no clipping, 6.0 = default */
  char clipP;
  float clip;
  int clipC;
  /***** -noclip: Do not clip the data.  (The default is to _always_ clip!) */
  char noclipP;
  /***** -noxwin: Do not show the result plots on-screen, only make postscript files */
  char noxwinP;
  /***** -runavg: Subtract each blocks average as it is read (single channel data only) */
  char runavgP;
  /***** -fine: A finer gridding in the p/pdot plane (for well known p and pdot) */
  char fineP;
  /***** -coarse: A coarser gridding in the p/pdot plane (for uknown p and pdot) */
  char coarseP;
  /***** -slow: Sets useful flags for slow pulsars */
  char slowP;
  /***** -searchpdd: Search p-dotdots as well as p and p-dots */
  char searchpddP;
  /***** -searchfdd: Search f-dotdots as well as f and f-dots */
  char searchfddP;
  /***** -nosearch: Show but do not search the p/pdot and/or DM phase spaces */
  char nosearchP;
  /***** -nopsearch: Show but do not search over period */
  char nopsearchP;
  /***** -nopdsearch: Show but do not search over p-dot */
  char nopdsearchP;
  /***** -nodmsearch: Show but do not search over DM */
  char nodmsearchP;
  /***** -scaleparts: Scale the part profiles independently */
  char scalepartsP;
  /***** -allgrey: Make all the images greyscale instead of color */
  char allgreyP;
  /***** -fixchi: Adjust the reduced chi^2 values so that off-pulse reduced chi^2 = 1 */
  char fixchiP;
  /***** -justprofs: Only output the profile portions of the plot */
  char justprofsP;
  /***** -dm: The central DM of the search (cm^-3 pc) */
  char dmP;
  double dm;
  int dmC;
  /***** -n: The number of bins in the profile.  Defaults to the number of sampling bins which correspond to one folded period */
  char proflenP;
  int proflen;
  int proflenC;
  /***** -nsub: The number of sub-bands to use for the DM search.  If unspecified, will use something reasonable. */
  char nsubP;
  int nsub;
  int nsubC;
  /***** -npart: The number of sub-integrations to use for the period search */
  char npartP;
  int npart;
  int npartC;
  /***** -pstep: The minimum period stepsize over the observation in profile bins */
  char pstepP;
  int pstep;
  int pstepC;
  /***** -pdstep: The minimum P-dot stepsize over the observation in profile bins */
  char pdstepP;
  int pdstep;
  int pdstepC;
  /***** -dmstep: The minimum DM stepsize over the observation in profile bins */
  char dmstepP;
  int dmstep;
  int dmstepC;
  /***** -npfact: 2 * npfact * proflen + 1 periods and p-dots will be searched */
  char npfactP;
  int npfact;
  int npfactC;
  /***** -ndmfact: 2 * ndmfact * proflen + 1 DMs will be searched */
  char ndmfactP;
  int ndmfact;
  int ndmfactC;
  /***** -p: The nominative folding period (s) */
  char pP;
  double p;
  int pC;
  /***** -pd: The nominative period derivative (s/s) */
  char pdP;
  double pd;
  int pdC;
  /***** -pdd: The nominative period 2nd derivative (s/s^2) */
  char pddP;
  double pdd;
  int pddC;
  /***** -f: The nominative folding frequency (hz) */
  char fP;
  double f;
  int fC;
  /***** -fd: The nominative frequency derivative (hz/s) */
  char fdP;
  double fd;
  int fdC;
  /***** -fdd: The nominative frequency 2nd derivative (hz/s^2) */
  char fddP;
  double fdd;
  int fddC;
  /***** -pfact: A factor to multiple the candidate p and p-dot by */
  char pfactP;
  double pfact;
  int pfactC;
  /***** -ffact: A factor to multiple the candidate f and f-dot by */
  char ffactP;
  double ffact;
  int ffactC;
  /***** -phs: Offset phase for the profil */
  char phsP;
  double phs;
  int phsC;
  /***** -start: The folding start time as a fraction of the full obs */
  char startTP;
  double startT;
  int startTC;
  /***** -end: The folding end time as a fraction of the full obs */
  char endTP;
  double endT;
  int endTC;
  /***** -psr: Name of pulsar to fold (do not include J or B) */
  char psrnameP;
  char* psrname;
  int psrnameC;
  /***** -par: Name of a TEMPO par file from which to get PSR params */
  char parnameP;
  char* parname;
  int parnameC;
  /***** -polycos: File containing TEMPO polycos for psrname (not required) */
  char polycofileP;
  char* polycofile;
  int polycofileC;
  /***** -timing: Sets useful flags for TOA generation. Generates polycos (if required) based on the par file specified as the argument. (This means you don't need the -par or -psr commands!) */
  char timingP;
  char* timing;
  int timingC;
  /***** -rzwcand: The candidate number to fold from 'infile'_rzw.cand */
  char rzwcandP;
  int rzwcand;
  int rzwcandC;
  /***** -rzwfile: Name of the rzw search '.cand' file to use (with suffix) */
  char rzwfileP;
  char* rzwfile;
  int rzwfileC;
  /***** -accelcand: The candidate number to fold from 'infile'_rzw.cand */
  char accelcandP;
  int accelcand;
  int accelcandC;
  /***** -accelfile: Name of the accel search '.cand' file to use (with suffix) */
  char accelfileP;
  char* accelfile;
  int accelfileC;
  /***** -bin: Fold a binary pulsar.  Must include all of the following parameters */
  char binaryP;
  /***** -pb: The orbital period (s) */
  char pbP;
  double pb;
  int pbC;
  /***** -x: The projected orbital semi-major axis (lt-sec) */
  char asinicP;
  double asinic;
  int asinicC;
  /***** -e: The orbital eccentricity */
  char eP;
  double e;
  int eC;
  /***** -To: The time of periastron passage (MJD) */
  char ToP;
  double To;
  int ToC;
  /***** -w: Longitude of periastron (deg) */
  char wP;
  double w;
  int wC;
  /***** -wdot: Rate of advance of periastron (deg/yr) */
  char wdotP;
  double wdot;
  int wdotC;
  /***** -mask: File containing masking information to use */
  char maskfileP;
  char* maskfile;
  int maskfileC;
  /***** -ignorechan: Comma separated string (no spaces!) of channels to ignore (or file containing such string).  Ranges are specified by min:max[:step] */
  char ignorechanstrP;
  char* ignorechanstr;
  int ignorechanstrC;
  /***** -events: Use a event file instead of a time series (.dat) file */
  char eventsP;
  /***** -days: Events are in days since the EPOCH in the '.inf' file (default is seconds) */
  char daysP;
  /***** -mjds: Events are in MJDs */
  char mjdsP;
  /***** -double: Events are in binary double precision (default is ASCII) */
  char doubleP;
  /***** -offset: A time offset to add to the 1st event in the same units as the events */
  char offsetP;
  double offset;
  int offsetC;
  /***** uninterpreted command line parameters */
  int argc;
  /*@null*/char **argv;
  /***** the whole command line concatenated */
  char *full_cmd_line;
} Cmdline;


extern char *Program;
extern void usage(void);
extern /*@shared*/Cmdline *parseCmdline(int argc, char **argv);

extern void showOptionValues(void);

#endif

