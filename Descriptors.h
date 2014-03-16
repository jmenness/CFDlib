/**
 * \file Descriptors.h
 * \brief Base class of all the descriptors
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

#ifndef DESCRIPTORS_H_
#define DESCRIPTORS_H_

#include "MyTools.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <vector>
using namespace cv;
/*! \class Descriptors
   * \brief Base class of all the descriptors
   *
   *  All our descriptors are derived from this class
   */
class Descriptors : public std::vector<double>{
protected :
	Mat im;		/*!< An image */

public:
	/*!
	 *  \brief Constructor of the Descriptors class
	 *
	 *  \param im : An image
	 *
	 */
	Descriptors(const Mat& im);
	/*!
	 *  \brief Virtual function which must be reimplemented to compute the features
	 *
	 *  \return A vector of double (the descriptors)
	 *
	 */
	virtual vector<double> computeFeatures() const= 0;
	virtual ~Descriptors();
};

#endif /* DESCRIPTORS_H_ */
