/**
 * \file GFD1.h
 * \brief Computation of the GCFD1
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

#ifndef GFD1_H_
#define GFD1_H_

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>
#include "FFT2.h"
#include "CFT.h"
#include "Descriptors.h"
#include "MyTools.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

using namespace cv;
/*! \class GFD1
 * \brief This class is used to compute the GFD1
 *
 */
class GFD1 : public Descriptors {
private:
	Mat Biv;				/*!< A color vector used to build the bivector B=Biv^e4*/
	vector<Mat> Dcircles;	/*!< Each Mat contains a mask used to integrate image values on discrete circles */
	/*!
	 *  \brief Compute the GFD1
	 *
	 *  \return Return the GFD1
	 */
	virtual vector<double> computeFeatures() const;
public:
	/*!
	     *  \brief Constructor of GFD1 class
	     *
	     *  \param im : A color image
	     *  \param Biv : A color vector used to build the bivector B=Biv^e4
	     *
	     */
	GFD1(const Mat& im,const Mat& Biv);
	/*!
	     *  \brief Constructor of GFD1 class
	     *
	     *  \param im : A color image
	     *  \param Biv : A color vector used to build the bivector B=Biv^e4
	     *  \param Dcircles : Each Mat contains a mask used to integrate image values on discrete circles
	     *
	     */
	GFD1(const Mat& im,const Mat& Biv,const vector<Mat>& Dcircles);
	virtual ~GFD1();
};
#endif /* GFD1_H_ */
