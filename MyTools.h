/**
 * \file MyTools.h
 * \brief A bag of tools
 * \author J. Mennesson
 * \version 1.0
 * \date July 30, 2013
 *
 * Copyright © 2013 J. Mennesson
 * Email:
 * jose.mennesson@univ-lille1.fr
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the distribution
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*! \mainpage GCFDLib documentation
 *
 * \section what What's the GCFDLib?
 *
 * This library is dedicated to the computation of the color Clifford Fourier Transform (CFT) and different color Fourier descriptors as GFD1, GCFD1, GCFD3.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Install OpenCV
 *	This library is based on the OpenCV library, so you must install it (See http://opencv.willowgarage.com/wiki/InstallGuide or http://remisoft.ath.cx/categorie2/opencv (In french)).
 *
 *	\subsection step2 Step 2: Link your project with the GCFDLib
 *
 */

#ifndef MYTOOLS_H_
#define MYTOOLS_H_

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <vector>
#include <dirent.h>
#include "FFT2.h"

using namespace cv;
/*! \class MyTools
 *
 * \brief This class contains a bag of tools
 *
 */
class MyTools {
public:
	MyTools();
	/*!
	 *  \brief This functions converts an integer to a string
	 *
	 *	\param number : An integer
	 *
	 *  \return Return the corresponding string
	 */
	static string Int2Str(const int& number);
	/*!
	 *  \brief This functions converts an double to a string
	 *
	 *	\param number : A double
	 *
	 *  \return Return the corresponding string
	 */
	static string Double2Str(const double& number);
	/*!
	 *  \brief This functions converts an bivector (a Mat which contains a 3D vector of double) to a string
	 *
	 *	\param Bivector : A color vector
	 *
	 *  \return Return the corresponding string
	 */
	static string Biv2Str(const Mat& Bivector);
	/*!
	 *  \brief Print a vector of double in the standard output stream
	 *
	 *	\param v2 : A vector of double
	 *
	 */
	static void printVector(vector<double>& v2);
	/*!
	 *  \brief Print a vector of integer in the standard output stream
	 *
	 *	\param v2 : A vector of integer
	 *
	 */
	static void printVector(vector<int>& v2);
	/*!
	 *  \brief Print a vector of string in the standard output stream
	 *
	 *	\param v2 : A vector of string
	 *
	 */
	static void printVector(vector<string>& v2);
	/*!
	*   \brief Get an element in a Mat of double
	*
	*	\param X : A Mat of double
	*	\param i : The line number in the Mat
	*	\param j : The column number in the Mat
	*	\return Return the element X(i,j)
	*
	*/
	static double getMatEltD(const Mat& X,const int& i,const int& j);

	/*!
	 *  \brief Convert a Mat to a vector
	 *
	 *	\param m : A Mat of double
	 *	\return Return a vector of double
	 */
	static vector<double> mat2vec(const Mat& m);
	/*!
	*  \brief Convert a vector of double to a Mat of size 1xN
	*
	*	\param v : A vector of double
	*	\return Return a Mat which correspond to the vector v
	*/
	static Mat vec2mat(const vector<double>& v);
	/*!
	*  \brief Convert a vector of integer to a Mat of size 1xN
	*
	*	\param v : A vector of integer
	*	\return Return a Mat which correspond to the vector v
	*/
	static Mat vec2mat(const vector<int>& v);
	/*!
	*   \brief Rotate a gray level image by an angle given by the user (the origin of the rotation is the center of the image)
	*
	*	\param gray : A gray level image
	*	\param angle : An angle of rotation
	*	\return Return a rotated gray level image
	*
	*/
	static Mat rotateIm(const Mat& gray,const double& angle);
	/*!
	*   \brief Rotate a color image by an angle given by the user (the origin of the rotation is the center of the image)
	*
	*	\param src : A color image
	*	\param angle : An angle of rotation
	*	\return Return a rotated color image
	*
	*/
	static Mat rotateColIm(cv::Mat& src, double angle);
	/*!
	*   \brief Convert an image in cartesian coordinates to a polar image. The center of the polar image is taken as the center of the original image.
	*
	*	\param im A gray level image in cartesian coordinates
	*	\param method If method=="full", all the image is considered and the missing parts are set to 0. If method=="crop", the image is cropped to a circle.
	*	\return Return a gray level polar image
	*/
	static Mat imCart2Pol(const Mat& im,const string& method);
	static Mat imCart2Pol(const Mat& im,const string& method, vector<double>& center);
	/*!
	*   \brief Convert an color image in cartesian coordinates to a polar image. The center of the polar image is taken as the center of the original image.
	*
	*	\param im : A color image in cartesian coordinates
	*	\param method : If method=="full", all the image is considered and the missing parts are set to 0. If method=="crop", the image is cropped to a circle.
	*	\return Return color polar image
	*/
	static Mat colImCart2Pol(const Mat& im,const string& method);
	static Mat colImCart2Pol(const Mat& im,const string& method, vector<double> center);
	static vector<double> getImageCenter(const Mat& colIm);
	/*!
		*   \brief Compute the magnitude of a Mat
		*
		*	\param M : A nD Mat
		*	\return Return the magnitude of the Mat
		*/
	static Mat magnitude(const Mat& M);
	/*!
		*   \brief Project each pixel of a color image on a color vector
		*
		*	\param colorIm : A color image
		*	\param colorVec : A color vec
		*	\return Return the magnitude of the Mat
		*/
	static Mat projImOnVec(const Mat& colorIm,const Mat& colorVec);
	/*!
		*   \brief Reorder color channels of an opencv color image (BGR -> RGB)
		*
		*	\param colorIm : A color image
		*
		*/
	static void reorderColorChannel(Mat& colorIm);
	/*!
	*   \brief Compute the number of null elements in a Mat of double
	*
	*	\param X : A color image
	*	\return Return the number of null elements in a Mat of double
	*/
	static int NbNullEltsCol(const Mat& X);
	/*!
		*   \brief Get the last token of a string
		*
		*	\param Text : A text
		*	\param delimiter : A delimiter '/', ' ', '.' etc.
		*	\return Return the number of null elements in a Mat of double
		*/
	static string myStrtok(const char* Text,char delimiter);

	/*!
	*   \brief Integrate an image on circles defined in Dcircles
	*
	*	\param X : An image
	*	\param Dcircles : A vector of masks
	*	\return Return the results of each integration
	*/
	static vector<double> integrOnCircles(const Mat& X,const vector<Mat>& Dcircles);
	/*!
	*   \brief Compute the masks corresponding to discrete circles
	*
	*	\param maxR : The maximum of radius in the image, i.e. for an image of size 127x127, maxR=63
	*
	*	\return Return a vector of masks
	*/
	static vector<Mat> computeDiscreteCircles(const int& maxR);
	/*!
	*   \brief Re-scale descriptors Mat between [-1;1]
	*
	*	\param Desc : A Mat of descriptors
	*
	*	\return Return a scaled Mat of Descriptors
	*/
	static Mat scaleDesc(const Mat& Desc);

	virtual ~MyTools();
};

#endif /* MYTOOLS_H_ */
