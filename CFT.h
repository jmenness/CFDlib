/**
 * \file CFT.h
 * \brief Computation of the color Clifford Fourier Transform (CFT) described in :
 *
 * Color object recognition based on a clifford fourier transform. José Mennesson, Christophe Saint-Jean, and Laurent Mascarilla.
 * Guide to Geometric Algebra in Practice. chapter 9, pages 175-191, Springer, 2011.
 *
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

#ifndef CFT_H_
#define CFT_H_

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <vector>
#include "FFT2.h"
#include "MyTools.h"

using namespace cv;
/*! \class CFT
   * \brief Color Clifford Fourier Transform
   *
   *  This class is used to compute the color Clifford Fourier Transform
   */
class CFT : public Mat{
private:
	Mat X;					/*!< A color image */
	Mat Vec;				/*!< A color vector used to build the bivector B=Vec^e4 */
	Mat parallelPart;		/*!< The parallel part of the CFT */
	Mat orthogonalPart;		/*!< The orthogonal part of the CFT */
public:

	CFT();
	/*!
		 *  \brief Constructor of CFT class
		 *
		 *  \param X : A color image
		 *  \param Vec : A color vector used to build the bivector B=Vec^e4
		 *
		 */
	CFT(const Mat& X,const Mat& Vec);
	/*!
	 *  \brief Constructor
	     *
	     *  Constructor of CFT class
	     *
	     *  \param X : A color image
	     *  \param Vec : A color vector used to build the bivector B=Vec^e4
	     *  \param inverse : If inverse==-1 then the inverse CFT is computed else the CFT is computed
	     */
	CFT(const Mat& X,const Mat& Vec,const int& inverse);
	/*!
	 *  \brief Compute the CFT
	     *
	     *
	     *  \param X : A color image
	     *  \param Vec : A color vector used to build the bivector B=Vec^e4
	     *
	     *   \return Return the parallel, orthogonal parts of the CFT and the reconstructed CFT of the image given in the constructor
	     */
	vector<Mat> computeCFT(const Mat& X,const Mat& Vec) const;
	/*!
	 *  \brief Compute the inverse CFT
	     *
	     *
	     *  \param X : A color image
	     *  \param Vec : A color vector used to build the bivector B=Vec^e4
	     *
	     *  \return Return the parallel, orthogonal parts of the ICFT and the reconstructed ICFT of the image given in the constructor
	     */
	vector<Mat> computeICFT(const Mat& X,const Mat& Vec) const;
	/*!
	 *  \brief Show the magnitude of the parallel, orthogonal parts and the reconstructed CFT
	     *
	     *  \param mess : The message in the title of the window
	     *
	     */
	void print(String mess) const;
	/*!
	 *  \brief Compute the magnitude of the CFT
	 *
	 *  \return Return the magnitude of the reconstructed CFT
	 */
	Mat magnitude() const;
	/*!
	 *  \brief Get the parallel part of the CFT
	 *
	 *	\return Return the parallel part of the CFT
	 */
	Mat getCFTPar();
	/*!
	 *  \brief Get the orthogonal part of the CFT
	 *
	 *  \return Return the orthogonal part of the CFT
	 *
	 */
	Mat getCFTOrth();

	virtual ~CFT();
};

#endif /* CFT_H_ */
