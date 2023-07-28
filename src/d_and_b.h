#pragma once
#include <Arduino.h>

String getDAndBtoMan(double lat, double lon);

String getRadial( double bearing );
String getAnnular(double bearing, double distance);
static double calcDistance(double lat1, double lon1,
                        double lat2, double lon2);
static double calcBearing(double lat1,double lon1,double lat2,double lon2);