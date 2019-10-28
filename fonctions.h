#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

  void affichageMessageBienvenue();
  void verificationImage(Mat image);
  void affichage(string nomFenetre, cv::Mat image);
  void enregistrementImage(string nomImage, cv::Mat image);
  vector<Vec3b> generationAleatoireCouleur(vector<vector<Point> > contours);
  void etiquetter(Mat markers,vector<vector<Point> > contours);
  void colorationDesRegions(Mat image3, Mat markers,vector<Vec3b> colors,vector<vector<Point> > contours);


#endif // FONCTIONS_H_INCLUDED
