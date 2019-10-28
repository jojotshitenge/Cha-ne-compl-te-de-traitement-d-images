////********************************************************************************************////
////             TP3 : Chaîne complète de traitements d'images                     	        ////
////                                                                                            ////
////																							////
////             Auteurs: TSHITENGE MUPUWE Jojo, SALU PUATI Emmanuel, OLEMBO Richmond           ////
////                                           													////
////																							////
////             Compilation: make
////             Execution : ./tp3 								////
////																							////
////
////********************************************************************************************////

#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include "fonctions.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    string nomImage; //Nom de l'image a fournir
    affichageMessageBienvenue();
    cin >> nomImage;

	Mat image_initiale = imread(nomImage);
	verificationImage(image_initiale);

    Mat image1;
    cvtColor(image_initiale, image1, COLOR_RGB2GRAY);
    imshow("image_grise",image1);

	//Conversion de l'image couleur en image en niveaux de gris pour appliquer la segmentation dessus

    //conversion de l'image en niveaux de gris en image binaire avec l'algorithme de OTSU qui permet de determiner automatiquement
    //la valeur du seuil sur la base de l'histogramme et les regions modales constituant cet histogramme.
    //Ici nous obtenons une image binaire inverse, c'est-a-dire que les pixels ayant leur valeur en-dessous du seul calcule prendront la valeur
    //255 et les pixels ayant una valeur superieure seront mis a 0.
    //La binarisation est le type de segmentation la plus simple
	threshold(image1, image1, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);//Application de l'algorithme de OTSU pour la segmentation

	//Ci-dessous la phase de traitement apres la segmentation

	//Définition des éléments structurants
	Mat element = getStructuringElement(MORPH_RECT, Size(13, 13));
	Mat element1 = getStructuringElement(MORPH_RECT, Size(7, 7));
	Mat image2;

	//Fermeture des contours
    dilate(image1, image2, element);//dilatation
	erode(image2, image2, element1);//erosion

	// Déclaration d'un vecteur pour contenir les contours des régions détectées
	vector<vector<Point> > contours;

	//Recherche des contours des régions détectées
	findContours(image2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	//imshow("image_apres findContours",image2);

	// Etiquetage des régions
	Mat markers = Mat::zeros(image2.size(), CV_32SC1);
	etiquetter(markers, contours);

	// Génération aléatoire de couleurs
	vector<Vec3b> colors=generationAleatoireCouleur(contours);

	// Coloration des régions avec des couleurs différentes
	Mat image3 = Mat::zeros(markers.size(), CV_8UC3);
	colorationDesRegions(image3, markers, colors, contours);

	// Et logique entre l'image entrée et le masque obtenu après post-segmentation
	Mat image4;
	image_initiale.copyTo(image4, image3);

	//-----FIN de la phase de post-Segmentation-----

	//Présentation des résultats

    affichage("Image Initiale", image_initiale);

    affichage("Image Segmentee avec OTSU", image1);
    enregistrementImage("image_segmentation_otsu.png",image1);

    affichage("Image apres segmentation", image3);
    enregistrementImage("image_apres_segmentation.png",image3);

    affichage("image_segmentee", image4);
    enregistrementImage("image_segmentee.png",image4);

	waitKey(0);
	return 0;
}
