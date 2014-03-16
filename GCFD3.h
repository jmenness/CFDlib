/**
 * \file GCFD3.h
 * \brief Computation of the GCFD3 described in :
 *
 * Un nouvel ensemble de descripteurs de Fourier Clifford pour les images couleur : les GCFD3. José Mennesson, Christophe Saint-Jean, Laurent Mascarilla.
 * Traitement du Signal-invitation au numéro spécial de RFIA 2012.
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

#ifndef GCFD3_H_
#define GCFD3_H_
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
/*! \class GCFD3
 *
   * \brief This class is used to compute the GCFD3
   *
   */
class GCFD3 : public Descriptors{
private:
	Mat Biv;				/*!< Color vector used to build the bivector B=Biv^e4*/
	vector<Mat> Dcircles;	/*!< Each Mat contains a mask used to integrate image values on discrete circles */
	/*!
	 *  \brief Compute the GCFD3
	 *
	 *  \return Return the GCFD3
	 */
	virtual vector<double> computeFeatures() const;
public:
	/*!
	     *  \brief Constructor of GCFD3 class
	     *
	     *  \param im : A color image
	     *  \param Biv : A color vector used to build the bivector B=Biv^e4
	     *
	     */
	GCFD3(const Mat& im,const Mat& Biv);
	/*!
	     *  \brief Constructor of GCFD3 class
	     *
	     *  \param im : A color image
	     *  \param Biv : A color vector used to build the bivector B=Biv^e4
	     *  \param Dcircles : Each Mat contains a mask used to integrate image values on discrete circles
	     *
	     */
	GCFD3(const Mat& im,const Mat& Biv,const vector<Mat>& Dcircles);

	virtual ~GCFD3();
};
#endif /* GCFD3_H_ */

