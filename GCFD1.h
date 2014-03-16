/**
 * \file GCFD1.h
 * \brief Computation of the GCFD1 described in :
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

#ifndef GCFD1_H_
#define GCFD1_H_
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>
#include "CFT.h"
#include "Descriptors.h"
#include "MyTools.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

using namespace cv;
/*! \class GCFD1
   * \brief This class is used to compute the GCFD1
   *
   */
class GCFD1 : public Descriptors{
private:
	Mat Biv;				/*!< Color vector used to build the bivector B=Biv^e4*/
	vector<Mat> Dcircles;	/*!< Each Mat contains a mask used to integrate image values on discrete circles */
	/*!
	 *  \brief Compute the GCFD1
	 *
	 *  \return Return the GCFD1
	 */
	virtual vector<double> computeFeatures() const;

public:
	/*!
	 *  \brief Constructor of GCFD1 class
	 *
	 *  \param im : A color image
	 *  \param Biv : A color vector used to build the bivector B=Biv^e4
	 *
	 */
	GCFD1(const Mat& im,const Mat& Biv);
	/*!
		     *  \brief Constructor of GCFD1 class
		     *
		     *  \param im : A color image
		     *  \param Biv : A color vector used to build the bivector B=Biv^e4
		     *  \param Dcircles : Each Mat contains a mask used to integrate image values on discrete circles
		     *
		     */
	GCFD1(const Mat& im,const Mat& Biv,const vector<Mat>& Dcircles);
	virtual ~GCFD1();
};
#endif /* GCFD1_H_ */

