#include "d_and_b.h"
#include "config.h"

String getDAndBtoMan(double lat, double lon) {
    if ( lat == 0.0 && lon == 0.0 ) {
        return "UNKNOWN";
    }
    String ret = "";
    double bearing = calcBearing(MAN_LAT, MAN_LON, lat, lon);
    bearing += MAN_OFFSET;
    double distance = calcDistance(MAN_LAT, MAN_LON, lat, lon);
    ret = getRadial(bearing) + " &\n" + getAnnular(bearing,distance);
    return ret;
}

String getRadial( double bearing ) {
    double t = (bearing / 360.0) * 12.0;
    int h = (int)(floor(t));
    if ( h < 0 ) h+=12;
    double m = (t - h) * 60.0;
    if ( m < 0 ) m+=720;
    int minutes = (int)(round(m));
    char buffer[4];
    if ( minutes == 60 ) {
        minutes = 0;
        h+=1;
    }
    if ( h == 0 ) {
        h = 12;
    }
    sprintf(buffer, "%d:%02d", h, minutes);
    return buffer;
}

String getAnnular(double bearing, double distance) {

    int d = (int)(round(distance));
    if ( bearing < 45 || bearing > 315 ) {
        return String(d);
    }
    if ( d < 2480 || d >5870 ) {
        return String(d);
    } 
    if ( d <= 2740 ) return("Esplanade");
    if ( d <= 3085 ) return("A");
    if ( d <= 3395 ) return("B");
    if ( d <= 3665 ) return("C");
    if ( d <= 3955 ) return("D");
    if ( d <= 4345 ) return("E");
    if ( d <= 4735 ) return("F");
    if ( d <= 5025 ) return("G");
    if ( d <= 5315 ) return("H");
    if ( d <= 5555 ) return("I");
    if ( d <= 5745 ) return("J");
    if ( d <= 5870 ) return("K");
    return "Unknown!";
}

static double calcDistance(double lat1, double lon1,
                        double lat2, double lon2) {
    // distance between latitudes and longitudes
    double dLat = (lat2 - lat1) *
                    M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                    M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
                pow(sin(dLon / 2), 2) *
                cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    // we want this in feet, so multiple by feet-to-meters
    return (rad * c) * 3280.84;
}

static double calcBearing(double lat1,double lon1,double lat2,double lon2){
    double teta1 = radians(lat1);
    double teta2 = radians(lat2);
    double delta1 = radians(lat2-lat1);
    double delta2 = radians(lon2-lon1);

    //==================Heading Formula Calculation================//

    double y = sin(delta2) * cos(teta2);
    double x = cos(teta1)*sin(teta2) - sin(teta1)*cos(teta2)*cos(delta2);
    double brng = atan2(y,x);
    brng = degrees(brng);// radians to degrees
    brng = ( ((int)brng + 360) % 360 ); 
    return brng;
}